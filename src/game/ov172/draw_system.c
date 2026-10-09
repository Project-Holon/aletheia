/*
 * file:     draw_system.c
 * unit:     yes
 * function: func_021B6A00, func_021B6A18, func_021B6A30, func_021B6A88, func_021B6ADC, func_021B6B68, func_021B6BE0, func_021B6C34, func_021B6C48, func_021B6C4C, func_021B6C78, func_021B6CA4, func_021B6E5C, func_021B6E88, func_021B6EA8, func_021B6EBC, func_021B6EC4, func_021B6ECC, func_021B6EE0, func_021B70A8, func_021B712C, func_021B71B8, func_021B7578, func_021B7590, func_021B75AC, func_021B7714, func_021B7724, func_021B7740, func_021B77B4, func_021B77B8
 * address:  0x021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021C88E8     0x021C88E8  data
 *   d_021C4D20 0x021C4D20 data a4
 *   d_021C4D10 0x021C4D10 data a1
 *   func_02030734 0x02030734 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   d_021C71D0 0x021C71D0 data a4
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021C4E84 0x021C4E84 data a4
 *   func_02082D44  0x02082D44  arm
 *   func_0207E008  0x0207E008  arm
 *   func_0203064C 0x0203064C arm
 *   func_0204A380 0x0204A380 arm
 *   func_021BE010 0x021BE010 thumb ov172
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_021B6100 0x021B6100 thumb ov172
 *   func_021B6950 0x021B6950 thumb ov172
 *   func_021B69BC 0x021B69BC thumb ov172
 *   func_021B674C 0x021B674C thumb ov172
 *   func_021B6744 0x021B6744 thumb ov172
 *   func_021B6814 0x021B6814 thumb ov172
 *   func_021B7888 0x021B7888 thumb ov172
 *   func_021B78A0 0x021B78A0 thumb ov172
 *   d_021C71E0 0x021C71E0 data a4
 *   func_0207C778 0x0207C778 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_021B63B8 0x021B63B8 thumb ov172
 *   func_020306F0 0x020306F0 arm
 *   func_021B78B8 0x021B78B8 thumb ov172
 *   func_021B64AC 0x021B64AC thumb ov172
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE1E4 0x021BE1E4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8BAC 0x021B8BAC thumb ov172
 *   func_020862F0 0x020862F0 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_0207E100 0x0207E100 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0202EB14 0x0202EB14 thumb
 *   func_021B6868  0x021B6868  thumb  ov172
 *   func_021B688C  0x021B688C  thumb  ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE0A4 0x021BE0A4 thumb ov172
 *   func_021BE0AC 0x021BE0AC thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_02034714 0x02034714 arm
 *   func_021BE0F8 0x021BE0F8 thumb ov172
 *   func_021BE0FC 0x021BE0FC thumb ov172
 *   d_021C71F0 0x021C71F0 data a4
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B796C 0x021B796C thumb ov172
 *   g_021C6E9C     0x021C6E9C  data   ov172
 */
#include "../../matched/include/Obj08255.h"
#include "../../matched/include/Obj24067.h"
#include "../../matched/include/Obj04549.h"
#include "../../matched/include/Obj04549.h"
#include "../../matched/include/Obj24068.h"
#include "../../matched/include/Obj00439.h"
#include "../../matched/include/Obj04550.h"
#include "../../matched/include/Obj03852.h"
#include "../../matched/include/Obj06558.h"
#include "../../matched/include/Obj02992.h"
#include "../../matched/include/Obj06552.h"
#include "../../matched/include/Obj24069.h"
#include "../../matched/include/Obj06553.h"
#include "../../matched/include/Obj00415.h"
#include "../../matched/include/Obj24070.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

typedef struct { u8 kind, pad; u16 count, x, y, a, b, c, d; void *data; } Object;

typedef struct Stroke_021B6A00 Stroke_021B6A00;

