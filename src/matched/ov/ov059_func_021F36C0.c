/*
 * function: GIMMICK57_LoadModelScene
 * address:  0x021F36C0
 * packet:   pkt_ov059_021F36C0
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
 *   sSpPokeGimmickPairASetup  0x021F3E94  data  a4
 */

typedef unsigned short u16;

typedef unsigned char  u8;
extern int FIELDMAP_GetExpObj(int *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern int FLD_EXP_OBJ_GetAnime(int a, int b, int c, u16 d);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, int c, u16 d, int e);
extern char sSpPokeGimmickPairASetup[];

void GIMMICK57_LoadModelScene(int a)
{
    int i;
    int r5;
    int z;
    int r7;

    r5 = FIELDMAP_GetExpObj((int *)a);
    FIELDMAP_AllocCommonWork((unsigned char *)a, 1, FIELDMAP_GetHeapId((u8 *)a), 0x28);
    FLD_EXP_OBJ_AddUnitFromArchive(r5, sSpPokeGimmickPairASetup, 0);
    i = 0;
    FLD_EXP_OBJ_SetModelHidden((char *)r5, 0, 1, 1);
    FLD_EXP_OBJ_SetModelHidden((char *)r5, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        r7 = FLD_EXP_OBJ_GetAnime(r5, z, z, i);
        FLD_EXP_OBJ_SetAnimeLoop((unsigned char *)r7, z);
        FLD_EXP_OBJ_SetAnimePaused((unsigned char *)r7, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(r5, z, z, i, z);
        r7 = FLD_EXP_OBJ_GetAnime(r5, z, 1, i);
        FLD_EXP_OBJ_SetAnimeLoop((unsigned char *)r7, z);
        FLD_EXP_OBJ_SetAnimePaused((unsigned char *)r7, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(r5, z, 1, i, z);
    }
}
