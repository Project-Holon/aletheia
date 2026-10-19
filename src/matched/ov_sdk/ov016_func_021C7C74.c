/*
 * function: procError
 * address:  0x021C7C74
 * packet:   pkt_ov016_021C7C74
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procError (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   DWCi_WINlGet  0x021D1568  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_WINlEnd  0x021D1524  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C7CA0  0x021C7CA0  arm  ov016
 */

extern signed char DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlEnd();
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C7CA0();

void procError(void)
{
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene((unsigned int)func_021C7CA0);
}
