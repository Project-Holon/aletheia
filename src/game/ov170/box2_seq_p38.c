/*
 * file:     box2_seq_p38.c
 * unit:     yes
 * function: func_021EC048, func_021EC060, func_021EC08C, func_021EC0B0, func_021EC0DC, func_021EC1E8, func_021EC254, func_021EC2A0, func_021EC338, func_021EC35C, func_021EC428, func_021EC45C, func_021EC48C, func_021EC4E0, func_021EC4FC, func_021EC548, func_021EC5A0, func_021EC61C, func_021EC688, func_021EC6F4
 * address:  0x021EC048
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B688 0x0204B688 arm
 *   func_0204B454 0x0204B454 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   d_021EFD04 0x021EFD04 data a4
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_020079BC 0x020079BC thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020185F4 0x020185F4 thumb
 *   d_021EFD4C 0x021EFD4C data a2
 *   func_021EC768 0x021EC768 thumb
 */
#include "../../matched/include/Obj02214.h"
#include "../../matched/include/Obj18519.h"
#include "../../matched/include/Obj24001.h"
#include "../../matched/include/Obj24002.h"
#include "../../matched/include/Obj24003.h"
#include "../../matched/include/Obj18520.h"
#include "../../matched/include/Obj06550.h"
#include "../../matched/include/Obj24004.h"
#include "../../matched/include/Obj24005.h"
#include "../../matched/include/Obj24007.h"
#include "../../matched/include/Obj24008.h"
#include "../../matched/include/Obj24009.h"
#include "../../matched/include/Obj24010.h"
#include "../../matched/include/Obj24011.h"
#include "../../matched/include/Obj24012.h"

#define SLOT(p,o) (*(void **)((p)+(o)))
#define WORK(p) (*(char **)((p) + 0x2C))
struct Node;
struct Actor;
struct Obj;
struct Vec2;
struct PtS;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct { short x, y; unsigned char pad4[2], b6, b7; int a, b, c; unsigned short e, d; } Desc;

typedef unsigned char  u8;

typedef struct { short x; short y; } Pos_021EC548;

typedef struct { short x; short y; } Pos_021EC5A0;

typedef struct {
    short x;
    short y;
} Pos_021EC61C;

typedef struct { short x, y; } Pos_021EC688;

typedef struct { short x, y; } Pos_021EC6F4;

extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_020275E4(void);
extern unsigned func_02027618(void);
extern unsigned func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void *func_021EBEE0(char *, const Desc *);
extern u32 func_0201BA68(void *mon);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void MIi_CpuCopy32(const void *src, void *dst, unsigned size);
extern u32 func_020307B0(void *p);
extern int func_0201BBE8(void *a0);
extern u16 func_0204B7F0(u8 *p);
extern void func_0204AA94(int a, void *b, u32 c, int d, int e);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_021EC000(char *w, int i, int v);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *, unsigned);
extern void *func_020185F4(void *);
extern void func_021EC768(char *p, unsigned i, int flag);
void func_021EC048(char *p, int i, int c);
void func_021EC060(char *p,unsigned i,int b);
void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
void func_021EC0DC(char *p);
void func_021EC1E8(char *p);
void func_021EC254(char *p);
void func_021EC2A0(char *p);
void *func_021EC338(char *p, void *b, void *c);
void func_021EC35C(char **p, int box);
void func_021EC428(char *p, int a, int i, int b);
void func_021EC45C(unsigned char *p, void *a, int i);
void func_021EC48C(unsigned char *p, int box, int pos, int win);
void func_021EC4E0(char *p);
void func_021EC4FC(unsigned char *p);
void func_021EC548(unsigned i, short *x, short *y, int mode);
void func_021EC5A0(char **p, int flag);
void func_021EC61C(unsigned char *p);
void func_021EC688(char *p);
void func_021EC6F4(char *p);
extern const Desc d_021EFD04;
extern const Pos_021EC548 d_021EFD4C[];

/*
 * Tail call with the table word at the pooled offset.
 */
void func_021EC048(char *p, int i, int c)
{
    func_0204B800((struct Node *)(*(int *)(p + i * 4 + 0x9E74)), (unsigned char)c);
}

void func_021EC060(char *p,unsigned i,int b){if(b==1)func_0204B688(*(void **)((unsigned)p+i*4+0x9e74),1);else func_0204B688(*(void **)((unsigned)p+i*4+0x9e74),0);}

/*
 * Stage two shorts on the stack and hand the 0x9E74 array slot to the
 *   SDK call.  Two spellings (array and struct) both give the image's
 *   store order, because the index term is computed between the stores.
 */
