/*
 * unit: no
 * function: func_021BA318
 * address: 0x021BA318
 * packet: pkt_ov181_021BA318
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203630C 0x0203630C arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern int func_0203630C(void);
void func_021BA318(u8 *p){if(**(int **)p){enum {K=0x2d1} k=K;if(p[k]==0)p[k+1]=(func_0203630C()&3)?1:0;p[0x2d1]=(p[0x2d1]+1)&3;}}
