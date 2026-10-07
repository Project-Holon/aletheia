/*
 * file:     intrude_subdisp_p04.c
 * unit:     yes
 * function: func_0217CFE4, func_0217D160, func_0217D1C0
 * address:  0x0217CFE4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0217EFCC  0x0217EFCC  thumb  ov018
 *   func_020490F4  0x020490F4  arm
 *   func_0217D624  0x0217D624  thumb  ov018
 *   func_0217D720  0x0217D720  thumb  ov018
 *   func_0217D890  0x0217D890  thumb  ov018
 *   func_0217D918  0x0217D918  thumb  ov018
 *   func_0217DA54  0x0217DA54  thumb  ov018
 *   func_02049238  0x02049238  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02037174  0x02037174  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0217D5AC  0x0217D5AC  thumb  ov018
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0217EBD8  0x0217EBD8  thumb  ov018
 *   func_0217E638  0x0217E638  thumb  ov018
 *   func_0217DE68  0x0217DE68  thumb  ov018
 *   func_0217E014  0x0217E014  thumb  ov018
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217E0F4  0x0217E0F4  thumb  ov018
 *   func_0217E3D0  0x0217E3D0  thumb  ov018
 *   func_0217E4D0  0x0217E4D0  thumb  ov018
 *   func_0217E524  0x0217E524  thumb  ov018
 *   str_02183B14   0x02183B14  data  a1
 *   func_02030EAC  0x02030EAC  arm
 *   func_02082A48  0x02082A48  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 *   func_0217DE44  0x0217DE44  thumb  ov018
 *   func_0217DA90  0x0217DA90  thumb  ov018
 *   func_0217DA18  0x0217DA18  thumb  ov018
 *   func_0217D904  0x0217D904  thumb  ov018
 *   func_0217D870  0x0217D870  thumb  ov018
 *   func_0217D6C8  0x0217D6C8  thumb  ov018
 *   func_020120F4            0x020120F4  thumb
 *   func_0201283C            0x0201283C  thumb
 *   func_0201058C            0x0201058C  thumb
 *   func_0217F008            0x0217F008  thumb  ov018
 *   func_02012B70            0x02012B70  thumb
 *   func_020061E4            0x020061E4  thumb
 *   func_020310C4            0x020310C4  arm
 *   func_0201C4E4            0x0201C4E4  thumb
 *   func_02045770            0x02045770  arm
 *   func_0201C6C4            0x0201C6C4  thumb
 *   func_02045334            0x02045334  arm
 *   func_020257D0            0x020257D0  thumb
 *   func_0217F0FC            0x0217F0FC  thumb  ov018
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0217EC7C            0x0217EC7C  thumb  ov018
 *   func_0215841C            0x0215841C  thumb  ov010
 *   func_0203D1C0            0x0203D1C0  arm
 *   func_021746AC            0x021746AC  thumb  ov011
 *   func_02158428            0x02158428  thumb  ov010
 *   func_0201210C            0x0201210C  thumb
 *   func_02188CCC            0x02188CCC  thumb  ov021
 *   func_02034714            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 */
#include "../../matched/include/Obj02674.h"
#include "../../matched/include/Obj00703.h"
#include "../../matched/include/Obj00399.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT_SUB (*(volatile u16 *)0x04001050)
struct Ctx;
struct State;
struct Rec44;
struct Node;
struct BigObj;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Tcbl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8;

u32 func_02012138(const struct Ctx *p);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
void func_0217EFCC(char *p, char *q);
void *func_020490F4(u32 id, u32 heap);
void func_0217D624(struct State *o);
void func_0217D720(u8 *w, void *bg);
void func_0217D890(u8 *w);
void func_0217D918(u8 *w, void *bg);
void func_0217DA54(void *p, void *bg);
void func_02049238(void *bg);
void func_0203D34C(u32 a, u32 b);
void func_02037174(void);
void *func_020056A0(void (*cb)(void), void *arg, int pri);
void func_0217D5AC(int a0, u8 *p);
u8 *func_020120F8(const struct Ctx *p);
u16 func_02012AC8(const struct Rec44 *p);
void *func_0217EBD8(u8 *p);
void func_0217E638(u8 *w, int);
void func_0217DE68(u8 *w, int);
void func_0217E014(u8 *w, int);
int func_02158344(int a0);
void func_0217E0F4(u8 *w, u8 *, int);
void func_0217E3D0(u8 *w, int, int);
void func_0217E4D0(int *p, int a1);
void func_0217E524(u8 *w, int);
extern void func_02030EAC(struct Node *n);
extern void func_02082A48();
extern u32 func_020307B0(void *p);
extern void func_02037190();
extern void func_0217DE44(void **p);
extern void func_0217DA90(void **p);
extern void func_0217DA18(u32 *p);
extern void func_0217D904(char *p);
extern void func_0217D870();
extern void func_0217D6C8(int *p);
void *func_020120F4(const struct Ctx *p);
u32 func_0201283C(const struct BigObj *p);
u32 func_0201058C(void *key);
void func_0217F008(char *p, char *q);
int func_02012B70(const struct BigObj *p);
void func_020061E4(u32 a);
void func_020310C4(struct Tcbl *p);
u32 func_0201C4E4(struct PrintSys *ps);
void *func_02045770(struct Descriptor *p);
u32 func_0201C6C4(struct PrintSys *p, void *v);
void func_02045334(struct Descriptor *d);
void func_020257D0(struct Obj *o);
int func_0217F0FC(u8 *w);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
void func_0217EC7C(u8 *p, u8 *w, int q);
u8 func_0215841C(void *p);
u32 func_0203D1C0(u32 index);
int func_021746AC(char *a, int b);
u8 func_02158428(u8 *p);
void *func_0201210C(const struct Ctx *p);
u32 func_02188CCC(u8 *p);
void func_02034714(const char *expr, u32 line, const char *file);
u8 *func_0217CFE4(void *a);
void func_0217D160(int a0);
void func_0217D1C0(u8 *w, int b);
extern char str_02183B14[];
extern char str_02183B28[];


