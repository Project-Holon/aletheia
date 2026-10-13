/*
 * function: FIELD_SOUND_SYSTEM_StartFadeOutTask
 * address:  0x0202952C
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker FIELD_SOUND_SYSTEM_StartFadeInTask.c is now a manifest entry (matched class)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_StartFadeOutTask.c \\
 *       --func FIELD_SOUND_SYSTEM_StartFadeOutTask --addr 0x0202952C --thumb --cc 1.1p1
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_FadeOutTask  0x020294F4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 */
#include "../include/Obj11301.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32  GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern int FIELD_SOUND_SYSTEM_FadeOutTask(u32 unused, u32 *state, u8 *cfg);

u8 *FIELD_SOUND_SYSTEM_StartFadeOutTask(u8 *p, u32 a)
{
    u32 r7 = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)FIELD_SOUND_SYSTEM_FadeOutTask), 0x10);
    u8 *r4 = func_020124E8((struct Obj *)r6);

    ((struct Obj11301 *)r4)->f4 = GAME_DATA_GetBgmInfo((const struct BigObj *)r7);
    ((struct Obj11301 *)r4)->fE = (u16)a;
    return r6;
}
