/*
 * file:     mcss_p06.c
 * unit:     yes
 * function: func_0201691C, func_02016984, func_020169D4, func_020169E8, func_02016BA0, func_02016C0C, func_02016C38, func_02016C60, func_02016FC8, func_02017100, func_02017114, func_02017168, func_02017214, func_02017270, func_020172AC, func_020172BC, func_020172D8, func_020173B4
 * address:  0x0201691C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020637D4  0x020637D4  arm
 *   func_02063E54  0x02063E54  arm
 *   sub_020307B0   0x020307B0  arm
 *   sub_02030EAC   0x02030EAC  arm
 *   data_020A72CC  0x020A72CC  data
 *   func_0201691C  0x0201691C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_02016C0C  0x02016C0C  thumb
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AB80   0x0209AB80  arm
 *   _d2s            0x0209C508  arm
 *   _ll_mul  0x0209C054  arm
 *   func_02017E88  0x02017E88  thumb
 *   func_02017EB4  0x02017EB4  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D09C  0x0202D09C  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_0202D110  0x0202D110  thumb
 *   func_0202D144  0x0202D144  thumb
 *   func_0202D178  0x0202D178  thumb
 *   func_0202D1AC  0x0202D1AC  thumb
 *   func_0202D1E0  0x0202D1E0  thumb
 *   func_0202D5CC  0x0202D5CC  thumb
 *   func_0202D5F8  0x0202D5F8  thumb
 *   func_0202D61C  0x0202D61C  thumb
 *   func_0202D640  0x0202D640  thumb
 *   func_0202D664  0x0202D664  thumb
 *   func_0202D688  0x0202D688  thumb
 *   func_0202D6AC  0x0202D6AC  thumb
 *   func_0202D6D0  0x0202D6D0  thumb
 *   sub_02014CF0  0x02014CF0  thumb
 *   sMcssTable  0x020A72D4  data
 */
#include "../../matched/include/Obj02301.h"
#include "../../matched/include/Obj00353.h"
#include "../../matched/include/Obj01459.h"
#include "../../matched/include/Obj01104.h"
#include "../../matched/include/Obj07131.h"
#include "../../matched/include/Obj11258.h"
#include "../../matched/include/Obj15713.h"
#include "../../matched/include/Obj15715.h"

struct Node;
struct Obj_0201691C;
struct S02030EE8;
struct Obj;
struct Rec;
struct Stats;
struct Sub150;
struct Obj02014CF0;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj24_0201691C {
    u8   pad00[4];
    void *f04;      /* +0x04 */
    void *f08;      /* +0x08 */
};

struct Obj04_0201691C {
    u8   pad00[0xc];
    void *f0c;      /* +0x0c */
};

struct Obj_0201691C {
    u8   pad00[4];
    struct Obj04_0201691C *f04;   /* +0x04 */
    u8   pad08[4];
    void *f0c;                    /* +0x0c */
    u8   pad10[0xc];
    u32  f1c;                     /* +0x1c */
    u8   pad20[4];
    struct Obj24_0201691C *f24;   /* +0x24 */
    u32  f28;                     /* +0x28 */
};

typedef signed char    s8;

typedef signed int     s32;

struct Inner {
    u32 f00;
    u32 f04;
    u32 f08;
    void *f0c;
};

struct Obj {
    u8 pad00[4];
    struct Inner *f04;
    u8 pad08[4];
    void *f0c;
    u8 pad10[0xc];
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Rec
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  s32 f14;
  s32 f18;
  s32 f1c;
  s32 f20;
  s32 f24;
  s32 f28;
  s32 f2c;
  s32 f30;
  s32 f34;
  s32 f38;
};

struct Work
{
  u8 pad00[0x2c];
  s32 *f2c;
  u8 pada8[0xa8 - 0x30];
  s32 fa8;
  u8 padac[4];
  s32 fb0;
  u8 padb4[0x140 - 0xb4];
  u32 f140;
};

struct Task
{
  u8 **f00;
};

typedef signed long long s64;

struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
};

struct MtxFx44 {
    s32 m[4][4];
};

struct Stats {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
};

typedef signed short s16;

