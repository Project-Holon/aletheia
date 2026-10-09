/*
 * file:     button_man_p01.c
 * unit:     yes
 * function: func_02051788, func_02051790, func_020517A4, func_020517B4, func_020517D0, func_020517D8, func_020517E0, func_020517E8, func_020517F0, func_02051800, func_02051808, func_02051818, func_02051820, func_02051830, func_02051838, func_02051880, func_0205189C, func_020518A4, func_020518AC, func_020519C4, func_020519E4, func_02051A04, func_02051A24, func_02051A2C, func_02051A34, func_02051A3C, func_02051A54, func_02051AA0, func_02051AB8, func_02051B04, func_02051B0C, func_02051B84, func_02051C58, func_02051C6C, func_02051C88, func_02051DE8, func_02051E10, func_02051E64, func_02051E74, func_02051F1C, func_02051F34, func_0205207C, func_020520A4, func_020520FC, func_020521BC, func_02052274, func_020522E4
 * address:  0x02051788
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02057EF8  0x02057EF8  arm
 *   func_02057F8C  0x02057F8C  arm
 *   func_020580A8  0x020580A8  arm
 *   func_02058180  0x02058180  arm
 *   func_02058204  0x02058204  arm
 *   func_020582CC  0x020582CC  arm
 *   g_020A8140   0x020A8140  data
 *   g_02146A88   0x02146A88  data
 *   g_020A8148   0x020A8148  data
 *   func_0207E1F8  0x0207E1F8  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_0207E2A0  0x0207E2A0  arm
 *   func_0207E330  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   func_0207E2F0  0x0207E2F0  arm
 *   func_0207E388  0x0207E388  arm
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   g_020A7FCC      0x020A7FCC  data
 *   g_020A15E8    0x020A15E8  data
 *   func_02035C38 0x02035C38  arm
 *   func_02035BA4 0x02035BA4  arm
 *   func_02035C08 0x02035C08  arm
 *   func_02035C60 0x02035C60  arm
 *   MTX_Rot22_       0x0207AD64  thumb
 *   MTX_ScaleApply22 0x0207AD70  arm
 *   func_0207C778    0x0207C778  arm
 *   tbl_020A1B38     0x020A1B38  data
 *   VEC_Subtract    0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_Mag         0x0207CBD0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *   FX_Div          0x0207C768  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   MTX_RotX33_      0x0207AF00  thumb
 *   MTX_RotY33_      0x0207AF1C  thumb
 *   MTX_RotZ33_      0x0207AF38  thumb
 *   MTX_Concat33     0x0207B388  arm
 *   FX_Atan2Idx    0x0207CFB8  arm
 *   func_02045A98  0x02045A98  arm
 */
#include "../../matched/include/Obj16168.h"
#include "../../matched/include/Obj16169.h"
#include "../../matched/include/Obj16170.h"
#include "../../matched/include/Obj16171.h"
#include "../../matched/include/Obj16172.h"
#include "../../matched/include/Obj16173.h"
#include "../../matched/include/Obj16174.h"
#include "../../matched/include/Obj16175.h"
#include "../../matched/include/Obj16176.h"
#include "../../matched/include/Obj16177.h"
#include "../../matched/include/Obj16178.h"
#include "../../matched/include/Obj16187.h"
#include "../../matched/include/Obj16190.h"
#include "../../matched/include/Obj16191.h"
#include "../../matched/include/Obj16192.h"
#include "../../matched/include/Obj16193.h"
#include "../../matched/include/Obj11459.h"
#include "../../matched/include/Obj11460.h"
#include "../../matched/include/Obj16194.h"
#include "../../matched/include/Obj08875.h"
#include "../../matched/include/Obj16196.h"
#include "../../matched/include/Obj04767.h"
#include "../../matched/include/Obj16198.h"

struct A;
struct B;
struct C;
struct Obj;
struct S;
struct Src;
typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    short x, y, z;
} Vec16;

typedef unsigned int u32;

typedef struct { u32 x, y, z; } VecFx32;

struct ParticleInner {
    u32     f00;
    VecFx32 pos;            /* +0x04 */
};

struct ParticleBlk {
    struct ParticleInner *inner;    /* +0x00, re-read per statement */
};

struct ParticleEmitter {
    char                pad00[0x20];
    struct ParticleBlk *blk;        /* +0x20 */
    char                pad24[0x04];
    VecFx32             pos;        /* +0x28 */
};

typedef unsigned short u16;

struct Vec3_02051788 {
    u16 x;
    u16 y;
    u16 z;
};

struct Obj_02051880 {
    char pad[0x50];
    u16 x;
    u16 y;
    u16 z;
};

struct Obj_0205189C {
    char pad[0x6c];
    u32 f6c;
};

struct Obj_020518A4 {
    char pad[0x70];
    u16 f70;
};

struct Ent {
    void *fn;
    void *data;
};

struct Blk {
    char pad[0x18];
    struct Ent *ents;
    u16 count;
};

typedef unsigned char  u8;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

struct Ctx_02051788 {
    u8   pad_00[0x44];
    u8  *base;      /* 0x44 */
};

typedef struct S02051B84 {
    u8 *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
} S02051B84;

typedef signed int     s32;

typedef signed short   s16_02051C88;

