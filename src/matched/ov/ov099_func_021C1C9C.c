/*
 * function: func_021C1C9C
 * address: 0x021C1C9C
 * packet: pkt_ov099_021C1C9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020061E4(u32 a);
void func_021C1C9C(u32 a,int b,u32 p){u32 offset;offset=a+(*(u8 *)(p+0x8ec)<<3);if(*(u8 *)(p+offset+0x8cc)==2 && *(u8 *)(p+0x8ed)==0 && b==0){*(u8 *)(p+0x8ed)=offset+1;func_020061E4(1356);}}
