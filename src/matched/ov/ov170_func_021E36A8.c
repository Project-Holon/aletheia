/*
 * function: func_021E36A8
 * address: 0x021E36A8
 * packet: pkt_ov170_021E36A8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF0BC 0x021DF0BC thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EF34C 0x021EF34C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021EC5A0 0x021EC5A0 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 */
struct WinMgr;
extern void func_021DF0BC(unsigned char *);
extern void func_021DD14C(unsigned char *);
extern void func_021ED888(char *, int);
extern void func_021ECB20(unsigned char *, int, int);
extern void func_021ED55C(char **, int);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **, int);
extern void func_020061E4(unsigned);
extern int func_021E8FC0(unsigned char *, int (*)(unsigned char *), int);
extern int func_021E01B0(unsigned char *);
extern void func_021DEFEC(unsigned char *, int);
extern void func_021EF68C(char *);
extern void func_021EE364(unsigned char *, int, int);
#define W(p) (*(char **)((p) + 0x2C))
int func_021E36A8(unsigned char *p)
{
    switch (*(int *)(W(p) + 0xA194)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C(p);
        func_021ED888(W(p), 0);
        func_021ECB20(p, 1, 1);
        func_021ED55C((char **)p, 0);
        func_021EF34C(*(struct WinMgr **)(W(p) + 0x74));
        func_021EF36C(*(struct WinMgr **)(W(p) + 0x74));
        func_021EC5A0((char **)p, 0);
        if (*(int *)(*(char **)p + 0x24) == 3)
            func_021ECB20(p, 0x82, 1);
        func_020061E4(0x669);
        (*(int *)(W(p) + 0xA194))++;
        return func_021E8FC0(p, func_021E01B0, 0x1A);
    case 1:
        *(int *)(W(p) + 0xA194) = 0;
        func_021DEFEC(p, 0x1E);
        func_021EF68C(W(p));
        if (*(int *)(*(char **)p + 0x24) == 3) {
            func_021EE364(p, 8, 0);
            return 0x46;
        } else {
            func_021EE364(p, 5, 0);
            return 0x1B;
        }
    }
    return 0x1A;
}
