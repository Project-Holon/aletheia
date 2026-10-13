/*
 * function: NAMEIN_SETUP_RunFallEvent
 * address:  0x0216C0E8
 * packet:   pkt_ov010_0216C0E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Eight-state proc of the field event beside NAMEIN_SETUP_RunLandEvent: run the
 * ov021 camera move, animate the actor to the ground, then push the next
 * screens. First draft.
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   ICA_ANIME_CreateFull  0x020114D0  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   NAMEIN_SETUP_StartLandEvent  0x0216C44C  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Pos {
    u32 f00;
    u32 f04;
    u32 f08;
} Pos;

typedef struct Work {
    void *sys;          /* 0x00 */
    void *field;        /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
    u8 pad14[4];
    u8 f18[0x60 - 0x18];/* 0x18 */
    void *f60;          /* 0x60 */
} Work;

extern void FIELD_CAMERA_ANIME_Setup(void *p);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(void *p, void *q);
extern int FIELD_CAMERA_ANIME_Start(u32 a);
extern int FIELD_TASK_MANAGER_IsEmpty(void *p);
extern void FIELD_CAMERA_ANIME_Delete(void *p);
struct Evt;
struct IcaAnime;
struct S0201235C;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *ICA_ANIME_CreateFull(u32 heap, u32 a1, u32 a2);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void func_0200616C(void *arg, int i);
struct Rec12;
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *anim, struct Rec12 *out);
extern int FIELDMAP_GetExpObj(int *p);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *p, int a, int b);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *sys, void *proc, u32 a, u32 b);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *p, void *q, u32 id, Pos *pos, u32 flag);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *NAMEIN_SETUP_StartLandEvent(void *sys, void *field);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int NAMEIN_SETUP_RunFallEvent(void *evt, u32 *state, Work *w)
{
    VecFx32 cur;
    VecFx32 v;
    Pos pos;
    void *sys = w->sys;
    void *field = w->field;
    void *f0c = w->f0c;
    void *q;

    switch (*state) {
    case 0:
        FIELD_CAMERA_ANIME_Setup(w->f60);
        FIELD_CAMERA_ANIME_GetCurrentParam(w->f08, w->f18);
        FIELD_CAMERA_ANIME_Start((u32)w->f60);
        (*state)++;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(f0c) != 0) {
            FIELD_CAMERA_ANIME_Delete(w->f60);
            (*state)++;
        }
        break;
    case 2:
        w->anim = ICA_ANIME_CreateFull(FIELDMAP_GetHeapId(field), 0x9D, 0x18);
        func_0200616C((void *)1953, GFL_USE_GetSeSlot(1953));
        (*state)++;
        break;
    case 3:
        ICA_ANIME_GetTranslate(w->anim, (struct Rec12 *)&cur);
        FLD_EXP_OBJ_GetModelStatus((void *)FIELDMAP_GetExpObj(field), 0, 0)->y = cur.y;
        q = FIELDMAP_GetFieldPlayer(field);
        FIELD_PLAYER_GetPos(q, &v);
        v.y = cur.y;
        FIELD_PLAYER_SetPos(q, &v);
        if (ICA_ANIME_IncFrameLoop(w->anim, 0x1000) != 0) {
            ICA_ANIME_Delete(w->anim);
            (*state)++;
        }
        break;
    case 4:
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeOut(sys, field, 0, 0));
        (*state)++;
        break;
    case 5:
        pos.f00 = 0;
        pos.f04 = 0;
        pos.f08 = 0;
        GAME_EVENT_CallEvent(evt, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(sys, field, 0x8A, &pos, 1));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_ChangeEvent(evt, NAMEIN_SETUP_StartLandEvent(sys, field));
        (*state)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}
