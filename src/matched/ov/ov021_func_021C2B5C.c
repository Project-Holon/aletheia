/*
 * function: FLD3D_CI_FadeInTask
 * address:  0x021C2B5C
 * packet:   pkt_ov021_021C2B5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fade-out state step: start the fade, then wait for it to finish.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 *   FADE_Start  0x0204E720  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb  arm9
 */

typedef unsigned int u32;

struct Obj;
struct Ctx;

extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int FLD3D_CI_FadeInTask(void *t, int *st)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(t));
    switch (*st) {
    case 0:
        FADE_Start(4, 0x10, 0, -1);
        (*st)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
