/*
 * function: SHINKA_DEMO_VIEW_CreateModels
 * address:  0x02206108
 * packet:   pkt_02206108
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_VIEW_GetModelOffset 0x022060C8 thumb ov195
 *   SHINKA_DEMO_VIEW_UpdateModelOffsets 0x02206274 thumb ov195
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *
 * mwccarm calls the add helper (0x0209C95C) _fadd and the subtract helper
 * (0x0209CB8C) _fsub, as layout/runtime_arm9.txt now does (swapped there
 * until 2026-09-28).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Owner {
    u8 pad00[4];
    void *res0;
    u32 f08;
    u8 pad0c[4];
    void *res1;
    u8 pad14[0x44 - 0x14];
    float scale;
    u8 pad48[4];
    void *sys;
    void *obj[2];
} Owner;

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

extern fx32 SHINKA_DEMO_VIEW_GetModelOffset(void *res);
extern void SHINKA_DEMO_VIEW_UpdateModelOffsets(Owner *o);
extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void MCSS_SetShadowVanishFlag(char *p, int v);
extern int MCSS_TOOL_SetAnimeStopCallback(int a0);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetVanishFlag(void *obj);
extern void MCSS_SetAnmStopFlag(void *obj);

void SHINKA_DEMO_VIEW_CreateModels(Owner *o)
{
    u8 i;
    VecFx32 scale;

    for (i = 0; i < 2; i++)
        o->obj[i] = 0;
    scale.x = FX_F32_TO_FX32(o->scale);
    scale.y = FX_F32_TO_FX32(o->scale);
    scale.z = 0x1000;
    if (o->f08 == 0) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                o->obj[i] = MCSS_TOOL_AddPokeMcss(o->sys, o->res0, 0, 0, SHINKA_DEMO_VIEW_GetModelOffset(o->res0), 0);
            else
                o->obj[i] = MCSS_TOOL_AddPokeMcss(o->sys, o->res1, 0, 0, SHINKA_DEMO_VIEW_GetModelOffset(o->res1), 0);
            MCSS_SetShadowVanishFlag(o->obj[i], 1);
            MCSS_TOOL_SetAnimeStopCallback((int)o->obj[i]);
            MCSS_SetScale(o->obj[i], (u32 *)(&scale));
            if (i != 0) {
                MCSS_SetVanishFlag(o->obj[i]);
                MCSS_SetAnmStopFlag(o->obj[i]);
            }
        }
    } else {
        o->obj[1] = MCSS_TOOL_AddPokeMcss(o->sys, o->res0, 0, 0, SHINKA_DEMO_VIEW_GetModelOffset(o->res0), 0);
        MCSS_SetShadowVanishFlag(o->obj[1], 1);
        MCSS_TOOL_SetAnimeStopCallback((int)o->obj[1]);
        MCSS_SetScale(o->obj[1], (u32 *)(&scale));
    }
    SHINKA_DEMO_VIEW_UpdateModelOffsets(o);
}
