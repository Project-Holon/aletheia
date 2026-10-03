/*
 * function: func_021F4EB4
 * address: 0x021F4EB4
 * packet: pkt_ov112_021F4EB4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
void func_021F4EB4(u32 unused,u32 p,s16 a,s16 b) { u16 flags; *(s16 *)(p+28)=a; flags=*(u16 *)p; *(s16 *)(p+30)=b; *(u16 *)p=flags|2; }
