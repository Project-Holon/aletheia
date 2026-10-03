/*
 * function: func_021BA124
 * address: 0x021BA124
 * packet: pkt_ov133_021BA124
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
void func_021BA124(u8*p,u8*q){if(*(u16*)(p+4)<*(u16*)(p+6)){if(!*(u8**)(p+8)){*(u8**)(p+8)=q;*(u8**)(p+12)=q;*(u8**)(q+48)=0;}else{*(u8**)(q+48)=*(u8**)(p+8);*(u8**)(p+8)=q;}(*(u16*)(p+4))++;}}
