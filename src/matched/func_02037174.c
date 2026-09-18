/*
 * function: func_02037174
 * address:  0x02037174
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
 * Sets the flag byte at +0x0F of the armed handler, and does nothing at all
 * when the handler is not armed - the `movne`/`strbne` pair is the whole body.
 * src/matched/func_02037190.c is the same function clearing the same byte.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037174.c \
 *       --func func_02037174 --addr 0x02037174 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 g_021469C8[];

void func_02037174(void)
{
    u8 *q;

    q = (u8 *)g_021469C8[1];
    if (q != 0)
        q[0x0F] = 1;
}
