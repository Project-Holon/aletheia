/*
 * function: func_0202F190
 * address:  0x0202F190
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020185F0   0x020185F0  thumb
 *   func_0202F1B4   0x0202F1B4  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F190.c \
 *       --func func_0202F190 --addr 0x0202F190 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_020185F0(void *a0);
extern void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    func_0202F1B4((u32)((void *)func_020185F0(a0)), a1, a2, a3, a4);
}
