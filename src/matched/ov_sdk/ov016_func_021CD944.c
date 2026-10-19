/*
 * function: procInit1
 * address:  0x021CD944
 * packet:   pkt_ov016_021CD944
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD944.c \n *       --func procInit1 --addr 0x021CD944 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   sSceneSetTestConfirmMessages     0x021DA8AC  data
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CD9CC  0x021CD9CC  arm  ov016
 */

typedef struct { int m[3]; } MsgTable;
extern MsgTable sSceneSetTestConfirmMessages;
extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void DWCi_WINlInitEx(int msg, int type, unsigned char dark, int n, int num);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CD9CC(void);

void procInit1(void)
{
    int prm;
    MsgTable msg = sSceneSetTestConfirmMessages;
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_GetParam2_(0, (unsigned int *)((void **)&prm));
    DWCi_WINlInitEx(msg.m[prm], 1, 1, -1, 0);
    DWCi_ChangeScene((unsigned int)func_021CD9CC);
}
