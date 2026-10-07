/*
 * file:     fld3d_ci_p06.c
 * unit:     yes
 * function: func_021C2484, func_021C24A8, func_021C24BC, func_021C24F0, func_021C2734
 * address:  0x021C2484
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
 *   func_020480E4  0x020480E4  arm
 *   func_021C1A84  0x021C1A84  thumb  ov021
 *   func_020515CC  0x020515CC  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 */
#include "../../matched/include/Obj07228.h"
#include "../../matched/include/Obj20162.h"

struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int f0;
    Vec v;
} Inner;

typedef struct {
    char pad0[0x20];
    Inner **f20;
    int f24;
    Vec f28;
} Obj;

typedef struct {
    u32 w0;
    u16 h4;
    u16 h6;
    u16 a[2];
    u16 hc;
    u16 he;
    u16 b[4];
    u16 c[4];
    u32 w20;
} Src;

typedef struct {
    u32 kind;
    u16 id;
    u32 val;
} E0;

typedef struct {
    u16 idx;
    u16 zero;
} E2;

typedef struct {
    u16 idx;
    u16 zero;
    u16 idx2;
    E2 *list;
    u16 cnt;
} E1;

typedef struct {
    E0 *e0;
    E1 *e1;
    E2 *e2;
    E2 *e3;
    E0 *p10;
    u16 n10;
    E1 *p18;
    u16 n1c;
    u16 pad1e;
    u16 h20;
    u16 h22;
    u16 h24;
    u16 h26;
    u32 w28;
    u8 total;
    u8 na;
    u8 nb;
    u8 nc;
    u32 w30;
} Out;

extern void func_020480E4(struct Ctx *c, u32 i);
extern u32 func_021C1A84(u32);
int func_020515CC(int *p, int a, int b, int c);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
int func_021C2484(u8 *a, u8 *b);
void func_021C24A8(char *p, int k);
void func_021C24BC(Obj *p);
void func_021C24F0(Out *out, u32 b, u32 heap);
void func_021C2734(void **p);
extern u8 d_021DE3D8;


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2484(u8 *a, u8 *b)
{
func_021C2734((void **)b);
func_020480E4((struct Ctx *)(((struct Obj07228 *)((u8 *)(a)))->f14), ((((struct Obj07228 *)((u8 *)(a)))->f18 << 16) >> 16));
((struct Obj07228 *)((u8 *)(a)))->f18 = (~0);
return func_021C1A84(((struct Obj07228 *)((u8 *)(a)))->f0);
}


/*
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * func_021C24BC (ov021_func_021C24BC.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 */
void func_021C24A8(char *p, int k)
{
    func_020515CC((int *)(((struct Obj20162 *)p)->f58), k, (int)func_021C24BC, 0);
}


/*
 * Unlabelled thumb leaf (push {r4} only), reached through the pool word
 * 0x021C24BD in func_021C24A8. Char-pointer offsets give the same bytes
 * scheduled differently (34 differ); the struct-typed accesses keep the
 * zero-initialiser stores ahead of the loads, as in the original.
 * Addresses are Black-image addresses.
 */
void func_021C24BC(Obj *p)
{
    Vec o = { 0, 0, 0 };

    o.z = 0x40;
    p->f28.x = o.x + (*p->f20)->v.x;
    p->f28.y = o.y + (*p->f20)->v.y;
    p->f28.z = o.z + (*p->f20)->v.z;
}


void func_021C24F0(Out *out, u32 b, u32 heap)
{
    Src s;
    u16 ids[8];
    u8 na, nb, nc, total, baseb, basec;
    u8 i, j, n;

    func_02048F4C(&s, 0x75, b);
    na = 0;
    for (i = 0; i < 2; i++) {
        if (s.a[i] != 0xFFFF) {
            na++;
        }
    }
    nc = 0;
    nb = 0;
    for (i = 0; i < 4; i++) {
        if (s.b[i] != 0xFFFF) {
            nb++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (s.c[i] != 0xFFFF) {
            nc++;
        }
    }
    baseb = 0 + na;
    basec = baseb + nb;
    total = na + nb + nc;
    if (total != 0) {
        out->e0 = func_02030734(heap, total * 12, 1, (const char *)&d_021DE3D8, 0x566);
    }
    if (na != 0) {
        out->e1 = func_02030734(heap, na * 16, 1, (const char *)&d_021DE3D8, 0x56a);
    }
    if (nb != 0) {
        out->e2 = func_02030734(heap, nb * 4, 1, (const char *)&d_021DE3D8, 0x56e);
    }
    if (nc != 0) {
        out->e3 = func_02030734(heap, nc * 4, 1, (const char *)&d_021DE3D8, 0x572);
    }
    out->total = total;
    out->na = na;
    out->nb = nb;
    out->nc = nc;
    out->h20 = s.h4;
    out->h22 = s.h6;
    out->h24 = s.hc;
    out->h26 = s.he;
    ids[0] = s.a[0];
    ids[1] = s.a[1];
    ids[2] = s.b[0];
    ids[3] = s.b[1];
    ids[4] = s.b[2];
    ids[5] = s.c[0];
    ids[6] = s.c[1];
    ids[7] = s.c[2];
    n = 0;
    for (j = 0; j < 8; j++) {
        if (ids[j] != 0xFFFF) {
            out->e0[n].kind = 0x73;
            out->e0[n].id = ids[j];
            out->e0[n].val = 0;
            n++;
        }
    }
    for (i = 0; i < nb; i++) {
        out->e2[i].idx = baseb + i;
        out->e2[i].zero = 0;
    }
    for (i = 0; i < nc; i++) {
        out->e3[i].idx = basec + i;
        out->e3[i].zero = 0;
    }
    for (i = 0; i < na; i++) {
        out->e1[i].idx = 0 + i;
        out->e1[i].zero = 0;
        out->e1[i].idx2 = 0 + i;
    }
    if (na >= 1) {
        out->e1[0].list = out->e2;
        out->e1[0].cnt = nb;
    }
    if (na >= 2) {
        out->e1[1].list = out->e3;
        out->e1[1].cnt = nc;
    }
    out->p10 = out->e0;
    out->n10 = total;
    out->n1c = na;
    out->p18 = out->e1;
    out->w28 = s.w0;
    out->w30 = s.w20;
}


/*
 * Frees the four optional buffers (EXACT*: trailing pad).
 */
void func_021C2734(void **p)
{
    if (p[2] != 0)
        func_020307B0(p[2]);
    if (p[3] != 0)
        func_020307B0(p[3]);
    if (p[1] != 0)
        func_020307B0(p[1]);
    if (p[0] != 0)
        func_020307B0(p[0]);
}
