/*
 * function: func_0203D814
 * address:  0x0203D814
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
 * Stores the two net_irc_wireless context words at +0xc and +4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D814.c \
 *       --func func_0203D814 --addr 0x0203D814 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021469E0[];

void func_0203D814(u32 a, u32 b)
{
    *(u32 *)(g_021469E0 + 0xc) = a;
    *(u32 *)(g_021469E0 + 4) = b;
}
