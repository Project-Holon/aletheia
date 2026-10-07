/*
 * file:     unit_021CB6A4.c
 * unit:     yes
 * function: func_021CB6A4, func_021CB734
 * address:  0x021CB6A4
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
 *   DWCi_RAKUlGetState               0x021c1518 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_SNDlStop                    0x021d0014 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_BTNlDisable                 0x021bcb9c arm
 *   Choose                           0x021de604 data
 *   endScene                         0x021cb544 arm
 *   DWCi_WINlGet                     0x021d1568 arm
 *   DWCi_WINlEnd                     0x021d1524 arm
 *   procError1                       0x021cb760 arm
 */
typedef _Bool bool;

extern int DWCi_RAKUlGetState(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_BTNlDisable(void);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern unsigned char Choose;


static void endScene(void);

static void procError(void);


static void checkRaku(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 1:
        Choose = 1;
        DWCi_ChangeScene(endScene);
        break;
    case 4:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_WINlInitEx(0xd, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    }
}


static void procError1(void);


static void procError(void)
{
    if (DWCi_WINlGet() != 0) {
        return;
    }
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}
