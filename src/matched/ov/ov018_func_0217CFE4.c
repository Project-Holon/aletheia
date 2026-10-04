/*
 * function: func_0217CFE4
 * address:  0x0217CFE4
 * packet:   pkt_ov018_0217CFE4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */
#include "../include/Obj02674.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8;

extern char str_02183B14[];

struct Ctx;
u32 func_02012138(const struct Ctx *p);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
void func_0217EFCC(u8 *w, u8 *p);
void *func_020490F4(unsigned int id, u16 heap);
void func_0217D624(u8 *w);
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
struct Rec44;
u16 func_02012AC8(const struct Rec44 *p);
void *func_0217EBD8(u8 *p);
void func_0217E638(u8 *w, int);
void func_0217DE68(u8 *w, int);
void func_0217E014(u8 *w, int);
int func_02158344(int a0);
void func_0217E0F4(u8 *w, u8 *, int);
void func_0217E3D0(u8 *w, int, int);
void func_0217E4D0(u8 *w, int);
void func_0217E524(u8 *w, int);

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)

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
    func_0217EFCC(w, p);
    w[0x11E] = w[0xDA];
    bg = func_020490F4(0x24, 0x15);
    func_0217D624(w);
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
    func_0217E4D0(w, k);
    func_0217E524(w, k);
    return w;
}
