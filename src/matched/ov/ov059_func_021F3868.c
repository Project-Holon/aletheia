/*
 * function: SP_POKE_GIMMICK_Init
 * address:  0x021F3868
 * packet:   pkt_ov059_021F3868
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     twin of ov059 GIMMICK57_LoadModelScene plus a heap allocation and a third
 *           row loop; the second loop's counter reuses z's register.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   sSpPokeGimmickFileName     0x021F4080  data  ov059  a1
 *   sSpPokeGimmickSetup     0x021F3E74  data  a4
 */
#include "../include/Obj20584.h"

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern char sSpPokeGimmickFileName[];
extern char sSpPokeGimmickSetup[];

extern int FIELDMAP_GetExpObj(int *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FLD_EXP_OBJ_AddUnit(void *a, void *b, int c);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern u8 *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);

void SP_POKE_GIMMICK_Init(void *a)
{
    int i;
    void *s;
    int z;
    u8 *e;
    int h;
    u8 *w;

    s = (void *)FIELDMAP_GetExpObj(a);
    h = (FIELDMAP_GetHeapId(a) & 0x7FFF) | 0x8000;
    FIELDMAP_AllocCommonWork(a, 1, (u16)h, 0x28);
    w = (u8 *)FIELDMAP_GetCommonWork(a, 1);
    ((struct Obj20584 *)w)->f24 = func_02030734((u16)h, 4, 1, sSpPokeGimmickFileName, 0x1D1);
    i = 0;
    FLD_EXP_OBJ_AddUnit(s, sSpPokeGimmickSetup, 0);
    FLD_EXP_OBJ_SetModelHidden(s, 0, 1, 1);
    FLD_EXP_OBJ_SetModelHidden(s, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        e = FLD_EXP_OBJ_GetAnime(s, z, z, i);
        FLD_EXP_OBJ_SetAnimeLoop(e, z);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, z, z, i, z);
        e = FLD_EXP_OBJ_GetAnime(s, z, 1, i);
        FLD_EXP_OBJ_SetAnimeLoop(e, z);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, z, 1, i, z);
    }
    for (i = 0; i < 3; i++) {
        e = FLD_EXP_OBJ_GetAnime(s, 0, 2, i);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 2, i, 0);
    }
}
