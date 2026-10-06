/*
 * function: func_021CD2A0
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD2A0.c \n *       --func func_021CD2A0 --addr 0x021CD2A0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021CF404  0x021CF404  arm  ov016
 *   func_02082A90  0x02082A90  arm
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_0205B98C  0x0205B98C  arm
 *   func_02088234  0x02088234  arm
 *   func_0205BFEC  0x0205BFEC  arm
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DA898     0x021DA898  data
 *   func_021CD4F4  0x021CD4F4  arm  ov016
 */

typedef struct { unsigned char pad[0xF4]; unsigned char ap; } SettingInfo;
typedef struct { unsigned char pad0[10]; unsigned char channel; unsigned char pad1[9]; } ACConfig;

extern ACConfig g_021DA898;
struct NCFGApInfo;
struct tagDWCACConfig;
extern char *func_021CF404(void);
extern void func_02082A90(void *srcp, void *destp, unsigned long size);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern int func_0205B98C(struct tagDWCACConfig *config);
extern void func_02088234(void);
extern void func_0205BFEC(int no, struct NCFGApInfo *info);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CD4F4(void *task);

void func_021CD2A0(void)
{
    SettingInfo *info;
    ACConfig config;
    int scene;
    info = (SettingInfo *)func_021CF404();
    func_02082A90(&g_021DA898, &config, 0x14);
    func_021C0EA0(0, (unsigned int *)((void **)&scene));
    if (scene == 2)
        config.channel = 4;
    else
        config.channel = info->ap + 1;
    if (func_0205B98C((struct tagDWCACConfig *)(&config)) == 0)
        func_02088234();
    if (scene == 0)
        func_0205BFEC(info->ap, (struct NCFGApInfo *)info);
    func_021D7680(0, func_021CD4F4, 0, 0x78);
}