struct Slot { u8 kind; u8 state; u8 pad[2]; };

struct Ctx_02051C88 {
    s32   f00;            /* 0x00 */
    u32   n;              /* 0x04 */
    void (*cb)(s32, s32, s32);  /* 0x08 */
    s32   arg;            /* 0x0c */
    struct Slot *slots;   /* 0x10 */
};

typedef signed short  s16_02051E74;

struct Mtx22 { s32 m[4]; };

struct Vec { int x, y, z; };

struct Ball_02051F1C { struct Vec p; int radius; };

struct Vec3_02051C88 { int x; int y; int z; };

struct Seg {
    struct Vec3_02051C88 p0;   /* 0x00 */
    struct Vec3_02051C88 dir;  /* 0x0c */
    u32 pad18;
};

struct Ball_02051F34 {
    struct Vec3_02051C88 c;    /* 0x00 */
    int r;            /* 0x0c */
};

struct Out {
    u32 hit;          /* 0x00 */
    struct Vec3_02051C88 n;    /* 0x04 */
    int d;            /* 0x10 */
};

typedef long long s64;

typedef short s16_020520FC;

struct Mtx33 {
    int m[9];
};

typedef short s16_020521BC;

extern void func_02057EF8(struct A *a, struct B *b);
extern void func_02057F8C(struct A *a, struct S *s, int unused, struct C *c);
extern void func_020580A8(struct Obj *o, u8 *dst);
extern void func_02058180(struct A *a, struct B *b, volatile int *c);
extern void func_02058204(struct Obj *o, struct Src *s, int *dst);
extern void func_020582CC(struct Obj *o, void *s, int *dst);
extern u32 func_020616CC(u32 size, u32 flag, u32 dir);
extern void *func_0207E1F8(void);
extern void *func_0207E24C(void);
extern void *func_0207E2A0(void);
extern void *func_0207E330(void);
extern int func_0207E22C(void);
extern int func_0207E280(void);
extern void *func_0207E2F0(void);
extern void *func_0207E388(void);
extern void *func_02030734(u16 id, u32 size, u32 flags, void *file, u32 line);
extern u32 func_020307B0(void *p);
extern s32 func_02035C38(void);
extern int func_02035BA4(const void *p);
extern int func_02035C08(const void *p);
extern s32 func_02035C60(void);
extern void MTX_Rot22_(struct Mtx22 *mtx, s32 sinVal, s32 cosVal);
extern void MTX_ScaleApply22(const struct Mtx22 *src, struct Mtx22 *dst, s32 x, s32 y);
extern long func_0207C778(long v);
extern void VEC_Subtract(const struct Vec3_02051C88 *a, const struct Vec3_02051C88 *b, struct Vec3_02051C88 *d);
extern int  VEC_DotProduct(const struct Vec3_02051C88 *a, const struct Vec3_02051C88 *b);
extern int  VEC_Mag(const struct Vec3_02051C88 *v);
extern void VEC_Normalize(const struct Vec3_02051C88 *v, struct Vec3_02051C88 *d);
extern int  FX_Div(int a, int b);
extern void MTX_Identity33_(struct Mtx33 *m);
extern void MTX_RotX33_(struct Mtx33 *m, s16_020520FC sinv, s16_020520FC cosv);
extern void MTX_RotY33_(struct Mtx33 *m, s16_020520FC sinv, s16_020520FC cosv);
extern void MTX_RotZ33_(struct Mtx33 *m, s16_020520FC sinv, s16_020520FC cosv);
extern void MTX_Concat33(const struct Mtx33 *a, const struct Mtx33 *b,
                         struct Mtx33 *dst);
extern int  FX_Atan2Idx(int y, int x);
extern u16 func_02045A98(void);
int func_02051788(char *p);
void func_02051790(char *p, Vec *out);
void func_020517A4(char *p, const Vec *v);
void func_020517B4(char *p, Vec16 *out);
int func_020517D0(char *p);
void func_020517D8(char *p, int v);
int func_020517E0(char *p);
void func_020517E8(char *p, int v);
short func_020517F0(char *p);
void func_02051800(char *p, int v);
short func_02051808(char *p);
void func_02051818(char *p, int v);
short func_02051820(char *p);
unsigned short func_02051830(char *p);
void func_02051838(struct ParticleEmitter *e, const VecFx32 *q);
void func_02051880(struct Obj_02051880 *o, const struct Vec3_02051788 *v);
void func_0205189C(struct Obj_0205189C *o, u32 v);
void func_020518A4(struct Obj_020518A4 *o, u16 v);
void *func_020518AC(void *obj, int kind);
void func_020519C4(void *p, struct S12 *q);
void func_020519E4(void *p, u16 *q);
void func_02051A04(void *p, struct S12 *q);
void func_02051A24(void *p, int v);
void func_02051A2C(void *p, int v);
int func_02051A34(void *p);
unsigned int func_02051A3C(int a0, int a1, int a2, int a3);
u32 func_02051A54(u32 a, u32 b);
int func_02051AA0(int a, int b);
u32 func_02051AB8(u32 a, u32 b);
u16 func_02051B04(void *res);
int func_02051B0C(int i);
void *func_02051B84(u8 *a0, int a1, int a2, int a3);
void func_02051C58(void *p0);
void func_02051C6C(void *p);
s32 func_02051C88(struct Ctx_02051C88 *c);
int func_02051DE8(void *p, int a, int b);
int func_02051E10(char *p, u32 x);
void func_02051E64(void *p, int a);
void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
void func_02051F1C(struct Ball_02051F1C *dst, struct Vec *src, unsigned radius);
u32 func_02051F34(struct Seg *seg, struct Ball_02051F34 *b, struct Out *out);
void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v);
void func_020520A4(const struct Vec3_02051C88 *v, int s, struct Vec3_02051C88 *dst);
void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
void func_020521BC(const struct Vec3_02051C88 *v, struct Mtx33 *dst);
void func_02052274(u8 *a, u8 *b, u32 n);
int func_020522E4(u16 *src, char *dst, u32 *stop);
extern struct Ctx_02051788 *g_02146A88;
extern int g_020A7FCC;
extern s16_02051E74 tbl_020A1B38[];




















