/*
 * file:     field_msgbg_p77.c
 * unit:     yes
 * function: func_02192264, func_021922A4, func_021924F0, func_02192570, func_02192628, func_0219269C, func_021926D8, func_0219270C, func_0219272C, func_02192788, func_021927B0, func_021927C0, func_021927E8, func_021927F8, func_021927FC
 * address:  0x02192264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_020437D4  0x020437D4  arm  arm9
 *   func_0204A1BC  0x0204A1BC  arm  arm9
 *   func_02062A4C  0x02062A4C  arm  arm9
 *   func_02082EA4  0x02082EA4  arm  arm9
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043678  0x02043678  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0201DC80  0x0201DC80  thumb
 *   func_020458F8  0x020458F8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   d_021DDA50     0x021DDA50  data  a4
 *   func_02030734  0x02030734  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02192244  0x02192244  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_02193044  0x02193044  thumb  ov021
 *   func_020456F8  0x020456F8  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02041300  0x02041300  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   func_021928F8  0x021928F8  thumb  ov021
 *   func_0201D304  0x0201D304  thumb  arm9
 *   func_0201D42C  0x0201D42C  thumb
 *   func_02045874  0x02045874  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020436FC  0x020436FC  arm  arm9
 *   func_02082BCC  0x02082BCC  arm  arm9
 *   func_02043AF4  0x02043AF4  arm  arm9
 *   d_021D3E50     0x021D3E50  data   ov021  a1
 */
#include "../../matched/include/Obj12612.h"
#include "../../matched/include/Obj00126.h"
#include "../../matched/include/Obj19604.h"
#include "../../matched/include/Obj12068.h"
#include "../../matched/include/Obj17936.h"

struct Bmp;
struct NitroFileHeader;
struct Obj020437AC;
struct Font;
struct StrObj;
struct U16Vec;
struct Cfg;
struct Descriptor;
struct Fx;
struct G;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02192264;

typedef struct CharData {
    u8  pad[0x14];
    u8 *raw;
} CharData;

typedef signed int     s32;

typedef signed short   s16_021924F0;

typedef short          s16_0219269C;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u32 f08;
} Fx;

typedef struct T {
    u32 f00;
    u32 f04;
    Fx *f08;
} T;

typedef short          s16_021926D8;

typedef struct U {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 sub[2];
} U;

typedef short          s16_0219270C;

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

typedef short          s16_02192788;

typedef struct G {
    u32 f00;
    u32 f04;
} G;

typedef short          s16_021927C0;

typedef short          s16_021927FC;

typedef struct Cur {
    u8 f00;
    u8 f01;
    u8 f02;
} Cur;

typedef struct Tri {
    u16 v[3];
} Tri;

