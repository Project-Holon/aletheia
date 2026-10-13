/*
 * function: FIELD_SOUND_SYSTEM_StartFadeInTask
 * address:  0x020294C0
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
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_StartFadeInTask.c \\
 *       --func FIELD_SOUND_SYSTEM_StartFadeInTask --addr 0x020294C0 --thumb --cc 1.1p1
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_FadeInTask  0x02029488  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 */
#include "../include/Obj11298.h"

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
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern int FIELD_SOUND_SYSTEM_FadeInTask(u32 unused, u32 *state, u8 *cfg);

u8 *FIELD_SOUND_SYSTEM_StartFadeInTask(u8 *p, u32 a)
{
    u32 r7 = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)FIELD_SOUND_SYSTEM_FadeInTask), 0x10);
    u8 *r4 = func_020124E8((struct Obj *)r6);

    ((struct Obj11298 *)r4)->f4 = GAME_DATA_GetBgmInfo((const struct BigObj *)r7);
    ((struct Obj11298 *)r4)->fC = (u16)a;
    return r6;
}
