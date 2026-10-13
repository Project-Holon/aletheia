/*
 * function: ARC_TOOL_LoadMember
 * address:  0x02048F60
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
 * "Load one archive sub-file into a fresh heap block", the defaulting wrapper
 * around ARC_TOOL_LoadMemberRangeImpl.  Same shape as ARC_TOOL_ReadMember one entry above: the
 * callee takes (archive id, member, heap, mode, size_out) and this entry
 * point supplies zero for the last two, so one `mov r3, #0` feeds both r3 and
 * the single outgoing stack word, and `push {r3, lr}` is that word's home
 * slot rather than a saved register.
 *
 * This is the call the field code uses to pull a map matrix out of a/0/1/2's
 * sibling archive: MAP_MATRIX_Load in ov010 calls it as
 * ARC_TOOL_LoadMember(9, matrix_id, heap), i.e. archive id 9 = a/0/0/9, with the
 * matrix id taken straight from the zone record's +0x04 lane.  See the
 * "Zone to map model" section of docs/ASSETS.md.
 *
 * Kept in its own file so the branch to ARC_TOOL_LoadMemberRangeImpl is witnessed from
 * outside this range by src/matched/ARC_TOOL_LoadMemberRange.c
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMember.c \
 *       --func ARC_TOOL_LoadMember --addr 0x02048F60 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *ARC_TOOL_LoadMemberRangeImpl(u32 archive_id, u32 member, u32 heap, u32 mode,
                           u32 *size_out);

void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap)
{
    return ARC_TOOL_LoadMemberRangeImpl(archive_id, member, heap, 0, 0);
}
