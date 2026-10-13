/*
 * function: SCRCMD_StartFld3dCiByTable
 * address:  0x021C81F8
 * packet:   pkt_ov021_021C81F8
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
 *   FLD3D_CI_StartSequence  0x021C1CB0  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   gFld3dCiKeyTable     0x021DAAE0  data  a2
 *   gFld3dCiIdTable     0x021DAAE2  data  a2
 */

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetFld3dCi(unsigned char *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int FLD3D_CI_StartSequence(int a, char *b, int c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern unsigned short gFld3dCiKeyTable[];
extern unsigned short gFld3dCiIdTable[];

int SCRCMD_StartFld3dCiByTable(int a, int b)
{
    void *sp4;
    void *sp0;
    int v, found, i;
    void *r5;
    unsigned short r4;

    sp4 = SCRCMD_WORK_GetGameSystem((void *)b);
    sp0 = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(sp4));
    v = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    found = 0;
    for (i = 0; i < 17; i++) {
        if (v == gFld3dCiKeyTable[i * 2]) {
            found = 1;
            r4 = gFld3dCiIdTable[i * 2];
            break;
        }
    }
    if (found) {
        r5 = SCRCMD_WORK_GetScriptWork((void *)b);
        v = FLD3D_CI_StartSequence((int)sp4, sp0, (unsigned char)r4);
        if (v) {
            SCRIPT_SYS_CallEvent(r5, (void *)v);
        }
    }
    return 1;
}
