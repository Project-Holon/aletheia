/*
 * function: func_0219CA98
 * address:  0x0219CA98
 * packet:   pkt_ov021_0219CA98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Linear search of an 8-byte-entry table (count at +0, entries at *(+4)).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b)
{
    int i = 0;
    u16 *e = (u16 *)o[1];
    if (a) *a = 0xFFFF;
    do {
        if (e[0] == key) {
            if (a) *a = e[1];
            if (b) *b = e[2];
            return 1;
        }
        i++;
        e += 4;
    } while (i < (int)o[0]);
    return 0;
}
