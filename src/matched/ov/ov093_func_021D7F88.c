/*
 * function: func_021D7F88
 * address: 0x021D7F88
 * packet: pkt_ov093_021D7F88
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7FBC 0x021D7FBC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021D7FBC(void **,void *);
u32 func_021D7F88(u8 *p) { u32 n=0; if(*(u32 *)p==1) { if(*(void **)(p+0x4c) && *(void **)(p+0x28)) n+=func_021D7FBC(*(void **)(p+0x4c),*(void **)(p+0x28)); if(*(void **)(p+0x54) && *(void **)(p+0x30)) n+=func_021D7FBC(*(void **)(p+0x54),*(void **)(p+0x30)); } return n; }
