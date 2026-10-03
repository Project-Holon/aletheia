/*
 * function: func_021CB4DC
 * address:  0x021CB4DC
 * packet:   pkt_021CB4DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB4DC   0x021CB4DC  arm
 *
 * Two-stage guard around func_021BCB28.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CB4DC.c \
 *       --func func_021CB4DC --addr 0x021CB4DC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(unsigned int f);
extern int func_021CB2C8(void);
extern void func_021BCB28(signed char v);

void func_021CB4DC(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021CB2C8())
        func_021BCB28(0);
}
