/*
 * function: func_02182080
 * address: 0x02182080
 * packet: pkt_ov018_02182080
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201232C 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021820A4 0x021820A4 thumb ov018
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201232C(void *, void *, int);
extern u8 *func_020124E8(void *);
extern void func_02082D44(void *, void *, int);
extern void func_021820A4(void);
void func_02182080(void *a, void *b) { func_0201232C(a,(void *)func_021820A4,0x9c); func_02082D44(b,func_020124E8(a),0x98); }