typedef struct {
    u8 x0;
    u8 y0;
    u8 x1;
    u8 y1;
    u16 c;
    u8 idx;
} Stroke_021B6C78;

typedef struct Shape {
    u8 w;
    u8 h;
    u8 m[32][32];
} Shape;

typedef struct Ent {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u8 pad[0xC];
} Ent;

typedef struct Q {
    u32 f0;
    char *f4;
    char *f8;
    char *fC;
    u8 f10;
    u8 pad11[3];
    int f14;
    int f18;
    int f1c;
    u32 f20;
    u8 pad24[8];
    u8 f2c;
    u8 f2d;
    u8 pad2e[2];
    int f30;
    u8 pad34[0xC];
    Ent ent[4];
} Q;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0203D7C8(u32, u32, const char *, u16);
extern void func_0203D7FC(void *p);
extern u32 func_020307B0(void *p);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern void  func_02082D44(void *a, void *b, int c);
extern void *func_0207E008(void);
extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern void *func_0204A380(void *, u32, u32, u32);
extern u32 func_021BE010(void *);
extern int func_021BE100(void);
extern char *func_021B6100(int);
extern void func_021B6950(char *, int);
extern void func_021B69BC(void *p, u32 v);
extern void func_021B674C(char *, int, u16);
extern void func_021B6744(void *p, u32 a, u32 b);
extern void func_021B6814(void *a0);
extern void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d);
extern void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d);
extern int func_0207C778(int);
extern void func_0207D59C(void *, int *, int, int, int, int);
extern void func_021B63B8(char *p);
extern void func_020306F0(unsigned int);
extern int func_021B78B8(void *, char *);
extern void func_021B64AC(char *p);
extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021BE054(void *p);
extern void func_021BE1E4(u8 *p);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern u8 func_021B8BAC(void *unused, char *base, int i);
extern void func_020862F0(void *p, u32 n);
extern void func_0207ECF0(const void *src, u32 off, u32 size);
extern void *func_0207E100(void);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern int func_0202EB14(void);
extern void func_021B6868(char *p);
extern int func_021B688C(void *p);
extern u32 func_021BDFDC(void *p);
extern u32 func_021BE0A4(void *p);
extern u32 func_021BE0AC(void *p);
extern u32 func_021BE0B4(void *p);
extern void MIi_CpuCopy32(const void *srcp, void *destp, unsigned long size);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern u32 func_021BE0F8(void *p);
extern void func_021BE0FC(void *p, u32 v);
extern unsigned int func_021B8BA4(int, char *, int);
extern void func_021B796C(void *, char *, int);
int func_021B6A00(void *a0, unsigned a1, void *a2);
int func_021B6A18(int a, int b, int c);
void func_021B6A30(short *src, unsigned char *dst, int n, int ctx);
void func_021B6A88(char *input, s16 *output, int size, char *state);
s8 func_021B6ADC(int sample, char *p);
s16 func_021B6B68(u8 code, const char *p);
Object *func_021B6BE0(Params *p);
void func_021B6C34(char *p);
void func_021B6C48(u32 a);
void func_021B6C4C(char *p);
void func_021B6C78(u16 *o, const Stroke_021B6C78 *e);
void func_021B6CA4(u16 *a, char *b, int x0, int x1, u16 y0, u16 y1, int idx, u16 arg);
void func_021B6E5C(unsigned short *p, char *base, u16 x, u16 y, unsigned short v);
void func_021B6E88(char *p, void *q);
void func_021B6EA8(void *p, u16 v);
void *func_021B6EBC(void);
u8 *func_021B6EC4(void *p, int i);
void func_021B6ECC(void *o, u16 *c);
char *func_021B6EE0(void *a, u16 b);
void func_021B70A8(int unused, char *q);
void func_021B712C(int unused, char *q);
void func_021B71B8(void *p, Q *q);
void func_021B7578(int x, char *p);
int func_021B7590(int x, char *p);
void func_021B75AC(char *src, void *p);
void func_021B7714(void *a, char *b, int c);
void func_021B7724(void *a, char *b, int c);
void func_021B7740(void *p, char *q, int a, int b);
u32 func_021B77B4(int unused, void *p);
u32 func_021B77B8(void *p);
extern u32 g_021C88E8[];
extern const int d_021C4D20[];
extern const s8 d_021C4D10[];
extern const char d_021C71D0[];
extern const Shape d_021C4E84[];
extern const char d_021C71E0[];
extern const char d_021C71F0[];
extern u32 g_021C6E9C[];







