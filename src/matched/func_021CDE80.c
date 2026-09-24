/*
 * function: func_021CDE80
 * address:  0x021CDE80
 * packet:   pkt_021CDE80
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CDE80   0x021CDE80  arm
 *
 * Two guarded func_021BCB28 calls keyed off func_021D6824.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CDE80.c \
 *       --func func_021CDE80 --addr 0x021CDE80 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(int);
extern void func_021BCB28(int);

void func_021CDE80(void)
{
    if (func_021D6824(1))
        func_021BCB28(1);
    if (func_021D6824(2))
        func_021BCB28(0);
}
