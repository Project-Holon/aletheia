/*
 * function: func_021BA148
 * address: 0x021BA148
 * packet: pkt_ov133_021BA148
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021BA148(u8*p,u8*q){u8 *prev;u8 *cur;prev=0;cur=*(u8**)(p+8);while(cur!=q && cur){prev=cur;cur=*(u8**)(cur+48);}if(cur){if(prev)*(u8**)(prev+48)=*(u8**)(cur+48);else *(u8**)(p+8)=*(u8**)(cur+48);if(*(u8**)(p+12)==q)*(u8**)(p+12)=prev;*(u8**)(cur+48)=0;(*(u16*)(p+4))--;}}
