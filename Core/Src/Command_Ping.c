#include "Commands.h"
#include "UARTStream.h"
#include "main.h"

static const char CMD_PING_NAME[] = "ping";


static Cmd_Handled Echo_onExe(CmdManager* manager, Cmd* cmd, Param_Cursor* cursor, Cmd_Type type);

const Cmd CMD_PING = CMD_INIT(
  CMD_PING_NAME, 
  Cmd_Type_Any, 
  Echo_onExe, NULL, NULL, NULL, NULL
);

static Cmd_Handled Echo_onExe(CmdManager* manager, Cmd* cmd, Param_Cursor* cursor, Cmd_Type type) {
  static const char HELP[] = "\r\nOK\r\n";
  UARTStream* uartStream = CmdManager_getArgs(manager);
  OStream_writeBytes(&uartStream->Output, (uint8_t*) HELP, sizeof(HELP) - 1);
  OStream_flush(&uartStream->Output);
  return Cmd_Done;
}
