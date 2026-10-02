/*
 * function: func_021B8548
 * address: 0x021B8548
 * packet: pkt_ov093_021B8548
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CD914 0x021CD914 thumb ov093
 */
extern void func_021CD914(void *);
void func_021B8548(unsigned char *p) { unsigned int i; for(i=0;i<4;i++) { void *q; q=*(void **)(p+0x10+i*4); if (q) func_021CD914(q); } }
