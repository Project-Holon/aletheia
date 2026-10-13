/*
 * function: SCRCMD_MUSICAL_WaitCommIdle
 * address:  0x0215E130
 * packet:   pkt_ov010_0215E130
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
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_IsAborted  0x02156BCC  thumb  ov010
 *   func_02026454  0x02026454  thumb
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *p);
extern void *SCRCMD_WORK_GetGameData(void *p);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int GAME_DATA_GetExternalWork(char *base);
extern void MUSICAL_EVENT_CheckNetError(void *p);
extern unsigned int MUSICAL_EVENT_IsAborted(void *p);
typedef unsigned int   u32;
extern u32 func_02026454(void *obj);

int SCRCMD_MUSICAL_WaitCommIdle(void *a, void *b)
{
    void *t;
    void *s;
    int *w;

    SCRCMD_WORK_GetScriptWork(b);
    t = SCRCMD_WORK_GetGameSystem(b);
    s = SCRCMD_WORK_GetGameData(b);
    t = (void *)GAMESYSTEM_GetGameComm(t);
    w = (int *)GAME_DATA_GetExternalWork(s);
    if (*w != 0) {
        MUSICAL_EVENT_CheckNetError((void *)(*w));
        if (MUSICAL_EVENT_IsAborted((void *)(*w)) == 1) {
            return 1;
        }
    }
    if (func_02026454(t) == 0) {
        return 1;
    }
    return 0;
}
