/*
 * function: FIELD_TILE_MOVE_SlideFinishBump
 * address:  0x021C8D74
 * packet:   pkt_ov021_021C8D74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_IsResourceLoaded  0x021ABE8C  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartAtPos  0x021AD598  thumb  ov021
 *   FIELD_TILE_MOVE_SlidePlayBumpEffectSe  0x021C8E14  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetEffect(u8 *p);
struct T;
extern int FIELD_EFFECT_IsResourceLoaded(struct T *a, int id);
extern void FIELD_EFFECT_LoadResources(int a, int *b, int c);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FLDEFF_NAMIPOKE_SPLASH_StartAtPos(u32 a, u32 b, u32 c);
extern void FIELD_TILE_MOVE_SlidePlayBumpEffectSe(int *p);

void FIELD_TILE_MOVE_SlideFinishBump(int *p)
{
    int buf[3];
    int v;
    int r5;

    if (p[5] != 0) {
        r5 = FIELDMAP_GetEffect((u8 *)p[1]);
        v = 9;
        if (FIELD_EFFECT_IsResourceLoaded((struct T *)r5, v) == 0) {
            FIELD_EFFECT_LoadResources(r5, &v, 1);
        }
        FIELD_PLAYER_GetPos((unsigned char *)p[2], (struct VecFx32 *)buf);
        FLDEFF_NAMIPOKE_SPLASH_StartAtPos(r5, 0, (u32)buf);
        FIELD_TILE_MOVE_SlidePlayBumpEffectSe(p);
        p[5] = 0;
        p[6] = 0;
    }
}
