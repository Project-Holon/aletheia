/*
 * function: SCRCMD_PROC_FLD_CallSubProcWithFlag
 * address:  0x021B4F1C
 * packet:   pkt_ov021_021B4F1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090D8  0x020090D8  thumb
 *   FLD_BTL_INST_TOOL_CreateCommResetEvent  0x02168BBC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
struct Big;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090D8(struct Sub020090B0Obj *obj, u8 value);
extern void *FLD_BTL_INST_TOOL_CreateCommResetEvent(void *a, void *b);

int SCRCMD_PROC_FLD_CallSubProcWithFlag(u32 a, u32 b)
{
    u32 r7;
    u32 r5;
    void *r6;
    void *r4;

    r7 = (u32)func_02009210(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData((void *)b)));
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r6 = SCRCMD_WORK_GetScriptWork((void *)b);
    r4 = SCRCMD_WORK_GetGameSystem((void *)b);
    func_020090D8((struct Sub020090B0Obj *)r7, 1);
    SCRIPT_SYS_CallEvent(r6, FLD_BTL_INST_TOOL_CreateCommResetEvent(r4, (void *)r5));
    return 1;
}
