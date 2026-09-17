/*
 * function: func_020618B8
 * address:  0x020618B8
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020618B8.c \
 *       --func func_020618B8 --addr 0x020618B8 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207FA0C(void);
extern void func_0207FA40(u32 a, u32 b, u32 c);
extern void func_0207FADC(void);

void func_020618B8(u32 a, u32 b, u32 c)
{
    func_0207FA0C();
    func_0207FA40(a, b, c);
    func_0207FADC();
}
