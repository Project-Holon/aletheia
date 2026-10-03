/*
 * function: func_021B9C28
 * address: 0x021B9C28
 * packet: pkt_ov225_021B9C28
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9CFC 0x021B9CFC thumb ov225
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9CFC(char *,int);
u16 func_021B9C28(char *p,int index) {return *(u16 *)(func_021B9CFC(p,index)+2);}
