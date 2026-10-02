/*
 * function: func_021BDC3C
 * address: 0x021BDC3C
 * packet: pkt_ov091_021BDC3C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding at 0x021BDC5A.
 * symbols:
 *   func_02017988 0x02017988 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 */
typedef unsigned int u32;
struct Blk37;
extern u32 func_02017988(void *, u32);
extern void func_0200CDE0(struct Blk37 *, void *);
void func_021BDC3C(u32 p, void *m)
{
    func_02017988(m, 1);
    func_0200CDE0(*(struct Blk37 **)(*(u32 *)(p + 0x280) + 0x18), m);
}
