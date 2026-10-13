/*
 * function: SCRCMD_PROC_SetMonParamChecked
 * address:  0x0215C0D0
 * packet:   pkt_ov010_0215C0D0
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

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_RecalcParam(void *);
extern struct { u16 a; u16 b; } sScrcmdParamLimits[6];

int SCRCMD_PROC_SetMonParamChecked(void *a0, void *a1)
{
    int k = SCRIPT_WORK_ReadWorkValue(a0, a1);
    u32 x = SCRIPT_WORK_ReadWorkValue(a0, a1);
    u32 y = SCRIPT_WORK_ReadWorkValue(a0, a1);
    void *v;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (x == sScrcmdParamLimits[i].a) {
            if (y <= sScrcmdParamLimits[i].b && SCRCMD_PROC_GetPartyMember(a1, k, &v) == 1) {
                POKE_TOOL_SetPartyValue(v, x, y);
                POKE_TOOL_RecalcParam(v);
            }
            return 0;
        }
    }
    return 0;
}
