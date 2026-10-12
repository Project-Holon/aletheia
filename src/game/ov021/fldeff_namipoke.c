/*
 * file:     fldeff_namipoke.c
 * unit:     yes
 * function: func_021AC810, func_021AC8E4, func_021AC900, func_021AC9D4, func_021AC9D8, func_021ACA38, func_021ACA5C, func_021ACA70, func_021ACB0C, func_021ACB38, func_021ACBB8, func_021ACBC8, func_021ACBE4, func_021ACC04, func_021ACC3C, func_021ACCAC, func_021ACCB0, func_021ACDC4, func_021ACFD8, func_021ACFF8, func_021AD274, func_021AD3D4, func_021AD3FC, func_021AD410, func_021AD530, func_021AD564, func_021AD598, func_021AD5CC, func_021AD5E0, func_021AD6A4, func_021AD6B8, func_021AD738, func_021AD758, func_021AD764, func_021AD770, func_021AD77C, func_021AD788, func_021AD794, func_021AD7A0, func_021AD7B4, func_021AD7E4, func_021AD82C, func_021AD8A4, func_021AD8DC, func_021AD96C, func_021ADA1C, func_021ADAAC, func_021ADB4C, func_021ADB5C, func_021ADB6C, func_021ADBAC, func_021ADBB0, func_021ADC04
 * address:  0x021AC810
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   d_021DE050     0x021DE050  data  a4
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_020508EC  0x020508EC  arm
 *   func_0205085C  0x0205085C  arm
 *   d_021D90C0     0x021D90C0  data
 *   d_021D90C8     0x021D90C8  data  a2
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   d_021DE080  0x021DE080  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D915C     0x021D915C  data  a4
 *   d_021D9184     0x021D9184  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   d_021D9198     0x021D9198  data  a2
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021D91C8     0x021D91C8  data  a4
 *   d_021D91B0     0x021D91B0  data  a2
 *   func_021C6678  0x021C6678  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_020521BC  0x020521BC  arm
 *   d_021D9170  0x021D9170  data
 *   d_021D91F8     0x021D91F8  data  a4
 *   func_021C6694  0x021C6694  thumb  ov021
 *   d_021DE0E8  0x021DE0E8  data
 *   d_021DE094     0x021DE094  data  a2
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_021ABE2C  0x021ABE2C  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   d_021D9238     0x021D9238  data  a1
 *   d_021D9240     0x021D9240  data  a4
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   func_02047828  0x02047828  arm
 *   func_021AAA4C  0x021AAA4C  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   d_021D9234     0x021D9234  data   a1
 */
#include "../../matched/include/Obj19872.h"
#include "../../matched/include/Obj05039.h"
#include "../../matched/include/Obj19874.h"
#include "../../matched/include/Obj18088.h"
#include "../../matched/include/Obj12097.h"
#include "../../matched/include/Obj05043.h"
#include "../../matched/include/Obj12797.h"
#include "../../matched/include/Obj19888.h"

struct BbActDesc;
struct BbActSys;
struct X_021ACA5C;
struct Mtx33;
struct Actor;
struct VecFx32;
struct E;
struct Vec3;
struct Desc;
struct P_021ACA38;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct A;
struct ModelSet;
struct Tagged;
struct AnmCtl;
struct SoundSys2;
struct Self;
struct BigObj;
typedef struct V3 { int x, y, z; } V3;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Blk_021AC810 { u32 w[9]; } Blk_021AC810;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct B_021AC810 {
    u32 f0;
    Blk_021AC810 blk;
    u16 f28[4];
    u16 f30;
} B_021AC810;

typedef signed short s16;

typedef signed char s8;

typedef struct P_021ACA38 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
} P_021ACA38;

typedef signed int s32;

typedef struct X_021ACA5C {
    u32 f0;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    u16 hc;
} X_021ACA5C;

typedef struct Arg_021ACB38 { u32 a; u32 b; u16 c, d, e; } Arg_021ACB38;

typedef struct E { int f0; int f4; int f8; } E;

typedef struct Blk_021AC9D8 { u32 w[7]; } Blk_021AC9D8;

typedef struct Inner_021AC810 { u16 a; u16 b; u8 pad[0x18]; u16 c; u16 pad2; u32 d, e, f; } Inner_021AC810;

typedef struct B_021AC9D8 {
    u8 pad0[9];
    u8 f9;
    u8 pad1[2];
    u16 fc;
    u8 pad2[2];
    u32 f10;
    u32 f14;
    u16 f18;
    u8 pad3[2];
    Blk_021AC9D8 blk;
    Inner_021AC810 in;
} B_021AC9D8;

typedef struct Ang { u16 x, y, z; } Ang;

typedef struct AngTbl { Ang e[4]; } AngTbl;

typedef struct PosTbl { V3 e[4]; } PosTbl;

typedef struct Node_021ACCB0 {
    V3 pos;
    V3 scale;
    u8 mtx[0x24];
} Node_021ACCB0;

typedef struct Inner {
    u16 a;
    u16 b;
    V3 p4;
    V3 p10;
    u16 c;
    u16 pad;
    V3 scale;
    V3 pos;
} Inner;

typedef struct B_021ACDC4 {
    u8 pad0[9];
    u8 f9;
    u8 fa;
    u8 pad1;
    u16 fc;
    u8 pad2[2];
    s32 f10;
    s32 f14;
    u16 f18;
    u8 pad3[2];
    u32 *f1c;
    u32 f20;
    u8 pad4[0x14];
    Inner in;
} B_021ACDC4;

