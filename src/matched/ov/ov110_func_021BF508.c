/*
 * function: func_021BF508
 * address: 0x021BF508
 * packet: pkt_ov110_021BF508
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BF500 0x021BF500 thumb ov110
 */
typedef unsigned char u8;
extern void func_021B9BEC(u8 *,int);
extern int func_021B9C74(unsigned);
extern void func_021BF500(u8 *);
void func_021BF508(u8 *p,int *q) {
 switch(*q) {
 case 0: func_021B9BEC(*(u8 **)(p+0x14),2); ++*q; break;
 case 1: if(func_021B9C74(*(unsigned *)(p+0x14))!=0) func_021BF500(p); break;
 }
}
