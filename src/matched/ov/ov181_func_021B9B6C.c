/*
 * function: func_021B9B6C
 * address: 0x021B9B6C
 * packet: pkt_ov181_021B9B6C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9B96.
 * symbols:
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
extern void func_0201D83C(void *),func_02045808(void *),func_02045C04(void *);
void func_021B9B6C(char *p){func_0201D83C(*(void **)(p+0xac));func_0201D83C(*(void **)(p+0xa8));func_02045808(*(void **)(p+0xb4));func_02045C04(*(void **)(p+0xb0));}
