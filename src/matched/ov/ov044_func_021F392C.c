/*
 * function: FIELD_GIMMICK_LIFT_ShowIdleAnime
 * address:  0x021F392C
 * packet:   pkt_ov044_021F392C
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 */

extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);

void FIELD_GIMMICK_LIFT_ShowIdleAnime(void *p)
{
    FLD_EXP_OBJ_SetAnimeEnabled(p, 0, 0, 1, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(p, 0, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeFrame((int)p, 0, 0, 1, 0);
    p = FLD_EXP_OBJ_GetAnime(p, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimePaused(p, 1);
}