typedef struct Y { u8 pad[0x18]; u16 h18; u16 pad1a; u32 *f1c; u8 pad20[0x34]; u16 h54; } Y;


typedef struct B_021ACFF8 {
    u8 pad0[9];
    u8 f9;
    u8 fa;
    u8 pad1;
    u16 fc;
    u8 pad2[2];
    s32 f10;
    s32 f14;
    u8 pad3[4];
    u32 *f1c;
    u32 f20;
    u8 pad4[0x14];
    Inner in;
} B_021ACFF8;

typedef struct M33 { s32 m[9]; } M33;

typedef struct Node_021AD274 {
    V3 pos;
    V3 scale;
    M33 mtx;
} Node_021AD274;

typedef struct Inner_021AD274 {
    u16 a;
    u16 b;
    u8 pad[0x18];
    u16 c;
    u16 pad2;
    V3 scale;
    V3 pos;
} Inner_021AD274;

typedef struct B_021AD274 {
    u8 pad0[0xc];
    u16 fc;
    u8 pad1[0xa];
    u16 f18;
    u8 pad2[2];
    u32 *f1c;
    u32 f20;
    u8 pad3[0x14];
    Inner_021AD274 in;
} B_021AD274;




typedef struct T5 {
    V3 v[5];
} T5;

typedef struct S16_021AD5E0 {
    int a, b, c, d;
} S16_021AD5E0;

typedef struct Tab {
    int f0;
    u16 h4, h6, h8, ha, hc;
} Tab;

typedef struct Obj_021AC810 {
    V3 v;
    int padc;
    u16 h10;
    u16 pad12;
    S16_021AD5E0 s14;
} Obj_021AC810;

typedef struct S16_021AD6B8 {
    int a;
    int *b;
    int c, d;
} S16_021AD6B8;

typedef struct Obj_021AD6B8 {
    V3 v;
    int padc;
    u16 h10;
    u16 pad12;
    S16_021AD6B8 s14;
} Obj_021AD6B8;

typedef struct S {
    int pad0[4];
    u16 h10;
    u16 pad12;
    int pad14;
    int *p18;
} S;

typedef struct Rec {
    u16 h[7];
} Rec;

typedef struct A {
    u32 f0;
    u32 f4[4];
    u32 f14;
} A;

typedef struct ModelDesc {
    u8 n;
    u8 lo : 3;
    u8 mid : 3;
    u8 b6 : 1;
    u8 b7 : 1;
    u16 pad2;
    u16 h4;
    u16 tab[4];
} ModelDesc;

typedef struct ModelSet {
    int f0;
    int f4;
    int f8[4];
    union {
        int f18[28];
        struct {
            int pad[4];
            A rec[4];
        } r;
    } u;
    ModelDesc desc;
} ModelSet;

typedef struct L {
    int f0;
    int f4;
    void *f8;
    int fc;
    u16 h10;
    u16 h12;
    int f14;
    u8 b18;
    u8 pad19[3];
    int f1c;
    int f20;
    int f24;
} L;

typedef struct S40 {
    int w[10];
} S40;

typedef struct Dst {
    u16 h0;
    u16 pad2;
    S40 s4;
    int pad2c[2];
    int f34;
} Dst;

extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern void func_021AC1CC(u32 a, void *v);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern int func_021AC1A0(u32 a);
extern void func_021AC178(u32 a);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern int func_0216E1C4(int a0, int a1);
extern u16 func_0216D608(void *p);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void func_0205085C(void *p, int idx, u32 v);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 *a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
extern u32 func_021C6628(u32 a, u32 b);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern u16 func_0216D588(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D55C(int a0, int a1);
extern u8 func_021ABFA8(u32 a, void *b, void *c, u32 d, void *e, u32 f);
extern int func_021AC1E0(u32 a);
extern int func_021C6658(u32 a, u32 b);
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_021AC1B8(u32 a, void *n);
extern void func_021C6678(u32 a, u32 b, u32 c);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D598(void *p);
extern void func_0216D8E0(u32 a, V3 *v);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_02197CCC(u8 *p, s32 *out);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_021C67F4(u32 a, u32 b);
extern void func_0219E784(u32 a, u32 b, s16 *out);
extern void func_0207CDB8(s16 *a, s16 *b);
extern s32 func_0207CF3C(const V3 *a, const V3 *b);
extern void func_020521BC(const struct Vec3 *v, struct Mtx33 *dst);
extern int func_021C6694(u32 *a, int idx, int v);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern u8 func_021ABE28(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern u8 func_021ABE2C(u8 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
extern unsigned int func_021ABE14(u8 *p);
extern unsigned int func_02188CFC(u8 *p);
extern void *func_02082BCC(void *p, u8 v, unsigned n);
extern void *func_02188C7C(unsigned char *p);
extern int func_02188BE8(void *a);
extern int func_02047910(void *a, int idx, int amount);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern int func_021AAA4C(struct Self *self, short *out);
extern u16 func_0209C0A4(int a, int b);
extern unsigned int func_02012A30(const struct BigObj *p);
extern void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
void func_021AC810(u32 a, B_021AC810 *b);
void func_021AC8E4(u32 a, B_021AC810 *b);
void func_021AC900(u32 a, B_021AC810 *b);
void func_021AC9D4(void);
int func_021AC9D8(u8 *p);
P_021ACA38 *func_021ACA38(u32 a, int heap);
void func_021ACA5C(u32 a, u8 *p);
void func_021ACA70(u32 *a);
void func_021ACB0C(X_021ACA5C *x);
void func_021ACB38(u32 a, u32 b, V3 *c, u32 d, u32 e);
void func_021ACBB8(u32 a, u8 v);
void func_021ACBC8(u32 a, int v);
int func_021ACBE4(int n);
int func_021ACC04(E *a, E *b, u32 mode);
void func_021ACC3C(u32 a, B_021AC9D8 *b);
void func_021ACCAC(void);
void func_021ACCB0(u32 a, B_021ACDC4 *b);
void func_021ACDC4(u32 a, B_021ACDC4 *b);
void func_021ACFD8(u32 a, Y *y);
void func_021ACFF8(u32 a, B_021ACFF8 *b);
void func_021AD274(u32 a, B_021AD274 *b);
P_021ACA38 *func_021AD3D4(u32 a, int heap);
void func_021AD3FC(u32 a, u8 *p);
void func_021AD410(u32 *a);
void func_021AD530(X_021ACA5C *x);
void func_021AD564(u32 a, u32 b, u32 c);
void func_021AD598(u32 a, u32 b, u32 c);
int func_021AD5CC(u32 a);
void func_021AD5E0(int a, int *bp);
int func_021AD6A4(u32 a, u32 b, u32 c, u32 d);
void func_021AD6B8(int a, Obj_021AD6B8 *b);
void func_021AD738(int a, S *s);
void *func_021AD758(u32 a, int heap);
void *func_021AD764(u32 a, int heap);
void *func_021AD770(u32 a, int heap);
void *func_021AD77C(u32 a, int heap);
void *func_021AD788(u32 a, int heap);
void *func_021AD794(u32 a, int heap);
void func_021AD7A0(u32 a, u8 *p);
P_021ACA38 *func_021AD7B4(u32 a, int heap, u32 c);
void func_021AD7E4(ModelSet *a, u32 b);
void func_021AD82C(A *a, ModelSet *b, int c);
void func_021AD8A4(A *z, ModelSet *w);
void func_021AD8DC(ModelSet *a, ModelDesc *d, int c);
void func_021AD96C(ModelSet *a, ModelDesc *d, int c);
void func_021ADA1C(ModelSet *a);
u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f);
void func_021ADB4C(u32 a, int v);
void func_021ADB5C(int a, int v);
void func_021ADB6C(int a, Dst *b);
void func_021ADBAC(void);
void func_021ADBB0(int a, u8 *w);
void func_021ADC04(u8 *w, u8 *o);
extern u32 d_021DE050[];
extern u8 d_021D90C0[];
extern u16 d_021D90C8[];
extern char d_021DE080[];
extern u8 d_021D915C[];
extern u8 d_021D9184[];
extern AngTbl d_021D9198;
extern PosTbl d_021D91C8;
extern AngTbl d_021D91B0;
extern u8 d_021D9170[];
extern T5 d_021D91F8;
extern char d_021DE0E8[];
extern ModelDesc d_021DE094[];
extern u8 d_021D9238[];
extern int d_021D9240[];
extern u8 d_021D9234[];









/*
 * Addresses are Black-image addresses.
 */
void func_021AC810(u32 a, B_021AC810 *b)
{
    u8 *p = (u8 *)func_021AC1AC(a);
    Desc s;
    u16 idx;
    u32 h;
    u16 r;

    b->blk = *(Blk_021AC810 *)p;
    func_0216E1A4(((struct Obj19872 *)p)->f4, (int)b->f28);
    func_021AC1CC(a, p + 0x14);
    idx = b->blk.w[8];
    s.slot = *(u16 *)(b->blk.w[0] + idx * 2 + 8);
    s.v12 = 0x2000;
    s.v14 = 0x2000;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.pos = *(V3 *)(p + 0x14);
    s.f1c = 0;
    s.f20 = (u32)b;
    h = *(u32 *)(b->blk.w[0] + 4);
    b->f30 = func_02050340((struct BbActSys *)h, 0, (const struct BbActDesc *)(&s), 1, 0);
    if (b->f30 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)h, b->f30, d_021DE050[idx], 1);
    r = b->f30;
    func_0205082C((void *)h, r, 0);
    func_020507F0((void *)h, r, 1);
    if (func_021AC1A0(a) == 0)
        b->f0 = 1;
    func_021AC178(a);
}









void func_021AC8E4(u32 a, B_021AC810 *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);

    if (b->f30 != 0xFFFF)
        func_02050468((struct BbActSys *)h, b->f30, 1);
}








