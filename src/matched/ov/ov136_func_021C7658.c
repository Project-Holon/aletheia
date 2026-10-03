/*
 * function: func_021C7658
 * address: 0x021C7658
 * packet: pkt_ov136_021C7658
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021C76D0 0x021C76D0 thumb ov136
 * func_02025CD0 0x02025CD0 thumb
 * d_021C7E40 0x021C7E40 data a4
 * d_021C7E1C 0x021C7E1C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02025CD0(const void *,const void *,void *,int,u8,u16);
extern void func_021C76D0(u8 *p, u32 v);
extern const u8 d_021C7E40[],d_021C7E1C[];
void func_021C7658(u8 *p)
{
    int v;
    u16 n=*(u16 *)(*(u8 **)(p+8)+0x2fe);
    if (*(u16 *)(p+0x1c)>n) { *(u16 *)(p+0x1c)=n; v=0; }
    else v=p[0x1e];
    *(u32 *)(*(u8 **)(p+8)+0x294)=func_02025CD0(d_021C7E40,d_021C7E1C,p,1,v,102);
    func_021C76D0(p,v);
}
