/*
 * file:     app_taskmenu_p03.c
 * unit:     yes
 * function: func_02027A24, func_02027B30, func_02027B60, func_02027BF4, func_02027CD8, func_02027CFC, func_02027D44, func_02027E3C, func_02027F60, func_02027FD8, func_02027FEC, func_0202800C, func_0202804C
 * address:  0x02027A24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_020450F0   0x020450F0  arm
 *   func_020282D8  0x020282D8  thumb
 *   func_02045770  0x02045770  arm
 *   sub_0201C724   0x0201C724  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   tbl_020A1B38   0x020A1B38  data
 *   sub_02061CA4   0x02061CA4  arm
 *   func_020355C4 0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C08  0x02035C08  arm
 *   func_02030734   0x02030734  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_020275E4   0x020275E4  thumb
 *   func_02049DB4   0x02049DB4  arm
 *   func_02049B40   0x02049B40  arm
 *   sFile_020A74E0  0x020A74E0  data
 *   sub_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj11289.h"
#include "../../matched/include/Obj00059.h"
#include "../../matched/include/Obj06917.h"
#include "../../matched/include/Obj00104.h"

struct Descriptor;
struct S;
struct Cfg;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Cfg {
    u16 f00;
    u16 f02;
    u8  pad04[0x10 - 0x04];
    u32 f10;
    u32 f14;
};

struct Src {
    u32 f00;
    u16 f04;
    u8  pad06[8 - 6];
    u32 f08;
};

struct Row_0 {
    u32 f00;
    u16 f04;
    u8  pad06[8 - 6];
    u32 f08;
};

struct Glyph {
    u16 f00;
    u16 f02;
};

struct Obj {
    u8  pad00[0x18];
    u32 *layers;
    struct Row_0 *rows;
    u8  pad20[0x24 - 0x20];
    u8  count;
    u8  pad25[0x2c - 0x25];
    u32 inset;
    u8  x0;
    u8  y0;
    u8  dx;
    u8  dy;
    struct Glyph *glyph;
};

typedef signed short   s16;

typedef signed int     s32;

struct Row_1 {
    u8  pad00[8];
    u32 f08;
};

struct Menu {
    u8  cursor;     /* +0x00 */
    u8  pad01;      /* +0x01 */
    u16 h2;         /* +0x02 */
    u32 pad04[2];   /* +0x04 */
    u32 f0C;        /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 pad14;      /* +0x14 */
    u32 *f18;       /* +0x18 */
    struct Row_1 *f1C;/* +0x1C */
    u32 pad20;      /* +0x20 */
    u8  count;      /* +0x24 */
    u8  pad25[0x34 - 0x25];
    u32 f34;        /* +0x34 */
};

struct R {
    u16 a;
    u16 b;
    u32 f04;
    u32 obj;
    u32 pad0c;
    u32 c;
    u32 d;
};

struct TaskMenuState {
    u8 pad[8];
    void *child;
};

extern u32   sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d,
                          u8 slot);
extern void  func_020282D8(u32 bg, struct Cfg *c, u32 d);
extern void *func_02045770(struct Descriptor *bg);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void  func_02045334(struct Descriptor *bg);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void  func_02041B6C(u32 bit);
extern void func_02045798(struct Descriptor *p, u8 v);
extern s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u8 func_020355C4(void);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 id);
extern int  func_02035C08(const void *key);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32   func_020275E4(void);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void  func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 sub_020307B0(void *p);
struct CfgObj;
extern struct CfgObj *func_02028084();
void func_02027A24(struct Obj *o, struct Cfg *cfg);
u32 func_02027B30(u32 a0, struct S *s, int mode);
void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot);
void func_02027BF4(u16 *phase, u16 *out, u16 mode, u32 slot, u16 c0, u16 c1);
int func_02027CD8(int a0, int a1);
void func_02027CFC(u8 *p, int sel);
void func_02027D44(struct Menu *m);
void func_02027E3C(u8 *m);
struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
u32 func_02027FD8(struct TaskMenuState *s);
u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
u32 *func_0202804C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern s16 tbl_020A1B38[];
extern const char sFile_020A74E0[];




/*
 * Build the o->count BG layers of a multi-row menu, one per iteration: the
 * layer handle goes into o->layers[i], the per-row descriptor lives in the
 * 0xc-byte array at o->rows[i], and the same four-call teardown quartet that
 * func_0202800C runs once per object runs once per layer here.
 *
 * The flag at +0x2c picks between a plain origin (+0x30, +0x31) and one
 * inset by +0x32 / (+0x33 * +0x24); both arms narrow to u8, which is what
 * keeps the two lsls/lsrs #0x18 pairs alive.
 */
