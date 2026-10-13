/*
 * function: FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent
 * address:  0x02168E5C
 * packet:   pkt_ov010_02168E5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   FLD_BTL_INST_TOOL_TrialHouseAwardEventMain  0x02168EB0  thumb
 */
#include "../include/Obj04944.h"

typedef unsigned int u32;
typedef unsigned char u8;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Sub0200852CObj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E8F8(void *sys);
extern int FLD_BTL_INST_TOOL_TrialHouseAwardEventMain(void *a, int *state);

int FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(int a, int b, int c)
{
    int x = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    int h = (int)func_020122C0((void *)a, 0, FLD_BTL_INST_TOOL_TrialHouseAwardEventMain, 0x18);
    int *p = func_020124E8((struct Obj *)h);
    p[0] = a;
    p[1] = (int)GAMESYSTEM_GetFieldMap((void *)a); /* int-typed on purpose: field is int in record */
    ((struct Obj04944 *)p)->f8 = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)x));
    p[3] = (int)func_0200E8F8(GAME_DATA_GetSaveControl((struct Big *)x));
    p[4] = b;
    p[5] = c;
    return h;
}
