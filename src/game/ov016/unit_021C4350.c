/*
 * file:     unit_021C4350.c
 * unit:     yes
 * function: func_021C4350, func_021C43AC, func_021C4408, func_021C44D8
 * address:  0x021C4350
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
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   Error                            0x021DE5C4  data
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_MOVlAdmitChild              0x021C11EC  arm
 *   DWCi_MOVlEnd                     0x021C115C  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SceneOptMovComm             0x021C315C  arm
 *   DWCi_SceneOptMovFailure          0x021C3D8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   isUnloaded  0x021de5c4  data
 */
typedef _Bool bool;

extern bool DWCi_WINlIsInit(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_MOVlAdmitChild();
extern void DWCi_MOVlEnd(void);
extern bool DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptMovComm(void);
extern void DWCi_SceneOptMovFailure(void);
extern unsigned char Error[];
extern unsigned char isUnloaded;


static void endScene1(void);


static void endScene(void)
{
    if (DWCi_WINlIsInit())
        return;
    if (Error[1] == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene1);
}


static void endScene2(void);


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (Error[0] == 0 && Error[1] == 1)
        DWCi_MOVlAdmitChild();
    else
        DWCi_MOVlEnd();
    DWCi_ChangeScene(endScene2);
}


static void endScene2(void)
{
    if (Error[0] || !Error[1]) {
        if (!DWCi_MOVlIsEnd())
            return;
    }
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    if (!Error[1]) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_SetParam_(0, (void *)1);
    if (Error[0]) {
        DWCi_ChangeScene(DWCi_SceneOptMovFailure);
        return;
    }
    if (Error[1] == 0) {
        DWCi_GXlInvisible(1, 1);
        DWCi_ChangeScene(DWCi_SceneOptMenu);
        return;
    }
    DWCi_ChangeScene(DWCi_SceneOptMovComm);
}


static void cbMov(void)
{
    isUnloaded = 1;
}
