/*
 * function: func_021C59DC
 * address:  0x021C59DC
 * packet:   pkt_ov111_021C59DC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204162C  0x0204162C  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0204162C(int channel);
extern void func_02041B6C(u32 bit);

void func_021C59DC(u32 bg, int mode)
{
    u16 *map = (u16 *)func_0204162C((u8)bg);
    u8 x, y;
    u16 n;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 24; x++) {
            map[(y + 11) * 32 + 4 + x] = 0;
        }
    }
    n = 0;
    switch (mode) {
    case 2:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 24; x++) {
                n++;
                map[(y + 11) * 32 + 4 + x] = n;
            }
        }
        break;
    case 0:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    case 1:
        n += 12;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    }
    func_02041B6C((u8)bg);
}
