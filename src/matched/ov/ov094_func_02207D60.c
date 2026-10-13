/*
 * function: BTLV_GAUGE_IsSlotOccupied
 * address: 0x02207D60
 * packet: pkt_ov094_02207D60
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Flags { u32 low:3; u32 bit3:1; u32 high:28; };
int BTLV_GAUGE_IsSlotOccupied(u8 *p, int index)
{
    if (((struct Flags *)(p + (index << 7) + 0xb0))->bit3) return 1;
    return 0;
}
