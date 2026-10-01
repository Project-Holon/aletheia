/*
 * function: func_021DCB04
 * address: 0x021DCB04
 * packet: pkt_ov137_021DCB04
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * func_02082BCC 0x02082BCC arm
 * d_021E2268 0x021E2268 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u16,u32,int,const void *,int);
extern void func_02082BCC(void *,int,u32);
extern const unsigned char d_021E2268[];
u32 *func_021DCB04(u32 a,int heap)
{
    u32 *p;
    p=func_02030734(heap,88,0,d_021E2268,152);
    func_02082BCC(p,0,88);
    p[0]=a;
    p[19]=(u32)func_02030734(heap,0x1be4,0,d_021E2268,159);
    p[20]=(u32)func_02030734(heap,0x1be4,0,d_021E2268,161);
    return p;
}
