/*
 * file:     btlv_b_gauge_p05.c
 * unit:     yes
 * function: func_022080B0, func_022080F4, func_02208268, func_022082FC, func_02208420, func_02208550
 * address:  0x022080B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_020437D4 0x020437D4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02045808 0x02045808 arm
 *   func_020437AC 0x020437AC arm
 *   func_02208034 0x02208034 thumb ov094
 *   func_0202D034 0x0202D034 thumb
 *   func_0220868C 0x0220868C thumb ov094
 *   func_0201F35C 0x0201F35C thumb
 */
#include "../../matched/include/Obj01911.h"

struct Bmp;
struct StrObj;
struct Struct36;
struct U16Vec;
struct CharBuf;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct { int w[9]; } Struct36;

typedef struct { void *f0; char p4[0x40]; int f44; } E_022080F4;

typedef struct { void *f0; char p4[0x44 - 4]; int f44; char p48[0x6d - 0x48]; u8 f6d; } E_02208268;

typedef struct { char p0[0x14]; char *f14; } O_02208268;

typedef struct E_022082FC {
    void *f0, *f4, *f8, *fc, *f10;
    char p14[0x34];
    int f48, f4c;
    u32 f50;
    int f54, f58, f5c, f60;
    u32 f64;
    int f68;
    u8 f6c;
    char p6d[0x13];
} E_022082FC;

typedef struct O_022082FC {
    char p0[0x14];
    char *f14;
    char p18[0x28];
    E_022082FC e[8];
    u32 lo:4, b4:1, hi:27;
} O_022082FC;

typedef struct { char p0[0x14]; char *f14; } O_02208420;

typedef struct { char p0[4]; void *f4; char p8[0x44]; int f4c; } E_02208420;

typedef struct { void *f0; char p4[0x40]; int f44; char p48[0x24]; u8 f6c; } E_02208550;

typedef struct { char p0[8]; void *f8; char pc[0x43c]; u16 heap; } O_02208550;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
extern u8 func_02208034(u32, int, int, u32 *, u8 *, u8);
extern int func_0202D034(u32, u32);
extern void func_0220868C(O_022082FC *, E_022082FC *, int);
extern void func_0201F35C(void *, int, u32, u32, u32);
int func_022080B0(int a, int b, int c, unsigned int d);
void func_022080F4(char *o, E_022080F4 *e, void *data);
void func_02208268(O_02208268 *o, E_02208268 *e);
void func_022082FC(O_022082FC *o, int idx, int k);
void func_02208420(const O_02208420 *o, E_02208420 *e, int v);
void func_02208550(O_02208550 *o, E_02208550 *e);

int func_022080B0(int a, int b, int c, unsigned int d)
{
    int k;
    int x;
    int p;
    int q;
    int r;

    k = (d << 27) >> 24;
    x = a - b;
    if (x < 0) {
        x = 0;
    } else if (x > c) {
        x = c;
    }
    p = (a * k) / c;
    q = (x * k) / c;
    r = (signed char)p - (signed char)q;
    r = (signed char)r;
    if (r < 0) {
        r = -r;
    }
    return r;
}

/*
 * lever: an enum VRAM base assigned in both copy arms prevents folding
 *   each base-plus-offset into a separate literal pool word.
 */
void func_022080F4(char *o, E_022080F4 *e, void *data)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    enum { VRAM_BASE = 0x06400000 } vram;
    v = func_020457B0(12, (u16)((((struct Obj01911 *)o)->f448 & 0x7fff) | 0x8000));
    bmp = func_02043678(8, 2, 32, (u16)((((struct Obj01911 *)o)->f448 & 0x7fff) | 0x8000));
    func_02043B5C(bmp, 0);
    func_02017E1C(data, 0x73, (u32)v);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 4, 0);
    if ((int)func_0201D304(v, (u32)(((struct Obj01911 *)o)->f8), (int)0) > 48)
        func_0201C7A4(bmp, 2, 5, v, ((struct Obj01911 *)o)->f8);
    else
        func_0201C7A4(bmp, 8, 5, v, ((struct Obj01911 *)o)->f8);
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    func_0204B7C8(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        vram = VRAM_BASE;
        func_02082A60(pixels, (void *)(vram + 0x40 + buf.w[1]), 0xc0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x140 + buf.w[1]), 0xc0);
        func_02082A60(pixels + 0xc0, (void *)(vram + 0x400 + buf.w[1]), 0x40);
        func_02082A60(pixels + 0x1c0, (void *)(vram + 0x500 + buf.w[1]), 0x40);
    } else {
        vram = VRAM_BASE;
        func_02082A60(pixels, (void *)(vram + 0x20 + buf.w[1]), 0xe0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x120 + buf.w[1]), 0xe0);
        func_02082A60(pixels + 0xe0, (void *)(vram + 0x400 + buf.w[1]), 0x20);
        func_02082A60(pixels + 0x1e0, (void *)(vram + 0x500 + buf.w[1]), 0x20);
    }
    func_02045808(v);
    func_020437AC(bmp);
}