/*
 * Returns the word at offset 0x20. Filed as the witness for ov094 func_021FA458.
 */
int func_02051788(char *p)
{
    return ((struct Obj16168 *)p)->f20;
}




















/*
 * Copies the vector at offset 0x34 out. Filed as the witness for ov094 func_021FD1CC.
 */
void func_02051790(char *p, Vec *out)
{
    *out = *(Vec *)(p + 0x34);
}



















/*
 * Stores a vector at offset 0x34. Filed as the witness for ov094 func_021FD1CC.
 */
void func_020517A4(char *p, const Vec *v)
{
    *(Vec *)(p + 0x34) = *v;
}


















/*
 * Copies the three halfwords at offset 0x50 out. Filed as the witness for ov094 func_021FD1CC.
 */
void func_020517B4(char *p, Vec16 *out)
{
    *out = *(Vec16 *)(p + 0x50);
}

















/*
 * Returns the word at offset 0x5c. Filed as the witness for ov094 func_021FD1CC.
 */
int func_020517D0(char *p)
{
    return ((struct Obj16169 *)p)->f5C;
}
















/*
 * Stores the word at offset 0x5c. Filed as the witness for ov094 func_021FD1CC.
 */
void func_020517D8(char *p, int v)
{
    ((struct Obj16170 *)p)->f5C = v;
}















/*
 * Returns the word at offset 0x60. Filed as the witness for ov094 func_021FD1CC.
 */
int func_020517E0(char *p)
{
    return ((struct Obj16171 *)p)->f60;
}














/*
 * Stores the word at offset 0x60. Filed as the witness for ov094 func_021FD1CC.
 */
void func_020517E8(char *p, int v)
{
    ((struct Obj16172 *)p)->f60 = v;
}













/*
 * Returns the word at offset 0x64 as a short. Filed as the witness for ov094 func_021FD1CC.
 */
short func_020517F0(char *p)
{
    return ((struct Obj16173 *)p)->f64;
}












/*
 * Stores the word at offset 0x64. Filed as the witness for ov094 func_021FD1CC.
 */
void func_02051800(char *p, int v)
{
    ((struct Obj16174 *)p)->f64 = v;
}











/*
 * Returns the word at offset 0x68 as a short. Filed as the witness for ov094 func_021FD1CC.
 */
short func_02051808(char *p)
{
    return ((struct Obj16175 *)p)->f68;
}










/*
 * Stores the word at offset 0x68. Filed as the witness for ov094 func_021FD1CC.
 */
void func_02051818(char *p, int v)
{
    ((struct Obj16176 *)p)->f68 = v;
}









/*
 * Returns the word at offset 0x6c as a short. Filed as the witness for ov094 func_021FD1CC.
 */
short func_02051820(char *p)
{
    return ((struct Obj16177 *)p)->f6C;
}








/*
 * Returns the halfword at offset 0x70. Filed as the witness for ov094 func_021FD1CC.
 */
unsigned short func_02051830(char *p)
{
    return ((struct Obj16178 *)p)->f70;
}







/*
 * particle.c (wave 13): the emitter's three-word position at +0x28..+0x30 is
 * the caller's vector plus the vector at +4 of the block the private 3D
 * block's first word names (+0x20 -> +0x00 -> +0x04/+0x08/+0x0C).
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051838.c.txt: 72 against 72 with 10 bytes
 * out via a `volatile` parameter, permuter exhausted at 3000): the caller's
 * vector is a `const VecFx32 *`.  mwccarm lets a load through a const-
 * qualified pointer move above a store through a non-const one, so all three
 * q reads are hoisted to the top in the image's order (r4, r3, r2 -- a
 * descending run the peephole cannot merge into one ldm), while the block's
 * inner pointer is still re-read before each sum because the stores to the
 * emitter may alias it.  No named locals: each component is one statement.
 * The `volatile` spelling only imitated that hoisting and allocated
 * differently; plain non-const spellings keep the q reads in place and merge
 * two of them into an ldm (68 bytes).
 */
void func_02051838(struct ParticleEmitter *e, const VecFx32 *q)
{
    e->pos.x = q->x + e->blk->inner->pos.x;
    e->pos.y = q->y + e->blk->inner->pos.y;
    e->pos.z = q->z + e->blk->inner->pos.z;
}








