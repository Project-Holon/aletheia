/*
 * function: SCRCMD_NETWORK_CmdGetCommValue
 * address:  0x0215F214
 * packet:   pkt_0215F214
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 20 compiled 18
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   APP_ENV_IsWirelessAvailable  0x0202EB44  thumb
 */
#include "../include/Obj17703.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int APP_ENV_IsWirelessAvailable();

int SCRCMD_NETWORK_CmdGetCommValue(int a0, int a1)
{    unsigned short *v0;

    v0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215F21A:
    a0 = APP_ENV_IsWirelessAvailable();
loc_0215F220:
((struct Obj17703 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}
