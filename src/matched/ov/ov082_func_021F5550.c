/*
 * function: func_021F5550
 * address: 0x021F5550
 * packet: pkt_ov082_021F5550
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02189A60 0x02189A60 thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F55A0 0x021F55A0 thumb ov082
 */
typedef unsigned char u8;
extern void *func_0201210C(void *p);
extern u8 *func_02189A60(u8 *p);
extern void *func_020122C0(void *owner,void *a,void *b,unsigned int size);
extern void func_021F55A0(void);
void *func_021F5550(void *p) { u8 *obj = func_0201210C(p); switch ((unsigned int)*(void **)func_02189A60(obj)) { case 0: return 0; default: return func_020122C0(p,0,(void *)func_021F55A0,0); } }
