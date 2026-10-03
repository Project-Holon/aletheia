/*
 * function: func_021C7E0C
 * address: 0x021C7E0C
 * packet: pkt_ov128_021C7E0C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041B6C 0x02041B6C arm
 *   func_021C85A4 0x021C85A4 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C6ADC(u8 *,u8 *,unsigned);
extern void func_02041B6C(u32);
extern void func_021C85A4(u8 *,u8 *,u8 *,int,int,int,u16);
void func_021C7E0C(u8 *p,u8 *q,u8 *r,u16 heap) {func_021C6ADC(r,r+12,5);func_02041B6C(0);func_021C85A4(p,q,r,*(s16 *)p,*(s16 *)(p+4),0,heap);}
