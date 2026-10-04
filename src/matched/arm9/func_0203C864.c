/*
 * function: func_0203C864
 * address:  0x0203C864
 * packet:   pkt_0203C65C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Promoted from src/pending/ on lane 1.  Every concrete byte is right; the one
 * open site was the `bl` to 0x02037700, whose only branch anywhere in the
 * image is this one, so `label` had no outside witness.  With
 * src/matched/func_02037700.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C864.c \
 *       --func func_0203C864 --addr 0x0203C864 --cc 1.1p1 --arm
 */
#include "../include/Obj15970.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern void *func_0203D798(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern int func_02037700(u32 a0, u32 a1);

void func_0203C864(void)
{
    u8 *p = func_0203D798();

    if (func_02037700(0x200, ((struct Obj15970 *)p)->f56) == 0)
        return;

    func_0203AD80((u32)g_021469DC, 0x0203C7E0, 0, 0x74A);
}
