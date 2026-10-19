/*
 * function: TR_AI_CmdLoadMovePp
 * address: 0x021899C4
 * packet: pkt_ov096_021899C4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 */
#include "../include/Obj07927.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
int TR_AI_CmdLoadMovePp(u8 *a, u8 *b)
{
    ((struct Obj07927 *)b)->f38 = BTL_POKEPARAM_GetMovePPChecked(((struct Obj07927 *)b)->fBC, b[1]); return ((struct Obj07927 *)b)->fC4;
}
