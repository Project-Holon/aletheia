/*
 * file:     unit_021C46B0_p01.c
 * unit:     yes
 * function: func_021C46B0, func_021C46DC, func_021C4714
 * address:  0x021C46B0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene                         0x021C46DC  arm
 *   func_021D5580  0x021D5580  arm
 *   func_021C11B8  0x021C11B8  arm
 *   func_021BCAE4  0x021BCAE4  arm
 *   func_021D55A4  0x021D55A4  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021C4794  0x021C4794  arm
 *   g_021DE5C8     0x021DE5C8  data
 */
typedef unsigned char u8;

extern int DWCi_BTNlGet(void);
extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021C115C(void);
extern void func_021BCB9C(void);
extern void func_021D5790(int);
extern void func_021C0E40(unsigned int v);
extern int  func_021D5580(int x);
extern int  func_021C11B8(void);
extern void func_021BCAE4(void);
extern void func_021D55A4(int a, int b, int c, int d);
extern void func_021C4794(void);
void func_021C46DC(void);
void func_021C4714(void);
extern u8   g_021DE5C8[];


static void endScene(void);


static void button(void)
{
    if (DWCi_BTNlGet())
        return;
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}


/*
 * Wake the sub-state, flag it and post the event at 0x021C4714.
 * Addresses are Black-image addresses.
 */
void func_021C46DC(void)
{
    if (*(unsigned char *)0x021DE5C8 == 0)
        func_021C115C();
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((unsigned int)((void *)0x021C4714));
}


void func_021C4714(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (g_021DE5C8[0] == 0) {
        if (func_021C11B8() == 0)
            return;
    }
    func_021BCAE4();
    if (g_021DE5C8[0] == 0)
        func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 0x15, 8);
    func_021C0E40((unsigned int)func_021C4794);
}
