/*
 * function: func_021BEF08
 * address: 0x021BEF08
 * packet: pkt_ov204_021BEF08
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF55C 0x021BF55C thumb ov204
 *   func_0201F02C 0x0201F02C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern int func_021BF55C(u8 *p);
extern void func_0201F02C(struct WordSet*,u32,void*);
void func_021BEF08(u8*p,u32 a){struct WordSet*q=(struct WordSet *)func_021BF55C(*(u8**)(p+24));func_0201F02C(q,a,**(void***)(p+4));}
