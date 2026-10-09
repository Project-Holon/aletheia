/*
 * file:     fldmmdl_p01.c
 * unit:     yes
 * function: func_0216BF38, func_0216BF74, func_0216BF9C, func_0216BFD4, func_0216C028, func_0216C0A4, func_0216C0C0, func_0216C0D4, func_0216C0E4, func_0216C0E8, func_0216C204, func_0216C270, func_0216C280, func_0216C2A4
 * address:  0x0216BF38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200C38C 0x0200C38C thumb
 *   d_02172508 0x02172508 data a4
 *   func_0200C39C 0x0200C39C thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045838  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020114D0  0x020114D0  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02011610  0x02011610  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02011590  0x02011590  thumb
 *   func_02011558  0x02011558  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0216C44C  0x0216C44C  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   d_02172528     0x02172528  data  ov010  a4
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj03544.h"
#include "../../matched/include/Obj02352.h"
#include "../../matched/include/Obj17766.h"
#include "../../matched/include/Obj01029.h"
#include "../../matched/include/Obj17767.h"
#include "../../matched/include/Obj17768.h"

struct Big;
struct Blk38;
struct Blk34;
struct Sub0200852CObj;
struct U16Vec;
struct Evt;
struct IcaAnime;
struct S0201235C;
struct Rec12;
struct Obj00020;
struct Desc;
struct Obj;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32_0216BF38;

typedef int s32_0216C0E8;

typedef s32_0216C0E8 fx32_0216BF38;

typedef struct VecFx32 {
    fx32_0216BF38 x;
    fx32_0216BF38 y;
    fx32_0216BF38 z;
} VecFx32;

typedef struct Pos {
    u32 f00;
    u32 f04;
    u32 f08;
} Pos;

typedef struct Work_0216C0E8 {
    void *sys;          /* 0x00 */
    void *field;        /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
    u8 pad14[4];
    u8 f18[0x60 - 0x18];/* 0x18 */
    void *f60;          /* 0x60 */
} Work_0216C0E8;

typedef struct B32 { int w[8]; } B32;

typedef struct Work_0216C270 {
    u8 pad00[0x10];
    void *anim;         /* 0x10 */
} Work_0216C270;

typedef signed int     s32_0216C270;

typedef int s32_0216C2A4;

typedef s32_0216C2A4 fx32_0216C2A4;

typedef struct Work {
    u8 pad00[8];
    void *field;        /* 0x08 */
} Work;

extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern unsigned int func_02159B10(void *, void *);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern u8 func_0200D468(struct Blk38 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200C38C(struct Blk34 *p, s32_0216BF38 i, u32 v);
extern u32 func_0200C39C(struct Blk34 *p, s32_0216BF38 i);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_02082BCC(void *, int, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_02045808();
extern int func_020307B0(void *);
extern void func_0218FEA4(void *p);
extern void func_0218FE78(void *p, void *q);
extern int func_0218FF00(u32 a);
extern int func_021C6E48(void *p);
extern void func_0218FE98(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_020114D0(u32 heap, u32 a1, u32 a2);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 func_02011610(struct IcaAnime *anim, struct Rec12 *out);
extern int func_02188D2C(int *);
extern VecFx32 *func_021BE480(void *p, int a, int b);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern u32 func_02011590(struct IcaAnime *p, s32_0216C0E8 v);
extern void func_02011558(struct IcaAnime *p);
extern void *func_021BE8D4(void *, void *, u32, u32);
extern void *func_021854B0(void *p, void *q, u32 id, Pos *pos, u32 flag);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_0216C44C(void *sys, void *field);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern struct Desc *func_020122C0(void *, void *, void *, unsigned int);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188C58(void *p);
extern unsigned int func_02188D38(u8 *p);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, unsigned int v);
int func_0216BF38(int a0, int a1);
void func_0216BF74(void *a, int i, void *b);
int func_0216BF9C(void *a, int i, void *b);
int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0);
int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
int func_0216C0C0(int a0);
void func_0216C0D4(int *p, int a1);
int func_0216C0E4(int *p);
int func_0216C0E8(void *evt, u32 *state, Work_0216C0E8 *w);
int func_0216C204(void *a, u8 *b);
int func_0216C270(Work_0216C270 *w);
void *func_0216C280(void *p);
void func_0216C2A4(Work *w);
extern const u32 d_02172508[];
extern char d_02172A60[];
extern B32 d_02172528;





int func_0216BF38(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    p = func_0215A5E4((void *)a0);
loc_0216BF44:
    p = func_02012EBC((struct Big *)p);
loc_0216BF48:
    t7 = func_0200D418(p);
loc_0216BF4C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216BF56:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159AE8((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_0216BF62:
t5 = a0 + 0;
a1 = t4 + 0;
    a0 = func_0200D468(t7, a1);
loc_0216BF6C:
*(u16 *)&((struct Obj00005 *)((char *)t5))->f0 = a0;
a0 = 0;
    return a0;}




void func_0216BF74(void *a, int i, void *b) {
    if(i<8) func_0200C38C(a,i,func_02008530(b)^*(const u32 *)((u32)d_02172508+(u32)i*4));
}




/*
 * lever: named second call-result local preserves the original comparison registers.
 */
int func_0216BF9C(void *a, int i, void *b) {
    u32 v; u32 x;
    if(i>=8) return 0;
    v=func_02008530(b);
    x=func_0200C39C(a,i);
    if((x^v)==*(const u32 *)((u32)d_02172508+(u32)i*4)) return 1;
    return 0;
}





/*
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. func_02045838 takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 */
int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x37);
    func_02082BCC(p, 0, 0x2c);
    p[0] = a1;
    p[6] = s0;
    ((struct Obj03544 *)p)->f4 = a2;
    ((struct Obj03544 *)p)->f6 = a3;
    p[10] = s2;
    p[8] = (int)func_020457B0(0xb, a0);
    if (s1)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)s1);
    return p;
}





/*
 * The heap id is a u16, as in func_0216BFD4; that keeps its entry spill
 * at the front of the prologue.
 */
int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x59);
    func_02082BCC(p, 0, 0x2c);
    p[0] = 1;
    p[6] = a2;
    p[2] = a1;
    p[10] = s0;
    if (a1) {
        int t;
        ((struct Obj02352 *)p)->f4 = func_02017E1C((void *)a1, 5, 0);
        t = func_02017E1C((void *)a1, 0x6f, 0);
        ((struct Obj02352 *)p)->f6 = (func_02017E1C((void *)a1, 0x6e, 0) << 8) | t;
    }
    p[8] = (int)func_020457B0(0xb, a0);
    if (a3)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)a3);
    return p;
}




int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h) {
    int *p;
    p = func_0216C028(a,b,c,d,h);
    p[3]=e; p[4]=f; p[5]=g;
    return p;
}





int func_0216C0C0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj17766 *)t4)->f20;
    a0 = func_02045808(a0);
loc_0216C0CA:
a0 = t4 + 0;
    a0 = func_020307B0((void *)a0);
loc_0216C0D0:
    return a0;}





void func_0216C0D4(int *p, int a1)
{
    func_02045838((struct U16Vec *)a1, (struct U16Vec *)p[8]);
}




int func_0216C0E4(int *p)
{
    return p[7];
}





/*
 * Eight-state proc of the field event beside func_0216C2FC: run the
 * ov021 camera move, animate the actor to the ground, then push the next
 * screens. First draft.
 */
