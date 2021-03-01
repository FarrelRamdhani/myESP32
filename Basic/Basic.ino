//Insert Library Utama
#include <WiFi.h>
#include <FirebaseESP32.h>

//Kode Rahasia dari Firebase (Cek Tutorial Youtube Banyak)
#define FIREBASE_HOST "Rahasia"
#define FIREBASE_AUTH "Rahasia"

//Setiap database/akun/project database memiliki kode HOST dan AUTH berbeda

//WiFi Connect
#define WIFI_SSID Nama "SSID"                            
#define WIFI_PASSWORD "Password"

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

//Data (Jangan lupa di Define)
int dataInt;
String dataString;
float dataFloat;
double dataDouble;
bool dataBool;

void loop(){
  //Mengirim Data//
  
  //Data Int
  Firebase.setInt(firebaseData, "Path", dataInt);
  
  //Data String
  Firebase.setString(firebaseData, "Path", dataString);
  
  //Data Float
  Firebase.setFloat(firebaseData, "Path", dataFloat);
  
  //Data Double
  Firebase.setDouble(firebaseData, "Path", dataDouble);
  
  //Data Bool
  Firebase.setBool(firebaseData, "Path", dataBool);
  
  //------------------------------------------------------------------------------------------//
  
  //Menerima Data
  
  //Data Int
  dataInt = Firebase.getInt(firebaseData, "Path");
  
  //Data String
  dataString = Firebase.getString(firebaseData, "path");
  
  //Data Float
  dataFloat = Firebase.getFloat(firebaseData, "path");
  
  //Data Double
  dataDouble = Firebase.getDouble(firebaseData, "path");
  
  //Data Bool
  dataBool = Firebase.getBool(firebaseData, "path");
  
  //----------------------------Troubleshooting----------------------------//
  //Apabila program tidak berjalan dengan baik, lakukan troubleshooting dengan cara
  Serial.println(firebaseData.errorReason());  
}

  //-----------------------------------------------------// Apabila get.() Tidak Berfungsi   //-----------------------------------------------------//

//Beberapa kondisi memungkinkan berberapa fungsi tidak dapat dijalankan seperti biasanya, berikut adalah kumpulan fungsi yang dapat digunakan pada fitur get atau mengambil data dari realtime database

void getData(){
  //Data Int
  if(Firebase.getInt(firebaseData, "path")){
    dataInt = (firebaseData.intData());
  } else{}
  
  //Data String
  if(Firebase.getString(firebaseData, "path")){
    dataString = (firebaseData.stringData());
  } else{}
  
  //Data Float
  if(Firebase.getFloat(firebaseData, "path")){
    dataFloat = (firebaseData.floatData());
  } else{}
  
  //Data Double
  if(Firebase.getDouble(firebaseData, "path")){
    dataDouble = (firebaseData.doubleData());
  } else{}
  
  //Data Bool
  if(Firebase.getBool(firebaseData, "path")){
    dataBool = (firebaseData.boolData());
  } else{}
  
}