int func_021B6A00(void *a0, unsigned a1, void *a2)
{
    func_021B6A30((short *)a0, (unsigned char *)a2, (int)(a1 >> 1), (int)g_021C88E8);
    return (int)((a1 + 3) >> 2);
}







int func_021B6A18(int a, int b, int c)
{
    func_021B6A88((char *)a, (s16 *)c, b * 2, (void *)0x021C88E4);
    return b * 4;
}







/*
 * Packs the halfwords of src[0..n) into nibble pairs through func_021B6ADC and
 * writes the pair bytes to dst.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6A30(short *src, unsigned char *dst, int n, int ctx)
{
    int i;
    int out = 0;
    int pend = 0;
    int have = 0;

    for (i = 0; i < n; i++) {
        unsigned char v = (unsigned char)func_021B6ADC(src[i], (char *)ctx);

        if (have == 0) {
            pend = v;
            have = 1;
        } else {
            have = 0;
            dst[out] = (unsigned char)(pend + ((v & 0xf) << 4));
            pend = 0;
            out++;
        }
    }

    if (have == 1)
        dst[out] = (unsigned char)pend;
}






void func_021B6A88(char *input, s16 *output, int size, char *state)
{
    int i, count;
    char code;
    count = size / 2;
    for (i = 0; i < count; i++) {
        code = input[i];
        output[i * 2] = func_021B6B68(code & 15, state);
        output[i * 2 + 1] = func_021B6B68((code & 240) >> 4, state);
    }
}






s8 func_021B6ADC(int sample, char *p)
{
    int code, delta, step, value, index;
    code = 0;
    index = ((struct Obj08255 *)p)->f2;
    value = ((struct Obj08255 *)p)->f0;
    step = d_021C4D20[index];
    sample -= value;
    if (sample < 0) { code = 8; sample = -sample; }
    delta = step >> 3;
    if (sample >= step) { code |= 4; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 2; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 1; delta += step; }
    if (code & 8) value -= delta;
    else value += delta;
    if (value > 32767) value = 32767;
    else if (value < -32767) value = -32767;
    index += d_021C4D10[code];
    if (index < 0) index = 0;
    if (index > 88) index = 88;
    ((struct Obj08255 *)p)->f0 = value;
    ((struct Obj08255 *)p)->f2 = index;
    return code & 15;
}






s16 func_021B6B68(u8 code, const char *p)
{
  int step;
  int value;
  int index;
  int delta;
  value = *((s16 *) p);
  index = *((s8 *) (p + 2));
  step = d_021C4D20[index];
  delta = step >> 3;
  if (code & 4)
    delta += step;
  if (code & 2)
    delta += step >> 1;
  if (code & 1)
    delta += step >> 2;
  if (code & 8)
  {
    value -= delta;
    if (value < (-32767))
      value = -32767;
  }
  else
  {
    value += delta;
    if (value > 32767)
      value = 32767;
  }
  index += d_021C4D10[code];
  if (index < 0)
    index = 0;
  else
    if (index > 88)
    index = 88;
  *((s16 *) p) = (s16) value;
  *((s8 *) (p + 2)) = index;
  return (s16) value;
}






Object *func_021B6BE0(Params *p)
{
    Object *q;
    q = func_02030734(p->heap, 20, 1, d_021C71D0, 64);
    q->data = func_0203D7C8(p->heap, p->count * 8, d_021C71D0, 65);
    q->kind = p->kind;
    q->count = p->count;
    q->a = p->a;
    q->b = p->b;
    q->c = p->c;
    q->d = p->d;
    q->x = 0;
    q->y = 0;
    return q;
}







void func_021B6C34(char *p)
{
    func_0203D7FC(((struct Obj24067 *)p)->f10);
    func_020307B0(p);
}







void func_021B6C48(u32 a)
{
}





void func_021B6C4C(char *p)
{
    if (((struct Obj04549 *)p)->f6 != ((struct Obj04549 *)p)->f4) do {
        func_021B6C78((u16 *)p, (const Stroke_021B6C78 *)((const Stroke_021B6A00 *)func_021B6EC4(p, ((struct Obj04549 *)p)->f6)));
        func_021B6ECC(p, (u16 *)(p + 6));
    } while (((struct Obj04549 *)p)->f6 != ((struct Obj04549 *)p)->f4);
}




/*
 * note: 2026-10-02 the record pointer is const: that lets the scheduler hoist the r2/r3 loads
 *   above the outgoing stack stores (a plain pointer may alias the stack, which pins the order).
 */
