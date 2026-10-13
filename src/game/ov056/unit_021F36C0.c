/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36C8, func_021F36D4, func_021F36E4, func_021F36F0, func_021F3734, func_021F3890, func_021F38D4, func_021F3904, func_021F3918, func_021F392C, func_021F3A14, func_021F3A78, func_021F3AB0, func_021F3B10, func_021F3BF0, func_021F3C4C, func_021F3C84, func_021F3CC4, func_021F3D2C, func_021F3D44, func_021F3D54, func_021F3D60, func_021F3D9C, func_021F3DB8, func_021F3DCC, func_021F3E38, func_021F3E54
 * address:  0x021F36C0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F42B0  0x021F42B0  data
 *   func_02047674  0x02047674  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   d_021F42C0     0x021F42C0  data  a4
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   d_021F4290  0x021F4290  data  ov056  a4
 *   d_021F42D8  0x021F42D8  data  ov056  a4
 *   func_0218C860 0x0218C860 thumb ov021
 *   func_0218C69C 0x0218C69C thumb ov021
 *   func_0218C88C 0x0218C88C thumb ov021
 *   func_0218C8B0 0x0218C8B0 thumb ov021
 *   func_02011510  0x02011510  thumb
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048A24  0x02048A24  arm
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F1B4  0x0218F1B4  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218ED20  0x0218ED20  thumb  ov021
 *   d_021F4338     0x021F4338  data  a4
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ED14  0x0218ED14  thumb  ov021
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_02048AC4  0x02048AC4  arm
 *   func_02011558  0x02011558  thumb
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   func_020115EC  0x020115EC  thumb
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048B0C  0x02048B0C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   d_021F426C     0x021F426C  data  a4
 *   func_020490F4  0x020490F4  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02008550  0x02008550  thumb
 *   func_02046E24  0x02046E24  arm
 *   func_02047180  0x02047180  arm
 *   func_02049238  0x02049238  arm
 *   d_021F4308     0x021F4308  data  a4
 *   d_021F4264     0x021F4264  data  a2
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_02047204  0x02047204  arm
 *   func_021F4040  0x021F4040  thumb  ov056
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_021F42A0     0x021F42A0  data  a4
 *   d_021F43A4     0x021F43A4  data  a4
 *   func_021F408C  0x021F408C  thumb  ov056
 *   func_021F40A0  0x021F40A0  thumb  ov056
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F4278  0x021F4278  data  ov056  a4
 *   d_021F4258  0x021F4258  data  ov056  a4
 *   func_02028B50  0x02028B50  thumb
 *   func_02047A60  0x02047A60  arm
 */
#include "unit_021F36C0_types.h"

extern struct G3dAnmObjHead *func_02047674(struct G3dAnime *anime);
extern struct FieldSubproc *func_021BB990(int overlayId, struct FieldmapFunc *mapFunc, const struct FieldSubprocTemplate *tmpl);
extern FkDemoDrawWork *func_021BBA6C(const struct FieldSubproc *proc);
extern void func_021BBA1C(struct FieldSubproc *proc);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, FkDemoEventFunc func, u32 workSize);
extern FkDemoWork *func_020124E8(struct GameEvent *event);
extern struct Tcb *func_020056A0(FkDemoTcbFunc callback, FkDemoWork *work, u32 priority);
extern void func_02030EAC(struct Tcb *tcb);
extern void func_0218F0A8(struct FieldCamera *camera);
extern u32 func_0218F0E8(struct FieldCamera *camera);
extern struct BuildModelNode *func_0218C7D8(struct BuildModelMan *man, int kind, const VecFx32 *pos);
extern void func_0218C860(struct BuildModelNode *node);
extern void func_0218C69C(struct BuildModelMan *man, struct BuildModelEntry *entry, int slot, int mode);
extern void func_0218C88C(struct BuildModelNode *node, int slot, int mode);
extern int func_0218C8B0(struct BuildModelNode *node, int slot);
extern struct IcaAnime *func_02011510(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum);
extern struct G3dCamera *func_0218EC2C(struct FieldCamera *camera);
extern void func_02048B30(struct G3dCamera *g3dCamera, VecFx32 *out);
extern void func_02048AE8(struct G3dCamera *g3dCamera, VecFx32 *out);
extern void func_02048B0C(struct G3dCamera *g3dCamera, VecFx32 *out);
extern struct G3dCamera *func_02048A24(int projType, s16 fovySin, s16 fovyCos, int aspect, int right, int nearClip, int farClip, int scaleW,
                                       VecFx32 *position, VecFx32 *up, VecFx32 *target, int heapId);
