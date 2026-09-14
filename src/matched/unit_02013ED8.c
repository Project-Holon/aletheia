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
 * function: sub_02013ED8, sub_02013EEC, sub_02013F2C, sub_02013F6C
 *
 * symbols:
 *   g_sub02013AD0Obj2  0x02146264  data
 *   sub_02013A94       0x02013A94  thumb
 *   sub_02013AD0       0x02013AD0  thumb
 *
 * alias: continues the record-cache family of unit_02013AD0.c and
 * unit_02013BA8.c: every accessor here that calls sub_02013AD0() reads
 * through the same cached record, at offsets not used by those two files.
 * g_sub02013AD0Obj2 is the same cache object (0x02146264) as
 * unit_02013AD0.c's g_sub02013AD0Obj, redeclared here with only the extra
 * fields (0x38..0x43, two of its three small lookup tables and their
 * counts) this file touches; nothing about the two declarations needs to
 * agree byte for byte, only the addresses they claim.
 *
 * The halfword at the cached record's offset 0x1e holds two adjacent 5 bit
 * fields with no gap (bits[0:4] and bits[5:9]); sub_02013ED8 is the
 * accessor for the high one (unit_02014034.c has the low one).
 * sub_02013EEC/F2C/F6C are three independent { key(u16); val(u16) } lookup
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

/* the record sub_02013AD0() returns; only the two 5 bit fields at 0x1e
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

extern struct Sub02013ED8Obj *g_sub02013AD0Obj2;
extern u32   sub_02013A94(u32 id);
extern void *sub_02013AD0(u32 id);

u8 sub_02013ED8(u32 id)
{
    struct Sub02013AD0Rec *r = sub_02013AD0(id);
    return r->mid5;
}

u32 sub_02013EEC(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count1; i++) {
        if (rid == g_sub02013AD0Obj2->arr1[i].key) {
            result = g_sub02013AD0Obj2->arr1[i].val;
            break;
        }
    }
    return result;
}

u32 sub_02013F2C(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count2; i++) {
        if (rid == g_sub02013AD0Obj2->arr2[i].key) {
            result = g_sub02013AD0Obj2->arr2[i].val;
            break;
        }
    }
    return result;
}

u32 sub_02013F6C(u32 id)
{
    u32 result = 0;
    u32 rid;
    s32 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count3; i++) {
        if (rid == g_sub02013AD0Obj2->arr3[i].key) {
            result = g_sub02013AD0Obj2->arr3[i].val;
            break;
        }
    }
    return result;
}