/*
 * Setter on the same object as its packet-mate src/matched/func_020518AC.c:
 * copies a three-component 16-bit vector into the object's 0x50..0x54
 * triple.  The three loads come out ahead of the three stores, which is the
 * plain field-by-field spelling; a struct assignment would be ldm/stm.
 */
void func_02051880(struct Obj_02051880 *o, const struct Vec3_02051788 *v)
{
    o->x = v->x;
    o->y = v->y;
    o->z = v->z;
}







/*
 * Word setter on the same object as its packet-mate
 * src/matched/func_020518AC.c: stores the argument into field 0x6c.
 */
void func_0205189C(struct Obj_0205189C *o, u32 v)
{
    o->f6c = v;
}







/*
 * Halfword setter on the same object as its packet-mate
 * src/matched/func_020518AC.c: stores the argument into field 0x70.
 */
void func_020518A4(struct Obj_020518A4 *o, u16 v)
{
    o->f70 = v;
}






/*
 * Linear search of the block at obj+0x20 for the first 8-byte entry whose
 * first word is the handler address selected by `kind`, returning that
 * entry's second word (or NULL).  The six handlers are the 3D-rig rows at
 * 0x02057EF8..0x020582CC, all pool words and all attested by the sibling
 * pool at 0x02052DB0.
 *
 * Two tells decide the shape.  Declaring the index BEFORE the count is what
 * puts the count in r4 and the index in lr (declaration-order-decides-which-
 * register-a-local-gets).  And the image's `adds ip, r5, lr, lsl #3` / `beq`
 * pair at +0040 is a redundant null test on the entry pointer: the `adds`
 * form only appears when the source writes `if (e == 0) continue;`, which
 * folds into the address computation.  Without it the switch is four bytes
 * shorter and every branch target shifts.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020518AC.c \
 *       --func func_020518AC --addr 0x020518AC --cc 1.1p1 --arm
 */
void *func_020518AC(void *obj, int kind)
{
    struct Blk *b = *(struct Blk * *)&((struct Obj16187 *)obj)->f20;
    int i;
    int n = b->count;

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++) {
        struct Ent *e = &b->ents[i];
        if (e == 0)
            continue;
        switch (kind) {
        case 0:
            if (e->fn == (void *)func_020582CC)
                return e->data;
            break;
        case 1:
            if (e->fn == (void *)func_02058204)
                return e->data;
            break;
        case 2:
            if (e->fn == (void *)func_02058180)
                return e->data;
            break;
        case 3:
            if (e->fn == (void *)func_020580A8)
                return e->data;
            break;
        case 4:
            if (e->fn == (void *)func_02057F8C)
                return e->data;
            break;
        case 5:
            if (e->fn == (void *)func_02057EF8)
                return e->data;
            break;
        default:
            return 0;
        }
    }
    return 0;
}






/*
 * Copies a 12-byte record into the slot func_020518AC hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020519C4.c \
 *       --func func_020519C4 --addr 0x020519C4 --cc 1.1p1 --arm
 */
void func_020519C4(void *p, struct S12 *q)
{
    struct S12 *r = func_020518AC(p, 2);

    if (r != 0)
        *r = *q;
}






/*
 * The class-3 slot carries only a halfword at +2.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020519E4.c \
 *       --func func_020519E4 --addr 0x020519E4 --cc 1.1p1 --arm
 */
void func_020519E4(void *p, u16 *q)
{
    char *r = func_020518AC(p, 3);

    if (r != 0)
        ((struct Obj16190 *)r)->f2 = *q;
}






/*
 * Same 12-byte copy as func_020519C4, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051A04.c \
 *       --func func_02051A04 --addr 0x02051A04 --cc 1.1p1 --arm
 */
void func_02051A04(void *p, struct S12 *q)
{
    struct S12 *r = func_020518AC(p, 5);

    if (r != 0)
        *r = *q;
}






/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x90/4] = v`. With func_02051A2C (the +0x94 twin) it is the storage
 * setter pair the ov118 functions func_021D6EAC/func_021D6F0C call.
 *
 * Addresses are Black-image addresses.
 */
void func_02051A24(void *p, int v)
{
    ((struct Obj16191 *)p)->f90 = v;
}





/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x94/4] = v`. The +0x94 twin of func_02051A24.
 *
 * Addresses are Black-image addresses.
 */
void func_02051A2C(void *p, int v)
{
    ((struct Obj16192 *)p)->f94 = v;
}





/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte load helper,
 * `return p[0x94/4]`. The getter half of func_02051A2C.
 *
 * Addresses are Black-image addresses.
 */
int func_02051A34(void *p)
{
    return ((struct Obj16193 *)p)->f94;
}




unsigned int func_02051A3C(int a0, int a1, int a2, int a3){ int t0 = func_020614D4((int)a0, (int)a1, (int)0); return ((unsigned int)((t0 << 0x10)) >> 0xd); }





extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);





/*
 * The caller's registered handler (the function pointer in the clact.c global
 * 0x020A8140) is invoked with the two incoming arguments and a literal 0 in
 * r2; r1 is never written, so the callee takes at least two arguments and the
 * third is a constant zero.
 *
 * The result is appended to the current context's u32 table: the count
 * halfword at base+0x25c is loaded once, incremented and stored back, and the
 * value is written to base+0x58+count*4 - the store uses the OLD count, so the
 * table is indexed before the increment.  The return value is the low
 * halfword of the result scaled by eight, which the compiler writes as the
 * fused unequal shift pair lsl #16 / lsr #13 (a u16 cast folded into the
 * multiply, see
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The twin at 0x02051AB8 is the same shape over the parallel table 0x100
 * higher (count at +0x25e, elements at +0x158).
 */
