/*
 * function: func_021BE374
 * address: 0x021BE374
 * packet: pkt_ov110_021BE374
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_021BDEF0 0x021BDEF0 thumb ov110
 *   func_021BE1B8 0x021BE1B8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern int func_021BD808(u8 *p, void *q);
extern int func_021BDEF0(u8 *,unsigned *);
extern int func_021BE1B8(u8 *,unsigned *);
extern void func_020061E4(u32 a);
int func_021BE374(u8 *p,unsigned *q) {
 if(*q<=2 && func_021BD808(p,q) && !*(int *)(p+0x70)) { func_020061E4(1352); return 0; }
 if(*(int *)(p+0x70)==0) { return func_021BDEF0(p,q); }
 else { return func_021BE1B8(p,q); }
}
