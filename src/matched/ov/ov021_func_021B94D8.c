/*
 * function: FIELD_RAIL_CLOSED_ContainsLine
 * address:  0x021B94D8
 * packet:   pkt_ov021_021B94D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The element count is a volatile u16: the original reads it once for the
 * loop entry guard and again on every bottom test, while the array base is
 * hoisted.  A plain u16 count is CSEd into one register (6 bytes shorter).
 *
 * symbols:
 *   FIELD_RAIL_CLOSED_Contains  0x021B94C0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u8 b[0x48]; } E48;
typedef struct { u16 f0; volatile u16 n; u8 pad[0x10]; E48 *arr; } SR;
int FIELD_RAIL_CLOSED_Contains(u16 *p, u16 v);
int FIELD_RAIL_CLOSED_ContainsLine(u16 *r, E48 *e, SR *sr)
{
    int i;
    int found = 0;
    for (i = 0; i < sr->n; i++) {
        if (e == &sr->arr[i])
            found = i;
    }
    return FIELD_RAIL_CLOSED_Contains(r, found);
}
