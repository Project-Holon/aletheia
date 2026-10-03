/*
 * function: func_02184C8C
 * address: 0x02184C8C
 * packet: pkt_ov219_02184C8C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028148 0x02028148 thumb
 *   sub_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02028148(u8*);
extern void sub_02041B6C(u32);
void func_02184C8C(u8 *p,u32 i){u32 off=i*4;u8 *slots=p+0xc05c;if(*(u8**)(slots+off)){func_02028148(*(u8**)(slots+off));sub_02041B6C(2);*(u8**)(slots+off)=0;}}
