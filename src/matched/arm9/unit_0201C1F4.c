/*
 * unit:     yes
 * address:  0x0201C1F4
 * packet:   pkt_0201C1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201C1F4, sub_0201C284
 *
 * waza_tool.c: two predicates over a move record, "is field 4 equal to 0x65"
 * and "is field 0x0E equal to 6", which are the same two special values
 * src/matched/unit_0201BD28.c's getter substitutes for at ids 4 and 7.
 *
 * Both carry their own copy of that file's cache lookup rather than calling
 * it: the slot search, the "cache full, reuse the last slot" fixup, the
 * func_02048F4C load and the not-yet-built fallback to 0x02146534 are written
 * out again in each.  The duplication is in the source, not an inlining
 * decision: sub_0201BD28 is a real function with eight callers, and the
 * bodies here reach the record directly instead of going through its
 * 32 case getter.
 *
 * VERSION SENSITIVITY: 0x65 and 6 are content ids of the move table, not
 * offsets.  They are expected to be identical in Pokemon White but are the
 * constants to re-read first if a White build diverges.
 *
 * symbols:
 *   gWazaTool   0x02146530  data
 *   g_02146534  0x02146534  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1F4.c \
 *       --addr 0x0201C1F4 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Waza {
    u8  unk00[4];
    u8  unk04;
    u8  unk05[9];
    u8  unk0E;
    u8  unk0F;
};

struct WazaTool {
    struct Waza **recs;
    u16 *vals;
    s32 count;
};

extern struct WazaTool *gWazaTool;
extern struct Waza g_02146534;

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);

u32 sub_0201C1F4(u16 id)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    if (rec->unk04 == 0x65) {
        return 1;
    }
    return 0;
}

u32 sub_0201C284(u16 id)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    if (rec->unk0E == 6) {
        return 1;
    }
    return 0;
}
