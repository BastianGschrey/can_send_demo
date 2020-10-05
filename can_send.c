#include <mcp_can.h>
#include <SPI.h>


long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];                        // Array to store serial string
int printValueInt = 0;
float printValueFloat = 0.0;

MCP_CAN CAN0(10);                               // Set CS to pin 10



void setup()
{
  Serial.begin(115200);
  
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK){
  }
  else{
    Serial.println("Error Initializing MCP2515...");
    }
  
  
  CAN0.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT);                            // Configuring pin for /INT input
  
}

void loop()
{
  if(!digitalRead(CAN0_INT))                         // If CAN0_INT pin is low, read receive buffer
  {
	CAN.sendMsgBuf(INT8U id, INT8U ext, INT8U len, data_buf);
  }
}
