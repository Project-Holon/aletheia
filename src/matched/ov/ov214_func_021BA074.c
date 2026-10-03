/*
 * unit: yes
 * function: func_021BA074, func_021BA0A4
 * address: 0x021BA074
 * packet: pkt_ov214_021BA074
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Parameter evidence: original narrows third input to u16 before func_0201F73C.
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 */
struct Descriptor;struct Cfg;
extern void func_0201F73C(void *,int,unsigned short,int),func_02045334(struct Descriptor *),func_02045374(struct Cfg *),func_02041B6C(unsigned),func_0201F7A8(void *,int);
extern unsigned char func_02045730(struct Descriptor *);
void func_021BA074(int unused,char *p){struct Descriptor *d;func_0201F73C(*(void **)(p+0x6c),1,*(unsigned *)(p+0x74),10);d=*(struct Descriptor **)(p+0x6c);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}
void func_021BA0A4(int unused,char *p){func_0201F7A8(*(void **)(p+0x6c),1);}
