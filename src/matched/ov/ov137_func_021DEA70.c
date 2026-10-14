/*
 * function: GURU2_MAIN_StateStart
 * address:  0x021DEA70
 * packet:   pkt_021DEA70
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GURU2_MAIN_PrintMessage  0x021E0130  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23743.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void GURU2_MAIN_PrintMessage(u8 *p, int message);

int GURU2_MAIN_StateStart(u8 *p)
{
    GURU2_MAIN_PrintMessage(p, 0);
    ((struct Obj23743 *)p)->f0 = 1;
    return 0;
}
