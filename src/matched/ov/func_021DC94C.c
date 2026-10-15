/*
 * function: BOX2_MAIN_CreateVBlankTask
 * address:  0x021DC94C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_VBlankHandler  0x021DC970  thumb  ov170
 *
 * Seat the 0x54 handler word.
 */
#include "../include/Obj18436.h"



extern int func_020056A0(void *, void *, int);
typedef unsigned int   u32;
extern void BOX2_MAIN_VBlankHandler(u32 a, char *p);
void BOX2_MAIN_CreateVBlankTask(char *p)
{
    *(int *)(((struct Obj18436 *)p)->f2C + 0x54) = func_020056A0((void *)BOX2_MAIN_VBlankHandler, p, 0);
}
