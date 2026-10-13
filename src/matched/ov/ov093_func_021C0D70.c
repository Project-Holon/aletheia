/*
 * function: BTL_SERVER_FLOW_SumHitRecordDamage
 * address: 0x021C0D70
 * packet: pkt_ov093_021C0D70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two zero alignment bytes at 0x021C0D8E.
 * Declare i before sum, but initialize sum before i, to reproduce both
 * register allocation and the order of the initial movs instructions.
 * Each record supplies the halfword at offset 4, stride 4.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 BTL_SERVER_FLOW_SumHitRecordDamage(const u8 *q)
{
    u32 i;
    u32 sum = 0;
    i = 0;
    for (; i < q[2]; i++)
        sum += *(const u16 *)(q + 4 + i * 4);
    return sum;
}
