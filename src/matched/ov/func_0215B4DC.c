/*
 * function: SCRCMD_PROC_GetPartyMemberParam
 * address:  0x0215B4DC
 * packet:   pkt_0215B4DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unpacks a record into a local and, when the overlay call says it took,
 * forwards the record and the third argument to the arm9 side.
 *
 * symbols:
 *   SCRCMD_PROC_GetPartyMember   0x0215B4AC  thumb  ov010
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int SCRCMD_PROC_GetPartyMemberParam(void *a0, void *a1, void *a2)
{
    int v;

    if (SCRCMD_PROC_GetPartyMember(a0, (u32)a1, (void **)(&v)) == 1)
        return POKE_TOOL_GetPartyValue((void *)v, (u32)a2, 0);

    return 0;
}

