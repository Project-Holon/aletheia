#ifndef ALETHEIA_OV059_SP_POKE_GIMMICK_TYPES_H
#define ALETHEIA_OV059_SP_POKE_GIMMICK_TYPES_H

/*
 * Special Pokemon field gimmick (overlay 59, sp_poke_gimmick.c). Two models
 * (side 0 and side 1) each carry three animations; script commands place a
 * model, move it along an arc, play its animations and wait for them. A third
 * model plays an effect and swaps one map object for another.
 */

/*
 * The expansion object types come from ov021/fld_exp_obj_types.h, which the
 * source file includes first (the compiler resolves includes against the
 * source file directory, so this header cannot include it). A file that does
 * not include it gets the few types it needs from the fallback below.
 */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;
#include "../sdk_fx.h"

typedef struct FldExpObjCnt FldExpObjCnt;
typedef struct FldExpObjAnime FldExpObjAnime;
typedef struct G3dUtilSetup G3dUtilSetup;
#endif

struct FieldMap;
struct GameSystem;
struct GameData;
struct GameEvent;

#include "../arm9/ica_anime_shared_types.h"

#define SP_POKE_GIMMICK_ANIME_COUNT 3

/* The effect model that plays while one map object is swapped for another. */
#define SP_POKE_GIMMICK_EFFECT_MODEL 2

/* Animation frames (fx32, 0x1000 per frame) the wait events stop at. */
#define SP_POKE_GIMMICK_SIDE0_WAIT_FRAME  0x5000
#define SP_POKE_GIMMICK_SIDE1_WAIT_FRAME  0x22000
#define SP_POKE_GIMMICK_SWAP_FRAME        0xF000

/* The common work of the gimmick on the field map (0x28 bytes, id 1). */
typedef struct SpPokeGimmickWork {
    int      side;          /* 0x00: model that is moved and waited for, 0 or 1 */
    VecFx32  moveFrom;      /* 0x04 */
    VecFx32  moveTo;        /* 0x10 */
    fx32     moveBump;      /* 0x1C: height of the arc over the middle of the move */
    u16      moveFrames;    /* 0x20: length of the move */
    u16      moveElapsed;   /* 0x22: frames moved so far */
    u16     *swapObjectIds; /* 0x24: allocated, [0] object removed, [1] object added */
} SpPokeGimmickWork;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
#include "../ov021/fld_exp_obj.h"

int SP_POKE_GIMMICK_SwapNpcEventMain(struct GameEvent *event, int *seq, void *work);

#endif