void func_021EC08C(char *p, int i, int a, int b, unsigned short c)
{
    unsigned short t[2];
    t[0] = a;
    t[1] = b;
    func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)), (const struct Vec2 *)t, c);
}


void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space)
{
    short t[2];
    func_0204B454((struct Actor *)*(int *)(p + i * 4 + 0x9E74), (struct PtS *)t, space);
    *a = t[0];
    *b = t[1];
}

void func_021EC0DC(char *p)
{
    void *h;
    unsigned i,j;
    h=func_020490F4(116,76);
    for(j=0;j<6;j++) SLOT(p+j*4,0xA0D8)=(void *)func_0204A6C8(h,71,1,0,76);
    SLOT(p,0xA11C)=(void *)func_0204ABF0(h,72,0,0,76);
    SLOT(p,0xA148)=(void *)func_0204AF28(h,73,74,76);
    for(i=0;i<37;i++) SLOT(p+i*4,0x9FF4)=(void *)func_0204A6C8(h,75,1,0,76);
    SLOT(p,0xA0F0)=(void *)func_0204A6C8(h,67,1,0,76);
    SLOT(p,0xA120)=(void *)func_0204ABF0(h,70,0,192,76);
    SLOT(p,0xA14C)=(void *)func_0204AF28(h,68,69,76);
    SLOT(p,0xA0F4)=(void *)func_0204A6C8(h,64,1,0,76);
    SLOT(p,0xA150)=(void *)func_0204AF28(h,65,66,76);
    SLOT(p,0xA090)=(void *)func_0204A6C8(h,76,1,0,76);
    SLOT(p,0xA140)=(void *)func_0204AF28(h,77,78,76);
    func_02049238(h);
}

void func_021EC1E8(char *p)
{
    void *h = func_020490F4(func_020275E4(), 0x4C);
    ((struct Obj02214 *)p)->fA0F8 = (void *)func_0204A6C8(h, func_02027618(), 0, 0, 0x4C);
    ((struct Obj02214 *)p)->fA124 = (void *)func_0204ABF0(h, func_02027614(), 0, 0x100, 0x4C);
    ((struct Obj02214 *)p)->fA154 = (void *)func_0204AF28(h, func_0202761C(2), func_02027620(2), 0x4C);
    func_02049238(h);
}

void func_021EC254(char *p)
{
    void *h = func_020490F4(7, 0x4C);
    ((struct Obj02214 *)p)->fA108 = (void *)func_0204ACEC(h, func_0201BC3C(), 0, 0x60, 0x4C);
    ((struct Obj02214 *)p)->fA134 = (void *)func_0204AF28(h, func_0201BC40(), func_0201BCB4(), 0x4C);
    func_02049238(h);
}

void func_021EC2A0(char *p)
{
    Desc d;
    Desc base = d_021EFD04;
    unsigned i;
    for (i = 0; i < 0x25; i++) {
        d = base;
        d.x += (short)((i % 6) * 24);
        d.y += (short)((i / 6) * 24);
        d.b6 = 0x75 - i * 2;
        d.a = i;
        *(void **)(p + i * 4 + 0x9F40) = func_021EBEE0(p, &d);
        *(unsigned char *)(p + i + 0x3DD2) = i + 0x33;
    }
}


/*
 * Forward with a resolved handle and the object table entry.
 */
void *func_021EC338(char *p, void *b, void *c)
{
    return func_02049E74((void *)(((struct Obj18519 *)p)->f1B0), func_0201BA68(b), 0, (u32)c, 0x4c);
}


void func_021EC35C(char **p, int box)
{
    unsigned i;
    void *m;
    void *r;
    void *buf;
    for (i = 0; i < 0x1E; i++) {
        if (func_020079BC(((void **)p[0])[1], box, i, 0xA9, 0) == 0) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else if (((struct Obj24001 *)(p[0]))->f24 != 3 && ((unsigned char *)p)[0x14] == ((unsigned char *)p)[0x17]
                   && ((unsigned char *)p)[0x16] == i) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else {
            m = (void *)func_021DD2D0((void ***)p, box, i);
            r = func_021EC338(p[11], m, &buf);
            MIi_CpuCopy32(((struct Obj24002 *)buf)->f14, p[11] + 0x1B4 + i * 0x200, 0x200);
            func_020307B0(r);
            *(unsigned char *)(p[11] + i + 0x3DB4) = func_0201BBE8(m);
            *(int *)(p[11] + i * 4 + 0x3DF8) = 1;
        }
    }
}

