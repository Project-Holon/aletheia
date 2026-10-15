/*
 * function: EVENT_FIELD_PROCLINK_CreateZukanParam
 * address:  0x02160D6C
 * packet:   pkt_ov010_02160D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   func_02012944  0x02012944  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   FIELD_SOUND_SYSTEM_LowerVolume  0x02029DBC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

typedef struct T { void *a; void *b; u8 *c; u16 h; } T;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u8 d_02172978[];
extern void MI_CpuFill8();
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u8 *func_02012944(void *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern void FIELD_SOUND_SYSTEM_LowerVolume(u8 *a, u32 b);

T *EVENT_FIELD_PROCLINK_CreateZukanParam(int *a0, int a1)
{
    T *p;
    void *sys;
    int s;

    p = func_02030734(4, 0x10, 0, (const char *)d_02172978, 0x49b);
    MI_CpuFill8(p, 0, 0x10);
    sys = ICA_ANIME_GetField1C((const struct Ctx *)*(int *)a0[6]);
    p->a = sys;
    p->b = ZUKAN_SAVE_GetFromGameData(sys);
    p->c = func_02012944(p->a);
    s = GAME_DATA_GetBgmInfo(p->a);
    FIELD_SOUND_SYSTEM_LowerVolume((u8 *)s, GAMESYSTEM_GetIssSystem((u32 *)(*(int *)a0[6])));
    if (a1 != -1) {
        p->h = a1;
    } else {
        p->h = 0;
    }
    return p;
}
