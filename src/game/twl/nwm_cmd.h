#ifndef GAME_TWL_NWM_CMD_H
#define GAME_TWL_NWM_CMD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwm_cmd.c, prototypes copied from their definitions. */

#include "../types.h"

void NWMi_SetCallbackTable(u32 index, u32 callback);
void NWMi_SetReceiveCallbackTable(u32 index, u32 callback);
u32 NWMi_SendCommand(u16 apiid, u16 argc, ...);
u32 NWMi_SendCommandDirect(u32 command, u32 length);
u16 *NwmGetCommandBuffer4Arm7(void);
/* END mkheaders: generated region */

#endif
