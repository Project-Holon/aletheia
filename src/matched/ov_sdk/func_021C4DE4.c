/*
 * function: func_021C4DE4
 * address:  0x021C4DE4
 * packet:   pkt_021C4660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C4DE4   0x021C4DE4  arm
 *   DWCi_IPTlUpdate  0x021D656C  arm
 *
 * Run the job, then select mode 0 and run the four ov016 steps.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4DE4.c \
 *       --func func_021C4DE4 --addr 0x021C4DE4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_IPTlUpdate(void);
extern void func_021D75D0(int);
extern void func_021C4BDC(void);
extern void func_021C4C18(void);

void func_021C4DE4(void)
{
    DWCi_IPTlUpdate();
    func_021D75D0(0);
    func_021C4BDC();
    func_021C4C18();
}
