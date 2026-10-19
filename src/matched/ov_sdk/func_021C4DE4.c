/*
 * function: taskVBlank
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
 *   taskVBlank   0x021C4DE4  arm
 *   DWCi_IPTlUpdate  0x021D656C  arm
 *   DWCi_TSKlAct  0x021D75D0  arm
 *
 * Run the job, then select mode 0 and run the four ov016 steps.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/taskVBlank.c \
 *       --func taskVBlank --addr 0x021C4DE4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_IPTlUpdate(void);
extern void DWCi_TSKlAct(int);
extern void func_021C4BDC(void);
extern void func_021C4C18(void);

void taskVBlank(void)
{
    DWCi_IPTlUpdate();
    DWCi_TSKlAct(0);
    func_021C4BDC();
    func_021C4C18();
}
