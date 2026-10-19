/*
 * function: SCRCMD_PROC_FLD_StartScriptedWildBattle
 * address:  0x021B503C
 * packet:   pkt_ov021_021B503C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELD_ENCOUNT_StartScriptedWild  0x021AA0A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern u32 FIELD_ENCOUNT_StartScriptedWild(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_PROC_FLD_StartScriptedWildBattle(u32 a, u32 b)
{
    void *r4;
    u32 s0;
    u32 r7;
    u32 r5;

    r4 = SCRCMD_WORK_GetScriptWork((void *)b);
    s0 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_WORK_GetGameSystem(r4);
    SCRIPT_SYS_CallEvent(r4, (void *)FIELD_ENCOUNT_StartScriptedWild(FIELDMAP_GetEncount((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)r4))[1])), s0, (u8)r7, r5));
    return 1;
}
