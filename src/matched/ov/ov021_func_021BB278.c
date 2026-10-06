/*
 * function: func_021BB278
 * address:  0x021BB278
 * packet:   pkt_ov021_021BB278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB348  0x021BB348  thumb  ov021
 *   func_02049030  0x02049030  arm
 *   func_0219EF7C  0x0219EF7C  thumb  ov021
 *   func_0219F018  0x0219F018  thumb  ov021
 *   func_021B7934  0x021B7934  thumb  ov021
 *   func_021BB0B4  0x021BB0B4  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int func_021BB348(u32 a);
extern u32 func_02049030(u32 a);
typedef unsigned char  u8;
struct S;
extern void func_0219EF7C(struct S *p, u32 b, u32 c);
extern u8 *func_0219F018(u8 *p);
extern int func_021B7934(u32 a, u32 b);
extern void func_021BB0B4(u32 *a, u32 b, u32 c);
extern void func_021AB840(u32, int, u32, u16);
extern u32 func_021AB880(u8 *p);
extern u32 func_021AB884(u8 *p);
extern u32 func_021AB888(u32);
extern void func_021AB634(u32, u32, u32, u32);

void func_021BB278(u32 *a, u16 *b, u32 c)
{
    func_021BB348((u32)a);
    if (b[0] != 0xFFFF) {
        u32 n = func_02049030(0x4f);

        func_0219EF7C((struct S *)a[1], b[0], c);
        func_021B7934(a[0], (u32)func_0219F018((u8 *)a[1]));
        func_021BB0B4((u32 *)a[2], b[0] + (n >> 1), c);
    }
    if (b[1] != 0xFFFF) {
        u32 t, u, v;

        func_021AB840(a[4], 0, b[1], c);
        t = func_021AB880((u8 *)a[4]);
        u = func_021AB884((u8 *)a[4]);
        v = func_021AB888(a[4]);
        func_021AB634(a[3], t, u, v);
    }
}
