/*
 * unit:     no
 * function: FLD_BTL_INST_TOOL_LoadTrainerGroup
 * address:  0x0216880C
 * packet:   pkt_02168800
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *
 * The reader for a/2/1/5: allocate a buffer and load one group record.
 * ARC_UTIL_LoadMember(archive_id, member, flag, heap) is arc_util.c's
 * "allocate and read a member" helper, so the returned pointer is the
 * sub-file itself.
 *
 * Two things the bytes pin down.  The member is `group + 1`, truncated to
 * 16 bits before the call, so group 0 is sub-file 1 and sub-file 0 is the
 * usual unused sentinel.  And the record is the group list documented in
 * docs/ASSETS.md, [u16 group_id][u16 count][u16 member_id x count]: its
 * consumer FLD_BTL_INST_TOOL_DrawTrainerParty takes `count` from +2, picks a random index below
 * it, reads `member_id` from +4 + 2*index, and hands that id to
 * FLD_BTL_INST_TOOL_ReadMonData, the a/2/1/4 record reader immediately above this
 * function.  That is the direct evidence that a/2/1/5's member ids index
 * a/2/1/4, which the previous pass could only infer from the id range.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLD_BTL_INST_TOOL_LoadTrainerGroup.c \
 *       --func FLD_BTL_INST_TOOL_LoadTrainerGroup --addr 0x0216880C --region ov010 \
 *       --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);

void *FLD_BTL_INST_TOOL_LoadTrainerGroup(u32 group, u32 heap)
{
    return (void *)ARC_UTIL_LoadMember(215, (u16)(group + 1), 0, heap);
}
