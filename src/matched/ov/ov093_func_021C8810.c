/*
 * function: BTL_SERVER_FLOW_ClearMsgRecord
 * address: 0x021C8810
 * packet: pkt_ov093_021C8810
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021C8826.
 * lever: clearing the low eight-bit field emits bics; a raw mask emits ands.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Packed021C8810 { u16 low : 8; u16 high : 8; };
extern void MI_CpuFill8(void *, int, u32);
void BTL_SERVER_FLOW_ClearMsgRecord(u8 *p)
{
    MI_CpuFill8(p, 0, 0x24);
    ((struct Packed021C8810 *)(p + 2))->low = 0;
}
