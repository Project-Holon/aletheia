/*
 * function: func_0203D610
 * address:  0x0203D610
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D610.c \
 *       --func func_0203D610 --addr 0x0203D610 --arm --cc 1.1p1
 */
#include "../include/Obj11375.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);

u32 func_0203D610(void)
{
    u8 *p = func_0203D788();

    if (((struct Obj11375 *)p)->f40 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) * (u32 *)(p + 0x40))(((struct Obj11375 *)p)->f34C);
}
