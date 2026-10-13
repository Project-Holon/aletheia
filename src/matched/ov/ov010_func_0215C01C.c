/*
 * function: SCRCMD_PROC_CheckMonParamMatchesTable
 * address:  0x0215C01C
 * packet:   pkt_ov010_0215C01C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
extern int SCRCMD_PROC_GetPartyMemberParam(void *a0, void *a1, void *a2);
extern u16 sScrcmdCompareTable[];

int SCRCMD_PROC_CheckMonParamMatchesTable(void *a0, void *a1)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    int k = SCRIPT_WORK_ReadWorkValue(a0, a1);
    int j = SCRIPT_WORK_ReadWorkValue(a0, a1);
    u16 t = SCRCMD_PROC_GetPartyMemberParam(a1, (void *)k, (void *)0x95);

    if (t == sScrcmdCompareTable[j]) {
        *out = 1;
    } else {
        *out = 0;
    }
    return 0;
}
