/*
 * unit: no
 * function: func_021BA354
 * address: 0x021BA354
 * packet: pkt_ov181_021BA354
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
void func_021BA354(u8 *p,u8 *out,u32 n){u32 i;if(out){for(i=0;i<n;i++)*(u32 *)(out+(8-n)*4+i*4)=*(u32 *)(p+i*4);}for(i=0;i<8-n;i++)*(u32 *)(p+i*4)=*(u32 *)(p+n*4+i*4);}