u32 func_02051A54(u32 a, u32 b)
{
    u32 v = g_020A8140(a, b, 0);
    u8 *base = g_02146A88->base;
    u16 n = ((struct Obj11459 *)base)->f25C;

    ((struct Obj11459 *)base)->f25C = n + 1;
    *(u32 *)(base + 0x58 + n * 4) = v;

    return (u16)v * 8;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051AA0.c \
 *       --func func_02051AA0 --addr 0x02051AA0 --cc 1.1p1 --arm
 */
int func_02051AA0(int a, int b)
{
    return (u16)func_020616CC(a, b, 1) << 3;
}





extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);





/*
 * Byte-for-byte the twin of func_02051A54 over the second table: same
 * indirect call through the handler at 0x020A8140 (two arguments forwarded,
 * a literal 0 in r2), same append-and-count shape, but the count halfword is
 * at base+0x25e and the elements at base+0x158, i.e. the parallel table 0x100
 * bytes higher with its own counter.
 */
u32 func_02051AB8(u32 a, u32 b)
{
    u32 v = g_020A8148(a, b, 0);
    u8 *base = g_02146A88->base;
    u16 n = ((struct Obj11460 *)base)->f25E;

    ((struct Obj11460 *)base)->f25E = n + 1;
    *(u32 *)(base + 0x158 + n * 4) = v;

    return (u16)v * 8;
}





/*
 * ARM leaf, seeded 2026-09-27 from the ov195 call site 0x02208954
 * (func_0220887C). Returns the u16 at +8 of its argument.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02051B04(void *res)
{
    return ((struct Obj16194 *)res)->f8;
}





/*
 * Eight-way dispatch on a button-man handler id: each of the eight ids tail
 * calls its own handler and returns that handler's value, and any id above 7
 * falls out of the switch to `return 0;`.  That trailing `return 0;` is what
 * the image has at +0x7C (`mov r0, #0; pop {r3, pc}`) and it is also the
 * addls-skipped target at +0x0C, so the `switch` has no `default:` label at
 * all - writing the arms as bare calls (or with `break`) instead of
 * `return f();` loses those eight bytes and the arms' `pop {r3, pc}` with
 * them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051B0C.c \
 *       --func func_02051B0C --addr 0x02051B0C --cc 1.1p1 --arm
 */
int func_02051B0C(int i)
{
    switch (i) {
    case 0: return (int)func_0207E1F8();
    case 1: return (int)func_0207E24C();
    case 2: return (int)func_0207E2A0();
    case 3: return (int)func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (int)func_0207E2F0();
    case 7: return (int)func_0207E388();
    }
    return 0;
}





void *func_02051B84(u8 *a0, int a1, int a2, int a3)
{
    S02051B84 *r;
    int i = 0;
    unsigned j;

    while (i < 0xff) {
        if (a0[i * 4] == 0xff) {
            break;
        }
        i++;
    }
    r = (S02051B84 *)func_02030734((u16)a3, 0x14, 0, &g_020A7FCC, 0x6b);
    if (r != 0) {
        r->f00 = a0;
        r->f04 = i;
        r->f08 = a1;
        r->f0c = a2;
        r->f10 = (int)func_02030734((u16)a3, i * 4, 0, &g_020A7FCC, 0x73);
        if (r->f10 != 0) {
            for (j = 0; j < i; j++) {
                func_02051C58((void *)(r->f10 + j * 4));
            }
        } else {
            func_020307B0(r);
            r = 0;
        }
    }
    return r;
}





void func_02051C58(void *p0){ ((struct Obj08875 *)p0)->f0 = (unsigned char)0; ((struct Obj08875 *)p0)->f1 = (unsigned char)0; ((struct Obj08875 *)p0)->f2 = (unsigned short)0; }





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051C6C.c \
 *       --func func_02051C6C --addr 0x02051C6C --cc 1.1p1 --arm
 */
void func_02051C6C(void *p)
{
    func_020307B0((void *)((struct Obj16196 *)p)->f10);
    func_020307B0(p);
}




extern s32 (*const g_020A15E8[])(struct Slot *, s32, s32);




/*
 * The per-frame slot refresh: every slot state byte is rewritten to
 * (a == i) or (b == i) by its previous value, then every slot is dispatched
 * through the handler table at 0x020A15E8 and each result other than -1 is
 * forwarded to c->cb(i, v, c->arg).  Returns whether a slot newly took the
 * hover.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 352/352, 19 bytes out for
 * five waves, docs/notes/pkt_02051C88.c.txt): the loop index is
 * `unsigned long`, not u32 (unsigned int).  With u32 the first loop's
 * index and the slots base swap ip / lr over 13 instructions; mwcc colours
 * long and int as different types (the same fact wave 16 found with
 * `long i, j` in 0x02048744).  The unsigned compare against the s32 slot
 * indices is kept, which is what holds the fourth 1 in fp.
 */
