/*
 * unit: no
 * function: func_0220BDA0
 * address: 0x0220BDA0
 * packet: pkt_ov198_0220BDA0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct CharBuf;extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(struct CharBuf *,u8);
void func_0220BDA0(u8 *p){u32 i;for(i=0;i<p[0x2174];i++)func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*8+0x1f70)),0);}