void func_02208268(O_02208268 *o, E_02208268 *e)
{
    Struct36 buf;
    int off1;
    int off2;
    enum { VRAM_BASE = 0x06400000 } vram;

    off1 = e->f6d * 64 + 0x380;
    off2 = e->f6d * 64 + 0x3a0;
    if (e->f6d == 2) {
        off1 = 0x660;
        off2 = 0x660;
    }
    func_0204B7C8(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        vram = VRAM_BASE;
        func_02082A60(o->f14 + off1, (void *)(vram + 0x440 + buf.w[1]), 0x20);
        func_02082A60(o->f14 + off2, (void *)(vram + 0x540 + buf.w[1]), 0x20);
    } else {
        vram = VRAM_BASE;
        func_02082A60(o->f14 + off1, (void *)(vram + 0x420 + buf.w[1]), 0x20);
        func_02082A60(o->f14 + off2, (void *)(vram + 0x520 + buf.w[1]), 0x20);
    }
}

/*
 * trailing: 0220841E..02208420 is two bytes of zero alignment padding.
 * lever: u8 count retains the result spill; enum VRAM base preserves add
 *   order and register home; zero the loop counter before assigning base.
 */
void func_022082FC(O_022082FC *o, int idx, int k)
{
    E_022082FC *e;
    u8 a[10];
    Struct36 buf;
    int color, val;
    u8 n, i;
    enum { VRAM = 0x06400000 } base;
    e = &o->e[idx];
    switch (k) {
    case 0:
        if (o->b4 && !(idx & 1)) break;
        func_0204B7C8(e->f8, (struct Struct36 *)(&buf));
        n = func_02208034(e->f4c, e->f48, e->f68, &e->f50, a, 6);
        val = e->f50;
        if (e->f4c < 48) val >>= 8;
        switch (func_0202D034(val, e->f4c)) {
        case 0: color = 0; break;
        case 1: color = 0x120; break;
        case 2:
        default: color = 0x240; break;
        }
        for (i = 0; i < 6; i++) {
            base = VRAM;
            func_02082A60(o->f14 + (color + a[i] * 32), (void *)(buf.w[1] + (base + (i + 1) * 32)), 32);
        }
        if (e->f68 > 0) func_0220868C(o, e, n);
        break;
    case 1:
        if (e->f10 == 0) break;
        func_0204B7C8(e->f10, (struct Struct36 *)(&buf));
        func_02208034(e->f58, e->f54, e->f60, &e->f64, a, 10);
        if (e->f6c == 100) {
            for (i = 0; i < 10; i++) a[i] = 0;
        }
        i = 0;
        base = VRAM;
        for (; i < 10; i++) {
            func_02082A60(o->f14 + (a[i] * 32 + 0x400), (void *)(buf.w[1] + (base + (i + 1) * 32)), 32);
        }
        break;
    }
}

void func_02208420(const O_02208420 *o, E_02208420 *e, int v)
{
    Struct36 buf;
    u16 current[3];
    u16 maximum[3];
    int i, n, j;
    enum { VRAM = 0x06400000 } base;
    if (e->f4 != 0) {
        func_0204B7C8(e->f4, (struct Struct36 *)(&buf));
        for (i = 0; i < 3; i++) {
            current[i] = 0x660;
            maximum[i] = 0x660;
        }
        if (v >= 100) {
            current[0] = v / 100 * 32 + 0x520;
            v %= 100;
        }
        if (v >= 10 || current[0] != 0x660) {
            current[1] = v / 10 * 32 + 0x520;
            v %= 10;
        }
        current[2] = v * 32 + 0x520;
        n = e->f4c;
        j = 0;
        if (n >= 100) {
            maximum[j] = n / 100 * 32 + 0x520;
            n %= 100;
            j++;
        }
        if (n >= 10 || j != 0) {
            maximum[j] = n / 10 * 32 + 0x520;
            n %= 10;
            j++;
        }
        maximum[j] = n * 32 + 0x520;
        i = 0;
        base = VRAM;
        for (; i < 3; i++) {
            func_02082A60(o->f14 + current[i], (void *)(buf.w[1] + (base + i * 32)), 32);
            func_02082A60(o->f14 + maximum[i], (void *)(buf.w[1] + (base + (i + 4) * 32)), 32);
        }
    }
}

/*
 * lever: initialize the reusable heap offset; assign enum VRAM in each
 *   copy arm; split addr = base; addr = addr + off and add buf.w[1] last.
 */
void func_02208550(O_02208550 *o, E_02208550 *e)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    u32 off = 0x448;
    int addr;
    enum { VRAM = 0x06400000 } base;
    v = func_020457B0(4, (u16)((*(u16 *)((char *)o + off) & 0x7fff) | 0x8000));
    bmp = func_02043678(3, 2, 32, (u16)((*(u16 *)((char *)o + off) & 0x7fff) | 0x8000));
    func_02043B5C(bmp, 0);
    func_0201F35C(v, e->f6c, 3, 0, 0);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 4, 0);
    func_0201C7A4(bmp, 0, 5, v, o->f8);
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    func_0204B7C8(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        base = VRAM;
        off += 0x38;
        addr = base;
        addr = addr + off;
        func_02082A60(pixels, (void *)(addr + buf.w[1]), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x580 + buf.w[1]), 0x60);
    } else {
        base = VRAM;
        off += 0x18;
        addr = base;
        addr = addr + off;
        func_02082A60(pixels, (void *)(addr + buf.w[1]), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x560 + buf.w[1]), 0x60);
    }
    func_02045808(v);
    func_020437AC(bmp);
}
