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
 * 2026-10-05 (wave D5 lane 02): arm9 func_02035010/func_02035040 and their setters func_02035004/func_02035034 are now filed in src/matched/arm9/; remaining unresolved sites should clear once labelled.
 * 2026-10-04 (wD2 lane 09): bytes are identical; only +002A and +0032 are open:
 * calls to unlabelled arm9 02035010 and 02035040 (no witness).
 * A separate arm9 label lane must label them; nothing left in this source.
 *
 * Blocked: func_02035010 and func_02035040 (arm, unlabelled arm9 leaves, EL_GetGlobalAdr
 * wrappers per sdk_class.json) have no witness outside this range; both are the integrator's.
 * Byte-correct otherwise.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetVisitProgress  0x021585E0  thumb
 *   INTRUDE_COMM_SetCompleted  0x02158614  thumb
 *   C_GEAR_DeleteFadeFx  0x021F2E5C  thumb  ov029
 *   func_02035010  0x02035010  arm
 *   func_02035040  0x02035040  arm
 *   GFL_NET_RestartNoTimeout  0x0203D8AC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   C_GEAR_FreeGraphics  0x021F1F24  thumb  ov029
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Node;
struct PalAnmSlot;
struct SoundSys;
extern u32 func_02012138(const struct Ctx *p);
extern int INTRUDE_COMM_GetVisitProgress(int r);
extern void INTRUDE_COMM_SetCompleted(int a);
extern void C_GEAR_DeleteFadeFx(char *a);
extern void func_02035010(u32 a, u32 b);
extern void func_02035040(u32 a, u32 b);
extern void GFL_NET_RestartNoTimeout(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_02030DA4(int a);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern void ARC_TOOL_DeleteHandle(int a);
extern void C_GEAR_FreeGraphics(char *p);
extern void func_02082BCC(char *p, int a, int b);

void C_GEAR_Cleanup(char *p)
{
    int r = func_02012138((const struct Ctx *)(*(int *)(p + 0x1c)));

    if (r != 0) {
        if (INTRUDE_COMM_GetVisitProgress(r) == 2)
            INTRUDE_COMM_SetCompleted(r);
    }
    C_GEAR_DeleteFadeFx(p + 0x21c);
    func_02035010(0, 0);
    func_02035040(0, 0);
    GFL_NET_RestartNoTimeout();
    GFL_NET_RestartWithDefaultTimeout(0, *(unsigned short *)(p + 0xc));
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1);
    PALANM_Delete((void *)(*(int *)(p + 0x210)));
    func_02030DA4(*(int *)(p + 0x204));
    func_020307B0((void *)(*(int *)(p + 0x20c)));
    func_02030EAC((struct Node *)(*(int *)(p + 0x208)));
    if (*(int *)(p + 0x218) != 5) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4((const struct Ctx *)(*(int *)(p + 0x1c)))));
    }
    ARC_TOOL_DeleteHandle(*(int *)(p + 0x24));
    C_GEAR_FreeGraphics(p);
    *(volatile unsigned short *)0x04001050 = 0;
    func_02082BCC(p, 0, 0x468);
}
