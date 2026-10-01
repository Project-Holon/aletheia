/*
 * function: func_021F8150
 * address: 0x021F8150
 * packet: pkt_ov094_021F8150
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02207BAC 0x02207BAC thumb ov094
 *   d_0220AF20 0x0220AF20 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02207BAC(void *, void *, int);
extern u8 *d_0220AF20;
void func_021F8150(int index, void *obj)
{
    func_02207BAC(*(void **)(d_0220AF20 + 0x1a4), obj, index);
}
