/*
 * function: func_021E198C
 * address: 0x021E198C
 * packet: pkt_ov119_021E198C
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
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern unsigned int func_02017E1C(void *,unsigned int,unsigned int);
extern void func_0201EF34(int,int,int);
extern void func_0201F250(int,int,int);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021E198C(int a,int b,int x,int y,char *p)
{
    int i,v;
    for(i=0;i<4;i++) {
        v=func_02017E1C((void *)a,54+i,0);
        if(v) {
            func_02045CAC(*(int *)(p+0x720),45,*(int *)(p+0x734));
            func_0201EF34(*(int *)(p+0x724),0,v);
            func_0201F250(*(int *)(p+0x724),*(int *)(p+0x730),*(int *)(p+0x734));
            func_0201C7A4(func_02045770((struct Descriptor *)b),x,y+16*i,*(void **)(p+0x730),*(void **)(p+0x728));
        }
    }
}
