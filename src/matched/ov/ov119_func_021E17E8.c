/*
 * function: func_021E17E8
 * address: 0x021E17E8
 * packet: pkt_ov119_021E17E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 */
typedef signed short s16;
extern void func_02045CAC(int,int,int);
extern void *func_02045770(int);
extern unsigned int func_02017E1C(void *,unsigned int,unsigned int);
extern void func_0201EFA4(int,int,int,int,int,int);
extern void func_0201F250(int,int,int);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021E17E8(int a,int b,int x,int y,char *p)
{
    int v,w;
    func_02045CAC(*(int *)(p+0x720),39,*(int *)(p+0x734));
    v=func_02017E1C((void *)a,160,0);
    w=func_02017E1C((void *)a,161,0);
    func_0201EFA4(*(int *)(p+0x724),0,v,3,1,1);
    func_0201EFA4(*(int *)(p+0x724),1,w,3,1,1);
    func_0201F250(*(int *)(p+0x724),*(int *)(p+0x730),*(int *)(p+0x734));
    func_0201C7A4(func_02045770(b),x,y,*(void **)(p+0x730),*(void **)(p+0x728));
}
