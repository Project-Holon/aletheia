/*
 * function: PALETTE_ANIME_StepHold
 * address:  0x021C2D68
 * packet:   pkt_ov217_021C2D68
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_BlendColors  0x02021F64  thumb
 */
#include "../include/Obj00115.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void PALANM_BlendColors(u32 a, u32 b, u32 c, u32 d, u32 e);

void PALETTE_ANIME_StepHold(void *p)
{
    PALANM_BlendColors(*(u32 *)&((struct Obj00115 *)p)->fC, *(u32 *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, 7, ((struct Obj00115 *)p)->f12);
    (((struct Obj00115 *)p)->f1C)++;
}
