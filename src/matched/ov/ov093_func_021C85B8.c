/*
 * function: func_021C85B8
 * address: 0x021C85B8
 * packet: pkt_ov093_021C85B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C85D4 0x021C85D4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C85D4(u8 *, int, int);
void func_021C85B8(u8 *p)
{
    if (*(u32 *)(p + 0x1a64) != 0) {
        --*(u32 *)(p + 0x1a64);
        func_021C85D4(p, *(u32 *)(p + 0x1a64), 0);
    }
}
