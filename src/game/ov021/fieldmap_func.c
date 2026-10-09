/*
 * file:     fieldmap_func.c
 * unit:     yes
 * function: func_021BB578, func_021BB5C8, func_021BB5DC, func_021BB608, func_021BB60C, func_021BB648, func_021BB68C, func_021BB778, func_021BB7B4, func_021BB808, func_021BB890, func_021BB90C, func_021BB948, func_021BB954, func_021BB960, func_021BB978, func_021BB990, func_021BBA1C, func_021BBA6C, func_021BBA70, func_021BBBD8, func_021BBC2C, func_021BBC58, func_021BBCBC, func_021BBCF8, func_021BBD0C, func_021BBD64, func_021BBD84
 * address:  0x021BB578
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
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A90     0x021D9A90  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D9AA4       0x021D9AA4  data  a4
 *   _fflt            0x0209BDBC  arm
 *   _fadd            0x0209C95C  arm
 *   _fsub            0x0209CB8C  arm
 *   _ffix            0x0209C494  arm
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_0206DB80    0x0206DB80  arm
 *   func_0207ADC4    0x0207ADC4  arm
 *   func_021AC1B8    0x021AC1B8  thumb  ov021
 *   func_02047AC8    0x02047AC8  arm
 *   g_02148B54       0x02148B54  data
 *   g_02148BCC       0x02148BCC  data
 *   func_020061E4  0x020061E4  thumb
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02030D28  0x02030D28  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034714  0x02034714  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0201F41C  0x0201F41C  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D9AE0     0x021D9AE0  data  a4
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02188C88  0x02188C88  thumb  ov021
 *   d_021DE30C  0x021DE30C  data
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D9B0C     0x021D9B0C  data  a2
 *   d_021D9AE8     0x021D9AE8  data  a4
 */
#include "../../matched/include/Obj18172.h"
#include "../../matched/include/G_Glb.h"
#include "../../matched/include/Obj18174.h"
#include "../../matched/include/Obj18175.h"
#include "../../matched/include/Obj07223.h"
#include "../../matched/include/Obj07224.h"
#include "../../matched/include/Obj06051.h"
#include "../../matched/include/Obj20098.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Actor;
struct VecFx32;
struct Vec;
struct Arg_021BB60C;
struct Ctx;
struct Node;
struct Big;
struct BigObj;
struct L0200EDC4;
struct Sub0200852CObj;
struct BbActRec;
struct BbActSys;
struct X;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int w[7];
} Blk;

typedef struct {
    Blk b;
    char pad[0x10];
    int f2C;
} Out;

typedef struct { u32 f0, f4, f8, fC; u16 f10[10]; u32 f24; } X;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct { fx32 x, y, z; } V3;

typedef struct Node {
    V3 pos;
    V3 scale;
    u8 mtx[0x24];
} Node;

typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

typedef struct {
    u8 pad0[0x24];
    u32 f24[4];
    u16 f34;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    Info *f8;
} Arg_021BB60C;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    char b[0x18];
} E18;

typedef struct {
    int f0;
    int f4;
    int n;
    E18 *arr;
    void *f10;
    void *f14;
} Obj;

typedef signed int     s32;

typedef struct Entry {
    u8 id[8];      /* 0x00 */
    u8 pad8[8];
    u16 v[4];      /* 0x10 */
    u16 h;         /* 0x18 */
    u8 key[6];     /* 0x1a */
    u8 flag;       /* 0x20 */
    u8 kind;       /* 0x21 */
    u8 rel;        /* 0x22 */
    u8 pad23;
} Entry;

typedef struct Ring {
    Entry e[30];
    u8 head;
    u8 tail;
    u8 pad2[2];
    int count;
    int mark;
} Ring;

typedef struct Src {
    u8 pad0[7];
    u8 kind : 3;   /* 0x07 */
    u8 flag : 1;
    u8 pad8[4];
    u8 id[8];      /* 0x0c */
    u8 pad14[8];
    u16 v[4];      /* 0x1c */
    u16 h;         /* 0x24 */
    u8 pad26[0x36];
    int x5c;       /* 0x5c */
    u8 pad60[4];
    u8 key[6];     /* 0x64 */
} Src;

typedef struct Sys {
    int a;
    u8 pad4[8];
    int c;
} Sys;

typedef struct Ctx {
    Sys *sys;
    u8 pad[0x30E0 - 4];
    Ring ring;
} Ctx;

