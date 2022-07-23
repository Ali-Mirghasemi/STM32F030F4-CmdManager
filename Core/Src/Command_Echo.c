#include "Commands.h"
#include "UARTStream.h"
#include "main.h"

static const char CMD_ECHO_NAME[] = "echo";


static Cmd_Handled Echo_onSet(CmdManager* manager, Cmd* cmd, Param_Cursor* cursor, Cmd_Type type);
static Cmd_Handled Echo_onHelp(CmdManager* manager, Cmd* cmd, Param_Cursor* cursor, Cmd_Type type);

const Cmd CMD_ECHO = CMD_INIT(
  CMD_ECHO_NAME, 
  Cmd_Type_Any, 
  NULL, Echo_onSet, NULL, Echo_onHelp, NULL
);

static Cmd_Handled Echo_onSet(CmdManager* manager, Cmd* cmd, Param_Cursor* cursor, Cmd_Type type) {
  UARTStream* uartStream = CmdManager_getArgs(manager);
  OStream_writeBytes(&uartStream->Output, (uint8_t*) cursor->Ptr, cursor->Len);
  OStream_flush(&uartStream->Output);
  return Cmd_Done;
}
static Cmd_Handled Echo_onHelp(CmdManager* manager, Cmd* cmd, Param_Cursor* cursor, Cmd_Type type) {
  static const char HELP[] = "+ECHO: <parms>\r\n\r\nOK\r\n";
  UARTStream* uartStream = CmdManager_getArgs(manager);
  OStream_writeBytes(&uartStream->Output, (uint8_t*) HELP, sizeof(HELP) - 1);
  OStream_flush(&uartStream->Output);
  return Cmd_Done;
}
