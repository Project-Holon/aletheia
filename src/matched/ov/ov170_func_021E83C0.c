/*
 * function: func_021E83C0
 * address: 0x021E83C0
 * packet: pkt_ov170_021E83C0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Return r0 from func_021EC01C and func_021EA858 is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF5E8 0x021EF5E8 thumb ov170
 *   func_021EC01C 0x021EC01C thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021EF770 0x021EF770 thumb ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_021EF680 0x021EF680 thumb ov170
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021EF45C 0x021EF45C thumb ov170
 *   func_021EF69C 0x021EF69C thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021EB988 0x021EB988 thumb ov170
 *   func_021EF534 0x021EF534 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EBC28 0x021EBC28 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   d_021EF908 0x021EF908 data a4
 */
typedef unsigned char u8;
struct WinMgr;
typedef struct { unsigned short a; unsigned short b; } Ent;
typedef struct { u8 pad[0x1c]; u8 lo : 4; u8 hi : 4; } Flags;
extern void func_021EC000(char *, int, int);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ED888(char *, int);
extern int func_021EF5E8(struct WinMgr *mgr);
extern int func_021EC01C(char *, int);
extern void func_021ED6E4(char **, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *, int, int);
extern int func_021E0190(char *);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EE008(char *, int, int);
extern void func_021EF680(char *);
extern int func_021EA858(char *, int);
extern int func_021EF45C(struct WinMgr *mgr);
extern void func_021EF69C(char *);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021E01B0(u8 *);
extern void func_021EB988(char *, Ent *, unsigned);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021ECB20(char *, int, int);
extern void func_021EBC28(u8 *, int, int);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021ED544(char *, int);
extern Ent d_021EF908[];
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
#define M (*(struct WinMgr **)(W + 0x74))
int func_021E83C0(char *p)
{
    switch (S) {
    case 0:
        S++;
        func_021EC000(W, 4, 0);
        func_021ED508((unsigned char *)p, 14, 0);
        func_021ED888(W, 0);
        if (func_021EF5E8(M) == 1) {
            if (func_021EC01C(W, 10) == 1)
                func_021EC000(W, 10, 0);
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(W, 24);
            func_021DD14C(p);
            func_021EF57C(M);
            return func_021E8FC0(p, (int)func_021E0190, 0x5d);
        } else if (func_021EF770(M) == 1) {
            func_021EE008(p, 0, 0);
            func_021EF680(W);
            return func_021EA858(p, 0x5d);
        } else if (func_021EF45C(M) == 1) {
            func_021EF69C(W);
            func_021EF3A0(M);
            return func_021E8FC0(p, (int)func_021E01B0, 0x5d);
        } else {
            func_021EF680(W);
        }
    case 1:
        func_021EB988(p, d_021EF908, 4);
        func_021EF534(M);
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x5d);
    case 2:
        S = 0;
        func_021ECB20(p, 1, 1);
        func_021EBC28((u8 *)p, 0, 24);
        func_021EE364((char **)p, 10, 0);
        ((Flags *)p)->lo = 0;
        func_021ED544(p, 6);
        return 0x5e;
    }
    return 0x5d;
}
