# Dự án làm game môn lập trình nâng cao INT2215 
- họ và tên: Nguyễn Tiến Thông
- MSV: 21020408
- Lớp: K66CC

# **Mục Lục**
- [1.Hướng dẫn cài đặt](#HuongDanCaiDat)
- [2.Mô tả chung](#MoTaChung)
- [3.Ý tưởng chính](#Ytuongchinh)
- [4.các chức năng cài đặt](#CacChucNangCaiDat)
- [5.Các kỹ thuật lập trình sử dụng](#CacKyThuatLapTrinhSuDung)
- [6.Kết luận](#KetLuan) 
- [7.Nguồn tham khảo](#ThamKhao)
  

<a name="HuongDanCaiDat"></a>
## 1.Hướng dẫn cài đặt 
- Nên cài đặt [Visual Studio](https://visualstudio.microsoft.com/) để thuận tiện hơn trong việc thiết lập game
- `sau khi tải file zip về thì nên cho vào ổ C:\ luôn đề tránh việc phải thiết lập lại các đường dẫn gây mất thời gian`
- **Nếu vẫn chưa chạy được thì xem tiếp**
- Vào phần `Game.sln` sau đó nhấp chuột phải vào `properties` và chỉ phải setup lại các đường dẫn của `SDL2, SDL_image, SDL_mix, SDL_ttf` theo [hướng dẫn](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)


<a name="MoTaChung"></a>
## 2.Mô tả chung
- [video minh họa](https://youtu.be/HmcJa93vi6Q)
- **Người chơi sử dụng chuột để điều khiển và ngắm bắn máy bay**
  - Đạn sẽ bắn từ bên trái và tên lửa sẽ bắn từ bên phải của màn hình
  - Người chơi sẽ phải bắn máy bay càng sớm càng tốt trước khi chúng kịp thả bom lên thành phố
  - Máy bay địch sau khi bị bắn hạ sẽ vẫn còn là một trở ngại cho người chơi
- **Luật và cách tính điểm**
  - Trò chơi sẽ kết thúc cho đến khi nào `City_health = 0`
  - Khi bắn trúng máy bay thì phải đợi cho máy bay ra khỏi màn hình mới tính điểm 
  - Sau mỗi màn chơi thì điểm cao nhất sẽ luôn được cập nhật và số tiền có được chính là bằng số điểm mỗi lần chơi 
  - máu và sức công phá bom đối với mỗi loại máy bay là khác nhau có trong phần `GET HELP` của Game
  - Càng về sau ( nếu chơi được ) thì máy bay địch sẽ càng đông và máu của chúng sẽ càng cao hơn
- **Có thể nâng cấp được sức công phá của vũ khí trong phần `UPGRADE` nếu có đủ tiền**

<a name="Ytuongchinh"></a>
## 3.Ý tưởng chính
- Đạn `chuột trái`, tên lửa `chuột phải` sẽ bắn theo góc của con trỏ chuột trên màn hình
- Sử dụng hàm lượng giác `atan2()` để lấy góc bắn cho đạn tên lửa và cả hướng máy bay rơi
- sử dụng hàm xử lý va chạm `CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)` để trừ máu của máy bay địch khi bị bắn trúng cũng như thành phố khi bị dội bom
- nếu các vật thể ra khỏi màn hình thì chúng sẽ bị xóa và giải phóng bộ nhớ
- sử dụng `rand()` để cài đặt độ cao cho máy bay địch

<a name="CacChucNangCaiDat"></a>
## 4.các chức năng cài đặt

- Menu của game: PLAY, GETHELP, UPGRADE 
- Đồ họa game
- Âm thanh ( bomb, Bullet, rocket)
- Nhận input từ chuột 
- có thể chơi lại nhiều lần
- quay lại MENU, thoát game
- tính điểm sau mỗi lượt chơi
- dùng tiền để nâng cấp
- cho biết điểm cao nhất
- FPS


<a name="CacKyThuatLapTrinhSuDung"></a>
## 5.Các kỹ thuật lập trình sử dụng
- đồ họa SDL
- sử dụng mảng con trỏ `vector` để thao tác với các đối tượng
- lớp đối tượng `class`
- kế thừa các lớp
- STL - `cmath.h`
- 1 particleEngine đơn giản
- đọc/ghi file

<a name="KetLuan"></a>
## 6.Kết luận

### Khó khăn 
- 90% là tự code game nên gặp nhiều trở ngại trong việc phát triển 
- đồ họa game chưa đẹp lắm vì phần lớn là tự vẽ (trên mạng có nhưng tính phí)
- cốt truyện game vẫn đơn giản
- chưa tối ưu được bộ nhớ ( khoảng 30mb mỗi phút)
- gặp khó khăn trong việc fixbug những lỗi liên quan đến logic thi biên dịch game

### Hướng phát triển
- Thêm chế độ chơi : người chơi lái máy bay thả bom thành phố
- tối ưu bộ nhớ hơn
- tối ưu lại một số đoạn code cho ngắn hơn mà vẫn đảm bảo chức năng
- học sử dụng các phần mềm chỉnh sửa ảnh như photoshop ... để hạn chế phụ thuộc nguồn trên mạng
- sử dụng các hàm toán học và đạo hàm để làm cho quỹ đạo của máy bay và tên lửa phức tạp hơn -> tăng độ khó
- nâng cấp particleEngine sao cho đẹp mắt hơn 

<a name="ThamKhao"></a>
## 7.Nguồn tham khảo
- [lazyfoo](https://lazyfoo.net/tutorials/SDL/index.php)
- [SDL2_tutorial](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
- hình ảnh và âm thanh đều lấy ở trên mạng về 
