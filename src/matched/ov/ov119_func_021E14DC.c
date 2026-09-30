/*
 * function: func_021E14DC
 * address: 0x021E14DC
 * packet: pkt_ov119_021E14DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201AF80 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
typedef unsigned short u16;
extern unsigned func_02017E1C(void *,unsigned,void *);
extern u16 *func_0201AF80(int,int);
extern void func_020307B0(void *);
extern void func_02045CAC(int,int,int);
extern void func_0201EFA4(int,int,int,int,int,int);
extern void func_0201F250(int,int,int);
extern void func_0201C7A4(void *,short,short,int,int);
void func_021E14DC(void *a,void *b,int x,int y,int flag,char *p) {int v;u16 *t;if(!flag) {v=func_02017E1C(a,171,0);if(!*(unsigned char *)(p+0x11f6)) {t=func_0201AF80(*(u16 *)(p+0x5f4),0);v=t[v];func_020307B0(t);}if(v==999) {func_02045CAC(*(int *)(p+0x720),162,*(int *)(p+0x730));}else {func_0201EFA4(*(int *)(p+0x724),1,v,3,1,1);func_02045CAC(*(int *)(p+0x720),27,*(int *)(p+0x734));func_0201F250(*(int *)(p+0x724),*(int *)(p+0x730),*(int *)(p+0x734));}func_0201C7A4(b,x,y,*(int *)(p+0x730),*(int *)(p+0x728));}}