void func_02027A24(struct Obj *o, struct Cfg *cfg)
{
    u32 ox;
    u32 oy;
    u8  i;
    u32 bg;
    struct Row_0 *rows;
    struct Row_0 *row;

    if (o->inset == 0) {
        ox = o->x0;
        oy = o->y0;
    } else {
        ox = (u8)(o->x0 - o->dx);
        oy = (u8)(o->y0 - o->dy * o->count);
    }
    for (i = 0; i < o->count; i++) {
        o->layers[i] = sub_020450F0((u8)o->glyph->f00, ox,
                                    (u8)(oy + i * o->dy), o->dx,
                                    o->dy, (u8)(o->glyph->f02 + 1), 1);
        func_020282D8(o->layers[i], cfg, o->rows[i].f08);
        rows = o->rows;
        row = &rows[i];
        sub_0201C724((void *)cfg->f14, (u32)func_02045770((struct Descriptor *)o->layers[i]), 0xa, 6,
                     rows[i].f00, cfg->f10, row->f04);
        bg = o->layers[i];
        func_02045334((struct Descriptor *)bg);
        func_02045374((struct Cfg *)bg);
        func_02041B6C(func_02045730((struct Descriptor *)bg));
    }
}





u32 func_02027B30(u32 a0, struct S *s, int mode)
{
    if (mode == 1) {
        func_02045798((struct Descriptor *)a0, (u8)((struct Obj11289 *)s)->f2);
    } else if (mode == 0) {
        func_02045798((struct Descriptor *)a0, (u8)(((struct Obj11289 *)s)->f2 + 1));
    }
    func_02045374((struct Cfg *)a0);
    func_02041B6C(func_02045730((struct Descriptor *)a0));
}





void func_02027B60(u16 *phase, u16 *out, u32 mode, u32 slot)
{
    s32 s;
    u8 b, r, g;

    if (*phase + 0x400 >= 0x10000) {
        *phase = (u16)(*phase - 0xfc00);
    } else {
        *phase = (u16)(*phase + 0x400);
    }

    s = (s16)((tbl_020A1B38[2 * (*phase >> 4) + 1] + 0x1000) / 2);

    b = (u8)(((s + s * 16) >> 12) + 0xd);
    r = (u8)(((s * 7) >> 12) + 5);
    g = (u8)(((s * 15) >> 12) + 0xa);

    *out = (u16)(r | (g << 5) | (b << 10));

    if (mode <= 3) {
        sub_02061CA4((void *)0xf, slot * 32 + 0xc, (u32)out, 2);
    } else {
        sub_02061CA4((void *)0x1f, slot * 32 + 0xc, (u32)out, 2);
    }
}




/*
 * Sibling of func_02027B60: advance the u16 phase by 0x400 (wrapping at
 * 0x10000), take the sine-table value tbl_020A1B38[2*(phase>>4)+1], and
 * lerp channel by channel between two BGR555 colours c0 and c1 (the fifth
 * and sixth, stack, arguments); write the packed colour to *out and hand
 * it to sub_02061CA4 with 0xf (mode <= 3) or 0x1f.
 *
 * Closed in wave 12.  The 59-byte residue the earlier note read as
 * scheduling of the six-way colour unpack was the third parameter's type:
 * `mode` is a u16.  Nothing in the instruction stream shows the width
 * (the parameter is homed with a plain str either way), but the narrower
 * type changes the order the scheduler emits the unpack prologue in,
 * which is exactly where all 59 bytes sat.  The
 * permuter found it inside an 11-mutation anneal result; `type:p(mode)` is
 * the only one of the eleven that matters.
 */
