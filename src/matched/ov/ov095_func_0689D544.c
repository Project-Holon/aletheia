/*
 * function: BTL_POSPOKE_UpdatePosOfPoke
 * address:  0x0689D544
 * packet:   pkt_ov095_0689D544
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_POSPOKE_UpdatePosOfPoke  0x0689D544  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

void BTL_POSPOKE_UpdatePosOfPoke(T *a, int b)
{
    u32 v;

    v = a->r[b].c;
    if (v != 0x1f)
        a->idx[v] = b;
}
