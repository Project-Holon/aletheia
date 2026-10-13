/*
 * function: GIMMICK64_PlayerEffectEvent
 * address:  0x021F384C
 * packet:   pkt_ov064_021F384C
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_020061E4  0x020061E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FLD_EXP_OBJ_GetAnimeFrame(int a, int b, int c, int d);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
extern void GFL_USE_StopAllSe(void);
extern void func_020061E4(u32 a);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int GIMMICK64_PlayerEffectEvent(void *task, int *st)
{
    void *sys;
    int s;
    int *w;
    int v;
    int lim;

    sys = GAMESYSTEM_GetFieldMap(func_020124E4(task));
    s = FIELDMAP_GetExpObj(sys);
    w = FIELDMAP_GetCommonWork((char *)sys, 1);
    v = FLD_EXP_OBJ_GetAnimeFrame(s, 0, 0, 0);
    lim = FLD_EXP_OBJ_GetAnimeLastFrame((u32)FLD_EXP_OBJ_GetAnime((char *)s, 0, 0, 0));
    if (v >= 0 && w[2] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7D0);
        w[2] = 1;
    } else if (v >= 0x83000 && w[3] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7CB);
        w[3] = 1;
    } else if (v >= 0x6C000 && w[4] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7CC);
        w[4] = 1;
    } else if (v >= 0xFA000 && w[5] == 0) {
        GFL_USE_StopAllSe();
        func_020061E4(0x7F2);
        w[5] = 1;
    }
    switch (*st) {
    case 0:
        if (v == 0x65000) {
            FADE_Start(w[0], 0, 0x10, 0);
            w[1] = 15;
            (*st)++;
        }
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            if (w[1] <= 0) {
                FADE_Start(w[0], 0x10, 0, 0);
                (*st)++;
            } else {
                w[1]--;
            }
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            (*st)++;
        }
        break;
    }
    return v >= lim;
}
