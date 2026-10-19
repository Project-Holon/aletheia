/*
 * function: endScene2
 * address:  0x021C1DC4
 * packet:   pkt_021C1DC4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_FOCUSlDelete  0x021BD5A8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_ARClRelease  0x021D4C68  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneMenuWork   0x021DE59C  data
 *   DWCi_SceneSetSelectAp  0x021CBC90  arm
 *   DWCi_SceneOptMenu  0x021C2A3C  arm
 */

typedef unsigned char u8;

struct D {
    u8  f0;
    u8  pad01[3];
    int f4;
};

extern int  DWCi_EFFlCheck(int x);
extern void DWCi_FOCUSlDelete(void);
extern void DWCi_COMMENTlDelete(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern struct D gSceneMenuWork;
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneOptMenu(void);

void endScene2(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease((void *)gSceneMenuWork.f4);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    switch (gSceneMenuWork.f0) {
    case 0:
        DWCi_SetParam_(1, 0);
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetSelectAp);
        return;
    case 1:
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMenu);
        return;
    }
}
