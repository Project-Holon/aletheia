/*
 * function: func_0201F5BC
 * address:  0x0201F5BC
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards one five-argument call to two four-argument workers, dropping the
 * second argument from the first call and the third from the second.  The
 * fifth argument arrives on the caller's stack and is re-read with `ldrh`
 * through a cached frame pointer (r7 = sp + 0x18) both times, once per call,
 * which is what fixes it as u16 rather than a word.
 *
 * symbols:
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F57C  0x0201F57C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F5BC.c \
 *       --func func_0201F5BC --addr 0x0201F5BC --cc 1.1p1 --thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern void func_0201F57C(u32 a, u32 b, u32 c, u16 d);

void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_0201F554(a, b, d, e);
    func_0201F57C(a, c, d, e);
}
