/*
 * function: func_021B7DAC
 * address: 0x021B7DAC
 * packet: pkt_ov105_021B7DAC
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
struct Descriptor; struct PrintSys; extern void *func_02045770(struct Descriptor *); extern unsigned int func_0201C6C4(struct PrintSys *,void *); extern void func_02045334(struct Descriptor *);
int func_021B7DAC(unsigned char *p,unsigned char *q) { struct PrintSys *s; s=*(struct PrintSys **)(q+8); if(p[8]) { if(!func_0201C6C4(s,func_02045770(*(struct Descriptor **)(p+4)))) { func_02045334(*(struct Descriptor **)(p+4)); p[8]=0; } } if(!p[8]) return 1; return 0; }
