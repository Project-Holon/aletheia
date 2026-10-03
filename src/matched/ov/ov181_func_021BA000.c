/*
 * unit: no
 * function: func_021BA000
 * address: 0x021BA000
 * packet: pkt_ov181_021BA000
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
void func_021BA000(u8 *p){u32 i;for(i=0;i<15;i++){u8 *q=p+i*4;*(u16 *)(q+0x34)=*(u16 *)(q+0x38);*(u16 *)(q+0x36)=*(u16 *)(q+0x3a);}*(u16 *)(p+0x70)=65535;*(u16 *)(p+0x72)=0;}
