/*
 * function: func_0203D8C4
 * address:  0x0203D8C4
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469E0  0x021469E0  data
 *
 * Writes 1 or 0 to the net context's +0x352 byte depending on whether the
 * argument is 1; a null context is a no-op.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D8C4.c \
 *       --func func_0203D8C4 --addr 0x0203D8C4 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021469E0[];

void func_0203D8C4(u32 a)
{
    u8 *p = *(u8 **)(g_021469E0 + 8);

    if (p == 0) {
        return;
    }
    if (a == 1) {
        p[0x352] = 1;
    } else {
        p[0x352] = 0;
    }
}
