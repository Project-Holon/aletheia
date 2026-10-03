/*
 * function: func_021C3650
 * address: 0x021C3650
 * packet: pkt_ov208_021C3650
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C36CC 0x021C36CC thumb ov208
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C36CC(u16 *heap, u8 *p, int key);
void func_021C3650(u16 *heap, u8 *p, int key)
{
    if (p[0x24] != 0) {
        p[0x24]--;
        return;
    }
    func_021C36CC(heap, p, key);
    p[0x24] = 0;
}
