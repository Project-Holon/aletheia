/*
 * function: FIELD_GIMMICK_MODELS_B_ShowModel1
 * address:  0x021F37B8
 * packet:   pkt_ov050_021F37B8
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb
 */

extern int FIELDMAP_GetExpObj(int a);
typedef unsigned int   u32;
extern void func_021BE4B4(char *ctx, int b, int c, u32 d);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, int c, unsigned short d, int e);
extern int FLD_EXP_OBJ_GetAnime(int a, int b, int c, unsigned short d);
extern void FLD_EXP_OBJ_SetAnimeLoop(int a, int b);

void FIELD_GIMMICK_MODELS_B_ShowModel1(int a)
{
    int r6;
    int i;
    int j;

    r6 = FIELDMAP_GetExpObj(a);
    func_021BE4B4((char *)r6, 0, 1, 0);
    for (i = 0; i < 2; i++)
        FLD_EXP_OBJ_SetAnimeEnabled(r6, 0, 1, i, 1);
    for (j = 0; j < 2; j++)
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(r6, 0, 1, j), 0);
}
