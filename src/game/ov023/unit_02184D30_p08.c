/*
 * file:     unit_02184D30_p08.c
 * unit:     yes
 * function: func_02185C38, func_02185DA8, func_02185DE8, func_02185EA0, func_02185F10, func_02185F50, func_02185F74, func_021860D0, func_02186164, func_02186170, func_021861C4, func_021862B0, func_021862F4, func_02186304, func_02186324, func_02186444, func_0218644C, func_02186480
 * address:  0x02185C38
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02185BBC  0x02185BBC  thumb  ov023
 *   d_02186C34     0x02186C34  data  ov023  a4
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02039338  0x02039338  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02184180  0x02184180  thumb  ov022
 *   func_0218506C  0x0218506C  thumb  ov023
 *   func_0203F684  0x0203F684  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02008500  0x02008500  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D56C  0x0203D56C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02186A04  0x02186A04  thumb  ov023
 *   func_021869C0  0x021869C0  thumb  ov023
 *   func_02186958  0x02186958  thumb  ov023
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0218654C 0x0218654C thumb ov023
 *   func_02184560 0x02184560 thumb ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_0204B878  0x0204B878  arm
 *   d_02186E84 0x02186E84 data a4
 *   func_02186694 0x02186694 thumb ov023
 */
#include "../../matched/include/Obj20359.h"
#include "../../matched/include/Obj01221.h"
#include "../../matched/include/Obj20361.h"
#include "../../matched/include/Obj20363.h"
#include "../../matched/include/Obj00525.h"
#include "../../matched/include/Obj20365.h"
#include "../../matched/include/Obj00460.h"
#include "../../matched/include/Obj20366.h"
#include "../../matched/include/Obj07610.h"
#include "../../matched/include/Obj00336.h"

#define E(p) ((struct e6 *)((char *)(p) + 0x4212))
struct Descriptor;
struct Cfg;
struct Obj;
struct Bmp;
struct PrintSys;
struct Entry;
struct CharBuf;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
struct e6 {
    unsigned char b[4];
    unsigned char c : 3;
    unsigned char n : 3;
    unsigned char d : 2;
    unsigned char pad;
};

struct o4 {
    unsigned char x;
    unsigned char y;
    unsigned short n;
};

typedef unsigned char  u8;

struct P {
    char pad0[4];
    int *unk4;
    char pad1[0x60 - 8];
    int unk60[5];
};

typedef unsigned short u16;

typedef int s32;

typedef signed short   s16;

typedef unsigned int u32;

typedef struct {
    u32 w;
    u8 f;
} Ent;

typedef struct {
    char pad0[0xc];
    u32 f0c;
    char pad10[0x8];
    u32 arr18[5];
    char pad2c[0x6c];
    u32 arr98[5];
    char padac[0x58];
    u32 win[7];
    char pad120[0xc];
    Ent ent[7];
    u32 f164;
    u32 f168;
    u32 f16c;
    u32 f170;
    char pad174[0x54];
    Ent e1c8[5];
} W;

extern void func_02185BBC(int a0, int a1, int x, int y, int w, int h, int dx, int dy,
                          int mx, int my);
