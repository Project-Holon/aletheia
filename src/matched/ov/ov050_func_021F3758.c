/*
 * function: func_021F3758
 * address: 0x021F3758
 * packet: pkt_ov050_021F3758
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: index declared before pointer restores r4/r5; fourth callee parameter is u16 for the observed call-site shift pair.
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 */

extern int func_02188D2C(int *);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *);
int func_021F3758(int *p) { int i; char *q; q=(char *)func_02188D2C(p); for(i=0;i<1;i++) { if(func_021BE6BC(func_021BE674(q,0,0,(unsigned short)i))==0) return 0; } return 1; }
