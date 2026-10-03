/*
 * function: func_021E49CC
 * address: 0x021E49CC
 * packet: pkt_ov170_021E49CC
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
extern void func_020061E4(unsigned);
extern void func_020260E4(void *, unsigned char);
extern void func_020260F4(void *, int);
extern int func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021DD14C(unsigned char *);
extern void func_021DF0BC(unsigned char *);
extern void func_021DEFEC(unsigned char *, int);
extern void func_021EBA5C(char *, int);
extern void func_021ED6E4(unsigned char *, int);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
extern void func_021ED508(unsigned char *, int, int);
extern void func_021ED888(char *, int);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021EC000(char *, int, int);
extern int func_021EBFEC(char *, int);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(unsigned char *, int, int);
extern void func_021EC5A0(unsigned char *, int);
extern void func_021EE364(unsigned char *, int, int);
extern int func_021EA83C(unsigned char *, int);
extern int func_021E8F50(unsigned char *, int);
extern int func_021E8FC0(unsigned char *, int (*)(unsigned char *), int);
extern int func_021E0190(unsigned char *);
extern int func_021E01B0(unsigned char *);
extern void func_021EBC58(unsigned char *, int, int, int);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
int func_021E49CC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C(p);
        func_021ED888(WORK(p), 0);
        func_021ECB20(p, 1, 1);
        func_021ED55C((char **)p, 0);
        func_021EF34C(MGR(p));
        func_021EF36C(MGR(p));
        func_021EC5A0(p, 0);
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0(p, func_021E01B0, 0x26);
    case 1:
        STEP(p) = 0;
        func_021DEFEC(p, 0x1e);
        func_021EF68C(WORK(p));
        func_021EE364(p, 0xe, 0);
        return 0x27;
    }
    return 0x26;
}
