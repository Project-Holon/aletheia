/*
 * function: func_021CD458
 * address:  0x021CD458
 * packet:   pkt_ov016_021CD458
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * symbols:
 *   DWCi_SETTINGlGetMemMap  0x021CFBD4  arm  ov016
 *   DWC_AC_Destroy  0x0205BE6C  arm
 *   DWCi_BACKUPlGetWifi  0x020589C4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWCi_ANIMElEnd  0x021BC8EC  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneSetTestWork     0x021DE61C  data
 *   DWCi_SceneSetError  0x021C7CE4  arm  ov016
 *   DWCi_SceneSetTestCompletet  0x021CD580  arm  ov016
 */

extern void *DWCi_SETTINGlGetMemMap(void);
extern int DWC_AC_Destroy(void);
extern void *DWCi_BACKUPlGetWifi();
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern unsigned char gSceneSetTestWork;
extern void DWCi_SceneSetError(void);
extern void DWCi_SceneSetTestCompletet(void);

void func_021CD458(void)
{
    unsigned char *map = DWCi_SETTINGlGetMemMap();
    if (DWC_AC_Destroy() == 0)
        return;
    MI_CpuCopy8(DWCi_BACKUPlGetWifi(), map + 0xF0, 14);
    MI_CpuCopy8(DWCi_BACKUPlGetWifi(), map + 0x1F0, 14);
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 21);
    if (gSceneSetTestWork == 0) {
        DWCi_SetParam_(0, (unsigned int)((void *)1));
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetError);
    } else {
        DWCi_SetParam_(0, (unsigned int)((void *)1));
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetTestCompletet);
    }
}