void func_02027BF4(u16 *phase, u16 *out, u16 mode, u32 slot,
                   u16 c0, u16 c1)
{
    s32 s;
    u8 r0c, g0c, b0c;
    u8 r1c, g1c, b1c;
    u8 r, g, b;

    r0c = (u8)(c0 & 0x1f);
    g0c = (u8)((c0 & (0x1f << 5)) >> 5);
    b0c = (u8)((c0 & (0x1f << 10)) >> 10);
    r1c = (u8)(c1 & 0x1f);
    g1c = (u8)((c1 & (0x1f << 5)) >> 5);
    b1c = (u8)((c1 & (0x1f << 10)) >> 10);

    if (*phase + 0x400 >= 0x10000) {
        *phase = (u16)(*phase - 0xfc00);
    } else {
        *phase = (u16)(*phase + 0x400);
    }

    s = (s16)((tbl_020A1B38[2 * (*phase >> 4) + 1] + 0x1000) / 2);

    b = (u8)(b0c + ((s * (b1c - b0c)) >> 12));
    r = (u8)(r0c + ((s * (r1c - r0c)) >> 12));
    g = (u8)(g0c + ((s * (g1c - g0c)) >> 12));

    *out = (u16)(r | (g << 5) | (b << 10));

    if (mode <= 3) {
        sub_02061CA4((void *)0xf, slot * 32 + 0xc, (u32)out, 2);
    } else {
        sub_02061CA4((void *)0x1f, slot * 32 + 0xc, (u32)out, 2);
    }
}




