/*
 * function: func_021B7AE8
 * address: 0x021B7AE8
 * packet: pkt_ov071_021B7AE8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BA8A0 0x021BA8A0 data a4
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned short u16;
extern const struct Pair { int x, y; } d_021BA8A0[];
extern void func_0204B404(void *,void *,int);
void func_021B7AE8(void **p,int i) { u16 t[2];t[0]=d_021BA8A0[i].x;t[1]=d_021BA8A0[i].y;func_0204B404(p[31],t,1);}
