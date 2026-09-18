/*
 * function: func_02037190
 * address:  0x02037190
 * packet:   pkt_02037154
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469C8     0x021469C8  data
 *
 * Clears the flag byte at +0x0F of the armed handler; the only difference from
 * src/matched/func_02037174.c is the `movne r0, #0` instead of `#1`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037190.c \
 *       --func func_02037190 --addr 0x02037190 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 g_021469C8[];

void func_02037190(void)
{
    u8 *q;

    q = (u8 *)g_021469C8[1];
    if (q != 0)
        q[0x0F] = 0;
}
