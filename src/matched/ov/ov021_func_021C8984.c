/*
 * function: func_021C8984
 * address:  0x021C8984
 * packet:   pkt_ov021_021C8984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAB24  0x021DAB24  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u16 id; u16 pad; u32 v; } E;
extern E d_021DAB24[4];
E *func_021C8984(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (id == d_021DAB24[i].id)
            return &d_021DAB24[i];
    }
    return 0;
}