typedef struct ActTbl {
    void *owner;
    void *res;
    u16 h8[0x1A];
    int f3c;
} ActTbl;

typedef struct Arg_021BBC58 { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg_021BBC58;

typedef struct Row { u8 b[4]; } Row;

int func_021ABEA0(u32 a, u32 b);
int func_0216E1A4(int a0, int a1);
u32 func_021ABE14(u8 *p);
void func_021ABFA8(int a, void *b, int c, int d, void *e, int f);
extern int func_021AC1E0(u32 a);
extern Blk *func_021AC1AC(int a);
extern void func_021AC178(int a);
extern int func_0216E1C4(int a0, int a1);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_021AC1CC(int a, int *b);
void func_021AC154(int a);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void func_0206A854(void);
extern void func_0206DB80(void);
extern void func_0207ADC4(void *mtx);
extern void func_021AC1B8(u32 a, Node *n);
extern int func_02047AC8(void *a0, struct Arg_021BB60C *a1);
void func_020061E4(u32 a);
void func_02048AE8(int a, int *out);
void func_02048B0C(int a, int *out);
void func_02048B30(int a, int *out);
void func_0207BCA0(int *a, int *b, int *c, int *d);
void func_02082B60(int *a, int *b);
void func_0207B0A4(int *a, int *b);
void func_0207B51C(int a, int *b, int c);
void *func_02188C58(void *p);
u32 func_0218EC2C(u8 *p);
void func_0207C9D0(Vec *a, Vec *b, Vec *c);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
u32 func_02030CB0(u32 idx);
struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern u32 func_020307B0(void *p);
extern void func_02030D28(struct Ctx *c);
int func_02034AC4(s32 handle);
int func_02030DA8(int a, void *fn, int *b, int c);
void func_02030EAC(struct Node *n);
void func_02034A5C(int a);
void func_02082BCC(void *p, int v, int n);
extern void func_02034714(const char *expr, u32 line, const char *file);
u32 func_020084F8(void *dst, u32 value, u32 size);
u8 func_02008550(const struct Sub0200852CObj *obj);
void func_0201F41C(const u16 *src, u16 *dst, u32 n);
void func_02087C6C(void *p);
void func_02082D44(const void *src, void *dst, int n);
void *func_020120F4(const struct Ctx *p);
u32 func_0201283C(const struct BigObj *p);
void *func_02012EBC(struct Big *p);
void *func_0200ED48(void *p);
int func_0217F894(void *p, char *q);
int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern u32 func_02188C88(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
void func_021BB578(int a, int b, int c, int d);
int func_021BB5C8(u32 a);
void func_021BB5DC(int a, Out *out);
void func_021BB608(void);
void func_021BB60C(u32 a, X *x);
void func_021BB648(int a, int *b);
void func_021BB68C(u32 a, Arg_021BB60C *b);
void func_021BB778(int n);
void func_021BB7B4(int a, int b, int c);
void func_021BB808(int *o, Vec *out);
int *func_021BB890(int a, int b, int n);
void func_021BB90C(Obj *p);
void func_021BB948(u8 *p);
void func_021BB954(u8 *p);
void func_021BB960(u32 a, u32 b, u32 c, u32 d);
void func_021BB978(u32 a, u32 b, u32 c, u32 d);
int *func_021BB990(int a, int *d, const int *c);
void func_021BBA1C(int *p);
u32 func_021BBA6C(const void *p);
void func_021BBA70(Ctx *ctx, Src *src, u16 *v, u8 kind);
Entry *func_021BBBD8(Ring *r);
Entry *func_021BBC2C(Ring *r, u32 i);
int func_021BBC58(Ring *r, const void *b, u16 c);
ActTbl *func_021BBCBC(void *owner, u32 heap);
void func_021BBCF8(u32 a, ActTbl *p);
void func_021BBD0C(ActTbl *p);
void func_021BBD64(ActTbl *p);
int func_021BBD84(int a, int n, int x, int y);
extern int d_021D9A90;
extern const Node d_021D9AA4;
extern MtxFx44 g_02148B54;
extern struct Glb g_02148BCC;
extern int d_021DE2F8;
extern char d_021D9AE0[];
extern const char d_021DE30C[];
extern u16 d_021D9B0C[];
extern Row d_021D9AE8[];




void func_021BB578(int a, int b, int c, int d)
{
    int s[7];

    s[0] = c;
    s[1] = d;
    s[2] = func_021ABEA0(a, 4);
    s[3] = b;
    func_0216E1A4(b, (int)(&s[4]));
    s[6] = func_021ABE14((u8 *)a);
    if (d == 1) {
        func_021BB778(c);
    }
    func_021ABFA8(a, &d_021D9A90, 0, 0, s, 0);
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB5C8(u32 a)
{
if (a != 0) {
    return ((struct Obj18172 *)((u8 *)(func_021AC1E0(a))))->f24;
}
return 1;
}




void func_021BB5DC(int a, Out *out)
{
    out->b = *func_021AC1AC(a);
    out->f2C = 0x6000;
    func_021AC178(a);
}


/*
 * Lays out the up-to-eight menu rows listed at +0x120 (8 terminates),
 * stacking them by the heights in d_021BD5EC and positioning the row
 * sprites.  Row order is filled in by ov088_func_021BB4B4.c.
 */
void func_021BB608(void) {}





void func_021BB60C(u32 a, X *x)
{
    int v[3];
    if (func_0216E1C4(x->fC, (int)x->f10) == 0) {
        x->f24 = 1;
        return;
    }
    func_0216D88C((const struct Actor *)x->fC, (struct VecFx32 *)v);
    func_021BB808((int *)x, (struct Vec *)v);
    func_021AC1CC(a, v);
}











void func_021BB648(int a, int *b)
{
    int v[3];

    if (b[9] == 1 || func_0216E1C4(b[3], (int)(b + 4)) == 0) {
        func_021AC154(a);
        return;
    }
    func_0216D88C((const struct Actor *)b[3], (struct VecFx32 *)v);
    func_021BB808(b, (struct Vec *)v);
    func_021AC1CC(a, v);
}











/*
 * Twin of ov021_func_02189810 (save/modify/restore of the projection matrix
 * g_02148B54).  Here the matrix is read through a pointer local initialised
 * at its declaration, which is what loads its address before the soft-float
 * conversion; `saved = g_02148B54` loads it after (22 bytes off with the
 * pointer declared first, r4/r5 swapped with it declared last).
 *
 * Addresses are Black-image addresses.
 */
void func_021BB68C(u32 a, Arg_021BB60C *b)
{
    Node n = d_021D9AA4;
    MtxFx44 *g = &g_02148B54;
    MtxFx44 saved;
    MtxFx44 m;
    fx32 z;

    z = FX_F32_TO_FX32(b->f8->f34);
    saved = *g;
    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], z);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_0207ADC4(n.mtx);
    func_021AC1B8(a, &n);
    func_02047AC8((void *)b->f8->f24[b->f0], (struct Arg_021BB60C *)(&n));
    MIi_CpuCopyFast(&saved, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
}











void func_021BB778(int n)
{
    int id = 0;

    switch (n) {
    case 0:
        id = 0x678;
        break;
    case 1:
        id = 0x730;
        break;
    case 2:
        id = 0x731;
        break;
    case 3:
        return;
    }
    func_020061E4(id);
}











void func_021BB7B4(int a, int b, int c)
{
    int v6c[3];
    int v60[3];
    int v54[3];
    int m24[12];
    int m0[9];

    func_02048AE8(a, v6c);
    func_02048B0C(a, v60);
    func_02048B30(a, v54);
    func_0207BCA0(v6c, v60, v54, m24);
    func_02082B60(m24, m0);
    func_0207B0A4(m0, m0);
    func_0207B51C(b, m0, c);
}











void func_021BB808(int *o, Vec *out)
{
    int r3;
    Vec w;

    switch (o[7]) {
    case 0:
        o[10] += o[11];
        if (o[10] != 0) {
            o[11] = o[11] - 0x2000;
        } else {
            o[11] = 0;
            o[7] = o[7] + 1;
        }
        break;
    case 1:
        o[8] = o[8] + 1;
        if (o[8] >= 30) {
            o[7] = o[7] + 1;
            o[9] = 1;
        }
        break;
    }
    r3 = func_0218EC2C(func_02188C58((void *)o[6]));
    {
        Vec v = {0, 0, 0};

        v.y = o[10] + 0x16000;
        w = v;
    }
    func_021BB7B4(r3, (int)(&w), (int)(&w));
    func_0207C9D0(&w, out, out);
}











int *func_021BB890(int a, int b, int n)
{
    int *p = func_02030734(b, 0x18, 1, (const char *)&d_021DE2F8, 0x46);
    int sz;

    p[0] = a;
    p[1] = b;
    p[2] = n;
    p[3] = (int)func_02030734(b, 0x18 * n, 1, (const char *)&d_021DE2F8, 0x4a);
    sz = func_02030CB0(n);
    p[5] = (int)func_02030734(b, sz, 1, (const char *)&d_021DE2F8, 0x56);
    p[5] = (int)func_02030CBC(n, (struct Ctx *)p[5]);
    p[4] = (int)func_02030734(b, sz, 1, (const char *)&d_021DE2F8, 0x59);
    p[4] = (int)func_02030CBC(n, (struct Ctx *)p[4]);
    return p;
}











void func_021BB90C(Obj *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        func_021BBA1C((int *)(&p->arr[i]));
    }
    func_020307B0(p->arr);
    func_020307B0(p->f10);
    func_020307B0(p->f14);
    func_020307B0(p);
}











void func_021BB948(u8 *p)
{
    func_02030D28((struct Ctx *)(((struct Obj18174 *)p)->f10));
}











void func_021BB954(u8 *p)
{
    func_02030D28((struct Ctx *)(((struct Obj18175 *)p)->f14));
}










void func_021BB960(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(((struct Obj07223 *)((u8 *)(b)))->fC) + 16) != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 16))(b, *(u32 *)((u8 *)(((struct Obj07223 *)((u8 *)(b)))->f0)), ((struct Obj07223 *)((u8 *)(b)))->f10, *(u32 *)((u8 *)(((struct Obj07223 *)((u8 *)(b)))->fC) + 16));
}
}










