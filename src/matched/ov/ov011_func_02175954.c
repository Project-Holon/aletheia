/*
 * function: INTRUDE_COMM_StoreSessionRequest
 * address:  0x02175954
 * packet:   pkt_ov011_02175954
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u32 lo : 15;
    u32 a  : 7;
    u32 b  : 10;
    u8  pad04[0x28];
    u8  f2c;
    u8  pad2d[7];
} Rec;

int INTRUDE_COMM_StoreSessionRequest(void *unused, u8 *o, Rec *src)
{
    Rec *dst;
    int r;

    dst = (Rec *)(o + 0x78);
    r = 0;
    if (src->a > 0x14 || src->b > 0xb4) {
        return 0;
    }
    if (o[0x1a1] == 0 && src->f2c != 4) {
        r = 1;
        o[0x1a1] = r;
    }
    if (dst->f2c != 4) {
        return r;
    }
    *dst = *src;
    return r;
}
