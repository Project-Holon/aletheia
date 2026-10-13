/*
 * function: SCRIPT_WORK_GetMsgData
 * address:  0x02158F84
 * packet:   pkt_ov010_02158F84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x38 (getter of SCRIPT_WORK_SetMsgData).
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj18753.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 SCRIPT_WORK_GetMsgData(u8 *p)
{
    return ((struct Obj18753 *)p)->f38;
}
