/*
 * function: BTL_POKESET_Get
 * address:  0x0689CC70
 * packet:   pkt_ov095_0689CC70
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

u32 BTL_POKESET_Get(S *p, u32 i)
{
    if (i < p->n)
        return p->id[i];
    return 0;
}