extern void *func_020437D4(const struct Bmp *bmp);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_02082EA4(void *dst, void *src, u32 n);
extern u32 func_020307B0(void *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_0201DC80(struct Font *p);
extern u16 func_020458F8(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void func_0201C7A4(void *x, s16_021924F0 y, s16_021924F0 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *w);
extern void func_02192244(u32 a, u32 b, u32 c);
extern void func_020409B4(u32 layer);
extern void func_02193044(u32 a);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_021928F8(u8 *a, u32 b, u32 c);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void ENV_SetResourceSet(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void func_02192264(u32 a, u32 unused, u32 heap, u32 idx);
void func_021922A4(u32 bmp, u32 b, u32 heap);
void func_021924F0(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f);
u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
void func_02192628(u32 *a);
void func_0219269C(T *t, u16 b, u16 c, u32 d);
int func_021926D8(U *u);
u32 func_0219270C(Q *q, int a, int n);
u32 func_0219272C(u16 *a, u32 b, u32 c);
G *func_02192788(Fx *a);
void func_021927B0(u8 *p);
void func_021927C0(G *g, Fx *a);
void func_021927E8(u32 *p);
u8 func_021927F8(u8 *p);
void func_021927FC(Cur *c, u32 win, u32 col);
extern char d_021DDA50[];
extern const Tri d_021D3E50;


/*
 * Addresses are Black-image addresses.
 */
void func_02192264(u32 a, u32 unused, u32 heap, u32 idx)
{
    enum { Z } i = Z;
    u8 *src;
    void *buf;
    CharData *cd;

    src = func_020437D4((const struct Bmp *)a);
    buf = (void *)func_0204A1BC(5, 8, 0, heap);
    func_02062A4C(buf, (void **)(&cd));
    func_02082EA4(cd->raw + i * 32 + idx * 32, src, 0x20);
    func_020307B0(buf);
}


static inline void blit(u32 tmp, u32 bmp, u16 x, u16 y)
{
    func_020439A0((struct Bmp *)tmp, (struct Bmp *)bmp, 0, 0, x * 8, y * 8, 8, 8, 0xFFFF);
}


/*
 * Nine-slice frame: loads each frame tile into an 8x8 scratch bitmap with
 * func_02192264 and blits it over the centre, the four edges and the four
 * corners of the target bitmap.
 *
 * Addresses are Black-image addresses.
 *
 * The edge loops use u16 locals truncated at their definition from the
 * CSE'd int w-1 / h-1 (spilled); the corners reuse the loop counters i
 * and j as the x/y tile positions, assigned before each tile load, so the
 * u16 truncation is scheduled ahead of the func_02192264 call.
 */
void func_021922A4(u32 bmp, u32 b, u32 heap)
{
    u16 w;
    u16 j;
    u16 h;
    u16 i;
    u32 tmp;
    u16 hm1;
    u16 wm1;

    w = func_020437DC((const struct Bmp *)bmp) >> 3;
    h = func_020437E4((const struct Bmp *)bmp) >> 3;
    tmp = (u32)func_02043678(1, 1, 0x20, heap);

    func_02192264(tmp, b, heap, 9);
    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
            blit(tmp, bmp, i, j);

    func_02192264(tmp, b, heap, 1);
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, 0);

    func_02192264(tmp, b, heap, 0x11);
    hm1 = h - 1;
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, hm1);

    func_02192264(tmp, b, heap, 8);
    for (i = 0; i < h; i++)
        blit(tmp, bmp, 0, i);

    func_02192264(tmp, b, heap, 0xA);
    wm1 = w - 1;
    for (i = 0; i < h; i++)
        blit(tmp, bmp, wm1, i);

    func_02192264(tmp, b, heap, 0);
    blit(tmp, bmp, 0, 0);
    i = w - 1;
    func_02192264(tmp, b, heap, 2);
    blit(tmp, bmp, i, 0);
    i = h - 1;
    func_02192264(tmp, b, heap, 0x10);
    blit(tmp, bmp, 0, i);
    i = w - 1;
    j = h - 1;
    func_02192264(tmp, b, heap, 0x12);
    blit(tmp, bmp, i, j);

    func_020437AC((struct Obj020437AC *)tmp);
}


void func_021924F0(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f)
{
    int i;
    u32 h;
    int t;

    t = func_0201DC80((struct Font *)d) + 2;
    h = (u32)func_020457B0(func_020458F8((struct U16Vec *)e) + 1, f);
    for (i = 0; func_0201D37C((struct StrObj *)e, (struct StrObj *)h, i) == 1; i++) {
        func_0201C7A4((void *)c, (s16_021924F0)a, (s16_021924F0)b, (void *)h, (void *)d);
        b += (u16)t;
    }
    func_02045808((struct U16Vec *)h);
}


u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f)
{
    u32 *t;

    t = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0x115D);
    t[2] = (u32)a;
    t[0] = func_020450F0((u8)a[1], (u8)c, (u8)d, (u8)e, (u8)f, 9, 1);
    t[3] = (u32)func_02043678(1, 1, 0x20, *a);
    func_02192264(t[3], b, *a, 9);
    func_021922A4((u32)func_02045770((struct Descriptor *)t[0]), b, *a);
    func_02192244(a[1], 9, *a);
    func_02045374((struct Cfg *)t[0]);
    func_02045334((struct Descriptor *)t[0]);
    func_020409B4((u8)a[1]);
    func_021927C0((struct G *)(t + 4), (struct Fx *)a);
    a[3] = 0xB;
    func_02193044(0);
    return t;
}


