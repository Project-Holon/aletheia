/*
 * unit:     yes
 * function: FILE_UTIL_GetItemCount
 * address:  0x02020F08
 * packet:   pkt_02020E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *
 * Five unlabelled leaf accessors of the item archive block, none of which
 * saves lr and none of which therefore carries a `func_` label in the
 * listing (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md):
 * they print as a `.byte` run between FILE_UTIL_Get's literal pool and
 * FILE_UTIL_CreateArcTool0F34.
 *
 * This unit is the code-side attestation of the item archive's identity.
 * The archive id in this image is the decimal spelling of the a/X/Y/Z
 * path, so:
 *   - FILE_UTIL_Create_0F14 opens archive id 0x18 = 24 = a/0/2/4 as a persistent
 *     0x50-byte handle (func_020490F4 takes the archive id in r0), and
 *     FILE_UTIL_LoadArcMember reads member `item` out of that same handle after
 *     clamping the item id to 626, the last of a/0/2/4's 627 members.
 *   - FILE_UTIL_GetItemCount answers archive id 0x19 = 25 = a/0/2/5, the item
 *     graphics archive FILE_UTIL_CreateArcTool0F34 reads icon members out of.
 *
 * FILE_UTIL_GetBankCount and FILE_UTIL_GetBaseIndex are constant 1 / constant 0 answers in
 * the same block; the value they stand for is not attested here, only the
 * constant.
 *
 * Cut out of the natural 0x02020E60..0x02020F84 unit
 * (src/pending/unit_02020E60.c) on `tu --suggest-split`'s advice: the two
 * functions left out both carry relocations to data symbols with no
 * witness outside that range, while this piece's two relocations are both
 * label-attested from elsewhere in the image.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020F08.c \
 *       --addr 0x02020F08 --thumb
 */

typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);

u32 FILE_UTIL_GetItemCount(void)
{
    return 0x19;
}

u32 FILE_UTIL_GetBankCount(void)
{
    return 1;
}

u32 FILE_UTIL_GetBaseIndex(void)
{
    return 0;
}

void *FILE_UTIL_Create_0F14(u32 heap)
{
    return func_020490F4(0x18, heap);
}

u32 FILE_UTIL_LoadArcMember(void *handle, u32 item, u32 arg)
{
    if (item > 626) {
        item = 0;
    }

    return (u32)ARC_TOOL_LoadHandleMember(handle, item, arg);
}