extern void func_02045334(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned int index);
extern u16 func_02039338(void);
extern char *func_02184180(unsigned char *p, int i);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0218506C(void *actor, int x, int y);
extern short func_0203F684(unsigned short x);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02008500(void *a, void *b);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct Entry *func_020399A8(void);
extern int  func_0203D56C(void *h);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02186A04(char *a, char *b);
extern void func_021869C0(char *a, char *b);
extern void func_02186958(char *a);
int func_021841A4(unsigned char *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201CE48(struct Rec3 *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *h);
extern void func_0201F7A8(void *, unsigned int);
extern int func_0218654C(char *p);
extern void func_02184560(char *, int);
extern int func_02186558(char *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_02186694(char *);
void func_02185C38(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d);
void func_02185DA8(struct e6 *e, struct o4 *o);
void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag);
void func_02185EA0(struct P *p);
void func_02185F10(u16 *p);
int func_02185F50(char *p);
void func_02185F74(u32 *win, u16 color, W *p);
void func_021860D0(char *p);
int func_02186164(char *p);
int func_02186170(char *p);
void func_021861C4(u8 *w, u32 msg, int mode);
int func_021862B0(char *p);
void func_021862F4(char *p);
void func_02186304(char *p, int a);
int func_02186324(u8 *p);
void func_02186444(char *p, u32 v);
void func_0218644C(char *p, int mode);
void func_02186480(char *p);
extern char d_02186C34[];
extern int d_02186E84[][2];


void func_02185C38(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d)
{
    int sx;
    int sy;
    int ex;
    int dx;
    int ey;
    int dy;
    int err;
    int step;

    sx = *px;
    sy = *py;
    ex = x1;
    ey = y1;
    if (c == 0 && d == 0) {
        *px = x1;
        *py = y1;
        return;
    }
    dx = x1 - sx;
    if (dx < 0)
        dx = -dx;
    dy = y1 - sy;
    if (dy < 0)
        dy = -dy;
    if (dx > dy) {
        if (sx > x1) {
            step = (sy > y1) ? 1 : -1;
            ex = sx;
            sx = x1;
            sy = y1;
        } else {
            step = (sy < y1) ? 1 : -1;
        }
        func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        err = dx >> 1;
        for (sx++; sx <= ex; sx++) {
            err -= dy;
            if (err < 0) {
                err += dx;
                sy += step;
            }
            func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        }
    } else {
        if (sy > y1) {
            step = (sx > x1) ? 1 : -1;
            ey = sy;
            sy = y1;
            sx = x1;
        } else {
            step = (sx < x1) ? 1 : -1;
        }
        func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        err = dy >> 1;
        for (sy++; sy <= ey; sy++) {
            err -= dx;
            if (err < 0) {
                err += dy;
                sx += step;
            }
            func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        }
    }
    *px = x1;
    *py = y1;
}


void func_02185DA8(struct e6 *e, struct o4 *o)
{
    int i;

    for (i = 0; i < 5; i++) {
        o[i].n = e[i].n;
        if (e[i].n != 0) {
            o[i].x = *((unsigned char *)&e[i] + e[i].n - 1);
            o[i].y = *((unsigned char *)&e[i] + e[i].n + 1);
        }
    }
}


void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag)
{
    int hit;
    int i;
    int x;
    int y;

    hit = 0;
    for (i = 0; i < 5; i++) {
        if (e[i].n == 2) {
            x = e[i].b[0] - 9;
            y = e[i].b[2] - 0x11;
            func_02185C38((int)p, (int)(d_02186C34 + e[i].d * 0xc0 + e[i].c * 0x18),
                          e[i].b[1] - 9, e[i].b[3] - 0x11, &x, &y, 1, o[i].n);
            hit = 1;
        }
    }
    if (hit && flag) {
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_020409B4(func_02045730((struct Descriptor *)p));
    }
    func_02185DA8(e, o);
    for (i = 0; i < 5; i++)
        e[i].n = 0;
}


/*
 * The 6-byte records at +0x4212 are reached through a byte cast of a struct
 * pointer at every use (E below): the base is hoisted into r6 and the
 * element address is recomputed (muls) at each use. A local `e`, or a
 * `char *` parameter with the same cast, CSEs the element pointer instead.
 */
void func_02185EA0(struct P *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (i == func_02039338())
            continue;
        if (E(p)[i].n != 0 && func_02184180((unsigned char *)(*p->unk4), (unsigned char)i) != 0) {
            func_0204B3DC((struct Obj *)p->unk60[i], 1);
            func_0218506C((void *)p->unk60[i], E(p)[i].b[E(p)[i].n - 1], E(p)[i].b[E(p)[i].n + 1]);
        } else {
            func_0204B3DC((struct Obj *)p->unk60[i], 0);
        }
    }
}


void func_02185F10(u16 *p)
{
    u16 col;

    *p += 20;
    if (*p > 360)
        *p = 0;
    col = (u16)((((func_0203F684(*p) * 10) / 0x1000) + 15) << 5 | 0x1d);
    GX_LoadOBJPltt(&col, 0x18, 2);
}

/*
 * lever: index declared before count places i in r4 and n in r5.
 */
int func_02185F50(char *p)
{
    int i;
    int n;
    n = 0;
    for (i = 0; i < 5; i++) {
        if (func_02184180(**(u8 ** *)&((struct Obj20359 *)p)->f4, (u8)i) != 0)
            n++;
    }
    return n;
}


