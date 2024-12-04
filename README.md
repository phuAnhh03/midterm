# midterm
Họ tên: Bùi Đức Phú Anh

Nội dung: Hệ thống đèn tự động tuỳ chỉnh cho nhà

Sơ đồ khối dự kiến:
Start => Chờ tín hiệu sensor có người đi qua (1)
=> Nếu đúng: Bật Led, xoá timer    => Nếu sai: Đặt timer 10s nếu chưa có sẵn, nếu đã có sẵn thì không tác động timer
=> Nếu Timer = 0: Tắt led
=> Lặp lại từ bước (1)

Đặt bài toán:
Cầu thang bộ là một phần không thể thiếu với bất kì cơ sở hay nhà ở nào có nhiều tầng. Việc thiếu ánh sáng ở cầu thang dù chỉ trong thời gian ngắn có thể ảnh hưởng tới sinh hoạt và gây nguy hiểm cho nguời sử dụng, đặc biệt trong trường hợp ta có nhu cầu di chuyển đồ vật không tiện sử dụng công tắc bấm. Do đó, việc có hệ thống bật tắt đèn tự động là cần thiết để đảm bảo an toàn cho người sử dụng, có thể được sử dụng trong hầu hết cơ sở hạ tầng, kinh doanh hay nhà ở và cả chung cư. Việc sử dụng timer đảm bảo việc tắt đèn chỉ xảy ra sau khi sensor không phát hiện người trong 10s liên tục. Kết hợp sử dụng MQTT và node-red dashboard để cài đặt thêm các timer hoặc đặt thời gian điều khiển đèn để đảm bảo một số phần không gian đặc biệt cần chiếu sáng trong một khoảng thời điểm nhất định trong ngày.

Tổng hợp các tính năng:
- Bật tắt đèn dựa theo ultrasonic sensor
- Bật tắt đèn dựa trên timer người dùng tuỳ chỉnh qua dashboard
- Bật tắt đèn dựa trên mốc thời gian tuỳ chỉnh qua dashboard
- Bật tắt đèn trực tiếp qua dashboard

Mở rộng bài toán:

- Sử dụng cloud server (hivemq) thay cho mosquitto
- Thêm xác thực đơn giản như password, ...
- Kết hợp nút bấm vật lý
- Đưa UI tuỳ chỉnh lên thiết bị di động

Vấn đề còn tồn tại:
vấn đề code, kết nối mqtt của esp32 bị ngắt, dù kết nối wifi đã ổn định và PC có kết nối được tới mqtt