u8 *func_0217CFE4(void *a)
{
    void *s;
    u8 *w;
    u8 *p;
    void *bg;
    int i;
    int q;
    int k;
    u32 tmp;

    s = (void *)func_02012138(a);
    w = func_02030734(0x70, 0x170, 1, str_02183B14, 0x240);
    ((struct Obj02674 *)w)->f0 = a;
    w[0x105] = 0xFF;
    w[0x11B] = 0xFF;
    w[0x169] = 4;
    w[0x16A] = 4;
    ((struct Obj02674 *)w)->f10A = -1;
    for (i = 0; i < 3; i++) {
        *(u16 *)(w + 0xF0 + i * 8) = 0x1AB;
    }
    p = 0;
    if (func_02026454(s) == 2) {
        p = (u8 *)func_02026474(s);
    }
    if (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 1) {
        p = 0;
    }
    func_0217EFCC((char *)w, (char *)p);
    w[0x11E] = w[0xDA];
    bg = func_020490F4(0x24, 0x15);
    func_0217D624((struct State *)w);
    func_0217D720(w, bg);
    func_0217D890(w);
    func_0217D918(w, bg);
    func_0217DA54(w, bg);
    func_02049238(bg);
    func_0203D34C(0, 0x15);
    func_02037174();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    ((struct Obj02674 *)w)->f34 = func_020056A0((void (*)(void))func_0217D5AC, w, 10);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj02674 *)w)->f0));
    k = (int)func_0217EBD8(w);
    func_0217E638(w, q);
    func_0217DE68(w, k);
    func_0217E014(w, k);
    func_0217E0F4(w, (u8 *)func_02158344((int)s), k);
    func_0217E3D0(w, k, q);
    func_0217E4D0((int *)w, k);
    func_0217E524(w, k);
    return w;
}


void func_0217D160(int a0)
{
    func_02030EAC((struct Node *)(((struct Obj00703 *)a0)->f34));
    func_02082A48(0, 0x05000400, 2);
    func_0217DE44((void **)a0);
    func_0217DA90((void **)a0);
    func_0217DA18((u32 *)a0);
    func_0217D904((char *)a0);
    func_0217D870(a0);
    func_0217D6C8((int *)a0);
    func_020307B0((void *)a0);
    func_02037190();
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u16 *)0x04001050 = 0;
}


void func_0217D1C0(u8 *w, int b)
{
    void *s1;
    void *s2;
    u8 *p;
    int q;
    int i;
    int v;
    void *h;

    s1 = (void *)func_02012138(((struct Obj00399 *)w)->f0);
    s2 = func_020120F4(((struct Obj00399 *)w)->f0);
    p = (u8 *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj00399 *)w)->f0));
    func_0201058C((void *)func_0201283C(s2));
    func_02037174();
    if (p == 0 || (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 0)) {
        func_0217F008((char *)w, (char *)p);
    }
    if (w[0x11E] < w[0xDA]) {
        if (func_02012B70(s2) == 1) {
            func_020061E4(0x699);
        }
        w[0x11E] = w[0xDA];
    }
    func_020310C4(((struct Obj00399 *)w)->f20);
    func_0201C4E4(((struct Obj00399 *)w)->f28);
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x48] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f44)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f44);
            w[0x48] = 0;
        }
    }
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x50] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f4C)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f4C);
            w[0x50] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (func_0201C6C4(((struct Obj00399 *)w)->f28, *(void **)(w + 0xB4 + i * 4)) == 0) {
            func_020257D0(*(void **)(w + 0xC0 + i * 4));
        }
    }
    if (b == 0) {
        if (func_0217F0FC(w) == 1 || w[0x116] == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
            return;
        }
    } else {
        REG_DB_BLDCNT_SUB = 0;
    }
    if (b == 1) {
        func_0217EC7C(p, w, q);
    }
    if (p != 0 && w[0x106] == 1) {
        v = func_0215841C(s2);
        if ((int)func_0203D1C0((u8)v) == 0) {
            w[0x106] = 0;
            return;
        }
        switch (w[0x107]) {
        case 0:
            if (func_021746AC((char *)p, (u8)v) == 1) {
                w[0x107]++;
            }
            break;
        case 1:
            if (func_02158428(p) == 1) {
                func_02188CCC(func_0201210C(((struct Obj00399 *)w)->f0));
                ((struct Obj00399 *)w)->f110 = 0x126;
                w[0x112] = 1;
                w[0x106] = 0;
            }
            break;
        default:
            func_02034714(str_02183B28, 0, str_02183B28);
            break;
        }
    }
}
