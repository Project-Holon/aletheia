/*
 * function: func_020618E4
 * address:  0x020618E4
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020618E4.c \
 *       --func func_020618E4 --addr 0x020618E4 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207FB2C(void);
extern void func_0207FBBC(u32 a, u32 c);
extern void func_0207FCE4(void);

void func_020618E4(u32 a, u32 b, u32 c)
{
    func_0207FB2C();
    func_0207FBBC(a, c);
    func_0207FCE4();
}
