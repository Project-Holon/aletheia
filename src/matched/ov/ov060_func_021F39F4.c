/*
 * function: GIMMICK60_UpdateEffect
 * address:  0x021F39F4
 * packet:   pkt_ov060_021F39F4
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     closes docs/notes/ov060_func_021F39F4.c.txt: the Thumb callee at
 *           0x021BE6BC is ov021's leaf, now matched (ov021 token); the
 *           function is 52 bytes, the rest of the handed 492 is data.
 *
 * symbols:
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 */

typedef unsigned char u8;

extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);

void GIMMICK60_UpdateEffect(u8 *a, void *p)
{
    if (a[1] != 0) {
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(p, 0, 0x14, 0)) != 0) {
            FLD_EXP_OBJ_SetModelHidden(p, 0, 0x14, 1);
            a[1] = 0;
        }
    }
}
