/*
 * function: func_021D4D64
 * address: 0x021D4D64
 * packet: pkt_ov093_021D4D64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082D44(const void *, void *, u32);
void func_021D4D64(u32 *p, const void *src, u32 a)
{
    *p = (*p & ~255u) | (u8)a;
    func_02082D44(src, p + 1, *p >> 8);
}
