/*
 * function: func_021C6E20
 * address:  0x021C6E20
 * packet:   pkt_ov021_021C6E20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
u8 func_021C6E20(R *r)
{
    int i;
    u8 c = 0;
    for (i = 0; i < r->n; i++) {
        if (r->f4[i] != 0)
            c++;
    }
    return c;
}