void func_021BB978(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->fC) + 20) != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 20))(b, *(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->f0)), ((struct Obj07224 *)((u8 *)(b)))->f10, *(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->fC) + 20));
}
}










int *func_021BB990(int a, int *d, const int *c)
{
    int *p = (int *)d[3];
    int i;

    for (i = 0; i < d[2]; i++, p += 6) {
        if (p[1] != 0) {
            continue;
        }
        if (a != -1) {
            func_02034AC4(a);
        }
        p[5] = a;
        p[1] = func_02030DA8(d[4], func_021BB960, p, c[0]);
        p[2] = func_02030DA8(d[5], func_021BB978, p, c[0]);
        p[0] = (int)d;
        p[3] = (int)c;
        if (((struct Obj06051 *)c)->f4 != 0) {
            p[4] = (int)func_02030734((u16)d[1], ((struct Obj06051 *)c)->f4, 1, (const char *)&d_021DE2F8, 0xc3);
        }
        if (c[2] != 0) {
            ((void (*)(int *, int, int))c[2])(p, d[0], p[4]);
        }
        return p;
    }
    return 0;
}









void func_021BBA1C(int *p)
{
    int *c;

    if (p[1] == 0) {
        return;
    }
    c = (int *)p[3];
    if (c[3] != 0) {
        ((void (*)(int *, int, int))c[3])(p, *(int *)p[0], p[4]);
    }
    if (*(u16 *)((char *)p[3] + 4) != 0) {
        func_020307B0((void *)p[4]);
    }
    func_02030EAC((struct Node *)p[1]);
    func_02030EAC((struct Node *)p[2]);
    if (p[5] != -1) {
        func_02034A5C(p[5]);
    }
    func_02082BCC(p, 0, 0x18);
}









