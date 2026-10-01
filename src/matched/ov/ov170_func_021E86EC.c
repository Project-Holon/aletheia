/*
 * function: func_021E86EC
 * address: 0x021E86EC
 * packet: pkt_ov170_021E86EC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EA83C 0x021EA83C thumb ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EBC28 0x021EBC28 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 */
extern void func_021ED55C(char **p, int flag);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern void func_021EF57C(int mgr);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0190(unsigned char *p);
extern void func_020061E4(unsigned se);
extern int func_021EA83C(unsigned char *p, int sel);
extern void func_021EE008(unsigned char *p, int a, int b);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EBC28(unsigned char *p, int a, int b);
extern void func_021EE038(char *p, int a, int b, int c);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int func_021E86EC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        *(unsigned char *)(WORK(p) + 0xA17A) = 1;
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        func_021EF57C(*(int *)(WORK(p) + 0x74));
        STEP(p)++;
        return func_021E8FC0(p, func_021E0190, 0x60);
    case 1:
        p[0x19] = p[0x14];
        STEP(p)++;
        func_020061E4(0x669);
        return func_021EA83C(p, 0x60);
    case 2:
        STEP(p) = 0;
        func_021EE008(p, 0, 1);
        func_021EE364((char **)p, 0xC, 1);
        *(int *)(WORK(p) + 0xA168) = 1;
        func_021EBC28(p, 1, 0x19);
        func_021EE038((char *)p, 0, 1, 1);
        return 0x61;
    }
    return 0x60;
}
