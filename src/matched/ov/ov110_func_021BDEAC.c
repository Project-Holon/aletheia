/*
 * function: func_021BDEAC
 * address: 0x021BDEAC
 * packet: pkt_ov110_021BDEAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_021BDCB4 0x021BDCB4 thumb ov110
 *   func_021BDB98 0x021BDB98 thumb ov110
 */
typedef unsigned char u8;
extern int func_021BD808(u8 *,unsigned *);
extern int func_021BDCB4(u8 *,unsigned *);
extern int func_021BDB98(u8 *,unsigned *);
extern void func_020061E4(int);
int func_021BDEAC(u8 *p,unsigned *q) {
 if(*q<=1 && func_021BD808(p,q) && !*(int *)(p+0x70)) { func_020061E4(1352); return 0; }
 if(*(int *)(p+0x70)==0) { return func_021BDCB4(p,q); }
 else { return func_021BDB98(p,q); }
}
