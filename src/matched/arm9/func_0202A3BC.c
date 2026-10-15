/*
 * function: TPOKE_DATA_ReadParty
 * address:  0x0202A3BC
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *
 */
typedef unsigned int u32;

extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

void TPOKE_DATA_ReadParty(void *a0, void *a1)
{
    ARC_TOOL_ReadMember(a1, 0x5d, (u32)a0);
}
