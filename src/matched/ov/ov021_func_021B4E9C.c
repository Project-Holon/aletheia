/*
 * function: SCRCMD_PROC_FLD_StartNameInMode6
 * address:  0x021B4E9C
 * packet:   pkt_ov021_021B4E9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_NAMEIN_Create  0x021CD2A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 EVENT_NAMEIN_Create(u32 a, u32 b, u32 x, u32 c, u32 d);

int SCRCMD_PROC_FLD_StartNameInMode6(u32 a, u32 b)
{
    void *r6;
    void *r7;
    void *z;

    r6 = SCRCMD_WORK_GetScriptWork((void *)b);
    r7 = SCRCMD_WORK_GetGameSystem((void *)b);
    z = GAMESYSTEM_GetFieldMap((void *)r7);
    SCRIPT_SYS_CallEvent(r6, (void *)EVENT_NAMEIN_Create((u32)r7, (u32)z, 0, 6, (u32)SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b)));
    return 1;
}
