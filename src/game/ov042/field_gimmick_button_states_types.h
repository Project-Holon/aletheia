#ifndef ALETHEIA_OV042_FIELD_GIMMICK_BUTTON_STATES_TYPES_H
#define ALETHEIA_OV042_FIELD_GIMMICK_BUTTON_STATES_TYPES_H

/*
 * Field gimmick 42 (overlay 42): twelve expansion models. Models 0 to 8 are
 * shown in a state set by an event (first or last animation frame). Models 9
 * to 11 play their animation once; the save area remembers which ones did.
 */

/*
 * The expansion object types come from ov021/fld_exp_obj_types.h, which the
 * source file includes first (the compiler resolves includes against the
 * source file directory, so this header cannot include it). A file that does
 * not include it sees the types as opaque.
 */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;
typedef struct FldExpObjCnt FldExpObjCnt;
typedef struct FldExpObjAnime FldExpObjAnime;
typedef struct G3dUtilSetup G3dUtilSetup;
typedef struct G3dObjectStatus G3dObjectStatus;
#endif

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GimmickWork;

#include "../arm9/game_event.h"

#define FIELD_GIMMICK_BUTTON_STATES_STATE_MODEL_COUNT 9       /* models 0 to 8 */
#define FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_FIRST_MODEL 9    /* models 9 to 11 */

/* The common work of the gimmick on the field map (4 bytes, id 1), filled by the event creators. */
typedef struct FieldGimmickButtonStatesWork {
    u8 stateModel;      /* 0x00: model the state event changes */
    u8 oneShotIndex;    /* 0x01: one-shot model (relative to the first one) the play event runs */
    u8 showLastFrame;   /* 0x02: nonzero: the state event shows the last frame */
    u8 reserved;        /* 0x03 */
} FieldGimmickButtonStatesWork;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
#include "../ov021/fld_exp_obj.h"

int FIELD_GIMMICK_BUTTON_STATES_EventPlayOneShot(struct GameEvent *event, int *seq, void *work);

#endif
