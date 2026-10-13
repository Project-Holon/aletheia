/*
 * function: GIMMICK64_IsArcAnimeStopped
 * address:  0x021F3BD8
 * packet:   pkt_ov064_021F3BD8
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);

int GIMMICK64_IsArcAnimeStopped(void *task)
{
    int s;

    s = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(func_020124E4(task)));
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)s, 0, 1, 0)) != 0) {
        return 1;
    }
    return 0;
}
