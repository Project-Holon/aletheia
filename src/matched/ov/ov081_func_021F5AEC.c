/*
 * function: func_021F5AEC
 * address:  0x021F5AEC
 * packet:   pkt_ov081_021F5AEC
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021F5AEC(u8 *w)
{
    u8 *t = w + 0x300C;

    *(u16 *)(t + 0x182) = 0;
    *(u16 *)(t + 0x180) = 0;
    *(u16 *)(t + 0xC0) = 0x33;
    (*(u16 *)(t + 0x182))++;
    *(u16 *)(t + 0xC2) = 0x95;
    (*(u16 *)(t + 0x182))++;
    *(u16 *)(t + 0xC4) = 0x5B;
    (*(u16 *)(t + 0x182))++;
}
