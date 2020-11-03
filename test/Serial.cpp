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

  // Having trouble printing because it is a println command
  // String test = "test";
  // mySerial.print(test);
  // assertEqual("", state->serialPort[0].dataIn);
  // assertEqual("btest\n", state->serialPort[0].dataOut);
}

unittest_main()
