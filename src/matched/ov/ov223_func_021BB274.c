/*
 * function: func_021BB274
 * address: 0x021BB274
 * packet: pkt_ov223_021BB274
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(struct CharBuf *,u8);extern void func_02045334(struct Descriptor *);extern void func_02045374(struct Cfg *);extern u8 func_02045730(struct Descriptor *);extern void func_02041B6C(u32);
void func_021BB274(char *p) {struct Descriptor *d;u32 off;off=0x240;func_02043B5C(func_02045770(*(struct Descriptor **)(p+off)),0);d=*(struct Descriptor **)(p+off);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}
