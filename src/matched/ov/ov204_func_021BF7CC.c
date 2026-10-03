/*
 * function: func_021BF7CC
 * address: 0x021BF7CC
 * packet: pkt_ov204_021BF7CC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02015DB0 0x02015DB0 thumb
 *   func_02015DC0 0x02015DC0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02015DB0(void *);
extern void func_02015DC0(void *);
void func_021BF7CC(u8 *p,int index,int flag)
{
    if(flag!=0)func_02015DB0(*(void **)((u32)p+(u32)index*12+8));
    else func_02015DC0(*(void **)((u32)p+(u32)index*12+8));
}
