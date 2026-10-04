/*
 * function: func_021DB378
 * address:  0x021DB378
 * packet:   pkt_ov175_021DB378
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *
 * Same guard as func_021DB300 but it moves the word the third argument
 *     points at into the +0x150 slot of the fourth argument and sets +0x14c.
 */

typedef unsigned long u32;

struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(u32 v);

void func_021DB378(u32 a, u32 b, u32 *c, char *d, u32 e)
{
    u32 v = *c;

    if (e != (u32)func_020399A8())
        return;
    if (a == func_0203D1A4((u32)func_020399A8()))
        return;
    *(u32 *)(d + 0x150) = v;
    *(u32 *)(d + 0x14c) = 1;
}

