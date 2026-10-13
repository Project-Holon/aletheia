/*
 * function: FIELD_GIMMICK_TIME_EFFECT_StartEffect
 * address:  0x021F385C
 * packet:   pkt_ov065_021F385C
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void FIELD_GIMMICK_TIME_EFFECT_StartEffect(int a)
{
    int i;
    int s;
    int *w;

    s = FIELDMAP_GetExpObj((int *)a);
    w = FIELDMAP_GetCommonWork((char *)a, 1);
    w[0] = 1;
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 0);
    for (i = 0; i < 2; i++)
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)s, 0, (int)0, (unsigned short)i), 0);
    if (w[1] != 0)
        GFL_USE_PlaySeDefaultVolume(0x7F7);
    else
        GFL_USE_PlaySeDefaultVolume(0x7F8);
}
