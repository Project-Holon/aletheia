/*
 * function: func_021E62FC
 * address: 0x021E62FC
 * packet: pkt_ov170_021E62FC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EBFEC 0x021EBFEC thumb ov170
 *   func_021EA878 0x021EA878 thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 */
struct WinMgr;
extern void func_020061E4(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021DD14C(char *p);
extern void func_021DF0BC(unsigned char *);
extern void func_021DEFEC(char *p, int b);
extern void func_021EBA5C(char *, int);
extern void func_021ED6E4(char **p, int v);
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
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EA83C(char *p, int a);
extern int func_021E8F50(unsigned char *, int);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern void func_021EBC58(unsigned char *, int, int, int);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
int func_021E62FC(unsigned char *p)
{
    if (func_021EBFEC(WORK(p), 0xa) == 1)
        return 0x3b;
    func_021EA878(p, 0);
    func_021ED108(WORK(p), 0);
    func_021EC000(WORK(p), 0xa, 0);
    func_021EBCB4(p, 3, 0x18);
    if (p[0x16] < 0x1e) {
        func_021ECB20(p, 0x81, 1);
        func_021ED888(WORK(p), 1);
    } else {
        func_021ECB20(p, 0x82, 1);
    }
    *(unsigned short *)(WORK(p) + 0xa16c) = 0;
    *(int *)(p + 0x28) = 0x3d;
    return func_021E8F50(p, 6);
}
