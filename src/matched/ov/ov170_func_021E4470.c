/*
 * function: func_021E4470
 * address: 0x021E4470
 * packet: pkt_ov170_021E4470
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021EA83C 0x021EA83C thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
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
extern void func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(unsigned char *, int, int);
extern int func_021EA83C(unsigned char *, int);
extern int func_021E8F50(char *p, int v);
extern int func_021E8FC0(unsigned char *, int (*)(unsigned char *), int);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern void func_021EBC58(unsigned char *, int, int, int);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
int func_021E4470(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EC000(WORK(p), 4, 0);
        func_021EF3A0(MGR(p));
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0(p, func_021E01B0, 0x22);
    case 1:
        func_020061E4(0x669);
        p[0x19] = p[0x14];
        STEP(p)++;
        return func_021EA83C(p, 0x22);
    case 2:
        func_021EE364(p, 4, 0x27);
        func_021EF670(WORK(p));
        *(int *)(WORK(p) + 0xa168) = 0x27;
        STEP(p) = 0;
        return 0x15;
    }
    return 0x22;
}
