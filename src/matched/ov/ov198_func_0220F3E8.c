/*
 * function: func_0220F3E8
 * address: 0x0220F3E8
 * packet: pkt_ov198_0220F3E8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_0220F478 0x0220F478 thumb ov198
 *   func_02210EFC 0x02210EFC thumb ov198
 *   d_02212550 0x02212550 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_02212550[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_02030DA8(void *,unsigned,unsigned,unsigned);
extern void func_0220F478(void *,u8 *);
extern int func_02210EFC(unsigned);
void func_0220F3E8(u8 *p)
{
    u8 *q;
    if (p[0x20]>5) p[0x20]=0;
    q=func_02030734(*(u16 *)(p+0x10),0x2544,1,d_02212550,0x130);
    func_02030DA8(*(void **)(p+0x28),(unsigned)func_0220F478,(unsigned)q,100);
    *(u8 **)q=p;
    if (p[0x1f]!=5) p[0x4b]=0;
    else if (func_02210EFC((unsigned)q)==1 && p[0x1c]==1) p[0x20]++;
    *(void **)(q+0x1d8)=*(void **)(p+0x2c);
    *(int *)(q+0x2178)=0;
    q[0x2176]=p[0x20];
    *(int *)(q+0x2540)=0;
}