/*
 * Compiled 212 of a 216-byte extent: the follower at 0x021AC9D4 is an
 * unlabelled `bx lr` stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC900(u32 a, B_021AC810 *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);
    u32 m;
    u16 tmp;

    switch (b->f0) {
    case 0:
        if (d_021D90C0[b->blk.w[8]] == 1) {
            m = b->blk.w[1];
            if (func_0216E1C4(m, (int)b->f28) == 1 && func_021AC9D8((u8 *)b) == 0 && func_0216D608((void *)m) == 1) {
                func_021AC154(a);
                return;
            }
        }
        if (func_020508EC((u8 *)h, b->f30, &tmp) != 0)
            b->f0++;
        break;
    case 1:
        if (func_0216E1C4(b->blk.w[1], (int)b->f28) == 0) {
            func_021AC154(a);
            return;
        }
        func_0205085C((void *)h, b->f30, d_021D90C8[b->blk.w[8]]);
        b->f0++;
        break;
    case 2:
        b->f0++;
    case 3:
        if (func_0216E1C4(b->blk.w[1], (int)b->f28) == 0) {
            func_021AC154(a);
            return;
        }
        if (func_021AC9D8((u8 *)b) == 0)
            func_021AC154(a);
        break;
    }
}






void func_021AC9D4(void) {}










int func_021AC9D8(u8 *p)
{
    u32 a = ((struct Obj05039 *)p)->f8;
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 f = d_021D90C0[((struct Obj05039 *)p)->f24];
    if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
        goto yes;
    if (f == 0 && func_0216D608((void *)a) == 0) {
        x = func_0216D804((void *)a);
        y = func_0216D81C((void *)a);
        if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
            return 1;
    }
    return 0;
yes:
    return 1;
}










P_021ACA38 *func_021ACA38(u32 a, int heap)
{
    P_021ACA38 *p;

    p = (P_021ACA38 *)func_02030734(heap, 0xc, 1, d_021DE080, 0xac);
    p->f0 = a;
    func_021ACA70((u32 *)p);
    return p;
}










/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ACA5C(u32 a, u8 *p)
{
    func_021ACB0C((struct X_021ACA5C *)p);
    func_020307B0(p);
}










void func_021ACA70(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r4 = func_021ABE18((u8 *)a[0]);
    u32 r6 = func_021ABE24((u8 *)a[0]);
    func_021C6AE0(buf);
    func_021C6AF0((u32)buf, r6, 0x31);
    h[2] = func_021C6574(r4, (u32)buf, 0);
    h[4] = func_021C6590(r4, h[2], 0, 0);
    func_021C67D8(r4, h[4], 1);
    func_021C6AE0(buf);
    func_021C6AF0((u32)buf, r6, 0x36);
    func_021C6AF8((u32 *)buf, r6);
    func_021C6AFC(buf, 0x6b);
    func_021C6AFC(buf, 0x85);
    h[3] = func_021C6574(r4, (u32)buf, 0);
    h[5] = func_021C6590(r4, h[3], 0, 0);
    func_021C67D8(r4, h[5], 1);
}










void func_021ACB0C(X_021ACA5C *x)
{
    u32 h = func_021ABE18((u8 *)x->f0);

    func_021C6628(h, x->h8);
    func_021C6628(h, x->ha);
    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
}










void func_021ACB38(u32 a, u32 b, V3 *c, u32 d, u32 e)
{
    V3 v;
    Arg_021ACB38 s;
    s.a = func_021ABEA0(a, 3);
    s.b = d;
    s.c = func_0216D588((void *)d);
    s.d = func_0216D590((void *)d);
    s.e = b;
    v = *c;
    if (func_0216D55C(d, 0x2000) != 0)
        func_021ABFA8(a, d_021D915C, &v, e, &s, 0);
    else
        func_021ABFA8(a, d_021D9184, &v, e, &s, 0);
}










void func_021ACBB8(u32 a, u8 v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[9] = v;
}










void func_021ACBC8(u32 a, int v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)func_021AC1E0(a);
        if (v == 1)
            p[10] = 0;
        else
            p[10] = 1;
    }
}









int func_021ACBE4(int n)
{
    if (n > 0x40000)
        n = 0x40000;
    return n / 0xA3D * 0x28;
}









int func_021ACC04(E *a, E *b, u32 mode)
{
    int r = 0;

    switch (mode) {
    case 0:
        r = b->f8 - a->f8;
        break;
    case 1:
        r = a->f8 - b->f8;
        break;
    case 2:
        r = b->f0 - a->f0;
        break;
    case 3:
        r = a->f0 - b->f0;
        break;
    }
    return r;
}







void func_021ACC3C(u32 a, B_021AC9D8 *b)
{
    u8 *p = (u8 *)func_021AC1AC(a);
    Inner_021AC810 *q;
    u32 k = 0x1000;
    b->blk = *(Blk_021AC9D8 *)p;
    func_021AC1CC(a, p + 0x10);
    b->fc = ((struct Obj19874 *)p)->fC;
    func_021ABE18((u8 *)(*(u32 *)b->blk.w[0]));
    b->f18 = *(u16 *)(b->blk.w[0] + 8);
    b->f9 = func_021AC1A0(a);
    b->f10 = k;
    b->f14 = k >> 2;
    q = &b->in;
    q->c = *(u16 *)(b->blk.w[0] + 0xa);
    b->in.a = 1;
    q->b = 9;
    q->d = k;
    q->e = k;
    q->f = k;
    func_021AC178(a);
}





void func_021ACCAC(void) {}




void func_021ACCB0(u32 a, B_021ACDC4 *b)
{
    AngTbl t = d_021D9198;
    Ang *e = &t.e[b->fc];
    u32 obj;
    Node_021ACCB0 *n;

    obj = func_021ABE18((u8 *)(*b->f1c));
    n = (Node_021ACCB0 *)func_021C6658(obj, b->f18);
    func_020520FC(e->x, e->y, e->z, (struct Mtx33 *)n->mtx);
    func_021AC1B8(a, n);
    if (b->in.a == 0) {
        Inner *in = &b->in;
        PosTbl pt = d_021D91C8;
        AngTbl at = d_021D91B0;
        V3 *p = &pt.e[b->fc];
        Ang *g = &at.e[b->fc];
        n = (Node_021ACCB0 *)func_021C6658(obj, in->c);
        func_020520FC(g->x, g->y, g->z, (struct Mtx33 *)n->mtx);
        func_021AC1B8(a, n);
        n->pos.x = n->pos.x + (in->pos.x + p->x);
        n->pos.y = n->pos.y + (in->pos.y + p->y);
        n->pos.z = n->pos.z + (in->pos.z + p->z);
        n->scale = in->scale;
        func_021C6678(obj, in->c, 0);
    } else {
        func_021C6678(obj, b->in.c, 1);
    }
}






/*
 * Addresses are Black-image addresses.
 */
