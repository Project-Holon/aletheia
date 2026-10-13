/*
 * function: FIELD_FK_DEMO_EventMain
 * address:  0x021F3734
 * packet:   pkt_ov056_021F3734
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five-step init/run/teardown state machine for the ov056 work block.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   FIELD_SUBPROC_GetWork  0x021BBA6C  thumb  ov021
 *   FIELD_SUBPROC_End  0x021BBA1C  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   FIELD_FK_DEMO_InitModel  0x021F3B10  thumb  ov056
 *   FIELD_FK_DEMO_InitCamera  0x021F392C  thumb  ov056
 *   FIELD_FK_DEMO_CreateSoundAnime  0x021F3D60  thumb  ov056
 *   FIELD_FK_DEMO_InitBuildAnime  0x021F3890  thumb  ov056
 *   FIELD_FK_DEMO_CreateModelObject  0x021F3BF0  thumb  ov056
 *   FIELD_FK_DEMO_SetPlayerHidden  0x021F3CC4  thumb  ov056
 *   FIELD_FK_DEMO_StartBuildAnime  0x021F3904  thumb  ov056
 *   FIELD_FK_DEMO_StepCamera  0x021F3A78  thumb  ov056
 *   FIELD_FK_DEMO_StepModel  0x021F3C84  thumb  ov056
 *   FIELD_FK_DEMO_StepSoundAnime  0x021F3DB8  thumb  ov056
 *   FIELD_FK_DEMO_IsBuildAnimeDone  0x021F3918  thumb  ov056
 *   FIELD_FK_DEMO_DeleteModel  0x021F3C4C  thumb  ov056
 *   FIELD_FK_DEMO_DeleteSoundAnime  0x021F3D9C  thumb  ov056
 *   FIELD_FK_DEMO_ExitCamera  0x021F3A14  thumb  ov056
 *   FIELD_FK_DEMO_DeleteBuildAnime  0x021F38D4  thumb  ov056
 *   gFkDemoDrawTemplate     0x021F42C0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct Work {
    int f0;
    int f4;
    int idx;
    u8 cam[0x30];
    u8 obj[0x80];
    u8 f_bc[0xc];
    u8 f_c8[4];
    u32 task;
    void *fd0;
} Work;

typedef unsigned short u16;
struct Ctx;
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int *FIELD_SUBPROC_Start(int a, int *d, const int *c);
extern u32 FIELD_SUBPROC_GetWork(const void *p);
extern void FIELD_SUBPROC_End(int *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
struct Obj;
extern void FIELD_FK_DEMO_InitModel(struct Obj *o, void *a1, int a2, int a3, int idx);
extern void FIELD_FK_DEMO_InitCamera(struct Obj *o, int a1, int heap, int idx);
extern void FIELD_FK_DEMO_CreateSoundAnime(void *o, int idx, int heap);
extern void FIELD_FK_DEMO_InitBuildAnime(u32 *out, int a, int idx);
extern void FIELD_FK_DEMO_CreateModelObject(u32 *p);
extern void FIELD_FK_DEMO_SetPlayerHidden(u8 *p, int flag);
extern void FIELD_FK_DEMO_StartBuildAnime(unsigned char **p);
extern int FIELD_FK_DEMO_StepCamera(u8 *p);
extern int FIELD_FK_DEMO_StepModel(u32 *p);
extern int FIELD_FK_DEMO_StepSoundAnime(int **pp);
extern int FIELD_FK_DEMO_IsBuildAnimeDone(void **p);
extern void FIELD_FK_DEMO_DeleteModel(u8 *p);
extern void FIELD_FK_DEMO_DeleteSoundAnime(void *o);
extern void FIELD_FK_DEMO_ExitCamera(u8 *p);
extern void FIELD_FK_DEMO_DeleteBuildAnime(unsigned char *p);

extern const u8 gFkDemoDrawTemplate[];

int FIELD_FK_DEMO_EventMain(void *a0, int *state, Work *p)
{
    int heap;
    int h;
    int a;
    int b;
    int c;

    heap = FIELDMAP_GetHeapId((u8 *)p->f0);
    switch (*state) {
    case 0:
        h = (int)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData((const struct Ctx *)p->f4));
        FIELD_FK_DEMO_InitModel((struct Obj *)p->obj, FIELDMAP_GetFieldPlayer((void *)p->f0), h, heap, p->idx);
        (*state)++;
        break;
    case 1:
        FIELD_CAMERA_EndDelay(FIELDMAP_GetCamera((void *)p->f0));
        (*state)++;
        break;
    case 2:
        h = (int)FIELDMAP_GetCamera((void *)p->f0);
        if (FIELD_CAMERA_IsDelayEnabled((u8 *)h) != 0) {
            break;
        }
        FIELD_FK_DEMO_InitCamera((struct Obj *)p->cam, h, heap, p->idx);
        FIELD_FK_DEMO_CreateSoundAnime(p->f_c8, p->idx, heap);
        FIELD_FK_DEMO_InitBuildAnime((u32 *)p->f_bc, FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((u8 *)p->f0)), p->idx);
        FIELD_FK_DEMO_CreateModelObject((u32 *)p->obj);
        p->task = (u32)FIELD_SUBPROC_Start(-1, (int *)FIELDMAP_GetMapFunc((u8 *)p->f0), (const int *)gFkDemoDrawTemplate);
        *((void **)FIELD_SUBPROC_GetWork((const void *)p->task)) = p->obj;
        FIELD_FK_DEMO_SetPlayerHidden(p->obj, 1);
        FIELD_FK_DEMO_StartBuildAnime((unsigned char **)p->f_bc);
        (*state)++;
        break;
    case 3:
        a = FIELD_FK_DEMO_StepCamera(p->cam);
        FIELD_FK_DEMO_StepModel((u32 *)p->obj);
        b = FIELD_FK_DEMO_StepSoundAnime((int **)p->f_c8);
        c = FIELD_FK_DEMO_IsBuildAnimeDone((void **)p->f_bc);
        if (a && c && b) {
            (*state)++;
        }
        break;
    case 4:
        FIELD_FK_DEMO_SetPlayerHidden(p->obj, 0);
        FIELD_SUBPROC_End((int *)p->task);
        func_02030EAC(p->fd0);
        FIELD_FK_DEMO_DeleteModel(p->obj);
        FIELD_FK_DEMO_DeleteSoundAnime(p->f_c8);
        FIELD_FK_DEMO_ExitCamera(p->cam);
        FIELD_FK_DEMO_DeleteBuildAnime(p->f_bc);
        return 1;
    }
    return 0;
}
