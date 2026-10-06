/*
 * file:     app_taskmenu_p07.c
 * unit:     yes
 * function: func_02028230, func_0202824C, func_020282A4, func_020282AC, func_020282D8, func_0202843C, func_02028454, func_0202846C, func_02028470, func_02028484, func_020284F4, func_02028528, func_0202855C, func_02028590
 * address:  0x02028230
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
 *   _s32_div_f   0x0209C0A4  arm
 *   func_02035D20  0x02035D20  arm
 *   func_02045738  0x02045738  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045798  0x02045798  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045740  0x02045740  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   g_0209FD10  0x0209FD10  data
 */
#include "../../matched/include/Obj00864.h"
#include "../../matched/include/Obj11291.h"
#include "../../matched/include/Obj11292.h"
#include "../../matched/include/Obj15793.h"
#include "../../matched/include/Obj15794.h"

struct Descriptor;
struct Cfg;
struct Bmp;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Obj {
    u32 pad_00[2];
    u32 field_08;
    u32 pad_0c;
    u16 field_10;
    u16 pad_12;
};

struct T {
    u32 f00;
    u8  pad04[0x18];
    u16 f1c;
    u16 f1e;
};

struct Cfg {
    u32 pad00;
    struct { u8 pad[0x14]; u32 f14; } *f04;
};

typedef signed int     s32_0202846C;

typedef signed int     s32_02028470;

typedef int s32_02028484;

typedef struct Blk {
    u8  first;
    u8  pad[3];
    u32 flags;
} Blk;

typedef signed char    s8;

extern u32 func_02035D20(u32 *x, u32 *y);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void func_02045798(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 func_02045740(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *bg);
extern void *func_020437D4(const struct Bmp *bmp);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 n);
extern void func_020456F8(struct Descriptor *d);
void func_0202843C(u8 *p);
void func_02028454(u8 *p);
extern void func_02082BCC(void *p, u32 v, u32 size);
extern u32 func_0201CE30(void *h);
extern void func_0201CE38(void *h);
extern void func_0201CE5C(struct Rec *p, s32_02028484 v);
extern void func_020061E4(u32 id);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
u32 func_0202846C(u8 *p);
void func_02028470(u8 *p, u32 v);
s32_02028484 func_02028484(Blk *blk, void *h);
u32 func_020284F4(u32 a);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
u32 func_02028528(u32 a);
u32 func_0202855C(u32 a);
u32 func_02028230(u8 *p);
u32 func_0202824C(void **p);
void func_02028590(u32 a0, u32 a1, u32 a2, u16 a3);
extern char g_0209FD10[];






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028230.c \
 *       --func func_02028230 --addr 0x02028230 --thumb --cc 1.1p1
 */
u32 func_02028230(u8 *p)
{
    s32 r = 0x10 / (s32)((struct Obj00864 *)p)->f12;

    if ((s32)((struct Obj00864 *)p)->f10 < r) {
        return 0;
    }
    return 1;
}







/*
 * Touch hit test against a window.  func_02035D20 reports whether the
 * screen is being touched and where; if so the window's origin and
 * extent are read off its descriptor in tile units and scaled to
 * pixels by 8, and the touch point must fall inside that rectangle.
 *
 * The extent accessor func_02045738 is called twice rather than once
 * with its result reused: it is an external ARM call, so the compiler
 * cannot prove it pure, and both calls survive.
 */
u32 func_0202824C(void **p)
{
    u32 x;
    u32 y;
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;

    if (func_02035D20(&x, &y) == 0) {
        goto fail;
    }

    left = func_02045758(p[0]) * 8;
    top = func_02045760(p[0]) * 8;
    right = left + func_02045738(p[0]) * 8;
    bottom = top + func_02045738(p[0]) * 8;

    if (x - left > right - left) {
        goto fail;
    }
    if (y - top > bottom - top) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}







/*
 * A leaf that clears the word at offset 8 and the halfword at offset 0x10.
 */
void func_020282A4(struct Obj *obj)
{
    obj->field_08 = 0;
    obj->field_10 = 0;
}



void func_020282AC(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4)
{
    a1[1] = a2;
    p->f1c = a3;
    p->f1e = a4;
    func_02045798((void *)p->f00, (u8)(a2 + 1));
    func_02045374((void *)p->f00);
    func_02041B6C(func_02045730((void *)p->f00));
}


/*
 * app_taskmenu.c: paints a window frame into the BG's tilemap.  Walks the
 * layer's rows (func_02045740) and columns (func_02045738) and, per 0x20-byte
 * tile, classifies the cell as one of eleven kinds -- four corners, three
 * edges, two style-dependent inner columns, the plain interior -- and copies
 * the matching tile out of the template's tile bank (cfg->f04->f14) into the
 * layer's tile memory.
 *
 * Two shape notes, both worth a byte each:
 *  - Both loops are a top guard plus a bottom back-edge (`for (;;)` with the
 *    `x >= n` / `y >= n` test written out at both ends), not a plain `for`:
 *    the original's guards are `bhi`/`bhs` on the freshly-called bound and
 *    the two back-edges land on 0x02028312 and 0x02028304, which a `for` does
 *    not reproduce (366 bytes, 291 wrong).  The row loop's `x = 0` sits after
 *    the row guard, which is what the `goto nextrow` preserves.
 *  - `rowbase` must be DECLARED BEFORE `dst`: the two are the only spilled
 *    locals and they take sp+0xc and sp+0x10 in declaration order, the later
 *    declaration at the lower address (docs/idioms/local-declaration-order-is-stack-order.md).
 *    The wrong order is otherwise byte-perfect and reads as exactly 4 bytes
 *    out, two stores and two loads with the slots swapped.
 *
 * EXACT*: the compiled body is 354 bytes and the listing's inferred extent is
 * 356 -- the follower at 0x0202843C has no label, so the extent ran two bytes
 * long over the alignment padding.  Not a byte difference.
 */
