/*
 * unit:     yes
 * function: func_02020E60
 * address:  0x02020E60
 * packet:   pkt_02020E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202F170       0x0202F170  thumb
 *   func_020490F4       0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember       0x02049250  arm
 *   ARC_TOOL_LoadMember       0x02048F60  arm
 *   item_gfx_member     0x0209EB6C  data
 *   item_gfx_member_x   0x0209E9E8  data
 *
 * The item archive's own accessor block: 0x02020E60..0x02020F84, seven
 * functions, five of them unlabelled leaves that print as a `.word`/`.byte`
 * run in the listing (see docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).
 *
 * This is the file that closes the item chain
 * func_02021014 <- func_02020FE4 <- func_02020F34: three separate functions
 * here name the item archive id 0x18 as a plain immediate
 * (func_02020F14's handle open, func_02020F34's one-shot member read) and
 * two name the item graphics archive 0x19 (func_02020F08 answers it as a
 * constant, func_02020F34 reads members of it).  Archive ids are the
 * decimal spelling of the a/X/Y/Z path, so 0x18 = 24 = a/0/2/4 and
 * 0x19 = 25 = a/0/2/5.
 *
 * 626 is the last item id: a/0/2/4 has 627 members, 0..626.  Both bounds
 * checks in this file clamp an out of range id to 0 rather than rejecting.
 *
 * Blocked at MATCH, not EXACT: three relocation sites have no witness
 * outside this range.
 *   - item_gfx_member_x (0x0209E9E8) and func_0202F170 (0x0202F170) are
 *     named only from here anywhere in the image.
 *   - item_gfx_member (0x0209EB6C) has exactly one literal witness,
 *     0x02020F7C, which is func_02020F34's own pool and therefore inside
 *     this range.  func_02020E60's copy of the same word sits at
 *     0x02020EF4 but is not indexed as a literal pool by disasm.py: that
 *     pool is inside the `.byte` run this unit's leaf functions live in.
 *     Splitting func_02020E60 and func_02020F34 into two files does not
 *     fix it either: verified separately, the split leaves
 *     func_02020E60 attested (literal 0x02020F7C, now outside its range)
 *     and func_02020F34 still not, since its only witness is its own
 *     pool word.  `tu --suggest-split` agrees and leaves both out.
 *
 * The middle piece that --suggest-split does keep, the five leaf
 * accessors 0x02020F08..0x02020F34, is filed EXACT on its own as
 * src/matched/unit_02020F08.c; this file stays as the whole-range record.
 *
 * Every concrete byte of this range is reproduced; only the relocation
 * fields above stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02020E60.c \
 *       --addr 0x02020E60 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct ItemGfxMember {
    u16 lo;
    u16 hi;
};

extern struct ItemGfxMember item_gfx_member[];
extern struct ItemGfxMember item_gfx_member_x[];

extern u32   func_0202F170(u32 item);
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);

u32 func_02020E60(u32 item, u32 which)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        if (item == 0 || item == 0xFFFF) {
            break;
        }
        return item;
    case 1:
        if (item == 0) {
            return 1001;
        }
        if (item == 0xFFFF) {
            return 1003;
        }
        return item_gfx_member[item].lo;
    case 2:
        if (item == 0) {
            return 1002;
        }
        if (item == 0xFFFF) {
            return 1004;
        }
        return item_gfx_member[item].hi;
    case 3:
        return item_gfx_member_x[func_0202F170(item)].lo;
    case 4:
        return item_gfx_member_x[func_0202F170(item)].hi;
    }

    return 0;
}

u32 func_02020F08(void)
{
    return 0x19;
}

u32 func_02020F0C(void)
{
    return 1;
}

u32 func_02020F10(void)
{
    return 0;
}

void *func_02020F14(u32 heap)
{
    return func_020490F4(0x18, heap);
}

u32 func_02020F20(void *handle, u32 item, u32 arg)
{
    if (item > 626) {
        item = 0;
    }

    return (u32)ARC_TOOL_LoadHandleMember(handle, item, arg);
}

void *func_02020F34(u32 item, u32 which, u32 heap)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        return ARC_TOOL_LoadMember(0x18, item, heap);
    case 1:
        return ARC_TOOL_LoadMember(0x19, item_gfx_member[item].lo, heap);
    case 2:
        return ARC_TOOL_LoadMember(0x19, item_gfx_member[item].hi, heap);
    }

    return 0;
}
