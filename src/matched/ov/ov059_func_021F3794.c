/*
 * function: SP_POKE_GIMMICK_InitPairB
 * address:  0x021F3794
 * packet:   pkt_ov059_021F3794
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   sSpPokeGimmickPairBSetup     0x021F3E84  data  a4
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern char sSpPokeGimmickPairBSetup[];

extern int FIELDMAP_GetExpObj(int *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void FLD_EXP_OBJ_AddUnitFromArchive(void *a, void *b, int c);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern u8 *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);

void SP_POKE_GIMMICK_InitPairB(void *a)
{
    int i;
    void *s;
    u8 *e;

    s = (void *)FIELDMAP_GetExpObj(a);
    FIELDMAP_AllocCommonWork(a, 1, FIELDMAP_GetHeapId(a), 0x28);
    FLD_EXP_OBJ_AddUnitFromArchive(s, sSpPokeGimmickPairBSetup, 0);
    FLD_EXP_OBJ_SetModelHidden(s, 0, 1, 1);
    FLD_EXP_OBJ_SetModelHidden(s, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        e = FLD_EXP_OBJ_GetAnime(s, 0, 0, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 0, (u16)i, 0);
        e = FLD_EXP_OBJ_GetAnime(s, 0, 1, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        FLD_EXP_OBJ_SetAnimePaused(e, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 1, (u16)i, 0);
    }
}