void func_021ACDC4(u32 a, B_021ACDC4 *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    Inner *in;
    s32 d;
    u16 k;

    if (b->f9 == 0) {
        func_021ACCB0(a, b);
        return;
    }
    b->fc = func_0216D5F8((void *)b->f20);
    if (b->f9 == 1) {
        b->f10 += b->f14;
        if (b->f10 >= 0x4000) {
            b->f10 = 0x4000;
            b->f14 = -b->f14;
        } else if (b->f10 <= 0x1000) {
            b->f10 = 0x1000;
            b->f14 = -b->f14;
        }
        v.x = 0;
        v.y = b->f10 + 0x1000;
        v.z = 0x5000;
        k = func_0216D598((void *)b->f20);
        if (k == 0xA0 || k == 0xA1)
            v.y = b->f10 + 0x8000;
        func_0216D8E0(b->f20, &v);
    } else if (b->f9 == 2) {
        func_0216D8D0((u8 *)b->f20, (u8 *)(&v));
    }
    func_02197CCC((u8 *)b->f20, (s32 *)(&w));
    w.x -= v.x;
    w.y -= v.y;
    w.z -= v.z;
    if (b->f9 != 2)
        w.y += b->f10 - 0x1000;
    func_021AC1CC(a, &w);
    if (b->f9 == 2 || b->fa == 1) {
        in = &b->in;
        in->b = 9;
        if (b->fa == 1)
            in->a = 1;
    } else {
        in = &b->in;
        func_021C66EC((u32 *)func_021ABE18((u8 *)(*b->f1c)), in->c, 0x1000);
        func_0216D88C((const struct Actor *)b->f20, (struct VecFx32 *)&u);
        if (b->fc != in->b) {
            in->b = b->fc;
            in->p4 = u;
        } else if (u.x == in->p10.x && u.y == in->p10.y && u.z == in->p10.z) {
            switch (in->b) {
            case 0:
                in->p4.z -= 0x4000;
                if (in->p4.z < u.z)
                    in->p4.z = u.z;
                break;
            case 1:
                in->p4.z += 0x4000;
                if (in->p4.z > u.z)
                    in->p4.z = u.z;
                break;
            case 2:
                in->p4.x -= 0x4000;
                if (in->p4.x < u.x)
                    in->p4.x = u.x;
                break;
            case 3:
                in->p4.x += 0x4000;
                if (in->p4.x > u.x)
                    in->p4.x = u.x;
                break;
            }
        }
        d = func_021ACC04((struct E *)(&u), (struct E *)(&in->p4), in->b);
        if (d >= 0x40000) {
            switch (in->b) {
            case 0:
                in->p4.z = u.z + 0x40000;
                break;
            case 1:
                in->p4.z = u.z - 0x40000;
                break;
            case 2:
                in->p4.x = u.x + 0x40000;
                break;
            case 3:
                in->p4.x = u.x - 0x40000;
                break;
            }
        }
        d = func_021ACBE4(d);
        if (d < 0x28) {
            in->a = 1;
        } else {
            in->a = 0;
            in->scale.x = d;
            in->scale.y = d;
            in->scale.z = d;
        }
        in->p10 = u;
    }
    func_021ACCB0(a, b);
}







void func_021ACFD8(u32 a, Y *y)
{
    u32 h = func_021ABE18((u8 *)(*y->f1c));

    func_021C67F4(h, y->h18);
    func_021C67F4(h, y->h54);
}







static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}







