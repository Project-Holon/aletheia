/*
 * function: func_02013D74
 * address:  0x02013D74
 * packet:   pkt_02013D74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ZONEDATA_GetChangedZoneId  0x02013A94  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *
 * zonedata.c: true when the zone id is in 0x121..0x13C or func_02013D9C
 * accepts it.  The image shares one `movs r0, #1` exit between the range
 * test and the callee test, which only one disjunction gives
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 ZONEDATA_GetChangedZoneId(u32 key);
extern u32 func_02013D9C(u32 id);

int func_02013D74(u32 key)
{
    u32 v = ZONEDATA_GetChangedZoneId(key);

    if ((v >= 0x121 && v <= 0x13c) || func_02013D9C(v) == 1)
        return 1;
    return 0;
}
