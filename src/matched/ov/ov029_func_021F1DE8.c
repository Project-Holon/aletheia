/*
 * function: C_GEAR_LoadGraphics
 * address:  0x021F1DE8
 * packet:   pkt_ov029_021F1DE8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020090F0  0x020090F0  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   C_GEAR_LoadSkin  0x021F1458  thumb  ov029
 *   C_GEAR_LoadSpriteResources  0x021F1574  thumb  ov029
 *   C_GEAR_CreateHudActors  0x021F1950  thumb  ov029
 *   C_GEAR_CreateBarActors  0x021F1C0C  thumb  ov029
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   C_GEAR_DrawEmptyBoard  0x021F1010  thumb  ov029
 *   C_GEAR_SetAllActorsVisible  0x021F1A64  thumb  ov029
 *   C_GEAR_SetTileMarkersVisible  0x021F1A44  thumb  ov029
 *   C_GEAR_DrawAllCells  0x021F13FC  thumb  ov029
 *   C_GEAR_OnButtonEvent  0x021F18F0  thumb  ov029
 *   d_021F3214     0x021F3214  data  a4
 *   d_021F3272     0x021F3272  data  a2
 */
#include "../include/Obj00106.h"

struct Bank;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
struct Obj;
struct Sub0200852CObj;
struct Sub020090B0Obj;
extern unsigned char *GAME_DATA_GetMyStatus(void *p);
extern unsigned char func_02008550(const struct Sub0200852CObj *obj);
extern unsigned char func_020090F0(const struct Sub020090B0Obj *obj);
extern struct Bank *CLACT_CreateUnit(int count, unsigned char flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(unsigned char *a0, u32 a1, u32 heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern u32 C_GEAR_LoadSkin(unsigned char *p, int a, int b, int c);
typedef unsigned char  u8;
extern void C_GEAR_LoadSpriteResources(char *p, int idx);
extern void C_GEAR_CreateHudActors(char *p);
extern void C_GEAR_CreateBarActors(char *p);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern void C_GEAR_DrawEmptyBoard(void *);
extern void C_GEAR_SetAllActorsVisible(char *p, int flag);
extern void C_GEAR_SetTileMarkersVisible(char *p, int flag);
extern void C_GEAR_DrawAllCells(void *);
extern void C_GEAR_OnButtonEvent(int key, int flag, u8 *p);
extern char d_021F3214[];
extern char d_021F3272[];

void C_GEAR_LoadGraphics(char *p, int flag)
{
    int z;

    ((struct Obj00106 *)p)->f459 = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj00106 *)p)->f1C))));
    ((struct Obj00106 *)p)->f458 = func_020090F0((const struct Sub020090B0Obj *)(((struct Obj00106 *)p)->f20));
    z = 0;
    ((struct Obj00106 *)p)->f34 = (int)CLACT_CreateUnit(0x44, 0, ((struct Obj00106 *)p)->fC);
    ((struct Obj00106 *)p)->f38 = CLACT_CreateRenderer((unsigned char *)d_021F3214, 1, ((struct Obj00106 *)p)->fC);
    CLACT_SetUnitRenderer((struct Bank *)(((struct Obj00106 *)p)->f34), ((struct Obj00106 *)p)->f38);
    C_GEAR_LoadSkin((unsigned char *)p, ((struct Obj00106 *)p)->f459, ((struct Obj00106 *)p)->f458, 1);
    C_GEAR_LoadSpriteResources(p, ((struct Obj00106 *)p)->f459);
    C_GEAR_CreateHudActors(p);
    C_GEAR_CreateBarActors(p);
    ((struct Obj00106 *)p)->f10 = (int)BUTTON_MAN_Create((u8 *)d_021F3272, (int)((void *)C_GEAR_OnButtonEvent), (int)p, ((struct Obj00106 *)p)->fC);
    if (flag) {
        C_GEAR_DrawEmptyBoard(p);
        C_GEAR_SetAllActorsVisible(p, z);
    } else {
        C_GEAR_DrawAllCells(p);
        C_GEAR_SetAllActorsVisible(p, 1);
        C_GEAR_SetTileMarkersVisible(p, 1);
    }
}
