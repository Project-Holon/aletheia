/*
 * file:     bmp_menulist_p03.c
 * unit:     yes
 * function: func_02020A34, func_02020A58, func_02020B5C
 * address:  0x02020A34
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
 *   func_020437D4  0x020437D4  arm
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 */
struct Bmp;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Elem {
    u32 unk00;
    void *unk04;
};

struct Obj {
    struct Elem *arr;
    void (*callback)(struct Obj *, void *, void *);
    u8 pad[0x40 - 0x08];
    u16 f40;
    u16 f42;
};

typedef signed int     s32;

extern void *func_020437D4(const struct Bmp *bmp);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
void func_02020A58(void *bmp, u32 dir, u32 start, u32 color, u16 size);
void func_02020B5C(void *bmp, u32 dir, u32 start, u32 color, u16 size);


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
