/*
 * function: SCRCMD_StartFld3dCiByVar
 * address:  0x021C8170
 * packet:   pkt_ov021_021C8170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLD3D_CI_StartPartyMemberSequence  0x021C1D68  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetFld3dCi(unsigned char *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int FLD3D_CI_StartPartyMemberSequence(int a, int b, int c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_StartFld3dCiByVar(int a, int b)
{
    void *r7;
    int r5, v;
    void *r6;
    void *r4;

    r6 = SCRCMD_WORK_GetGameSystem((void *)b);
    r7 = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(r6));
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = SCRCMD_WORK_GetScriptWork((void *)b);
    v = FLD3D_CI_StartPartyMemberSequence((int)r6, (int)r7, (unsigned char)r5);
    if (v) {
        SCRIPT_SYS_CallEvent(r4, (void *)v);
    }
    return 1;
}