void func_021ACFF8(u32 a, B_021ACFF8 *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    s16 f[3];
    s16 d[3];
    Inner *in;
    s32 dist;
    s32 r;

    if (b->f9 == 0)
        return;
    b->fc = func_0216D5F8((void *)b->f20);
    func_0219E784(b->f20, 0, f);
    func_0219E784(b->f20, b->fc, d);
    f[1] = 0;
    func_0207CDB8(f, f);
    d[1] = 0;
    func_0207CDB8(d, d);
    if (b->f9 == 1) {
        b->f10 += b->f14;
        if (b->f10 >= 0x4000) {
            b->f10 = 0x4000;
            b->f14 = -b->f14;
        } else if (b->f10 <= 0x1000) {
            b->f10 = 0x1000;
            b->f14 = -b->f14;
        }
        v.x = FX_Mul(-f[0], 0x7000);
        v.y = b->f10 + 0x5000;
        v.z = FX_Mul(-f[2], 0x7000);
        func_0216D8E0(b->f20, &v);
    }
    func_02197CCC((u8 *)b->f20, (s32 *)(&w));
    w.x -= v.x;
    w.y -= v.y;
    w.z -= v.z;
    w.y += b->f10 - 0x1000;
    func_021AC1CC(a, &w);
    if (b->f9 == 2 || b->fa == 1) {
        in = &b->in;
        in->b = 9;
        if (b->fa == 1)
            in->a = 1;
    } else {
        in = &b->in;
        func_021C66EC((u32 *)func_021ABE18((u8 *)(*b->f1c)), in->c, 0x1000);
        func_0216D88C((const struct Actor *)b->f20, (struct VecFx32 *)&u);
        if (b->fc != in->b) {
            in->b = b->fc;
            in->p4 = u;
        } else if (u.x == in->p10.x && u.y == in->p10.y && u.z == in->p10.z) {
            in->p4.x += FX_Mul(d[0], 0x4000);
            in->p4.z += FX_Mul(d[2], 0x4000);
            in->p4.y = u.y;
            if (d[0] > 0) {
                if (in->p4.x > u.x)
                    in->p4.x = u.x;
            } else if (d[0] < 0) {
                if (in->p4.x < u.x)
                    in->p4.x = u.x;
            }
            if (d[2] > 0) {
                if (in->p4.z > u.z)
                    in->p4.z = u.z;
            } else if (d[2] < 0) {
                if (in->p4.z < u.z)
                    in->p4.z = u.z;
            }
        }
        dist = func_0207CF3C(&u, &in->p4);
        if (dist >= 0x40000) {
            in->p4.x = u.x - FX_Mul(d[0], 0x40000);
            in->p4.z = u.z - FX_Mul(d[2], 0x40000);
        }
        r = func_021ACBE4(dist);
        if (r <= 0x28) {
            in->a = 1;
        } else {
            in->a = 0;
            in->scale.x = r;
            in->scale.y = r;
            in->scale.z = r;
        }
        in->p10 = u;
    }
}







void func_021AD274(u32 a, B_021AD274 *b)
{
    V3 va;
    V3 vb;
    M33 ma;
    M33 mb;
    s16 f[3];
    Inner_021AD274 *in = &b->in;
    u32 obj;
    Node_021AD274 *n;

    func_0219E784(b->f20, b->fc, f);
    va.x = f[0];
    va.y = 0;
    va.z = f[2];
    vb.x = -f[0];
    vb.y = 0;
    vb.z = -f[2];
    func_020521BC((const struct Vec3 *)(&va), (struct Mtx33 *)(&ma));
    func_020521BC((const struct Vec3 *)(&vb), (struct Mtx33 *)(&mb));
    obj = func_021ABE18((u8 *)(*b->f1c));
    n = (Node_021AD274 *)func_021C6658(obj, b->f18);
    n->mtx = ma;
    func_021AC1B8(a, n);
    if (b->in.a == 0) {
        func_021C6678(obj, in->c, 0);
        n = (Node_021AD274 *)func_021C6658(obj, in->c);
        n->mtx = mb;
        func_021AC1B8(a, n);
        n->pos.x = n->pos.x + (in->pos.x - FX_Mul(va.x, 0xE000));
        n->pos.y = n->pos.y + (in->pos.y - 0x4000 - FX_Mul(va.y, 0xE000));
        n->pos.z = n->pos.z + (in->pos.z - FX_Mul(va.z, 0xE000));
        n->scale = in->scale;
    } else {
        func_021C6678(obj, in->c, 1);
    }
    func_021C67F4(obj, b->f18);
    func_021C67F4(obj, in->c);
}






P_021ACA38 *func_021AD3D4(u32 a, int heap)
{
    P_021ACA38 *p;

    p = (P_021ACA38 *)func_02030734(heap, 0x10, 1, d_021DE080, 0x3cf);
    p->f0 = a;
    func_021AD410((u32 *)p);
    return p;
}






/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD3FC(u32 a, u8 *p)
{
    func_021AD530((X_021ACA5C *)((struct X_021ACA5C *)p));
    func_020307B0(p);
}






/*
 * Addresses are Black-image addresses.
 *
 * The buffer handle p is assigned after the func_021ABE24 call, but the
 * first func_021C6AE0 call takes the buffer itself, so a call lies between
 * the assignment and the first read of p. That keeps p a register variable
 * (r7) instead of a rematerialised address, and the repeated 0 argument is
 * rebuilt per call. See docs/idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md.
 */
void func_021AD410(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r6;
    u32 r4;
    u32 p;
    r6 = func_021ABE18((u8 *)a[0]);
    r4 = func_021ABE24((u8 *)a[0]);
    p = (u32)buf;
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x37);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC((u32 *)p, 0x80);
    func_021C6AFC((u32 *)p, 0x6c);
    h[2] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x3a);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC((u32 *)p, 0x6f);
    func_021C6AFC((u32 *)p, 0x63);
    h[3] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x39);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC((u32 *)p, 0x6e);
    func_021C6AFC((u32 *)p, 0x62);
    h[5] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x3b);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC((u32 *)p, 0x70);
    func_021C6AFC((u32 *)p, 0x64);
    h[4] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x38);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC((u32 *)p, 0x6d);
    func_021C6AFC((u32 *)p, 0x61);
    h[6] = func_021C6574(r6, p, 0);
}






void func_021AD530(X_021ACA5C *x)
{
    u32 h = func_021ABE18((u8 *)x->f0);

    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
    func_021C6580((u8 *)h, x->ha);
    func_021C6580((u8 *)h, x->h8);
    func_021C6580((u8 *)h, x->hc);
}






