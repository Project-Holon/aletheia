/*
 * function: RESEARCH_LIST_RegisterVBlank
 * address:  0x021BD5C4
 * packet:   pkt_021BD5C4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   RESEARCH_LIST_VBlankHandler  0x021BC610  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25894.h"

extern int func_020056A0(void (*)(void), void *, int);
typedef unsigned int   u32;
extern void RESEARCH_LIST_VBlankHandler(u32 a0, u32 a1);

void RESEARCH_LIST_RegisterVBlank(char *p)
{
    ((struct Obj25894 *)p)->f154 = func_020056A0((void (*)(void))RESEARCH_LIST_VBlankHandler, p, 0);
}
