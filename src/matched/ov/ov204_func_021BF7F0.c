/*
 * function: func_021BF7F0
 * address: 0x021BF7F0
 * packet: pkt_ov204_021BF7F0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02016374 0x02016374 thumb
 */
typedef unsigned char u8;
extern void func_02016374(void *);
void func_021BF7F0(u8 *p)
{
    *(int *)(p+4)=1;
    if(*(int *)(p+8)==1)func_02016374(*(void **)p);
}
