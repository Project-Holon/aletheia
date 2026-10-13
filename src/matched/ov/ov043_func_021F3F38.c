/*
 * function: GIMMICK43_ShowLiftAnime
 * address:  0x021F3F38
 * packet:   pkt_ov043_021F3F38
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sGimmick43LiftAnimeFlip     0x021F4328  data  ov043
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 */

typedef unsigned short u16;

extern int sGimmick43LiftAnimeFlip[];

extern void  FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);

void GIMMICK43_ShowLiftAnime(int *a, void *b, int c)
{
    int r4, r6;

    if (a[c]) {
        if (sGimmick43LiftAnimeFlip[c]) {
            r4 = 0;
            r6 = 1;
        } else {
            r4 = 1;
            r6 = 0;
        }
    } else {
        if (sGimmick43LiftAnimeFlip[c]) {
            r4 = 1;
            r6 = 0;
        } else {
            r4 = 0;
            r6 = 1;
        }
    }
    FLD_EXP_OBJ_SetAnimeEnabled(b, 0, c, r4, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(b, 0, c, r6, 0);
    FLD_EXP_OBJ_SetAnimeFrame((int)b, 0, (u16)c, (u16)r4, 0);
    FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(b, 0, c, r4), 1);
}
