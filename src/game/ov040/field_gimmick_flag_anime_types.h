#ifndef ALETHEIA_OV040_FIELD_GIMMICK_FLAG_ANIME_TYPES_H
#define ALETHEIA_OV040_FIELD_GIMMICK_FLAG_ANIME_TYPES_H

/*
 * Field gimmick 40 (overlay 40): one expansion model with one animation.
 * Script commands set a flag, read it, and start the animation event.
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

/* The common work of the gimmick on the field map (4 bytes, id 1). */
typedef struct FieldGimmickFlagAnimeWork {
    u16 modelIndex;     /* 0x00: model whose animation the event plays */
    u16 reserved;       /* 0x02 */
} FieldGimmickFlagAnimeWork;

/* Where the model stands (x and z in fx32). */
typedef struct FieldGimmickFlagAnimeModelPos {
    fx32 x;
    fx32 z;
} FieldGimmickFlagAnimeModelPos;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
#include "../ov021/fld_exp_obj.h"

int FIELD_GIMMICK_FLAG_ANIME_EventPlayAnime(struct GameEvent *event, int *seq, void *work);

#endif
