//Terkadang ketika mengirimkan data menuju database, beberapa kendala seperti penambahan waktu muncul. 
//Karena itu, firebase telah memiliki fitur untuk mengirimkan perintah dari ESP untuk memberikan timestamp atau waktu ke dalam path yang ingin dituju

//Insert Library Utama
#include <WiFi.h>
#include <FirebaseESP32.h>

//Untuk keperluan basic lainnya seperti menyambungkan ke wifi dan firebase, lihat basic.ino di https://github.com/FarrelRamdhani/myESP32

//Firebase
FirebaseData firebaseData;

void setWaktu(){
  Firebase.setTimeStamp(firebaseData, "path");
}

// Timestamp yang diberikan berupa long/unsign long berbentuk Unix Time
// https://en.wikipedia.org/wiki/Unix_time

// Timestamp ini biasanya menggunakan satuan milisekond


//-----------------------------------------------------//Penggunaan Timestamp//-----------------------------------------------------//
//Penggunaan timestamp ini berfungsi untuk memberikan informasi pada database bahwa modul mengirimkan data pada waktu sekian.
//Hal ini bermanfaat misal ketika menggunakan database pada monitoring jarak jauh untuk pengambilan data yang dimana ketika data tersebut diambil diperlukan waktu yang akurat

//Penggunaan timestamp ini juga lebih mudah dan lebih cepat karena sudah ter integrated dengan library Firebase-ESP32 dan Firebase sehingga memudahkan dalam pemrograman dan pemrosesan data
//Penggunaan ini juga lebih cepat dibandingkan menggunakan library time maupun library NTP Client yang memerlukan sambungan lain selain Firebase (menurunkan efisiensi)
