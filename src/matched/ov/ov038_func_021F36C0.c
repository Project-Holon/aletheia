/*
 * function: GIMMICK38_Init
 * address:  0x021F36C0
 * packet:   pkt_ov038_021F36C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     each loop keeps its own index variables: the third loop's n and
 *           t = n + 0x12 are separate from the second loop's i and k (sharing
 *           them moves the spilled index to another slot), the q lookups
 *           are spelled q[i + 8] / q[n + 0x12] (q[k] scales k instead), and
 *           i is declared before q.
 *
 * symbols:
 *   gGimmick38UnitDef     0x021F464C  data  a4
 *   gGimmick38SwitchPos     0x021F46E8  data  a4
 *   gGimmick38PlatePos     0x021F4748  data  a4
 *   gGimmick38DoorPos     0x021F4694  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   GFL_HEAP_GetTotalFreeSize  0x02030344  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 */

#include "../include/G_S3A08.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int gGimmick38UnitDef;
extern V gGimmick38SwitchPos[];
extern V gGimmick38PlatePos[];
extern struct S3A08 gGimmick38DoorPos[];

struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
extern unsigned char *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
typedef unsigned char  u8;
extern void *GFL_HEAP_GetTotalFreeSize(u32 heapId);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern V    *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void  FLD_EXP_OBJ_SetModelHidden(void *p, int i, u16 j, int v);
extern void *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);
extern void  FLD_EXP_OBJ_SetAnimeFrame(void *p, int i, u16 j, u16 k, int v);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);

void GIMMICK38_Init(void *a0)
{
    void *r5;
    int i;
    int *q;
    int n;
    int j;
    int k;
    int t;
    int m;
    void *b;
    V *e;
    V v;

    r5 = (void *)FIELDMAP_GetExpObj(a0);
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave((struct Big *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0))), 6);
    GFL_HEAP_GetTotalFreeSize(0x15);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 0x24);
    FLD_EXP_OBJ_AddUnitFromArchive(r5, &gGimmick38UnitDef, 0);
    GFL_HEAP_GetTotalFreeSize(0x15);
    for (i = 0; i < 8; i++) {
        e = FLD_EXP_OBJ_GetModelStatus(r5, 0, i);
        *e = gGimmick38SwitchPos[i];
        FLD_EXP_OBJ_SetModelCullDraw(r5, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            b = FLD_EXP_OBJ_GetAnime(r5, 0, i, j);
            FLD_EXP_OBJ_SetAnimeLoop(b, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(r5, 0, i, j, 1);
            FLD_EXP_OBJ_SetAnimePaused(b, 1);
            if (q[i] != 0)
                FLD_EXP_OBJ_SetAnimeFrame(r5, 0, i, j, FLD_EXP_OBJ_GetAnimeLastFrame((u32)b));
        }
    }
    for (i = 0; i < 10; i++) {
        k = i + 8;
        e = FLD_EXP_OBJ_GetModelStatus(r5, 0, k);
        *e = gGimmick38PlatePos[i];
        FLD_EXP_OBJ_SetModelCullDraw(r5, 0, (u16)k, 1);
        for (j = 0; j < 2; j++) {
            b = FLD_EXP_OBJ_GetAnime(r5, 0, k, j);
            FLD_EXP_OBJ_SetAnimeLoop(b, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(r5, 0, k, j, 1);
            FLD_EXP_OBJ_SetAnimePaused(b, 1);
            if (q[i + 8] != 0)
                FLD_EXP_OBJ_SetAnimeFrame(r5, 0, k, j, FLD_EXP_OBJ_GetAnimeLastFrame((u32)b));
        }
    }
    for (n = 0; n < 7; n++) {
        t = n + 0x12;
        m = n + 0x19;
        e = FLD_EXP_OBJ_GetModelStatus(r5, 0, t);
        v = ((V *)gGimmick38DoorPos)[n];
        *e = v;
        *FLD_EXP_OBJ_GetModelStatus(r5, 0, m) = v;
        FLD_EXP_OBJ_SetModelCullDraw(r5, 0, (u16)t, 1);
        FLD_EXP_OBJ_SetModelCullDraw(r5, 0, (u16)m, 1);
        switch (q[n + 0x12]) {
        case 0:
            FLD_EXP_OBJ_SetModelHidden(r5, 0, m, 1);
            break;
        case 1:
            FLD_EXP_OBJ_SetModelHidden(r5, 0, t, 1);
            break;
        }
    }
    FLD_EXP_OBJ_SetModelCullDraw(r5, 0, (u16)0x20, 1);
    for (i = 0; i < 2; i++) {
        b = FLD_EXP_OBJ_GetAnime(r5, 0, 0x20, i);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
        FLD_EXP_OBJ_SetAnimePaused(b, 1);
    }
    for (i = 0; i < 8; i++) {
        b = FLD_EXP_OBJ_GetAnime(r5, 0, 0x21, i);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
        FLD_EXP_OBJ_SetAnimeEnabled(r5, 0, 0x21, i, 0);
    }
    for (i = 0; i < 4; i++) {
        b = FLD_EXP_OBJ_GetAnime(r5, 0, 0x22, i);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
    }
    FLD_EXP_OBJ_SetModelHidden(r5, 0, 0x21, 1);
    FLD_EXP_OBJ_SetModelHidden(r5, 0, 0x22, 1);
    GFL_HEAP_GetTotalFreeSize(0x15);
}
