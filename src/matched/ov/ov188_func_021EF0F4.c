/*
 * function: func_021EF0F4
 * address: 0x021EF0F4
 * packet: pkt_ov188_021EF0F4
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045A38 0x02045A38 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045A38(void *, u16 *, u32);
void func_021EF0F4(u8 *a, u8 *b)
{
    unsigned i;
    *(u16 *)(b+4) = *(u32 *)a;
    *(u16 *)(b+6) = *(u32 *)(a+4);
    *(u32 *)b = *(u32 *)(a+8);
    *(u16 *)(b+0x30) = *(u16 *)(a+0x18);
    *(u16 *)(b+0x32) = *(u16 *)(a+0x1a);
    *(u16 *)(b+0x34) = *(u16 *)(a+0x1c);
    *(u16 *)(b+0x36) = *(u16 *)(a+0x1e);
    *(u16 *)(b+0x38) = *(u16 *)(a+0x20);
    *(u16 *)(b+0x3a) = *(u16 *)(a+0x22);
    *(u16 *)(b+0x3c) = *(u16 *)(a+0x24);
    *(u16 *)(b+0x3e) = *(u16 *)(a+0x26);
    for(i=0;i<4;i++) *(u16 *)(b+8+i*2) = *(u16 *)(a+12+i*2);
    func_02045A38(*(void **)(a+20), (u16 *)(b+16), 16);
}
