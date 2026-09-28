/*
 * function: func_021CBCC4
 * address:  0x021CBCC4
 * packet:   pkt_ov021_021CBCC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps the owner's mode 0x43..0x49 to a small index.
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02188C9C(void *p);

int func_021CBCC4(void *p)
{
    u16 m = func_02188C9C(p);
    int r = 0;

    switch (m) {
    case 0x43:
        r = 0;
        break;
    case 0x44:
        r = 5;
        break;
    case 0x45:
        r = 1;
        break;
    case 0x46:
        r = 6;
        break;
    case 0x47:
        r = 2;
        break;
    case 0x48:
        r = 7;
        break;
    case 0x49:
        r = 4;
        break;
    }
    return r;
}
