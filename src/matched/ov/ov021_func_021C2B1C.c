/*
 * function: FLD3D_CI_FadeOutTask
 * address:  0x021C2B1C
 * packet:   pkt_ov021_021C2B1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 */

struct Obj;
void *func_020124E4(struct Obj *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int FADE_IsActive(void);

int FLD3D_CI_FadeOutTask(int a, int *b)
{
    GAMESYSTEM_GetFieldMap(func_020124E4((struct Obj *)a));
    switch (*b) {
    case 0:
        FADE_Start(4, 0, 0x10, -1);
        (*b)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
