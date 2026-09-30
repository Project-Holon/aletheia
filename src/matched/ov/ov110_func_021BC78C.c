/*
 * function: func_021BC78C
 * address: 0x021BC78C
 * packet: pkt_ov110_021BC78C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041648 0x02041648 arm
 *   func_02041664 0x02041664 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02041648(u8);
extern int func_02041664(u8);
void func_021BC78C(u8 *p, int a, int b, int step, int n)
{
    *(int *)p=a;
    if (b==0) {
        *(int *)(p+8)=func_02041648(a);
        *(int *)(p+4)=0;
    } else {
        *(int *)(p+8)=func_02041664(a);
        *(int *)(p+4)=3;
    }
    *(int *)(p+0xc)=(*(int *)(p+8)+step)&511;
    *(int *)(p+8)<<=12;
    *(int *)(p+0x10)=(step<<12)/n;
    *(u16 *)(p+0x14)=n;
    *(u16 *)(p+0x16)=0;
}
