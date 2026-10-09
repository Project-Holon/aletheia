/*
 * file:     script_work_p03.c
 * unit:     yes
 * function: func_02158A90, func_02158AC8, func_02158AD4, func_02158AE0, func_02158B00, func_02158B3C, func_02158B6C, func_02158BFC, func_02158CB4, func_02158CD0, func_02158D78, func_02158D90, func_02158DB0, func_02158DBC, func_02158DE8, func_02158E38, func_02158E54, func_02158E7C, func_02158F18, func_02158F50, func_02158F54, func_02158F58, func_02158F6C, func_02158F74, func_02158F78, func_02158F7C, func_02158F80, func_02158F84, func_02158F88, func_02158F8C, func_02158F90, func_02158F94, func_02158FB4, func_02158FB8, func_02158FBC, func_02158FD0
 * address:  0x02158A90
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
 *   func_020120F4 0x020120F4 thumb
 *   func_02012844 0x02012844 thumb
 *   func_02162450 0x02162450 thumb ov010
 *   func_02158A34 0x02158A34 thumb ov010
 *   func_0201296C   0x0201296C  thumb
 *   func_021589F4   0x021589F4  thumb  ov010
 *   func_02158768 0x02158768 thumb ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_0215A55C  0x0215A55C  thumb  ov010
 *   func_0201121C  0x0201121C  thumb
 *   func_0201126C  0x0201126C  thumb
 *   func_0215A760  0x0215A760  thumb  ov010
 *   func_0201127C  0x0201127C  thumb
 *   func_0201134C  0x0201134C  thumb
 *   d_0217062C     0x0217062C  data  ov010
 *   d_021705D8     0x021705D8  data  ov010
 *   func_02011324  0x02011324  thumb
 *   func_0215A5A4  0x0215A5A4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02011264  0x02011264  thumb
 *   func_02034714  0x02034714  arm
 *   func_02013B5C  0x02013B5C  thumb
 *   func_02013B68  0x02013B68  thumb
 *   d_021701A8     0x021701A8  data  a4
 *   d_02172898     0x02172898  data  ov010  a1
 *   func_0204A1BC 0x0204A1BC arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_0203CF5C  0x0203CF5C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020053EC  0x020053EC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 *   func_02011328 0x02011328 thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02082A7C  0x02082A7C  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0215A514  0x0215A514  thumb  ov010
 *   func_02159130  0x02159130  thumb  ov010
 *   d_0217289C     0x0217289C  data  ov010  a1
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_0215A554  0x0215A554  thumb  ov010
 *   func_0216D588 0x0216D588 thumb ov010
 */
#include "../../matched/include/Obj17627.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj00105.h"
#include "../../matched/include/Obj17628.h"
#include "../../matched/include/Obj17629.h"
#include "../../matched/include/Obj17630.h"
#include "../../matched/include/Obj17631.h"
#include "../../matched/include/Obj17632.h"
#include "../../matched/include/Obj17633.h"
#include "../../matched/include/Obj17634.h"
#include "../../matched/include/Obj18753.h"
#include "../../matched/include/Obj17635.h"
#include "../../matched/include/Obj17636.h"
#include "../../matched/include/Obj17637.h"
#include "../../matched/include/Obj00005.h"

struct Ctx;
struct BigObj;
struct Desc;
struct ScriptVm;
struct ScriptVmParams;
struct Cursor;
struct WordSet;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct V { u16 x, y; int a; int b; int c; };

struct W { u16 w, h; int p; int q; };

struct E { u16 lo, hi, a, b, c; };

struct Bits { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; };

struct O {
    int f0; u16 f4; int f8; u16 fc; int f10, f14, f18[3];
    int f24;
    int f20, f28, f2c, f30, f34;
};

typedef signed short   s16;

extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162450(void *p);
extern void func_02158A34(int, int, int, int);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021589F4(int a0);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_0215A55C(const struct V *, int);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern void func_0215A760(u8 *a, unsigned b, unsigned c);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern u32 func_0201134C(struct Cursor *p);
extern void *func_02011324(struct ScriptVm *vm);
extern int func_0215A5A4(int a0);
extern int func_020307B0();
extern int func_02011264();
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_02013B5C(u32 id);
extern u16 func_02013B68(u16);
extern int func_0204A1BC(int, int, int, int);
extern int func_0203CD98();
extern int func_0203CF04();
extern int func_0203CEAC(int a0);
extern int func_0203D0D0();
extern u32 func_0203CF5C(void);
extern int func_0203CDBC();
extern int func_020053EC();
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0215A5D4(void *p);
extern u32 func_0215A5D8(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_02011328(void *, int (*)(int, void *, void *, int), void *);
extern int func_02082A7C();
extern int func_02188C54();
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0215A514(int a, int heap);
extern void func_02159130(void);
extern int func_0201ED04();
extern int func_02045808();
extern int func_0215A554();
extern u16 func_0216D588(void *);
int func_02158A90(void *a, int unused, int key, int d);
void func_02158AC8(int a, int b);
void func_02158AD4(int a, int b);
/* * Two arm9 frame calls, an overlay reset, then the four-argument submit. */ void func_02158AE0(void *a0, void *a1);
void *func_02158B00(void *a, u32 b);
int func_02158B3C(const u8 *p, int key);
/* * levers: wave76 reused cursor p across both parsing phases; p += 6 at the * matched key, then p += key before save accessor. Local base/q produced * DIFF40; cursor reuse alone31, resetting it through base129; in-place * advances give EXACT. Permuter300 previously consumed, not repeated. */ u16 func_02158B6C(const void *a, const u8 *list, u32 key);
int *func_02158BFC(u16 a0, int a1, u16 a2, u16 a3, int a4);
int func_02158CB4(int a0);
/* * Looks up value v in a table of 46 range records (lo, hi, a, b, c). * Writes a, b, c to the three outputs and returns v - lo. Past the table * it falls back to two lookups by k, or to fixed outputs when v is 0. * 2026-10-05 (wave P15): the table is const and the three outputs are * stored directly from the record. The old DIFF 14 B draft copied b and c * into u16 locals; that form is not needed. */ u16 func_02158CD0(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3);
/* * The null pointer local is the branch condition, not parameter b. * Lever: a-null-pointer-local-tested-reuses-the-movs-flags.md. * Extent follower 0x02158D90 already has its own matched shard. */ void *func_02158D78(int a, int b);
/* * Unlabelled leaf (a .word run in the ov010 listing): 0 for 2000, 1 below * 0x291C, else 0. Callee of ov021 func_0218A0E4, func_0218A278 and * func_02189BD0. * Addresses are Black-image addresses. */ int func_02158D90(u16 v);
int func_02158DB0(int a0);
int func_02158DBC(void);
int func_02158DE8(int a, int b, int c, int idx);
/* * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28. */ void func_02158E38(void *a);
int func_02158E54(int a0, int a1);
int *func_02158E7C(u16 a, int b, int c, int d, int e, int f);
int func_02158F18(int a0);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02158F50.c \ * --func func_02158F50 --addr 0x02158F50 --region ov010 --cc dsi/1.1p1 --thumb */ void *func_02158F50(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02158F54.c \ * --func func_02158F54 --addr 0x02158F54 --region ov010 --cc dsi/1.1p1 --thumb */ void *func_02158F54(void *p);
int func_02158F58(int a0);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02158F6C.c \ * --func func_02158F6C --addr 0x02158F6C --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_02158F6C(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02158F74.c \ * --func func_02158F74 --addr 0x02158F74 --region ov010 --cc dsi/1.1p1 --thumb */ void *func_02158F74(void *p);
/* * Reads the word field at +0x30. * * Addresses are Black-image addresses. */ u32 func_02158F78(u8 *p);
/* * Reads the word field at +0x34. * * Addresses are Black-image addresses. */ u32 func_02158F7C(u8 *p);
/* * Stores the word field at +0x38. * * Addresses are Black-image addresses. */ void func_02158F80(u8 *p, u32 v);
u32 func_02158F84(u8 *p);
/* * Unlabelled leaf, blocker of ov021 func_021AF1E8..func_021AF26C: address of the field at +0x40. * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here, * ov010 holds this Thumb routine, and the ov021 callers already name ov010 * (ov010 is the overlay resident with ov021). * * Addresses are Black-image addresses. */ u8 *func_02158F88(void *p);
/* * Reads the halfword field at +0x4. * * Addresses are Black-image addresses. */ u16 func_02158F8C(u8 *p);
/* * Reads the word field at +0x8. * * Addresses are Black-image addresses. */ void *func_02158F90(void *p);
void func_02158F94(void *p, void *q, int a2);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Returns the address of an interior member (field address), pool-free leaf. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02158FB4.c \ * --func func_02158FB4 --addr 0x02158FB4 --region ov010 --cc dsi/1.1p1 --thumb */ void *func_02158FB4(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02158FB8.c \ * --func func_02158FB8 --addr 0x02158FB8 --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_02158FB8(void *p);
void func_02158FBC(int a0);
int func_02158FD0(int a0, u32 a1, int a2);
extern int d_0217062C;
extern int d_021705D8;
extern const struct E d_021701A8[];
extern char d_02172898[];
extern struct Bits d_02170374[];
extern char d_0217289C[];





int func_02158A90(void *a, int unused, int key, int d) {
    int result = func_02158B3C((const u8 *)func_02162450((void *)func_02012844(func_020120F4(a))), key);
    if (result == 0xffff) return 0;
    func_02158A34((int)a, 0, result, d);
    return 1;
}







void func_02158AC8(int a, int b)
{
    func_02158A90((void *)a, b, 4, 1);
}







void func_02158AD4(int a, int b)
{
    func_02158A90((void *)a, b, 3, 1);
}







/*
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 */
void func_02158AE0(void *a0, void *a1)
{
    func_021589F4(func_0201296C(func_020120F4(a0)));
    func_02158A90(a0, (int)a1, 2, 2);
}






void *func_02158B00(void *a, u32 b) {
    void *s = func_020120F4(a);
    int msg = func_02158B6C(s, (const u8 *)func_02162450((void *)func_02012844(s)), 1);
    if (msg == 0xffff) return 0;
    return func_02158768((int)a, msg, 0, b);
}





int func_02158B3C(const u8 *p, int key) {
    for (;;) {
        u16 v = p[0] + (p[1] << 8);
        if (v == 0) return 0xffff;
        if (key == v) return (u16)(p[2] + (p[3] << 8));
        p += 6;
    }
}





inline static u16 RD16(const u8 *p)
{
  return (u16) (p[0] + (p[1] << 8));
}






/*
 * levers: wave76 reused cursor p across both parsing phases; p += 6 at the
 * matched key, then p += key before save accessor. Local base/q produced
 * DIFF40; cursor reuse alone31, resetting it through base129; in-place
 * advances give EXACT. Permuter300 previously consumed, not repeated.
 */
u16 func_02158B6C(const void *a, const u8 *list, u32 key)
{
  const u8 *p = list;
  u32 h;
  const u8 *tmp;
  int pad;
  u16 tmp1;
  u32 tmp2;
  for (;; p += 6)
  {
    u32 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (key == id)
    {
      key = ((p[2] + (p[3] << 8)) + (p[4] << 16)) + (p[5] << 24);
      p += 6;
      break;
    }
  }

  if (key == 0)
    return 0xFFFF;
  p += key;
  tmp2 = func_0201296C(a);
  h = tmp2;
  for (;; p += 6)
  {
    u16 val;
    u16 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (id == 0)
      return 0xFFFF;
    tmp1 = RD16(p + 2);
    val = tmp1;
    if (val == (*((u16 *)func_020143CC(h, id))))
      return RD16(p + 4);
  }

}






int *func_02158BFC(u16 a0, int a1, u16 a2, u16 a3, int a4)
{
    struct V v;
    struct W w;
    u16 s[4];
    int r6, t, n;
    int *o;

    r6 = func_02158DB0(a4);
    v.x = a2;
    v.y = a3;
    v.a = a4;
    v.b = r6;
    v.c = a1;
    t = func_0215A55C(&v, a0);
    w.w = 0x100;
    w.h = 0x40;
    w.p = (int)&d_0217062C;
    w.q = d_021705D8;
    o = (int *)func_0201121C(a0, (const struct ScriptVmParams *)(&w));
    func_0201126C((struct ScriptVm *)o, (void *)t);
    n = func_02158CD0(a2, a3, &s[2], &s[1], &s[0]);
    o[0x2C / 4] = (int)func_02158D78(s[2], a0);
    if (r6 == 0) {
        if (s[0] != -1)
            func_0215A760((u8 *)t, s[1], s[0]);
    }
    func_0201127C((struct ScriptVm *)o, (u8 *)o[0x2C / 4]);
    o[0x14 / 4] += n << 2;
    o[0x14 / 4] += func_0201134C((struct Cursor *)o);
    func_02158E38(o);
    return o;
}






int func_02158CB4(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_02011324((struct ScriptVm *)a0);
loc_02158CBC:
    a0 = func_0215A5A4((int)p);
loc_02158CC0:
a0 = ((struct Obj17627 *)t4)->f2C;
    a0 = func_020307B0(a0);
loc_02158CC6:
a0 = t4 + 0;
    a0 = func_02011264(a0);
loc_02158CCC:
    return a0;}






/*
 * Looks up value v in a table of 46 range records (lo, hi, a, b, c).
 * Writes a, b, c to the three outputs and returns v - lo. Past the table
 * it falls back to two lookups by k, or to fixed outputs when v is 0.
 * 2026-10-05 (wave P15): the table is const and the three outputs are
 * stored directly from the record. The old DIFF 14 B draft copied b and c
 * into u16 locals; that form is not needed.
 */
u16 func_02158CD0(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3)
{
    unsigned i;
    const struct E *t = d_021701A8;
    const struct E *e;
    for (i = 0; i < 46; i++) {
        if (v < t[i].lo)
            continue;
        if (v > t[i].hi)
            func_02034714(d_02172898, (int)0, d_02172898);
        e = &t[i];
        *o1 = e->a;
        *o2 = e->b;
        *o3 = e->c;
        return v - t[i].lo;
    }
    if (v >= 1) {
        u16 x = (u16)func_02013B5C((u16)k);
        u16 y = func_02013B68(k);
        *o1 = x;
        *o2 = 3;
        *o3 = y;
        return v - 1;
    }
    *o1 = 0x356;
    *o2 = 3;
    *o3 = 0x9E;
    return 0;
}





/*
 * The null pointer local is the branch condition, not parameter b.
 * Lever: a-null-pointer-local-tested-reuses-the-movs-flags.md.
 * Extent follower 0x02158D90 already has its own matched shard.
 */
void *func_02158D78(int a, int b) {
    void *result = 0;
    if (result == 0) result = (void *)func_0204A1BC(0x39, a, (int)result, b);
    return result;
}






/*
 * Unlabelled leaf (a .word run in the ov010 listing): 0 for 2000, 1 below
 * 0x291C, else 0.  Callee of ov021 func_0218A0E4, func_0218A278 and
 * func_02189BD0.
 * Addresses are Black-image addresses.
 */
int func_02158D90(u16 v)
{
    if (v == 2000)
        return 0;
    if (v < 0x291C)
        return 1;
    return 0;
}








int func_02158DB0(int a0)
{

    if (a0 == 0) goto loc_02158DB8;
loc_02158DB4:
a0 = 1;
    return a0;
loc_02158DB8:
a0 = 0;
    return a0;}






int func_02158DBC(void)
{
    int a0;

    a0 = func_0203CD98();
loc_02158DC2:
    if (a0 == 0) goto loc_02158DE0;
loc_02158DC6:
    a0 = func_0203CF04();
loc_02158DCA:
a0 = 0;
    a0 = func_0203CEAC(a0);
loc_02158DD0:
    a0 = func_0203D0D0();
loc_02158DD4:
    a0 = func_0203CF5C();
loc_02158DD8:
    a0 = func_0203CDBC(a0);
loc_02158DDC:
    if (a0 == 0) goto loc_02158DD4;
loc_02158DE0:
    a0 = func_020053EC();
loc_02158DE4:
    goto loc_02158DE0;}





int func_02158DE8(int a, int b, int c, int idx)
{
    int m, r;
    func_0201210C((void *)c);
    func_0215A5D4((void *)b);
    m = func_0215A5D8((void *)b);
    r = 0;
    switch (m) {
    case 0: r = d_02170374[idx].b0; break;
    case 1: r = d_02170374[idx].b1; break;
    case 2: r = d_02170374[idx].b2; break;
    }
    if (r == 0)
        func_02158DBC();
    return r;
}




/*
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 */
void func_02158E38(void *a) {
    void *b = func_0215A5DC(func_02011324(a));
    func_02011328(a, (int (*)(int,  void *, void *, int))func_02158DE8, b);
}





int func_02158E54(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a0 + 0;
a0 = a1 + 0;
    t4 = func_0201210C((const struct Ctx *)a0);
loc_02158E5E:
a0 = 0;
a1 = t5 + 0;
a2 = 8;
    a0 = func_02082A7C(a0, a1, a2);
loc_02158E6A:
((struct Obj00020 *)t5)->f4 = t4;
    if (t4 == 0) goto loc_02158E78;
loc_02158E70:
a0 = (int)t4 + 0; /* int-typed on purpose: pointer local changes codegen */
    a0 = func_02188C54(a0);
loc_02158E76:
((struct Obj00020 *)((char *)t5))->f0 = a0;
loc_02158E78:
    return a0;}





int *func_02158E7C(u16 a, int b, int c, int d, int e, int f)
{
    int *p = func_02030734(a, 0x14C, 1, d_0217289C, 0xAF);
    p[0] = 0x3643F;
    *(u16 *)(p + 3) = a;
    p[4] = b;
    p[5] = c;
    ((struct Obj00105 *)p)->f4 = d;
    p[2] = 0;
    p[8] = e;
    p[10] = f;
    p[9] = func_02158DB0(f);
    if (p[9] == 0) {
        p[11] = (int)func_0201EC74(0x1C, 0x40, a);
        p[12] = (int)func_020457B0(0x500, a);
        p[13] = (int)func_020457B0(0x500, a);
    } else {
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
    }
    p[0x52] = (int)func_0215A514((int)p, a);
    func_02158E54((int)(p + 6), b);
    if (p[9] == 0)
        func_02159130();
    return p;
}





int func_02158F18(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = 0;
*(int *)((char *)t4) = a0;
a0 = ((struct Obj00105 *)t4)->f2C;
    if (a0 == 0) goto loc_02158F2A;
loc_02158F26:
    a0 = func_0201ED04(a0);
loc_02158F2A:
a0 = ((struct Obj00105 *)t4)->f30;
    if (a0 == 0) goto loc_02158F34;
loc_02158F30:
    a0 = func_02045808(a0);
loc_02158F34:
a0 = ((struct Obj00105 *)t4)->f34;
    if (a0 == 0) goto loc_02158F3E;
loc_02158F3A:
    a0 = func_02045808(a0);
loc_02158F3E:
a0 = 0x52;
a0 = a0 << 2;
a0 = *(int *)((char *)t4 + a0);
    a0 = func_0215A554(a0);
loc_02158F48:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02158F4E:
    return a0;}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F50.c \
 *       --func func_02158F50 --addr 0x02158F50 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F50(void *p) { return ((struct Obj17628 *)p)->f14; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F54.c \
 *       --func func_02158F54 --addr 0x02158F54 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F54(void *p) { return ((struct Obj17629 *)p)->f10; }





int func_02158F58(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a1 = ((struct Obj17630 *)t4)->f10;
a0 = a0 + 0x18;
    a0 = func_02158E54(a0, a1);
loc_02158F64:
t4 = t4 + 0x18;
a0 = t4 + 0;
    return a0;}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F6C.c \
 *       --func func_02158F6C --addr 0x02158F6C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02158F6C(void *p) { return ((struct Obj17631 *)p)->f148; }





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F74.c \
 *       --func func_02158F74 --addr 0x02158F74 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F74(void *p) { return ((struct Obj00020 *)p)->f2C; }






/*
 * Reads the word field at +0x30.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02158F78(u8 *p)
{
    return ((struct Obj17632 *)p)->f30;
}






/*
 * Reads the word field at +0x34.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02158F7C(u8 *p)
{
    return ((struct Obj17633 *)p)->f34;
}






/*
 * Stores the word field at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_02158F80(u8 *p, u32 v)
{
    ((struct Obj17634 *)p)->f38 = v;
}





u32 func_02158F84(u8 *p)
{
    return ((struct Obj18753 *)p)->f38;
}





/*
 * Unlabelled leaf, blocker of ov021 func_021AF1E8..func_021AF26C: address of the field at +0x40.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02158F88(void *p)
{
    return (u8 *)p + 0x40;
}






/*
 * Reads the halfword field at +0x4.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02158F8C(u8 *p)
{
    return ((struct Obj17635 *)p)->f4;
}






/*
 * Reads the word field at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void *func_02158F90(void *p)
{
    return ((struct Obj17636 *)p)->f8;
}



void func_02158F94(void *p, void *q, int a2)
{
    *(void **)((char *)p + 8) = q;
    if (q != 0) {
        u16 *r = (u16 *)func_02158FD0((int)p, 0x8011, a2);
        *r = func_0216D588(q);
    }
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158FB4.c \
 *       --func func_02158FB4 --addr 0x02158FB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158FB4(void *p) { return (char *)p + 60; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158FB8.c \
 *       --func func_02158FB8 --addr 0x02158FB8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02158FB8(void *p) { return ((struct Obj17637 *)p)->f3C; }




void func_02158FBC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00005 *)t4)->f3C;
    if (a0 == 0) goto loc_02158FCE;
loc_02158FC6:
    a0 = func_020307B0(a0);
loc_02158FCA:
a0 = 0;
((struct Obj00005 *)t4)->f3C = a0;
loc_02158FCE:
    return;}




int func_02158FD0(int a0, u32 a1, int a2)
{

a2 = 2;
a2 = a2 << 0xe;
a1 = a1 - a2;
a0 = a0 + 0x7c;
a1 = a1 << 1;
a0 = a0 + a1;
    return a0;}
