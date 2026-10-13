/*
 * function: SCRCMD_PROC_FLD_StoreGameSystemValue
 * address:  0x021B4BEC
 * packet:   pkt_ov021_021B4BEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetCommKind  0x021896F4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int FIELDMAP_GetCommKind(void *p);

int SCRCMD_PROC_FLD_StoreGameSystemValue(u32 a, u32 b)
{
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *o = FIELDMAP_GetCommKind((void *)GAMESYSTEM_GetGameComm(d));
    return 1;
}
