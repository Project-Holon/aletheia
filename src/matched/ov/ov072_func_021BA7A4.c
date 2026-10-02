/*
 * function: func_021BA7A4
 * address: 0x021BA7A4
 * packet: pkt_ov072_021BA7A4
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAE44 0x021BAE44 thumb ov072
 *   func_021BADF4 0x021BADF4 thumb ov072
 */
typedef unsigned int u32;
extern void func_021BAE44(void *p);
extern void func_021BADF4(void *p);
void func_021BA7A4(char *p, void *selected) { u32 i; void *q; for(i=0;i<*(u32 *)(p+12);i++) { q=(void *)(*(u32 *)(p+8)+i*0x44); if(q==selected) func_021BADF4(q); else func_021BAE44(q); } }
