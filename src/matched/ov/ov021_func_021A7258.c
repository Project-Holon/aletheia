/*
 * function: FIELDMAP_CTRL_HYBRID_SetMode
 * address:  0x021A7258
 * packet:   pkt_ov021_021A7258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Switches an object's model between the placed mode (0: position copied
 * in and rotation set from whole-unit sixteenths) and the attached mode,
 * then applies the shared animation settings and records the new mode.
 * gFieldMapCtrlHybridModeTable is one static record: two callbacks, then at +8 the
 * parameter block FLDMMDL_ChangeHeader takes, whose u16 at +0xA is refreshed
 * here (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-
 * by-the-load-reach.md).
 *
 * symbols:
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckMoveBitAcmd  0x0216DC4C  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_PLAYER_ResetNogrid  0x021A368C  thumb  ov021
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FIELD_NOGRID_MAPPER_UnbindCameraWork  0x021BB3B8  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_ReloadSetting  0x0218E160  thumb  ov021
 *   FIELD_PLAYER_SetNogridParam  0x021A3680  thumb  ov021
 *   FIELD_PLAYER_GetNogridState  0x021A36A4  thumb  ov021
 *   FIELD_NOGRID_MAPPER_BindCameraWork  0x021BB3AC  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDirMove  0x0216D600  thumb  ov010
 *   FLDMMDL_DRAW_SetBlactAnime  0x0219F0B0  thumb  ov021
 *   gFieldMapCtrlHybridModeTable     0x021DDF38  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct ModelParam {
    u8 f0;
    u8 f1;
    u16 f2;
} ModelParam;

typedef struct Record {
    void *cb[2];
    ModelParam param;
} Record;

typedef struct Holder {
    int mode;
    void *f04;
} Holder;

extern Record gFieldMapCtrlHybridModeTable;

extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void *FIELDMAP_GetCamera(void *o);
struct Actor;
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FLDMMDL_CheckMoveBitAcmd(void *m);
extern void *FLDMMDL_FreeAcmd(char *p);
extern u16 FLDMMDL_GetObjCode(void *m);
extern void FIELD_PLAYER_ResetNogrid(u8 *p);
extern void FLDMMDL_ChangeHeader(void *a0, void *a1);
extern void FLDMMDL_InitGridPosition(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern void FIELD_NOGRID_MAPPER_UnbindCameraWork(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern int FIELD_CAMERA_ReloadSetting(u32 a);
extern void FIELD_PLAYER_SetNogridParam(u8 *p, int a1);
extern u32 FIELD_PLAYER_GetNogridState(u8 *p);
extern void FIELD_NOGRID_MAPPER_BindCameraWork(u8 *p, u32 b);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_SetDirMove(int a0, u16 a1);
extern void FLDMMDL_DRAW_SetBlactAnime(u32 a, u32 b, u32 c);

void FIELDMAP_CTRL_HYBRID_SetMode(void *o, Holder *h, int mode, VecFx32 *pos, u16 e, u16 f, u16 g)
{
    void *x;
    void *y;
    void *m;
    VecFx32 v;

    x = (void *)FIELDMAP_GetNogridMapper(o);
    y = FIELDMAP_GetCamera(o);
    if (h->mode == mode) {
        return;
    }
    m = FIELD_PLAYER_GetMmdl(h->f04);
    if (FLDMMDL_CheckMoveBitAcmd(m) != 0) {
        FLDMMDL_FreeAcmd(m);
    }
    if (mode == 0) {
        v = *pos;
        gFieldMapCtrlHybridModeTable.param.f2 = FLDMMDL_GetObjCode(m);
        FIELD_PLAYER_ResetNogrid(h->f04);
        FLDMMDL_ChangeHeader(m, &gFieldMapCtrlHybridModeTable.param);
        FLDMMDL_InitGridPosition(m, (s16)((v.x >> 12) / 16), (s16)((v.y >> 12) / 16), (s16)((v.z >> 12) / 16), e);
        FLDMMDL_GetPos(m, &v);
        FIELD_PLAYER_SetPos(h->f04, &v);
        FIELD_NOGRID_MAPPER_UnbindCameraWork(x);
        FIELD_CAMERA_SetMode(y, 0);
        FIELD_CAMERA_ResumeTargetTrace((u32)y);
        FIELD_CAMERA_ReloadSetting((u32)y);
    } else {
        FIELD_PLAYER_SetNogridParam(h->f04, (int)pos);
        FIELD_NOGRID_MAPPER_BindCameraWork(x, FIELD_PLAYER_GetNogridState(h->f04));
        FIELD_CAMERA_RestartDelay(y);
    }
    FLDMMDL_SetDirDispCheckPause((int)m, e);
    FLDMMDL_SetDirMove((int)m, e);
    FLDMMDL_DRAW_SetBlactAnime((u32)m, f, g);
    h->mode = mode;
}
