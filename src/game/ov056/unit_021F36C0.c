/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36C8, func_021F36D4, func_021F36E4, func_021F36F0, func_021F3734, func_021F3890, func_021F38D4, func_021F3904, func_021F3918, func_021F392C, func_021F3A14, func_021F3A78, func_021F3AB0, func_021F3B10, func_021F3BF0, func_021F3C4C, func_021F3C84, func_021F3CC4, func_021F3D2C, func_021F3D44, func_021F3D54, func_021F3D60, func_021F3D9C, func_021F3DB8, func_021F3DCC, func_021F3E38, func_021F3E54
 * address:  0x021F36C0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F42B0  0x021F42B0  data
 *   func_02047674  0x02047674  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   d_021F42C0     0x021F42C0  data  a4
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   d_021F4290  0x021F4290  data  ov056  a4
 *   d_021F42D8  0x021F42D8  data  ov056  a4
 *   func_0218C860 0x0218C860 thumb ov021
 *   func_0218C69C 0x0218C69C thumb ov021
 *   func_0218C88C 0x0218C88C thumb ov021
 *   func_0218C8B0 0x0218C8B0 thumb ov021
 *   func_02011510  0x02011510  thumb
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048A24  0x02048A24  arm
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F1B4  0x0218F1B4  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218ED20  0x0218ED20  thumb  ov021
 *   d_021F4338     0x021F4338  data  a4
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ED14  0x0218ED14  thumb  ov021
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_02048AC4  0x02048AC4  arm
 *   func_02011558  0x02011558  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02011608  0x02011608  thumb
 *   func_020115EC  0x020115EC  thumb
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048B0C  0x02048B0C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   d_021F426C     0x021F426C  data  a4
 *   func_020490F4  0x020490F4  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02008550  0x02008550  thumb
 *   func_02046E24  0x02046E24  arm
 *   func_02047180  0x02047180  arm
 *   func_02049238  0x02049238  arm
 *   d_021F4308     0x021F4308  data  a4
 *   d_021F4264     0x021F4264  data  a2
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_02047204  0x02047204  arm
 *   func_021F4040  0x021F4040  thumb  ov056
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_021F42A0     0x021F42A0  data  a4
 *   d_021F43A4     0x021F43A4  data  a4
 *   func_021F408C  0x021F408C  thumb  ov056
 *   func_021F40A0  0x021F40A0  thumb  ov056
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F4278  0x021F4278  data  ov056  a4
 *   d_021F4258  0x021F4258  data  ov056  a4
 *   func_02028B50  0x02028B50  thumb
 *   func_02047A60  0x02047A60  arm
 */
#include "../../matched/include/Obj07668.h"
#include "../../matched/include/Obj03166.h"
#include "../../matched/include/Obj01680.h"
#include "../../matched/include/Obj03652.h"
#include "../../matched/include/Obj01881.h"
#include "../../matched/include/Obj09852.h"

struct Desc;
struct Job;
struct Obj;
struct Work;
struct Ctx;
struct Obj00020;
struct Node;
struct IcaAnime;
struct Obj11244;
struct Sub0200852CObj;
struct G3dOwner;
struct G3dRec;
struct AnmCtl;
struct G3dSys;
struct Rec;
struct Tagged;
struct Actor;
struct SoundSys2;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct { char pad[4]; u16 f4; } Inner;

typedef struct { char pad[8]; Inner *f8; } Outer;

typedef struct Work {
    int f0;
    int f4;
    int idx;
    u8 cam[0x30];
    u8 obj[0x80];
    u8 f_bc[0xc];
    u8 f_c8[4];
    u32 task;
    void *fd0;
} Work;

typedef struct { u32 a, b, c; } Ent;

typedef short          s16_021F36C0;

typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32_021F36C0;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Job {
    void *f0;
    void *cam;
    int f8;
    u16 hc;
    u16 he;
    VecFx32_021F36C0 f10;
    VecFx32_021F36C0 f1c;
    int f28;
    u32 f2c;
} Job;

typedef signed int     s32;

typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct Obj {
    void *res0;
    void *res1;
    void *res2;
    int f0c;
    u8 pad10[0x10];
    Vec pos;
    Vec scale;
    Mtx33 rot;
    int f5c;
    int f60;
    void *f64;
    void *f68;
    Vec f6c;
    u16 f78;
    u16 pad7a;
    int f7c;
} Obj;

typedef signed short   s16_021F3B10;

typedef struct VecFx32_021F3B10 { s32 x; s32 y; s32 z; } VecFx32_021F3B10;

extern Outer *func_02047674(u32 a);
extern u16 func_02188C84(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Job *p);
extern void *func_020056A0(void (*cb)(void), void *ctx, int a);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C58(void *p);
extern u32 func_02188C98(u8 *p);
extern u32 func_02188D24(u8 *p);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern u32 func_0218DC6C(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
extern u32 func_021BBA6C(const void *p);
extern void func_021BBA1C(int *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void func_02030EAC(struct Node *n);
extern int func_0218C7D8(void *p, int b, int c);
extern int func_0218C654(int a, int b, int c);
extern void func_0218C860(void *);
extern void func_0218C69C(unsigned char *,int,int,int);
extern void func_0218C88C(unsigned char *,int,int);
extern int func_0218C8B0(void *,int);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048B30(u32 cam, VecFx32_021F36C0 *out);
extern void func_02048AE8(u32 cam, VecFx32_021F36C0 *out);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32_021F36C0 *pos, VecFx32_021F36C0 *up, VecFx32_021F36C0 *tgt, int heap);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern u8 func_0218F1B4(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218EC54(u8 *p);
extern void func_0218ECC4(int a, VecFx32_021F36C0 *v);
extern void func_0218ECD4(int a, VecFx32_021F36C0 *v);
extern void func_0218ED20(void *p, void *out);
extern int func_0218EC60(u32 a);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC90(u32 a, u32 b);
extern void func_0218ED14(u8 *p, u32 q);
extern void func_0218E17C(u32 *p, u32 v);
extern void func_0218F05C(u8 *a);
extern u32 func_02048AC4(void *ptr);
extern void func_02011558(struct IcaAnime *p);
extern void func_02082BCC(void *, unsigned, unsigned);
extern u32 func_02011608(struct Obj11244 *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern void func_02011B8C(void *dst, void *ctx);
extern void func_02048B0C(u32, s32 *);
extern void func_0207C9D0(s32 *a, const Vec *b, s32 *c);
extern void func_0218ECF4(u32 a, s32 *b);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_021A3074(unsigned char *p);
extern void func_0207ADC4(Mtx33 *m);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02047180(u32 *p);
extern void func_02049238(void *);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
extern int func_02164010(int a);
extern void func_0216D88C(const struct Actor *a, struct VecFx32_021F3B10 *out);
extern void func_021A3044(u8 *p, void *v);
extern int func_0216DC18(void *a0, int a1);
extern u32 func_02047204(struct Tagged *p);
extern u32 *func_021F4040(void *a, u32 b, u32 c, u32 d, u16 e);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_021F408C(struct IcaAnime **pp);
extern int func_021F40A0(int *p);
extern int func_0218C6F4(unsigned char *p, int b, int id);
extern void *func_02188C80(void *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_02028B50(u8 *p, int a0);
extern void func_02047A60(void *, void *);
void *func_021F36C0(void *a, u8 *b, u32 c);
u32 func_021F36C8(u32 idx);
int func_021F36D4(u32 a);
void func_021F36E4(u8 *a, u8 *b);
void *func_021F36F0(void *a, u8 *b, u32 c);
int func_021F3734(void *a0, int *state, Work *p);
void func_021F3890(u32 *out, int a, int idx);
void func_021F38D4(unsigned char *p);
void func_021F3904(unsigned char **p);
int func_021F3918(void **p);
void func_021F392C(Job *o, int a1, int heap, int idx);
void func_021F3A14(u8 *p);
int func_021F3A78(u8 *p);
void func_021F3AB0(u32 *p);
void func_021F3B10(Obj *o, void *a1, int a2, int a3, int idx);
void func_021F3BF0(u32 *p);
void func_021F3C4C(u8 *p);
int func_021F3C84(u32 *p);
void func_021F3CC4(u8 *p, int flag);
void func_021F3D2C(u8 *p);
void func_021F3D44(char *a);
void func_021F3D54(int a, int b, char **c);
void func_021F3D60(void *o, int idx, u16 heap);
void func_021F3D9C(void *o);
int func_021F3DB8(int **pp);
void func_021F3DCC(int unused, int b, u32 *c);
void func_021F3E38(void *a0, void *a1);
void func_021F3E54(int unused, int b, u32 *c);
extern const u32 d_021F42B0[];
extern const u8 d_021F42C0[];
extern u32 d_021F4290[];
extern Ent d_021F42D8[];
extern const VecFx32_021F36C0 d_021F4338;
extern const s16_021F36C0 FX_SinCosTable_[];
extern const Vec d_021F426C;
extern const Vec d_021F4308[];
extern const u16 d_021F4264[];
extern u32 d_021F42A0[];
extern u8 d_021F43A4[];
extern Ent d_021F4278;
extern int d_021F4258[];








void *func_021F36C0(void *a, u8 *b, u32 c)
{
    return func_021F36F0(a, b, c);
}








/*
 * Word table lookup in d_021F42B0 ({0x1C, 0x1D, 0x1E, 0x1F}), the table ov056
 * func_021F392C also indexes. Region ov056: of the 33 overlays mapped at this
 * address it is the only one with a function entry here (the bytes before are
 * the tail-call thunk at 0x021F36C0 and its pool word); ov036..ov065 except
 * ov056 are mid-function at 0x021F36C8, ov107 is ARM. Its ov021 caller
 * func_021B5650 passes a 1-based slot minus one (wave A1 witness).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021F36C8(u32 idx)
{
    return d_021F42B0[idx];
}








int func_021F36D4(u32 a)
{
    return func_02047674(a)->f8->f4 << 12;
}








/*
 * Unlabelled tail-call leaf: forwards the second argument plus 0x3c.
 */
void func_021F36E4(u8 *a, u8 *b)
{
    func_021F3D2C(b + 0x3c);
}








void *func_021F36F0(void *a, u8 *b, u32 c)
{
    void *r;
    u32 *t;

    func_02188C84(b);
    r = func_020122C0(a, 0, func_021F3734, 0xd4);
    t = func_020124E8(r);
    t[0] = (u32)b;
    t[1] = (u32)a;
    t[2] = c;
    ((struct Obj07668 *)t)->fD0 = func_020056A0((void (*)(void))func_021F36E4, t, 0);
    return r;
}








int func_021F3734(void *a0, int *state, Work *p)
{
    u16 heap;
    int h;
    int a;
    int b;
    int c;

    heap = func_02188C84((u8 *)p->f0);
    switch (*state) {
    case 0:
        h = (int)func_02012944(func_020120F4((const struct Ctx *)p->f4));
        func_021F3B10((struct Obj *)p->obj, func_02188CB4((void *)p->f0), h, heap, p->idx);
        (*state)++;
        break;
    case 1:
        func_0218F0A8(func_02188C58((void *)p->f0));
        (*state)++;
        break;
    case 2:
        h = (int)func_02188C58((void *)p->f0);
        if (func_0218F0E8((u8 *)h) != 0) {
            break;
        }
        func_021F392C((Job *)p->cam, h, heap, p->idx);
        func_021F3D60(p->f_c8, p->idx, heap);
        func_021F3890((u32 *)p->f_bc, func_0218DC6C((u8 *)func_02188C98((u8 *)p->f0)), p->idx);
        func_021F3BF0((u32 *)p->obj);
        p->task = (u32)func_021BB990(-1, (int *)func_02188D24((u8 *)p->f0), (const int *)d_021F42C0);
        *((void **)func_021BBA6C((const void *)p->task)) = p->obj;
        func_021F3CC4(p->obj, 1);
        func_021F3904((unsigned char **)p->f_bc);
        (*state)++;
        break;
    case 3:
        a = func_021F3A78(p->cam);
        func_021F3C84((u32 *)p->obj);
        b = func_021F3DB8((int **)p->f_c8);
        c = func_021F3918((void **)p->f_bc);
        if (a && c && b) {
            (*state)++;
        }
        break;
    case 4:
        func_021F3CC4(p->obj, 0);
        func_021BBA1C((int *)p->task);
        func_02030EAC(p->fd0);
        func_021F3C4C(p->obj);
        func_021F3D9C(p->f_c8);
        func_021F3A14(p->cam);
        func_021F38D4(p->f_bc);
        return 1;
    }
    return 0;
}








void func_021F3890(u32 *out, int a, int idx)
{
    if (d_021F4290[idx] != 0) {
        out[0] = func_0218C7D8((void *)a, 0, (int)(&d_021F42D8[idx]));
        out[1] = func_0218C654(a, 0, (int)(&d_021F42D8[idx]));
        out[2] = a;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}







void func_021F38D4(unsigned char *p) { if (((struct Obj03166 *)p)->f0) { func_0218C860(((struct Obj03166 *)p)->f0); func_0218C69C(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,1); func_0218C69C(*(unsigned char * *)&((struct Obj03166 *)p)->f8,((struct Obj03166 *)p)->f4,0,3); *(int *)&((struct Obj03166 *)p)->f0=0; ((struct Obj03166 *)p)->f4=0; *(int *)&((struct Obj03166 *)p)->f8=0; } }







void func_021F3904(unsigned char **p) { if (*p) func_0218C88C(*p,0,0); }






int func_021F3918(void **p) { if (*p) return func_0218C8B0(*p,0); return 1; }







void func_021F392C(Job *o, int a1, int heap, int idx)
{
    VecFx32_021F36C0 tgt;
    VecFx32_021F36C0 pos;
    u8 zero[12];
    VecFx32_021F36C0 up;
    u32 cam;
    VecFx32_021F36C0 *pz;

    o->f28 = 0;
    o->f0 = func_02011510(heap, 0x96, idx + 0x18, 10);
    cam = func_0218EC2C((u8 *)a1);
    func_02048B30(cam, &tgt);
    func_02048AE8(cam, &pos);
    up = d_021F4338;
    o->cam = func_02048A24(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &pos, &up, &tgt, heap);
    o->f8 = a1;
    o->hc = func_0218E138((u8 *)a1);
    func_0218E13C((u8 *)o->f8, 2);
    o->he = func_0218F1B4((u8 *)o->f8);
    func_0218F1AC((u8 *)o->f8, 0);
    func_0218EC54((u8 *)o->f8);
    pz = (VecFx32_021F36C0 *)zero;
    pz->x = 0;
    pz->y = 0;
    pz->z = 0;
    func_0218ECC4(o->f8, &o->f10);
    func_0218ECD4(o->f8, pz);
    func_0218ED20((void *)o->f8, &o->f1c);
    func_021F3AB0((u32 *)o);
    o->f2c = d_021F42B0[idx];
}






void func_021F3A14(u8 *p)
{
    func_0218EC60(*(u32 *)&((struct Obj01680 *)p)->f8);
    func_0218EC90(*(u32 *)&((struct Obj01680 *)p)->f8, func_0218EC5C(*(u8 * *)&((struct Obj01680 *)p)->f8));
    func_0218ECD4(*(u32 *)&((struct Obj01680 *)p)->f8, (VecFx32_021F36C0 *)((u32)(p + 0x10)));
    func_0218E13C((u8 *)(*(u32 *)&((struct Obj01680 *)p)->f8), ((struct Obj01680 *)p)->fC);
    func_0218F1AC(*(u8 * *)&((struct Obj01680 *)p)->f8, ((struct Obj01680 *)p)->fE);
    func_0218ED14((u8 *)(*(u32 *)&((struct Obj01680 *)p)->f8), (u32)(p + 0x1c));
    func_0218E17C(*(u32 * *)&((struct Obj01680 *)p)->f8, ((struct Obj01680 *)p)->f2C);
    func_0218F05C(*(u8 * *)&((struct Obj01680 *)p)->f8);
    func_02048AC4((void *)(((struct Obj01680 *)p)->f4));
    func_02011558((struct IcaAnime *)(((struct Obj01680 *)p)->f0));
    func_02082BCC(p, 0, 0x30);
}






/*
 * note:     twin of the head of func_021F40A0 (same clock read and clamp),
 *           with the frame counter at +0x28. EXACT* = 54 bytes of code plus
 *           2 bytes of alignment padding before matched func_021F3AB0.
 */
int func_021F3A78(u8 *p)
{
    int flag;
    s32 x = func_02011608((struct Obj11244 *)(*(struct IcaAnime **)(p + 0x0))) << 12;
    s32 y = *(s32 *)(p + 0x28) + 0x1000;

    if (x <= y) {
        flag = 1;
        *(s32 *)(p + 0x28) = x - 0x1000;
    } else {
        flag = 0;
        *(s32 *)(p + 0x28) = y;
    }
    func_020115EC(*(struct IcaAnime **)(p + 0x0), *(s32 *)(p + 0x28));
    func_021F3AB0((u32 *)p);
    return flag;
}




void func_021F3AB0(u32 *p)
{
    s32 v2[3];
    s32 v1[3];
    s32 v3[3];

    func_02011B8C((void *)p[1], (void *)p[0]);
    func_02048AE8(p[1], (VecFx32_021F36C0 *)v1);
    func_02048B30(p[1], (VecFx32_021F36C0 *)v2);
    func_02048B0C(p[1], v3);
    func_0207C9D0(v1, &d_021F426C, v1);
    func_0207C9D0(v2, &d_021F426C, v2);
    func_0218ECF4(p[2], v1);
    func_0218EC90(p[2], (u32)v2);
    func_0218ED14((u8 *)p[2], (u32)v3);
}






void func_021F3B10(Obj *o, void *a1, int a2, int a3, int idx)
{
    void *h;
    int k;

    idx = (u32)idx;
    h = func_020490F4(0x96, (u16)((a3 & 0x7fff) | 0x8000));
    o->f7c = 0;
    o->f5c = 0;
    o->f6c = d_021F4308[idx];
    o->f60 = a2;
    o->f78 = d_021F4264[idx];
    o->f64 = a1;
    o->f68 = func_021A3074(a1);
    o->pos = d_021F426C;
    o->scale.x = 0x1000;
    o->scale.y = 0x1000;
    o->scale.z = 0x1000;
    func_0207ADC4(&o->rot);
    if (func_02008550((const struct Sub0200852CObj *)a2) == 0) {
        k = idx * 6;
        o->res0 = func_02046E24((u32)h, k + 3);
        o->res2 = func_02046E24((u32)h, k + 4);
    } else {
        k = idx * 6;
        o->res0 = func_02046E24((u32)h, k + 1);
        o->res2 = func_02046E24((u32)h, k + 2);
    }
    o->res1 = func_02046E24((u32)h, k + 5);
    func_02047180(o->res0);
    o->f0c = 1;
    func_02049238(h);
}






void func_021F3BF0(u32 *p)
{
    int i;
    int v;

    i = 0;
    p[4] = (u32)func_02047400((void *)p[0], 0, (void *)p[0]);
    p[5] = (u32)func_02047564((struct G3dOwner *)p[4], (const struct G3dOwner *)p[1], 0);
    p[6] = (u32)func_02047564((struct G3dOwner *)p[4], (const struct G3dOwner *)p[2], 0);
    p[7] = (u32)func_0204767C(p[4], &p[5], 2);
    v = 0;
    for (; i < 2; i++) {
        func_0204784C((struct AnmCtl *)p[7], (u16)i, &v);
        func_020477A4((struct G3dSys *)p[7], (u16)i);
    }
}






void func_021F3C4C(u8 *p)
{
    func_02047738((struct Rec *)(((struct Obj03652 *)p)->f1C));
    func_0204762C((struct Rec *)(((struct Obj03652 *)p)->f14));
    func_0204762C((struct Rec *)(((struct Obj03652 *)p)->f18));
    func_02047504((struct Rec *)(((struct Obj03652 *)p)->f10));
    func_020470D0((u32 *)(((struct Obj03652 *)p)->f0));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f0));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f4));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f8));
}






