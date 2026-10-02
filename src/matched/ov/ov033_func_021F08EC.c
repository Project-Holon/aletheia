/*
 * function: func_021F08EC
 * address: 0x021F08EC
 * packet: pkt_ov033_021F08EC
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
extern void func_0204B3B4(int);
extern void func_0204AFD8(int);
extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
void func_021F08EC(char *p) { unsigned char i; char *q; for(i=0;i<4;i++) { q=p+i*12; func_0204B3B4(*(int *)(q+0x38)); if(i!=1) { func_0204AFD8(*(int *)(q+0x34)); func_0204A8D4(*(int *)(q+0x30)); } } func_0204ADA4(*(int *)(p+0x2c)); }
