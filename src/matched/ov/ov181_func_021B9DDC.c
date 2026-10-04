/*
 * function: func_021B9DDC
 * address: 0x021B9DDC
 * packet: pkt_ov181_021B9DDC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9E12.
 * symbols:
 *   func_02045334 0x02045334 arm
 */
struct Descriptor;
extern void func_02045334(struct Descriptor *);
void func_021B9DDC(char *p){if(*(unsigned char *)(p+0x2cc)&1)func_02045334((struct Descriptor *)*(unsigned *)(p+0x2bc));if(*(unsigned char *)(p+0x2cc)&2)func_02045334((struct Descriptor *)*(unsigned *)(p+0x2c4));*(unsigned char *)(p+0x2cc)=0;}