void func_021B6C78(u16 *o, const Stroke_021B6C78 *e)
{
    func_021B6CA4(o, func_021B6EBC(), e->x0, e->x1, e->y0, e->y1, e->idx, e->c);
}



/*
 * note 2026-10-05 wD4 lane05: EXACT. Rewritten from the listing: const Shape table {u8 w, h; u8 m[32][32]}
 *   (const lets the t->w / t->h loop bounds hoist), u32 w/h locals, callee seen with u16 x/y, m1/m2 as
 *   `sx >= 0 ? 2 : 8`, px/py computed with ox/oy as copies inside an `if (n > 0)` around a do-while,
 *   and the abs values in the ternary macro form `(v < 0) ? -(v) : (v)` (fixes the y0/y1 colours).
 */
void func_021B6CA4(u16 *a, char *b, int x0, int x1, u16 y0, u16 y1, int idx, u16 arg)
{
    const Shape *t = &d_021C4E84[idx];
    int sx, sy, ax, ay, k;
    u8 m1, m2, j;
    int bx, by, ox, oy, n;
    int adx, ady, d, px, py;
    u8 fl, i;
    u32 w, h;
    adx = ((x0 - x1) < 0) ? -(x0 - x1) : (x0 - x1);
    ady = ((y0 - y1) < 0) ? -(y0 - y1) : (y0 - y1);
    n = (adx > ady ? adx : ady) + 1;
    d = x1 - x0;
    sx = _ffix(d > 0 ? _fadd(0.5f, _fflt(d << 12)) : _fsub(_fflt(d << 12), 0.5f)) / n;
    d = y1 - y0;
    sy = _ffix(d > 0 ? _fadd(0.5f, _fflt(d << 12)) : _fsub(_fflt(d << 12), 0.5f)) / n;
    ax = 0;
    ay = 0;
    w = t->w;
    h = t->h;
    px = x0 - (w >> 1);
    py = y0 - (h >> 1);
    m1 = (sx >= 0) ? 2 : 8;
    m2 = (sy >= 0) ? 4 : 1;
    k = 0;
    if (n > 0) {
    ox = px;
    oy = py;
    do {
        bx = ox + (ax >> 12);
        by = oy + (ay >> 12);
        if (k > 0) {
            fl = 0;
            if (bx != px) fl += m1;
            if (by != py) fl += m2;
        } else {
            fl = 0x1F;
        }
        for (j = 0; j < t->h; j++) {
            for (i = 0; i < t->w; i++) {
                if (t->m[j][i] & fl)
                    func_021B6E5C(a, b, bx + i, by + j, arg);
            }
        }
        ax += sx;
        ay += sy;
        px = bx;
        py = by;
    } while (++k < n);
    }
}




