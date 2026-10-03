/*
 * function: func_021B884C
 * address: 0x021B884C
 * packet: pkt_ov104_021B884C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02035D20(u32 *outA, u32 *outB);
int func_021B884C(u32 *p) { u32 x,y; if(func_02035D20(&x,&y)) { if(x<=256 && y<=168) { p[0]=x; p[1]=y; return 1; } } return 0; }
