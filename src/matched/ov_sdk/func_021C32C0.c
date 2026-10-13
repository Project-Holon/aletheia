/*
 * function: func_021C32C0
 * address:  0x021C32C0
 * packet:   pkt_021C32C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_MOVlIsEnd  0x021C11B8  arm
 *   DWCi_ICONlEnd  0x021BD7F4  arm
 *   DWCi_ANIMElEnd  0x021BC8EC  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneOptMovCommWork     0x021DE5B4  data
 *   DWCi_SceneOptMovFailure  0x021C3D8C  arm
 *   DWCi_SceneOptMovDisconnect  0x021C3B8C  arm
 *   DWCi_SceneOptMovComplete  0x021C33CC  arm
 */

typedef unsigned char u8;

extern int  DWCi_EFFlCheck(int x);
extern int  DWCi_MOVlIsEnd(void);
extern void DWCi_ICONlEnd(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern u8   gSceneOptMovCommWork[];
extern void DWCi_SceneOptMovFailure(void);
extern void DWCi_SceneOptMovDisconnect(void);
extern void DWCi_SceneOptMovComplete(void);

void func_021C32C0(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (DWCi_MOVlIsEnd() == 0)
        return;
    DWCi_ICONlEnd();
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    if (gSceneOptMovCommWork[0] == 0) {
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovFailure);
        return;
    }
    if (gSceneOptMovCommWork[0] == 2) {
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovDisconnect);
        return;
    }
    DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovComplete);
}
