/*
 * function: FLD_WIPE_3DOBJ_FadeOutEventMain
 * address:  0x021C85CC
 * packet:   pkt_ov021_021C85CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020124E4  0x020124E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
int FLD_WIPE_3DOBJ_FadeOutEventMain(void *task, int *state)
{
    GAMESYSTEM_GetFieldMap(func_020124E4(task));
    switch (*state) {
    case 0:
        FADE_Start(3, 0x10, 0, 0);
        (*state)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
