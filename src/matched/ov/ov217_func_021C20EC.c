/*
 * function: ARROW_RunState
 * address:  0x021C20EC
 * packet:   pkt_ov217_021C20EC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARROW_RunIdle  0x021C2118  thumb  ov217
 *   ARROW_RunDrawing  0x021C211C  thumb  ov217
 *   ARROW_RunDone  0x021C2188  thumb  ov217
 */
#include "../include/Obj06717.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void ARROW_RunIdle(void *p);
extern void ARROW_RunDrawing(void *p);
extern void ARROW_RunDone(void *p);

void ARROW_RunState(void *p)
{
    switch (((struct Obj06717 *)p)->f20) {
    case 0: ARROW_RunIdle(p); break;
    case 1: ARROW_RunDrawing(p); break;
    case 2: ARROW_RunDone(p); break;
    }
    (((struct Obj06717 *)p)->f24)++;
}
