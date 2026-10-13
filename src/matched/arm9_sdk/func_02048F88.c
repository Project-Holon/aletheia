/*
 * function: ARC_TOOL_LoadMemberRange
 * address:  0x02048F88
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_LoadMemberRangeImpl  0x02048D54  arm
 *
 * The five-argument entry point of the allocating load: a pure forwarder to
 * ARC_TOOL_LoadMemberRangeImpl, with the caller's single stack argument copied down through
 * ip exactly as ARC_TOOL_ReadMemberRange does for ARC_TOOL_ReadMemberRangeImpl.
 *
 * Kept in its own file so the branch to ARC_TOOL_LoadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_LoadMember.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMemberRange.c \
 *       --func ARC_TOOL_LoadMemberRange --addr 0x02048F88 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *ARC_TOOL_LoadMemberRangeImpl(u32 archive_id, u32 member, u32 heap, u32 mode,
                           u32 *size_out);

void *ARC_TOOL_LoadMemberRange(u32 archive_id, u32 member, u32 heap, u32 mode,
                    u32 *size_out)
{
    return ARC_TOOL_LoadMemberRangeImpl(archive_id, member, heap, mode, size_out);
}
