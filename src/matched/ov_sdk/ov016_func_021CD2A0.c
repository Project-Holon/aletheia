/*
 * function: initAc
 * address:  0x021CD2A0
 * packet:   pkt_ov016_021CD2A0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      initAc (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD2A0.c \n *       --func initAc --addr 0x021CD2A0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_SETTIGNlGet  0x021CF404  arm  ov016
 *   MIi_CpuCopy32  0x02082A90  arm
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWC_AC_Create  0x0205B98C  arm
 *   OS_Terminate  0x02088234  arm
 *   DWCi_AC_InsertApInfo  0x0205BFEC  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   sSceneSetTestConfig     0x021DA898  data
 *   func_021CD4F4  0x021CD4F4  arm  ov016
 */

typedef struct { unsigned char pad[0xF4]; unsigned char ap; } SettingInfo;
typedef struct { unsigned char pad0[10]; unsigned char channel; unsigned char pad1[9]; } ACConfig;

extern ACConfig sSceneSetTestConfig;
struct NCFGApInfo;
struct tagDWCACConfig;
extern char *DWCi_SETTIGNlGet(void);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern int DWC_AC_Create(struct tagDWCACConfig *config);
extern void OS_Terminate(void);
extern void DWCi_AC_InsertApInfo(int no, struct NCFGApInfo *info);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CD4F4(void *task);

void initAc(void)
{
    SettingInfo *info;
    ACConfig config;
    int scene;
    info = (SettingInfo *)DWCi_SETTIGNlGet();
    MIi_CpuCopy32(&sSceneSetTestConfig, &config, 0x14);
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene == 2)
        config.channel = 4;
    else
        config.channel = info->ap + 1;
    if (DWC_AC_Create((struct tagDWCACConfig *)(&config)) == 0)
        OS_Terminate();
    if (scene == 0)
        DWCi_AC_InsertApInfo(info->ap, (struct NCFGApInfo *)info);
    DWCi_TSKlForm(0, func_021CD4F4, 0, 0x78);
}
