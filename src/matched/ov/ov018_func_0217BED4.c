/*
 * function: INTRUDE_FIELD_GetZoneAnchor
 * address:  0x0217BED4
 * packet:   pkt_ov018_0217BED4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013D5C  0x02013D5C  thumb
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   INTRUDE_FIELD_gHomeAnchorPos     0x02182B60  data   a4
 */

typedef struct { int x, y, z; } V12;

typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern short *INTRUDE_FIELD_FindZonePos(int);
extern const V12 INTRUDE_FIELD_gHomeAnchorPos;

int INTRUDE_FIELD_GetZoneAnchor(int a, V12 *out)
{
    short *p;
    int x, y, z;

    if (func_02013D5C(a) != 1) {
        p = INTRUDE_FIELD_FindZonePos(a);
        if (p == 0)
            return 0;
        z = p[4] << 16;
        y = p[3] << 16;
        x = p[2] << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = INTRUDE_FIELD_gHomeAnchorPos;
    }
    return 1;
}
