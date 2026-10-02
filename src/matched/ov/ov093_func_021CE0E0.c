/*
 * function: func_021CE0E0
 * address: 0x021CE0E0
 * packet: pkt_ov093_021CE0E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F8504 0x021F8504 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F8504(u32,u32,u32);
void func_021CE0E0(u8 *p) { if(*(u16 *)(p+0xe4)!=0) func_021F8504(1,0,0); }
