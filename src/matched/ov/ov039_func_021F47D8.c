/*
 * function: GIMMICK39_SwapCartAnimes
 * address:  0x021F47D8
 * packet:   pkt_ov039_021F47D8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK39_SwapCartAnimes  0x021F47D8  thumb
 *   GIMMICK39_GetAnimeFrame  0x021F3DE4  thumb
 *   GIMMICK39_SetAnimeFrame  0x021F3E04  thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimePaused  0x021BE6B4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int GIMMICK39_GetAnimeFrame(void *p, u16 delta, u16 i);
extern void GIMMICK39_SetAnimeFrame(void *p, u8 delta, u16 i, int frame);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *a, int b, int c, int d, int e);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern u8 FLD_EXP_OBJ_IsAnimePaused(u8 *p);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);

void GIMMICK39_SwapCartAnimes(void *a, int f, int i)
{
    u8 r7;
    u8 r6;
    u8 r4;
    u8 v;
    int d;

    if (f == 0) {
        r7 = i * 2 + 1;
        r6 = r7 + 1;
    } else {
        r6 = i * 2 + 1;
        r7 = r6 + 1;
    }
    r4 = i;
    d = GIMMICK39_GetAnimeFrame(a, r4, r7);
    FLD_EXP_OBJ_SetAnimeEnabled(a, 0, r4, r7, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(a, 0, r4, r6, 1);
    GIMMICK39_SetAnimeFrame(a, r4, r6, d);
    v = FLD_EXP_OBJ_IsAnimePaused(FLD_EXP_OBJ_GetAnime(a, 0, r4, r7));
    FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(a, 0, r4, r6), v);
}
