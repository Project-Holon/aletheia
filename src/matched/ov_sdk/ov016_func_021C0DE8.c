/*
 * function: procEnd
 * address:  0x021C0DE8
 * packet:   pkt_ov016_021C0DE8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procEnd (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   GX_DispOff  0x0207D42C  arm
 *   DWCi_SetLedNormal  0x021D7474  arm  ov016
 *   PM_SetLCDPower 0x0208C64C  arm
 *   DWCi_IPTlEnd  0x021D6538  arm  ov016
 *   DWCi_ITRlEnd  0x021D6CE4  arm  ov016
 *   DWCi_SNDlEnd  0x021CFF80  arm  ov016
 *   DWCi_CELLlEnd  0x021D4DC8  arm  ov016
 *   DWCi_OBJlEnd  0x021D6EEC  arm  ov016
 *   DWCi_FNTlEnd  0x021D5904  arm  ov016
 *   DWCi_EFFlEnd  0x021D556C  arm  ov016
 *   DWCi_ARClEnd  0x021D4A20  arm  ov016
 *   DWCi_TSKlEnd  0x021D7588  arm  ov016
 *   DWCi_HEAPlEnd  0x021D63A8  arm  ov016
 *   DWCi_RepairVram  0x021D72F8  arm  ov016
 */

extern void GX_DispOff(void);
extern void DWCi_SetLedNormal(void);
extern int PM_SetLCDPower(int sw);
extern void DWCi_IPTlEnd(void);
extern void DWCi_ITRlEnd(void);
extern void DWCi_SNDlEnd(void);
extern void DWCi_CELLlEnd(void);
extern void DWCi_OBJlEnd(void);
extern void DWCi_FNTlEnd(void);
extern void DWCi_EFFlEnd(void);
extern void DWCi_ARClEnd(void);
extern void DWCi_TSKlEnd(void);
extern void DWCi_HEAPlEnd(void);
extern void DWCi_RepairVram(void);

void procEnd(void)
{
    GX_DispOff();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    DWCi_SetLedNormal();
    PM_SetLCDPower(1);
    DWCi_IPTlEnd();
    DWCi_ITRlEnd();
    DWCi_SNDlEnd();
    DWCi_CELLlEnd();
    DWCi_OBJlEnd();
    DWCi_FNTlEnd();
    DWCi_EFFlEnd();
    DWCi_ARClEnd();
    DWCi_TSKlEnd();
    DWCi_HEAPlEnd();
    DWCi_RepairVram();
}
