// #include <WiFi.h>
// #include <PubSubClient.h>

// // Wi-Fi credentials
// const char* ssid = "Chitose";           // Replace with your Wi-Fi SSID
// const char* password = "password";   // Replace with your Wi-Fi password

// // MQTT broker
// const char* mqttServer = "192.168.1.108";  // Replace with your MQTT broker's IP (use localhost if on the same machine)
// const int mqttPort = 1883;

// // MQTT topics
// const char* ledControlTopic = "esp32/led";  // Topic for controlling LED

// // Pin for the LED (GPIO 4 on ESP32)
// WiFiClient espClient;
// PubSubClient client(espClient);

// // Callback function for handling incoming messages
// void callback(char* topic, byte* payload, unsigned int length) {
//   String message;
//   for (int i = 0; i < length; i++) {
//     message += (char)payload[i];
//   }
//   // Handle LED control
//   if (message == "ON") {
//     digitalWrite(LED_PIN, HIGH);  // Turn on LED
//   } else if (message == "OFF") {
//     digitalWrite(LED_PIN, LOW);   // Turn off LED
//   }

//   // Print the received message to the Serial Monitor (for debugging)
//   Serial.print("Received message: ");
//   Serial.println(message);
// }

// void setup() {
//   // Start Serial Monitor for debugging
//   Serial.begin(115200);

//   // Initialize LED pin
//   pinMode(LED_PIN, OUTPUT);
//   digitalWrite(LED_PIN, LOW);  // Make sure LED is off initially

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.print(".");
//   }

//   // Once connected, print the IP address
//   Serial.println("");
//   Serial.print("Connected to WiFi. IP address: ");
//   Serial.println(WiFi.localIP());

//   // Connect to MQTT broker
//   client.setServer(mqttServer, mqttPort);
//   client.setCallback(callback);

//   // MQTT connection loop
//   while (!client.connected()) {
//     Serial.print("Attempting MQTT connection...");
//     if (client.connect("ESP32Client")) {
//       Serial.println("connected");
//       client.subscribe(ledControlTopic);  // Subscribe to the control topic    //bug
//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       delay(5000);
//     }
//   }
// }

// void loop() {
//   client.loop();  // Keep MQTT connection alive
// }

#include <Arduino.h>
unsigned long comparator = 0;  // Get the counting time
const unsigned long interval = 10000;  // Interval in milliseconds (1 second)
bool flag = true;
void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);
  
  // Set the pins for the sensor and LED
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Ensure the LED is off initially
  digitalWrite(LED_PIN, LOW);
  
}

void loop() {
  // Send a pulse to the trigger pin
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Read the pulse duration from the echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance in cm (speed of sound = 343 m/s, divide by 2 for round trip)
  long distance = (duration / 2) / 29.1;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // If the distance is less than or equal to 20 cm, turn on the LED
  if (distance <= 20) {
    digitalWrite(LED_PIN, HIGH);  // Turn on LED
    bool flag = true;     // safe flag true
  } else {
      // Negate safe flag if its true
    if(flag == true){
      comparator = millis();
      flag = false;
    }
    else
    {
      // Check if 10 second has passed since flag negateds
      if(millis()-comparator>interval){
        digitalWrite(LED_PIN, LOW);
      }
    }  
}
  
  // Wait a short time before taking another measurement
  delay(500);
}

