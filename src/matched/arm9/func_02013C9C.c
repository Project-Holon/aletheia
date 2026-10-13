/*
 * function: func_02013C9C
 * address:  0x02013C9C
 * packet:   pkt_02013C9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0028 ABS32 _ZoneSpecialKindTable       : 0209E026 (data, from header) has no witness outside 02013C9C..02013CC8
 * symbols:
 *   _ZoneSpecialKindTable  0x0209E026  data
 *   ZONEDATA_GetChangedZoneId  0x02013A94  thumb
 */

typedef unsigned int u32;

struct Ent0209E026 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

extern struct Ent0209E026 _ZoneSpecialKindTable[];
typedef unsigned short u16;
extern u16 ZONEDATA_GetChangedZoneId(u32 key);

int func_02013C9C(u16 key)
{
    u32 r = ZONEDATA_GetChangedZoneId(key);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        if (r == _ZoneSpecialKindTable[i].code)
            return _ZoneSpecialKindTable[i].kind;
    }
    return -1;
}
