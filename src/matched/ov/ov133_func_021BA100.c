/*
 * function: func_021BA100
 * address: 0x021BA100
 * packet: pkt_ov133_021BA100
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021BA100(u8*p,u8*q){if(*(u16*)(p+4)<*(u16*)(p+6)){if(!*(u8**)(p+8))*(u8**)(p+8)=q;else *(u8**)(*(u8**)(p+12)+48)=q;*(u8**)(p+12)=q;*(u8**)(q+48)=0;(*(u16*)(p+4))++;}}