extern void func_020637D4(u32 *p);
extern void func_02063E54(void *a, u32 b, int c, void *d);
extern u32 sub_020307B0(void *p);
extern void sub_02030EAC(struct Node *n);
extern int func_020648B4(u32 a, u32 b);
extern void *func_02030734(u32 a0, u32 a1, int a2, const char *a3, unsigned short a4);
extern void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind);
void func_02016984(char *a0, int a1);
void sub_020169D4(void);
extern void func_02021F64(void *a, void *b, u16 c, u8 d, u16 e);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_0201691C(void *a0, struct Obj_0201691C *a1);
extern unsigned int func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02016C0C(void *id);
void func_020169E8(u8 *a0, u8 *a1);
void sub_02016BA0(void *obj);
void sub_02016C0C(void *id);
extern double _s32_to_double(s32 v);
extern double func_0209AB80(double a, double b);
extern s32 _d2s(double d);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern u32   func_02017EB4(void *p);
extern void *func_020185F4(void *p);
extern int func_0202D060(void);
extern s32 func_0202D09C(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D110(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D144(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D178(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D1AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D1E0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
void func_02017114(void *p, struct Stats *out, u32 lvl);
void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6);
extern u32 func_0202D5CC(u32 a);
extern u32 func_0202D5F8(u32 id, u32 flags);
extern u32 func_0202D61C(u32 id, u32 flags);
extern u32 func_0202D640(u32 id, u32 flags);
extern u32 func_0202D664(u32 id, u32 flags);
extern u32 func_0202D688(u32 id, u32 flags);
extern u32 func_0202D6AC(u32 id, u32 flags);
extern u32 func_0202D6D0(u32 id, u32 flags);
extern u32  func_02017E1C(void *p, u32 a, u32 b);
extern void func_02017100(void *p, struct Stats *out, u32 lvl);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void sub_02014CF0(struct Obj02014CF0 *o, int v1, int v2);
void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
void func_020172AC(int a0, int a1);
u32 func_020172BC(u8 *a0, u8 **a1, u32 a2);
void func_020172D8(u8 *a0, u32 a1);
int func_020173B4(int a0);
void func_02016C38(int a0);
extern char data_020A72CC[];
extern const u8 *sMcssTable[4];




void func_0201691C(void *a0, struct Obj_0201691C *a1)
{
    if (a1->f28 == 0) {
        u32 v = *(volatile u16 *)0x04000006;

        if (v < 0xc0 || v > 0xc8)
            return;
    }
    func_020637D4(a1->f0c);
    func_02063E54(a1->f04, a1->f1c, 0, a1->f0c);
    if (a1->f24 != 0) {
        if (a1->f24->f04 == a0)
            a1->f24->f04 = 0;
        if (a1->f24->f08 == a0)
            a1->f24->f08 = 0;
    }
    sub_020307B0(((struct Obj04_0201691C *)a1->f04)->f0c);
    sub_020307B0(a1->f04);
    sub_020307B0(a1);
    sub_02030EAC(a0);
}



/*
 * A two-call registrar.  The first call is five arguments wide: the value
 * loaded from +0x14c is an `int` truncated to `u16` at the call (the listing
 * shows `ldr` + the lsls/lsrs 0x10 pair, not a `ldrh` - declaring the field
 * itself `u16` is what produces a `ldrh` and loses four bytes), and 0x970 is
 * the fifth argument on the stack.  The result is stored back into +0x98,
 * which the second call reads as its own second argument, so the field is a
 * genuine `int`.
 *
 * The pool word at 0x020169D0 is 0x020A72CC; that same word sits in eight
 * other functions' pools in this image (0x02014B9C, 0x02015B94, 0x02016240,
 * 0x02016360, 0x02016624, 0x02016870, 0x02016B84, ...), all outside the
 * compared range, which is what attests the site through the `literal` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02016984.c \
 *       --func func_02016984 --addr 0x02016984 --cc 1.1p1 --thumb
 */
void func_02016984(char *a0, int a1)
{
    *(int *)&((struct Obj02301 *)a0)->f98 = (int)func_02030734((unsigned short)((struct Obj02301 *)a0)->f14C,
                                        func_020648B4(((struct Obj02301 *)a0)->f18, a1),
                                        0, data_020A72CC, 0x970);
    func_02064754((char *)((int)(a0 + 0x34)), (char *)(*(int *)&((struct Obj02301 *)a0)->f98), (void *)(((struct Obj02301 *)a0)->f20),
                  ((struct Obj02301 *)a0)->f10, (void *)(((struct Obj02301 *)a0)->f18), a1);
}



/*
 * A single matched function.
 *
 * alias: a direct write of a fixed 32-bit value to a hardware register pair
 * at 0x040004C0: the low word gets the full constant, the high word (at
 * +4) gets its upper halfword. This is a raw I/O register store, not an
 * SDK call, which is why it is game code sitting on hardware address space.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020169D4.c \
 *       --func sub_020169D4 --addr 0x020169D4 --cc 1.1p1 --thumb
 */
void sub_020169D4(void)
{
    u32 v = 0x4210FFFF;
    *(volatile u32 *)0x040004C0 = v;
    *(volatile u32 *)0x040004C4 = v >> 16;
}



/*
 * Closed in the second pass (2026-09-22) from the 4-byte near miss in
 * docs/notes/func_020169E8.c.txt.  The residue was NOT the pool-word
 * shape that note predicted; it was two misreadings of the image:
 *
 *   1. the flag mask is 0xFFFFEFFF (bit 12), not 0xEFFFFFFF (bit 28).
 *      The pool word at 0x02016B94 is `ff ef ff ff`.  Fixing it alone
 *      took the diff from 4 concrete bytes to 2.
 *   2. the second clamp reads +0x135 / +0x134, not +0x137 / +0x136.
 *      The `ldr r0,[pc,#0x3c]` at 0x02016B58 resolves to 0x02016B98,
 *      the SECOND pool word (0x135), while the `ldr r0,[pc,#0x30]` at
 *      0x02016B6A resolves to 0x02016B9C, the THIRD (0x137).  Reading
 *      both as 0x137 is what made the 0x135 pool word disappear and the
 *      function come out 436 bytes instead of 440.  The missing pool
 *      word was a symptom, not the cause.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020169E8.c \
 *       --func func_020169E8 --addr 0x020169E8 --cc 1.1p1 --thumb
 */
void func_020169E8(u8 *a0, u8 *a1)
{
    struct Obj *p;
    u32 flag;
    void *ret;
    s32 step;
    s8 cur;
    s8 tgt;

    if (((struct Obj00353 *)a1)->f136 != 0) {
        goto dec;
    }

    flag = 1;
    p = (struct Obj *)func_02030734((u16)(((u16)((struct Obj00353 *)a1)->f14C & 0x7FFF) | 0x8000), 0x2C, 1, data_020A72CC, 0x9A1);
    p->f20 = a0;
    if (((struct Obj01459 *)a0)->f8 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f24 = a1;
    p->f0c = a1 + 0xC0;
    p->f1c = ((struct Obj01459 *)a0)->f34 + (((struct Obj00353 *)a1)->f148 << 5);

    flag = 0;
    p->f04 = (struct Inner *)func_02030734((u16)(((u16)((struct Obj00353 *)a1)->f14C & 0x7FFF) | 0x8000), 0x10, 0, data_020A72CC, 0x9A9);
    p->f04->f00 = ((struct Obj00353 *)a1)->fC0;
    p->f04->f04 = flag;
    p->f04->f08 = ((struct Obj00353 *)a1)->fDC;
    p->f04->f0c = func_02030734((u16)(((u16)((struct Obj00353 *)a1)->f14C & 0x7FFF) | 0x8000), ((struct Obj00353 *)a1)->fDC, 0, data_020A72CC, 0x9A9 + 5);

    if ((((struct Obj00353 *)a1)->f140 << 3) >> 0x1F) {
        func_02021F64(((struct Obj00353 *)a1)->fD8, p->f04->f0c,
                      ((s32)((struct Obj00353 *)a1)->fDC / 2),
                      *(u8 *)&((struct Obj00353 *)a1)->f134, (u16)((struct Obj00353 *)a1)->f13C);
    } else {
        func_02021F64(((struct Obj00353 *)a1)->fD4, p->f04->f0c,
                      ((s32)((struct Obj00353 *)a1)->fDC / 2),
                      *(u8 *)&((struct Obj00353 *)a1)->f134, (u16)((struct Obj00353 *)a1)->f13C);
    }

    if (((struct Obj00353 *)a1)->f4 != 0) {
        func_02016C38((int)(((struct Obj00353 *)a1)->f4));
        ((struct Obj00353 *)a1)->f4 = 0;
    }

    if (((struct Obj01459 *)a0)->f8 != 0) {
        ret = func_02030DA8(((struct Obj01459 *)a0)->f8, func_0201691C, p, 0);
    } else {
        ret = func_020056A0(func_0201691C, p, 0);
    }
    ((struct Obj00353 *)a1)->f4 = ret;

    cur = ((struct Obj00353 *)a1)->f134;
    tgt = ((struct Obj00353 *)a1)->f135;
    if (cur == tgt) {
        ((struct Obj00353 *)a1)->f140 &= 0xFFFFEFFF;
    } else {
        step = ((struct Obj00353 *)a1)->f138;
        ((struct Obj00353 *)a1)->f134 = (s8)(cur + (s8)step);
        if (step < 0 || ((struct Obj00353 *)a1)->f134 < tgt) {
            if (step < 0) {
                tgt = ((struct Obj00353 *)a1)->f135;
                if (((struct Obj00353 *)a1)->f134 > tgt) {
                    goto done;
                }
            } else {
                goto done;
            }
        }
        ((struct Obj00353 *)a1)->f134 = tgt;
    }
done:
    ((struct Obj00353 *)a1)->f136 = ((struct Obj00353 *)a1)->f137;
    return;
dec:
    ((struct Obj00353 *)a1)->f136 = ((struct Obj00353 *)a1)->f136 - 1;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a teardown chain on the same object class as unit_02015BA4.c.
 * sub_02016BA0 releases eight pointer fields of the object through
 * func_020307B0 (a generic release call reached by blx, so it is ARM),
 * zeroes three of them (+0x98, +0xd4, +0xd8, all past the immediate str
 * reach so the compiler adds the offset into a register first), then
 * zeroes the other four (+0xc, +0x1c, +0x14, +0x24, +0x2c) and, if the
 * object's own field at +0 is non-zero, recurses into sub_02016C0C with
 * that field's value before zeroing it too. sub_02016C0C turns an id into
 * an object through func_02030EE8, releases one or two of the object's own
 * pointer fields the same way, releases the object itself, and finally
 * releases the id through func_02030EAC.
 *
 * The immediate follower, sub_02016C38 (38 bytes, same shape over a third
 * field, one level of extra indirection), is a documented near miss: this
 * front end assigns it only two callee-saved registers (padding a filler
 * into r3) where the original spends three (r4, r5, r6), so the second
 * fetch of the inner pointer is a register move here and a reload from
 * memory in every source shape tried. Left out rather than forced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02016BA0.c \
 *       --addr 0x02016BA0 --thumb
 */
void sub_02016BA0(void *obj)
{
    u8 *o = (u8 *)obj;

    func_020307B0(((struct Obj01104 *)o)->fC);
    func_020307B0(((struct Obj01104 *)o)->f1C);
    func_020307B0(((struct Obj01104 *)o)->f14);
    func_020307B0(((struct Obj01104 *)o)->f24);
    func_020307B0(((struct Obj01104 *)o)->f98);
    func_020307B0(((struct Obj01104 *)o)->f2C);
    func_020307B0(((struct Obj01104 *)o)->fD4);
    func_020307B0(((struct Obj01104 *)o)->fD8);

    ((struct Obj01104 *)o)->f98 = 0;
    ((struct Obj01104 *)o)->fD4 = 0;
    ((struct Obj01104 *)o)->fD8 = 0;

    {
        void *v = ((struct Obj01104 *)o)->f0;
        ((struct Obj01104 *)o)->fC = 0;
        ((struct Obj01104 *)o)->f1C = 0;
        ((struct Obj01104 *)o)->f14 = 0;
        ((struct Obj01104 *)o)->f24 = 0;
        ((struct Obj01104 *)o)->f2C = 0;
        if (v != 0) {
            func_02016C0C(v);
            ((struct Obj01104 *)o)->f0 = 0;
        }
    }
}



void sub_02016C0C(void *id)
{
    void *obj = (void *)func_02030EE8(id);

    if (((struct Obj07131 *)obj)->f10 != 0) {
        func_020307B0(((struct Obj07131 *)obj)->f10);
    }
    if (((struct Obj07131 *)obj)->f14 != 0) {
        func_020307B0(((struct Obj07131 *)obj)->f14);
    }
    func_020307B0(obj);
    func_02030EAC(id);
}






void func_02016C38(int a0)
{
    u32 t0 = func_02030EE8((struct S02030EE8 *)a0);
    func_020307B0((void *)*(int *)((char *)((struct Obj11258 *)t0)->f4 + 12));
    func_020307B0((void *)((struct Obj11258 *)t0)->f4);
    func_020307B0((void *)t0);
    func_02030EAC((struct Node *)a0);
}





/*
 * mcss.c, the two-pass nibble fill over a0->f2c's 0x30-byte records.
 * EXACT* (870 bytes; the 872-byte listing extent carries 2 pad bytes).
 * Closed in wave 21 (lane B2) from 16 bytes out.  The lever is w2: it is
 * read raw into the guard (`w2 = R->f2c; if (w2 != 0)`) and shifted
 * later (`w2 >>= 12;`), and the pass-2 header follows pass 1's order,
 * sx2, sy2, w2, h2, then `i2 = 0; y = 0;`.  The raw w2 web spans the
 * sx2/sy2 reads and is coloured before the record pointer, which puts
 * the pointer in r1 and both zeros in r0, as the image has them.
 * History: docs/notes/pkt_02016C60.c.txt.
 */
void func_02016C60(struct Work *a0, struct Task *a1)
{
  s32 scale;
  u8 *base;
  s32 k;
  s32 sx;
  s32 sy;
  s32 w;
  s32 h;
  s32 step;
  s32 nib;
  s32 found;
  s32 x;
  s32 y;
  s32 i;
  s32 j;
  s32 sx2;
  s32 sy2;
  s32 w2;
  s32 h2;
  s32 i2;
  s32 j2;
  s32 bw;
  s32 bh;
  s32 r;
  s32 c;
  s32 addr;
  s32 t;
  s32 v;
  s32 tmp1;
  s32 tmp2;
  s32 tmp3;
  s32 tmp4;
  s32 tmp5;
  s32 tmp8;
  s32 tmp10;
  if (a0->fb0 != 3)
  {
    return;
  }
  scale = _d2s(func_0209AB80(2.0, _s32_to_double(a0->fa8 + 2)));
  base = a1->f00[5];
  k = 0;
  while (((u32) k) < ((u32) a0->f2c[0]))
  {
    sx = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f1c >> 12;
    sy = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f20 >> 12;
    w = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f14 >> 12;
    h = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f18 >> 12;
    step = ((s32) ((a0->f140 << 4) >> 0x1c)) + 1;
    i = 0;
    y = 0;
    if (h > 0)
    {
      do
      {
        for (j = 0, x = 0; x < w; j++, x += step)
        {
          {
            s32 hi;
            if ((x + step) > w)
            {
              bw = w - (step * j);
            }
            else
            {
              bw = step;
            }
            if ((y + step) > h)
            {
              bh = h - (step * i);
            }
            else
            {
              bh = step;
            }
            found = 0;
            for (r = 0; r < bh; r++)
            {
              for (c = 0; c < bw; c++)
              {
                t = (sx + x) + c;
                tmp3 = (sy + y) + r;
                addr = (t / 2) + (tmp3 * scale);
                if (c & 1)
                {
                  v = (base[addr] & 0xf0) >> 4;
                }
                else
                {
                  v = base[addr] & 0x0f;
                }
                if (v != 0)
                {
                  found = v;
                  break;
                }
              }

              if (found != 0)
              {
                break;
              }
            }

            nib = (u8) found;
            hi = nib << 4;
            for (r = 0; r < bh; r++)
            {
              for (c = 0; c < bw; c++)
              {
                tmp10 = sx + x;
                t = tmp10 + c;
                tmp4 = sy + y;
                tmp1 = tmp4 + r;
                addr = (t / 2) + (tmp1 * scale);
                if (addr < (1 << 14))
                {
                  if (t & 1)
                  {
                    base[addr] = (base[addr] & 0x0f) | hi;
                  }
                  else
                  {
                    base[addr] = (base[addr] & 0xf0) | nib;
                  }
                }
              }

            }

          }
        }

        i++;
        y += step;
      }
      while (y < h);
    }
    w2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f2c;
    if (w2 != 0)
    {
      sx2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f34 >> 12;
      sy2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f38 >> 12;
      w2 >>= 12;
      h2 = (((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f30 >> 12) << 1;
      i2 = 0;
      y = 0;
      if (h2 > 0)
      {
        do
        {
          for (j2 = 0, x = 0; x < w2; j2++, x += step)
          {
            {
              s32 hi2;
              if ((x + step) > w2)
              {
                bw = w2 - (step * j2);
              }
              else
              {
                bw = step;
              }
              if ((y + step) > h2)
              {
                bh = h2 - (step * i2);
              }
              else
              {
                bh = step;
              }
              found = 0;
              for (r = 0; r < bh; r++)
              {
                for (c = 0; c < bw; c++)
                {
                  t = (sx2 + x) + c;
                  tmp8 = (sy2 + y) + r;
                  addr = (t / 2) + (tmp8 * scale);
                  if (c & 1)
                  {
                    v = (base[addr] & 0xf0) >> 4;
                  }
                  else
                  {
                    v = base[addr] & 0x0f;
                  }
                  if (v != 0)
                  {
                    found = v;
                    break;
                  }
                }

                if (found != 0)
                {
                  break;
                }
              }

              nib = (u8) found;
              hi2 = nib << 4;
              for (r = 0; r < bh; r++)
              {
                for (c = 0; c < bw; c++)
                {
                  t = sx2 + x;
                  t = t + c;
                  tmp5 = sy2 + y;
                  tmp2 = tmp5 + r;
                  addr = (t / 2) + (tmp2 * scale);
                  if (addr < (1 << 14))
                  {
                    if (t & 1)
                    {
                      base[addr] = (base[addr] & 0x0f) | hi2;
                    }
                    else
                    {
                      base[addr] = (base[addr] & 0xf0) | nib;
                    }
                  }
                }

              }

            }
          }

          i2++;
          y += step;
        }
        while (y < h2);
      }
    }
    k++;
  }

}


/*
 * 310 bytes, one function, and two bytes of linker fill after it before the
 * next function at 0x02017100; the range this entry owns is 0x02016FC8 plus
 * 310, which is why it is written as a unit rather than as a single function
 * entry (`match.py one` measures the extent to the next label, sees 312 and
 * reports EXACT* over two bytes the compiler never emitted).
 *
 * The 4x4 fixed-point transform of a three-component vector: the ordinary
 * Nitro row-vector convention, out = v * M with the translation row added
 * afterwards, computed in 64 bit and shifted back down by the 12 fractional
 * bits at the end of each component.  The fourth component does not go into
 * the destination vector; it is written through a separate `s32 *`, which is
 * what makes this the projection form rather than MTX_MultVec: the caller
 * gets x, y, z and w separately and divides by w itself.
 *
 *   dst->x = (s32)((vx * m[0][0] + vy * m[1][0] + vz * m[2][0]) >> 12)
 *            + m[3][0];        and the same for columns 1, 2 and 3
 *
 * Every product is a call to the compiler's 64 bit multiply helper at
 * 0x0209C054, twelve of them, and the `asrs rN, rM, #0x1f` in front of each
 * operand is the sign extension an `s32` costs on the way to `long long`; see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md
 * for the same family of helpers seen from the division side.  The name the
 * relocation carries is `_ll_mul`, not `_ull_mul`: both spellings name the
 * same routine at 0x0209C054 (`umull` plus two `mla` is correct for either
 * signedness), and which one mwccarm emits follows the signedness of the
 * operands, so `src/matched/unit_020056A0.c` pins the same address under the
 * other name.  The helper's contract is r0:r1 and r2:r3 in, r0:r1 out.
 *
 * The 64 bit shift is not a call.  `lsls r0, rHi, #0x14` / `lsrs r1, rLo, #0xc`
 * / `orrs r1, r0` is the low word of a `>> 12` on a 64 bit value with the high
 * word dead, which is what the cast back to `s32` makes of it; the shift of
 * the low half is `lsrs` and not `asrs` whatever the sign of the value,
 * because it is a bit-field splice and not an arithmetic shift.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The shifted product needs a named local, or the translation row is loaded
 * ten bytes too early.**  Written as one expression,
 *
 *     dst->x = (s32)((...) >> 12) + mtx->m[3][0];
 *
 * the compiler loads `mtx->m[3][0]` before the last two adds of the 64 bit
 * accumulation, which then needs two register copies to get the helper's
 * result out of r0:r1; the function grows twelve bytes and 248 concrete bytes
 * differ, all of them scheduling.  Splitting the statement,
 *
 *     r = (s32)((...) >> 12);
 *     dst->x = r + mtx->m[3][0];
 *
 * is EXACT.  Holding the 64 bit sum in an `s64` local instead and casting at
 * the store is byte-identical, so the image does not say which of the two the
 * source wrote, only that it was not one expression.
 *
 * **The three vector components are read into locals, and the sign extension
 * is what they are read for.**  `v` is `const` and `dst` is not, so a store
 * through `dst` may alias `v`; written as `v->x` inside all twelve products
 * the compiler reloads and re-extends each component for every output and
 * comes out four bytes short with the whole body rescheduled.  Three `s32`
 * locals assigned at the top make the six words of sign-extended vector one
 * CSE that lives on the stack at sp+4 through sp+0x18 for the whole function,
 * which is the original's frame.  The same three values held as `s64` locals
 * are twelve bytes longer, so the source's locals are 32 bit and the cast is
 * at the multiply.
 *
 * Nothing here is version specific: every constant is a matrix offset or the
 * fixed-point shift.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02016FC8.c  *       --addr 0x02016FC8 --thumb
 */
void func_02016FC8(const struct VecFx32 *v, const struct MtxFx44 *mtx,
                   struct VecFx32 *dst, s32 *w)
{
    s32 vx;
    s32 vy;
    s32 vz;
    s32 r;

    vx = v->x;
    vy = v->y;
    vz = v->z;

    r = (s32)(((s64)vx * mtx->m[0][0] + (s64)vy * mtx->m[1][0]
                    + (s64)vz * mtx->m[2][0]) >> 12);
    dst->x = r + mtx->m[3][0];
    r = (s32)(((s64)vx * mtx->m[0][1] + (s64)vy * mtx->m[1][1]
                    + (s64)vz * mtx->m[2][1]) >> 12);
    dst->y = r + mtx->m[3][1];
    r = (s32)(((s64)vx * mtx->m[0][2] + (s64)vy * mtx->m[1][2]
                    + (s64)vz * mtx->m[2][2]) >> 12);
    dst->z = r + mtx->m[3][2];
    r = (s32)(((s64)vx * mtx->m[0][3] + (s64)vy * mtx->m[1][3]
                    + (s64)vz * mtx->m[2][3]) >> 12);
    *w = r + mtx->m[3][3];
}



/*
 * The first of two parallel fillers of the same nine word record.
 * func_02017168 builds it from the five values func_02017114 reads out of the
 * save block and writes 0 into the last word; its twin at 0x02017214 builds
 * the same record from a pair of pointers and writes 1, so that word is the
 * tag saying which of the two produced it.  The twin is parked in
 * src/pending/unit_02017214.c: it is the only caller of six of its eight
 * callees.
 *
 * func_02017100 passes its first argument through func_020185F4 rather than
 * holding it in a callee-saved register, which is only possible because that
 * function returns its argument: it is the two byte `bx lr` at 0x020185F4 that
 * src/matched/unit_020185F0.c matches as an empty hook.  Written as a void
 * call followed by func_02017114(p, ...) the first argument would have to be
 * saved across it and the function grows a register.
 */
void func_02017100(void *p, struct Stats *out, u32 lvl)
{
    func_02017114(func_020185F4(p), out, lvl);
}

void func_02017114(void *p, struct Stats *out, u32 lvl)
{
    u32 a0 = func_02017E88(p, 5, 0);
    u32 a1 = func_02017E88(p, 0x6F, 0);
    u32 a2 = func_02017E88(p, 0x6E, 0);
    u32 a3 = func_02017EB4(p);
    u32 a4 = func_02017E88(p, 0x4C, 0);

    func_02017168(a0, a1, a2, a3, a4, out, lvl);
}

void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6)
{
    out->unk00 = func_0202D060();
    out->unk04 = func_0202D09C(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk08 = func_0202D0D4(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk0C = func_0202D110(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk10 = func_0202D144(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk14 = func_0202D178(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk18 = func_0202D1AC(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk1C = func_0202D1E0(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk20 = 0;
}


/*
 * Promoted from src/pending/ during a shard verify sweep: all six of its
 * previously witness-less callees (func_0202D5F8, func_0202D640,
 * func_0202D664, func_0202D688, func_0202D6AC, func_0202D6D0) are now
 * EXACT matched entries elsewhere in the tree, so the `matched` class
 * resolves every site that was stuck wildcarded and this closes to
 * EXACT with no change to the C.
 *
 * This is the twin of func_02017168 in src/matched/unit_02017100.c: the
 * same nine word record, built from a pair of pointers instead of from
 * five save block fields, with 1 in the last word where the other
 * writes 0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02017214.c \
 *       --addr 0x02017214 --thumb
 */
void func_02017214(void *p, struct Stats *out, void *q)
{
    out->unk00 = func_0202D5CC((u32)q);
    out->unk04 = func_0202D5F8((u32)p, (u32)q);
    out->unk08 = func_0202D61C((u32)p, (u32)q);
    out->unk0C = func_0202D640((u32)p, (u32)q);
    out->unk10 = func_0202D664((u32)p, (u32)q);
    out->unk14 = func_0202D688((u32)p, (u32)q);
    out->unk18 = func_0202D6AC((u32)p, (u32)q);
    out->unk1C = func_0202D6D0((u32)p, (u32)q);
    out->unk20 = 1;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017270.c \
 *       --func func_02017270 --addr 0x02017270 --cc 1.1p1 --thumb
 */
void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 buf[0x24];

    func_020172AC((int)a0, func_02017E1C(a1, 0, 0));
    func_02017100(a1, (struct Stats *)buf, a2);
    return func_020159C8(a0, a3, a4, a5, (const struct Sub150 *)buf);
}


/*
 * A four-instruction tail call: the second argument is replaced by a function
 * pointer (the pool word 0x020172BD, the Thumb bit set), the first and third
 * pass through, and the target is loaded from the pool and branched to with
 * `bx r3`.  The callee is the label-less Thumb leaf src/matched/sub_02014CF0.c.
 *
 * The `symbols:` line is load-bearing.  Without it the name `func_02014CF0`
 * carries the address but the naming convention can only guess the ISA, and
 * an address no `func_` label was traced at is guessed ARM -- so the site
 * was reported as "02014CF0 (arm, from name) has no witness" and the file sat
 * at MATCH, because sub_02014CF0 is a Thumb manifest entry and the `matched`
 * class refuses an ISA that does not agree with it.  Declaring the ISA
 * explicitly (origin "header") resolves the word to 0x02014CF1, which is what
 * the image holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172AC.c \
 *       --func func_020172AC --addr 0x020172AC --cc 1.1p1 --thumb
 */
void func_020172AC(int a0, int a1)
{
    sub_02014CF0((struct Obj02014CF0 *)a0, (int)func_020172BC, a1);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172BC.c \
 *       --func func_020172BC --addr 0x020172BC --cc 1.1p1 --thumb
 */
u32 func_020172BC(u8 *a0, u8 **a1, u32 a2)
{
    if (((struct Obj15713 *)a0)->f1C == 0x1994) {
        func_020172D8((u8 *)(((struct Obj15715 *)(*a1))->f14), a2);
    }
    return 1;
}



/*
 * mcss.c.  Walks four (x, y) offset lists and bumps the matching nibble of
 * two bytes per point.  Lever (wave 16): the read-modify-write of a0[p] is a
 * compound assignment `a0[p] += 0x50` / `a0[p] += 5`; the spelled-out
 * `a0[p] = (u8)(val + 0x50)` left a three-register rotation (a0/k/b0, 47
 * bytes out) that no declaration order, scope, type or permuter run moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172D8.c \
 *       --func func_020172D8 --addr 0x020172D8 --cc 1.1p1 --thumb
 */
void func_020172D8(u8 *a0, u32 a1)
{
    const u8 *cur;
    s32 i;
    s32 n;
    s32 d[2];

    for (i = 0; i < 4; i++) {
        cur = sMcssTable[i];
        n = 0;
        if (cur[0] != 0xff) {
            d[1] = (a1 & 0xf) - 8;
            d[0] = ((a1 & 0xf0) >> 4) - 8;
            do {
                u8 b0 = (u8)(d[1] + cur[n * 2]);
                u32 b1 = (u8)(d[0] + cur[n * 2 + 1]);
                u32 idx[2];
                s32 k;
                idx[0] = ((u32)b0 >> 1) + (b1 << 7);
                idx[1] = ((u32)b0 >> 1) + ((b1 + 0x28) << 7);
                for (k = 0; k < 2; k++) {
                    if ((b0 & 1) != 0) {
                        u32 p = idx[k];
                        u8 val = a0[p];
                        s32 v = val & 0xf0;
                        if (v >= 0x10 && v <= 0x30) {
                            a0[p] += 0x50;
                        }
                    } else {
                        u32 p = idx[k];
                        u8 val = a0[p];
                        s32 v = 0xf & val;
                        if (v >= 1 && v <= 3) {
                            a0[p] += 5;
                        }
                    }
                }
                n = (u8)(n + 1);
            } while (cur[n * 2] != 0xff);
        }
        a1 = a1 >> 8;
    }
}

int func_020173B4(int a0){ int t0 = func_02015F2C((int)a0, (int)(a0 + 0), (int)0x20173C9, (int)1); return t0; }
