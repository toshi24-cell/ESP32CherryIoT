//貞子サーチ1号
//物体が通過したことを検知して恐怖のメロディを流す装置 想定案：果樹園の泥棒及び害獣被害リスク管理
const int ruptPin = 32;
const int spkrPin = 25;

#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883

void setup() {
  pinMode(ruptPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  Serial.begin(115200);
  ledcAttach(spkrPin, 12000, 8);//周波数12kHz(高いほど音が滑らからしい、8ビットの分解能をもつ信号を生成)
}

void loop() {
  if(digitalRead(ruptPin) == LOW) {
    Serial.println("WARNING!");
    Playmusic();
  } else {
    Serial.println("No ENEMY");
  }
  delay(1000);//連続して判定されないために
}

//BPM = 200 1拍 = delay(300) リング
void  Playmusic() {
  ledcWriteTone(spkrPin, RA);
  delay(600);
  ledcWriteTone(spkrPin, MI);
  delay(600);
  ledcWriteTone(spkrPin, 0);
  delay(300);
  ledcWriteTone(spkrPin, RA);
  delay(300);
  ledcWriteTone(spkrPin, 0);
  delay(300);
  ledcWriteTone(spkrPin, RA);
  delay(300);
  ledcWriteTone(spkrPin, TI);
  delay(300);
  ledcWriteTone(spkrPin, SO);
  delay(600);
  
  ledcWriteTone(spkrPin, 0);
  delay(100);
}