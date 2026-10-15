/*
 * function: GURU2_MAIN_ProcExit
 * address: 0x021DE960
 * packet: pkt_ov137_021DE960
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P14 C10: EXACT first compile. Callees all void except UI_ClearFlags39Global (int, result unused); no older draft existed.
 * symbols:
 * PRINTSYS_QUE_Clear 0x0201C6EC thumb
 * PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 * TIME_ICON_Delete 0x0202F038 thumb
 * TCB_Noop 0x02030DA4 arm
 * func_020307B0 0x020307B0 arm
 * G3D_UTIL_Delete 0x02047E54 arm
 * G3D_SYSTEM_Exit 0x02046788 arm
 * func_02030EAC 0x02030EAC arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * func_020315D4 0x020315D4 arm
 * GFL_HEAP_DeleteChecked 0x020306F0 arm
 * UI_ClearFlags39Global 0x020351A0 arm
 * GURU2_MAIN_DeleteBounceEffectTask 0x021E0E1C thumb ov137
 * GURU2_MAIN_DeleteSettleEffectTask 0x021E0F54 thumb ov137
 * GURU2_MAIN_DeleteWobbleEffectTask 0x021E1080 thumb ov137
 * GURU2_MAIN_DeleteEntranceEffectTask 0x021E11E4 thumb ov137
 * GURU2_MAIN_DeleteScreenFlashTask 0x021E13F0 thumb ov137
 * GURU2_MAIN_DeletePulseEffectTask 0x021E14BC thumb ov137
 * GURU2_MAIN_RemoveBackgroundUnit 0x021E0678 thumb ov137
 * GURU2_MAIN_RemoveCenterUnit 0x021E0554 thumb ov137
 * GURU2_MAIN_RemovePlayerUnits 0x021E073C thumb ov137
 * GURU2_MAIN_TeardownAll 0x021DF83C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
struct Proc;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void TIME_ICON_Delete(u8 *);
extern void TCB_Noop(void *);
extern u32 func_020307B0(void *p);
struct Node;
struct Rec;
extern void G3D_UTIL_Delete(struct Rec *p);
extern void G3D_SYSTEM_Exit(void);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(u32);
extern int UI_ClearFlags39Global(u32);
extern void GURU2_MAIN_DeleteBounceEffectTask(u8 *);
extern void GURU2_MAIN_DeleteSettleEffectTask(u8 *);
extern void GURU2_MAIN_DeleteWobbleEffectTask(u8 *);
extern void GURU2_MAIN_DeleteEntranceEffectTask(u8 *);
extern void GURU2_MAIN_DeleteScreenFlashTask(u8 *);
extern void GURU2_MAIN_DeletePulseEffectTask(u8 *);
extern void GURU2_MAIN_RemoveBackgroundUnit(char *);
extern void GURU2_MAIN_RemoveCenterUnit(u8 *);
extern void GURU2_MAIN_RemovePlayerUnits(char *);
extern void GURU2_MAIN_TeardownAll(char *);
int GURU2_MAIN_ProcExit(struct Proc *a, int b, int c, u8 *p)
{
    PRINTSYS_QUE_Clear(*(struct PrintSys **)(p + 0xD38));
    PRINTSYS_QUE_Delete(*(struct PrintSys **)(p + 0xD38));
    if (*(u8 **)(p + 0xDA8) != 0) TIME_ICON_Delete(*(u8 **)(p + 0xDA8));
    GURU2_MAIN_DeleteBounceEffectTask(p);
    GURU2_MAIN_DeleteSettleEffectTask(p);
    GURU2_MAIN_DeleteWobbleEffectTask(p);
    GURU2_MAIN_DeleteEntranceEffectTask(p);
    GURU2_MAIN_DeleteScreenFlashTask(p);
    GURU2_MAIN_DeletePulseEffectTask(p);
    TCB_Noop(*(void **)(p + 0xD98));
    func_020307B0(*(void **)(p + 0xD94));
    GURU2_MAIN_RemoveBackgroundUnit((char *)p);
    GURU2_MAIN_RemoveCenterUnit(p);
    GURU2_MAIN_RemovePlayerUnits((char *)p);
    G3D_UTIL_Delete(*(void **)(p + 0xAF4));
    G3D_SYSTEM_Exit();
    GURU2_MAIN_TeardownAll((char *)p);
    func_02030EAC(*(void **)(p + 0xD9C));
    ARC_TOOL_DeleteHandle(*(void **)(p + 0xD58));
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x72);
    UI_ClearFlags39Global(8);
    return 1;
}
