/*
 * function: FISHING_CreateEvent
 * address:  0x021C5D10
 * packet:   pkt_ov021_021C5D10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetFormSlot  0x021A34EC  thumb  ov021
 *   FISHING_CheckFacingWater  0x021C5C64  thumb  ov021
 *   EFFECT_ENCOUNT_IsSpotAt  0x021AA900  thumb  ov021
 *   FIELD_ENCOUNT_CheckFishingEncount  0x021AA180  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FISHING_EventMain  0x021C5DF4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    void *f18;
    void *f1C;
    s16 f20[3];
    u16 pad26;
    u32 f28;
    u8 pad2C[8];
    VecFx32 f34;
    VecFx32 f40;
    u8 pad4C[0xC];
    u8 f58;
    u8 f59;
    u16 f5A;
    u8 pad5C[8];
    void *f64;
} Work;

struct Ctx;
struct Desc;
struct Obj;
struct Self;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, u32 n);
extern void *func_020120F4(const struct Ctx *p);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void *FIELDMAP_GetMmdlSys(u8 *q);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *id, struct VecFx32 *out);
extern int FIELD_PLAYER_GetFormSlot(u8 *p);
extern int FISHING_CheckFacingWater(u32 unused, u32 a, u32 *out);
extern int EFFECT_ENCOUNT_IsSpotAt(struct Self *self, short *pos);
/* Retain the mode used to store f59 for the helper's second argument. */
extern struct Obj *FIELD_ENCOUNT_CheckFishingEncount(struct Ctx *ctx, int mode);
extern void FLDMMDL_SysPauseMove(void *o);
extern void FISHING_EventMain(void);

void *FISHING_CreateEvent(struct Obj00020 *a, void *b)
{
    void *task;
    Work *w;
    int mode;

    task = func_020122C0(b, 0, FISHING_EventMain, sizeof(Work));
    w = func_020124E8(task);
    func_02082BCC(w, 0, sizeof(Work));
    w->f0 = b;
    w->f8 = (u8 *)a;
    w->f4 = func_020120F4(b);
    w->fC = (void *)FIELDMAP_GetEncount(w->f8);
    w->f10 = (u32)GAME_DATA_GetTrainerRecord(w->f4);
    w->f14 = FIELDMAP_GetMmdlSys(w->f8);
    w->f18 = FIELDMAP_GetFieldPlayer(a);
    w->f1C = FIELD_PLAYER_GetMmdl(w->f18);
    w->f58 = FLDMMDL_GetDirDisp(w->f1C);
    FIELD_PLAYER_GetPos(w->f18, (struct VecFx32 *)&w->f34);
    w->f28 = FIELD_PLAYER_GetFormSlot(w->f18);
    if (FISHING_CheckFacingWater((u32)w->f4, (u32)w->f8, (u32 *)(&w->f40)) == 0)
        w->f5A = 1;
    w->f20[0] = (w->f40.x >> 4) / 4096;
    w->f20[1] = (w->f40.y >> 4) / 4096;
    w->f20[2] = (w->f40.z >> 4) / 4096;
    if (EFFECT_ENCOUNT_IsSpotAt(w->fC, w->f20))
        w->f59 = mode = 1;
    else
        w->f59 = mode = 0;
    w->f64 = FIELD_ENCOUNT_CheckFishingEncount(w->fC, mode);
    FLDMMDL_SysPauseMove(w->f14);
    return task;
}
