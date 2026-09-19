/*
 * function: func_020117D8
 * address:  0x020117D8
 * packet:   pkt_020117D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lay out `a1` rows of `a2` bytes each at stride a1*0xc into the three
 * buffers the record declares at +0x1c, +0x20 and +0x24, but only where the
 * matching flag word at +0x28, +0x2c and +0x30 is set.  a3 is the caller's
 * byte budget: if it is smaller than a1*0xc times the number of live flags
 * nothing is written and the call answers 0.  +0x18 records the row count.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020117D8.c \
 *       --func func_020117D8 --addr 0x020117D8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int func_020117D8(u8 *a0, int a1, u8 *a2, int a3)
{
    int total;
    int step;
    int k;

    total = 0;
    step = a1 * 0xc;
    k = 0;
    if (*(u32 *)(a0 + 0x28) != 0) {
        total += step;
    }
    if (*(u32 *)(a0 + 0x2c) != 0) {
        total += step;
    }
    if (*(u32 *)(a0 + 0x30) != 0) {
        total += step;
    }
    if (a3 < total) {
        return 0;
    }
    if (*(u32 *)(a0 + 0x28) != 0) {
        *(u8 **)(a0 + 0x1c) = a2;
        k++;
    }
    if (*(u32 *)(a0 + 0x2c) != 0) {
        *(u8 **)(a0 + 0x20) = a2 + step * k;
        k++;
    }
    if (*(u32 *)(a0 + 0x30) != 0) {
        *(u8 **)(a0 + 0x24) = a2 + step * k;
        k++;
    }
    *(u32 *)(a0 + 0x18) = a1;
    return 1;
}
