/*
 * function: func_021D8340
 * address: 0x021D8340
 * packet: pkt_ov093_021D8340
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct B { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; }; u32 func_021D8340(struct B *p) { if(p->kind==1) return (u16)p->id; return 0; }
