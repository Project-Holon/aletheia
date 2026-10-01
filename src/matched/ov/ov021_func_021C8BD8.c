/*
 * function: func_021C8BD8
 * address:  0x021C8BD8
 * packet:   pkt_ov021_021C8BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAB44  0x021DAB44  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
typedef struct { u16 id; u16 a; } E;
extern E d_021DAB44[4];
E *func_021C8BD8(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (id == d_021DAB44[i].id)
            return &d_021DAB44[i];
    }
    return 0;
}
