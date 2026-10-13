/*
 * function: FLD3D_CI_PokemonExtraTask
 * address:  0x021C27F4
 * packet:   pkt_ov021_021C27F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124F0  0x020124F0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FLD3D_CI_LoadPokemonIconTexture  0x021C2918  thumb  ov021
 *   BMP_Delete  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj01215.h"

struct Obj;
struct Obj020437AC;
void *func_020124F0(struct Obj *p);
struct Ctx;
struct Obj;
void *func_020124E8(struct Obj *p);
void *GAME_EVENT_GetGameSystem(struct Obj *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
void FLD3D_CI_LoadPokemonIconTexture(struct Obj *p);
void BMP_Delete(struct Obj020437AC *p);
typedef unsigned int   u32;
u32 func_020307B0(void *p);

int FLD3D_CI_PokemonExtraTask(int a, int *b)
{
    char *p;

    p = *(char **)func_020124E8(func_020124F0((struct Obj *)a));
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((struct Obj *)a));
    switch (*b) {
    case 0:
        FLD3D_CI_LoadPokemonIconTexture((struct Obj *)((int)p));
        (*b)++;
        break;
    case 1:
        BMP_Delete((struct Obj020437AC *)(*(int *)&((struct Obj01215 *)p)->f90));
        func_020307B0((void *)(*(int *)&((struct Obj01215 *)p)->f94));
        func_020307B0((void *)(*(int *)&((struct Obj01215 *)p)->f98));
        (*b)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
