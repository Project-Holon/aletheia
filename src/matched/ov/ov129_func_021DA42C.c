/*
 * function: func_021DA42C
 * address: 0x021DA42C
 * packet: pkt_ov129_021DA42C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Original calls visibly load r2/r3 and outgoing stack zero; retain those arguments despite the matched callee declaring only two.
 * symbols:
 *   func_021DA3FC 0x021DA3FC thumb ov129
 *   func_021DA454 0x021DA454 thumb ov129
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021DA3FC(u8 *);
extern void func_021DA454(u8 *,int,int,int,int);
void func_021DA42C(u8 *p) { int zero; func_021DA3FC(p); zero=0; func_021DA454(p,0,78,165,zero); func_021DA454(p,1,172,165,zero); }
