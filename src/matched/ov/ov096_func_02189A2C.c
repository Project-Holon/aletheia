/*
 * function: TR_AI_CmdLoadMoveDamageType
 * address: 0x02189A2C
 * packet: pkt_ov096_02189A2C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TR_AI_GetMoveParam 0x0218A378 thumb ov096
 */
#include "../include/Obj10188.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int TR_AI_GetMoveParam(int, int, int);
int TR_AI_CmdLoadMoveDamageType(u8 *a, u8 *b)
{
    ((struct Obj10188 *)b)->f38 = TR_AI_GetMoveParam((int)b, ((struct Obj10188 *)b)->f2, 2); return ((struct Obj10188 *)b)->fC4;
}
