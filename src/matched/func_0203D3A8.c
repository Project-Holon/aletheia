/*
 * unit:     no
 * function: func_0203D3A8
 * address:  0x0203D3A8
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_020395EC  0x020395EC  arm
 *   func_02038C18  0x02038C18  arm
 *
 * TU: net.c.
 *
 * Seven-argument send wrapper.  The leading func_0203D798 call is made for
 * effect only, its result is dead in the original, and the four incoming
 * arguments all have to survive it, which is what spends r4-r7.  Arguments
 * five to seven go on the stack, hence the `sub sp, sp, #0xc`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D3A8.c \
 *       --func func_0203D3A8 --addr 0x0203D3A8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D798(void);
extern u32   func_020395EC(u32 a);
extern void  func_02038C18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void func_0203D3A8(u32 a, u32 b, u32 c, u32 d)
{
    func_0203D798();
    func_02038C18(b, d, c, 0, func_020395EC(a), 0xff, 0);
}
