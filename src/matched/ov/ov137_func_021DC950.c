/*
 * function: func_021DC950
 * address: 0x021DC950
 * packet: pkt_ov137_021DC950
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * d_021E2260 0x021E2260 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u16,u32,int,const void *,int);
extern u32 func_02012934(void *);
extern u32 func_0201292C(void *);
extern int func_0201AA18(void *);
extern void func_0201AB28(void *,int);
extern const unsigned char d_021E2260[];
u32 *func_021DC950(u32 *p,int a,int b)
{
    u32 *v;
    int i;
    v=func_02030734(4,152,1,d_021E2260,256);
    v[0]=func_02012934((void *)p[4]);
    v[1]=func_0201292C((void *)p[4]);
    v[14]=0;
    v[13]=a;
    v[15]=b;
    for(i=0;i<func_0201AA18((void *)v[0]);i++) func_0201AB28((void *)v[0],i);
    return v;
}
