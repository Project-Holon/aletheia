/*
 * file:     research_top_p12.c
 * unit:     yes
 * function: func_021BCAE8, func_021BCB44, func_021BCB48, func_021BCB60, func_021BCB70, func_021BCBCC, func_021BCBD0, func_021BCC3C, func_021BCC40, func_021BCC58, func_021BCC68, func_021BCD6C, func_021BCD90, func_021BCDDC
 * address:  0x021BCAE8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02041090 0x02041090 arm
 *   func_02049238 0x02049238 arm
 *   func_021C0EF4 0x021C0EF4 thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C33C8 0x021C33C8 data a4
 *   d_021C3520 0x021C3520 data a4
 *   func_021C0F48 0x021C0F48 thumb ov217
 */
#include "../../matched/include/Obj00025.h"

struct Arc;
struct ArcFile;
struct Config;
struct Record;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

struct S_021BCBD0 { char pad0[8]; u16 h8; };

struct Ent {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 idx;
    u32 arg;
    u32 w;
};

struct Loc {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 w;
};

struct S_021BCC68 { char pad0[8]; u16 h8; char pad1[2]; u32 f0c; u32 arr[0x28]; };

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_02041B6C(u32 bit);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_020414EC();
extern void func_02040DA8(u32, u32, u32);
extern u32 func_021BC6DC(void *p);
extern struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
extern u32 func_021C0F5C(u32 a0, u32 a1);
extern void func_021C0F48(u8 *);
void func_021BCAE8(char *p);
void func_021BCB44(u8 *a0);
u32 func_021BCB48(u32 a0);
void func_021BCB60(u32 a0);
void func_021BCB70(char *p);
void func_021BCBCC(u8 *a0);
void func_021BCBD0(struct S_021BCBD0 *p);
void func_021BCC3C(u8 *a0);
u32 func_021BCC40(u32 a0);
void func_021BCC58(u32 a0);
void func_021BCC68(struct S_021BCC68 *p);
void func_021BCD6C(void *p);
void func_021BCD90(u8 *p);
void func_021BCDDC(void *p);
extern const struct Ent d_021C33C8[];
extern const struct Ent d_021C3520[];

/*
 * Original narrows the heap before 020490F4; its extern takes u16.
 */
void func_021BCAE8(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct Obj00025 *)p)->f8 & 0x7FFF) | 0x8000));
    buf = func_02049250(arc, 13, ((struct Obj00025 *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(6, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(6);
    func_020307B0(buf);
    func_02049238(arc);
}


void func_021BCB44(u8 *a0)
{
}

u32 func_021BCB48(u32 a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}


void func_021BCB60(u32 a0)
{
    func_02040DA8(7, 1, 0);
}

void func_021BCB70(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct Obj00025 *)p)->f8 & 0x7FFF) | 0x8000));
    buf = func_02049250(arc, 3, ((struct Obj00025 *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(0, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(0);
    func_020307B0(buf);
    func_02049238(arc);
}


/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCBCC(u8 *a0)
{
}


void func_021BCBD0(struct S_021BCBD0 *p)
{
    void *heap = func_020490F4(0xc0, (u16)((p->h8 & 0x7fff) | 0x8000));
    int v = func_021BC6DC(p) * 3;
    void *res = func_02049250(heap, 5, p->h8);
    char *q;
    func_02062B30(res, (void **)(&q));
    func_02041090(2, (u32)(q + 0xc), 0, 0, 0x20, (u8)v);
    func_02041B6C(2);
    func_020307B0(res);
    func_02049238(heap);
}


void func_021BCC3C(u8 *a0)
{
}

u32 func_021BCC40(u32 a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}


void func_021BCC58(u32 a0)
{
    func_02040DA8(3, 1, 0);
}


void func_021BCC68(struct S_021BCC68 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        const struct Ent *e = &d_021C33C8[i];
        struct Loc l1;
        l1.b0 = e->b0;
        l1.b1 = e->b1;
        l1.b2 = e->b2;
        l1.b3 = e->b3;
        l1.b4 = e->b4;
        l1.b5 = e->b5;
        l1.b6 = e->b6;
        l1.b7 = e->b7;
        l1.b8 = e->b8;
        l1.b9 = e->b9;
        l1.b10 = e->b10;
        l1.w = e->w;
        p->arr[0xdc / 4 - 4 + i] = (u32)func_021C0EF4((const struct Config *)(&l1), p->f0c, p->arr[e->idx], p->h8);
        func_021C0F5C(p->arr[0xdc / 4 - 4 + i], e->arg);
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        const struct Ent *e = &d_021C3520[i];
        struct Loc l2;
        l2.b0 = e->b0;
        l2.b1 = e->b1;
        l2.b2 = e->b2;
        l2.b3 = e->b3;
        l2.b4 = e->b4;
        l2.b5 = e->b5;
        l2.b6 = e->b6;
        l2.b7 = e->b7;
        l2.b8 = e->b8;
        l2.b9 = e->b9;
        l2.b10 = e->b10;
        l2.w = e->w;
        p->arr[0xb4 / 4 - 4 + i] = (u32)func_021C0EF4((const struct Config *)(&l2), p->f0c, p->arr[e->idx], p->h8);
        func_021C0F5C(p->arr[0xb4 / 4 - 4 + i], e->arg);
    }
}


/*
 * Clear seven u32 slots at +0xdc, then ten at +0xb4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCD6C(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xdc) = 0;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0xb4) = 0;
}

void func_021BCD90(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        func_021C0F48(*(u8 **)(p + i * 4 + 0xDC));
        *(u32 *)(p + i * 4 + 0xDC) = 0;
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        func_021C0F48(*(u8 **)(p + i * 4 + 0xB4));
        *(u32 *)(p + i * 4 + 0xB4) = 0;
    }
}


void func_021BCDDC(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xf8) = 0;
}
