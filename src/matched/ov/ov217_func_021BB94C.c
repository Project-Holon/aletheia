/*
 * function: RESEARCH_LIST_ProcessCommand
 * address:  0x021BB94C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_LIST_SetState  0x021BB978  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *
 * Same guard shape as 021BA158 on the +0x158 word, handing the +0x18
 * handle to RESEARCH_LIST_SetState.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ring;
extern int RESEARCH_LIST_SetState(char *p, int a1);
extern u32 RingQueue_Pop(struct Ring *r);
extern u32 RingQueue_IsEmpty();
void RESEARCH_LIST_ProcessCommand(u32 a0)
{
    if (((struct Obj00025 *)(((u8*)a0)))->f158 != 0) {
    if (RingQueue_IsEmpty(((struct Obj00025 *)(((u8*)a0)))->f18) == 0) {
    RESEARCH_LIST_SetState((char *)a0, RingQueue_Pop((struct Ring *)(((struct Obj00025 *)(((u8*)a0)))->f18)));
    }
    }
}
