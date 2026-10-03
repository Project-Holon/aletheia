/*
 * function: func_021BF794
 * address: 0x021BF794
 * packet: pkt_ov204_021BF794
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: The shifts at 021BF7B8/021BF7BC narrow the outgoing alpha to u8.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02015FBC 0x02015FBC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207D63C(void *,int,int,int,int);
extern void func_02015FBC(char *,u8);
void func_021BF794(u8 *p,int index,u32 alpha)
{
    func_0207D63C((void *)0x04000050,1,9,0,0);
    if(alpha>31)alpha=31;
    func_02015FBC(*(char **)((u32)p+(u32)index*12+8),alpha);
}
