/*
 * function: func_021B9A88
 * address: 0x021B9A88
 * packet: pkt_ov133_021B9A88
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
extern void func_0204B3DC(void *,unsigned int);
void func_021B9A88(unsigned char *p,unsigned int limit) {*(unsigned int *)(p+24)=0;*(unsigned int *)(p+20)=0;(*(unsigned short *)(p+0x1844))++;func_0204B3DC(*(void **)(p+0x1854),0);if(*(unsigned short *)(p+0x1844)>limit){*(unsigned short *)(p+0x1844)=0;(*(unsigned char *)(p+0x1846))++;}}
