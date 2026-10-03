/*
 * function: func_068996C8
 * address: 0x068996C8
 * packet: pkt_ov095_068996C8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled store-and-return follower after the 0x068996B8 veneer.
 * symbols:
 *   data_0689D708 0x0689D708 data a4
 */
typedef unsigned int u32;
extern unsigned char data_0689D708[];

void *func_068996C8(u32 *p)
{
    *p = 1;
    return data_0689D708;
}
