/*
 * function: SCRCMD_FLDMMDL_StartPlayerAnimeAndWait
 * address:  0x021B1D20
 * packet:   pkt_ov021_021B1D20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_FLDMMDL_CheckPlayerAnimeDone  0x021B1CFC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Stream;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 VM_GetU16(struct Stream *s);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
extern int FIELD_PLAYER_StepFormChange(u8 *p);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_FLDMMDL_CheckPlayerAnimeDone(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_FLDMMDL_StartPlayerAnimeAndWait(u32 a, u32 b)
{
    u32 *e;
    u32 v;
    void *o;

    e = (u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b));
    v = VM_GetU16((struct Stream *)a);
    o = FIELDMAP_GetFieldPlayer((struct Obj00020 *)e[1]);
    FIELD_PLAYER_StartFormChange(o, v);
    if (FIELD_PLAYER_StepFormChange(o) == 1)
        return 0;
    VM_SetWait((char *)a, (int)SCRCMD_FLDMMDL_CheckPlayerAnimeDone);
    return 1;
}
