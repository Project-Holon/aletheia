/*
 * function: func_021C76BC
 * address: 0x021C76BC
 * packet: pkt_ov128_021C76BC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009A1C 0x02009A1C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_0201283C(void *);
struct Sub020097BCObj;
extern int func_02009A1C(struct Sub020097BCObj *obj, u32 i);
int func_021C76BC(int *p,u8 *q) {int i;void *v;if(*p==1) {v=func_0201283C(*(void **)(q+4));for(i=0;i<32;i++) {if(func_02009A1C(v,i)==0) return 1;}}else return 1;return 0;}
