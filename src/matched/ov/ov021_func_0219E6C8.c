/*
 * function: func_0219E6C8
 * address:  0x0219E6C8
 * packet:   pkt_ov021_0219E6C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7C90  0x021B7C90  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0216D67C();
extern u32 func_0216D530();
extern u32 func_021BB480();
extern void func_0219E2F4();
extern u8 func_0201441C(int i);
extern void func_021B7C90();
extern u32 func_0216D83C();
extern void func_0216D80C();
extern u32 func_0216D854();
extern void func_0216D818();
extern u32 func_0216D86C();
extern void func_0216D824();
extern void func_0216D844(u32, s16);
extern void func_0216D85C(u32, s16);
extern void func_0216D874(u32, s16);

void func_0219E6C8(u32 o, u32 id)
{
    u32 h;
    s32 v[3];
    u32 a[2];

    h = func_021BB480(func_0216D530(func_0216D67C(o)));
    func_0219E2F4(o, a);
    func_021B7C90(h, a, func_0201441C(id), v);
    func_0216D80C(o, func_0216D83C(o));
    func_0216D818(o, func_0216D854(o));
    func_0216D824(o, func_0216D86C(o));
    func_0216D844(o, (v[0] >> 4) / 4096);
    func_0216D85C(o, (v[1] >> 4) / 4096);
    func_0216D874(o, (v[2] >> 4) / 4096);
}
