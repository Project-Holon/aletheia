/*
 * file:     unit_021F5620.c
 * unit:     yes
 * function: func_021F5620, func_021F565C, func_021F5698, func_021F5748, func_021F57D4, func_021F5800, func_021F5950
 * address:  0x021F5620
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F5BC8 0x021F5BC8 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF59C 0x021CF59C thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   d_021F5BBC 0x021F5BBC data a4
 *   func_021F529C 0x021F529C thumb ov075
 *   func_021F5AFC 0x021F5AFC thumb ov078
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021CF51C 0x021CF51C thumb ov021
 *   func_0207DD24 0x0207DD24 arm
 *   func_021F52D8 0x021F52D8 thumb ov075
 *   d_021F5BB0     0x021F5BB0  data  a4
 *   d_021F5BD4     0x021F5BD4  data  a4
 */
#include "../../matched/include/Obj03670.h"
#include "../../matched/include/Obj03671.h"

#define REG_MTX_PUSH       (*(vu32 *)0x04000444)
#define REG_MTX_POP        (*(vu32 *)0x04000448)
#define REG_MTX_SCALE      (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS      (*(vu32 *)0x04000470)
#define REG_NORMAL         (*(vu32 *)0x04000484)
#define REG_TEXCOORD       (*(vu32 *)0x04000488)
#define REG_VTX_16         (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR   (*(vu32 *)0x040004A4)
#define REG_DIF_AMB        (*(vu32 *)0x040004C0)
#define REG_SPE_EMI        (*(vu32 *)0x040004C4)
#define REG_LIGHT_COLOR    (*(vu32 *)0x040004CC)
#define REG_BEGIN_VTXS     (*(vu32 *)0x04000500)
#define REG_END_VTXS       (*(vu32 *)0x04000504)
struct Res021CF;
struct Vec;
struct Ctx;
struct Desc;
struct Obj;
typedef struct { int x,y,z; } Vec;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef short s16;

typedef signed int     s32;

typedef unsigned short u16;

typedef signed short s16_021F5800;

typedef s32 fx32;

typedef s16_021F5800 fx16;

typedef volatile u32 vu32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx16 x, y, z;
} VecFx16_021F5800;

typedef short s16_021F5950;

typedef struct {
    s16_021F5950 x, y, z;
} VecFx16_021F5950;

typedef struct {
    VecFx16_021F5950 v[825];
    s16_021F5950 vel[825];
    s16_021F5950 wait;
    s16_021F5950 count;
    u16 period;
    u16 next;
    int height;
} Grid;

extern int func_02189A08(unsigned char *p);
extern void func_021CF59C(struct Res021CF *r);
extern void *func_021F5260(void *a, struct Vec *src, u32 b, u32 c);
extern void *func_021F529C(void *a, struct Vec *src, u32 b, u32 c);
extern void *func_021F5AFC(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern u32 func_021CF560(u32 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_021CF51C(u32 *p);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_021F52D8(u32 *);
void *func_021F5620(void *p, int b);
void *func_021F565C(void *p, int b);
void *func_021F5698(void *a);
int func_021F5748(void *task, int *st);
void func_021F57D4(void *p);
void func_021F5800(VecFx16_021F5800 *w);
int func_021F5950(Grid *w);
extern const Vec d_021F5BC8;
extern const Vec d_021F5BBC;
extern const VecFx32 d_021F5BB0;
extern const VecFx32 d_021F5BD4;



void *func_021F5620(void *p, int b) {
    Vec v = d_021F5BC8;
    func_021CF59C((void *)func_02189A08((unsigned char *)b));
    return func_021F5260(p, (struct Vec *)(&v), (u32)func_021F5698, (u32)func_021F5800);
}



/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov021 callee 021CF59C (12-byte thunk, no label) is unresolved. Nothing to change in the source.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF59C (no label witness). It is a 12-byte ARM-style thunk inside the ov021_func_021CF580 extent (ldr r1,[pc]; ldr r3,[pc]; bx r3 with r1 = 0x4B, target func_021CF564): veneer-like, not C. Needs a label in layout.
 */
void *func_021F565C(void *p, int b) {
    Vec v = d_021F5BBC;
    func_021CF59C((void *)func_02189A08((unsigned char *)b));
    return func_021F529C(p, (struct Vec *)(&v), (u32)func_021F5AFC, (u32)func_021F5800);
}




/*
 * Addresses are Black-image addresses.
 */
void *func_021F5698(void *a)
{
    u8 *w;
    void *h;
    int i;

    w = (u8 *)func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(a))), 0x19E0, 0x50);
    h = func_020122C0(a, 0, (void (*)(void))func_021F5748, 0);
    ((struct Obj03670 *)w)->f19CA = 7;
    ((struct Obj03670 *)w)->f19C8 = 0;
    ((struct Obj03670 *)w)->f19CC = 8;
    ((struct Obj03670 *)w)->f19D0 = 0x400;
    ((struct Obj03670 *)w)->f19CE = 0;
    ((struct Obj03670 *)w)->f19D8 = 0x32;
    ((struct Obj03670 *)w)->f19DC = 0;
    for (i = 0; i < 0x339; i++) {
        s16 *e = (s16 *)(w + i * 6);

        e[0] = ((i % 33) << 12) / 16;
        e[1] = ((i / 33) << 12) / 16;
        e[2] = 0;
    }
    ((struct Obj03670 *)w)->f19D4 = 0xc;
    return h;
}




