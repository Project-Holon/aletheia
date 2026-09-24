/*
 * function: func_021C4674
 * address:  0x021C4674
 * packet:   pkt_021C4674
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C4674   0x021C4674  arm
 *
 * Two-stage guard around func_021BCB28.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4674.c \
 *       --func func_021C4674 --addr 0x021C4674 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(int);
extern int func_021C44EC(void);
extern void func_021BCB28(int);

void func_021C4674(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021C44EC())
        func_021BCB28(0);
}
