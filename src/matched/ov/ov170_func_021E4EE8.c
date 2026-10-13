/*
 * function: func_021E4EE8
 * address: 0x021E4EE8
 * packet: pkt_ov170_021E4EE8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021EF480 0x021EF480 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 */
struct WinMgr;
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020355C4(void);
extern unsigned POKEPARTY_GetCount(void *);
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
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(char **p, int idx, int v);
extern int func_021EA83C(char *p, int a);
extern int func_021E8F50(char *p, int v);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern void func_021EBC58(unsigned char *, int, int, int);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
int func_021E4EE8(unsigned char *p)
{
    func_021EBA5C(WORK(p), 0x1b);
    func_021ED6E4((char **)p, 0);
    func_021DD14C((char *)p);
    if (func_020355C4() == 0)
        func_020260F4(OBJ(p), 1);
    if (func_021EF480(MGR(p)) == 1) {
        func_020260E4(OBJ(p), p[0x16] - 0x1e);
        func_021EE3E4((char **)p, p[0x16] - 0x1e);
        func_021EF68C(WORK(p));
        return 0x27;
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021EF670(WORK(p));
        return 0x23;
    }
}