u32 func_021BBA6C(const void *p)
{
    return ((struct Obj20098 *)p)->f10;
}







void func_021BBA70(Ctx *ctx, Src *src, u16 *v, u8 kind)
{
    Ring *ring = &ctx->ring;
    Entry *e;
    int a;
    int t;
    int s;
    int r;

    if (src == 0 && v == 0) {
        func_02034714((void *)0x021DE308, 0, (void *)0x021DE308);
    }
    if (src != 0 && func_021BBC58(ring, src->key, src->h) == 0) {
        return;
    }
    e = func_021BBBD8(ring);
    if (src == 0) {
        a = ctx->sys->a;
        func_020084F8((void *)a, (u32)e->id, 8);
        /* the re-test of v inside the v == 0 arm is the dead second bne */
        if (v == 0) {
            if (v != 0 || kind == 0) {
                func_02034714((void *)0x021DE308, 0, (void *)0x021DE308);
            }
        }
        e->v[0] = v[0];
        e->v[1] = v[1];
        e->v[2] = v[2];
        e->v[3] = v[3];
        e->kind = kind;
        e->h = 0;
        func_02087C6C(e->key);
        e->flag = func_02008550((const struct Sub0200852CObj *)a);
        e->rel = 0;
    } else {
        func_0201F41C((const u16 *)src->id, (u16 *)e->id, 8);
        e->v[0] = src->v[0];
        e->v[1] = src->v[1];
        e->v[2] = src->v[2];
        e->v[3] = src->v[3];
        e->kind = src->kind;
        e->h = src->h;
        func_02082D44(src->key, e->key, 6);
        e->flag = src->flag;
        t = (int)func_020120F4((const struct Ctx *)ctx->sys->c);
        s = func_0201283C((const struct BigObj *)t);
        t = (int)func_0200ED48(func_02012EBC((struct Big *)t));
        if (func_0217F894((void *)s, (char *)src) == 1) {
            r = 1;
        } else if (func_0200EDC4((struct L0200EDC4 *)t, src->x5c) == 1) {
            r = 2;
        } else {
            r = 0;
        }
        e->rel = r;
    }
    if (ring->count == ring->mark) {
        ring->mark++;
    }
    ring->count++;
    if (ring->count - ring->mark >= 30) {
        ring->mark = ring->count - 29;
    }
}






