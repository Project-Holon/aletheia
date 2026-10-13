/*
 * function: DWCi_SceneOptMenu
 * address:  0x021C2A3C
 * packet:   pkt_021C2A3C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2B00  0x021C2B00  arm
 *   DWCi_HLlLoad  0x021BD674  arm
 *   DWCi_STEPlChangeScr  0x021D0AB0  arm
 *   DWCi_COMMENTlDispEx  0x021BD060  arm
 *   DWCi_CEINlSetExObj  0x021D5368  arm
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneOptMenuWork     0x021DE5A8  data
 *   sSceneOptMenuFocusX0     0x021DA4D0  data
 *   sSceneOptMenuFocusY0     0x021DA4D2  data
 *   sSceneOptMenuFocusX1     0x021DA4D4  data
 *   sSceneOptMenuFocusY1     0x021DA4D6  data
 *   func_021C2C94  0x021C2C94  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G {
    u8  f0;
    u8  f1;
    u8  pad02[6];
    int f8;
};

extern void func_021C2B00(void);
extern void DWCi_HLlLoad(int x);
extern void DWCi_STEPlChangeScr(int x);
extern void DWCi_COMMENTlDispEx(int a, int b, int c);
extern int  DWCi_CEINlSetExObj(int a, int b);
extern void DWCi_FOCUSlDisp4(int a, int b, int c, int d);
extern void DWCi_ChangeScene(unsigned int v);
extern struct G gSceneOptMenuWork;
extern u16 sSceneOptMenuFocusX0[][4];
extern u16 sSceneOptMenuFocusY0[][4];
extern u16 sSceneOptMenuFocusX1[][4];
extern u16 sSceneOptMenuFocusY1[][4];
extern void func_021C2C94(void);

void DWCi_SceneOptMenu(void)
{
    int q;
    u8 i;

    gSceneOptMenuWork.f1 = 0;
    func_021C2B00();
    DWCi_HLlLoad(0x10);
    DWCi_STEPlChangeScr(3);
    DWCi_COMMENTlDispEx(0x39, -1, 0);
    gSceneOptMenuWork.f8 = DWCi_CEINlSetExObj(0, 0x5b);
    q = gSceneOptMenuWork.f8;
    *(u32 *)q = (*(u32 *)q & 0xFE00FF00) | 0x84 | 0xE00000;
    q = gSceneOptMenuWork.f8;
    *(u16 *)(q + 4) = (*(u16 *)(q + 4) & ~0xC00) | 0xC00;
    i = gSceneOptMenuWork.f0;
    DWCi_FOCUSlDisp4(sSceneOptMenuFocusX0[i][0], sSceneOptMenuFocusX1[i][0],
                  sSceneOptMenuFocusY0[i][0], sSceneOptMenuFocusY1[i][0]);
    DWCi_ChangeScene((unsigned int)func_021C2C94);
}
