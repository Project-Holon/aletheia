/*
 * function: SCRCMD_PROC_GetMonTripleParams
 * address:  0x0215C064
 * packet:   pkt_ov010_0215C064
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   SCRCMD_PROC_GetPartyMemberParam  0x0215B4DC  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   sScrcmdCompareTable     0x02171180  data   ov010  a2
 *   sScrcmdParamLimits     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int SCRCMD_PROC_GetMonTripleParams(void *a0, void *a1)
{
    u16 *o0 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    u16 *o1 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    u16 *o2 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    void *v;

    if (SCRCMD_PROC_GetPartyMember(a1, SCRIPT_WORK_ReadWorkValue(a0, a1), &v) == 1) {
        *o0 = POKE_TOOL_GetPartyValue(v, 0x92, 0);
        *o1 = POKE_TOOL_GetPartyValue(v, 0x93, 0);
        *o2 = POKE_TOOL_GetPartyValue(v, 0x94, 0);
    } else {
        *o0 = 0;
        *o1 = 0;
        *o2 = 0;
    }
    return 0;
}
