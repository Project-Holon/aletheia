/*
 * function: func_021B2724
 * address: 0x021B2724
 * packet: pkt_ov013_021B2724
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B60D8 0x021B60D8 data a4
 *   func_020923B0 0x020923B0 arm
 */
typedef unsigned char u8;
extern int d_021B60D8[];
extern void *func_020923B0(void *,int,unsigned int);
void func_021B2724(u8 *p,u8 v)
{
    func_020923B0(p,0,24);
    *(int *)p=d_021B60D8[4];
    *(int *)(p+12)=0;
    p[4]=v;
}
