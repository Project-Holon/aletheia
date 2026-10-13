/*
 * function: SCRCMD_StartFld3dCi
 * address:  0x021C812C
 * packet:   pkt_ov021_021C812C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLD3D_CI_StartSequence  0x021C1CB0  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetFld3dCi(unsigned char *p);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int FLD3D_CI_StartSequence(int a, char *b, int c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_StartFld3dCi(int a, int b)
{
    void *r7;
    int r4, v;
    void *r5;
    void *r6;

    r5 = SCRCMD_WORK_GetGameSystem((void *)b);
    r7 = FIELDMAP_GetFld3dCi(GAMESYSTEM_GetFieldMap(r5));
    r4 = VM_GetU16((struct Stream *)a);
    r6 = SCRCMD_WORK_GetScriptWork((void *)b);
    v = FLD3D_CI_StartSequence((int)r5, r7, (unsigned char)r4);
    if (v) {
        SCRIPT_SYS_CallEvent(r6, (void *)v);
    }
    return 1;
}
