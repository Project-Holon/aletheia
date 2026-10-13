/*
 * function: SCRCMD_PROC_SetRotomFormMove
 * address:  0x0215BF7C
 * packet:   pkt_ov010_0215BF7C
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_SetRotomFormMove  0x02017A20  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct BigObj;
struct Blk37;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_SetRotomFormMove(void *p, u32 idx, u32 val);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);

int SCRCMD_PROC_SetRotomFormMove(void *a0, void *a1)
{
    void *k = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    void *v = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    void *w = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    void *h;
    void *e;

    SCRCMD_WORK_GetScriptWork(a1);
    h = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(a1));
    e = POKEPARTY_GetMember(GAME_DATA_GetMyParty(h), (u32)k);
    POKE_TOOL_SetRotomFormMove(e, (u32)w, (u32)v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}
