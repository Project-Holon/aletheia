/*
 * function: func_0203D88C
 * address:  0x0203D88C
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Truncates both arguments to 16 bits, then runs the pair through
 * func_020371AC and func_0203D2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D88C.c \
 *       --func func_0203D88C --addr 0x0203D88C --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020371AC(unsigned short a, unsigned int b);
extern void func_0203D2CC(void);

void func_0203D88C(u32 a, u32 b)
{
    func_020371AC((u16)a, (u16)b);
    func_0203D2CC();
}
