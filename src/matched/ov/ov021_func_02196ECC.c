/*
 * function: func_02196ECC
 * address:  0x02196ECC
 * packet:   pkt_ov021_02196ECC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02196E70  0x02196E70  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196EC8  0x02196EC8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj { u32 x0; u32 x4; u32 x8; u8 pad[0x288]; void *objs[27]; u32 mode; } Obj;
typedef struct { u16 x0; Obj *a; void (*cb)(); } Req;
extern void func_02196E70();
extern void func_0204B92C(void *, int);
extern void func_0204BA00(void *, Req *);
extern void func_0204B9A0(void *);
extern void func_02196034(Obj *, void (*)(), u32);
extern void func_02196EC8();

void func_02196ECC(Obj *a)
{
    Req r;
    int i;

    switch (a->x8) {
    case 1:
        i = 0;
        break;
    case 2:
        i = 1;
        break;
    case 3:
        i = 2;
        break;
    case 4:
        i = 3;
        break;
    default:
        i = 4;
        break;
    }
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196E70;
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], &r);
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_02196EC8, 0x58F);
}
