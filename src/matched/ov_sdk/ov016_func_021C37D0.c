/*
 * function: closeWaitStep
 * address:  0x021C37D0
 * packet:   pkt_ov016_021C37D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_SceneOptMovWait             0x021C450C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovconfi.o), symbol closeWaitStep (name and prototype
 * from the vendor object DWARF). Callee of endScene1. The object is stamped Metrowerks
 * C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so 1.1p1.
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_ChangeScene(void (*scene)());

static void DWCi_SceneOptMovWait(void);

static void closeWaitStep(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_((void *)0, (void *)1);
    DWCi_ChangeScene(DWCi_SceneOptMovWait);
}