int func_021F3C84(u32 *p)
{
    int r;
    int lim;
    int ret;

    r = func_021F36D4(p[5]);
    lim = p[31] + 0x1000;
    if (r <= lim) {
        ret = 1;
        p[31] = r - 0x1000;
    } else {
        ret = 0;
        p[31] = lim;
    }
    func_0204784C((struct AnmCtl *)p[7], 0, (int *)&p[31]);
    func_0204784C((struct AnmCtl *)p[7], 1, (int *)&p[31]);
    return ret;
}






void func_021F3CC4(u8 *p, int flag)
{
    VecFx32_021F3B10 v;

    if (flag) {
        ((struct Obj01881 *)p)->f5C = 1;
        func_0216DAC8(((struct Obj01881 *)p)->f68, 1);
        return;
    }
    ((struct Obj01881 *)p)->f5C = 0;
    func_0216DAC8(((struct Obj01881 *)p)->f68, 0);
    func_0216E084(((struct Obj01881 *)p)->f68, (s16_021F3B10)(((struct Obj01881 *)p)->f6C), (s16_021F3B10)(((struct Obj01881 *)p)->f70),
                  (s16_021F3B10)(((struct Obj01881 *)p)->f74), ((struct Obj01881 *)p)->f78);
    func_02164010((int)(((struct Obj01881 *)p)->f68));
    func_0216D88C(((struct Obj01881 *)p)->f68, &v);
    func_021A3044(((struct Obj01881 *)p)->f64, &v);
    func_0216DC18(((struct Obj01881 *)p)->f68, 0);
}




