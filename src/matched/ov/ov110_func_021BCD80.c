/*
 * function: func_021BCD80
 * address: 0x021BCD80
 * packet: pkt_ov110_021BCD80
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BF808 0x021BF808 thumb ov110
 *   func_020282AC 0x020282AC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021BF7FC(u8 *);
extern int func_021BF808(u8 *);
extern void func_020282AC(void *, void *, int, int, u16);
void func_021BCD80(u8 *p) {
    if (func_021BF7FC(*(u8 **)(p+4)))
        func_020282AC(*(void **)(p+0x64),*(void **)(p+0x34),8,0x3545,0x7b2c);
    else
        func_020282AC(*(void **)(p+0x64),*(void **)(p+0x34),14,0x3545,0x7b2c);
    if (func_021BF808(*(u8 **)(p+4)))
        func_020282AC(*(void **)(p+0x68),*(void **)(p+0x38),8,0x3545,0x7b2c);
    else
        func_020282AC(*(void **)(p+0x68),*(void **)(p+0x38),14,0x3545,0x7b2c);
}
