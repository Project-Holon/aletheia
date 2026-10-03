/*
 * function: func_021E85F0
 * address: 0x021E85F0
 * packet: pkt_ov170_021E85F0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 */
struct WinMgr;
extern void func_021ED55C(char *, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *);
extern void func_021EE038(char *, int, int, int);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *, int, int);
extern int func_021E0190(char *);
extern void func_021ED888(char *, int);
extern void func_021ED508(char *, int, int);
extern void func_021ECB20(char *, int, int);
extern void func_021EF670(char *);
extern void func_021EE364(char *, int, int);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int func_021E85F0(char *p)
{
    switch (S) {
    case 0:
        func_021ED55C(p, 0);
        func_021EBA5C(W, 24);
        func_021DD14C(p);
        func_021EE038(p, 0, 0, 1);
        func_021EF57C(*(struct WinMgr **)(W + 0x74));
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x5f);
    case 1:
        S = 0;
        func_021ED888(W, 1);
        func_021ED508(p, 14, 1);
        if (*(int *)(*(char **)p + 0x24) == 2) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364(p, 3, 30);
            return 17;
        } else if (*(int *)(*(char **)p + 0x24) == 1) {
            func_021ECB20(p, 1, 0);
            func_021EE364(p, 2, 30);
            return 44;
        } else if (*(int *)(*(char **)p + 0x24) == 3) {
            func_021ECB20(p, 0x81, 1);
            func_021EF670(W);
            func_021EE364(p, 7, 30);
            return 57;
        } else if (*(int *)(*(char **)p + 0x24) == 4) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364(p, 13, 30);
            return 35;
        }
    }
    return 0x5f;
}
