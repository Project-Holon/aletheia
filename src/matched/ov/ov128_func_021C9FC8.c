/*
 * function: func_021C9FC8
 * address: 0x021C9FC8
 * packet: pkt_ov128_021C9FC8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045CAC(void *,u32,void *);
extern void func_0201F250(void *,u32,void *);
extern void func_021B6AE4(u8 *,u32,u16,u16,u32,u32,u16,u32);
void func_021C9FC8(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color)
{
    func_02045CAC(*(void **)(q+4),item,*(void **)(q+32));
    func_0201F250(*(void **)q,*(u32 *)(q+28),*(void **)(q+32));
    func_021B6AE4(p,*(u32 *)(q+52),x,y,*(u32 *)(q+28),*(u32 *)(q+0x17c),color,0);
}
