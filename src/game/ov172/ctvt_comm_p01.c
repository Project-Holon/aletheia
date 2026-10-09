/*
 * file:     ctvt_comm_p01.c
 * unit:     yes
 * function: func_021B77E8, func_021B7818, func_021B7830, func_021B785C, func_021B7888, func_021B78A0, func_021B78B8, func_021B792C, func_021B796C, func_021B7B20, func_021B7B30, func_021B7B3C
 * address:  0x021B77E8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE05C  0x021BE05C  thumb  ov172
 *   func_021BE078  0x021BE078  thumb  ov172
 *   g_021C6EA8     0x021C6EA8  data   ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   g_021C6EB4    0x021C6EB4  data  ov172
 *   func_020061E4 0x020061E4 thumb
 *   func_021BE100  0x021BE100  thumb  ov172
 *   func_02085D3C  0x02085D3C  arm
 *   func_021B7B5C  0x021B7B5C  arm    ov172
 */
#include "../../matched/include/Obj06553.h"
#include "../../matched/include/Obj06554.h"
#include "../../matched/include/Obj06555.h"
#include "../../matched/include/Obj06556.h"
#include "../../matched/include/Obj24071.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    int active;
    int anim;
    int busy;
    u16 cur[4];
    u16 tgt[4];
} Ent;

typedef struct {
    u8 pad0[0x20];
    int wide;
    u8 pad24[0x10];
    Ent ent[4];
} Q;

extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 func_021BE0A4(void *p);
extern void func_020061E4(unsigned int);
extern int func_021BE100(void);
extern int func_02085D3C(int a);
extern void func_021B7B5C(int a, int b, int c);
u32 func_021B77E8(void *p);
u32 func_021B7818(void *p, void *q);
int func_021B7830(void *a0, char *a1, int a2);
u32 func_021B785C(void *p);
void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d);
void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d);
int func_021B78B8(void *p, char *q);
int func_021B792C(void *p, u16 *value, u16 *limit);
void func_021B796C(void *p, char *q, int i);
void func_021B7B20(int unused, char *base, int i);
u32 func_021B7B30(int unused, char *base, int i);
void func_021B7B3C(int x, int y, int z);
extern u32 g_021C6EA8[];
extern u32 g_021C6EB4[];



/*
 * Table lookup at g_021C6EA8; the second arm keeps the low 16 bits of the halved word.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B77E8(void *p)
{
    u32 i = func_021BE05C(p);

    if (func_021BE078(p) == 0)
        return (u16)g_021C6EA8[i];
    return (g_021C6EA8[i] << 15) >> 16;
}



/*
 * Forward three arguments, the third from func_021BE0A4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B7818(void *p, void *q)
{
    return func_021B7830(p, q, func_021BE0A4(p));
}



/*
 * Scaled offset: func_021B785C's value times a2 when the state probe passes and a2 is non-zero.
 *
 * Addresses are Black-image addresses.
 */
int func_021B7830(void *a0, char *a1, int a2)
{
    int n = (int)func_021B785C(a0);

    if (func_021BE05C(a0) == 1 && a2 != 0)
        return ((struct Obj06553 *)a1)->f4 + n;
    return ((struct Obj06553 *)a1)->f4 + n * a2;
}



u32 func_021B785C(void *p)
{
    u32 i = func_021BE05C(p);
    if (func_021BE078(p) == 0) {
        return g_021C6EB4[i];
    }
    return g_021C6EB4[i] >> 2;
}



