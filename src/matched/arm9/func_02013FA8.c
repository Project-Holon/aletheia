/*
 * function: ZONEDATA_GetSecondSpecialKind
 * address:  0x02013FA8
 * packet:   pkt_02013FA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0028 ABS32 _ZoneSecondSpecialKindTable       : 0209DFC8 (data, from header) has no witness outside 02013FA8..02013FD8
 * symbols:
 *   _ZoneSecondSpecialKindTable  0x0209DFC8  data
 *   ZONEDATA_GetChangedZoneId  0x02013A94  thumb
 */

typedef unsigned int u32;

struct Ent0209DFC8 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

extern struct Ent0209DFC8 _ZoneSecondSpecialKindTable[];
typedef unsigned short u16;
extern u16 ZONEDATA_GetChangedZoneId(u32 key);

int ZONEDATA_GetSecondSpecialKind(u16 key)
{
    u32 v = ZONEDATA_GetChangedZoneId(key);
    u32 i;

    for (i = 0; i < 5; i++) {
        if (v == _ZoneSecondSpecialKindTable[i].code)
            return _ZoneSecondSpecialKindTable[i].kind;
    }
    return 0xffff;
}
