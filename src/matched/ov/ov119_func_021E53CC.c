/*
 * function: func_021E53CC
 * address:  0x021E53CC
 * packet:   pkt_ov119_021E53CC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 */
typedef unsigned char u8;
extern void func_02040DA8(int, int, int);
extern void func_020403F4(int);
void func_021E53CC(int p)
{
    if (*(u8 *)(p + 0x11ec) != 0) {
        func_02040DA8(6, 1, 0);
        func_020403F4(6);
        func_020403F4(7);
        *(u8 *)(p + 0x11ec) = 0;
    }
}
