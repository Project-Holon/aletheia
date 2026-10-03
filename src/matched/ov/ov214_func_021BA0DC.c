/*
 * function: func_021BA0DC
 * address: 0x021BA0DC
 * packet: pkt_ov214_021BA0DC
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 021BA106.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct Descriptor;struct Cfg;struct CharBuf;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,unsigned char),func_02045334(struct Descriptor *),func_02045374(struct Cfg *),func_02041B6C(unsigned);
extern unsigned char func_02045730(struct Descriptor *);
void func_021BA0DC(int unused,char *p){struct Descriptor *d;func_02043B5C(func_02045770(*(struct Descriptor **)(p+0x6c)),0);d=*(struct Descriptor **)(p+0x6c);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}
