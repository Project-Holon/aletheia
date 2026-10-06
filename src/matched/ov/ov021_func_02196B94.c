/*
 * function: func_02196B94
 * address:  0x02196B94
 * packet:   pkt_ov021_02196B94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02196B7C  0x02196B7C  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196B90  0x02196B90  thumb  ov021
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
extern void func_02196B7C(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
struct Cmd;
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj *, void (*)(), u32);
extern void func_02196B90();

void func_02196B94(Obj *a)
{
    Req r;

    r.x0 = 0;
    r.a = a;
    r.cb = func_02196B7C;
    func_0204B92C(a->objs[a->mode], 1);
    func_0204BA00(a->objs[a->mode], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[a->mode]);
    func_02196034(a, func_02196B90, 0x492);
}
