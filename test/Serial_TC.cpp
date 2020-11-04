#include <Serial_TC.h>

#include "ArduinoUnitTests.h"

unittest(SerialTest) {
  GodmodeState* state = GODMODE();
  state->serialPort[0].dataIn = "";   // the queue of data waiting to be read
  state->serialPort[0].dataOut = "";  // the history of data written

  Serial_TC mySerial;

  assertTrue(true);

  mySerial.write('b');
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("b", state->serialPort[0].dataOut);

  String test = "test:";
  mySerial.print(test);
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\n", state->serialPort[0].dataOut);

  mySerial.print(test, 2);
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\ntest:2\r\n", state->serialPort[0].dataOut);

  mySerial.print(" car", " bike");
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\ntest:2\r\n car\r\n bike\r\n", state->serialPort[0].dataOut);

  mySerial.print(" Test Hex:", 78, HEX);
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\ntest:2\r\n car\r\n bike\r\n Test Hex:4E\r\n", state->serialPort[0].dataOut);

  byte mac[6] = {0x90, 0xA2, 0xDA, 0x00, 0x00, 0x00};
  mySerial.print_mac(mac);
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\ntest:2\r\n car\r\n bike\r\n Test Hex:4E\r\nMAC Address: 144:162:218:0:0:0\r\n",
              state->serialPort[0].dataOut);

  // char temp[] = {'a', 'b', 'c'};
  // mySerial.write(temp, strlen(temp));
  // assertEqual("", state->serialPort[0].dataIn);
  // assertEqual("btest:\r\ntest:2\r\n car\r\n bike\r\n Test Hex:4E\r\nMAC Address: 144:162:218:0:0:0\r\n",
  //             state->serialPort[0].dataOut);}
}
unittest_main()
