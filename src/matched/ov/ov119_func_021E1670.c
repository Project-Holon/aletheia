/*
 * function: func_021E1670
 * address: 0x021E1670
 * packet: pkt_ov119_021E1670
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7D0 0x0201C7D0 thumb
 */
extern unsigned func_02017E1C(void *,unsigned,void *);
extern void func_02045CAC(int,int,int);
extern void func_0201C7D0(void *,short,short,int,int,int);
void func_021E1670(void *a,void *b,int x,int y,char *p,int mode,int guard) {int v,w,id,color;v=func_02017E1C(a,110,0);w=func_02017E1C(a,173,0);id=func_02017E1C(a,5,0);if(v<=1 && w!=0 && !(guard && id==29) && !(guard && id==32)) {if(mode) {if(v==1)color=0x31a0;else color=0x39e0;}else {if(v==1)color=0xc80;else color=0x14c0;}func_02045CAC(*(int *)(p+0x720),v+46,*(int *)(p+0x730));func_0201C7D0(b,x,y,*(int *)(p+0x730),*(int *)(p+0x728),color);}}
