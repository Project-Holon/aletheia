/*
 * function: POKE_REGULATION_LoadInto
 * address:  0x0201A364
 * packet:   pkt_0201A364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb argument-shuffling tail-call thunk: ARC_TOOL_ReadMember(b, 0x69, a).
 *
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 */

typedef unsigned int   u32;
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

void POKE_REGULATION_LoadInto(int a, unsigned int b)
{
    ARC_TOOL_ReadMember((void *)b, 0x69, a);
}
