/*
 * function: ZUKAN_SEARCH_SCREEN_Tick
 * address:  0x021BC890
 * packet:   pkt_021BC890
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041F6C  0x02041F6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void func_02041F6C(u32 which, u32 op, u32 value);

void ZUKAN_SEARCH_SCREEN_Tick(void)
{
    func_02041F6C(3, 4, 0x80);
    func_02041F6C(3, 7, 0x80);
    func_02041F6C(7, 4, 0x80);
    func_02041F6C(7, 7, 0x80);
}
