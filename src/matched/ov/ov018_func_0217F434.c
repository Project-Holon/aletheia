/*
 * function: func_0217F434
 * address: 0x0217F434
 * packet: pkt_ov018_0217F434
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F45A.
 * symbols:
 *   func_02190708 0x02190708 thumb ov021
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct Fx;
extern void *func_02190708(struct Fx *p, u32 a, u32 b, u32 c, u16 d, u16 e);
void func_0217F434(void **p)
{
    if (p[7] == 0) p[7] = func_02190708(p[9], (u32)p[3], 1, 0x13, 0x1e, 4);
}
