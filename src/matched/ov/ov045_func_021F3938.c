/*
 * function: FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose
 * address:  0x021F3938
 * packet:   pkt_ov045_021F3938
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 */

typedef unsigned short u16;

extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);

void FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose(void *a0, int a1, int a2, int a3)
{
    int r4, r7;

    if (a1) {
        r4 = 1;
        r7 = 0;
    } else {
        r4 = 0;
        r7 = 1;
    }
    if (a3 != 1) {
        a2 += 3;
    }
    FLD_EXP_OBJ_SetAnimeEnabled(a0, 0, a2, r4, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(a0, 0, a2, r7, 0);
    FLD_EXP_OBJ_SetAnimeFrame((int)a0, 0, (u16)a2, (u16)r4, 0);
    FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(a0, 0, a2, r4), 1);
}
