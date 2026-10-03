/*
 * function: func_021E57A4
 * address: 0x021E57A4
 * packet: pkt_ov119_021E57A4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
void func_021E57A4(int p)
{
    if (*(u8 *)(p + 0x11eb) == 1) {
        func_02040DA8(4, 1, 0);
        func_02040DA8(6, 1, 0);
        func_020403F4(4);
        func_020403F4(5);
        func_020403F4(6);
        func_020403F4(7);
        *(u8 *)(p + 0x11eb) = 0;
    }
}
