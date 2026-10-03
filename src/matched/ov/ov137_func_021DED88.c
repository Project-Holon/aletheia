/*
 * function: func_021DED88
 * address: 0x021DED88
 * packet: pkt_ov137_021DED88
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1974 0x021E1974 thumb ov137
 *   func_021E1954 0x021E1954 thumb ov137
 */
typedef unsigned short u16;
extern int func_021E1974(char *);
extern int func_021E1954(char *);
int func_021DED88(char *p) {if(func_021E1974(p)==1)*(int *)p=45;else if(*(int *)(p+48)==func_021E1954(p))*(int *)p=16;return 0;}
