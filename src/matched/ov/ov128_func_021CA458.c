/*
 * function: func_021CA458
 * address: 0x021CA458
 * packet: pkt_ov128_021CA458
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:

 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

void func_021CA458(char *p,void *q) {u32 i;for(i=0;i<64;i++) {if(!*(void **)(p+i*4+56)) {*(void **)(p+i*4+56)=q;return;}}}
