/*
 * function: ARROW_RunDrawing
 * address:  0x021C211C
 * packet:   pkt_ov217_021C211C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARROW_ShowPart  0x021C21C4  thumb  ov217
 *   ARROW_StopPart  0x021C2250  thumb  ov217
 *   ARROW_IsComplete  0x021C2194  thumb  ov217
 *   ARROW_SetState  0x021C218C  thumb  ov217
 */
#include "../include/Obj06717.h"
#include "../include/Obj06718.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void ARROW_ShowPart(u8 *p, int index);
extern void ARROW_StopPart(u32 a0, u32 a1);
extern u32 ARROW_IsComplete(void *p);
extern void ARROW_SetState(void *p, u32 v);

void ARROW_RunDrawing(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj06717 *)p)->f298; i++) {
        char *e = (char *)p + i * 0x18;
        if (((struct Obj06718 *)e)->f28 == 0 && ((struct Obj06718 *)e)->f2C <= ((struct Obj06717 *)p)->f24)
            ARROW_ShowPart(p, (u8)i);
        if (((struct Obj06718 *)e)->f28 == 1 && ((struct Obj06718 *)e)->f30 == 1 && ((struct Obj06718 *)e)->f34 <= ((struct Obj06717 *)p)->f24)
            ARROW_StopPart((u32)p, (u8)i);
    }
    if (ARROW_IsComplete(p))
        ARROW_SetState(p, 2);
}
