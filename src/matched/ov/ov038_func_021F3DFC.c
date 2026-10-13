/*
 * function: FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor
 * address:  0x021F3DFC
 * packet:   pkt_ov038_021F3DFC
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     same enum-k spelling as ov038_func_021F3F40 (k = (u8)(k + 1)
 *           on an enum local, int fourth parameter on the 0x021BE6xx calls).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb  ov021
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj00881.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K_0 } KType;

typedef struct {
    int x;
    int y;
    int z;
} V3;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(int p, int i, int j, int k, int flag);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void GFL_USE_StopAllSe(void);
extern int FLDMMDL_ACMD_ListCheckEnd(u32 a);
extern void FLDMMDL_ACMD_ListDelete(void *a);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);

int FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    int done;
    int d;
    V3 v;

    sys = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)a0));
    h = FIELDMAP_GetExpObj(sys);
    s = (u8 *)FIELDMAP_GetCommonWork(sys, 1);
    q = FIELDMAP_GetFieldPlayer(sys);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    switch (*a1) {
    case 0:
        GFL_USE_StopAllSe();
        *a1 = *a1 + 1;
    case 1:
        if (((struct Obj00881 *)s)->f14 != 0) {
            if (FLDMMDL_ACMD_ListCheckEnd(((struct Obj00881 *)s)->f14) == 1) {
                FLDMMDL_ACMD_ListDelete((void *)(((struct Obj00881 *)s)->f14));
                ((struct Obj00881 *)s)->f14 = 0;
                s[5] = 0;
                *a1 = *a1 + 1;
            }
        } else {
            s[5] = 0;
            *a1 = *a1 + 1;
        }
        if (*a1 == 2)
            ((struct Obj00881 *)s)->f20 = 0;
        break;
    case 2:
        FIELD_PLAYER_GetPos(q, (struct VecFx32 *)&v);
        done = 0;
        s[5]++;
        if (s[6] == 0) {
            v.z += s[5] << 12;
            if (v.z >= ((struct Obj00881 *)s)->f10) {
                v.z = ((struct Obj00881 *)s)->f10;
                done = 1;
            }
            d = (((struct Obj00881 *)s)->f10 - v.z) / 2;
        } else {
            v.z += -s[5] << 12;
            if (v.z <= ((struct Obj00881 *)s)->f10) {
                v.z = ((struct Obj00881 *)s)->f10;
                done = 1;
            }
            d = (v.z - ((struct Obj00881 *)s)->f10) / 2;
        }
        if (((struct Obj00881 *)s)->f20 == 0 && d != 0) {
            GFL_USE_PlaySeDefaultVolume(0x6C4);
            ((struct Obj00881 *)s)->f20 = 1;
        }
        FLD_EXP_OBJ_SetAnimeFrame(h, 0, 0x22, k, d);
        FIELD_PLAYER_SetPos(q, &v);
        if (done) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, 0x22, k, 0);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, 0x22, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
