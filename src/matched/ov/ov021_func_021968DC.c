/*
 * function: func_021968DC
 * address:  0x021968DC
 * packet:   pkt_ov021_021968DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219686C  0x0219686C  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_021968D8  0x021968D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj { u8 pad[0x294]; void *objs[27]; u32 mode; } Obj;
typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;
struct Actor;
extern void func_0219686C(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(void *, Req *);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj *, void (*)(), u32);
extern void func_021968D8();

void func_021968DC(Obj *a)
{
    Req r;
    u32 i;

    i = a->mode;
    r.x0 = 0;
    r.a = a;
    r.cb = func_0219686C;
    if (i == 5) {
        i = 0;
    } else if (i == 6) {
        i = 1;
    } else if (i == 7) {
        i = 3;
    }
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], &r);
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_021968D8, 0x3BF);
}
