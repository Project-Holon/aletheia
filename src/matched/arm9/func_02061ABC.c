/*
 * function: NNSi_GfdLoadSubObjExtPltt
 * address:  0x02061ABC
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdLoadSubObjExtPltt.c \
 *       --func NNSi_GfdLoadSubObjExtPltt --addr 0x02061ABC --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207F6A8(void);
extern void func_0207F6C0(u32 a, u32 b, u32 c);
extern void func_0207F754(void);

void NNSi_GfdLoadSubObjExtPltt(u32 a, u32 b, u32 c)
{
    func_0207F6A8();
    func_0207F6C0(a, b, c);
    func_0207F754();
}
