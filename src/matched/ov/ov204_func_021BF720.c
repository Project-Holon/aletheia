/*
 * function: func_021BF720
 * address: 0x021BF720
 * packet: pkt_ov204_021BF720
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
void func_021BF720(u8 *p,int flag,int index)
{
    if(flag==1)func_02015EB0(*(void **)((u32)p+(u32)index*12+8));
    else func_02015EA0(*(void **)((u32)p+(u32)index*12+8));
}