extern u32 func_0218E138(struct FieldCamera *camera);
extern void func_0218E13C(struct FieldCamera *camera, u32 mode);
extern u8 func_0218F1B4(struct FieldCamera *camera);
extern void func_0218F1AC(struct FieldCamera *camera, u32 enabled);
extern void func_0218EC54(struct FieldCamera *camera);
extern void func_0218ECC4(struct FieldCamera *camera, VecFx32 *out);
extern void func_0218ECD4(struct FieldCamera *camera, const VecFx32 *shift);
extern void func_0218ED20(struct FieldCamera *camera, VecFx32 *out);
extern void func_0218EC60(struct FieldCamera *camera);
extern const VecFx32 *func_0218EC5C(struct FieldCamera *camera);
extern void func_0218EC90(struct FieldCamera *camera, const VecFx32 *target);
extern void func_0218ED14(struct FieldCamera *camera, const VecFx32 *up);
extern void func_0218E17C(struct FieldCamera *camera, u32 settingId);
extern void func_0218F05C(struct FieldCamera *camera);
extern void func_0218ECF4(struct FieldCamera *camera, const VecFx32 *eye);
extern void func_02048AC4(struct G3dCamera *g3dCamera);
extern void func_02011B8C(struct G3dCamera *g3dCamera, struct IcaAnime *anime);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern struct ArcFile *func_020490F4(u32 arcId, u32 heapId);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern void func_0207ADC4(MtxFx33 *matrix);
extern struct G3dResource *func_02046E24(struct ArcFile *arc, u32 memberId);
extern int func_02047180(struct G3dResource *res);
extern void func_02049238(struct ArcFile *arc);
extern struct G3dRender *func_02047400(struct G3dResource *modelRes, u32 modelIndex, struct G3dResource *texRes);
extern struct G3dAnime *func_02047564(struct G3dRender *render, const struct G3dResource *animeRes, int flags);
extern struct G3dObject *func_0204767C(struct G3dRender *render, struct G3dAnime **animeTable, int animeCount);
extern u32 func_0204784C(struct G3dObject *object, u16 animeIndex, s32 *frame);
extern u32 func_020477A4(struct G3dObject *object, u32 animeIndex);
extern void func_02047738(struct G3dObject *object);
extern void func_0204762C(struct G3dAnime *anime);
extern void func_02047504(struct G3dRender *render);
extern int func_020470D0(struct G3dResource *res);
extern void func_02046EFC(struct G3dResource *res);
extern void func_0216DAC8(struct Mmdl *mmdl, u32 hidden);
extern void func_0216E084(struct Mmdl *mmdl, unsigned int tileX, unsigned int tileY, unsigned int tileZ, u16 dir);
extern int func_02164010(struct Mmdl *mmdl);
extern void func_0216D88C(const struct Mmdl *mmdl, VecFx32 *out);
extern void func_021A3044(struct FieldPlayer *player, const VecFx32 *pos);
extern int func_0216DC18(struct Mmdl *mmdl, int value);
extern u32 func_02047204(struct G3dResource *res);
extern void func_02047A60(struct G3dObject *object, G3dObjectStatus *status);
extern const s16 FX_SinCosTable_[];

