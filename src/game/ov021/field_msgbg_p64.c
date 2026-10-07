/*
 * file:     field_msgbg_p64.c
 * unit:     yes
 * function: func_02190A6C, func_02190A74, func_02190AC4, func_02190ACC, func_02190AEC, func_02190B08, func_02190B1C, func_02190B2C, func_02190BE4, func_02190C78, func_02190C94, func_02190D08, func_02190D2C, func_02190D48
 * address:  0x02190A6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F8F4  0x0201F8F4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201F91C  0x0201F91C  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   d_021D3F38     0x021D3F38  data   ov021  a4
 *   d_021D3E68     0x021D3E68  data   ov021  a4
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_02190860  0x02190860  thumb  ov021
 *   func_02020D10  0x02020D10  thumb
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_0201CD10  0x0201CD10  thumb
 *   func_02193200  0x02193200  thumb  ov021
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02006238  0x02006238  thumb  arm9
 *   func_0201CE48  0x0201CE48  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj05858.h"
#include "../../matched/include/Obj17931.h"
#include "../../matched/include/Obj07432.h"
#include "../../matched/include/Obj07433.h"
#include "../../matched/include/Obj17932.h"

struct Slot;
struct StrObj;
struct Pair;
struct Rec;
struct Rec3;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02190ACC;

typedef signed short   s16_02190B08;

typedef signed char    s8;

typedef signed short   s16_02190B1C;

typedef struct Src {
    u16 a00;
    u16 a02;
    u8  a04;
    u8  a05;
    u8  a06;
    u8  a07lo : 4;
    u8  a07hi : 4;
    u8  a08lo : 4;
    u8  a08hi : 4;
    u8  pad09;
    u16 a0a_lo : 3;
    u16 a0a_mid : 4;
    u16 a0a_hi : 9;
    int a0c : 2;
    int pad0c : 30;
    u16 a10;
    u16 a12;
    u8  pad14[8];
    u32 a1c;
} Src;

typedef struct Dst {
    u8  pad00[8];
    u32 d08;
    u8  pad0c[4];
    u16 d10;
    u16 d12;
    u8  d14;
    u8  d15;
    u8  d16;
    u8  d17lo : 4;
    u8  d17hi : 4;
    u8  d18lo : 4;
    u8  d18hi : 4;
    u8  pad19;
    u16 d1a_lo : 3;
    u16 d1a_mid : 4;
    u16 d1a_z : 2;
    u16 d1a_hi : 7;
    u8  pad1c[4];
    u16 d20;
    u16 d22;
} Dst;

typedef struct Blk32 { u32 w[8]; } Blk32;

typedef struct Blk16 { u32 w[4]; } Blk16;

typedef short          s16_02190C78;

typedef struct Handle {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

typedef short          s16_02190C94;

typedef signed int     s32;

typedef short          s16_02190D08;

typedef short          s16_02190D2C;

typedef signed short   s16_02190D48;

extern void func_0201F8F4(struct Slot *s);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201F91C(struct Slot *s);
extern u32 func_0201F73C(u32, u32, u32, u32);
extern void func_02082BCC(void *p, int v, int n);
extern int func_021904B0(u32 a, u32 b);
extern u32 func_02190A28(const struct Pair *arr, int n, u32 c, u16 d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 *func_02190860(u16 *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
extern void func_02020D10(u8 *p, u32 v);
extern int func_021909E4(Handle *h);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Rec *func_0201CD10(u32 a0, s16_02190C94 a1, s16_02190C94 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern int func_02193200(u32 a);
extern void func_020061E4(u32 se);
extern int func_02006238(void);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_020307B0(void *p);
void func_02190A6C(u32 a);
u32 func_02190A74(u32 *obj, u32 *tab, u32 *out, u32 key);
unsigned func_02190AC4(void *p);
u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key);
unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d);
int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
int func_02190B1C(u32 a);
void func_02190B2C(Dst *d, const Src *s);
u32 *func_02190BE4(u16 *a, u32 b);
int func_02190C78(Handle *h);
u32 *func_02190C94(u32 *a, u32 b, u32 c, u32 d, u16 e0, u32 f, u16 g);
int func_02190D08(int x);
u32 *func_02190D2C(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f);
int func_02190D48(void *a);
extern Blk32 d_021D3F38;
extern Blk16 d_021D3E68;
extern char d_021DDA50[];


/*
 * Tail-call thunk: forwards to func_0201F8F4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02190A6C(u32 a)
{
    func_0201F8F4((struct Slot *)a);
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_02190A74(u32 *obj, u32 *tab, u32 *out, u32 key)
{
    u32 k;
    u32 bestIdx;
    u32 best;
    u32 i;

    best = 0;
    bestIdx = 0;
    i = 0;
    if (tab[0] != -1) {
        k = (u16)key;
        do {
            u32 r;
            if (tab[0] == 0) {
                break;
            }
            r = func_0201D304((struct StrObj *)tab[0], obj[2], k);
            if (r > best) {
                best = r;
                bestIdx = i;
            }
            tab += 2;
            i++;
        } while (tab[0] != -1);
    }
    *out = bestIdx;
    return best;
}


/*
 * Unlabelled leaf (tail call through a pool word), sole blocker of
 * ov010 func_0215A864's MATCH.
 */
