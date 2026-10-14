/*
 * function: WORLDTRADE_INPUT_StateStartThreeOptionScreen
 * address:  0x021FBCB8
 * packet:   pkt_021FBCB8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_INPUT_DrawThreeOptionScreen  0x021FAAD4  thumb  ov135
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb  ov135
 *   g_0220320E  0x0220320E  data  ov135
 *   g_0220320F  0x0220320F  data  ov135
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9

 * Reset, re-arm the 6 frame, then index the two parallel stride-2 tables from the cursor at +0x44.
 */
#include "../include/Obj04906.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void WORLDTRADE_INPUT_DrawThreeOptionScreen(u8 *p);
extern void WORLDTRADE_SetActorPos(u32 v, u32 a, u32 b);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 g_0220320E[];
extern u8 g_0220320F[];

int WORLDTRADE_INPUT_StateStartThreeOptionScreen(u8 *p)
{
    u32 i;

    ((struct Obj04906 *)p)->f44 = 0;
    WORLDTRADE_INPUT_DrawThreeOptionScreen(p);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj04906 *)p)->f8), 6);
    i = ((struct Obj04906 *)p)->f44;
    WORLDTRADE_SetActorPos(((struct Obj04906 *)p)->f8, g_0220320E[i * 2], g_0220320F[i * 2]);
    ((struct Obj04906 *)p)->f48 = 1;
    ((struct Obj04906 *)p)->f4C = 0x1f;
    return -1;
}