struct GameEvent *func_021F36C0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant);
u32 func_021F36C8(u32 variant);
int func_021F36D4(struct G3dAnime *anime);
void func_021F36E4(struct Tcb *tcb, FkDemoWork *work);
struct GameEvent *func_021F36F0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant);
int func_021F3734(struct GameEvent *event, int *seq, FkDemoWork *work);
void func_021F3890(FkBuildModelAnime *anime, struct BuildModelMan *man, int variant);
void func_021F38D4(FkBuildModelAnime *anime);
void func_021F3904(FkBuildModelAnime *anime);
int func_021F3918(FkBuildModelAnime *anime);
void func_021F392C(FkDemoCamera *demoCamera, struct FieldCamera *fieldCamera, int heapId, int variant);
void func_021F3A14(FkDemoCamera *demoCamera);
int func_021F3A78(FkDemoCamera *demoCamera);
void func_021F3AB0(FkDemoCamera *demoCamera);
void func_021F3B10(FkDemoModel *model, struct FieldPlayer *player, struct MyStatus *myStatus, int heapId, int variant);
void func_021F3BF0(FkDemoModel *model);
void func_021F3C4C(FkDemoModel *model);
int func_021F3C84(FkDemoModel *model);
void func_021F3CC4(FkDemoModel *model, int hide);
void func_021F3D2C(FkDemoModel *model);
void func_021F3D44(FkDemoModel *model);
void func_021F3D54(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkDemoDrawWork *work);
void func_021F3D60(FkSoundAnime **out, int variant, u16 heapId);
void func_021F3D9C(FkSoundAnime **soundAnime);
int func_021F3DB8(FkSoundAnime **soundAnime);
void func_021F3DCC(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work);
void func_021F3E38(struct FieldSubproc *proc, struct FieldMap *fieldMap);
void func_021F3E54(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work);

/* Entry of the script command that starts the demo of a variant; returns the event the script waits for. */
struct GameEvent *func_021F36C0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant)
{
    return func_021F36F0(gameSystem, fieldMap, variant);
}

/*
 * Field camera setting (word table d_021F42B0, {0x1C, 0x1D, 0x1E, 0x1F}) of a
 * variant, the table func_021F392C also indexes. Region ov056: of the 33
 * overlays mapped at this address it is the only one with a function entry
 * here (the bytes before are the tail-call thunk at 0x021F36C0 and its pool
 * word); ov036..ov065 except ov056 are mid-function at 0x021F36C8, ov107 is
 * ARM. Its ov021 caller func_021B5650 passes a 1-based slot minus one (wave A1
 * witness).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021F36C8(u32 variant)
{
    return d_021F42B0[variant];
}

/* Length of a model animation in fx32 frames. */
int func_021F36D4(struct G3dAnime *anime)
{
    return func_02047674(anime)->res->frameCount << 12;
}

/*
 * Per frame task: uploads the stand-in model once. Unlabelled tail-call leaf:
 * forwards the work plus 0x3c (the model).
 */
void func_021F36E4(struct Tcb *tcb, FkDemoWork *work)
{
    func_021F3D2C(&work->model);
}

/* Creates the demo event and the task that uploads the model. */
struct GameEvent *func_021F36F0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 variant)
{
    struct GameEvent *event;
    FkDemoWork *work;

    func_02188C84(fieldMap);
    event = func_020122C0(gameSystem, 0, func_021F3734, sizeof(FkDemoWork));
    work = func_020124E8(event);
    work->fieldMap = fieldMap;
    work->gameSystem = gameSystem;
    work->variant = variant;
    work->uploadTcb = func_020056A0(func_021F36E4, work, 0);
    return event;
}

/*
 * Event function of the demo.
 *   0: set up the stand-in player model
 *   1: tell the field camera to end its delay
 *   2: wait for the delay, then set up camera, sound anime, building animation and the draw proc
 *   3: run the animations until all of them end
 *   4: put everything back
 */
