/*
 * file:     unit_021B9AE4.c
 * unit:     yes
 * function: func_021B9AE4, func_021B9B3C, func_021B9B64, func_021B9BA0, func_021B9BAC, func_021B9BB8, func_021B9BC8, func_021B9BD8, func_021B9BE8, func_021B9C1C, func_021B9C30, func_021B9C7C, func_021B9F2C, func_021B9F74, func_021B9FEC, func_021B9FF8, func_021BA004, func_021BA01C, func_021BA0CC, func_021BA11C, func_021BA140, func_021BA1B0, func_021BA1DC, func_021BA1FC, func_021BA2CC, func_021BA384, func_021BA3B4, func_021BA400, func_021BA420, func_021BA44C, func_021BA4D4, func_021BA4EC, func_021BA528
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
 *   func_020413B0  0x020413B0  arm
 *   func_021B6C30  0x021B6C30  thumb  ov071
 *   func_021B6C48  0x021B6C48  thumb  ov071
 *   func_021B6BEC  0x021B6BEC  thumb  ov071
 *   func_02041B6C  0x02041B6C  arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202590C  0x0202590C  thumb
 *   func_02043814  0x02043814  arm
 *   func_020257D0 0x020257D0 thumb
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 *   func_021BA5D4  0x021BA5D4  thumb  ov071
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAB94     0x021BAB94  data  a4
 *   d_021BABB4     0x021BABB4  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02043B5C  0x02043B5C  arm
 */
#include "../../matched/include/Obj02123.h"
#include "../../matched/include/Obj07705.h"
#include "../../matched/include/Obj13185.h"
#include "../../matched/include/Obj00044.h"
#include "../../matched/include/Obj20757.h"
#include "../../matched/include/Obj20758.h"
#include "../../matched/include/Obj20759.h"
#include "../../matched/include/Obj13186.h"
#include "../../matched/include/Obj13187.h"
#include "../../matched/include/Obj06191.h"
#include "../../matched/include/Obj07706.h"
#include "../../matched/include/Obj20760.h"
#include "../../matched/include/Obj06192.h"
#include "../../matched/include/Obj09900.h"
#include "../../matched/include/Obj13188.h"
#include "../../matched/include/Obj20762.h"
#include "../../matched/include/Obj20763.h"
#include "../../matched/include/Obj20764.h"
#include "../../matched/include/Obj09901.h"
#include "../../matched/include/Obj13189.h"
#include "../../matched/include/Obj03178.h"
#include "../../matched/include/Obj06193.h"

struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct Obj;
struct Obj0203159C;
struct Descriptor;
struct PrintSys;
struct S020315D4;
struct BgTemplate;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct Big;
struct CharBuf;
struct Ctx;
struct Rec1B0;
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
} S_021B9AE4;

