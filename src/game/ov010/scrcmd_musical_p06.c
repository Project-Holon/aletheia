/*
 * file:     scrcmd_musical_p06.c
 * unit:     yes
 * function: func_0215E184, func_0215E1C0, func_0215E2B8, func_0215E31C
 * address:  0x0215E184
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_021FD910  0x021FD910  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009370  0x02009370  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021B76F8  0x021B76F8  thumb  ov021
 *   func_021B7794  0x021B7794  thumb  ov021
 *   func_021B76B4  0x021B76B4  thumb  ov021
 *   func_021B7740  0x021B7740  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EF5C  0x0201EF5C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02013EC0  0x02013EC0  thumb
 *   func_020493D4  0x020493D4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204944C  0x0204944C  arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02172928 0x02172928 data a1
 */
#include "../../matched/include/Obj00005.h"

struct Big;
struct Ctx;
struct Sub02009448Obj;
struct WordSet;
struct Sub02009210Obj;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct R {
    u8 pad00[7];
    u8 f7;
};

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern int func_02012F80(char *base);
extern int func_02156BAC();
extern u32 func_02156BCC(void *p);
extern int func_021FD910();
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *c, void *vm);
extern u16 func_0215A5CC(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021B76F8(void *p, int key, void *q);
extern void *func_021B7794(void *p);
extern void func_021B76B4(void *a0, int a1, int a2);
extern void *func_021B7740(void *p, int key, void *q, int idx);
extern void func_0215897C(void *a, void *b);
extern void *func_02158F74(void *p);
extern void func_0201EF5C(struct WordSet *p, u32 i, u32 v);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_02013EC0(u32 id);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
int func_0215E184(int a0, int a1);
int func_0215E1C0(void *c, void *vm);
int func_0215E2B8(struct R *r, int a, int b, int n);
void *func_0215E31C(u32 heap);
void func_0215E334(void *p);
extern const char d_02172928[];


/*
 * blocked:
 */
int func_0215E184(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E18E:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215E194:
    a0 = func_02012F80(v1);
loc_0215E198:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BAC(a0);
loc_0215E1A0:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BCC((void *)a0);
loc_0215E1A6:
    if (a0 != 1) goto loc_0215E1AE;
loc_0215E1AA:
a0 = 1;
    return a0;
loc_0215E1AE:
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
    a0 = func_021FD910(a0);
loc_0215E1B4:
    if (a0 != 1) goto loc_0215E1BC;
loc_0215E1B8:
a0 = 1;
    return a0;
loc_0215E1BC:
a0 = 0;
    return a0;}


/*
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the save-data block func_02009448 returns;
 * sub-commands 0, 1 and 4 write a halfword result through the destination
 * variable, 5 formats a value into the word set.
 */
int func_0215E1C0(void *c, void *vm)
{
    u32 cmd;
    u16 *dst;
    u16 v;
    void *sys;
    void *x;
    void *blk;
    u32 lim;
    void *t;
    void *ws;

    cmd = func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    v = func_0215A5CC(vm);
    sys = func_0215A5DC(vm);
    x = func_0215A5E4(vm);
    blk = func_02009448(func_02012EBC(x));
    lim = (int)func_02009370(blk);
    if (func_0201210C(sys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *dst = (int)func_02009370(blk) > 0 ? 1 : 0;
        break;
    case 1:
        if (func_021B76F8(x, v, blk) < lim) {
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 2:
        t = func_021B7794(sys);
        func_0215897C(func_0215A5F4(vm), t);
        return 1;
    case 3:
        func_021B76B4(x, v, (int)blk);
        break;
    case 5:
        ws = func_02158F74(func_0215A5F4(vm));
        func_0201EF5C(ws, 0, (u32)func_021B7740(x, v, blk, *dst));
        break;
    case 4:
        *dst = func_021B76F8(x, v, blk);
        break;
    }
    return 0;
}


int func_0215E2B8(struct R *r, int a, int b, int n)
{
    u32 q;
    int v;

    func_02082BCC(r, 0, 0xe8);
    v = func_02013EC0(b);
    if (v == 0xffff) {
        return 0;
    }
    q = func_020493D4((struct ArcFile *)a, v) / 0xe8;
    if (q != 1 && q != 4) {
        return 0;
    }
    if (q == 1) {
        n = 0;
    }
    func_0204944C((struct ArcFile *)a, v, n * 0xe8, 0xe8, r);
    r->f7 |= 0x80;
    return 1;
}

void *func_0215E31C(u32 heap)
{
    return func_02030734(heap, 32, 1, d_02172928, 45);
}

void func_0215E334(void *p)
{
    func_020307B0(p);
}
