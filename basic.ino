//Insert Library Utama
#include <WiFi.h>
#include <FirebaseESP32.h>

//Kode Rahasia dari Firebase (Cek Tutorial Youtube Banyak)
#define FIREBASE_HOST "Rahasia"
#define FIREBASE_AUTH "Rahasia"

//Setiap database/akun/project database memiliki kode HOST dan AUTH berbeda

//WiFi Connect
#define WIFI_SSID Nama SSID"                            
#define WIFI_PASSWORD "Password8"

//Firebase
FirebaseData firebaseData;

void setup(){
  //Serial Begin (Opsional tergantung mau menggunakan fungsi serial atau tidak [misal print data dari firebase dsb.])
  Serial.begin(115200);
  
  //WiFi Begin (Menyambungkan ESP-32 ke WiFi)
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);   
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");
  
  //Firebase Begin (Menyambungkan ESP-32 ke Firebase !!!Harus dilakukan setelah ESP-32 tersambung WiFi)
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set Timeout dsb.
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}

void loop(){
  //Mengirim Data//
  
  //Data Int
  Firebase.setInt
}