void func_02192628(u32 *a)
{
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    func_020456F8((struct Descriptor *)a[0]);
    x = func_02045758((struct Descriptor *)a[0]);
    y = func_02045760((struct Descriptor *)a[0]);
    w = func_02045738((struct Descriptor *)a[0]);
    h = func_02045740((struct Descriptor *)a[0]);
    func_02041300((u8)((u16 *)a[2])[1], 0, x, y, w, h, 0x11);
    func_02045334((struct Descriptor *)a[0]);
    func_020409B4((u8)((u16 *)a[2])[1]);
    func_021927E8(a + 4);
    func_020437AC((struct Obj020437AC *)a[3]);
    func_020452E8((struct Descriptor *)a[0]);
    func_020307B0(a);
}


void func_0219269C(T *t, u16 b, u16 c, u32 d)
{
    Fx *x = t->f08;

    func_021924F0(b, c, (u32)func_02045770((struct Descriptor *)t->f00), x->f08, d, x->f00);
    func_02045334((struct Descriptor *)t->f00);
    func_020409B4((u8)t->f08->f02);
}


int func_021926D8(U *u)
{
    u32 v = func_020362DC();
    func_0203630C();
    if (v & 3)
        return 1;
    func_021928F8((u8 *)u->sub, (u32)func_02045770((struct Descriptor *)u->f00), u->f0c);
    func_02045334((struct Descriptor *)u->f00);
    return 0;
}


u32 func_0219270C(Q *q, int a, int n)
{
    u32 x;
    u32 r;

    x = n * 2 + func_0201D304((struct StrObj *)a, (int)q->f08, 0);
    r = x >> 3;
    if (x & 7)
        r++;
    return r;
}


u32 func_0219272C(u16 *a, u32 b, u32 c)
{
    u32 n;
    u32 h;
    u32 i;

    n = c * 2 + func_0201D42C((struct StrObj *)b, (void *)(((struct Obj12612 *)a)->f8));
    h = (u32)func_02045874((struct U16Vec *)b, *a);
    i = 0;
    if (func_0201D37C((struct StrObj *)b, (struct StrObj *)h, 0) == 1) {
        while (++i < 0x18 && func_0201D37C((struct StrObj *)b, (struct StrObj *)h, i) == 1)
            ;
    }
    func_02045808((struct U16Vec *)h);
    n += (i - 1) * 2;
    if (n & 7)
        n += 8;
    return n >> 3;
}


G *func_02192788(Fx *a)
{
    G *g = func_02030734(a->f00, 8, 1, d_021DDA50, 0x1202);
    func_021927C0(g, a);
    return g;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021927B0(u8 *p)
{
    func_021927E8((u32 *)p);
    ENV_SetResourceSet(p);
}


void func_021927C0(G *g, Fx *a)
{
    func_02082BCC(g, 0, 8);
    g->f04 = (u32)func_020436FC((void *)(((struct Obj19604 *)(*(u8 * *)&((struct Obj00126 *)a)->f178))->f14), 1, 1, 0x20, a->f00);
}


/*
 * Clears the leading byte and tail calls on the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021927E8(u32 *p)
{
    ((struct Obj12068 *)p)->f0 = 0;
    func_020437AC((struct Obj020437AC *)p[1]);
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021927F8(u8 *p)
{
    return ((struct Obj17936 *)p)->f0;
}


void func_021927FC(Cur *c, u32 win, u32 col)
{
    Tri t = d_021D3E50;
    u16 x;
    u16 y;

    x = func_020437DC((const struct Bmp *)win) - 8;
    y = func_020437E4((const struct Bmp *)win) - 8 - t.v[c->f01];
    func_02043AF4((struct Bmp *)win, (s16_021927FC)x, (s16_021927FC)y, (u16)8, (u16)8, (u8)col);
    c->f00 = 0;
}
