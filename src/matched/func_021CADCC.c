/*
 * function: func_021CADCC
 * address:  0x021CADCC
 * packet:   pkt_021CADCC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CADCC   0x021CADCC  arm
 *
 * Two-stage guard around func_021BCB28.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CADCC.c \
 *       --func func_021CADCC --addr 0x021CADCC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(int);
extern int func_021CAC44(void);
extern void func_021BCB28(int);

void func_021CADCC(void)
{
    if (func_021D6824(2))
    {
        func_021BCB28(0);
        return;
    }
    if (func_021CAC44())
        func_021BCB28(0);
}
