/*
 * function: SCRCMD_FLDMMDL_GetPlayerForm
 * address:  0x021B1F60
 * packet:   pkt_ov021_021B1F60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Each arm stores its constant through o itself; cross-jumping merges the
 * stores, leaving cases 2 and 3 branching onto case 1's branch.
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned short u16;
typedef unsigned int u32;



extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef unsigned char  u8;
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);

int SCRCMD_FLDMMDL_GetPlayerForm(u32 a, u32 b)
{
    void *x = FIELDMAP_GetFieldPlayer((struct Obj00020 *)((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1]);
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    switch (FIELD_PLAYER_GetFormCode(x)) {
    case 0:
        *o = 0;
        break;
    case 1:
        *o = 1;
        break;
    case 2:
        *o = 2;
        break;
    case 3:
        *o = 3;
        break;
    default:
        *o = 0;
        break;
    }
    return 0;
}