Entry *func_021BBBD8(Ring *r)
{
    int t;
    Entry *ret;
    if (r->count > 0) {
        t = r->tail;
        if (t == r->head) {
            r->head += 1;
            if (r->head >= 30) r->head = 0;
        }
    }
    ret = &r->e[r->tail];
    r->tail += 1;
    if (r->tail >= 30) r->tail = 0;
    return ret;
}






Entry *func_021BBC2C(Ring *r, u32 i)
{
    Entry *e = &r->e[i % 30];

    if (func_0203EFC8(e->key, (const u8 *)d_021D9AE0, 6) == 0) {
        e = 0;
    }
    return e;
}






/* A u16 `c` (not int/u32) is what stores c's spill before b's. */
int func_021BBC58(Ring *r, const void *b, u16 c)
{
    int i;
    Entry *p;

    for (i = r->count; i > r->count - 30; i--) {
        if (i < 0) return 1;
        p = func_021BBC2C(r, i);
        if (p != 0 && func_0203EFC8(p->key, b, 6) == 0) {
            if (p->h != c) return 1;
            return 0;
        }
    }
    return 1;
}






ActTbl *func_021BBCBC(void *owner, u32 heap)
{
    ActTbl *o;

    o = func_02030734(heap, 0x40, 1, d_021DE30C, 0x9d);
    o->owner = owner;
    o->res = (void *)func_02188C88((u8 *)func_021ABE14(owner));
    func_021BBD0C(o);
    o->f3c = 0x2000;
    return o;
}






/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBCF8(u32 a, ActTbl *p)
{
    func_021BBD64(p);
    func_020307B0(p);
}






void func_021BBD0C(ActTbl *p)
{
    Arg_021BBC58 s;
    int i;
    const u16 *t = d_021D9B0C;
    u32 r7 = func_021ABE24((u8 *)p->owner);
    s.b4 = 2;
    s.b5 = 0x11;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.c = 1;
    for (i = 0; i < 0x1a; i++, t++) {
        s.a = (u32)func_02046E24(r7, *t);
        func_021AC1F0((struct X *)p->owner, (void *)s.a);
        p->h8[i] = func_020500F0((struct BbActSys *)p->res, (const struct BbActRec *)(&s), 1);
    }
}




void func_021BBD64(ActTbl *p)
{
    int i;

    for (i = 0; i < 0x1A; i++) {
        func_02050278((struct BbActSys *)p->res, p->h8[i], 1);
    }
}




int func_021BBD84(int a, int n, int x, int y)
{
    int r = 0;
    switch (n) {
    case 0: r = x; break;
    case 1: r = d_021D9AE8[y].b[x]; break;
    case 2: r = x + 10; break;
    case 3: r = d_021D9AE8[y].b[x] - 4; r += 14; break;
    case 4: r = d_021D9AE8[y].b[x] - 4; r += 20; break;
    }
    return r;
}
