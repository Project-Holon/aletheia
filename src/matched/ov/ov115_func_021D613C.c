/*
 * function: func_021D613C
 * address: 0x021D613C
 * packet: pkt_ov115_021D613C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;typedef unsigned int u32;

int func_021D613C(u8 *p) { void (*cb)(u8 *);cb=*(void (**)(u8 *))(p+12);if(cb){cb(p);return 0;}return 1; }
