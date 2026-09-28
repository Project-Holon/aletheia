/*
 * function: endScene2
 * address:  0x021C4408
 * packet:   pkt_ov016_021C4408
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      endScene2 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *           EXACT*: the inferred extent runs to 0x021C44EC (next label),
 *           over the 20-byte cbMov follower at 0x021C44D8; the function's
 *           own 208 bytes are byte-identical.
 *
 * symbols:
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SceneOptMovComm             0x021C315C  arm
 *   DWCi_SceneOptMovFailure          0x021C3D8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   Error                            0x021DE5C4  data
 */
typedef _Bool bool;

extern bool DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptMovComm(void);
extern void DWCi_SceneOptMovFailure(void);
extern unsigned char Error[];

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
