/*
 * function: func_021C34F4
 * address:  0x021C34F4
 * packet:   pkt_021C34F4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C34F4   0x021C34F4  arm
 *
 * Guard: if (func_021D6824(1)) call func_021D6824.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C34F4.c \
 *       --func func_021C34F4 --addr 0x021C34F4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(int);
extern void func_021BCB28(int);

void func_021C34F4(void)
{
    if (func_021D6824(1))
        func_021BCB28(0);
}
