/*
 * file:     script_work_p11.c
 * unit:     yes
 * function: func_02158B3C, func_02158B6C, func_02158BFC, func_02158CB4, func_02158CD0, func_02158D78, func_02158D90, func_02158DB0, func_02158DBC
 * address:  0x02158B3C
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
 *   func_0201296C  0x0201296C  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_0215A55C  0x0215A55C  thumb  ov010
 *   func_0201121C  0x0201121C  thumb
 *   func_0201126C  0x0201126C  thumb
 *   func_0215A760  0x0215A760  thumb  ov010
 *   func_0201127C  0x0201127C  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_02158E38  0x02158E38  thumb  ov010
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
 */
#include "../../matched/include/Obj17627.h"

struct BigObj;
struct ScriptVm;
struct ScriptVmParams;
struct Cursor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct V { u16 x, y; int a; int b; int c; };

struct W { u16 w, h; int p; int q; };

struct E { u16 lo, hi, a, b, c; };

extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_0215A55C(const struct V *, int);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern void func_0215A760(u8 *a, unsigned b, unsigned c);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern u32 func_0201134C(struct Cursor *p);
extern void func_02158E38(void *a);
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
int func_02158B3C(const u8 *p, int key);
u16 func_02158B6C(const void *a, const u8 *list, u32 key);
int *func_02158BFC(u16 a0, int a1, u16 a2, u16 a3, int a4);
int func_02158CB4(int a0);
u16 func_02158CD0(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3);
void *func_02158D78(int a, int b);
int func_02158D90(u16 v);
int func_02158DB0(int a0);
int func_02158DBC(void);
extern int d_0217062C;
extern int d_021705D8;
extern const struct E d_021701A8[];
extern char d_02172898[];

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
