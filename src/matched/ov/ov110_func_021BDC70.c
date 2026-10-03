/*
 * function: func_021BDC70
 * address: 0x021BDC70
 * packet: pkt_ov110_021BDC70
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_021BD8D8 0x021BD8D8 thumb ov110
 *   func_021BDB98 0x021BDB98 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern int func_021BD808(u8 *p, void *q);
extern int func_021BD8D8(u8 *,unsigned *);
extern int func_021BDB98(u8 *,unsigned *);
extern void func_020061E4(u32 a);
int func_021BDC70(u8 *p,unsigned *q) {
 int result;
 if(*q<=1 && func_021BD808(p,q) && !*(int *)(p+0x70)) { func_020061E4(1352); return 0; }
 if(*(int *)(p+0x70)==0) { result=func_021BD8D8(p,q); }
 else { result=func_021BDB98(p,q); }
 return result;
}
