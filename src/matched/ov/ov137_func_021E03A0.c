/*
 * unit: no
 * function: func_021E03A0
 * address: 0x021E03A0
 * packet: pkt_ov137_021E03A0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void func_020456F8(struct Descriptor *);
extern u8 func_02045730(struct Descriptor *);
extern void func_020409B4(u32);
extern void func_020452E8(struct Descriptor *);
void func_021E03A0(u8 *p){int i;u8 *s=p+0xce0;for(i=0;i<*(int *)s;i++){u8 *q=s+(u32)i*4;struct Descriptor *w=*(struct Descriptor **)(q+20);func_020456F8(w);func_020409B4(func_02045730(w));func_020452E8(*(struct Descriptor **)(q+20));}}
