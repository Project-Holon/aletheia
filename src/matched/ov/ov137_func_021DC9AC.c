/*
 * function: func_021DC9AC
 * address: 0x021DC9AC
 * packet: pkt_ov137_021DC9AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021DC924 0x021DC924 thumb ov137
 * func_021DC950 0x021DC950 thumb ov137
 * func_0203D7B0 0x0203D7B0 arm
 * func_02031348 0x02031348 arm
 * d_021BED00 0x021BED00 data ov091 a4
 * d_0000005B 0x0000005B data a1
 */
typedef unsigned int u32;
extern int func_021DC924(void *);
extern void *func_021DC950(void *,int,int);
extern void func_0203D7B0(int);
extern void func_02031348(void *,int,const void *,void *);
extern const unsigned char d_021BED00[];
extern const unsigned char d_0000005B[];
int func_021DC9AC(u32 *p)
{
    void *v;
    if (!func_021DC924((void *)p[3])) p[0]=5;
    else {
        func_0203D7B0(1);
        v=func_021DC950(p,21,0);
        p[6]=(u32)v;
        func_02031348((void *)p[8],(int)d_0000005B,d_021BED00,v);
        *(u32 *)p[3]=1;
        p[0]=2;
    }
    return 0;
}
