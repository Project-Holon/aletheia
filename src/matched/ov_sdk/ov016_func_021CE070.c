/*
 * function: DWCi_SceneSetUsbReady1
 * address:  0x021CE070
 * packet:   pkt_ov016_021CE070
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetUsbReady1 (libdwcutil.TWL.HYB.a scenesetusbready)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE070.c \n *       --func DWCi_SceneSetUsbReady1 --addr 0x021CE070 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   gSceneSetUsbReady1Work     0x021DE62C  data
 *   func_021CE108  0x021CE108  arm  ov016
 *   DWCi_HLlLoad  0x021BD674  arm  ov016
 *   DWCi_CMNlStep  0x021BD214  arm  ov016
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DWCi_CMNlMsgNameDraw  0x021BD310  arm  ov016
 *   DWCi_ANIMElInitEx  0x021BC820  arm  ov016
 *   DWCi_USBAPlBegin  0x021D0B44  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CE45C  0x021CE45C  arm  ov016
 *   func_021CE1B0  0x021CE1B0  arm  ov016
 */

typedef struct {
    unsigned char favoriteColor;
    unsigned char pad;
    unsigned char birthMonth;
    unsigned char birthDay;
    unsigned short nickName[11];
    unsigned short nickNameLength;
    unsigned short comment[27];
    unsigned short commentLength;
} OwnerInfo;

extern unsigned char gSceneSetUsbReady1Work;
extern void func_021CE108(void);
extern void DWCi_HLlLoad(int idx);
extern void DWCi_CMNlStep(int step);
struct OSOwnerInfo;
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern void MIi_CpuClear16(unsigned short value, void *destp, unsigned long size);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void DWCi_CMNlMsgNameDraw(unsigned short *name, int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern int DWCi_USBAPlBegin(void (*callback)(int));
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CE45C(int state);
extern void func_021CE1B0(void);

void DWCi_SceneSetUsbReady1(void)
{
    OwnerInfo info;
    unsigned short buf[11];
    gSceneSetUsbReady1Work = 0;
    func_021CE108();
    DWCi_HLlLoad(8);
    DWCi_CMNlStep(2);
    OS_GetOwnerInfo((struct OSOwnerInfo *)(&info));
    MIi_CpuClear16(0, buf, 0x16);
    MIi_CpuCopy16(info.nickName, buf, info.nickNameLength * 2);
    DWCi_CMNlMsgNameDraw(buf, 40);
    DWCi_ANIMElInitEx(0);
    DWCi_USBAPlBegin(func_021CE45C);
    DWCi_SNDlPlay(11);
    DWCi_ChangeScene((unsigned int)func_021CE1B0);
}
