/*
 * function: func_02191DC8
 * address:  0x02191DC8
 * packet:   pkt_ov021_02191DC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041300  0x02041300  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);

void func_02191DC8(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal)
{
    func_02041300(layer, tile, x - 2, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 1, x - 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 2, x, y - 1, w, 1, pal);
    func_02041300(layer, tile + 4, x + w, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 5, x + w + 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 6, x - 2, y, 1, h, pal);
    func_02041300(layer, tile + 7, x - 1, y, 1, h, pal);
    func_02041300(layer, tile + 10, x + w, y, 1, h, pal);
    func_02041300(layer, tile + 11, x + w + 1, y, 1, h, pal);
    func_02041300(layer, tile + 12, x - 2, y + h, 1, 1, pal);
    func_02041300(layer, tile + 13, x - 1, y + h, 1, 1, pal);
    func_02041300(layer, tile + 14, x, y + h, w, 1, pal);
    func_02041300(layer, tile + 16, x + w, y + h, 1, 1, pal);
    func_02041300(layer, tile + 17, x + w + 1, y + h, 1, 1, pal);
}
