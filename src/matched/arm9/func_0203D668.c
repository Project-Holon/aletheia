/*
 * function: func_0203D668
 * address:  0x0203D668
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the argument at +0x34c of the net context, when there is one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D668.c \
 *       --func func_0203D668 --addr 0x0203D668 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_0203D788(void);

void func_0203D668(u32 v)
{
    u8 *p = func_0203D788();

    if (p != 0) {
        *(u32 *)(p + 0x34c) = v;
    }
}
