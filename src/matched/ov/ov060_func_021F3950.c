/*
 * function: GIMMICK60_SetupEffect
 * address:  0x021F3950
 * packet:   pkt_ov060_021F3950
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern u8 *FLD_EXP_OBJ_GetAnime(void *p, int i, int j, u16 k);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);

void GIMMICK60_SetupEffect(void *unused, void *p)
{
    int i;
    u8 *e;

    FLD_EXP_OBJ_SetModelHidden(p, 0, 0x14, 1);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimeEnabled(p, 0, 0x14, (u16)i, 1);
        e = FLD_EXP_OBJ_GetAnime(p, 0, 0x14, (u16)i);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        FLD_EXP_OBJ_SetAnimePaused(e, 0);
    }
}
