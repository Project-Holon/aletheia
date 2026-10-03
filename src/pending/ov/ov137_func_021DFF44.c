/*
 * unit: no
 * function: func_021DFF44
 * address: 0x021DFF44
 * packet: pkt_ov137_021DFF44
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocking: ABS32 data d_020A1448 at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   d_020A1448 0x020A1448 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern const struct Cfg d_020A1448;
void func_021DFF44(u8 *p){func_0204A48C(&d_020A1448,0x021E1EA4,114);*(struct Bank **)(p+0xd68)=func_0204B100(30,1,114);}
