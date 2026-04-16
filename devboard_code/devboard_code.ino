#include <Arduino.h>

#define BAUD_RATE 115200

static const uint32_t PRINT_INTERVAL_MS = 1000;

uint32_t boot_ms = 0;
uint32_t last_update_ms = 0;

void setup() {
  Serial.begin(BAUD_RATE);

  uint32_t start_wait = millis();
  while (!Serial && (millis() - start_wait < 5000)) {
    delay(10);
  }

  boot_ms = millis();

  Serial.println();
  Serial.println("==================================");
  Serial.println(" COMPUTE MINI Devboard Booting...");
  Serial.println("==================================");

  Serial.print("CPU Frequency: ");
  Serial.print(rp2040.f_cpu() / 1000000);
  Serial.println(" MHz");

  Serial.print("Flash Size: ");
  Serial.print(rp2040.getFlashSize() / (1024 * 1024));
  Serial.println(" MB");

  Serial.println("System Initialization: OK");
  Serial.println("----------------------------------");
}

void loop() {
  uint32_t now = millis();

  if (now - last_update_ms >= PRINT_INTERVAL_MS) {
    last_update_ms = now;

    Serial.print("Uptime: ");
    Serial.print(now / 1000);
    Serial.println(" s | Status: RUNNING OK 🚀");
  }
}