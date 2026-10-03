/*
 * function: func_021E15F8
 * address: 0x021E15F8
 * packet: pkt_ov119_021E15F8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02045CAC(int,int,int);
extern void func_0201EFA4(int,int,int,int,int,int);
extern void func_0201F250(int,int,int);
extern void func_0201C7A4(void *,short,short,int,int);
void func_021E15F8(void *a,void *b,int x,int y,char *p) {func_02017E1C(a,171,0);func_02045CAC(*(int *)(p+0x720),18,*(int *)(p+0x734));func_0201EFA4(*(int *)(p+0x724),0,func_02017E1C(a,158,0),3,1,1);func_0201F250(*(int *)(p+0x724),*(int *)(p+0x730),*(int *)(p+0x734));func_0201C7A4(b,x,y,*(int *)(p+0x730),*(int *)(p+0x728));}
