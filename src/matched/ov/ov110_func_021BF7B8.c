/*
 * function: func_021BF7B8
 * address: 0x021BF7B8
 * packet: pkt_ov110_021BF7B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * body: tail-forwards p+0x54 to EDE8, whose complete four-byte body is
 *   ldrh r0,[r0,#2]; bx lr. Widening that unsigned return preserves every bit.
 * symbols:
 *   func_021BEDE8 0x021BEDE8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_021BEDE8(u8 *);
unsigned func_021BF7B8(u8 *p) { return func_021BEDE8(p+0x54); }
