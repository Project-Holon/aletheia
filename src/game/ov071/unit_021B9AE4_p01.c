/*
 * file:     unit_021B9AE4_p01.c
 * unit:     yes
 * function: func_021B9AE4, func_021B9B3C, func_021B9B64, func_021B9BA0, func_021B9BAC, func_021B9BB8, func_021B9BC8, func_021B9BD8, func_021B9BE8, func_021B9C1C, func_021B9C30, func_021B9C7C, func_021B9F2C, func_021B9F74, func_021B9FEC, func_021B9FF8, func_021BA004
 * address:  0x021B9AE4
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   d_021BAB10     0x021BAB10  data  a4
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_021B6A0C 0x021B6A0C thumb ov071
 *   func_020355C4 0x020355C4 arm
 *   func_021B6B58 0x021B6B58 thumb ov071
 *   func_021B6B38  0x021B6B38  thumb  ov071
 *   func_021B6B70  0x021B6B70  thumb  ov071
 *   func_021B7070 0x021B7070 thumb ov071
 *   func_021B70B8 0x021B70B8 thumb ov071
 *   func_021B70C4 0x021B70C4 thumb ov071
 *   func_021B7118 0x021B7118 thumb ov071
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B7168 0x021B7168 thumb ov071
 *   func_021B7170  0x021B7170  thumb  ov071
 *   func_02035CB8  0x02035CB8  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_021BA1DC  0x021BA1DC  thumb  ov071
 *   func_020413B0  0x020413B0  arm
 */
#include "../../matched/include/Obj02123.h"
#include "../../matched/include/Obj07705.h"
#include "../../matched/include/Obj13185.h"
#include "../../matched/include/Obj00044.h"
#include "../../matched/include/Obj20757.h"

struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct Obj;
typedef unsigned char u8;

typedef struct {
    void *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
} Tmpl;

typedef struct {
    u8 pad00[0x2a0];
    void *a2a0[7];
    void *a2bc[7];
} Work;

typedef struct {
    u8 pad00[0x2c];
    void *f2c;
    u8 pad30[0x5c - 0x30];
    int f5c;
} Src;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u8 pad000[0x1b4];
    int f1b4[(0x27c - 0x1b4) / 4];
    u8 f27c;
    u8 pad27d[0x2d8 - 0x27d];
    int f2d8;
    int f2dc;
    int f2e0;
    int f2e4;
    int f2e8;
    int f2ec;
    int f2f0;
    int f2f4;
} S;

extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_021B6A0C(void *, void *, int, int, int, int, int, void *);
extern u8 func_020355C4(void);
extern void func_021B6B58(void **p, int v);
extern void func_021B7070(int *, int *);
extern void func_021B70B8(void **);
extern void func_021B70C4(void *);
extern struct Obj *func_021B7118(int *p, int x, int y, int w);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021B7168(void *);
extern void func_021B7170(void *a);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern int func_02035C60(void);
extern int func_021BA1DC(char *p, unsigned a);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
void func_021B9AE4(Work *p, Src *s);
void func_021B9B3C(char *p);
void func_021B9B64(char *p, char *q);
void func_021B9BA0(void *p);
void func_021B9BAC(void *p, int a);
void func_021B9BB8(char *p, char *q);
void func_021B9BC8(char *p);
void func_021B9BD8(char *p);
void func_021B9BE8(char *p, char *q);
void func_021B9C1C(char *p);
void func_021B9C30(u8 *p);
int func_021B9C7C(void *a, S *p);
int func_021B9F2C(u8 *p, int i, int v);
void func_021B9F74(u8 *p, int i, int v);
void func_021B9FEC(void *p, int a);
void func_021B9FF8(void *p, int a);
void func_021BA004(char *p);
extern const Tmpl d_021BAB10;


void func_021B9AE4(Work *p, Src *s)
{
    int i;
    Tmpl t;

    t = d_021BAB10;
    t.f08 = s->f5c;
    for (i = 0; i < 7; i++) {
        p->a2bc[i] = func_02043678(0x17, 2, 0x20, 0x61);
        t.f00 = p->a2bc[i];
        p->a2a0[i] = func_020255A0(s->f2c, (const struct Param *)(&t));
    }
}

