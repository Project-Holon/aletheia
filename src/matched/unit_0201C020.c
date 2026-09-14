/*
 * unit:     yes
 * address:  0x0201C020
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201C020, sub_0201C0BC
 *
 * waza_tool.c: two more readers over a move record, each with its own copy of
 * the cache lookup src/matched/unit_0201BD28.c and
 * src/matched/unit_0201C1F4.c also carry.  sub_0201C020 counts how many of
 * the three bytes at +0x15 are set; sub_0201C0BC hands one of the three
 * signed bytes at +0x18 back through an out-parameter, or zero when the
 * matching +0x15 byte is clear.
 *
 * The +0x18 read is a `movs`/`ldrsb` register-offset pair because the index
 * is a run-time value and Thumb has no immediate-offset `ldrsb`, which is
 * also the only evidence that the field is signed where its +0x15 neighbour
 * is not (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * symbols:
 *   gWazaTool   0x02146530  data
 *   g_02146534  0x02146534  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C020.c  *       --addr 0x0201C020 --thumb
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Waza {
    u8  unk00[0x15];
    u8  unk15[3];
    s8  unk18[3];
};

struct WazaTool {
    struct Waza **recs;
    u16 *vals;
    s32 count;
};

extern struct WazaTool *gWazaTool;
extern struct Waza g_02146534;

extern void func_02048F4C(struct Waza *dest, u32 kind, u16 id);

u8 sub_0201C020(u16 id)
{
    struct Waza *rec;
    s32 i;
    u32 k;
    u32 n;

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
    n = 0;
    for (k = 0; k < 3; k++) {
        if (rec->unk15[k] != 0) {
            n++;
        }
    }
    return (u8)n;
}

u8 sub_0201C0BC(u16 id, u32 idx, s32 *out)
{
    struct Waza *rec;
    s32 i;
    u8 v;

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
    v = rec->unk15[idx];
    if (v != 0) {
        *out = rec->unk18[idx];
    } else {
        *out = 0;
    }
    return v;
}
