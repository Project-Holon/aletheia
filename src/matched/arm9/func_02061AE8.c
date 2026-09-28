/*
 * function: func_02061AE8
 * address:  0x02061AE8
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061AE8.c \
 *       --func func_02061AE8 --addr 0x02061AE8 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207F5B0(void);
extern void func_0207F5C8(u32 a, u32 b, u32 c);
extern void func_0207F65C(void);

void func_02061AE8(u32 a, u32 b, u32 c)
{
    func_0207F5B0();
    func_0207F5C8(a, b, c);
    func_0207F65C();
}
