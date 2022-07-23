#include "Commands.h"

#include "CmdManager.h"

extern const Cmd CMD_LED;
extern const Cmd CMD_ECHO;
extern const Cmd CMD_PING;

static const Cmd_Array CMDS[] = {
  (Cmd_Array) &CMD_LED,
  (Cmd_Array) &CMD_ECHO,
  (Cmd_Array) &CMD_PING,
};

static const Cmd_LenType CMDS_LEN = CMD_ARR_LEN(CMDS);

Cmd_Array* Commands_get(void) {
  return (Cmd_Array*) &CMDS;
}
Cmd_LenType Commands_len(void) {
  return CMDS_LEN;
}

