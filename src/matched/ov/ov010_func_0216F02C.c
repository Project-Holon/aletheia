/*
 * function: func_0216F02C
 * address: 0x0216F02C
 * packet: pkt_ov010_0216F02C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082A7C 0x02082A7C arm
 *   func_020120F4 0x020120F4 thumb
 */

extern void func_02082A7C(int,void *,int);
extern void *func_020120F4(void *);
void func_0216F02C(void **p,void *a,void *b) { int zero=0; func_02082A7C(0,p,40); p[0]=a; p[1]=func_020120F4(a); p[2]=b; p[5]=(void *)zero; p[6]=(void *)zero; p[7]=(void *)zero; }
