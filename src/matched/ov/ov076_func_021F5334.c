/*
 * function: ENCEFF_ModelSceneEventMain
 * address:  0x021F5334
 * packet:   pkt_ov076_021F5334
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the only wildcard is the THM_CALL at +0x118 to the arm9
 * leaf G3D_SYSTEM_GetObjectAnimeFrameMax (unlabelled ARM, 48 bytes, the integrator's), which has no
 * witness outside this range.  Reading the frame count into `cur` before
 * the f38 test is what loads it ahead of the compare (3 lines otherwise).
 *
 * blocker:
 *   0x02047888 arm9 ARM, verified EXACT (--arm, no --region) by the ov021
 *   FLDEFF_BUBBLE_Update lane; copied from src/pending/ov/FLDEFF_BUBBLE_Update.c:
 *     typedef unsigned short u16;
 *     int G3D_SYSTEM_GetObjectAnimeFrameMax(int *a, int idx, int *out) {
 *         int *p = ((int **)a[2])[idx];
 *         if (p == 0) { return 0; }
 *         *out = ((u16 *)((int *)p[1])[2])[2] << 12;
 *         return 1;
 *     }
 *
 * Task callback that ENCEFF_StartModelScene registers: ov073 ENCEFF_NameCutInEventMain's fade
 * states 0-2, then a 3D model load, a frame-count wait with a fade-out
 * and the teardown.  The work block is the 0x44 bytes ENCEFF_StartModelScene
 * allocates (f4 = b, f2C/f30 = c/d, f34 = fade plane, f40 = -1 sound).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GX_GetBankForTex  0x02080C44  arm
 *   func_02080294  0x02080294  arm
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCREENTEX_Create  0x0202E560  thumb
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   SCREENTEX_CaptureDisplay  0x0202E610  thumb
 *   FIELDMAP_GetDrawMode  0x021899F0  thumb  ov021
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   G3D_SYSTEM_GetObjectAnimeFrameMax  0x02047888  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Work {
    int f0;
    u8 *f4;
    u32 f8;
    int fC;
    u32 f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    u32 f2C;
    u32 f30;
    int f34;
    int f38;
    s32 f3C;
    int f40;
} Work;

struct AnmCtl;
struct Ctx;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Obj;
struct Rec;
struct Tagged;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_GetWork(u32 *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern u16 GX_GetBankForTex(void);
extern void func_02080294(u32 bank);
extern void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *SCREENTEX_Create(u32 heap, u32 sel);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void SCREENTEX_CaptureDisplay(u32 a0, u32 a1);
extern u32 FIELDMAP_GetDrawMode(u8 *p);
extern void FIELDMAP_SetDrawMode(u8 *p, u32 v);
extern int G3D_SYSTEM_GetObjectAnimeFrameMax(int *a, int idx, int *out);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

int ENCEFF_ModelSceneEventMain(void *task, int *st)
{
    Work *w;
    s32 end;
    s32 frame;
    s32 cur;

    w =(Work *)ENCEFF_GetWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(task)))));
    switch (*st) {
    case 0:
        FADE_Start(4, 0, 0x10, 0);
        *st = *st + 1;
    case 1:
        if (FADE_IsActive() == 0) {
            FADE_Start(4, 0x10, 0, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            w->f0 = w->f0 + 1;
            if (w->f0 < 2) {
                FADE_Start(4, 0, 0x10, 0);
                *st = 1;
            } else {
                *st = *st + 1;
            }
        }
        break;
    case 3:
        w->f8 = GX_GetBankForTex();
        w->fC = 0;
        if ((w->f8 & 8) == 0) {
            w->fC = 1;
            w->f8 |= 8;
            func_02080294(w->f8);
        }
        w->f14 = G3D_SYSTEM_CreateResourceArc(0x81, w->f2C);
        w->f1C = G3D_SYSTEM_CreateResourceArc(0x81, w->f30);
        w->f18 = SCREENTEX_Create(FIELDMAP_GetHeapId(w->f4), 3);
        w->f20 = G3D_SYSTEM_CreateRender(w->f14, 0, w->f18);
        w->f24 = G3D_SYSTEM_CreateAnime(w->f20, w->f1C, 0);
        w->f28 = G3D_SYSTEM_CreateObject((u32)w->f20, (u32 *)(&w->f24), 1);
        G3D_SYSTEM_EnableObjectAnime(w->f28, 0);
        SCREENTEX_CaptureDisplay(3, 3);
        w->f10 = FIELDMAP_GetDrawMode(w->f4);
        FIELDMAP_SetDrawMode(w->f4, 2);
        w->f38 = 0;
        G3D_SYSTEM_GetObjectAnimeFrameMax(w->f28, 0, &end);
        w->f3C = end - 0x14000;
        if (w->f40 != -1) {
            GFL_USE_PlaySeDefaultVolume(w->f40);
        }
        *st = *st + 1;
        break;
    case 4:
        G3D_SYSTEM_GetObjectAnimeFrame(w->f28, 0, &frame);
        cur = frame;
        if (w->f38 == 0 && cur >= w->f3C) {
            FADE_Start(w->f34, 0, 0x10, 3);
            w->f38 = 1;
        }
        if (G3D_SYSTEM_IncObjectAnimeFrame(w->f28, 0, 0x1000) == 0 && FADE_IsActive() == 0) {
            *st = *st + 1;
        }
        break;
    case 5:
        if (w->fC == 1) {
            w->f8 &= ~8;
            func_02080294(w->f8);
        }
        G3D_SYSTEM_DeleteObject(w->f28);
        G3D_SYSTEM_DeleteAnime(w->f24);
        G3D_SYSTEM_DeleteRender(w->f20);
        G3D_SYSTEM_DeleteResource(w->f1C);
        G3D_SYSTEM_DeleteResource(w->f18);
        G3D_SYSTEM_DeleteResource(w->f14);
        FIELDMAP_SetDrawMode(w->f4, w->f10);
        return 1;
    }
    return 0;
}