/*
 * Bounds-checks the two indices and stores the pixel into the +0xa8 plane.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6E5C(unsigned short *p, char *base, u16 x, u16 y,
                  unsigned short v)
{
    if (x >= p[4] && x < p[5] && y >= p[6] && y < p[7]) {
        *(u16 *)(base + x * 2 + y * 512) = v;
    }
}





/*
 * Copies one 8-byte entry in and steps the +4 cursor.
 *
 * Addresses are Black-image addresses.
 */
void func_021B6E88(char *p, void *q)
{
    func_02082D44(q, func_021B6EC4(p, ((struct Obj04549 *)p)->f4), 8);
    func_021B6ECC(p, (u16 *)(p + 4));
}




void func_021B6EA8(void *p, u16 v)
{
    u16 *h = (u16 *)p;
    h[2] = v;
    h[3] = v + 5;
    if (h[3] >= h[1])
        h[3] -= h[1];
}




void *func_021B6EBC(void)
{
    return func_0207E008();
}




/*
 * Pointer field at +0x10 advanced by 8 bytes per index.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_021B6EC4(void *p, int i)
{
    return (u8 *)((struct Obj04549 *)p)->f10 + i * 8;
}




void func_021B6ECC(void *o, u16 *c)
{
    *c += 1;
    if (*c >= ((struct Obj24068 *)o)->f2) {
        *c = 0;
    }
}




char *func_021B6EE0(void *a, u16 b)
{
    char *p;
    u32 r6;
    void *r0;
    char *q;
    u8 i;
    int off;

    p = func_02030734(b, 0xB4, 1, d_021C71E0, 0x67);
    r6 = func_021BE010(a);
    if (func_021BE100() == 1) {
        ((struct Obj00439 *)p)->f0 = 0x6E;
        func_0203064C(1, 0x6E, 0x80000);
        *(char * *)&((struct Obj00439 *)p)->fA4 = func_021B6100(((struct Obj00439 *)p)->f0);
        func_021B6950(*(char * *)&((struct Obj00439 *)p)->fA4, 5);
        func_021B69BC(*(char * *)&((struct Obj00439 *)p)->fA4, 1);
        func_021B674C(*(char * *)&((struct Obj00439 *)p)->fA4, 2, (u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000));
        func_021B6744(*(char * *)&((struct Obj00439 *)p)->fA4, (u32)((void *)func_021B75AC), (u32)a);
        func_021B6814(*(char * *)&((struct Obj00439 *)p)->fA4);
        ((struct Obj00439 *)p)->fA8 = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x76);
        ((struct Obj00439 *)p)->fAC = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x77);
        ((struct Obj00439 *)p)->fB0 = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x78);
        ((struct Obj00439 *)p)->f8 = func_0204A380((void *)r6, 0x19, 0, ((struct Obj00439 *)p)->f0);
        r0 = func_0204A380((void *)r6, 0x1A, 0, ((struct Obj00439 *)p)->f0);
    } else {
        ((struct Obj00439 *)p)->f8 = func_0204A380((void *)r6, 0x19, 0, b);
        r0 = func_0204A380((void *)r6, 0x1A, 0, b);
    }
    ((struct Obj00439 *)p)->fC = r0;
    i = 0;
    ((struct Obj00439 *)p)->f10 = i;
    ((struct Obj00439 *)p)->f2C = i;
    ((struct Obj00439 *)p)->f14 = i;
    ((struct Obj00439 *)p)->f2D = 0xC0;
    ((struct Obj00439 *)p)->f18 = i;
    ((struct Obj00439 *)p)->f1C = i;
    ((struct Obj00439 *)p)->f20 = i;
    ((struct Obj00439 *)p)->f30 = i;
    ((struct Obj00439 *)p)->f24 = i;
    ((struct Obj00439 *)p)->f28 = i;
    ((struct Obj00439 *)p)->f4 = func_02030734((u16)((b & 0x7FFF) | 0x8000), 0x18000, 1, d_021C71E0, 0x8C);
    q = p + 0x34;
    for (i = 0; i < 4; i++) {
        off = i * 0x1C;
        func_021B7888(q + off, 0, 0, 0, 0);
        func_021B78A0(q + off, 0, 0, 0, 0);
        *(int *)(p + off + 0x34) = 0;
        *(int *)(p + off + 0x38) = 1;
        *(int *)(p + off + 0x3C) = 1;
    }
    return p;
}



void func_021B70A8(int unused, char *q)
{
    int matrix[4];
    matrix[0] = func_0207C778(4096);
    matrix[3] = func_0207C778(4096);
    matrix[1] = 0;
    matrix[2] = 0;
    func_0207D59C((void *)0x04000030, matrix, 0, 0, 0, 0);
    func_020307B0(((struct Obj04550 *)q)->f4);
    func_020307B0(((struct Obj04550 *)q)->fC);
    func_020307B0(((struct Obj04550 *)q)->f8);
    if (func_021BE100() == 1) {
        func_020307B0(((struct Obj04550 *)q)->fB0);
        func_020307B0(((struct Obj04550 *)q)->fA8);
        func_020307B0(((struct Obj04550 *)q)->fAC);
        func_021B63B8(((struct Obj04550 *)q)->fA4);
        func_020306F0(110);
    }
    func_020307B0(q);
}



static inline void window0(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = ((x1 << 8) & 0xff00) | (x2 & 255);
    *(volatile u16 *)0x04000044 = ((y1 << 8) & 0xff00) | (y2 & 255);
}



static inline void window1(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000042 = ((x1 << 8) & 0xff00) | (x2 & 255);
    *(volatile u16 *)0x04000046 = ((y1 << 8) & 0xff00) | (y2 & 255);
}



/*
 * volatile: Window register writes at 0x021B71A2, 0x021B71A6, 0x021B71AC, 0x021B71AE.
 */
