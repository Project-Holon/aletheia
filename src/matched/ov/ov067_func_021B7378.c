/*
 * function: func_021B7378
 * address:  0x021B7378
 * packet:   pkt_ov067_021B7378
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed 848-byte extent also holds the unlabelled leaf 0x021B76B0
 * after the pool (filed separately).
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_020355C4  0x020355C4  arm
 *   func_021B76C8  0x021B76C8  thumb  ov067
 *   func_0204B404  0x0204B404  arm
 *   d_021B94C4     0x021B94C4  data  a1
 *   func_02035D40  0x02035D40  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021B94D0     0x021B94D0  data  a2
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021B7718  0x021B7718  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 v[12]; } Rect12;

struct Step {
    u16 frame;
    u16 idx;
};

typedef struct S {
    u8 pad00[0x0c];
    int fc;
    u32 f10;
    u8 pad14[0x16 - 0x14];
    u8 f16;
    u8 f17;
    u8 pad18[0x1c - 0x18];
    u32 f1c;
    u8 pad20[0x22 - 0x20];
    u16 f22[1][16];
    u8 pad42[0x88 - 0x42];
    void *f88;
    void *f8c;
    int f90;
    int f94;
    u32 f98;
    int f9c;
    void *fa0[4];
    u8 padb0[0xc0 - 0xb0];
    int fc0;
    u8 fc4;
    u8 padc5;
    u16 fc6;
    u16 fc8;
} S;

extern const Rect12 d_021B94C4;
extern const struct Step d_021B94D0[10];

extern u32 func_020362DC(void);
extern int func_02035D20(u32 *x, u32 *y);
extern void func_020061E4(u32 id);
extern void func_020355D8(int a);
extern int func_020355C4(void);
extern u8 func_021B76C8(u32 a, u32 b, u32 c);
extern void func_0204B404(void *cell, u16 *pt, u16 flags);
extern int func_02035D40(const void *rect, u32 x, u32 y);
extern void func_0204B3DC(void *p, int k);
extern void func_0204B92C(void *p, int k);
extern int func_02045770(void *p);
extern int func_0201C6C4(int a, int b);
extern void func_02045334(void *p);
extern void func_02045374(void *p);
extern u8 func_02045730(void *p);
extern void func_02041B6C(u32 bit);
extern void func_021B7718(u32 which, u8 idx, void *data);

void func_021B7378(S *p)
{
    Rect12 rect;
    u32 x;
    u32 y;
    u16 pt[2];
    int update;
    int touch;
    int handled;
    u32 keys;
    int changed;
    u8 i;
    void *o;

    update = 0;
    keys = func_020362DC();
    touch = func_02035D20(&x, &y);
    switch (p->f98) {
    case 0:
        break;
    case 1:
        p->f98 = 2;
        break;
    case 2:
        handled = 0;
        if (keys & 2) {
            func_020061E4(0x552);
            p->f9c = 0;
            handled = 1;
            func_020355D8(0);
        }
        if (!handled && func_020355C4() == 0 && keys != 0) {
            changed = 0;
            if (keys & 1) {
                if (p->fc0 == 0) {
                    func_020061E4(0x54d);
                    p->f9c = 1;
                } else {
                    func_020061E4(0x552);
                    p->f9c = 0;
                }
                handled = 1;
            } else if (keys & 0x40) {
                if (p->fc0 != 0) {
                    p->fc0 = 0;
                    changed = 1;
                }
            } else if (keys & 0x80) {
                if (p->fc0 != 1) {
                    p->fc0 = 1;
                    changed = 1;
                }
            }
            if (changed) {
                for (i = 0; i < 4; i++) {
                    pt[0] = func_021B76C8(p->fc0, i, 0);
                    pt[1] = func_021B76C8(p->fc0, i, 1);
                    func_0204B404(p->fa0[i], pt, p->f1c);
                }
                func_020061E4(0x548);
            }
        }
        if (!handled && touch != 0) {
            int res;
            rect = d_021B94C4;
            res = func_02035D40(&rect, x, y);
            if (res != -1) {
                if (res == 0) {
                    func_020061E4(0x54d);
                    p->f9c = 1;
                } else if (res == 1) {
                    func_020061E4(0x552);
                    p->f9c = 0;
                }
                handled = 1;
                func_020355D8(1);
            }
        }
        if (!handled && func_020355C4() == 1 && keys != 0) {
            for (i = 0; i < 4; i++) {
                func_0204B3DC(p->fa0[i], 1);
                func_0204B92C(p->fa0[i], 1);
            }
            func_020061E4(0x548);
            func_020355D8(0);
        }
        if (handled) {
            for (i = 0; i < 4; i++) {
                func_0204B3DC(p->fa0[i], 0);
                func_0204B92C(p->fa0[i], 0);
            }
            p->f98 = 3;
            p->fc4 = 0;
            p->fc8 = 1;
            p->fc6 = 1;
        }
        break;
    case 3:
        if (p->fc6 < 10) {
            if (p->fc8 == d_021B94D0[p->fc6].frame) {
                p->fc4 = d_021B94D0[p->fc6].idx;
                update = 1;
                p->fc6++;
            }
            p->fc8++;
        } else {
            p->f98 = 4;
        }
        break;
    case 4:
        break;
    }
    if (p->f98 != 0) {
        if (p->f90 == 0 && func_0201C6C4(p->fc, func_02045770(p->f88)) == 0) {
            o = p->f88;
            func_02045334(o);
            func_02045374(o);
            func_02041B6C(func_02045730(o));
            p->f90 = 1;
        }
        if (p->f94 == 0 && func_0201C6C4(p->fc, func_02045770(p->f8c)) == 0) {
            o = p->f8c;
            func_02045334(o);
            func_02045374(o);
            func_02041B6C(func_02045730(o));
            p->f94 = 1;
        }
    }
    if (update) {
        func_021B7718(p->f10, p->f9c == 1 ? p->f16 : p->f17, p->f22[p->fc4]);
    }
}
