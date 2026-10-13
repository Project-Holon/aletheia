/*
 * function: DWCi_SceneOptMovFailure
 * address:  0x021C3D8C
 * packet:   pkt_ov016_021C3D8C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovFailure (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021C3DC8  0x021C3DC8  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovFailureWork     0x021DE5C0  data
 *   func_021C3E48  0x021C3E48  arm  ov016
 */

extern void func_021C3DC8();
extern void DWCi_CMNlMsgDraw();
extern int DWCi_COMMENTlDispEx();
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3E48();
extern unsigned char gSceneOptMovFailureWork;

void DWCi_SceneOptMovFailure(void)
{
    func_021C3DC8();
    DWCi_CMNlMsgDraw(0x20);
    gSceneOptMovFailureWork = DWCi_COMMENTlDispEx(0x3C, -1, 0);
    DWCi_ChangeScene((unsigned int)func_021C3E48);
}
