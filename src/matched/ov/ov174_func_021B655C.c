/*
 * function: func_021B655C
 * address: 0x021B655C
 * packet: pkt_ov174_021B655C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A380 0x0204A380 arm
 */
extern void *func_0204A380(void *,unsigned,unsigned,unsigned short);
void func_021B655C(char *p) {unsigned char *q=func_0204A380(*(void **)(p+24),**(unsigned short **)(p+48)+62,0,*(unsigned short *)p);*(void **)(p+56)=q;*(void **)(p+60)=q;*(void **)(p+64)=q+8;if(q[2]==255 && q[3]==255) *(unsigned *)(p+8)=2;else *(unsigned *)(p+8)=4;}
