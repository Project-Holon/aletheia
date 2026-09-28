/*
 * function: func_021C28FC
 * address:  0x021C28FC
 * packet:   pkt_021C28FC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C28FC   0x021C28FC  arm
 *
 * Guard: if (func_021D6824(2)) call func_021D6824.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C28FC.c \
 *       --func func_021C28FC --addr 0x021C28FC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(int);
extern void func_021BCB28(int);

void func_021C28FC(void)
{
    if (func_021D6824(2))
        func_021BCB28(0);
}
