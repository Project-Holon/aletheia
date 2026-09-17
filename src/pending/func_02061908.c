/*
 * function: func_02061908
 * address:  0x02061908
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061908.c \
 *       --func func_02061908 --addr 0x02061908 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207FB2C(void);
extern void func_0207FC48(u32 a, u32 c);
extern void func_0207FCE4(void);

void func_02061908(u32 a, u32 b, u32 c)
{
    func_0207FB2C();
    func_0207FC48(a, c);
    func_0207FCE4();
}