void func_021B9B3C(char *p) { int i; for (i = 0; i < 7; i++) { func_0202570C(*(void **)(p + i * 4 + 0x2a0)); func_020437AC(*(void **)(p + i * 4 + 0x2bc)); } }

void func_021B9B64(char *p, char *q) { func_021B6A0C(((struct Obj02123 *)p)->f4, q + 8, 1, 2, 0x40, 0xb4, 0x24, 0); if (func_020355C4() == 1) func_021B6B58((void **)(q + 8), 0); }

void func_021B9BA0(void *p)
{
    void func_021B6B38(void **p);
    func_021B6B38((void **)((char *)p + 8));
}

void func_021B9BAC(void *p, int a)
{
    int func_021B6B70(void **p, u8 *q);
    func_021B6B70(p, (u8 *)(a + 8));
}

void func_021B9BB8(char *p, char *q) { func_021B7070(*(int * *)&((struct Obj02123 *)p)->f4, (int *)(q + 0x298)); }

void func_021B9BC8(char *p) { func_021B70B8((void **)(p + 0x298)); }

void func_021B9BD8(char *p) { func_021B70C4(p + 0x298); }

void func_021B9BE8(char *p, char *q) { ((struct Obj07705 *)q)->f18 = func_021B7118(((struct Obj02123 *)p)->f4, 0x80, 0x1c, 9); ((struct Obj07705 *)q)->f1C = func_021B7118(((struct Obj02123 *)p)->f4, 0x80, 0xa4, 10); func_0204B3DC(((struct Obj07705 *)q)->f18, 0); func_0204B3DC(((struct Obj07705 *)q)->f1C, 0); }

void func_021B9C1C(char *p) { func_021B7168(((struct Obj13185 *)p)->f18); func_021B7168(((struct Obj13185 *)p)->f1C); }


void func_021B9C30(u8 *p)
{
    if (((struct Obj00044 *)p)->f2D8 <= 0x800)
        func_0204B3DC(((struct Obj00044 *)p)->f18, 0);
    else
        func_0204B3DC(((struct Obj00044 *)p)->f18, 1);
    if ((((struct Obj00044 *)p)->f2D8 >> 8) >= p[0x27c] * 32 - 200)
        func_0204B3DC(((struct Obj00044 *)p)->f1C, 0);
    else
        func_0204B3DC(((struct Obj00044 *)p)->f1C, 1);
    func_021B7170(((struct Obj00044 *)p)->f18);
    func_021B7170(((struct Obj00044 *)p)->f1C);
}


/*
 * `touch = 0` in the key branch is what keeps r7 as the zero stored to
 * f2e0/f2dc and passed to func_020355D8; `p->f2e4 = ret` (not 0) reloads
 * the spilled result as in the image.
 */
