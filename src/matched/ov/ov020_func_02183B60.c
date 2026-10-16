/*
 * function: EVENT_MAPCHANGE_StartMarker
 * address:  0x02183B60
 * packet:   pkt_02183B60
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef int (*fp)(void);

int EVENT_MAPCHANGE_StartMarker(int f)
{
    if (f)
        ((fp)f)();
    return ~f;
}