int func_021F3734(struct GameEvent *event, int *seq, FkDemoWork *work)
{
    u16 heapId;
    struct FieldCamera *fieldCamera;
    struct MyStatus *myStatus;
    int cameraDone;
    int buildAnimeDone;
    int soundAnimeDone;

    heapId = func_02188C84(work->fieldMap);
    switch (*seq) {
    case 0:
        myStatus = func_02012944(func_020120F4(work->gameSystem));
        func_021F3B10(&work->model, func_02188CB4(work->fieldMap), myStatus, heapId, work->variant);
        (*seq)++;
        break;
    case 1:
        func_0218F0A8(func_02188C58(work->fieldMap));
        (*seq)++;
        break;
    case 2:
        fieldCamera = func_02188C58(work->fieldMap);
        if (func_0218F0E8(fieldCamera) != 0) {
            break;
        }
        func_021F392C(&work->camera, fieldCamera, heapId, work->variant);
        func_021F3D60(&work->soundAnime, work->variant, heapId);
        func_021F3890(&work->buildAnime, func_0218DC6C(func_02188C98(work->fieldMap)), work->variant);
        func_021F3BF0(&work->model);
        work->drawProc = func_021BB990(-1, func_02188D24(work->fieldMap), &d_021F42C0);
        func_021BBA6C(work->drawProc)->model = &work->model;
        func_021F3CC4(&work->model, 1);
        func_021F3904(&work->buildAnime);
        (*seq)++;
        break;
    case 3:
        cameraDone = func_021F3A78(&work->camera);
        func_021F3C84(&work->model);
        soundAnimeDone = func_021F3DB8(&work->soundAnime);
        buildAnimeDone = func_021F3918(&work->buildAnime);
        if (cameraDone && buildAnimeDone && soundAnimeDone) {
            (*seq)++;
        }
        break;
    case 4:
        func_021F3CC4(&work->model, 0);
        func_021BBA1C(work->drawProc);
        func_02030EAC(work->uploadTcb);
        func_021F3C4C(&work->model);
        func_021F3D9C(&work->soundAnime);
        func_021F3A14(&work->camera);
        func_021F38D4(&work->buildAnime);
        return 1;
    }
    return 0;
}

/* Finds the building model of the variant and creates its animation node; nothing for variants without one. */
void func_021F3890(FkBuildModelAnime *anime, struct BuildModelMan *man, int variant)
{
    if (d_021F4290[variant] != 0) {
        anime->node = func_0218C7D8(man, 0, &d_021F42D8[variant]);
        anime->entry = func_0218C654(man, 0, &d_021F42D8[variant]);
        anime->man = man;
    } else {
        anime->node = 0;
        anime->entry = 0;
    }
}

/* Stops both animations of the building model and deletes its node. */
void func_021F38D4(FkBuildModelAnime *anime)
{
    if (anime->node) {
        func_0218C860(anime->node);
        func_0218C69C(anime->man, anime->entry, 0, 1);
        func_0218C69C(anime->man, anime->entry, 0, 3);
        anime->node = 0;
        anime->entry = 0;
        anime->man = 0;
    }
}

/* Starts the building animation (animation slot 0, mode 0). */
void func_021F3904(FkBuildModelAnime *anime)
{
    if (anime->node) {
        func_0218C88C(anime->node, 0, 0);
    }
}

/* Returns 1 when the building animation ended or there is none. */
int func_021F3918(FkBuildModelAnime *anime)
{
    if (anime->node) {
        return func_0218C8B0(anime->node, 0);
    }
    return 1;
}

/*
 * Saves the field camera, switches it to free mode without constraint areas
 * and builds the demo camera. The demo camera is driven by the ICA animation
 * of the variant.
 */
