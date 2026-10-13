/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F5270, func_021F5280, func_021F5290, func_021F52A0, func_021F52B0, func_021F52D8, func_021F5324
 * address:  0x021F5260
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF560 0x021CF560 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5334  0x021F5334  thumb  ov076
 *   SCREENTEX_SetupCamera 0x0202E688 thumb
 */
#include "enceff_model_types.h"

struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5334(void *task, int *state);
extern void SCREENTEX_SetupCamera(void *object);
void *func_021F5260(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *func_021F5270(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *func_021F5280(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *func_021F5290(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *func_021F52A0(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *func_021F52B0(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen);
void *func_021F52D8(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen);
void func_021F5324(struct EncEffWork *eff);

void *func_021F5260(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return func_021F52D8(gameSystem, fieldMap, 7, 6, useSubScreen); }

void *func_021F5270(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return func_021F52D8(gameSystem, fieldMap, 9, 8, useSubScreen); }

void *func_021F5280(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return func_021F52D8(gameSystem, fieldMap, 5, 4, useSubScreen); }

void *func_021F5290(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return func_021F52D8(gameSystem, fieldMap, 3, 2, useSubScreen); }

/*
 * Extent tail: two bytes of alignment padding.
 */
void *func_021F52A0(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) { return func_021F52D8(gameSystem, fieldMap, 1, 0, useSubScreen); }

void *func_021F52B0(void *gameSystem, struct FieldMap *fieldMap, int useSubScreen) {
    void *event;
    event = func_021F52D8(gameSystem, fieldMap, 11, 10, useSubScreen);
    func_021CF560(func_02189A08(fieldMap))->soundId = 0x7F3;
    return event;
}


void *func_021F52D8(void *gameSystem, struct FieldMap *fieldMap, u32 modelIndex, u32 animeIndex, int useSubScreen)
{
    EncEffModelScene *scene;
    void *event;

    scene = func_021CF52C(func_02189A08(func_0201210C(gameSystem)), sizeof(EncEffModelScene), 0x50);
    event = func_020122C0(gameSystem, 0, func_021F5334, 0);
    scene->fieldMap = fieldMap;
    scene->modelIndex = modelIndex;
    scene->animeIndex = animeIndex;
    scene->soundId = -1;
    if (useSubScreen != 0) {
        scene->fadeScreens = 0xC;
    } else {
        scene->fadeScreens = 3;
    }
    return event;
}

void func_021F5324(struct EncEffWork *eff) { SCREENTEX_SetupCamera(func_021CF560(eff)->object); }
