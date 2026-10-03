/*
 * unit: no
 * function: func_021B9F9C
 * address: 0x021B9F9C
 * packet: pkt_ov181_021B9F9C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BACE4 0x021BACE4 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern const u8 d_021BACE4[];
void func_021B9F9C(u8 *p){u32 i;*(const void **)p=d_021BACE4;*(u16 *)(p+0x74)=7;*(u16 *)(p+0x78)=0;*(u16 *)(p+0x76)=0;*(u32 *)(p+0x7c)=0;for(i=0;i<16;i++){u8 *q=p+i*4;*(u16 *)(q+0x34)=65535;*(u16 *)(q+0x36)=0;}}
