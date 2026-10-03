/*
 * function: func_022024B0
 * address: 0x022024B0
 * packet: pkt_ov135_022024B0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200949C 0x0200949C thumb
 *   func_020094D8 0x020094D8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0200949C(void *,int,int);
extern void func_020094D8(void *,int,int,int);
void func_022024B0(void *obj,u8 *p) { int b=p[0x121],a=p[0x120]; if(func_0200949C(obj,a,b)==0) func_020094D8(obj,a,b,1); }
