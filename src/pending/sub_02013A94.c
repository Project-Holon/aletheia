/*
 * function: sub_02013A94
 * address:  0x02013A94
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   g_sub02013AD0Obj  0x02146264  data
 *   sZoneSubstKey     0x020A72A8  data
 *   sZoneSubstVal     0x020A72AA  data
 *
 * Blocked on: no class, and permanently for the two table pools.  Every
 * concrete byte is reproduced.  The ABS32 at 0x02146264 resolves (`literal`,
 * fourteen other pools hold it), but 0x020A72A8 and 0x020A72AA appear in no
 * other pool word anywhere in the image, are plain data so no `label` applies,
 * and sit immediately before the "zonedata.c" string rather than after a
 * terminated one, so `string` does not apply either.  Only a second, outside
 * reader of the same table could lift this, and there is none.
 *
 * The zone-id substitution hook every other entry point in the subsystem goes
 * through: sub_02013AD0 remaps the caller's id through this before using it as
 * the record index, and so do the side-table lookups func_02013EEC,
 * func_02013F2C and func_02013F6C.  The table is two { u16 key; u16 value }
 * pairs at 0x020A72A8 (key 0x0000 -> 0x01a8, key 0x0126 -> 0x0127), each gated
 * by its own byte in the manager's +0x48 pair, which sub_02013A80 sets.  An
 * unmatched id is returned unchanged.
 *
 * Two pool words, two symbols: the key lane is read from 0x020A72A8 and the
 * value lane from 0x020A72AA, both with a stride of four bytes, so each lane
 * is indexed as `[i * 2]` of its own u16 array rather than as two fields of
 * one struct.  Folding them into a single symbol loses one of the two
 * relocations.
 *
 * Declaration order is register order here and nothing else distinguishes the
 * two locals: declaring the manager pointer first puts it in r4 and the loop
 * counter in r5, which is the mirror image of the original's allocation and
 * also flips the operand order of the `adds r1, r5, r4`.  The counter has to
 * be declared first.  See
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 * Version note: a two-entry id substitution gated at runtime is exactly the
 * shape a version- or event-exclusive area would take.  Which of the two
 * meanings it carries is not readable from this address range, and the
 * constants 0x01a8 / 0x0126 / 0x0127 are content, so nothing about them
 * should be assumed to hold for White.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02013A94.c \
 *       --func sub_02013A94 --addr 0x02013A94 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct ZoneDataMgr {
    void *archive;
    u8    record[0x34 - 0x04];
    u16   cached_id;
    u16   pad36;
    void *table38;
    void *table3c;
    u16   count40;
    u8    count42;
    u8    count43;
    void *table44;
    u8    subst_on[0x4c - 0x48];
};

extern struct ZoneDataMgr *g_sub02013AD0Obj;
extern const u16 sZoneSubstKey[];
extern const u16 sZoneSubstVal[];

u32 sub_02013A94(u32 id)
{
    s32 i;
    struct ZoneDataMgr *mgr = g_sub02013AD0Obj;

    for (i = 0; i < 2; i++) {
        if (mgr->subst_on[i] != 0 && id == sZoneSubstKey[i * 2])
            return sZoneSubstVal[i * 2];
    }
    return id;
}
