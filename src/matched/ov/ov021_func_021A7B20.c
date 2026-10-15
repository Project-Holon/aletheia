/*
 * function: FIELD_GROUND_ANIME_CreateA
 * address:  0x021A7B20
 * packet:   pkt_ov021_021A7B20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_GROUND_ANIME_GetPlayerMoveMode  0x021A80FC  thumb  ov021
 *   ENTRANCE_CAMERA_Create  0x021BDC94  thumb  ov021
 *   FIELD_GROUND_ANIME_GetPlayerPos  0x021A810C  thumb  ov021
 *   FIELD_GROUND_ANIME_CreateBuildModel  0x021A8214  thumb  ov021
 *   FIELD_GROUND_ANIME_SetupStepsA  0x021A7B88  thumb  ov021
 *   FIELD_GROUND_ANIME_MainA  0x021A7CE8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Work {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x28 - 0x1B];
    int f28;
    u8 pad2C[0x36 - 0x2C];
    u8 f36;
} Work;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args;

typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern int FIELD_GROUND_ANIME_GetPlayerMoveMode(u32 a);
extern void *ENTRANCE_CAMERA_Create(void *p);
struct VecFx32;
struct Obj00020;
extern void FIELD_GROUND_ANIME_GetPlayerPos(struct Obj00020 *p, struct VecFx32 *out);
extern void FIELD_GROUND_ANIME_CreateBuildModel(Work *w);
extern void FIELD_GROUND_ANIME_SetupStepsA(Work *w);
extern int FIELD_GROUND_ANIME_MainA(void *task, int *state, struct Work *w);

void *FIELD_GROUND_ANIME_CreateA(Args *a)
{
    void *task;
    Work *w;

    task = func_020122C0(a->f04, 0, FIELD_GROUND_ANIME_MainA, 0x3C);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = (void *)GAME_DATA_GetBgmInfo(a->f08);
    w->f28 = 0;
    w->f18 = 0;
    w->f1A = FIELD_GROUND_ANIME_GetPlayerMoveMode((u32)a->f0C);
    w->f36 = 0;
    w->f08 = ENTRANCE_CAMERA_Create(a->f0C);
    w->f0C = a->f14;
    w->f10 = 1;
    w->f14 = 0;
    FIELD_GROUND_ANIME_GetPlayerPos(a->f0C, (struct VecFx32 *)((u8 *)w + 0x1C));
    FIELD_GROUND_ANIME_CreateBuildModel(w);
    FIELD_GROUND_ANIME_SetupStepsA(w);
    return task;
}
