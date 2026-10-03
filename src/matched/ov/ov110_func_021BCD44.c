/*
 * function: func_021BCD44
 * address: 0x021BCD44
 * packet: pkt_ov110_021BCD44
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Reads r0 after BF824 and supplies p+4; preserve return and visible argument.
 * symbols:
 *   func_021BF824 0x021BF824 thumb ov110
 *   func_020282AC 0x020282AC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021BF824(u8 *);
extern void func_020282AC(void *, u16 *, u32, u32, u16);
void func_021BCD44(u8 *p)
{
    if (func_021BF824(*(u8 **)(p + 4)) != 0) {
        func_020282AC(*(void **)(p + 0x64), *(u16 **)(p + 0x34), 8, 0x3545, 0x7b2c);
    } else {
        func_020282AC(*(void **)(p + 0x64), *(u16 **)(p + 0x34), 14, 0x3545, 0x7b2c);
    }
}
