/*
 * function: FIELD_GetAreaZoneId
 * address:  0x021CD400
 * packet:   pkt_ov021_021CD400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gZoneAreaTable  0x021DB450  data  ov021  a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 r;
} Ent;

extern const Ent gZoneAreaTable[];

u32 FIELD_GetAreaZoneId(u32 a, int b, int c)
{
    u32 i;
    const Ent *e = gZoneAreaTable;

    for (i = 0; i < 4; i++, e++) {
        if (e->a == a && e->b <= (u32)b && b < e->b + 3 && e->c <= (u32)c && c < e->c + 3)
            return e->r;
    }
    return 0x1ab;
}
