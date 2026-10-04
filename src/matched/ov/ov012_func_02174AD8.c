/*
 * function: func_02174AD8
 * address:  0x02174AD8
 * packet:   pkt_ov012_02174AD8
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02157450  0x02157450  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

void *func_02157450(void *a0, void *a1, u32 kind, void *rec);

u32 func_02174AD8(void *a0, u8 *a1, void *a2, void *a3, u32 a4, void **out, u8 *state)
{
    u8 *q = a1 + 0x2830;
    if (*state == 0) {
        *out = func_02157450(a0, a2, q[0], a3);
    } else {
        return 1;
    }
    (*state)++;
    return 0;
}