void func_021AD564(u32 a, u32 b, u32 c)
{
    P_021ACA38 s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = c;
    s.f0 = 0;
    func_021ABFA8(a, d_021D9170, 0, 0, &s, 1);
}






void func_021AD598(u32 a, u32 b, u32 c)
{
    P_021ACA38 s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = 0;
    s.f0 = 1;
    func_021ABFA8(a, d_021D9170, (void *)c, 0, &s, 1);
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AD5CC(u32 a)
{
if (a != 0) {
    return ((struct Obj18088 *)((u8 *)(func_021AC1E0(a))))->fC;
}
return 1;
}






void func_021AD5E0(int a, int *bp)
{
    Obj_021AC810 *b = (Obj_021AC810 *)bp;
    V3 out;
    T5 tab;
    int r;
    int m;
    Tab *t;

    b->s14 = *((S16_021AD5E0 *)func_021AC1AC(a));
    t = (Tab *)b->s14.b;
    r = func_021ABE18((u8 *)t->f0);
    switch (b->s14.c) {
    case 0:
        m = ((Tab *)b->s14.b)->h4;
        break;
    case 1:
        m = ((Tab *)b->s14.b)->h6;
        break;
    case 2:
        m = ((Tab *)b->s14.b)->ha;
        break;
    case 3:
        m = ((Tab *)b->s14.b)->h8;
        break;
    case 4:
        m = ((Tab *)b->s14.b)->hc;
        break;
    default:
        goto skip;
    }
    b->h10 = func_021C6590(r, m, 0, 0);
skip:
    if (b->s14.d != 0) {
        tab = d_021D91F8;
        b->v = tab.v[b->s14.c];
        func_021AC1B8(b->s14.d, (Node_021AD274 *)&out);
        out.x += b->v.x;
        out.y += b->v.y;
        out.z += b->v.z;
        func_021AC1CC(a, (V3 *)&out);
    }
}





int func_021AD6A4(u32 a, u32 b, u32 c, u32 d)
{
return func_021C6628(func_021ABE18((u8 *)(*(u32 *)((u8 *)(((struct Obj12097 *)((u8 *)(b)))->f18)))), ((struct Obj12097 *)((u8 *)(b)))->f10);
}




void func_021AD6B8(int a, Obj_021AD6B8 *b)
{
    V3 v;
    int r;

    if (b->padc == 1 && b->s14.a == 1) {
        func_021AC154(a);
        return;
    }
    r = func_021ABE18((u8 *)(*b->s14.b));
    if (b->s14.c == 0) {
        if (b->padc == 0) {
            if (func_021C6694((u32 *)r, b->h10, 0x1000) == 0) {
                b->padc = 1;
            }
        }
    } else {
        func_021C66EC((u32 *)r, b->h10, 0x1000);
    }
    if (b->s14.d != 0) {
        func_021AC1B8(b->s14.d, &v);
        v.x += b->v.x;
        v.y += b->v.y;
        v.z += b->v.z;
        func_021AC1CC(a, &v);
    }
}




void func_021AD738(int a, S *s)
{
    func_021AC1B8(a, (V3 *)(func_021C6658(func_021ABE18((u8 *)(*s->p18)), s->h10)));
}



void *func_021AD758(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 0);
}



void *func_021AD764(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 1);
}



void *func_021AD770(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 2);
}



void *func_021AD77C(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 3);
}



void *func_021AD788(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 4);
}



void *func_021AD794(u32 a, int heap)
{
    return (void *)func_021AD7B4(a, heap, 5);
}







/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD7A0(u32 a, u8 *p)
{
    func_021ADA1C((ModelSet *)p);
    func_020307B0(p);
}







P_021ACA38 *func_021AD7B4(u32 a, int heap, u32 c)
{
    P_021ACA38 *p;

    p = (P_021ACA38 *)func_02030734(heap, 0x98, 1, d_021DE0E8, 0x11e);
    p->f0 = a;
    func_021AD7E4((ModelSet *)p, c);
    return p;
}







void func_021AD7E4(ModelSet *a, u32 b)
{
    int t;

    a->desc = d_021DE094[b];
    t = func_021ABE24((u8 *)a->f0);
    if (b == 0) {
        func_021AD8DC((ModelSet *)a, &a->desc, t);
    } else {
        func_021AD96C((ModelSet *)a, &a->desc, t);
    }
}









/*
 * Lever: func_0204767C takes three arguments (see ov019_func_0217FA10); the
 * third is b->desc.n, which is what keeps the loop bound in r2.
 */
void func_021AD82C(A *a, ModelSet *b, int c)
{
    int i = 0;

    a->f14 = (u32)func_02047400((void *)b->f8[c], 0, (void *)b->f8[c]);
    for (; i < b->desc.n; i++)
        a->f4[i] = (u32)func_02047564((struct G3dOwner *)a->f14, (const struct G3dOwner *)b->u.f18[c * b->desc.n + i], 0);
    a->f0 = (u32)func_0204767C(a->f14, a->f4, b->desc.n);
    for (i = 0; i < b->desc.n; i++)
        func_020477A4((struct G3dSys *)a->f0, (u16)i);
}









void func_021AD8A4(A *z, ModelSet *w)
{
    int i;

    for (i = 0; i < w->desc.n; i++)
        func_0204762C((struct Rec *)z->f4[i]);
    func_02047738((struct Rec *)z->f0);
    func_02047504((struct Rec *)z->f14);
}