typedef signed short   s16;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct {
    int h[3];
    struct {
        int h;
        u8 on;
        u8 pad[3];
    } e[3];
} S_021BA384;

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
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_021B6C30(int *p, int flag, int index);
extern void func_021B6C48(void *p, int a);
extern void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
extern void func_02041B6C(u32 bit);
extern void func_02041EE4(unsigned, unsigned, unsigned);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_020257D0(struct Obj *o);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021BA5D4(void *a, void *b, void *c);
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_02043534(unsigned int);
extern void func_020315D4(struct S020315D4 *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(int a, int b, int c, int d, int e, int f, int g);
extern void func_020403F4(unsigned);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 func_0200BF10(struct Rec1B0 *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
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
int func_021B9C7C(void *a, S_021B9AE4 *p);
int func_021B9F2C(u8 *p, int i, int v);
void func_021B9F74(u8 *p, int i, int v);
void func_021B9FEC(void *p, int a);
void func_021B9FF8(void *p, int a);
void func_021BA004(char *p);
void func_021BA01C(void *a, u8 *p);
int func_021BA0CC(u8 *p, int d);
void func_021BA11C(char *p);
void func_021BA140(u8 *p);
void func_021BA1B0(void *unused, char *p);
int func_021BA1DC(char *p, unsigned a);
int func_021BA1FC(struct Obj0203159C *a, int *b, u8 *o, u8 *c);
int func_021BA2CC(int a, int *b, u8 *o, u8 *c);
int func_021BA384(void *a, void *b, char *c, void **d);
void func_021BA3B4(void);
void func_021BA400(void);
void func_021BA420(char *p);
void func_021BA44C(int a, S_021BA384 *p);
void func_021BA4D4(void **p);
void func_021BA4EC(char *p, char *q);
void func_021BA528(u32 **a, u8 *b, u8 *c);
extern const Tmpl d_021BAB10;
extern char d_021BAB94[];
extern char d_021BABB4[];




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
int func_021B9C7C(void *a, S_021B9AE4 *p)
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




void func_021BA01C(void *a, u8 *p)
{
    int v;
    int m;

    if (((struct Obj00044 *)p)->f304 == 1) {
        func_021B9FEC(p, ((struct Obj00044 *)p)->f2F4);
        v = ((struct Obj00044 *)p)->f2F4;
        if (v == 0xffff) {
            func_021B6C30(a, 0, 1);
        } else {
            m = ((struct Obj00044 *)p)->f308;
            if ((m == 2 && v == ((struct Obj00044 *)p)->f2FC) || (m == 1 && v == ((struct Obj00044 *)p)->f2F8)) {
                if (*(int *)(p + 0x1b4 + v * 4) == 0) {
                    ((struct Obj00044 *)p)->f300 = v;
                    if (((struct Obj00044 *)p)->f308 == 1) {
                        func_021B6C48(a, 1);
                    } else {
                        func_021B6BEC(a, (int *)(p + 8), 1, 0, 3);
                    }
                } else if (m == 2) {
                    func_021B6C30(a, 1, 1);
                }
            } else {
                func_021B6C30(a, 1, 1);
            }
        }
        func_02041B6C(6);
        ((struct Obj00044 *)p)->f304 = 0;
    }
}




int func_021BA0CC(u8 *p, int d)
{
    int lim;
    int old;

    old = ((struct Obj00044 *)p)->f2D8;
    lim = p[0x27c] * 32 - 8;
    if (lim <= 0xc0) {
        return 0;
    }
    ((struct Obj00044 *)p)->f2D8 = old + d;
    if (((struct Obj00044 *)p)->f2D8 < 0x800) {
        ((struct Obj00044 *)p)->f2D8 = 0x800;
    } else if (((struct Obj00044 *)p)->f2D8 > (lim - 0xc0) << 8) {
        ((struct Obj00044 *)p)->f2D8 = (lim - 0xc0) << 8;
    }
    if ((((struct Obj00044 *)p)->f2D8 >> 8) != (old >> 8)) {
        return 1;
    }
    return 0;
}



void func_021BA11C(char *p) { func_02041EE4(6, 3, (((struct Obj20758 *)p)->f2D8 >> 8) % 64); }




void func_021BA140(u8 *p)
{
    int x = ((struct Obj20759 *)p)->f2D8 >> 8;
    int b = 8 - x % 32;
    u8 *q = p + (x / 32) * 4;
    int i;

    for (i = 0; i < 7; i++) {
        func_0202590C(*(void **)(p + i * 4 + 0x2a0), 0x20, b + i * 32);
        if (*(void **)(q + i * 4 + 0x24) != 0) {
            func_02043814(*(void **)(q + i * 4 + 0x24), *(void **)(p + i * 4 + 0x2bc));
        }
    }
}



void func_021BA1B0(void *unused, char *p) { int i; if (((struct Obj13186 *)p)->f2F0 == 1) { for (i = 0; i < 7; i++) func_020257D0(*(void **)(p + i * 4 + 0x2a0)); ((struct Obj13186 *)p)->f2F0 = 0; } }



int func_021BA1DC(char *p, unsigned a) { int x = ((((struct Obj13187 *)p)->f2D8 >> 8) + a) >> 5; if (x >= ((struct Obj13187 *)p)->f27C) x = 0xffff; return x; }




int func_021BA1FC(struct Obj0203159C *a, int *b, u8 *o, u8 *c)
{
    u8 *m;
    int busy;
    int i;
    u32 t;
    u8 *e;
    Bool f;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        ((struct Obj20760 *)m)->f24 = 0x30;
        func_021BA3B4();
        func_021BA420(((struct Obj07706 *)o)->f4);
        func_021BA44C((int)(((struct Obj07706 *)o)->f4), (S_021BA384 *)m);
        func_021BA4EC(((struct Obj07706 *)o)->f4, (char *)m);
        func_021BA528((u32 **)o, ((struct Obj07706 *)o)->f4, m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            t = (*(u32 **)(o + 4))[2];
            e = c + i * 8;
            if (e[0x10] != 0) {
                if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06191 *)e)->fC))) == 0) {
                    func_02045334((struct Descriptor *)((struct Obj06191 *)e)->fC);
                    e[0x10] = 0;
                }
            }
            f = e[0x10] == 0 ? B_TRUE : B_FALSE;
            if (f == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}




