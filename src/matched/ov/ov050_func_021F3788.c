/*
 * function: func_021F3788
 * address: 0x021F3788
 * packet: pkt_ov050_021F3788
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: index declared before pointer restores r4/r5; u16 fourth parameter reproduces the observed call-site truncation.
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE4B4 0x021BE4B4 thumb ov021
 *   func_021BE700 0x021BE700 thumb ov021
 */

extern int func_02188D2C(int *);
extern void func_021BE4B4(char *,int,int,int);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
void func_021F3788(int *p) { int i; char *q; q=(char *)func_02188D2C(p); func_021BE4B4(q,0,1,1); for(i=0;i<2;i++) func_021BE700(q,0,1,(unsigned short)i,0); }