void func_021AD8DC(ModelSet *a, ModelDesc *d, int c)
{
    int r7;

    r7 = func_021ABE28((u8 *)a->f0);
    func_02046FF8((int *)(a->f8[0] = (int)func_02046E24(c, d->h4 + r7)));
    a->u.f18[0] = (int)func_02046E24(c, d->tab[0] + r7);
    func_021AD82C(&a->u.r.rec[0], (ModelSet *)a, 0);
    r7 += d->mid;
    func_02046FF8((int *)(a->f8[1] = (int)func_02046E24(c, d->h4 + r7)));
    a->u.f18[1] = (int)func_02046E24(c, d->tab[0] + r7);
    func_021AD82C(&a->u.r.rec[1], (ModelSet *)a, 1);
    func_02046FF8((int *)(a->f8[2] = (int)func_02046E24(c, d->h4)));
    a->u.f18[2] = (int)func_02046E24(c, d->tab[0]);
    func_021AD82C(&a->u.r.rec[2], (ModelSet *)a, 2);
}









void func_021AD96C(ModelSet *a, ModelDesc *d, int c)
{
    int base;
    int i;
    int j;
    int t;

    base = 0;
    if (d->b6) {
        base = func_021ABE28((u8 *)a->f0);
    } else if (d->b7) {
        base = func_021ABE2C((u8 *)a->f0);
    }
    for (i = 0; i < d->lo; i++) {
        t = base + i * d->mid;
        a->f8[i] = (int)func_02046E24(c, d->h4 + t);
        func_02046FF8((int *)a->f8[i]);
        for (j = 0; j < d->n; j++) {
            a->u.f18[i * d->n + j] = (int)func_02046E24(c, t + d->tab[j]);
        }
        func_021AD82C(&a->u.r.rec[i], a, (u8)i);
    }
}









void func_021ADA1C(ModelSet *a)
{
    int i;

    for (i = 0; i < a->desc.lo; i++) {
        func_021AD8A4(&a->u.r.rec[i], a);
    }
    for (i = 0; i < a->desc.n * a->desc.lo; i++) {
        func_02046EFC((struct Tagged *)a->u.f18[i]);
    }
    for (i = 0; i < a->desc.lo; i++) {
        func_020470D0((u32 *)a->f8[i]);
        func_02046EFC((struct Tagged *)a->f8[i]);
    }
}









u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f)
{
    int t;
    int k;
    int r;
    L l;

    t = func_021ABE14(b);
    if (func_02188CFC((u8 *)t) != 0) {
        return 0;
    }
    k = d_021D9238[f];
    r = func_021ABEA0((u32)b, k + 0x12);
    if (r == 0) {
        return 0;
    }
    func_02082BCC(&l, 0, 0x28);
    l.f0 = a;
    l.f4 = r;
    l.f8 = func_02188C7C((void *)t);
    l.h10 = c;
    l.h12 = d;
    l.f14 = k;
    if (k == 0) {
        l.b18 = f;
    } else {
        l.b18 = 0;
    }
    l.f1c = (c << 16) + 0x8000;
    l.f24 = (d << 16) + 0x8000;
    l.f20 = e;
    return func_021ABFA8((int)b, d_021D9240, 0, 1, &l, 0);
}









void func_021ADB4C(u32 a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[2] = v;
}









void func_021ADB5C(int a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[3] = v;
}







void func_021ADB6C(int a, Dst *b)
{
    int *s = (int *)func_021AC1AC(a);

    b->f34 = s[0];
    b->s4 = *(S40 *)s;
    func_021AC1CC(a, (V3 *)(s + 7));
    if (func_021AC1A0(a) == 0) {
        b->h0 = 1;
    }
    func_021AC178(a);
}





void func_021ADBAC(void) {}





void func_021ADBB0(int a, u8 *w)
{
    int i;
    u8 *o = *(u8 * *)&((struct Obj05043 *)w)->f8;

    if (func_02188BE8((void *)func_021ABE14((u8 *)(((struct Obj12797 *)o)->f0))) != 0 && w[2] == 0) {
        func_021ADC04(w, o);
        for (i = 0; i < o[0x88]; i++) {
            func_02047910((void *)(*(int *)(o + 0x28 + w[0x1c] * 0x18)), (u16)i, 0x1000);
        }
    }
}





/*
 * Levers: func_02047828's second parameter is an index (the zero stored to v
 * is passed in r1), not &v; the final call's arguments are named locals with
 * the inner call bound to a local after them, which keeps both loads above
 * the call in callee-saved registers.
 */
void func_021ADC04(u8 *w, u8 *o)
{
    u16 v;
    int z;
    u8 c;
    u16 k;
    void *x;

    v = 0;
    func_02047828(*(void **)(o + 0x28 + w[0x1c] * 0x18), 0, &z);
    if (z == 0 && func_021AAA4C((struct Self *)(((struct Obj05043 *)w)->f34), (short int *)(&v)) != 0) {
        v = func_0209C0A4(v, 5);
        if (v > 3)
            v = 3;
        c = d_021D9234[v];
        k = ((struct Obj19888 *)o)->f8A;
        x = (void *)func_02012A30(*(void **)(((struct Obj05043 *)w)->f34 + 8));
        func_02028ACC(x, k, c);
    }
}
