/*
 * file:     unit_021CD944.c
 * unit:     yes
 * function: func_021CD944, func_021CD9CC
 * address:  0x021CD944
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021DA8AC     0x021DA8AC  data
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   DWCi_SceneSetTestConfNopA  0x021CDA0C  arm  ov016
 *   DWCi_SceneSetTestConfNopB  0x021CDA10  arm  ov016
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021CDA14  0x021CDA14  arm  ov016
 */
typedef struct { int m[3]; } MsgTable;

extern int func_021D5580(int lcd);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021C0E40(unsigned int v);
extern void DWCi_SceneSetTestConfNopA(void);
extern void DWCi_SceneSetTestConfNopB(void);
extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524(void);
extern void func_021CDA14(void);
void func_021CD944(void);
void func_021CD9CC(void);
extern MsgTable g_021DA8AC;


/*
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD944.c \n *       --func func_021CD944 --addr 0x021CD944 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD944(void)
{
    int prm;
    MsgTable msg = g_021DA8AC;
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_021C0EA0(0, (unsigned int *)((void **)&prm));
    func_021D1208(msg.m[prm], 1, 1, -1, 0);
    func_021C0E40((unsigned int)func_021CD9CC);
}


/*
 * sdk:      procScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD9CC.c \n *       --func func_021CD9CC --addr 0x021CD9CC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CD9CC(void)
{
    DWCi_SceneSetTestConfNopA();
    DWCi_SceneSetTestConfNopB();
    if (func_021D1568())
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021CFFAC(6);
    func_021C0E40((unsigned int)func_021CDA14);
}
