


#include <EtherCard.h>


byte Ethernet::buffer[700];

const char website[] PROGMEM = "192.168.0.70"; 

// IP адрес сервера.
static byte websiteip[] = { 192,168,0,70 }; 
static uint32_t timer;

static byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

static void callback (byte status, word off, word len) {
  Serial.println(">>>");
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

//відправка данних
void send_package(){
    ether.packetLoop(ether.packetReceive());
    if (millis() > timer) {
    	Serial.println(F("<<PING"));
    	timer = millis() + 5000;
    	ether.browseUrl(PSTR("/cgi-bin/handler.py?"),"cxem=i_love_arduno", website, callback);
  }
}

void setup () {
  Serial.begin(9600);
//провірка на зєднання контроллера + віфі
  if (ether.begin(sizeof Ethernet::buffer, mac) == 0)
    Serial.println(F("Failed to access Ethernet controller"));
  else
    Serial.println(F("Successfully to access Ethernet controller"));
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP failed"));
  else
    Serial.println(F("Successfully DHCP"));

  memcpy(ether.hisip, websiteip, sizeof(websiteip));
  ether.printIp(F("SRV: "), ether.hisip);
}

void loop () {
  send_package();
}
