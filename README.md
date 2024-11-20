# midterm
Họ tên: Bùi Đức Phú Anh

Nội dung: Dùng cảm biến siêu âm phát hiện có người di chuyển qua

Sơ đồ khối dự kiến:
Start => Chờ tín hiệu sensor có người đi qua (1)
=> Nếu đúng: Bật Led, xoá timer    => Nếu sai: Đặt timer 10s nếu chưa có sẵn, nếu đã có sẵn thì không tác động timer
=> Nếu Timer = 0: Tắt led
=> Lặp lại từ bước (1)

Đặt bài toán:
Cầu thang bộ là một phần không thể thiếu với bất kì cơ sở hay nhà ở nào có nhiều tầng. Việc thiếu ánh sáng ở cầu thang dù chỉ trong thời gian ngắn có thể ảnh hưởng tới sinh hoạt và gây nguy hiểm cho nguời sử dụng, đặc biệt trong trường hợp ta có nhu cầu di chuyển đồ vật không tiện sử dụng công tắc bấm. Do đó, việc có hệ thống bật tắt đèn tự động là cần thiết để đảm bảo an toàn cho người sử dụng, có thể được sử dụng trong hầu hết cơ sở hạ tầng, kinh doanh hay nhà ở và cả chung cư. Việc sử dụng timer đảm bảo việc tắt đèn chỉ xảy ra sau khi sensor không phát hiện người trong 10s liên tục.