/*
 * Store the four u16 arguments at +0xc..+0x12 and the word 1 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d)
{
    ((struct Obj06554 *)p)->f0 = 1;
    ((struct Obj06554 *)p)->fC = a;
    ((struct Obj06554 *)p)->fE = b;
    ((struct Obj06554 *)p)->f10 = c;
    ((struct Obj06554 *)p)->f12 = d;
}



void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d)
{
    ((struct Obj06555 *)p)->f0 = 1;
    ((struct Obj06555 *)p)->f14 = a;
    ((struct Obj06555 *)p)->f16 = b;
    ((struct Obj06555 *)p)->f18 = c;
    ((struct Obj06555 *)p)->f1A = d;
}


int func_021B78B8(void *p, char *q)
{
    int result, zero;
    if (((struct Obj06556 *)q)->f0 == 1) {
        zero = 0;
        result = 0;
        result |= func_021B792C(p, (u16 *)(q + 12), (u16 *)(q + 20));
        result |= func_021B792C(p, (u16 *)(q + 14), (u16 *)(q + 22));
        result |= func_021B792C(p, (u16 *)(q + 16), (u16 *)(q + 24));
        result |= func_021B792C(p, (u16 *)(q + 18), (u16 *)(q + 26));
        if (result == 0) ((struct Obj06556 *)q)->f0 = zero;
        if (((struct Obj06556 *)q)->f8 == 1) {
            ((struct Obj06556 *)q)->f8 = 0;
            func_020061E4(0x66e);
        }
        ((struct Obj06556 *)q)->f4 = 0;
        return 1;
    }
    return 0;
}



/*
 * Steps a u16 value towards a u16 limit by 4 or 8 (chosen from p->+0x20 == 1),
 * clamping at the limit.  Returns 1 when the value moved, 0 when it already sat
 * on the limit.
 *
 * Addresses are Black-image addresses.
 */
int func_021B792C(void *p, u16 *value, u16 *limit)
{
    unsigned char step = (((struct Obj24071 *)p)->f20 == 1) ? 4 : 8;
    u16 lim = *limit;
    u16 v = *value;

    if (v < lim) {
        if ((int)(v + step) < (int)lim)
            *value = v + step;
        else
            *value = lim;
        return 1;
    }
    if (v > lim) {
        if ((int)(v - step) > (int)lim)
            *value = v - step;
        else
            *value = lim;
        return 1;
    }
    return 0;
}


void func_021B796C(void *p, char *q, int i)
{
    Q *s;
    int sub;
    int mode;
    s = (Q *)q;
    sub = func_021BE05C(p);
    mode = i;
    if (sub == 1 && i != 0)
        mode = 1;
    if (s->wide == 0) {
        s->ent[i].tgt[0] = (mode == 0 || mode == 2) ? 0 : 0x80;
        s->ent[i].tgt[1] = (mode == 0 || mode == 1) ? 0 : 0x60;
        s->ent[i].tgt[2] = 0x80;
        s->ent[i].tgt[3] = (sub == 1) ? 0xc0 : 0x60;
    } else {
        s->ent[i].tgt[0] = (mode == 0 || mode == 2) ? 0 : 0x40;
        s->ent[i].tgt[1] = (mode == 0 || mode == 1) ? 0 : 0x30;
        s->ent[i].tgt[2] = 0x40;
        s->ent[i].tgt[3] = (sub == 1) ? 0x60 : 0x30;
    }
    if (s->ent[i].anim == 0) {
        s->ent[i].cur[0] = s->ent[i].tgt[0];
        s->ent[i].cur[1] = s->ent[i].tgt[1];
        s->ent[i].cur[2] = s->ent[i].tgt[2];
        s->ent[i].cur[3] = s->ent[i].tgt[3];
    } else {
        s->ent[i].busy = 1;
        switch (mode) {
        case 0:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0, 0, 0x80, 0);
            else
                func_021B7888(&s->ent[i], 0, 0, 0x40, 0);
            break;
        case 1:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0x80, 0, 0, (sub == 1) ? 0xc0 : 0x60);
            else
                func_021B7888(&s->ent[i], 0x40, 0, 0, (sub == 1) ? 0x60 : 0x30);
            break;
        case 2:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0, 0x60, 0x80, 0);
            else
                func_021B7888(&s->ent[i], 0, 0x30, 0x40, 0);
            break;
        case 3:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0x80, 0x60, 0, 0x60);
            else
                func_021B7888(&s->ent[i], 0x40, 0x30, 0, 0x30);
            break;
        }
    }
    s->ent[i].active = 1;
}



/*
 * Set the two words at +0x38 and +0x3c of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */
void func_021B7B20(int unused, char *base, int i)
{
    *(u32 *)(base + i * 0x1c + 0x38) = 1;
    *(u32 *)((char *)base + i * 0x1c + 0x3c) = 1;
}



/*
 * Field getter, u32 at +0x34 of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B7B30(int unused, char *base, int i)
{
    return *(u32 *)(base + i * 0x1c + 0x34);
}



void func_021B7B3C(int x, int y, int z)
{
    int r = func_021BE100();
    if (r != 1) {
        return;
    }
    r = func_02085D3C(r);
    if (r != 1) {
        return;
    }
    func_021B7B5C(3, 3, z);
}
