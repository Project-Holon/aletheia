/*
 * function: sub_0200FA94
 * address:  0x0200FA94
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200FD38  0x0200FD38  thumb
 *   func_020351A0  0x020351A0  arm
 *   func_020053EC  0x020053EC  thumb
 *
 * An abort path: reports a fixed status, tears down with func_020351A0(2),
 * then spins forever calling func_020053EC(). The infinite loop is why
 * nothing after this in the same block is ever reached.
 *
 * EXACT* because the 22 compiled bytes fall two short of the disasm.py
 * extent: a "movs r0, r0" alignment filler before the next label, the
 * ordinary inter-function padding, not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FA94.c \
 *       --func sub_0200FA94 --addr 0x0200FA94 --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0200FD38(u32 a, u32 b);
extern void func_020351A0(u32 a);
extern void func_020053EC(void);

void sub_0200FA94(void)
{
    func_0200FD38(1, 0);
    func_020351A0(2);
    for (;;) {
        func_020053EC();
    }
}
