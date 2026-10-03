/*
 * function: func_021C9ED0
 * address: 0x021C9ED0
 * packet: pkt_ov128_021C9ED0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021C9ED0(u32 p,int unused,const u16 *q,u32 value) { int i; *(u32 *)(p+8)=value; *(u16 *)p=q[0]; *(u16 *)(p+2)=q[1]; *(u16 *)(p+4)=q[2]; for(i=0;i<8;i++) *(u32 *)(p+44+i*4)=0; }