void func_021F392C(FkDemoCamera *demoCamera, struct FieldCamera *fieldCamera, int heapId, int variant)
{
    VecFx32 target;
    VecFx32 eye;
    s32 zeroShift[3]; /* stand-in: a VecFx32 local is addressed through sp, the original keeps a pointer register */
    VecFx32 up;
    struct G3dCamera *g3dCamera;
    VecFx32 *zeroShiftPtr;

    demoCamera->frame = 0;
    demoCamera->anime = func_02011510(heapId, FK_DEMO_ARC_ID, variant + FK_DEMO_CAMERA_FILE, 10);
    g3dCamera = func_0218EC2C(fieldCamera);
    func_02048B30(g3dCamera, &target);
    func_02048AE8(g3dCamera, &eye);
    up = d_021F4338;
    /* perspective, half field of view index 0x1C6, aspect 4:3, near 1.0, far 1024.0 */
    demoCamera->g3dCamera = func_02048A24(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &eye, &up, &target, heapId);
    demoCamera->fieldCamera = fieldCamera;
    demoCamera->savedMode = func_0218E138(demoCamera->fieldCamera);
    func_0218E13C(demoCamera->fieldCamera, FK_CAMERA_MODE_FREE);
    demoCamera->savedAreasEnabled = func_0218F1B4(demoCamera->fieldCamera);
    func_0218F1AC(demoCamera->fieldCamera, 0);
    func_0218EC54(demoCamera->fieldCamera);
    zeroShiftPtr = (VecFx32 *)zeroShift;
    zeroShiftPtr->x = 0;
    zeroShiftPtr->y = 0;
    zeroShiftPtr->z = 0;
    func_0218ECC4(demoCamera->fieldCamera, &demoCamera->savedTargetShift);
    func_0218ECD4(demoCamera->fieldCamera, zeroShiftPtr);
    func_0218ED20(demoCamera->fieldCamera, &demoCamera->savedUp);
    func_021F3AB0(demoCamera);
    demoCamera->endSettingId = d_021F42B0[variant];
}

/* Gives the field camera back and deletes the demo camera. */
void func_021F3A14(FkDemoCamera *demoCamera)
{
    func_0218EC60(demoCamera->fieldCamera);
    func_0218EC90(demoCamera->fieldCamera, func_0218EC5C(demoCamera->fieldCamera));
    func_0218ECD4(demoCamera->fieldCamera, &demoCamera->savedTargetShift);
    func_0218E13C(demoCamera->fieldCamera, demoCamera->savedMode);
    func_0218F1AC(demoCamera->fieldCamera, demoCamera->savedAreasEnabled);
    func_0218ED14(demoCamera->fieldCamera, &demoCamera->savedUp);
    func_0218E17C(demoCamera->fieldCamera, demoCamera->endSettingId);
    func_0218F05C(demoCamera->fieldCamera);
    func_02048AC4(demoCamera->g3dCamera);
    func_02011558(demoCamera->anime);
    MI_CpuFill8(demoCamera, 0, sizeof(FkDemoCamera));
}

/*
 * Advances the camera animation by one frame; returns 1 on the last frame.
 *
 * note:     twin of the head of func_021F40A0 (same clock read and clamp),
 *           with the frame counter at +0x28. EXACT* = 54 bytes of code plus
 *           2 bytes of alignment padding before matched func_021F3AB0.
 */
int func_021F3A78(FkDemoCamera *demoCamera)
{
    int done;
    s32 length = ICA_ANIME_GetFrameNum(demoCamera->anime) << 12;
    s32 nextFrame = demoCamera->frame + 0x1000;

    if (length <= nextFrame) {
        done = 1;
        demoCamera->frame = length - 0x1000;
    } else {
        done = 0;
        demoCamera->frame = nextFrame;
    }
    func_020115EC(demoCamera->anime, demoCamera->frame);
    func_021F3AB0(demoCamera);
    return done;
}

/* Applies the ICA animation to the demo camera and copies its eye, target and up vector, moved by the demo origin, to the field camera. */
void func_021F3AB0(FkDemoCamera *demoCamera)
{
    VecFx32 target;
    VecFx32 eye;
    VecFx32 up;

    func_02011B8C(demoCamera->g3dCamera, demoCamera->anime);
    func_02048AE8(demoCamera->g3dCamera, &eye);
    func_02048B30(demoCamera->g3dCamera, &target);
    func_02048B0C(demoCamera->g3dCamera, &up);
    func_0207C9D0(&eye, &d_021F426C, &eye);
    func_0207C9D0(&target, &d_021F426C, &target);
    func_0218ECF4(demoCamera->fieldCamera, &eye);
    func_0218EC90(demoCamera->fieldCamera, &target);
    func_0218ED14(demoCamera->fieldCamera, &up);
}

