/*
 * function: func_0202A420
 * address:  0x0202A420
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202A3D8   0x0202A3D8  thumb
 *   Table_0209FEE4  0x0209FEE4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Record {
    u16 val : 7;
    u16 field2 : 4;
    u16 rest : 5;
};

extern u8 func_0202A3D8(u32 key);
extern const struct Record Table_0209FEE4[];

u32 func_0202A420(u32 key)
{
    u8 idx = func_0202A3D8(key);
    if (idx >= 0x1c) {
        return 0x11;
    }
    return Table_0209FEE4[idx].rest;
}
