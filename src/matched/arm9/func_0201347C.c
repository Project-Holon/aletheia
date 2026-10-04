/*
 * function: func_0201347C
 * address:  0x0201347C
 * packet:   pkt_02013360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020076D0   0x020076D0  thumb
 *   func_0201293C   0x0201293C  thumb
 *   func_020130C4   0x020130C4  thumb
 *   func_02013144   0x02013144  thumb
 *   func_0201333C   0x0201333C  thumb
 *   func_02013360   0x02013360  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_0201AA14   0x0201AA14  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AC2C   0x0201AC2C  thumb
 *
 * btl_setup.c.  The link-battle variant of the setup builder: the same
 * three shared writers as func_020135C0, then the object is put in mode 0
 * and a consistency check on the +0x24 slot decides whether flag 0x40 is
 * set.
 *
 * The documented near miss in docs/notes/pkt_02013360.c.txt compiled 122
 * bytes against 120 and missed on 108 of them.  Two leftover-register
 * readings are what close it, and both are the same idiom, see
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 *
 * (1) func_0201AC2C takes the func_0201A920 result as a second argument.
 * The original writes `adds r1, r0, #0; str r1, [r4, #0x28]`, which reads
 * as a gratuitous register copy before the store.  It is not: r1 is the
 * second argument of the guarded func_0201AC2C call below, so the value has
 * to reach r1 anyway and the store then sources it from there.  The
 * declaration has to be variadic, `void func_0201AC2C(u32 a, ...)`, because
 * the other call site of this family (in func_020135C0, EXACT) passes two
 * registers while some pass one; a fixed two-parameter declaration emits a
 * spurious `movs r1, #0`.  This is the same finding
 * docs/notes/pkt_02013528.c.txt reached for func_020135C0.
 *
 * (2) func_020076D0 takes THREE arguments, and its first is the return
 * value of the func_0201293C call immediately above it.  The original sets
 * only r1 and r2 (`add r1, sp, #4; add r2, sp, #0`) and leaves r0 holding
 * what func_0201293C returned.  Declaring it with two parameters puts the
 * two pointers in r0/r1 and is a two-byte, two-instruction miss; declaring
 * func_0201293C as returning u32 and passing that result explicitly gives
 * the original bytes with no extra `adds`, because the value is already in
 * r0 and the compiler elides the copy.
 *
 * The two out-parameters are declared x then y but passed &x as the SECOND
 * argument and &y as the third: x lives at sp+4 and y at sp+0, which is the
 * later-declaration-at-the-lower-address rule, see
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * EXACT*: all 118 code bytes reproduce (10 of 10 relocation sites
 * resolved); the inferred extent ran two bytes long only on the
 * `movs r0, r0` alignment pad at 0x020134F2 before func_020134F4.  Never a
 * byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201347C.c \
 *       --func func_0201347C --addr 0x0201347C --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
extern void func_020130C4(u8 *p);
struct Party;
struct Rec534;
extern void func_02013360(u8 *o, void *a1, const void *a2);
extern void func_0201333C(void *a, void *b, u16 c);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern u32  func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_0201293C(const struct BigObj *p);
extern int  func_020076D0(u32 s, u32 *a, u32 *b);
extern void func_02013144(void *a, int b);

void func_0201347C(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5)
{
    u32 x;
    u32 y;
    u32 r;
    u32 t;
    u32 u;

    func_020130C4(a0);
    func_02013360(a0, a1, (const void *)a3);
    func_0201333C(a0, a1, a5);
    r = (u32)func_0201A920(a5);
    ((struct Obj00155 *)a0)->f28 = r;
    if (a2 != 0) {
        func_0201AC2C((const struct Rec534 *)a2, (struct Rec534 *)r);
    }
    ((struct Obj00155 *)a0)->f4 = a4;
    ((struct Obj00155 *)a0)->f0 = 0;
    t = func_0201AA18((void *)((struct Obj00155 *)a0)->f24);
    if (t != func_0201AA14((void *)(((struct Obj00155 *)a0)->f24))) {
        return;
    }
    u = func_0201293C(a1);
    x = 0;
    y = 0;
    if (func_020076D0(u, &x, &y) == 0) {
        func_02013144(a0, 0x40);
    }
}