void func_020282D8(u32 bg, struct Cfg *cfg, u32 style)
{
    u8  y;
    u8  x;
    u32 rowbase;
    u32 dst;
    u32 tEdgeB;
    u32 tEdgeA;
    u32 src;
    u32 t;

    y = 0;
    if (y >= func_02045740((struct Descriptor *)bg)) {
        return;
    }
    t = style - 1;
    tEdgeB = (t + t * 2 + 9) << 5;
    tEdgeA = (t + t * 2 + 10) << 5;
    for (;;) {
        x = 0;
        if (x >= func_02045738((struct Descriptor *)bg)) {
            goto nextrow;
        }
        for (;;) {
        dst = (u32)func_020437D4((const struct Bmp *)((u32)func_02045770((struct Descriptor *)bg)));
        rowbase = (x + y * func_02045738((struct Descriptor *)bg)) << 5;
        if (y == 0 && x == 0) {
            src = cfg->f04->f14;
        } else if (y == 0 && x == func_02045738((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0x40;
        } else if (y == 0) {
            src = cfg->f04->f14 + 0x20;
        } else if (y == func_02045740((struct Descriptor *)bg) - 1 && x == 0) {
            src = cfg->f04->f14 + 0xc0;
        } else if (y == func_02045740((struct Descriptor *)bg) - 1 && x == func_02045738((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + (1 << 8);
        } else if (y == func_02045740((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0xe0;
        } else if (style != 0 && x == func_02045738((struct Descriptor *)bg) - 3) {
            src = cfg->f04->f14 + tEdgeB;
        } else if (style != 0 && x == func_02045738((struct Descriptor *)bg) - 2) {
            src = cfg->f04->f14 + tEdgeA;
        } else if (x == 0) {
            src = cfg->f04->f14 + 0x60;
        } else if (x == func_02045738((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0xa0;
        } else {
            src = cfg->f04->f14 + 0x80;
        }
        MIi_CpuCopy32((const void *)src, (void *)(dst + rowbase), 0x20);
            x++;
            if (x >= func_02045738((struct Descriptor *)bg)) {
                break;
            }
        }
nextrow:
        y++;
        if (y >= func_02045740((struct Descriptor *)bg)) {
            return;
        }
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202843C.c \\
 *       --func func_0202843C --addr 0x0202843C --thumb --cc 1.1p1
 */
void func_0202843C(u8 *p)
{
    func_020456F8((struct Descriptor *)(((struct Obj11291 *)p)->f0));
    func_02041B6C((u8)*(u16 *)(((struct Obj11291 *)p)->f18));
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028454.c \\
 *       --func func_02028454 --addr 0x02028454 --thumb --cc 1.1p1
 */
void func_02028454(u8 *p)
{
    func_02045374((struct Cfg *)(((struct Obj11292 *)p)->f0));
    func_02041B6C((u8)*(u16 *)(((struct Obj11292 *)p)->f18));
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202846C.c \\
 *       --func func_0202846C --addr 0x0202846C --thumb --cc 1.1p1
 */
u32 func_0202846C(u8 *p)
{
    return ((struct Obj15793 *)p)->fC;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028470.c \\
 *       --func func_02028470 --addr 0x02028470 --thumb --cc 1.1p1
 */
void func_02028470(u8 *p, u32 v)
{
    func_02082BCC(p, 0, 8);
    ((struct Obj15794 *)p)->f4 = v;
}



/*
 * Per-frame service step for one handle attached to a state block: reads
 * the handle's state word with func_0201CE30 and dispatches on it as a
 * switch. State 1 finishes the handle (func_020284F4 on the block's flags
 * word, then a fixed-id notify through func_020061E4 and a teardown call);
 * state 0 runs a two-phase step, gated on bit 10 of the same flags word,
 * where func_0202855C latches the block's first byte and func_02028528
 * later releases the handle. Both state-0 callees take the flags word in
 * r0, which is what pins it there across the whole arm and pushes the mask
 * and the byte test into r1. State 2, and a null handle, return 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028484.c \
 *       --func func_02028484 --addr 0x02028484 --cc 1.1p1 --thumb
 */
s32_02028484 func_02028484(Blk *blk, void *h)
{
    u32 mask;

    if (h != 0) {
        switch (func_0201CE30(h)) {
        case 2:
            return 1;
        case 1:
            if (func_020284F4(blk->flags) != 0) {
                func_020061E4(0x547);
                func_0201CE38(h);
            }
            break;
        case 0:
            mask = 1 << 10;
            if ((mask & blk->flags) == 0) {
                if (blk->first == 0) {
                    if (func_0202855C(blk->flags) != 0) {
                        blk->first = 1;
                    }
                } else {
                    if (func_02028528(blk->flags) != 0) {
                        func_0201CE5C(h, 0);
                    }
                }
            }
            break;
        }
        return 0;
    }
    return 1;
}



u32 func_020284F4(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_020362DC() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C60() != 0) {
            r = 1;
        }
    }

    return r;
}



u32 func_02028528(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_0203630C() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C38() != 0) {
            r = 1;
        }
    }

    return r;
}



u32 func_0202855C(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_0203630C() == 0) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C38() == 0) {
            r = 1;
        }
    }

    return r;
}


void func_02028590(u32 a0, u32 a1, u32 a2, u16 a3)
{
    func_020285A4(a0, a1, a2, a3, g_0209FD10);
}
