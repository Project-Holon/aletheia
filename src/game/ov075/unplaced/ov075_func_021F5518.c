/*
 * function: ENCEFF_ScreenTexEventMain
 * address:  0x021F5518
 * packet:   pkt_ov075_021F5518
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state proc; its states 1-3 are ENCEFF_ScreenTexFlashEventMain's states 4-6, and the
 * shape follows ov073's ENCEFF_NameCutInEventMain.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_RequestScreenCapture  0x021F54A0  thumb  ov075
 *   func_0204047C  0x0204047C  arm
 *   FIELDMAP_GetDrawMode  0x021899F0  thumb  ov021
 *   func_02080C44  0x02080C44  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02080294  0x02080294  arm
 *   ENCEFF_GetScreenTexParam  0x021F54E0  thumb  ov075
 *   func_02040588  0x02040588  arm
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */
#include "../../ov021/fieldmap_types.h"
#include "../unit_021F5260_types.h"

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern void ENCEFF_RequestScreenCapture(EncEffScreenTexWork *work);
extern void func_0204047C(int idx, u16 val);
extern int FIELDMAP_GetDrawMode(struct FieldMap *fieldMap);
extern void FIELDMAP_SetDrawMode(struct FieldMap *fieldMap, int drawMode);
extern u16 func_02080C44(void);
extern void func_02080B98(void);
extern void func_02080294(u32 bank);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct EncEff *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void *ENCEFF_GetWork(struct EncEff *eff);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern u32 ENCEFF_GetScreenTexParam(void);

int ENCEFF_ScreenTexEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u32 texBanks;
    struct GameEvent *child;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    switch (*state) {
    case 0:
        ENCEFF_RequestScreenCapture(work);
        *state = *state + 1;
        break;
    case 1:
        if (work->captureDone != 0) {
            func_0204047C(0, 0);
            func_0204047C(2, 3);
            work->savedDrawMode = FIELDMAP_GetDrawMode(fieldMap);
            texBanks = func_02080C44();
            work->texBanks = texBanks;
            work->addedTexBank = 0;
            if ((texBanks & 8) == 0) {
                work->texBanks = texBanks | 8;
                work->addedTexBank = 1;
            }
            func_02080B98();
            func_02080294(work->texBanks);
            work->texParam = ENCEFF_GetScreenTexParam();
            *state = *state + 1;
        }
        break;
    case 2:
        func_02040588(2, 1);
        func_02040588(0, 1);
        FIELDMAP_SetDrawMode(fieldMap, 2);
        child = work->start(gameSystem);
        work->effectWork = ENCEFF_GetWork(FIELDMAP_GetEncEff(fieldMap));
        GAME_EVENT_CallEvent(event, child);
        *state = *state + 1;
        break;
    case 3:
        if (work->addedTexBank == 1) {
            work->texBanks &= ~8;
            func_02080294(work->texBanks);
        }
        FIELDMAP_SetDrawMode(fieldMap, work->savedDrawMode);
        return 1;
    }
    return 0;
}