int func_0216C0E8(void *evt, u32 *state, Work_0216C0E8 *w)
{
    VecFx32 cur;
    VecFx32 v;
    Pos pos;
    void *sys = w->sys;
    void *field = w->field;
    void *f0c = w->f0c;
    void *q;

    switch (*state) {
    case 0:
        func_0218FEA4(w->f60);
        func_0218FE78(w->f08, w->f18);
        func_0218FF00((u32)w->f60);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(f0c) != 0) {
            func_0218FE98(w->f60);
            (*state)++;
        }
        break;
    case 2:
        w->anim = func_020114D0(func_02188C84(field), 0x9D, 0x18);
        func_0200616C((void *)1953, func_02006148(1953));
        (*state)++;
        break;
    case 3:
        func_02011610(w->anim, (struct Rec12 *)&cur);
        func_021BE480((void *)func_02188D2C(field), 0, 0)->y = cur.y;
        q = func_02188CB4(field);
        func_021A3038(q, &v);
        v.y = cur.y;
        func_021A3044(q, &v);
        if (func_02011590(w->anim, 0x1000) != 0) {
            func_02011558(w->anim);
            (*state)++;
        }
        break;
    case 4:
        func_02012374(evt, func_021BE8D4(sys, field, 0, 0));
        (*state)++;
        break;
    case 5:
        pos.f00 = 0;
        pos.f04 = 0;
        pos.f08 = 0;
        func_02012374(evt, func_021854B0(sys, field, 0x8A, &pos, 1));
        (*state)++;
        break;
    case 6:
        func_0201235C(evt, func_0216C44C(sys, field));
        (*state)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}





int func_0216C204(void *a, u8 *b)
{
    int r = (int)func_020122C0(a, 0, (void *)func_0216C0E8, 0x64);
    int *p = func_020124E8((struct Obj *)r);
    p[0] = (int)a;
    p[1] = (int)b;
    p[4] = 0;
    p[2] = (int)func_02188C58((void *)b);
    p[3] = func_02188D38(b);
    p[5] = 0x14;
    *(B32 *)(p + 14) = d_02172528;
    p[22] = 1;
    p[23] = 1;
    p[24] = (int)func_0218FE80((void *)b);
    func_0218FEA0((u8 *)p[24], (unsigned int)(p + 5));
    return r;
}





int func_0216C270(Work_0216C270 *w)
{
    return func_02011590(w->anim, 0x1000);
}



/*
 * unblocked: func_021BE480 (ov021, unlabelled leaf) matched bottom-up and
 *           filed as pkt_021BE480; the `ov021` token resolves the +0x18
 *           call as `matched, overlay`.  func_02188D2C was already matched.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 */
void *func_0216C280(void *p)
{
    char v[12];
    void *q;

    func_02011610(((struct Obj01029 *)p)->f10, (struct Rec12 *)v);
    q = (void *)func_021BE480((char *)func_02188D2C(((struct Obj01029 *)p)->f8), 0, 0);
    ((struct Obj17768 *)q)->f4 = ((struct Obj17767 *)v)->f4;

    return q;
}


#pragma opt_propagation off

/*
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object.
 *
 * pass 6 2026-10-06 P6L05: closed from a capture of the compiler's register
 * colouring (debugger break at the colour select step of mwccarm). The
 * graph showed y with a long live range (stored after the x snap) was
 * coloured early and took r3. Storing v.y first makes y short-lived, so it
 * is coloured late, after x; reading z, y, x (x snapped first, its load
 * hoisted) gives the image's load order x, z, y. EXACT in c99 and c.
 */
void func_0216C2A4(Work *w)
{
    VecFx32 v;
    const VecFx32 *pos;
    void *q;
    fx32_0216C2A4 x;
    fx32_0216C2A4 y;
    fx32_0216C2A4 z;
    fx32_0216C2A4 k;

    pos = func_021BE480((void *)func_02188D2C(w->field), 0, 0);
    q = func_02188CB4(w->field);
    z = pos->z;
    y = pos->y;
    x = pos->x;
    k = 0x20000;
    z = z + k;
    v.y = y;
    v.x = (((x >> 12) / 16) << 16) + 0x8000;
    v.z = (((z >> 12) / 16) << 16) + 0x8000;
    func_021A3044(q, &v);
}

#pragma opt_propagation reset
