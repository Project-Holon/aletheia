/*
 * function: C_GEAR_Cleanup
 * address:  0x021F26E0
 * packet:   pkt_ov029_021F26E0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wave D5 lane 02): arm9 UI_SetSleepHookGlobal/UI_SetWakeHookGlobal and their setters UI_SetSleepHook/UI_SetWakeHook are now filed in src/matched/arm9/; remaining unresolved sites should clear once labelled.
 * 2026-10-04 (wD2 lane 09): bytes are identical; only +002A and +0032 are open:
 * calls to unlabelled arm9 02035010 and 02035040 (no witness).
 * A separate arm9 label lane must label them; nothing left in this source.
 *
 * Blocked: UI_SetSleepHookGlobal and UI_SetWakeHookGlobal (arm, unlabelled arm9 leaves, EL_GetGlobalAdr
 * wrappers per sdk_class.json) have no witness outside this range; both are the integrator's.
 * Byte-correct otherwise.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040.
 *
 * symbols:
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   INTRUDE_COMM_GetVisitProgress  0x021585E0  thumb
 *   INTRUDE_COMM_SetCompleted  0x02158614  thumb
 *   C_GEAR_DeleteFadeFx  0x021F2E5C  thumb  ov029
 *   UI_SetSleepHookGlobal  0x02035010  arm
 *   UI_SetWakeHookGlobal  0x02035040  arm
 *   GFL_NET_RestartNoTimeout  0x0203D8AC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   TCB_Noop  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   C_GEAR_FreeGraphics  0x021F1F24  thumb  ov029
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Node;
struct PalAnmSlot;
struct SoundSys;
extern u32 ICA_ANIME_GetField24(const struct Ctx *p);
extern int INTRUDE_COMM_GetVisitProgress(int r);
extern void INTRUDE_COMM_SetCompleted(int a);
extern void C_GEAR_DeleteFadeFx(char *a);
extern void UI_SetSleepHookGlobal(u32 a, u32 b);
extern void UI_SetWakeHookGlobal(u32 a, u32 b);
extern void GFL_NET_RestartNoTimeout(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void TCB_Noop(int a);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern void ARC_TOOL_DeleteHandle(int a);
extern void C_GEAR_FreeGraphics(char *p);
extern void MI_CpuFill8(char *p, int a, int b);

void C_GEAR_Cleanup(char *p)
{
    int r = ICA_ANIME_GetField24((const struct Ctx *)(*(int *)(p + 0x1c)));

    if (r != 0) {
        if (INTRUDE_COMM_GetVisitProgress(r) == 2)
            INTRUDE_COMM_SetCompleted(r);
    }
    C_GEAR_DeleteFadeFx(p + 0x21c);
    UI_SetSleepHookGlobal(0, 0);
    UI_SetWakeHookGlobal(0, 0);
    GFL_NET_RestartNoTimeout();
    GFL_NET_RestartWithDefaultTimeout(0, *(unsigned short *)(p + 0xc));
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1);
    PALANM_Delete((void *)(*(int *)(p + 0x210)));
    TCB_Noop(*(int *)(p + 0x204));
    func_020307B0((void *)(*(int *)(p + 0x20c)));
    func_02030EAC((struct Node *)(*(int *)(p + 0x208)));
    if (*(int *)(p + 0x218) != 5) {
        func_02028A70((struct SoundSys *)GAME_DATA_GetBgmInfo(ICA_ANIME_GetField1C((const struct Ctx *)(*(int *)(p + 0x1c)))));
    }
    ARC_TOOL_DeleteHandle(*(int *)(p + 0x24));
    C_GEAR_FreeGraphics(p);
    *(volatile unsigned short *)0x04001050 = 0;
    MI_CpuFill8(p, 0, 0x468);
}
