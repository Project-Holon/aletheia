/*
 * function: func_021A6CB8
 * address:  0x021A6CB8
 * packet:   pkt_ov021_021A6CB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021A6D58  0x021A6D58  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021A36B0  0x021A36B0  thumb  ov021
 *   func_021A36D4  0x021A36D4  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02188C58(void *p);
extern u32 func_02188C5C(u8 *p);
extern void *func_02188CB4(u8 *p);
extern u16 func_02188C84(u8 *p);
extern u32 *func_021A6D58(void *a, u32 heap);
extern void func_02188CAC(u8 *p, u32 v);
extern void *func_021A3074(u8 *p);
extern void *func_0216D888(void *p);
extern void func_02188D40(u8 *p, u32 v);
extern void *func_02188C80(void *p);
struct Ctx;
struct H4;
struct Rec44;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern struct H4 *func_02012AB8(struct Rec44 *p);
extern void func_021A36B0(u8 *p, void *v);
extern void func_021A36D4(u8 *p, u32 v);
extern void func_021A3044(u8 *p, u32 v);
extern void func_021A305C(u8 *p, u32 v);

void func_021A6CB8(u8 *a, u32 b, u32 c)
{
    u8 *r4;

    func_02188C58(a);
    func_02188C5C(a);
    r4 = func_02188CB4(a);
    func_02188CAC(a, (u32)func_021A6D58(a, func_02188C84(a)));
    func_02188D40(a, (u32)func_0216D888(func_021A3074(r4)));
    func_021A36B0(r4, func_02012AB8(func_020127A4(func_020120F4(func_02188C80(a)))));
    func_021A36D4(r4, b);
    func_021A3044(r4, b);
    func_021A305C(r4, c);
}
