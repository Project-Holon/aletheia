/*
 * function: func_021BCD90
 * address: 0x021BCD90
 * packet: pkt_ov217_021BCD90
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C0F48 0x021C0F48 thumb ov217
 *   func_021BC6DC 0x021BC6DC thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C0F48(u8 *);
extern u32 func_021BC6DC(void *);
void func_021BCD90(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        func_021C0F48(*(u8 **)(p + i * 4 + 0xDC));
        *(u32 *)(p + i * 4 + 0xDC) = 0;
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        func_021C0F48(*(u8 **)(p + i * 4 + 0xB4));
        *(u32 *)(p + i * 4 + 0xB4) = 0;
    }
}
