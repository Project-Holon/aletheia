/*
 * function: func_021D83E0
 * address: 0x021D83E0
 * packet: pkt_ov093_021D83E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * follower: Two zero alignment bytes.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct B { u32 kind:4; u32 pad:6; u32 flag:1; u32 rest:21; }; int func_021D83E0(struct B *p) { if(p->kind==3 && p->flag==1) return 1; return 0; }