void func_021F3D2C(u8 *p)
{
    if (((struct Obj09852 *)p)->fC != 0) {
        func_02047204((struct Tagged *)(((struct Obj09852 *)p)->f0));
        ((struct Obj09852 *)p)->fC = 0;
    }
}




/*
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of func_021F4040's u16 parameter (an int heap adds lsls/lsrs).
 */
void func_021F3D44(char *a)
{
    func_02047A60(*(void **)(a + 0x1c), a + 0x20);
}



/*
 * Addresses are Black-image addresses.
 */
void func_021F3D54(int a, int b, char **c)
{
    func_021F3D44(*c);
}



void func_021F3D60(void *o, int idx, u16 heap)
{
    if (d_021F42A0[idx] != 0) {
        *(u32 **)o = func_021F4040(d_021F43A4 + idx * 0x12, 0x96, idx + 0x1c, 10, heap);
        return;
    }
    MI_CpuFill8(o, 0, 4);
}




void func_021F3D9C(void *o)
{
    if (*(void **)o != 0) {
        func_021F408C(*(void **)o);
    }
    func_02082BCC(o, 0, 4);
}




int func_021F3DB8(int **pp)
{
    int r = 1;

    if (*pp != 0) {
        r = func_021F40A0(*pp);
    }
    return r;
}