void func_02185F74(u32 *win, u16 color, W *p)
{
    int sel;
    int i;
    u32 w;
    u32 t;

    sel = func_02039338();
    if (!func_02186170((char *)p))
        return;
    for (i = 0; i < 5; i++) {
        if (p->e1c8[i].w == 0)
            func_0204B3DC((struct Obj *)p->arr98[i], 0);
        else
            func_0204B3DC((struct Obj *)p->arr98[i], 1);
    }
    func_0201C6EC((struct PrintSys *)p->f164);
    for (i = 0; i < 5; i++)
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)win[i])), 0, 0, 0x50, 0x10, 0);
    for (i = 0; i < 5; i++) {
        if (p->e1c8[i].w != 0) {
            func_02008500((void *)p->e1c8[i].w, (void *)p->arr18[i]);
            if (sel == i) {
                t = p->f164;
                func_0201C724((void *)t, (u32)func_02045770((struct Descriptor *)p->ent[i].w), 0, 0, p->arr18[i], p->f0c, 0xc80);
                p->ent[i].f = 1;
            } else {
                t = p->f164;
                func_0201C724((void *)t, (u32)func_02045770((struct Descriptor *)p->ent[i].w), 0, 0, p->arr18[i], p->f0c, color);
                p->ent[i].f = 1;
            }
        }
        w = win[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
}


void func_021860D0(char *p)
{
    void *h;

    if (func_02039338() == 0) {
        h = func_020399A8();
        if (func_0203D56C(h) == 0)
            return;
        func_02186A04(p + 0x9e4c, p + 0x928c);
        ((struct Obj01221 *)p)->f9E51 = ((struct Obj01221 *)p)->f9E6C;
        if (func_0203D3A8(h, 0x2902, 0x1e, (u32)(p + 0x9e4c)) == 1)
            func_02186958(p + 0x928c);
    } else {
        h = func_020399A8();
        func_021869C0(p + 0x420c, p + 0x928c);
        if (func_0203D56C(h) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 0x2901, 6, (u32)(p + 0x420c)) == 1)
            func_02186958(p + 0x928c);
    }
}


/*
 * Unblocked by matching the leaf at 0x021841A4 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_02186164(char *p)
{
    return func_021841A4((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj20361 *)p)->f4));
}


int func_02186170(char *p)
{
    int i;
    int r;

    r = 0;
    for (i = 0; i < 5; i++) {
        *(int *)(p + i * 8 + 0x1cc) = *(int *)(p + i * 8 + 0x1c8);
        *(int *)(p + i * 8 + 0x1c8) = (int)func_02184180((unsigned char *)(**(int * *)&((struct Obj20363 *)p)->f4), (unsigned char)i);
    }
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + i * 8 + 0x1cc) != *(int *)(p + i * 8 + 0x1c8))
            r = 1;
    }
    return r;
}


void func_021861C4(u8 *w, u32 msg, int mode)
{
    void *str;
    void *t;
    void *p;

    str = func_020457B0(0x50, 0x28);
    func_02045CAC(((struct Obj00525 *)w)->f14, msg, str);
    func_0201F250(((struct Obj00525 *)w)->f10, ((struct Obj00525 *)w)->f30, str);
    func_02045808(str);
    func_02043B5C(func_02045770(((struct Obj00525 *)w)->f11C), 15);
    func_0201F73C(((struct Obj00525 *)w)->f11C, 0, 1, 10);
    if (((struct Obj00525 *)w)->f16C != 0) {
        func_0201CE48(((struct Obj00525 *)w)->f16C);
        ((struct Obj00525 *)w)->f16C = 0;
    }
    if (mode == 0) {
        t = ((struct Obj00525 *)w)->f168;
        func_0201C724(t, (u32)func_02045770(((struct Obj00525 *)w)->f15C), 0, 0, (u32)(((struct Obj00525 *)w)->f30), ((struct Obj00525 *)w)->fC, 0x44F);
        ((struct Obj00525 *)w)->f160 = 1;
    } else {
        ((struct Obj00525 *)w)->f16C = func_0201CCE4(((struct Obj00525 *)w)->f11C, 0, 0, ((struct Obj00525 *)w)->f30,
                                              ((struct Obj00525 *)w)->fC, func_02012FFC(),
                                              ((struct Obj00525 *)w)->f170, 1, 0x28, 0xF0F);
    }
    p = ((struct Obj00525 *)w)->f11C;
    func_02045334(p);
    func_02045374(p);
    func_020409B4(func_02045730(p));
}


int func_021862B0(char *p)
{
    int r = func_0201CE30(((struct Obj00525 *)p)->f16C);

    if (r == 1) {
        if (func_020362DC() & 1) {
            func_0201CE38(((struct Obj00525 *)p)->f16C);
        }
        return 0;
    }
    if (r == 2) {
        func_0201CE48(((struct Obj00525 *)p)->f16C);
        ((struct Obj00525 *)p)->f16C = 0;
        return 1;
    }
    return ((struct Obj00525 *)p)->f16C == 0;
}

void func_021862F4(char *p)
{
    func_0201F7A8(((struct Obj20365 *)p)->f11C, 0);
}

/*
 * extent: two zero padding bytes follow the return at 0x02186320.
 * Caller explicitly sets r1 for func_02184560, retained despite its legacy one-argument definition.
 */