/*
 * Loads the stand-in player model and its two animations of the variant
 * from archive 0x96 (six files per variant, gender selects the model).
 */
void func_021F3B10(FkDemoModel *model, struct FieldPlayer *player, struct MyStatus *myStatus, int heapId, int variant)
{
    struct ArcFile *arc;
    int fileBase;

    variant = (u32)variant; /* stand-in: the plain unsigned parameter gives other registers (checked) */
    arc = func_020490F4(FK_DEMO_ARC_ID, (u16)((heapId & 0x7fff) | 0x8000));
    model->animeFrame = 0;
    model->playerHidden = 0;
    model->endTile = d_021F4308[variant];
    model->myStatus = myStatus;
    model->endDir = d_021F4264[variant];
    model->player = player;
    model->playerMmdl = func_021A3074(player);
    model->status.trans = d_021F426C;
    model->status.scale.x = 0x1000;
    model->status.scale.y = 0x1000;
    model->status.scale.z = 0x1000;
    func_0207ADC4(&model->status.rotate);
    if (func_02008550(myStatus) == 0) {
        fileBase = variant * FK_DEMO_MODEL_FILE_STEP;
        model->modelRes = func_02046E24(arc, fileBase + 3);
        model->genderAnimeRes = func_02046E24(arc, fileBase + 4);
    } else {
        fileBase = variant * FK_DEMO_MODEL_FILE_STEP;
        model->modelRes = func_02046E24(arc, fileBase + 1);
        model->genderAnimeRes = func_02046E24(arc, fileBase + 2);
    }
    model->sharedAnimeRes = func_02046E24(arc, fileBase + 5);
    func_02047180(model->modelRes);
    model->uploadPending = 1;
    func_02049238(arc);
}

/* Builds the render object and the two animations of the model and starts both at frame 0. */
void func_021F3BF0(FkDemoModel *model)
{
    int i;
    int frame;

    i = 0;
    model->render = func_02047400(model->modelRes, 0, model->modelRes);
    model->anime[0] = func_02047564(model->render, model->sharedAnimeRes, 0);
    model->anime[1] = func_02047564(model->render, model->genderAnimeRes, 0);
    model->object = func_0204767C(model->render, model->anime, 2);
    frame = 0;
    for (; i < 2; i++) {
        func_0204784C(model->object, (u16)i, &frame);
        func_020477A4(model->object, (u16)i);
    }
}

/* Deletes the render object, the animations and the resources of the model. */
void func_021F3C4C(FkDemoModel *model)
{
    func_02047738(model->object);
    func_0204762C(model->anime[0]);
    func_0204762C(model->anime[1]);
    func_02047504(model->render);
    func_020470D0(model->modelRes);
    func_02046EFC(model->modelRes);
    func_02046EFC(model->sharedAnimeRes);
    func_02046EFC(model->genderAnimeRes);
}

/* Advances both model animations by one frame; returns 1 on the last frame. */
int func_021F3C84(FkDemoModel *model)
{
    int length;
    int limit;
    int done;

    length = func_021F36D4(model->anime[0]);
    limit = model->animeFrame + 0x1000;
    if (length <= limit) {
        done = 1;
        model->animeFrame = length - 0x1000;
    } else {
        done = 0;
        model->animeFrame = limit;
    }
    func_0204784C(model->object, 0, &model->animeFrame);
    func_0204784C(model->object, 1, &model->animeFrame);
    return done;
}

/*
 * Hides the real player model while the demo runs. With hide 0 it shows it
 * again at the end tile and facing of the variant and moves the player there.
 */
