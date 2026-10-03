/*
 * function: func_021B9BC8
 * address: 0x021B9BC8
 * packet: pkt_ov225_021B9BC8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9CE0 0x021B9CE0 thumb ov225
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9CE0(char *,int);
u16 func_021B9BC8(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+6);}
