#include <Serial_TC.h>

#include "ArduinoUnitTests.h"

unittest(SerialTest) {
  GodmodeState* state = GODMODE();
  state->serialPort[0].dataIn = "";   // the queue of data waiting to be read
  state->serialPort[0].dataOut = "";  // the history of data written

  TC_Serial mySerial;

  assertTrue(true);

  mySerial.write('b');
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("b", state->serialPort[0].dataOut);

  String test = "test:";
  mySerial.print(test);
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\n", state->serialPort[0].dataOut);

  mySerial.print(test, 3);
  assertEqual("", state->serialPort[0].dataIn);
  assertEqual("btest:\r\ntest:3\r\n", state->serialPort[0].dataOut);
}

unittest_main()
