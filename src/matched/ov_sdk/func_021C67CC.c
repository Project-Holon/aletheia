/*
 * function: func_021C67CC
 * address:  0x021C67CC
 * packet:   pkt_021C67CC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_KBlInit  0x021BD8D8  arm
 *   DWCi_SNDlPlay  0x021CFFAC  arm
 *   DWCi_KBlSetErase  0x021BDC68  arm
 *   DWCi_KBlSetInput  0x021BDC7C  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gMemSse     0x021DE5E0  data
 *   func_021C684C  0x021C684C  arm
 */

typedef unsigned char u8;

extern int  DWCi_EFFlCheck(int x);
extern void DWCi_KBlInit(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_KBlSetErase(unsigned char v);
extern void DWCi_KBlSetInput(unsigned char v);
extern void DWCi_ChangeScene(unsigned int v);
extern u8  *gMemSse;
extern void func_021C684C(void);

void func_021C67CC(void)
{
    u8 *p;

    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_KBlInit();
    DWCi_SNDlPlay(0x14);
    p = gMemSse;
    if (p[0x29] == 0)
        DWCi_KBlSetErase(0);
    p = gMemSse;
    if (p[0x29] == 0x20)
        DWCi_KBlSetInput(0);
    DWCi_ChangeScene((unsigned int)func_021C684C);
}