void func_021B712C(int unused, char *q)
{
    u8 i;
    if (((struct Obj03852 *)q)->f14 == 0) {
        for (i = 0; i < 4; i++) {
            if (func_021B78B8(q, q + 0x34 + i * 28) == 1) {
                ((struct Obj03852 *)q)->f10 |= (u8)(1 << i);
                break;
            }
        }
    }
    if (func_021BE100() == 1) func_021B64AC(((struct Obj03852 *)q)->fA4);
    if (((struct Obj03852 *)q)->f2D < 0xc0 && ((struct Obj03852 *)q)->f30 == 0) {
        ((struct Obj03852 *)q)->f2D += 8;
        window0(0, 0, 255, ((struct Obj03852 *)q)->f2D);
        window1(128, 0, 0, ((struct Obj03852 *)q)->f2D);
    }
}




void func_021B71B8(void *p, Q *q)
{
    int sub;
    u32 wide;
    u32 base;
    u32 dst;
    int h;
    int bit;
    u8 i;
    int m[4];

    sub = func_021BE05C(p);
    wide = func_021BE078(p);
    base = func_021BDFE4(p);
    if (func_021BE054(p) < 2)
        return;
    if (sub == 0) {
        if (q->f10 != 0) {
            func_020862F0((u16 *)q->f4, 0x18000);
            func_0207ECF0(q->f4, 0, 0x18000);
            q->f10 = 0;
        }
    } else {
        if (q->f14 == 1) {
            u8 n = 0;
            for (i = 0; i < 4; i++) {
                if ((1 << i) & q->f10)
                    n++;
            }
            if (n != func_021BE054(p))
                return;
            if (q->f2c < 2) {
                q->f10 = 0;
                q->f2c++;
                for (i = 0; i < 4; i++) {
                    if (func_021B8B8C((int)p, (char *)base, i) == 1 && func_021B8BAC(p, (char *)base, i) == 0)
                        q->f10 |= (u8)(1 << i);
                }
                return;
            }
            if (q->f2d < 0xC0)
                return;
            if (q->f18 == 1) {
                q->f2d = 0;
                q->f30 = 1;
                q->f18 = 0;
                *(volatile u16 *)0x04000040 = 0xFF;
                *(volatile u16 *)0x04000044 = 0;
                *(volatile u16 *)0x04000042 = 0x8000;
                *(volatile u16 *)0x04000046 = 0;
            }
            if (q->f1c == 1) {
                q->f1c = 0;
                func_021BE1E4(p);
            }
            func_02082A7C(0, func_0207E100(), 0x18000);
            q->f14 = 0;
            if (q->f20 != func_021BE078(p)) {
                q->f20 = func_021BE078(p);
                if (q->f20 == 1) {
                    m[0] = func_0207C778(0x2000);
                    m[3] = func_0207C778(0x2000);
                } else {
                    m[0] = func_0207C778(0x1000);
                    m[3] = func_0207C778(0x1000);
                }
                m[1] = 0;
                m[2] = 0;
                func_0207D59C((void *)0x04000030, m, 0, 0, 0, 0);
                for (i = 0; i < 4; i++) {
                    if (q->f20 == 1) {
                        *(u16 *)((u8 *)q + 0x48 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x48 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4A + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4A + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4C + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4C + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4E + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4E + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x40 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x40 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x42 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x42 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x44 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x44 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x46 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x46 + i * 0x1C) >> 1;
                    } else {
                        q->ent[i].a <<= 1;
                        q->ent[i].b <<= 1;
                        q->ent[i].c <<= 1;
                        q->ent[i].d <<= 1;
                        q->ent[i].x <<= 1;
                        q->ent[i].y <<= 1;
                        q->ent[i].w <<= 1;
                        q->ent[i].h <<= 1;
                    }
                }
            }
            q->f30 = 0;
        }
        for (i = 0; i < 4; i++) {
            bit = 1 << i;
            if (!(bit & q->f10))
                continue;
            if (func_021B8B8C((int)p, (char *)base, i) == 1) {
                u32 idx = i;
                int w;
                            int j;
                if (sub == 1 && idx != 0)
                    idx = 1;
                if (wide == 0) {
                    w = 0x80;
                    h = (u16)(sub == 1 ? 0xC0 : 0x60);
                } else {
                    w = 0x40;
                    h = (u16)(sub == 1 ? 0x60 : 0x30);
                }
                if (func_021B8BAC(p, (char *)base, i) == 1 && func_0202EB14() == 0) {
                    dst = (u32)(q->f4 + idx * (w * h * 2));
                    func_020862F0((void *)dst, w * h * 2);
                } else if (wide == 0) {
                    if (sub == 1) {
                        dst = (u32)q->f8;
                        func_020862F0((void *)dst, 0xC000);
                    } else {
                        dst = (u32)(q->f8 + 0x3000);
                        func_020862F0((void *)dst, 0x6000);
                    }
                } else {
                    if (sub == 1) {
                        dst = (u32)q->fC;
                        func_020862F0((void *)dst, 0x3000);
                    } else {
                        dst = (u32)(q->fC + 0xC00);
                        func_020862F0((void *)dst, 0x1800);
                    }
                }
                for (j = 0; j < q->ent[i].h; j++) {
                    int r = j + (h - q->ent[i].h);
                    func_0207ECF0((void *)((w - q->ent[i].w) * 2 + (dst + r * w * 2)),
                                  q->ent[i].x * 2 + (j + q->ent[i].y) * 0x200,
                                  q->ent[i].w * 2);
                }
            }
            q->f10 -= (u8)bit;
        }
    }
}




