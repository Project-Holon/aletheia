/*
 * function: func_021CD944
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD944.c \n *       --func func_021CD944 --addr 0x021CD944 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DA8AC     0x021DA8AC  data
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD9CC  0x021CD9CC  arm  ov016
 */

typedef struct { int m[3]; } MsgTable;
extern MsgTable g_021DA8AC;
extern int func_021D5580(int lcd);
extern void func_021C0EA0(void **param2, void **param3);
extern void func_021D1208(int msg, int type, int dark, int n, int num);
extern void func_021C0E40(void (*scene)(void));
extern void func_021CD9CC(void);

void func_021CD944(void)
{
    int prm;
    MsgTable msg = g_021DA8AC;
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_021C0EA0(0, (void **)&prm);
    func_021D1208(msg.m[prm], 1, 1, -1, 0);
    func_021C0E40(func_021CD9CC);
}
