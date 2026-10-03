/*
 * function: func_021DF778
 * address: 0x021DF778
 * packet: pkt_ov137_021DF778
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_0218417C 0x0218417C thumb ov022
 *   func_0202F038 0x0202F038 thumb
 */
typedef unsigned char u8;typedef unsigned int u32;
extern void *func_021DEB10(char *p);extern u32 func_0218417C(u8 *);extern void func_0202F038(void *);
int func_021DF778(char *p){if(func_0218417C(func_021DEB10(p))){func_0202F038(*(void **)(p+0xda8));*(void **)(p+0xda8)=0;*(int *)p=50;return 1;}return 0;}
