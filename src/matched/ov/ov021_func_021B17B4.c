/*
 * function: SCRCMD_FLDMMDL_GetPlayerGridPos
 * address:  0x021B17B4
 * packet:   pkt_ov021_021B17B4
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
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */

typedef signed short s16;

void *SCRCMD_WORK_GetScriptWork(void *p);
int SCRIPT_WORK_ResetFieldParam(int a0);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
void *FIELD_PLAYER_GetMmdl(unsigned char *p);
s16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
int FLDMMDL_GetGridNowX(void *p);
int FLDMMDL_GetGridNowZ(void *p);

int SCRCMD_FLDMMDL_GetPlayerGridPos(int a, int b)
{
    void *r5;
    s16 *r6;
    s16 *r4;

    r5 = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)(((unsigned char **)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1])));
    r6 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *r6 = FLDMMDL_GetGridNowX(r5);
    *r4 = FLDMMDL_GetGridNowZ(r5);
    return 0;
}
