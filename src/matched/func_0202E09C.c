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
typedef unsigned int  u32;

extern u32 func_0202DFEC(u32 a, u32 b);

void func_0202E09C(u8 *o, u32 a, u32 b)
{
    int i;

    for (i = 0; i < 2; i++) {
        *(u32 *)(o + 8 + i * 4) = func_0202DFEC(a, b);
    }
    *(u32 *)(o + 0x18) = (*(u32 *)(o + 0x18) & ~1) | 4;
}
