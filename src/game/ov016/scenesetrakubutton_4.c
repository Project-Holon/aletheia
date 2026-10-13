/*
 * file:     scenesetrakubutton_4.c
 * function: func_021CA9A0
 * address:  0x021CA9A0
 * packet:   pkt_021CA9A0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA9A0   0x021CA9A0  arm
 *
 * Two-stage guard around func_021BCB28.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CA9A0.c \
 *       --func func_021CA9A0 --addr 0x021CA9A0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(unsigned int f);
extern int func_021CA818(void);
extern void func_021BCB28(signed char v);

void func_021CA9A0(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021CA818())
        func_021BCB28(0);
}
