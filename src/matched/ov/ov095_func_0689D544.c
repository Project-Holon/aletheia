/*
 * function: func_0689D544
 * address:  0x0689D544
 * packet:   pkt_ov095_0689D544
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0689D544  0x0689D544  thumb
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

void func_0689D544(T *a, int b)
{
    u32 v;

    v = a->r[b].c;
    if (v != 0x1f)
        a->idx[v] = b;
}
