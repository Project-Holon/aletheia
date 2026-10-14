/*
 * function: GURU2_MAIN_StateWaitIntroMessage
 * address:  0x021DEAC8
 * packet:   pkt_021DEAC8
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GURU2_MAIN_AreAllOthersReady  0x021E16D8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10637.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int GURU2_MAIN_AreAllOthersReady(const char *p);

int GURU2_MAIN_StateWaitIntroMessage(u8 *p)
{
    if (GURU2_MAIN_AreAllOthersReady((const char *)p)) {
        ((struct Obj10637 *)p)->f0 = 3;
        return 1;
    }
    return 0;
}
