/*
 * function: DWCi_SceneMenu
 * address:  0x021C1984
 * packet:   pkt_021C1984
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Settles the panel and dispatches the record indexed by gSceneMenuWork[0].
 *
 * symbols:
 *   func_021C1A04  0x021C1A04  arm
 *   DWCi_HLlLoad  0x021BD674  arm
 *   DWCi_COMMENTlDispEx  0x021BD060  arm
 *   DWCi_STEPlChangeScr  0x021D0AB0  arm
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneMenuWork   0x021DE59C  data
 *   sSceneMenuFocusX0     0x021DA488  data
 *   sSceneMenuFocusY0     0x021DA48A  data
 *   sSceneMenuFocusX1     0x021DA48C  data
 *   sSceneMenuFocusY1     0x021DA48E  data
 *   func_021C1AE8  0x021C1AE8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_021C1A04(void);
extern void DWCi_HLlLoad(int x);
extern void DWCi_COMMENTlDispEx(int a, int b, int c);
extern void DWCi_STEPlChangeScr(int x);
extern void DWCi_FOCUSlDisp4(int a, int b, int c, int d);
extern void DWCi_ChangeScene(unsigned int v);
extern u8   gSceneMenuWork[];
extern u16  sSceneMenuFocusX0[][4];
extern u16  sSceneMenuFocusY0[][4];
extern u16  sSceneMenuFocusX1[][4];
extern u16  sSceneMenuFocusY1[][4];
extern void func_021C1AE8(void);

void DWCi_SceneMenu(void)
{
    u8 i;

    func_021C1A04();
    DWCi_HLlLoad(0);
    DWCi_COMMENTlDispEx(0x2e, -1, 0);
    DWCi_STEPlChangeScr(4);
    i = gSceneMenuWork[0];
    DWCi_FOCUSlDisp4(sSceneMenuFocusX0[i][0], sSceneMenuFocusX1[i][0],
                  sSceneMenuFocusY0[i][0], sSceneMenuFocusY1[i][0]);
    DWCi_ChangeScene((unsigned int)func_021C1AE8);
}