/*
 * Stop the slot, re-key it and restart it.  Two facts pin this one:
 *   the second call's FIRST argument is the first call's RESULT (r0 is
 *   never overwritten), and the result must be a named local -- the
 *   nested spelling moves a and b to r6/r7 (r6=a) instead of the image's
 *   r7=a / r6=b, a 1-byte miss at +0x18.
 */
void func_021EC428(char *p, int a, int i, int b)
{
    int v = func_0204B7F0((u8 *)(*(int *)(p + 0x9E74 + i * 4)));
    func_0204AA94(v, (void *)a, 0x200, 0, 0);
    func_0204B6F4((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned char)b, 1);
}


/*
 * Loads an icon resource for a, uploads it and frees the file.
 */
void func_021EC45C(unsigned char *p, void *a, int i)
{
    void *d;
    void *res = func_021EC338(WORK(p), a, &d);
    func_021EC428(WORK(p), ((struct Obj24003 *)d)->f14, i, func_0201BBE8(a));
    func_020307B0(res);
}


/*
 * Hides window win, and when slot (box, pos) holds something shows its icon
 * there again.  The image narrows both the slot and the box to 16 bits
 * before func_021DD25C, so its box parameter is declared unsigned short here;
 * the callee body only forwards it and cannot show the width.
 */
void func_021EC48C(unsigned char *p, int box, int pos, int win)
{
    char *w = WORK(p);
    func_021EC000(WORK(p), win, 0);
    if (func_021DD25C((void ***)p, pos, (unsigned short)box, 0xA9, 0)) {
        func_021EC45C(p, (void *)func_021DD2D0((void ***)p, box, pos), win);
        func_021EC000(w, win, 1);
    }
}

/*
 * Loop 0x1e entries forwarding (p[0x14], i, i+0x33).
 */
void func_021EC4E0(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1e; i++)
        func_021EC48C((unsigned char *)p, ((struct Obj18520 *)p)->f14, i, i + 0x33);
}

void func_021EC4FC(unsigned char *p)
{
    unsigned n = func_0201AA18(((struct Obj24004 *)(*(char * *)&((struct Obj06550 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < n; i++) {
        func_021EC45C(p, func_020185F4(func_0201AB28(((struct Obj24005 *)(*(char * *)&((struct Obj06550 *)p)->f0))->f8, i)),
                       *(unsigned char *)(*(char * *)&((struct Obj06550 *)p)->f2C + i + 0x3DF0));
        func_021EC000(*(char * *)&((struct Obj06550 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj06550 *)p)->f2C + i + 0x3DF0), 0);
    }
}


void func_021EC548(unsigned i, short *x, short *y, int mode)
{
    if (i < 0x1E) {
        *x = (i % 6 + 1) * 0x18;
        *y = (i / 6) * 0x18 + 0x30;
        return;
    }
    i -= 0x1E;
    *x = d_021EFD4C[i].x;
    *y = d_021EFD4C[i].y - 0x90;
    if (mode == 2)
        *x += 0x98;
}


void func_021EC5A0(char **p, int flag)
{
    unsigned n = func_0201AA18(((void **)p[0])[2]);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int k = *(unsigned char *)(p[11] + i + 0x3DF0);
        func_021EC08C(p[11], k, d_021EFD4C[i].x, d_021EFD4C[i].y, 0);
        func_021EC768(p[11], i + 0x1E, 1);
        if (i < n && (flag == 0 || ((unsigned char *)p)[0x16] != i + 0x1E))
            func_021EC000(p[11], k, 1);
        else
            func_021EC000(p[11], k, 0);
    }
}


/*
 * Lays out the six party-slot windows and shows the ones the party fills.
 * The window id is an int local: as unsigned char the load is scheduled after
 * the table address and 34 bytes move.
 */
void func_021EC61C(unsigned char *p)
{
    unsigned n = func_0201AA18(((struct Obj24008 *)(*(char * *)&((struct Obj24007 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, (short)(d_021EFD4C[i].x + 0x98), (short)d_021EFD4C[i].y, (short)0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}

void func_021EC688(char *p)
{
    unsigned n = func_0201AA18(((struct Obj24010 *)(*(char * *)&((struct Obj24009 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, (short)d_021EFD4C[i].x, (short)(d_021EFD4C[i].y - 0x90), (short)0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}

void func_021EC6F4(char *p)
{
    unsigned n = func_0201AA18(((struct Obj24012 *)(*(char * *)&((struct Obj24011 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, (short)(d_021EFD4C[i].x + 0x98), (short)(d_021EFD4C[i].y - 0x90), (short)0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}
