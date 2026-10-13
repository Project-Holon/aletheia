/*
 * function: FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor
 * address:  0x021F3B3C
 * packet:   pkt_ov038_021F3B3C
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     enum-k spelling as ov038_func_021F3F40.  Case 1 keeps the pressed
 *           path in the if body (the release path, a task swap to
 *           FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor, is the else) so case 0's two failed tests reuse
 *           its `b` to the shared tail; d = (u32)s[5] >> 1 gives the plain lsrs.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor  0x021F3DFC  thumb  ov038
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb  ov021
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb  ov021
 *   EVENT_FIELD_PROCLINK_CreateObjAnimEvent  0x021618A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   gGimmick38PullAcmdSide1     0x021F45F8  data  a4
 *   gGimmick38ReleaseAcmdSide1     0x021F4600  data  a4
 *   gGimmick38ReleaseAcmdSide0     0x021F4608  data  a4
 *   gGimmick38PullAcmdSide0     0x021F4620  data  a4
 */
#include "../include/Obj00488.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K_0 } KType;

typedef struct {
    int x;
    int y;
    int z;
} V3;

extern u32 gGimmick38PullAcmdSide1[];
extern u32 gGimmick38ReleaseAcmdSide1[];
extern u32 gGimmick38ReleaseAcmdSide0[];
extern u32 gGimmick38PullAcmdSide0[];

struct Big;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_CheckEndAcmd(void *t);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern V3 *FLD_EXP_OBJ_GetModelStatus(int p, int i, int j);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(int p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern int FLD_EXP_OBJ_GetAnimeFrame(int p, int i, int j, int k);
extern unsigned int KEY_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void GFL_USE_StopAllSe(void);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(void *p, int a1, int a2, int a3);
extern int FLDMMDL_ACMD_ListCheckEnd(u32 a);
extern void FLDMMDL_ACMD_ListDelete(void *a);
extern int FLDMMDL_ACMD_ListCreate(void *t, void *p);
extern int FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor(int a0, int *a1);

int FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor(int a0, int *a1)
{
    void *w;
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    void *e;
    void *t;
    V3 *src;
    int mask;
    int dir;
    u32 d;
    V3 v;

    w = GAME_EVENT_GetGameSystem((struct Obj *)a0);
    sys = GAMESYSTEM_GetFieldMap(w);
    h = FIELDMAP_GetExpObj(sys);
    s = (u8 *)FIELDMAP_GetCommonWork(sys, 1);
    q = FIELDMAP_GetFieldPlayer(sys);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(sys))), 6);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    e = FLD_EXP_OBJ_GetAnime((char *)h, 0, 0x22, k);
    switch (*a1) {
    case 0:
        t = FIELD_PLAYER_GetMmdl((void *)q);
        if (FLDMMDL_CheckEndAcmd(t) != 0 && FLDMMDL_CheckPossibleAcmd((int)t) != 0) {
            ((struct Obj00488 *)s)->f1C = 1;
            FIELD_PLAYER_GetPos(q, (struct VecFx32 *)(s + 8));
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, c, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, 0x22, 0);
            src = FLD_EXP_OBJ_GetModelStatus(h, 0, c);
            *FLD_EXP_OBJ_GetModelStatus(h, 0, 0x22) = *src;
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, 0x22, k, 1);
            FLD_EXP_OBJ_SetAnimeFrame(h, 0, 0x22, k, 0);
            FLD_EXP_OBJ_SetAnimePaused(e, 1);
            ((struct Obj00488 *)s)->f20 = 0;
            *a1 = *a1 + 1;
        }
        break;
    case 1:
        if (s[6] == 0) {
            mask = 0x40;
            dir = -1;
        } else {
            mask = 0x80;
            dir = 1;
        }
        if ((KEY_GetCont() & mask) != 0) {
            s[7]++;
            if (s[7] >= 2) {
                s[7] = 0;
                s[5]++;
                FIELD_PLAYER_GetPos(q, (struct VecFx32 *)&v);
                v.z += dir << 12;
                FIELD_PLAYER_SetPos(q, &v);
                d = (u32)s[5] >> 1;
                if (((struct Obj00488 *)s)->f20 == 0 && d != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x6C2);
                    ((struct Obj00488 *)s)->f20 = 1;
                }
                FLD_EXP_OBJ_SetAnimeFrame(h, 0, 0x22, k, d << 12);
                if (s[5] >= 0x20)
                    *a1 = *a1 + 1;
            }
        } else {
            GAME_EVENT_ChangeEvent((struct S0201235C *)a0, (u32 *)func_020122C0(w, 0, FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor, 0));
            return 0;
        }
        break;
    case 2:
        if (((struct Obj00488 *)s)->f14 != 0) {
            if (FLDMMDL_ACMD_ListCheckEnd(((struct Obj00488 *)s)->f14) == 1) {
                FLDMMDL_ACMD_ListDelete((void *)(((struct Obj00488 *)s)->f14));
                ((struct Obj00488 *)s)->f14 = 0;
                ((struct Obj00488 *)s)->f18 = 1;
                *a1 = *a1 + 1;
            }
        } else {
            ((struct Obj00488 *)s)->f18 = 1;
            *a1 = *a1 + 1;
        }
        if (((struct Obj00488 *)s)->f18 != 0) {
            FLD_EXP_OBJ_SetAnimePaused(e, 0);
            GAME_EVENT_CallEvent((struct Evt *)a0, EVENT_FIELD_PROCLINK_CreateObjAnimEvent(w, (int)sys, 0xff, (int)(s[6] == 0 ? gGimmick38ReleaseAcmdSide0 : gGimmick38ReleaseAcmdSide1)));
            GFL_USE_StopAllSe();
            GFL_USE_PlaySeDefaultVolume(0x6C3);
        }
        break;
    case 3:
        FLD_EXP_OBJ_GetAnimeFrame(h, 0, 0x22, k);
        if (FLD_EXP_OBJ_IsAnimeStopped(e)) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, 0x22, k, 0);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, 0x22, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    if (((struct Obj00488 *)s)->f1C != 0 && ((struct Obj00488 *)s)->f18 == 0) {
        t = FIELD_PLAYER_GetMmdl((void *)q);
        if (((struct Obj00488 *)s)->f14 == 0) {
            ((struct Obj00488 *)s)->f14 = FLDMMDL_ACMD_ListCreate(t, s[6] == 0 ? gGimmick38PullAcmdSide0 : gGimmick38PullAcmdSide1);
        } else if (FLDMMDL_ACMD_ListCheckEnd(((struct Obj00488 *)s)->f14) == 1) {
            FLDMMDL_ACMD_ListDelete((void *)(((struct Obj00488 *)s)->f14));
            ((struct Obj00488 *)s)->f14 = 0;
        }
    }
    return 0;
}