/*
 * Guarded call to func_021B6868.
 *
 * Addresses are Black-image addresses.
 */
void func_021B7578(int x, char *p)
{
    if (func_021BE100() == 1) {
        func_021B6868(((struct Obj06558 *)p)->fA4);
    }
}




int func_021B7590(int x, char *p)
{
    if (func_021BE100() == 1) {
        return func_021B688C(((struct Obj02992 *)p)->fA4);
    }
    return 1;
}



void func_021B75AC(char *src, void *p)
{
    char *base;
    int sub;
    u32 wide;
    int x;
    u32 me;
    u32 n;
    u16 y;
    int w;
    u16 h;
    int i;
    base = (char *)func_021BDFDC(p);
    sub = func_021BE05C(p);
    wide = func_021BE078(p);
    me = func_021BE0A4(p);
    if (func_021BE0AC(p) == 1 || func_021BE054(p) < 2)
        return;
    if (((struct Obj06552 *)base)->f10 & (1 << me))
        return;
    if (func_021BE0B4(p) == 0) {
        for (i = 0; i < 0xc0; i++)
            MIi_CpuCopy32(src + i * 0x200 + 0x80, *(char * *)&((struct Obj06552 *)base)->fB0 + i * 0x100, 0x100);
    }
    if (sub == 0) {
        func_02034714(d_021C71F0, 0, d_021C71F0);
        return;
    }
    n = me;
    if (sub == 1 && me > 1)
        n = 1;
    if (wide == 0) {
        x = 0;
        y = (sub == 1) ? 0 : 0x30;
        w = 0x80;
        h = (sub == 1) ? 0xc0 : 0x60;
    } else {
        x = 0x20;
        y = (sub == 1) ? 0x30 : 0x50;
        w = 0x40;
        h = (sub == 1) ? 0x60 : 0x30;
    }
    if (func_021BE0F8(p) != 0)
        return;
    func_021BE0FC(p, 1);
    for (i = 0; i < h; i++)
        MIi_CpuCopy32((void *)(*(u32 *)&((struct Obj06552 *)base)->fB0 + (y + i) * 0x100 + x * 2),
                      (void *)(((struct Obj06552 *)base)->f4 + w * h * 2 * n + w * i * 2), w * 2);
    func_021BE0FC(p, 0);
    ((struct Obj06552 *)base)->f10 |= (u8)(1 << me);
}



