/*
 * function: func_021E1778
 * address: 0x021E1778
 * packet: pkt_ov119_021E1778
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 */
typedef signed short s16;
extern void func_02045CAC(int,int,int);
extern void *func_02045770(int);
extern unsigned int func_02017E1C(void *p, unsigned int id, unsigned int v);
extern void func_0201EF40(int,int,int);
extern void func_0201F250(int,int,int);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021E1778(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC(*(int *)(p+0x720),43,*(int *)(p+0x734));
    v=func_02017E1C((void *)a,6,0);
    if(v) {
        func_0201EF40(*(int *)(p+0x724),0,v);
        func_0201F250(*(int *)(p+0x724),*(int *)(p+0x730),*(int *)(p+0x734));
        func_0201C7A4(func_02045770(b),x,y,*(void **)(p+0x730),*(void **)(p+0x728));
    }
}