unsigned func_02190AC4(void *p)
{
    return func_0201F91C(p);
}


u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key)
{
    u32 tmp;
    u32 x;
    u32 r;

    x = func_02190A74(obj, tab, &tmp, key);
    x += key + 0x10;
    r = x >> 3;
    if (x & 7)
        r++;
    return r;
}

/*
 * Unlabelled leaf, sole blocker of ov010 func_0215A864's MATCH.
 */
unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d)
{
    unsigned n = a * (b + c);
    unsigned r = (n + 7) >> 3;

    if (d && r * 8 - n < 6) {
        r++;
    }
    return r;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f)
{
((struct Obj05858 *)((u8 *)(a)))->f0 = b;
((struct Obj05858 *)((u8 *)(a)))->f16 = d;
((struct Obj05858 *)((u8 *)(a)))->f14 = c;
((struct Obj05858 *)((u8 *)(a)))->f18 = *(u16 *)((u8 *)((u8 *)&e0));
((struct Obj05858 *)((u8 *)(a)))->f1A = *(u16 *)((u8 *)((u8 *)&e0) + 4);
return a;
}


int func_02190B1C(u32 a)
{
return func_0201F73C(((struct Obj17931 *)((u8 *)(a)))->f8, 0, 1, 13);
}


void func_02190B2C(Dst *d, const Src *s)
{
    func_02082BCC(d, 0, 0x34);
    d->d10 = s->a00;
    d->d12 = s->a02;
    d->d14 = s->a04;
    d->d15 = s->a05;
    d->d16 = s->a06;
    d->d17lo = s->a07lo;
    d->d17hi = s->a07hi;
    d->d18lo = s->a08lo;
    d->d18hi = s->a08hi;
    d->d1a_lo = s->a0a_lo;
    d->d1a_mid = s->a0a_mid;
    d->d1a_z = s->a0c;
    d->d20 = s->a10;
    d->d22 = s->a12;
    d->d08 = s->a1c;
}


u32 *func_02190BE4(u16 *a, u32 b)
{
    Blk32 A = d_021D3F38;
    Blk16 B = d_021D3E68;
    u32 r7;
    u32 r18;
    u32 *res;

    r7 = func_021904B0((u32)a, 0xe9);
    r18 = func_02190A28((const struct Pair *)(&B), 2, r7, a[0]);
    func_02045C04((struct Rec *)r7);
    func_02190B08((u32)(&A), 2, 0x18, 0xa, 7, 4);
    res = func_02190860(a, &A, r18, 0, (u16)b, a[3], 0, 0, 0);
    func_02020D10((u8 *)res[4], 0);
    return res;
}


int func_02190C78(Handle *h)
{
    int v = func_021909E4(h);
    if (v == -1)
        return 2;
    if (v == -2)
        return 1;
    return v;
}


u32 *func_02190C94(u32 *a, u32 b, u32 c, u32 d, u16 e0, u32 f, u16 g)
{
    u32 *r;

    r = (u32 *)func_02030734(((struct Obj07432 *)a)->f0, 0xc, 1, d_021DDA50, 0x85e);
    r[2] = (u32)a;
    ((struct Obj07433 *)r)->f2 = f;
    r[1] = (u32)func_0201CD10(c, d, e0, b, a[2], f, a[0x59], 0, ((struct Obj07432 *)a)->f0, g,
                         (u32)((void *)func_02190D08));
    func_02193200(r[2] + 0x160);
    return r;
}


int func_02190D08(int x)
{
    switch (x) {
    case 3:
        func_020061E4(0x56B);
        break;
    case 6:
        return func_02006238();
    }
    return 0;
}


u32 *func_02190D2C(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f)
{
    return func_02190C94(a, b, c, d, e, f, 0xF);
}


int func_02190D48(void *a)
{
func_0201CE48((struct Rec3 *)(((struct Obj17932 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}