void func_021B7714(void *a, char *b, int c)
{
    ((struct Obj24069 *)b)->f10 |= (u8)(1 << c);
}



void func_021B7724(void *a, char *b, int c)
{
    int m;
    if (((struct Obj06553 *)b)->f14 == 0) {
        m = 1 << c;
        if (((struct Obj06553 *)b)->f10 & m)
            ((struct Obj06553 *)b)->f10 -= (u8)m;
    }
}



void func_021B7740(void *p, char *q, int a, int b)
{
    char *base;
    u8 i;
    base = (char *)func_021BDFE4(p);
    ((struct Obj00415 *)q)->f14 = 1;
    if (((struct Obj00415 *)q)->f18 == 0) ((struct Obj00415 *)q)->f18 = a;
    if (((struct Obj00415 *)q)->f1C == 0) ((struct Obj00415 *)q)->f1C = b;
    ((struct Obj00415 *)q)->f10 = 0;
    ((struct Obj00415 *)q)->f2C = 0;
    if (func_021BE100() == 0)
        ((struct Obj00415 *)q)->f10 |= (u8)(1 << func_021BE0A4(p));
    for (i = 0; i < 4; i++) {
        if (func_021B8BA4((int)p, base, i) == 1)
            func_021B796C(p, q, i);
    }
}




/*
 * Field getter, u32 at +0x14 of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B77B4(int unused, void *p)
{
    return ((struct Obj24070 *)p)->f14;
}




/*
 * Table lookup at g_021C6E9C; the second arm keeps the low 16 bits of the halved word.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B77B8(void *p)
{
    u32 i = func_021BE05C(p);

    if (func_021BE078(p) == 0)
        return (u16)g_021C6E9C[i];
    return (g_021C6E9C[i] << 15) >> 16;
}