void func_021F3DCC(int unused, int b, u32 *c)
{
    int r7;
    u32 i;
    int r;

    r7 = func_0218DC6C((u8 *)func_02188C98((u8 *)b));
    i = 0;
    c[1] = func_0218C654(r7, 0, (int)(&d_021F4278));
    c[0] = r7;
    r = func_0218C6F4((unsigned char *)r7, c[1], 1);
    c[2] = 0x6000;
    c[3] = i;
    for (; i < 1; i++) {
        if (r < d_021F4258[i]) {
            c[2] = d_021F4258[i];
            c[3] = i;
            break;
        }
    }
    func_02028A7C((struct SoundSys2 *)func_02012A30((const struct BigObj *)func_020120F4(func_02188C80((void *)b))), 0x746);
}




void func_021F3E38(void *a0, void *a1)
{
    func_02028B50((u8 *)func_02012A30(func_020120F4(func_02188C80(a1))), 0x746);
}




void func_021F3E54(int unused, int b, u32 *c)
{
    int r;

    if (c[2] == func_0218C6F4((unsigned char *)c[0], c[1], 1)) {
        r = func_02012A30((const struct BigObj *)func_020120F4(func_02188C80((void *)b)));
        c[3] = 0;
        c[2] = d_021F4258[c[3]];
        func_02028A7C((struct SoundSys2 *)r, 0x692);
    }
}
