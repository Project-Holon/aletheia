/*
 * file:     monolith_tool_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6250, func_021B6458, func_021B64D0
 * address:  0x021B6100
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02031324  0x02031324  arm
 *   func_02028470  0x02028470  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_021B69AC  0x021B69AC  thumb  ov071
 *   func_021B652C  0x021B652C  thumb  ov071
 *   func_021B6540  0x021B6540  thumb  ov071
 *   func_021B65B4  0x021B65B4  thumb  ov071
 *   func_021B6644  0x021B6644  thumb  ov071
 *   func_021B6790  0x021B6790  thumb  ov071
 *   func_021B6844  0x021B6844  thumb  ov071
 *   func_021B68E0  0x021B68E0  thumb  ov071
 *   func_021B699C  0x021B699C  thumb  ov071
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0202208C  0x0202208C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0217440C  0x0217440C  thumb  ov011
 *   func_0217446C  0x0217446C  thumb  ov011
 *   func_020221A4  0x020221A4  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02031348  0x02031348  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02031330  0x02031330  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   d_021BA774     0x021BA774  data  a4
 *   func_0203133C  0x0203133C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02010F8C  0x02010F8C  thumb
 *   func_021B6960  0x021B6960  thumb  ov071
 *   func_021B68B4  0x021B68B4  thumb  ov071
 *   func_021B6808  0x021B6808  thumb  ov071
 *   func_021B677C  0x021B677C  thumb  ov071
 *   func_021B6624  0x021B6624  thumb  ov071
 *   func_021B6588  0x021B6588  thumb  ov071
 *   func_021B6538  0x021B6538  thumb  ov071
 *   func_021B6524  0x021B6524  thumb  ov071
 *   func_02049238  0x02049238  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021BA7D4     0x021BA7D4  data  ov071  a4
 *   d_021BA764     0x021BA764  data  a4
 */
#include "../../matched/include/Obj00712.h"

struct S02021D50;
struct W6844;
struct Obj0203159C;
struct Ctx;
struct PrintSys;
struct Tcbl;
struct Node;
struct PalAnmSlot;
struct S020314B8;
struct S020315D4;
struct DispConfig;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
} Pair;

extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0204363C(u32 a);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02010F7C(u32 heap);
extern void *func_02031324(int a0);
extern void func_02028470(u8 *p, u32 v);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021B69AC(u8 *a, u8 *b);
extern void func_021B652C(void);
extern unsigned int func_021B6540(int *p);
extern void func_021B65B4(void);
extern void func_021B6644(void *a, void *b);
extern void func_021B6790(int *p);
extern void func_021B6844(struct W6844 *p);
extern void func_021B68E0(int *p);
extern void func_021B699C(void *unused, struct S02021D50 **p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_0200FB24(void);
extern u32 func_0217440C(void);
extern u32 func_0217446C(void);
extern u32 func_020221A4(void);
extern u32 func_0202648C(void *obj);
extern u32 func_02026454(void *obj);
extern void func_02031348(int h, int id, int a, void *b);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_02031330(void *h);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
int func_021B6100(struct Obj0203159C *ctx, int unused, u8 *arg);
int func_021B6250(int a, int *seq, void **pwk, u8 *mywk);
int func_021B6458(int a, int b, int c, int *w);
void func_021B64D0(void);
extern Pair d_021BA774[];
extern char d_021BA7D4;
extern char d_021BA764;


int func_021B6100(struct Obj0203159C *ctx, int unused, u8 *arg)
{
    u8 *o;

    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0207D63C(0x04000050, 4, 8, 0xF, 0xF);
    func_0207D63C(0x04001050, 4, 8, 0xF, 0xF);
    func_0204363C(1);
    func_0203064C(1, 0x61, 0x70000);
    o = func_0203159C(ctx, 0x13C, 0x61);
    func_02082BCC(o, 0, 0x13C);
    o[0xF1] = 0x30;
    func_021B69AC(o, arg);
    *(int *)(o + 0x30) = (int)func_020490F4(0x27, 0x61);
    func_021B64D0();
    func_021B652C();
    func_021B6540((int *)o);
    func_021B65B4();
    func_021B6644(o, o);
    func_021B6790((int *)o);
    func_021B6844((struct W6844 *)o);
    func_021B68E0((int *)o);
    *(int *)(o + 0x34) = (int)func_02010F7C(0x61);
    *(int *)(o + 0x12C) = (int)func_02031324(0x61);
    *(int *)(o + 0x130) = (int)func_02031324(0x61);
    func_02028470(o + 0x38, 6);
    *(u32 *)(o + 0x128) = func_020056A0((void (*)(void))func_021B699C, o, 0xA);
    func_0203D34C(0, 0x61);
    *(u8 **)(o + 0xF8) = arg;
    *(u8 **)(o + 0xFC) = o;
    *(u8 **)(o + 0x100) = o + 0xF0;
    return 1;
}


int func_021B6250(int a, int *seq, void **pwk, u8 *mywk)
{
    void *h;
    u8 *r;
    int s1;
    int s2;
    u8 k;

    h = (void *)func_02012138(*pwk);
    r = (u8 *)func_02158344((int)h);
    switch (*seq) {
    case 0:
        func_0202208C(0, 1, 1, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 1:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (func_0217440C() == 1)
            (*seq)++;
        break;
    case 2:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0200FB24() != 0 || (r == 0 && func_0202648C(h) != 0) || (r == 0 && func_02026454(h) == 2))
            mywk[0x126] = 1;
        if (mywk[0x126] == 0) {
            if (mywk[0x135] == 0) {
                func_02031348(((struct Obj00712 *)mywk)->f12C, -1, d_021BA774[mywk[0x134]].a, mywk + 0xF8);
                mywk[0x135] = 1;
            }
            if (mywk[0x136] == 0) {
                func_0201DD78(0xF, 2, 0);
                func_02031348(((struct Obj00712 *)mywk)->f130, -1, d_021BA774[mywk[0x134]].b, mywk + 0xF8);
                mywk[0x136] = 1;
            }
        }
        s2 = func_02031330((void *)((struct Obj00712 *)mywk)->f130);
        k = mywk[0x124];
        if (k == 4 || (s2 != 1 && mywk[0x126] == 1)) {
            mywk[0x125] = 1;
        } else if (mywk[0x134] != k && d_021BA774[mywk[0x134]].a != d_021BA774[k].a) {
            mywk[0x125] = 1;
        }
        s1 = func_02031330((void *)((struct Obj00712 *)mywk)->f12C);
        if (s1 == 1 && s2 == 1)
            break;
        if (mywk[0x126] == 1 || mywk[0x124] == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            mywk[0x134] = mywk[0x124];
            if (s1 != 1) {
                mywk[0x135] = 0;
                mywk[0x125] = 0;
            }
            if (s2 != 1)
                mywk[0x136] = 0;
        }
        break;
    case 4:
        func_0202208C(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (func_0217446C() == 1)
            (*seq)++;
        break;
    case 6:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    func_020310C4(((struct Obj00712 *)mywk)->f18);
    func_0201C4E4((struct PrintSys *)(((struct Obj00712 *)mywk)->f8));
    func_0204A600();
    return 0;
}

/*
 * Byte-correct. Blocker: func_02010F8C (arm9 unlabelled tail-call stub,
 * Ilias's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: func_020307B0 0x020307B0 arm):
 *   void func_02010F8C(void *p) { void func_020307B0(void *); func_020307B0(p); }
 */
int func_021B6458(int a, int b, int c, int *w)
{
    void func_0203133C(struct S020314B8 *p);
    void func_02030EAC(struct Node *n);
    void func_02010F8C(void *p);
    void func_021B6960(u32 *p);
    void func_021B68B4(void **p);
    void func_021B6808(void **p);
    void func_021B677C(u32 *p);
    void func_021B6624(void);
    void func_021B6588(struct PalAnmSlot **p);
    void func_021B6538(void);
    void func_021B6524(void);
    void func_02049238(int);
    void func_020315D4(struct S020315D4 *p);
    void func_020306F0(u32 heap);

    func_0203133C((struct S020314B8 *)w[0x12c / 4]);
    func_0203133C((struct S020314B8 *)w[0x130 / 4]);
    func_02030EAC((struct Node *)w[0x128 / 4]);
    func_02010F8C((void *)w[0x34 / 4]);
    func_021B6960((u32 *)w);
    func_021B68B4((void **)w);
    func_021B6808((void **)w);
    func_021B677C((u32 *)w);
    func_021B6624();
    func_021B6588((struct PalAnmSlot **)w);
    func_021B6538();
    func_021B6524();
    func_02049238(w[0x30 / 4]);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x61);
    return 1;
}

void func_021B64D0(void)
{
    void func_020433E0(const struct DispVram *c);
    void func_0203F8F4(u16 heapId);
    void func_0203FC28(struct DispConfig *cfg);
    void func_02082A7C(int, int, int);

    func_020433E0((const struct DispVram *)(&d_021BA7D4));
    func_0203F8F4(0x61);
    func_0203FC28((struct DispConfig *)(&d_021BA764));
    func_02082A7C(0, 0x06000000, 0x80000);
    func_02082A7C(0, 0x06200000, 0x20000);
    func_02082A7C(0, 0x06400000, 0x40000);
    func_02082A7C(0, 0x06600000, 0x20000);
}
