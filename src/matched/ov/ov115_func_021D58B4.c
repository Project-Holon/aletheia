/*
 * function: func_021D58B4
 * address: 0x021D58B4
 * packet: pkt_ov115_021D58B4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the hardware scanline before adding the signed counter;
 *        the nested expression moves the first four loads/adds.
 * volatile: hardware reads at 021D58BE, 021D58CC and writes 021D58E2, 021D58EA.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
void func_021D58B4(void *unused, u8 *p) {
    int i;
    i = *(volatile u16 *)0x04000006;
    i = (i + (*(s16 *)(p + 0x9c8) + 1)) % 192;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x04000014 = *(s16 *)(p + 0x9ca + i * 2) & 511;
        *(volatile u32 *)0x04001018 = *(s16 *)(p + 0x9ca + i * 2) & 511;
    }
}