int func_021F5748(void *task, int *st)
{
    u8 *w;

    w = (u8 *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(func_020124E4(task)))));
    switch (*st) {
    case 0:
        if (((struct Obj03671 *)w)->f19D8 != 0) {
            (((struct Obj03671 *)w)->f19D8)--;
        } else if (((struct Obj03671 *)w)->f19DC == 0) {
            func_0204E720(((struct Obj03671 *)w)->f19D4, 0, 0x10, 0);
            ((struct Obj03671 *)w)->f19DC = 1;
        }
        if (func_021F5950((Grid *)w) != 0) {
            ((struct Obj03671 *)w)->f19C8 = 6;
            (*st)++;
        }
        break;
    case 1:
        if (((struct Obj03671 *)w)->f19C8 != 0) {
            (((struct Obj03671 *)w)->f19C8)--;
        } else if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF51C (no label witness). Filed src/matched/ov/ov021_func_021CF51C.c (EXACT, 4-byte accessor); it needs a manifest shard to count as a witness.
 */
void func_021F57D4(void *p) {
    u32 h = func_021CF51C(p);
    func_0207DD24(0x4210,31,0x7FFF,0,0);
    func_021F52D8((u32 *)h);
}



static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}



static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}



static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16_021F5800)(s >> 8) | ((u32)(u16)(s16_021F5800)(t >> 8) << 16);
}



static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}



/*
 * volatile: G3 geometry FIFO registers 0x04000444-0x04000504, written by the SDK inlines (stores only)
 *
 * Draws the 33 x 25 vertex grid func_021F5698 / func_021F5AFC build as
 * quad strips.
 * Levers: the six vertex fields are loaded into locals before the stores
 * (inline loads give an 0x30 frame); j declared before the row pointer
 * (slot order); the element pointer is spelled `w + j * 33 + i` with no
 * row local, so the scaled row base is hoisted and `i = 0` lands last in
 * the preheader (a row local or `&w[j * 33 + i]` schedules it early or
 * hoists j * 33 unscaled).
 *
 * Addresses are Black-image addresses.
 */
void func_021F5800(VecFx16_021F5800 *w)
{
    VecFx32 trans;
    VecFx32 scale;
    int j;
    int i;
    VecFx16_021F5800 *v;
    fx32 t;
    fx16 x0, x1, y0, y1, z0, z1;

    j = 0;
    REG_MTX_PUSH = j;
    REG_DIF_AMB = 0x7FFF7FFF;
    REG_SPE_EMI = 0x4210;
    REG_LIGHT_COLOR = 0x7FFF;
    REG_POLYGON_ATTR = 0x001F00C1;
    trans = d_021F5BB0;
    scale = d_021F5BD4;
    G3_Translate(trans.x, trans.y, trans.z);
    G3_Scale(scale.x, scale.y, scale.z);
    for (; j < 0x18; j++) {
        REG_BEGIN_VTXS = 3;
        t = j << 15;
        for (i = 0; i < 33; i++) {
            v = w + j * 33 + i;
            x0 = v[0].x;
            x1 = v[33].x;
            y0 = v[0].y;
            y1 = v[33].y;
            z0 = v[0].z;
            z1 = v[33].z;
            REG_NORMAL = 0x20000000;
            G3_TexCoord(i << 15, t);
            G3_Vtx(x0, -y0, z0);
            G3_TexCoord(i << 15, t + 0x8000);
            G3_Vtx(x1, -y1, z1);
        }
        REG_END_VTXS = 0;
    }
    REG_MTX_POP = 1;
}



/*
 * One step of the ripple over the 33 x 25 grid func_021F5698 /
 * func_021F5AFC allocate (0x19E0 bytes); the vertex list is drawn by
 * func_021F5800.
 * Levers: period/next are u16 (ldrh); each neighbour coordinate is a
 * temporary (x = col - 1, ...) so the +-1 is not folded into the load
 * offset; the element pointer p is a named local declared before col/row
 * (without it row takes r0 and the quotient is never moved to r1).
 *
 * Addresses are Black-image addresses.
 */
int func_021F5950(Grid *w)
{
    s16_021F5950 z[825];
    int i;
    VecFx16_021F5950 *p;
    int col;
    int row;
    int a;
    int b;
    int c;
    int d;
    int x;
    int y;
    s16_021F5950 diff;

    for (i = 0; i < 825; i++)
        z[i] = w->v[i].z;
    if (w->count > 0) {
        if (w->wait == 0) {
            w->v[412].z = w->height;
            w->wait = w->period;
            w->count--;
        } else {
            w->wait--;
        }
        if (w->count <= 0) {
            if (w->next == 0) {
                w->wait = 6;
                return 1;
            }
            w->wait = w->next;
        }
    } else {
        w->wait--;
        if (w->wait <= 0) {
            w->wait = 6;
            return 1;
        }
    }
    for (i = 0; i < 825; i++) {
        col = i % 33;
        row = i / 33;
        x = col - 1;
        a = (x >= 0) ? z[x + row * 33] : 0;
        x = col + 1;
        b = (x < 33) ? z[x + row * 33] : 0;
        y = row - 1;
        c = (y >= 0) ? z[col + y * 33] : 0;
        y = row + 1;
        d = (y < 25) ? z[col + y * 33] : 0;
        p = &w->v[i];
        diff = (a + b + c + d) / 4 - p->z;
        w->vel[i] += diff;
        p->z += w->vel[i];
        if (p->z > 0x1000)
            p->z = 0x1000;
        if (p->z < -0x1000)
            p->z = -0x1000;
        if (col == 0 || col == 32 || row == 0 || row == 24)
            p->z = 0;
    }
    return 0;
}