void func_02186304(char *p, int a)
{
    if (func_02039338() == 0) {
        func_0218654C(p);
        func_02184560(p, a);
    }
}


int func_02186324(u8 *p)
{
    int st;
    int r;

    st = func_02186164((char *)p);
    switch (st) {
    case 0:
        break;
    case 1:
        if (((struct Obj00460 *)p)->f198 > 0x10) {
            break;
        }
        if (func_02186558((char *)p) != 1) {
            ((struct Obj00460 *)p)->f9E78 = 1;
        }
        ((struct Obj00460 *)p)->f19C = 0x16;
        if (((struct Obj00460 *)p)->f9E70 != 0) {
            func_02186480((char *)p);
            func_0204B878(((struct Obj00460 *)p)->fF0, 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (st < ((struct Obj00460 *)p)->f1A8) {
            if (((struct Obj00460 *)p)->f9E6C == 2) {
                func_02186304((char *)p, 0);
            } else if (((struct Obj00460 *)p)->f9E7C == 0) {
                func_02186304((char *)p, 1);
            } else {
                func_02186304((char *)p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (st < ((struct Obj00460 *)p)->f1A8) {
        ((struct Obj00460 *)p)->f1AC = func_0218654C((char *)p);
        r = func_02186558((char *)p);
        ((struct Obj00460 *)p)->f1B0 = r;
        if (((struct Obj00460 *)p)->f9E7C != 0 && (r & ((struct Obj00460 *)p)->f9E80) == 0) {
            func_02186304((char *)p, 1);
            ((struct Obj00460 *)p)->f9E6C = 1;
            ((struct Obj00460 *)p)->f9E7C = 0;
            ((struct Obj00460 *)p)->f9E80 = 0;
        }
    }
    ((struct Obj00460 *)p)->f1A8 = func_02186164((char *)p);
    if (((struct Obj00460 *)p)->f1AC < func_0218654C((char *)p)) {
        ((struct Obj00460 *)p)->f9E6C = 2;
        ((struct Obj00460 *)p)->f9E7C = 1;
        ((struct Obj00460 *)p)->f9E80 = func_02186558((char *)p) ^ ((struct Obj00460 *)p)->f1B0;
    }
    return 1;
}


void func_02186444(char *p, u32 v)
{
    ((struct Obj20366 *)p)->f19C = v;
}

void func_0218644C(char *p, int mode)
{
    int n;
    n = ((struct Obj07610 *)p)->f19C;
    if (((struct Obj07610 *)p)->f198 != n) {
        if (mode != 2) {
            ((struct Obj07610 *)p)->f198 = n;
            return;
        }
        if (d_02186E84[n][0] != 0)
            ((struct Obj07610 *)p)->f198 = n;
    }
}

void func_02186480(char *p)
{
    if (((struct Obj00336 *)p)->f9E70 != 0) {
        if (((struct Obj00336 *)p)->f178 != 0)
            func_02186694(p);
        ((struct Obj00336 *)p)->f9E70 = 0;
    }
}
