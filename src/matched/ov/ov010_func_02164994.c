/*
 * function: func_02164994
 * address: 0x02164994
 * packet: pkt_ov010_02164994
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_021649E8 0x021649E8 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
struct Desc;
extern struct Desc *func_020122C0(void *,void *,void *,u32);
extern int func_021649E8(void *,int *);
extern void func_0215897C(void *,void *);
int func_02164994(void *a,void *b){void *v=func_0215A5F4(b);void *t=func_020122C0(func_0215A5DC(b),0,(void *)func_021649E8,0);if(t==0)return 1;func_0215897C(v,t);return 1;}