void func_021F3CC4(FkDemoModel *model, int hide)
{
    VecFx32 pos;

    if (hide) {
        model->playerHidden = 1;
        func_0216DAC8(model->playerMmdl, 1);
        return;
    }
    model->playerHidden = 0;
    func_0216DAC8(model->playerMmdl, 0);
    func_0216E084(model->playerMmdl, (s16)(model->endTile.x), (s16)(model->endTile.y),
                  (s16)(model->endTile.z), model->endDir);
    func_02164010(model->playerMmdl);
    func_0216D88C(model->playerMmdl, &pos);
    func_021A3044(model->player, &pos);
    func_0216DC18(model->playerMmdl, 0);
}

/* Uploads the model resource once (called by the task every frame until then). */
void func_021F3D2C(FkDemoModel *model)
{
    if (model->uploadPending != 0) {
        func_02047204(model->modelRes);
        model->uploadPending = 0;
    }
}

/* Draws the stand-in model. */
void func_021F3D44(FkDemoModel *model)
{
    func_02047A60(model->object, &model->status);
}

/*
 * Draw callback of the draw proc (template d_021F42C0).
 *
 * Addresses are Black-image addresses.
 */
void func_021F3D54(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkDemoDrawWork *work)
{
    func_021F3D44(work->model);
}

/*
 * Creates the sound anime of the variant, or clears the slot for a variant
 * without one.
 *
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of func_021F4040's u16 parameter (an int heap adds lsls/lsrs).
 */
void func_021F3D60(FkSoundAnime **out, int variant, u16 heapId)
{
    if (d_021F42A0[variant] != 0) {
        *out = func_021F4040(d_021F43A4[variant], FK_DEMO_ARC_ID, variant + FK_SOUND_ANIME_FILE, 10, heapId);
        return;
    }
    MI_CpuFill8(out, 0, 4);
}

/* Deletes the sound anime and clears the slot. */
void func_021F3D9C(FkSoundAnime **soundAnime)
{
    if (*soundAnime != 0) {
        func_021F408C(*soundAnime);
    }
    MI_CpuFill8(soundAnime, 0, 4);
}

/* Steps the sound anime; returns 1 when it ended or there is none. */
int func_021F3DB8(FkSoundAnime **soundAnime)
{
    int done = 1;

    if (*soundAnime != 0) {
        done = func_021F40A0(*soundAnime);
    }
    return done;
}

/*
 * Init of the proc that ties sounds to the animation of a building model
 * (template d_021F4344): starts the loop sound and finds the first trigger
 * frame that lies ahead.
 */
void func_021F3DCC(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work)
{
    struct BuildModelMan *man;
    u32 i;
    int frame;

    man = func_0218DC6C(func_02188C98(fieldMap));
    i = 0;
    work->entry = func_0218C654(man, 0, &d_021F4278);
    work->man = man;
    frame = func_0218C6F4(man, work->entry, 1);
    work->triggerFrame = 0x6000;
    work->triggerIndex = i;
    for (; i < 1; i++) {
        if (frame < d_021F4258[i]) {
            work->triggerFrame = d_021F4258[i];
            work->triggerIndex = i;
            break;
        }
    }
    func_02028A7C(func_02012A30(func_020120F4(func_02188C80(fieldMap))), FK_SE_BUILD_ANIME_LOOP);
}

/* Exit of that proc: stops the loop sound. */
void func_021F3E38(struct FieldSubproc *proc, struct FieldMap *fieldMap)
{
    func_02028B50(func_02012A30(func_020120F4(func_02188C80(fieldMap))), FK_SE_BUILD_ANIME_LOOP);
}

/* Update of that proc: plays the hit sound when the building animation reaches the trigger frame. */
void func_021F3E54(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAnimeSoundWork *work)
{
    struct FieldSoundSystem *soundSys;

    if (work->triggerFrame == func_0218C6F4(work->man, work->entry, 1)) {
        soundSys = func_02012A30(func_020120F4(func_02188C80(fieldMap)));
        work->triggerIndex = 0;
        work->triggerFrame = d_021F4258[work->triggerIndex];
        func_02028A7C(soundSys, FK_SE_BUILD_ANIME_HIT);
    }
}
