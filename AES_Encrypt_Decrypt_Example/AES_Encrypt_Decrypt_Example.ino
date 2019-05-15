#include "CryptoAccel.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(5000);
  Serial.println("Starting :)");
  unsigned int i;
  unsigned char aeskey[16];
  for (i = 0; i < sizeof(aeskey); i++)  aeskey[i] = 0x70;
  unsigned char keysched[4*44];
  mmcau_aes_set_key(aeskey, 128, keysched);
  unsigned char in[16];
  for (i = 0; i < sizeof(in); i++)  in[i] = i;
  for (i = 0; i < sizeof(in); i++)  Serial.print(in[i]);
  Serial.println();
  unsigned char out[16];
  mmcau_aes_encrypt(in, keysched, 10, out);
  for (i = 0; i < sizeof(out); i++) Serial.print(out[i]);
  Serial.println();
  unsigned char iv[16];
  mmcau_aes_decrypt(out, keysched, 10, iv);
  for (i = 0; i < sizeof(iv); i++) Serial.print(iv[i]);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