int func_02027CD8(int a0, int a1){ int t0, t1; *(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f10 = (int)a1; if ((unsigned int)(a1) == (unsigned int)(1)) { func_020355D8((int)1); t1 = func_02027B30((int)*(int *)(((char *)(*(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f18) + ((int)((*(unsigned char *)&((struct Obj00059 *)((char *)((a0 + 0))))->f0 << 2)) << 0))), (struct S *)*(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f34, (int)0); } else {  return a0; } }





void func_02027CFC(u8 *p, int sel)
{
    int i;

    *p = sel;
    if (func_020355C4() != 0) {
        return;
    }
    i = 0;
    while (i < ((struct Obj06917 *)p)->f24) {
        if (i == sel) {
            func_02027B30((*(u32 **)(p + 0x18))[i], (struct S *)(((struct Obj06917 *)p)->f34), 1);
        } else {
            func_02027B30((*(u32 **)(p + 0x18))[i], (struct S *)(((struct Obj06917 *)p)->f34), 0);
        }
        i++;
    }
}





/*
 * The TaskMenu per-frame input step: up (0x40) / down (0x80) move the
 * cursor with wrap-around and play 0x548; A (held & 1) confirms (m->f0C = 1,
 * sound 0x551 or 0x54c by the row's +8 word); B (held & 2) jumps to the
 * last row, sound 0x551.  In the func_020355C4() == 1 mode a press that is
 * not B only re-highlights the current row.  When the cursor moved, the old
 * row is un-highlighted and the new one highlighted via func_02027B30.
 *
 * Closed in wave 12 from the 84-byte wave-4 source by two facts:
 *  - the up/down arms play 0x548, not 0x54C: the pool is 0x548, 0x551,
 *    0x54C in first-use order and the 0x40 arm's ldr reaches the first
 *    word (68 of the 84 bytes were this constant and the pool order it
 *    forced);
 *  - in the B arm the cursor store is written BEFORE the m->f0C = 1 store.
 *    The scheduler emits them the other way round, but the source order
 *    decides which of the constant 1 and the count temporary gets r0; the
 *    permuter never moves one store past another, so it could not find it.
 * No `one` local is needed; the constant is CSE'd by the compiler.
 */
void func_02027D44(struct Menu *m)
{
    u32 held;
    u32 hit;
    int prev;

    held = func_020362DC();
    hit  = func_0203633C();
    if (m->f10 == 1) {
        return;
    }
    if (func_020355C4() == 1) {
        if ((held & 2) == 0) {
            if ((held & 0xC3) == 0) {
                return;
            }
            func_02027B30(m->f18[m->cursor], (struct S *)m->f34, 1);
            func_020355D8(0);
            func_020061E4(0x548);
            return;
        }
    }
    prev = m->cursor;
    if (hit & 0x40) {
        if (prev == 0) {
            m->cursor = (u8)(m->count - 1);
        } else {
            m->cursor = (u8)(prev - 1);
        }
        m->h2 = 0;
        func_020061E4(0x548);
    } else if (hit & 0x80) {
        if (prev >= m->count - 1) {
            m->cursor = 0;
        } else {
            m->cursor = (u8)(prev + 1);
        }
        m->h2 = 0;
        func_020061E4(0x548);
    } else {
        if (held & 1) {
            m->f0C = 1;
            if (m->f1C[prev].f08 == 1) {
                func_020061E4(0x551);
            } else {
                func_020061E4(0x54C);
            }
        } else if (held & 2) {
            m->cursor = (u8)(m->count - 1);
            m->f0C = 1;
            func_020061E4(0x551);
            func_020355D8(0);
        }
    }
    if (prev == m->cursor) {
        return;
    }
    func_02027B30(m->f18[prev], (struct S *)m->f34, 0);
    func_02027B30(m->f18[m->cursor], (struct S *)m->f34, 1);
}




/*
 * app_taskmenu.c: the touch handler.  Builds a stack table of one
 * eight-pixel-tall hit rectangle per menu entry (0xff-terminated), hands it
 * to func_02035C08, and on a hit moves the cursor, repaints the old and the
 * new entry, and raises the confirm notification.
 */
void func_02027E3C(u8 *m)
{
    u8  rect[0x24];
    u32 top;
    u8  left;
    u8  i;
    int hit;
    int one;

    if (((struct Obj00104 *)m)->f2C == 0) {
        top  = m[0x30];
        left = m[0x31];
    } else {
        top = (u8)(m[0x30] - m[0x32]);
        left = (u8)(m[0x31] - m[0x33] * m[0x24]);
    }

    for (i = 0; i < m[0x24]; i++) {
        rect[i * 4 + 0] = (u8)((left << 3) + m[0x33] * 8 * i);
        rect[i * 4 + 1] = (u8)((left << 3) + m[0x33] * 8 * (i + 1));
        rect[i * 4 + 2] = (u8)(top << 3);
        rect[i * 4 + 3] = (u8)(((top + m[0x32]) << 3) - 1);
    }
    rect[i * 4] = 0xff;

    hit = func_02035C08(rect);
    if (hit == ~0) {
        return;
    }
    one = 1;
    func_020355D8(one);
    func_02027B30(((u32 *)*(u32 * *)&((struct Obj00104 *)m)->f18)[m[0]], (struct S *)(*(u32 *)&((struct Obj00104 *)m)->f34), 0);
    m[0] = (u8)hit;
    *(int *)&((struct Obj00104 *)m)->fC = one;
    func_02027B30(((u32 *)*(u32 * *)&((struct Obj00104 *)m)->f18)[m[0]], (struct S *)(*(u32 *)&((struct Obj00104 *)m)->f34), one);
    if (m[0] == 0) {
        func_020061E4(0x54C);
        return;
    }
    if (*(int *)(*(u8 * *)&((struct Obj00104 *)m)->f1C + m[0] * 0xC + 8) == 1) {
        func_020061E4(0x551);
        return;
    }
    func_020061E4(0x54C);
}




/*
 * Allocate and zero a 0x18-byte record ("app_taskmenu.c", line 0x2c6) and
 * fill it: two u16 ids at +0/+2, two words at +0x10/+0x14, then two
 * resources from the 0x02049xxx loader keyed by func_020275E4()'s handle.
 *
 * The 30-byte residue the earlier notes read as an allocation tie was the
 * callees' argument lists: func_020275E4()'s result is the FIRST argument
 * of func_02049DB4 and func_02049B40 (r0 is never reloaded between the bl
 * and the blx), so the constants 0x20 / 0x1f are the second argument, and
 * func_02049B40 takes (h, 0x1f, sel, a1 << 5, 0x40, heap) -- six arguments
 * with the heap id last.  Written that way the heap parameter needs no
 * address-taken pointer; it is an ordinary fifth (stack) parameter.
 */
struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap)
{
    struct R *r;
    u32 sel;

    sel = 0;
    r = (struct R *)func_02030734(heap, 0x18, 0, sFile_020A74E0, 0x2c6);
    MI_CpuFill8(r, 0, 0x18);
    r->a = a0;
    r->b = a1;
    r->c = a2;
    r->d = a3;
    if (a0 > 3) {
        sel = 4;
    }
    r->obj = (u32)func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&r->f04), heap);
    func_02049B40(func_020275E4(), 0x1f, sel, a1 << 5, 0x40, heap);
    return r;
}




u32 func_02027FD8(struct TaskMenuState *s)
{
    sub_020307B0(s->child);
    return sub_020307B0(s);
}



u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5)
{
    return (u32)func_0202800C(a0, a1, a2, a3, a4, 3, 0, 0, a5);
}




u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                   u16 a8)
{
    u32 *p = (u32 *)func_02028084(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    void *q = (void *)p[0];

    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    return p;
}




u32 *func_0202804C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                   u16 a8)
{
    u32 *p = (u32 *)func_02028084(a0, a1, a2, a3, a4, a5, a6, a7, a8);

    func_02045374((void *)p[0]);
    func_02041B6C(func_02045730((void *)p[0]));
    return p;
}
