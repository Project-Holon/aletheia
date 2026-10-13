/*
 * function: FLDMMDL_MOVE_AttrEffectDust
 * address: 0x0216375C
 * packet: pkt_ov010_0216375C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_CheckMoveBitShadowVanish 0x0216DD04 thumb ov010
 *   FLDEFF_KEMURI_Start 0x021AC528 thumb ov021
 */
#include "../include/Obj00110.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int FLDMMDL_CheckMoveBitShadowVanish(void *p);
extern void FLDEFF_KEMURI_Start(u32 a, u32 b);
void FLDMMDL_MOVE_AttrEffectDust(void *p, u8 *q)
{
    if (!(((struct Obj00110 *)q)->fE & 2) && !FLDMMDL_CheckMoveBitShadowVanish(p))
        FLDEFF_KEMURI_Start((u32)p, *(u32 *)&((struct Obj00110 *)q)->f14);
}
