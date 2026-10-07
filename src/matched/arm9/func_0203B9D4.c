/*
 * function: func_0203B9D4
 * address:  0x0203B9D4
 * packet:   pkt_0203B9D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC      0x021469DC  data
 *   func_0203D788   0x0203D788  arm
 *   func_0203AD80   0x0203AD80  arm
 *
 * A frame's 64-bit accumulator advanced by a 64-bit multiply: the pair at
 * +0x0c (little-endian u64) is multiplied by the pair at +0x14, the pair at
 * +0x1c is added in, both halves are stored back, and the new high half is
 * re-scaled by 30/2^32 into the u16 countdown at +0x46.
 *
 * Two spellings are load-bearing.  The multiply has to be written `y * x`
 * with x at +0x0c and y at +0x14: the other order loads +0x0c first and
 * swaps two `ldr`s.  And the addend has to stay inline in the multiply's own
 * statement (`r = y * x + *(u64 *)(p + 0x1c);`) with the low half stored by
 * a single 64-bit store: with a named addend and two u32 stores mwcc puts
 * the sum's low half in `ip` and the high half in `r2`, a five-instruction
 * difference in register choice alone.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B9D4.c \
 *       --func func_0203B9D4 --addr 0x0203B9D4 --cc 1.1p1 --arm
 */
#include "../include/Obj03451.h"
#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern struct Sys *g_021469DC;

extern void *func_0203D788(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);

void func_0203B9D4(u8 *p)
{
    u8 *s = func_0203D788();
    u64 x, y, r;

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0xAC))() == 1) {
        (*(void (**)(void))(*(u32 *)(s + 0x340) + 0xB4))();
        func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)0x0203B868, 0, 0x3A5);
        return;
    }

    if (((struct Obj03451 *)p)->f46 != 0) {
        ((struct Obj03451 *)p)->f46 = ((struct Obj03451 *)p)->f46 - 1;
        return;
    }

    x = *(u64 *)(p + 0x0C);
    y = *(u64 *)(p + 0x14);
    r = y * x + *(u64 *)(p + 0x1C);

    ((struct Obj03451 *)p)->f46 = (u16)((u32)(((u64)(u32)(r >> 32) * 30) >> 32) + 15);
    *(u64 *)(p + 0x0C) = r;

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x08))(0);
}
