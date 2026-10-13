/*
 * function: ARC_TOOL_ReadMemberRange
 * address:  0x02048F74
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_ReadMemberRangeImpl  0x02048D00  arm
 *
 * The five-argument entry point of the same read: a pure forwarder to
 * ARC_TOOL_ReadMemberRangeImpl that copies the caller's one stack argument down into its own
 * outgoing stack area (`ldr ip, [sp, #8]` reads it across the two words this
 * function pushed) and leaves r0-r3 untouched.
 *
 * Kept in its own file so the branch to ARC_TOOL_ReadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_ReadMember.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadMemberRange.c \
 *       --func ARC_TOOL_ReadMemberRange --addr 0x02048F74 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archive_id, u32 member, u32 mode,
                          u32 *size_out);

void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    ARC_TOOL_ReadMemberRangeImpl(dst, archive_id, member, mode, size_out);
}
