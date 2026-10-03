/*
 * function: func_021FAEC0
 * address: 0x021FAEC0
 * packet: pkt_ov186_021FAEC0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 */
extern int func_021FB7B0(int,int);
extern void func_021FB514(char *p, short x, short y);
void func_021FAEC0(char *p,unsigned index) { short x=(short)func_021FB7B0(*(int *)(p+0xc),0);func_021FB514(*(void **)(p+8),x,(short)(169-(index<<4))); }
