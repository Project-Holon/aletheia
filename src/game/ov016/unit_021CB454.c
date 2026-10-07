/*
 * file:     unit_021CB454.c
 * unit:     yes
 * function: func_021CB454, func_021CB498
 * address:  0x021CB454
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
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_RAKUlInit                   0x021c1488 arm
 *   DWCi_CMNlButton                  0x021bd264 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   procScene                        0x021cb4bc arm
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_RAKUlInit(void);
extern void DWCi_CMNlButton(int kind);
extern void DWCi_ChangeScene(void (*scene)());
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);


static void procInit2(void);


static void procInit1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_RAKUlInit();
    DWCi_CMNlButton(1);
    DWCi_ChangeScene(procInit2);
}


static void procScene(void);


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
