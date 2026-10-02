/*
 * function: func_021D5F90
 * address: 0x021D5F90
 * packet: pkt_ov093_021D5F90
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * lever: plain subtraction avoids compound-assignment operand narrowing.
 */
typedef unsigned char u8;
typedef unsigned short u16;
void func_021D5F90(u8 *p, unsigned int n)
{
    if (*(u16 *)(p + 0x10) > n) {
        *(u16 *)(p + 0x10) = *(u16 *)(p + 0x10) - n;
        return;
    }
    *(u16 *)(p + 0x10) = 0;
}
