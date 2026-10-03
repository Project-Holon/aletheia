/*
 * function: func_021B6F04
 * address: 0x021B6F04
 * packet: pkt_ov071_021B6F04
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
typedef unsigned char u8;
extern int func_0201C6C4(void *, unsigned);
struct Obj;
extern void func_020257D0(struct Obj *o);
int func_021B6F04(void **p, u8 *q) { if(q[8]==1) { if(func_0201C6C4(p[2], *(unsigned *)q)==0) { func_020257D0(*(void **)(q+4)); q[8]=0; return 1; } } return 0; }