int func_021B9C7C(void *a, S *p)
{
    int ret;
    int sel;
    u32 x;
    u32 y;
    int touch;
    int t;
    int row;
    int rem;
    int d;
    int r;

    ret = 0;
    sel = 0xffff;
    p->f2e4 = ret;
    touch = func_02035CB8(&x, &y);
    if (p->f2dc == 0) {
        if (x < 0x18 || x > 0xe0) {
            touch = 0;
        }
    }
    if (func_0203630C() & 0xc3) {
        t = (p->f2d8 >> 8) + 0x18;
        row = t / 32;
        rem = t % 32;
        touch = 0;
        p->f2e0 = touch;
        p->f2dc = touch;
        if (p->f2f4 == 0xffff) {
            if (rem != 0) {
                row++;
            }
            if (row < 1) {
                row = 1;
            }
            if (row >= p->f27c - 2) {
                func_021B9F2C((u8 *)p, p->f27c - 2, 1);
            } else {
                func_021B9F2C((u8 *)p, row, 1);
            }
            func_020061E4(0x548);
            return 0;
        }
        if (func_020362DC() & 1) {
            func_021B9F2C((u8 *)p, p->f2f4, 1);
            func_020355D8(0);
            if (p->f1b4[p->f2f4] == 0) {
                func_020061E4(0x54c);
            }
            return 1;
        }
        if (func_0203633C() & 0x40) {
            if (rem != 0) {
                row++;
            }
            if (func_021B9F2C((u8 *)p, p->f2f4 - 1, 1) == 1) {
                func_020061E4(0x548);
            }
            if (p->f2f4 < row) {
                p->f2e4 = -0x2000;
            }
            return 0;
        }
        if (func_0203633C() & 0x80) {
            row = ((p->f2d8 >> 8) + 0xa8) / 32;
            if (func_021B9F2C((u8 *)p, p->f2f4 + 1, 1) == 1) {
                func_020061E4(0x548);
            }
            if (p->f2f4 >= row) {
                p->f2e4 = 0x2000;
            }
            return 0;
        }
    }
    if (p->f2dc == 0) {
        if (touch == 1) {
            if (y > 0x18 && y < 0xa8) {
                p->f2dc = 1;
                p->f2e8 = y;
                p->f2ec = y;
                func_021B9F2C((u8 *)p, 0xffff, 0);
            } else if (func_02035C60() == 1 && p->f2f4 != 0xffff
                       && x >= 0x10 && x <= 0x70 && y >= 0xac && y <= 0xbc) {
                ret = 1;
                sel = p->f2f4;
                func_020355D8(1);
            }
        } else if (p->f2e0 != 0) {
            if (p->f2e0 > 0) {
                p->f2e0 -= 0xc0;
                if (p->f2e0 < 0) {
                    p->f2e0 = 0;
                }
            } else {
                p->f2e0 += 0xc0;
                if (p->f2e0 > 0) {
                    p->f2e0 = 0;
                }
            }
        }
    } else if (touch == 0) {
        p->f2dc = 0;
        if (p->f2ec != 0xffff) {
            d = p->f2e8 - p->f2ec;
            if (d < 0) {
                d = -d;
            }
            if (d < 4) {
                r = func_021BA1DC((char *)p, p->f2e8);
                if (r != 0xffff) {
                    ret = 1;
                    sel = r;
                    func_020061E4(0x548);
                }
            }
        }
    } else {
        p->f2e0 = (p->f2e8 - y) << 8;
        p->f2e8 = y;
        p->f2dc++;
        if (p->f2ec != 0xffff) {
            d = y - p->f2ec;
            if (d < 0) {
                d = -d;
            }
            if (d > 4) {
                p->f2ec = 0xffff;
            }
        }
    }
    if (ret == 1) {
        p->f2e0 = 0;
        func_021B9F2C((u8 *)p, sel, 2);
    }
    return ret;
}


int func_021B9F2C(u8 *p, int i, int v)
{
    int old;

    if (i != 0xFFFF) {
        if (i >= p[0x27c] - 1 || i < 1) {
            return 0;
        }
    }
    old = ((struct Obj00044 *)p)->f2F4;
    ((struct Obj00044 *)p)->f2F8 = old;
    ((struct Obj00044 *)p)->f2FC = old;
    ((struct Obj00044 *)p)->f2F4 = i;
    ((struct Obj00044 *)p)->f304 = 1;
    ((struct Obj00044 *)p)->f308 = v;
    return 1;
}


void func_021B9F74(u8 *p, int i, int v)
{
    int x;
    int q;
    int m32;
    int m64;
    int d;

    if (i != 0xFFFF) {
        x = ((struct Obj20757 *)p)->f2D8 >> 8;
        q = x / 32;
        m32 = x % 32;
        m64 = x % 64;
        d = i - q;
        if (d >= 0 && d < q + 7) {
            func_020413B0(6, 3, ((d * 32 + m64 - m32) % 256) / 8, 0x19, 4, v);
        }
    }
}

/*
 * Two thunks passing a constant third argument.
 */
void func_021B9FEC(void *p, int a)
{
    void func_021B9F74(u8 *p, int i, int v);
    func_021B9F74(p, a, 3);
}


void func_021B9FF8(void *p, int a)
{
    void func_021B9F74(u8 *p, int i, int v);
    func_021B9F74(p, a, 0);
}

void func_021BA004(char *p) { if (((struct Obj00044 *)p)->f304 == 1) func_021B9FF8(p, ((struct Obj00044 *)p)->f2F8); }