s32 func_02051C88(struct Ctx_02051C88 *c)
{
    s32 a;
    s32 b;
    s32 h, sel;
    s32 ret = 0;
    unsigned long i;

    a = 0;
    h = func_02035C38();
    if (h != 0) {
        a = func_02035BA4((const void *)c->f00);
        b = func_02035C08((const void *)c->f00);
        sel = func_02035C60();

        for (i = 0; i < c->n; i++) {
            if (c->slots[i].state != 0) {
                c->slots[i].state = (u8)((a == i) ? 1 : 0);
            } else {
                c->slots[i].state = (u8)((b == i) ? 1 : 0);
                if (c->slots[i].state != 0)
                    ret = 1;
            }
        }
    } else {
        sel = 0;
        for (i = 0; i < c->n; i++)
            c->slots[i].state = (u8)a;
    }

    for (i = 0; i < c->n; i++) {
        s32 v = g_020A15E8[c->slots[i].kind](&c->slots[i], h, sel);
        if (v != -1)
            c->cb((s32)i, v, c->arg);
    }

    return ret;
}




/*
 * The conjunction shares one exit; `*(u8 *)(p+1)` is the armed flag the
 * 0x02051E10 sibling also tests.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051DE8.c \
 *       --func func_02051DE8 --addr 0x02051DE8 --cc 1.1p1 --arm
 */
int func_02051DE8(void *p, int a, int b)
{
    if (((struct Obj04767 *)p)->f1 == 0 || b == 0)
        return -1;
    func_02051E64(p, 1);
    return 0;
}




/*
 * State-machine step over a small ARM struct: if the flag byte at +1 is set,
 * bump the halfword at +2 while it is below 0xFFFF and report state 2;
 * otherwise it clears the second argument's slot through func_02051E64 and
 * reports 1 or 3 depending on whether the incoming second argument was zero.
 * The shared `mov r1, #0` before the compare is the constant both arms pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051E10.c \
 *       --func func_02051E10 --addr 0x02051E10 --cc 1.1p1 --arm
 */
int func_02051E10(char *p, u32 x)
{
    if (((struct Obj04767 *)p)->f1 != 0) {
        u16 v = ((struct Obj04767 *)p)->f2;

        if (v < 0xFFFF)
            ((struct Obj04767 *)p)->f2 = (u16)(v + 1);
        return 2;
    }
    if (x != 0) {
        func_02051E64(p, 0);
        return 3;
    }
    func_02051E64(p, 0);
    return 1;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051E64.c \
 *       --func func_02051E64 --addr 0x02051E64 --cc 1.1p1 --arm
 */
void func_02051E64(void *p, int a)
{
    ((struct Obj04767 *)p)->f0 = (unsigned char)a;
    ((struct Obj04767 *)p)->f2 = 0;
}




/*
 * Scaled 2x2 rotation: convert the angle to a 16-bit turn fraction (mode 1:
 * (ang * 0xFFFF) >> 8; mode 2: degrees, (ang * 0xFFFF) / 360, the umull by
 * 0x6C16C16D with the add-and-halve fix-up), rotate with the sin/cos pair
 * from the shared table at index ang >> 4 (FX_SinIdx/FX_CosIdx shape), then
 * scale by the two vector magnitudes.  EXACT* because the 24-byte leaf that
 * follows at 0x02051F1C (struct copy of three words plus a fourth store) has
 * no label.
 *
 * Wave 9: closed by writing the two conversions as the plain unsigned
 * expressions (the wave-7 note hand-expanded the division and kept a 19-byte
 * register residue) and the table as the extern data symbol; the old
 * "label wall" on MTX_Rot22_/MTX_ScaleApply22 is now carried by the sdk class.
 */
void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode)
{
    if (mode == 1)
        ang = (u16)((ang * 0xFFFF) >> 8);
    else if (mode == 2)
        ang = (u16)((ang * 0xFFFF) / 360);

    MTX_Rot22_(mtx, tbl_020A1B38[((s32)ang >> 4) * 2], tbl_020A1B38[((s32)ang >> 4) * 2 + 1]);
    MTX_ScaleApply22(mtx, mtx, func_0207C778((long int)v1), func_0207C778((long int)v2));
}



void func_02051F1C(struct Ball_02051F1C *dst, struct Vec *src, unsigned radius)
{
    dst->p = *src;
    dst->radius = radius;
}




/*
 * Segment-versus-sphere test: project the ball's centre onto the segment
 * p0 -> dir (t = FX_Div(dot(d, c - p0), dot(d, d)), d = dir - p0); on the
 * segment compare the distance against b->r + seg->pad18, off it compare the
 * distance to the far end and then to p0 against b->r.  Fills a 20-byte
 * { hit, normal, dist } block copied to *out when out is non-null; returns hit.
 * Compiler pin dsi/1.1p1 (a PART 1 math helper of cluster_02051E64).
 *
 * What closed it (wave 9, from the wave-7 note's 72-byte point): the distance
 * is a register local `d` compared at the shared join, and res.d is stored
 * AFTER the limit is loaded (`d = VEC_Mag(..); lim = ..; res.d = d;`).
 * Comparing res.d itself reloads it from the stack at the join.
 */