int func_021BA2CC(int a, int *b, u8 *o, u8 *c)
{
    int i;
    u8 f[3];
    u32 t;
    u8 *e;

    if (o[0x2d] == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        t = (*(u32 **)(o + 4))[2];
        e = c + i * 8;
        if (e[0x10] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06192 *)e)->fC))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj06192 *)e)->fC);
                e[0x10] = 0;
            }
        }
        f[i] = e[0x10] == 0;
    }
    if (*b == 0) {
        if ((*(u8 **)(o + 8))[3] == 1 && f[1] == 1) {
            func_021BA528((u32 **)o, ((struct Obj09900 *)o)->f4, c);
            (*(u8 **)(o + 8))[3] = 0;
        }
        if ((*(u8 **)(o + 8))[1] != ((struct Obj13188 *)c)->f24 && f[2] == 1) {
            func_021BA5D4(o, ((struct Obj09900 *)o)->f4, c);
            ((struct Obj13188 *)c)->f24 = (*(u8 **)(o + 8))[1];
        }
        return 0;
    }
    return 0;
}



int func_021BA384(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20763 *)(*(char * *)&((struct Obj20762 *)c)->f4))->f8) == 0) return 0;
    func_02043534(8);
    func_021BA4D4(d);
    func_021BA400();
    func_020315D4(a);
    return 1;
}



void func_021BA3B4(void)
{
    func_0203FCA0(0, (const struct BgTemplate *)d_021BAB94, 0);
    func_0203FCA0(2, (const struct BgTemplate *)d_021BABB4, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}


void func_021BA400(void) {
    func_02040588(0, 0); func_02040588(2, 0);
    func_020403F4(0); func_020403F4(2);
}


void func_021BA420(char *p) {
    func_020498F4((void *)(((struct Obj20764 *)p)->f30),13,2,0,0,1,0x61);
    func_020409B4(0); func_020409B4(2);
}



void func_021BA44C(int a, S_021BA384 *p)
{
    int i;

    p->h[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(0, 2, 4, 0x1c, 8, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    p->h[2] = func_020450F0(0, 2, 0xf, 0x1c, 9, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[2]);
    func_02045374((struct Cfg *)p->h[2]);
    for (i = 0; i < 3; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}


void func_021BA4D4(void **p) {
    int i;
    for (i = 0; i < 3; i++) func_020452E8(p[i]);
}


/*
 * note: trailing two-byte alignment padding.
 */
void func_021BA4EC(char *p, char *q) {
    unsigned s, h;
    s = (unsigned int)func_02045EC0((struct MsgBank *)(((struct Obj09901 *)p)->f28),38);
    h = ((struct Obj09901 *)p)->f8;
    func_0201C6FC((struct PrintSys *)h,(unsigned)func_02045770((struct Descriptor *)((struct Obj13189 *)q)->fC),0,4,(void *)s,((struct Obj09901 *)p)->fC);
    q[16] = 1;
    func_02045808((struct U16Vec *)s);
}



void func_021BA528(u32 **a, u8 *b, u8 *c)
{
    u32 s;
    u32 s2;
    u32 k;
    u32 h;

    k = func_0200BF10((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4((const struct Ctx *)(**a)))));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f4)), 0);
    if (k == 0x30) {
        s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f28), 0x27);
    } else {
        int off = k * 12;
        s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f20), *(u16 *)(*(u8 * *)&((struct Obj03178 *)b)->f34 + off + 4));
        s2 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj03178 *)b)->f24), *(u16 *)(*(u8 * *)&((struct Obj03178 *)b)->f34 + off + 6));
        h = ((struct Obj03178 *)b)->f8;
        func_0201C6FC((struct PrintSys *)h, (u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f14), 0, 0x10, (void *)s2, ((struct Obj03178 *)b)->fC);
        c[0x18] = 1;
        func_02045808((struct U16Vec *)s2);
    }
    h = ((struct Obj03178 *)b)->f8;
    func_0201C6FC((struct PrintSys *)h, (u32)func_02045770((struct Descriptor *)((struct Obj06193 *)c)->f14), 0, 0, (void *)s, ((struct Obj03178 *)b)->fC);
    c[0x18] = 1;
    func_02045808((struct U16Vec *)s);
}
