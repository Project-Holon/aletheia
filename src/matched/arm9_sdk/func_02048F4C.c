/*
 * function: func_02048F4C
 * address:  0x02048F4C
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
 * "Read one archive sub-file into a caller-supplied buffer", the defaulting
 * wrapper around ARC_TOOL_ReadMemberRangeImpl.  ARC_TOOL_ReadMemberRangeImpl takes five arguments
 * (dst, archive id, member, mode, size_out); this entry point supplies zero
 * for the last two, which is why the body is a single `mov r3, #0` doing
 * double duty: the same zero reaches r3 (the fourth argument) and the one
 * word of outgoing stack area (the fifth).  The `push {r3, lr}` is the home
 * slot for that stack argument, not a saved register.
 *
 * ARC_TOOL_ReadMemberRangeImpl itself opens a temporary archive handle with ARC_TOOL_OpenArchive,
 * sizes the member with ARC_TOOL_SeekMember, reads it and closes the handle again.
 *
 * Kept in its own file so that the branch to ARC_TOOL_ReadMemberRangeImpl is witnessed from
 * outside this range by src/matched/func_02048F74.c, which calls the same
 * target (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F4C.c \
 *       --func func_02048F4C --addr 0x02048F4C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archive_id, u32 member, u32 mode,
                          u32 *size_out);

void func_02048F4C(void *dst, u32 archive_id, u32 member)
{
    ARC_TOOL_ReadMemberRangeImpl(dst, archive_id, member, 0, 0);
}
