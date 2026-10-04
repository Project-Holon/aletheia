/*
 * function: func_0202E09C
 * address:  0x0202E09C
 * packet:   pkt_0202E09C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): the loop counter is signed,
 *           the image compares with blt; u32 gave blo (1 byte)
 *
 * symbols:
 *   func_0202DFEC  0x0202DFEC  thumb
 *
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

struct Res;
extern void *func_0202DFEC(struct Res *a, u16 b);

void func_0202E09C(u8 *o, struct Res *a, u16 b)
{
    int i;

    for (i = 0; i < 2; i++) {
        *(u32 *)(o + 8 + i * 4) = (u32)func_0202DFEC(a, b);
    }
    *(u32 *)(o + 0x18) = (*(u32 *)(o + 0x18) & ~1) | 4;
}
