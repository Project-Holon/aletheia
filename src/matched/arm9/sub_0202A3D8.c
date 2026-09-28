/*
 * function: func_0202A3D8
 * address:  0x0202A3D8
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   Table_0209FEE4  0x0209FEE4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Record {
    u16 val : 7;
    u16 rest : 9;
};

extern const struct Record Table_0209FEE4[];

u8 func_0202A3D8(u32 key)
{
    int i;

    for (i = 0; i < 0x1c; i++) {
        if (key == Table_0209FEE4[i].val) {
            return (u8)i;
        }
    }
    return 0x1c;
}
