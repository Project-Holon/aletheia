/*
 * function: func_0203D720
 * address:  0x0203D720
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x28 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D720.c \
 *       --func func_0203D720 --addr 0x0203D720 --arm --cc 1.1p1
 */
#include "../include/Obj11378.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
struct Entry;
extern struct Entry *func_020399A8(void);

void func_0203D720(u32 a)
{
    u8 *p = func_0203D788();

    if (((struct Obj11378 *)p)->f28 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) * (u32 *)(p + 0x28))(
        (u32)func_020399A8(), a, ((struct Obj11378 *)p)->f34C);
}
