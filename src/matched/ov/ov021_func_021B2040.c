/*
 * function: SCRCMD_FLDMMDL_GetPlayerAnimeState
 * address:  0x021B2040
 * packet:   pkt_ov021_021B2040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned char  u8;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int FIELD_PLAYER_CheckFormModel(u8 *p);

int SCRCMD_FLDMMDL_GetPlayerAnimeState(u32 a, u32 b)
{
    void *x = FIELDMAP_GetFieldPlayer((struct Obj00020 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1]));
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *o = FIELD_PLAYER_CheckFormModel(x);
    return 0;
}
