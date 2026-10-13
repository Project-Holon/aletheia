/*
 * function: FLD_FACEUP_ScrCmdPrepareField
 * address:  0x02164978
 * packet:   pkt_02164978
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FLD_FACEUP_ResumeLipSync  0x021F558C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FLD_FACEUP_ResumeLipSync();

int FLD_FACEUP_ScrCmdPrepareField(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_02164982:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_02164988:
    v2 = GAMESYSTEM_GetFieldMap(v1);
loc_0216498C:
    a0 = FLD_FACEUP_ResumeLipSync(v2);
loc_02164990:
a0 = 0;
    return a0;}
