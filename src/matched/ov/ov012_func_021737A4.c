/*
 * function: UNION_MAIN_UpdateField
 * address:  0x021737A4
 * packet:   pkt_ov012_021737A4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02034714  0x02034714  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   GAME_EVENT_IsRunning  0x020123C4  thumb
 *   UNION_MAIN_IsFieldReady  0x02173840  thumb  ov012
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   UNION_ONESELF_RunPlayCategory  0x0217B840  thumb  ov019
 *   UNION_CHARA_ProcessBeaconUpdates  0x0217B75C  thumb  ov019
 *   UNION_CHARA_Main  0x0217B264  thumb  ov019
 */
#include "../include/Obj00610.h"
#include "../include/Obj19233.h"
#include "../include/Obj19234.h"

typedef unsigned char u8;

extern unsigned int func_02026454(void *obj);
extern unsigned int func_02026474(void *obj);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern u8 GAMESYSTEM_GetFieldMapState(const struct Ctx *p);
extern int GAME_EVENT_IsRunning(void *v);
extern int UNION_MAIN_IsFieldReady(u8 *p);
extern int UNION_MAIN_IsScenePending(u8 *p);
extern int UNION_ONESELF_RunPlayCategory(char *base, int r1);
extern void UNION_CHARA_ProcessBeaconUpdates(char *p);
extern void UNION_CHARA_Main(u8 *w, void *sys, void *q);

void UNION_MAIN_UpdateField(void *a, int b)
{
    u8 *r4;
    u8 s;

    if (func_02026454(a) != 3) {
        return;
    }
    r4 = (u8 *)func_02026474(a);
    if (r4 == 0) {
        func_02034714((void *)0x02175610, 0, (void *)0x02175610);
    }
    if (GAMESYSTEM_GetFieldMapState(FIELDMAP_GetGameSystem((void *)b)) == 1) {
        return;
    }
    if (GAME_EVENT_IsRunning((void *)((struct Obj19233 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->fC) == 1) {
        return;
    }
    if (UNION_MAIN_IsFieldReady(r4) != 1) {
        return;
    }
    s = r4[0x2830];
    if (s >= 4 && s <= 0x17) {
        if (UNION_MAIN_IsScenePending(r4) != 0) {
            return;
        }
        UNION_ONESELF_RunPlayCategory((char *)r4, b);
        return;
    }
    if (s != 0 && s != 1) {
        return;
    }
    if (UNION_MAIN_IsScenePending(r4) != 0) {
        return;
    }
    UNION_CHARA_ProcessBeaconUpdates((char *)r4);
    UNION_ONESELF_RunPlayCategory((char *)r4, b);
    UNION_CHARA_Main(r4, (void *)(((struct Obj19234 *)(*(u8 * *)&((struct Obj00610 *)r4)->f0))->f8), (void *)b);
}
