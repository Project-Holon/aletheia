/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02013ED8
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_GetFieldEffectSetId, ZONEDATA_GetFogId, ZONEDATA_GetLightId, ZONEDATA_GetFieldSkillMapEffect
 *
 * symbols:
 *   g_ZoneDataMgr  0x02146264  data
 *   ZONEDATA_GetChangedZoneId       0x02013A94  thumb
 *   ZONEDATA_GetHeader       0x02013AD0  thumb
 *
 * alias: continues the record-cache family of unit_02013AD0.c and
 * unit_02013BA8.c: every accessor here that calls ZONEDATA_GetHeader() reads
 * through the same cached record, at offsets not used by those two files.
 * g_ZoneDataMgr is the same cache object (0x02146264) as
 * unit_02013AD0.c's g_ZoneDataMgr, redeclared here with only the extra
 * fields (0x38..0x43, two of its three small lookup tables and their
 * counts) this file touches; nothing about the two declarations needs to
 * agree byte for byte, only the addresses they claim.
 *
 * The halfword at the cached record's offset 0x1e holds two adjacent 5 bit
 * fields with no gap (bits[0:4] and bits[5:9]); ZONEDATA_GetFieldEffectSetId is the
 * accessor for the high one (unit_02014034.c has the low one).
 * ZONEDATA_GetFogId/F2C/F6C are three independent { key(u16); val(u16) } lookup
 * tables reached through the cache object, differing only in the width of
 * their count field and in their not-found sentinel (0x0FFFFFFF for the
 * first two, 0 for the third).  The third table's array pointer and count
 * sit at offsets 0x44/0x43, immediately after this file's range in the
 * struct, and are declared again in unit_02014034.c.
 *
 * Near miss: sub_02013FA8 (0x02013FA8..0x02013FD8, 48 bytes), a five entry
 * table lookup unrelated to the cache object, reproduces every concrete
 * byte and caps at MATCH: the only pool word anywhere in the image that
 * names its table address is its own, so the honesty rule refuses the
 * witness.  Parked at src/pending/sub_02013FA8.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013ED8.c \
 *       --addr 0x02013ED8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

/* the record ZONEDATA_GetHeader() returns; only the two 5 bit fields at 0x1e
 * that this file reads. */
struct Sub02013AD0Rec {
    u8  pad00[0x1e];
    u16 lo5 : 5;
    u16 mid5 : 5;
    u16 hi6 : 6;
};

struct Sub02013ED8Pair {
    u16 key;
    u16 val;
};

struct Sub02013ED8Obj {
    u8                        pad00[0x38];
    const struct Sub02013ED8Pair *arr1;    /* 0x38 */
    const struct Sub02013ED8Pair *arr2;    /* 0x3c */
    u16                        count1;      /* 0x40 */
    u8                         count2;      /* 0x42 */
    u8                         count3;      /* 0x43 */
    const struct Sub02013ED8Pair *arr3;    /* 0x44 */
};

extern struct Sub02013ED8Obj *g_ZoneDataMgr;
extern u16 ZONEDATA_GetChangedZoneId(u32 key);
extern void *ZONEDATA_GetHeader(u32 id);

u8 ZONEDATA_GetFieldEffectSetId(u32 id)
{
    struct Sub02013AD0Rec *r = ZONEDATA_GetHeader(id);
    return r->mid5;
}

u32 ZONEDATA_GetFogId(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32 i;

    rid = ZONEDATA_GetChangedZoneId(id);
    for (i = 0; i < g_ZoneDataMgr->count1; i++) {
        if (rid == g_ZoneDataMgr->arr1[i].key) {
            result = g_ZoneDataMgr->arr1[i].val;
            break;
        }
    }
    return result;
}

u32 ZONEDATA_GetLightId(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32 i;

    rid = ZONEDATA_GetChangedZoneId(id);
    for (i = 0; i < g_ZoneDataMgr->count2; i++) {
        if (rid == g_ZoneDataMgr->arr2[i].key) {
            result = g_ZoneDataMgr->arr2[i].val;
            break;
        }
    }
    return result;
}

u32 ZONEDATA_GetFieldSkillMapEffect(u32 id)
{
    u32 result = 0;
    u32 rid;
    s32 i;

    rid = ZONEDATA_GetChangedZoneId(id);
    for (i = 0; i < g_ZoneDataMgr->count3; i++) {
        if (rid == g_ZoneDataMgr->arr3[i].key) {
            result = g_ZoneDataMgr->arr3[i].val;
            break;
        }
    }
    return result;
}

