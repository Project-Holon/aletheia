/*
 * function: NNSi_GfdLoadMainObjExtPltt
 * address:  0x020619BC
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdLoadMainObjExtPltt.c \
 *       --func NNSi_GfdLoadMainObjExtPltt --addr 0x020619BC --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207F47C(void);
extern void func_0207F4C4(u32 a, u32 b, u32 c);
extern void func_0207F560(void);

void NNSi_GfdLoadMainObjExtPltt(u32 a, u32 b, u32 c)
{
    func_0207F47C();
    func_0207F4C4(a, b, c);
    func_0207F560();
}
