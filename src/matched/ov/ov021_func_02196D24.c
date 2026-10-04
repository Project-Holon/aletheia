/*
 * function: func_02196D24
 * address:  0x02196D24
 * packet:   pkt_ov021_02196D24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3F9C     0x021D3F9C  data  ov021  a1
 *   func_02196CD8  0x02196CD8  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196D20  0x02196D20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj { u32 x0; u32 x4; u32 x8; u32 xc; u8 pad[0x284]; void *objs[27]; u32 mode; } Obj;
typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;
typedef struct { u8 v[3]; } Tbl3;
extern const Tbl3 d_021D3F9C;
struct Actor;
extern void func_02196CD8(u8 *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(void *, Req *);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj *, void (*)(), u32);
extern void func_02196D20();

void func_02196D24(Obj *a)
{
    Tbl3 t = d_021D3F9C;
    Req r;
    int i;

    i = t.v[a->xc];
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196CD8;
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], &r);
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_02196D20, 0x504);
}
