/*
 * function: func_021B8810
 * address:  0x021B8810
 * packet:   pkt_ov102_021B8810
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-tile init: clear 0x1c bytes, store the second argument at +0x18, run the
 * 0xc/0xd mode select through 0x0204B878, initialise with 0x021B88F8, publish
 * the +8/+0xc halfwords through 0x0204B404, enable through 0x0204B3DC and set
 * the 0x2000 flag through 0x0204B8C4.  Blocker target of func_021B8934.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021B88F8  0x021B88F8  thumb  ov102
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02005728  0x02005728  thumb
 *   func_0204B8C4  0x0204B8C4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082BCC(int a, int b, int c);
extern void func_0204B878(int p, int a);
extern void func_021B88F8(int p);
extern void func_0204B404(int p, u16 *v, int c);
extern void func_0204B3DC(int p, int a);
extern u32 func_02005728(u32 range);
extern void func_0204B8C4(int p, int a);

void func_021B8810(int a0, int b, int c)
{
    u16 tmp[2];

    func_02082BCC(a0, 0, 0x1c);
    *(int *)(a0 + 0x18) = b;
    func_0204B878(*(int *)(a0 + 0x18), c != 0 ? 0xd : 0xc);
    func_021B88F8(a0);
    tmp[0] = (u16)*(u32 *)(a0 + 8);
    tmp[1] = (u16)*(u32 *)(a0 + 0xc);
    func_0204B404(*(int *)(a0 + 0x18), tmp, 1);
    func_0204B3DC(*(int *)(a0 + 0x18), 1);
    func_0204B8C4(*(int *)(a0 + 0x18), func_02005728(0x2000));
}
