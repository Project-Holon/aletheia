/*
 * file:     bmp_menulist_p02.c
 * unit:     yes
 * function: func_020208B8, func_02020970, func_02020A34, func_02020A58, func_02020B5C
 * address:  0x020208B8
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
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02020780  0x02020780  thumb
 *   func_0202071C  0x0202071C  thumb
 *   func_020206C0  0x020206C0  thumb
 *   func_02045334  0x02045334  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 */
struct Descriptor;
struct CharBuf;
struct Bmp;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj_020208B8 {
    void *arr;
    void *unk04;
    void *unk08;
    void *unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Amid2 : 8;
    u16 f1Atop : 1;
    u8 pad1C[0x20 - 0x1C];
    u16 f20;
    u16 f22;
    u8 pad24[0x40 - 0x24];
    u16 f40;
    u16 f42;
};

struct Elem_020208B8 {
    u32 unk00;
    u32 unk04;
};

struct Obj_02020970 {
    struct Elem_020208B8 *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8 pad10[0x40 - 0x10];
    u16 f40;
    u16 f42;
};

struct Elem_02020A34 {
    u32 unk00;
    void *unk04;
};

struct Obj {
    struct Elem_02020A34 *arr;
    void (*callback)(struct Obj *, void *, void *);
    u8 pad[0x40 - 0x08];
    u16 f40;
    u16 f42;
};

typedef signed int     s32;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202055C(struct Obj_020208B8 *o, u32 a, u32 b, u32 c, u32 d);
extern void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);
extern u8   func_02020780(struct Obj_02020970 *obj, u8 dir);
extern void func_0202071C(struct Obj_02020970 *obj, u32 n);
extern void func_020206C0(struct Obj_02020970 *obj);
extern void func_02045334(struct Descriptor *win);
extern void *func_020437D4(const struct Bmp *bmp);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
void func_020208B8(struct Obj_020208B8 *obj, int n, u32 flag);
u32 func_02020970(struct Obj_02020970 *obj, u8 notify, u8 count, u8 dir);
void func_02020A34(struct Obj *obj, void *arg1);
void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size);



void func_020208B8(struct Obj_020208B8 *obj, int n, u32 flag)
{
    u8 step;

    if (n >= (int)obj->rows) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
        func_0202055C((struct Obj_020208B8 *)obj, obj->f40, 0, obj->rows, 1);
        return;
    }

    step = (u8)(obj->f22 + obj->f1Amid);
    if (flag == 0) {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 1, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C((struct Obj_020208B8 *)obj, obj->f40, 0, n, 1);
    } else {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 0, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C((struct Obj_020208B8 *)obj, (u16)(obj->f40 + (obj->rows - n)), (u16)(obj->rows - n), n, 0);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020970.c \
 *       --func func_02020970 --addr 0x02020970 --thumb
 *
 * Move the menu cursor count steps in direction dir (func_02020780 does one
 * step and answers 0 = no move, 1 = cursor moved inside the window, 2 = the
 * list scrolled), then, if notify, redraw what changed.  Closed in wave 13
 * after the 2026-09-21 note (docs/notes/func_02020970.c.txt) left it at 34
 * bytes out.  What closed it, in order of weight:
 *   - ALL THREE SCALAR PARAMETERS ARE NARROW (u8 here; u16 compiles the
 *     same).  u8 count is what gives the guard its `cmp r0,#0 / bls` with
 *     the reload from the home slot (u32 count gives `cmp #1 / blo` or folds
 *     onto r2); u8/u16 notify and dir are what schedule the three home
 *     stores ahead of the obj copy.
 *   - the guard is `i < count` with i already 0, around a do/while;
 *   - a skipped row (item value -3) re-runs the step WITHOUT advancing i:
 *     a goto to the top of the body, not a continue (continue reaches the
 *     condition);
 *   - `case 0: default: return 1;` written first; without case 0 the switch
 *     becomes a compare chain, with a separate default it duplicates.
 */
u32 func_02020970(struct Obj_02020970 *obj, u8 notify, u8 count, u8 dir)
{
    u8 acc;
    u8 moved;
    u8 i;
    u8 r;
    u16 saved;

    moved = 0;
    acc = 0;
    saved = obj->f42;
    i = 0;
    if (i < count) {
        do {
        again:
            r = func_02020780((struct Obj_02020970 *)obj, dir);
            acc |= r;
            if (r == 2) {
                moved++;
                if (obj->arr[obj->f40 + obj->f42].unk04 == (u32)-3)
                    goto again;
            }
            i++;
        } while (i < count);
    }
    if (notify != 0) {
        switch (acc) {
        case 0:
        default:
            return 1;
        case 1:
            func_0202071C((struct Obj_02020970 *)obj, saved);
            func_020206C0((struct Obj_02020970 *)obj);
            func_02020A34((struct Obj *)((struct Obj_02020970 *)obj), 0);
            func_02045334((struct Descriptor *)obj->unk0C);
            break;
        case 2:
        case 3:
            func_0202071C((struct Obj_02020970 *)obj, saved);
            func_020208B8((struct Obj_020208B8 *)obj, moved, dir);
            func_020206C0((struct Obj_02020970 *)obj);
            func_02020A34((struct Obj *)((struct Obj_02020970 *)obj), 0);
            break;
        }
    }
    return 0;
}



void func_02020A34(struct Obj *obj, void *arg1)
{
    if (obj->callback != 0) {
        obj->callback(obj, obj->arr[obj->f40 + obj->f42].unk04, arg1);
    }
}



void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32  len;
    s32  y;
    s32  src;
    s32  dst;
    u32  t;
    s32  x;
    u8  *buf;

    buf = func_020437D4(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)func_020437DC(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)func_020437E4(bmp) >> 3)) << 5;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                *(u32 *)(buf + dst) =
                    (src < len) ? *(u32 *)(buf + src) : fill;
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 4);
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 *q;
                u32  v;
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    q = (u32 *)(buf - dst);
                } else {
                    q = (u32 *)(buf - dst);
                    v = fill;
                }
                t++;
                *q = v;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}



void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32  len;
    s32  y;
    s32  src;
    s32  dst;
    u32  t;
    s32  x;
    u8  *buf;

    buf = func_020437D4(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)func_020437DC(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)func_020437E4(bmp) >> 3)) << 6;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x40) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 v;
                dst = y + x * 8;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 3);
                if (src < len) {
                    v = *(u32 *)(buf + src);
                    *(u32 *)(buf + dst) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf + dst) = v;
                }
                if (src + 4 < len + 4) {
                    v = *(u32 *)(buf + (src + 4));
                    *(u32 *)(buf + (dst + 4)) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf + (dst + 4)) = v;
                }
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 8);
        for (y = 0; y < len; y += 0x40) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32  v;
                dst = y + x * 8;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 3);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    *(u32 *)(buf - dst) = v;
                } else {
                    v = fill;
                    *(u32 *)(buf - dst) = v;
                }
                if (src - 4 < len - 4) {
                    v = *(u32 *)(buf - (src - 4));
                    dst = dst - 4;
                    *(u32 *)(buf - dst) = v;
                } else {
                    dst = dst - 4;
                    v = fill;
                    *(u32 *)(buf - dst) = v;
                }
                t++;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}