u32 func_02051F34(struct Seg *seg, struct Ball_02051F34 *b, struct Out *out)
{
    struct Out  res;    /* sp+0x24: res.hit, n, d -- copied out as one block */
    struct Vec3_02051C88 sd;     /* sp+0x18 */
    struct Vec3_02051C88 bc;     /* sp+0x0c */
    struct Vec3_02051C88 tmp;    /* sp+0x00 */
    int t;
    int d;
    int lim;

    res.hit = 0;
    VEC_Subtract(&seg->dir, &seg->p0, &sd);
    VEC_Subtract(&b->c, &seg->p0, &bc);

    t = FX_Div(VEC_DotProduct(&sd, &bc), VEC_DotProduct(&sd, &sd));
    if (t >= 0 && t <= 0x1000) {
        func_020520A4(&sd, t, &sd);
        VEC_Subtract(&sd, &bc, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r + seg->pad18;
        res.d = d;
    } else {
        VEC_Subtract(&b->c, &seg->dir, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
        if (d <= lim) {
            res.hit = 1;
            goto done;
        }
        tmp = bc;
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
    }
    if (d <= lim)
        res.hit = 1;
done:
    if (out != 0) {
        VEC_Normalize(&tmp, &res.n);
        *out = res;
    }
    return res.hit;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205207C.c \
 *       --func func_0205207C --addr 0x0205207C --cc 1.1p1 --arm
 */
void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v)
{
    *(struct S12 *)p = *q;
    *(struct S12 *)(p + 12) = *r;
    ((struct Obj16198 *)p)->f18 = v;
}




/*
 * VEC_MultAdd-style scale: dst = v * s in 1.19.12 fixed point, component by
 * component, with the SDK's own rounding.  Each component is the inlined body
 * of FX_Mul: a 32x32 signed `smull`, +0x800 for round-to-nearest with the
 * carry folded into the high word by `adc`, then the 64-bit >> 12 spelled as
 * `lsr #12` of the low word `orr`ed with `lsl #20` of the high word.  Writing
 * it as a (s64) multiply and shift is what makes the compiler emit exactly
 * that quartet rather than a call to a runtime helper.
 *
 * All three components are computed before any store, which is why the first
 * two land as one `stm r2,{r4,ip}` and only the third takes its own `str`
 * (the source order is x, y, z and the compiler interleaves the three
 * independent multiplies freely).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520A4.c \
 *       --func func_020520A4 --addr 0x020520A4 --cc 1.1p1 --arm
 */
void func_020520A4(const struct Vec3_02051C88 *v, int s, struct Vec3_02051C88 *dst)
{
    dst->x = (int)((((s64)v->x * s) + 0x800) >> 12);
    dst->y = (int)((((s64)v->y * s) + 0x800) >> 12);
    dst->z = (int)((((s64)v->z * s) + 0x800) >> 12);
}




/*
 * Build a 3x3 rotation matrix from three angles, composed X, then Y, then Z.
 * The destination (r3) is used both as the identity seed and as the running
 * accumulator; a 0x24-byte stack scratch holds the per-axis rotation before
 * each MTX_Concat33 folds it in.
 *
 * Each angle feeds the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c): index i = angle >> 4, with
 * sin at tbl[2*i] and cos at tbl[2*i+1].  The `asr #4` is a shift, not a
 * division, and the arguments are signed, which is what makes `ldrsh` with a
 * register offset the load (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * The X rotation is applied straight onto the identity in the destination,
 * with no scratch; the Y and Z rotations each build into the stack scratch and
 * are folded in by MTX_Concat33(dst, &tmp, dst).  Both Concat33 calls take the
 * destination as the LEFT operand: swapping the last one to
 * MTX_Concat33(&tmp, dst, dst) is byte-correct everywhere except the two
 * `mov` bytes at +00A4/+00A8, the only residue the whole function had.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520FC.c \
 *       --func func_020520FC --addr 0x020520FC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst)
{
    struct Mtx33 tmp;
    int i;

    MTX_Identity33_(dst);

    i = ax >> 4;
    MTX_RotX33_(dst, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    i = ay >> 4;
    MTX_RotY33_(&tmp, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);

    i = az >> 4;
    MTX_RotZ33_(&tmp, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);
}




/*
 * Turn a direction vector into a look-at rotation matrix: pitch about X, yaw
 * about Y, composed into the caller's 3x3.
 *
 * The horizontal run is measured by flattening a copy of the vector: the whole
 * 12-byte vector is copied to a stack scratch with one ldm/stm pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), its y component is zeroed,
 * and VEC_Mag of that gives the run.  Pitch is then FX_Atan2Idx(-v->y, run)
 * and yaw is FX_Atan2Idx(v->x, v->z) - note the argument order is (y, x), the
 * SDK's own, and the pitch numerator carries the `rsb r0, r2, #0` negation.
 *
 * Both angle indices feed the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c) at i = angle >> 4, sin at
 * tbl[2*i] and cos at tbl[2*i+1], exactly as in func_020520FC next door.
 *
 * Declaration order is the whole difference between 184 correct bytes and four
 * wrong ones: the frame lays `flat` at sp+0x48, `mx` at sp+0x24 and `my` at
 * sp+0x00, so the locals must be declared flat, mx, my - the later declaration
 * takes the LOWER stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md).  Declaring my, mx,
 * flat reproduces every instruction and misses only the three `add rN, sp, #k`
 * immediates and the `str r1, [sp, #0x4c]` offset.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020521BC.c \
 *       --func func_020521BC --addr 0x020521BC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void func_020521BC(const struct Vec3_02051C88 *v, struct Mtx33 *dst)
{
    struct Vec3_02051C88  flat;
    struct Mtx33 mx;
    struct Mtx33 my;
    int          i;
    int          run;

    flat = *v;
    flat.y = 0;
    run = VEC_Mag(&flat);

    i = FX_Atan2Idx(-v->y, run) >> 4;
    MTX_RotX33_(&mx, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    i = FX_Atan2Idx(v->x, v->z) >> 4;
    MTX_RotY33_(&my, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    MTX_Concat33(&mx, &my, dst);
}



/*
 * Convert a run of n wide characters at `a` into the narrow buffer at `b`,
 * stopping early when the converter raises its flag.  func_020522E4 is the
 * per-character encoder next door; it returns 1 when it wrote two bytes and
 * something else when it wrote one, and it reports "stop" by storing 1 into
 * the scratch word it is handed.
 *
 * Four declaration-level levers carry this function, three of them measured
 * by an earlier lane (docs/notes/pkt_02052274.c.txt) and the fourth the one
 * that finally closed it:
 *
 *  1. BOTH cursors are initialised BEFORE the `n == 0` guard.  That is what
 *     gives the original its nine-register push and `sub sp, sp, #4` pad;
 *     guard-first drops to eight callee-saved registers and 92 bytes.
 *  2. The scratch word is reset INSIDE the loop from a separate zero-valued
 *     local `z`, not once outside: `scratch = z;` is the `mov r5, r6` /
 *     `str r5, [sp]` pair.
 *  3. `i++` sits BEFORE the `scratch == 1` early return, not after it.
 *  4. `&scratch` is written INLINE at the call, NOT bound to a `u32 *p`
 *     hoisted above the loop.  With the pointer local, the scratch pointer
 *     and the zero seed trade r4 and r5 -- eight bytes out, and a residue no
 *     permuter mutation moves (164 single mutations tried, none improved,
 *     and ten hand spellings before that).  Written inline, the compiler
 *     materialises the seed first and colours it r5 exactly as the image
 *     does.  This is the same lever that closed func_02052770 in this
 *     cluster: hoisting an address-of into a named local gives that value
 *     the lower colour and displaces the values the image wanted there.
 *
 * Unlike most of this cluster this row is dsi/1.1p1, not the 1.2 front end:
 * under ../1.2/sp2 the same C compiles to 132 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052274.c \
 *       --func func_02052274 --addr 0x02052274 --cc 1.1p1 --arm
 */
void func_02052274(u8 *a, u8 *b, u32 n)
{
    u32 scratch;
    u32 z;
    u32 i;
    u32 j;

    i = 0;
    j = 0;
    if (n == 0)
        return;
    z = i;
    do {
        scratch = z;
        if (func_020522E4((u16 *)(a + i * 2), (char *)(b + j), &scratch) == 1)
            j += 2;
        else
            j += 1;
        i++;
        if (scratch == 1)
            return;
    } while (i < n);
}



/*
 * The per-character encoder behind func_02052274: one UCS-2 code unit to
 * Shift-JIS.  The terminator (func_02045A98's value) writes a NUL and raises
 * *stop; printable ASCII is copied; hiragana, both katakana runs and the
 * full-width A-Z, a-z and 0-9 are offset into their Shift-JIS rows and
 * written high byte first; the long-vowel mark, U+8140 (passed through as the
 * SJIS ideographic space), and the two gender signs are special-cased; any
 * other code writes '?'.  Returns 1 when two bytes were written.
 *
 * Levers: dst is plain (signed) char -- the 0x81 lead byte is `mvn r1,#0x7e`
 * and the trail bytes 0x89/0x8a are derived from it by `add` -- and the
 * result `two` is declared BEFORE the character (declaration order decides
 * the r4/r5 colours).  dsi/1.1p1; 1.2 and 2.0 are 170-220 bytes longer.
 */
int func_020522E4(u16 *src, char *dst, u32 *stop)
{
    int two = 0;
    u16 c = *src;
    u16 v;

    if (c == func_02045A98()) {
        *dst = 0;
        if (stop != 0)
            *stop = 1;
    } else if (c >= 0x20 && c <= 0x7e) {
        *dst = c;
    } else if (c >= 0x3041 && c <= 0x3093) {
        v = c + 0x525E;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30A1 && c <= 0x30DF) {
        v = c + 0x529F;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30E0 && c <= 0x30F3) {
        v = c + 0x52A0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF21 && c <= 0xFF3A) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF41 && c <= 0xFF5A) {
        v = c - 0x7CC0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF10 && c <= 0xFF19) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c == 0x30FC) {
        dst[0] = 0x81;
        dst[1] = 0x5B;
        two = 1;
    } else if (c == 0x8140) {
        dst[0] = 0x81;
        dst[1] = 0x40;
        two = 1;
    } else if (c == 0x2642) {
        dst[0] = 0x81;
        dst[1] = 0x89;
        two = 1;
    } else if (c == 0x2640) {
        dst[0] = 0x81;
        dst[1] = 0x8A;
        two = 1;
    } else {
        *dst = '?';
    }
    return two;
}
