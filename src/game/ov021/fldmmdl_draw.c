/*
 * file:     fldmmdl_draw.c
 * unit:     yes
 * function: func_0219F058, func_0219F0B0, func_0219F0F8, func_0219F114, func_0219F128, func_0219F17C, func_0219F188, func_0219F22C, func_0219F248, func_0219F25C, func_0219F2B0, func_0219F354, func_0219F3F0, func_0219F484, func_0219F490, func_0219F52C, func_0219F5C8, func_0219F5D4, func_0219F628, func_0219F634, func_0219F750, func_0219F7CC, func_0219F870, func_0219F8C8, func_0219F8E0, func_0219F8F4, func_0219F990, func_0219FAB4, func_0219FADC, func_0219FB20, func_0219FB2C, func_0219FB48, func_0219FB5C, func_0219FC5C, func_0219FC68, func_0219FCC0, func_0219FD1C, func_0219FD94, func_0219FE20, func_0219FE64, func_0219FE9C, func_0219FEB0, func_0219FFBC, func_0219FFD4, func_021A000C, func_021A006C, func_021A0084, func_021A00E0, func_021A00F4, func_021A00FC
 * address:  0x0219F058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_fog.c (CL110): ends at the field_fog.c __FILE__ anchor function 0x021A0104.
 *
 * Unanchored original between field_rail_loader.c (0x0219EF44) and
 * field_fog.c (0x021A0104): moving-model draw procedures (init, draw,
 * delete, push, pop, get-actor-id) over the fldmmdl_g3dobj and blact
 * objects. File name inferred from the fldmmdl module prefix.
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219C814  0x0219C814  thumb  ov021
 *   func_0219C8D4  0x0219C8D4  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   d_021D854C     0x021D854C  data  ov021  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_02188CBC  0x02188CBC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3080  0x021A3080  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_02013D9C  0x02013D9C  thumb
 *   func_020508EC  0x020508EC  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   data_021D8548  0x021D8548  data  ov021  a1
 *   func_02189A78  0x02189A78  thumb  ov021
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219D738  0x0219D738  thumb  ov021
 *   func_021642D4  0x021642D4  thumb  ov010
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0219C648  0x0219C648  thumb  ov021
 *   func_0219D634  0x0219D634  thumb  ov021
 *   func_0219D49C  0x0219D49C  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0219D680  0x0219D680  thumb  ov021
 */
#include "fldmmdl_blact_types.h"

struct FieldMap;
struct FieldCamera;
struct G3dCamera;
struct FieldG3dObjCtrl;

/* The four bytes at MmdlDrawWork.dirAnime: direction and animation state of
 * a billboard model. dir is 8 until the first update. */
typedef struct MmdlDirAnimeState {
    u8 dir;   /* last facing, 8 = none */
    u8 anime; /* last animation index */
    u8 frame; /* animation frame group while a turn blends (see UpdateDirAnime) */
    u8 wait;  /* one-frame delay before a turn into a still pose */
} MmdlDirAnimeState;

/* Draw procedure work of a moving model (8 bytes, 12 for the walk variant),
 * allocated with func_0216D6D8 and read back with func_0216D6F0. */
typedef struct MmdlDrawWork {
    u16 blactId;                 /* billboard actor slot, 0xFFFF = none */
    u8 state;
    u8 counter;
    MmdlDirAnimeState dirAnime;  /* the walking variant keeps other bytes here */
    u32 extra;
} MmdlDrawWork;

/* Frame groups to rest in after a turn (data_021D8548). */
typedef struct MmdlRestFrames {
    u8 frames[4];
} MmdlRestFrames;

extern MmdlObjCodeParam *func_0216E3C4(Mmdl *mmdl);
extern MmdlDrawWork *func_0216D6F0(Mmdl *mmdl);
extern BlactSys *func_0216D910(Mmdl *mmdl);
extern struct BbActSys *func_0219C9DC(BlactSys *cont);
extern u16 func_02050848(struct BbActSys *sys, int entryIndex);
extern u16 func_02050880(struct BbActSys *sys, int entryIndex);
extern void func_0205082C(struct BbActSys *sys, int entryIndex, u32 listIndex);
extern void func_0205085C(struct BbActSys *sys, int entryIndex, u32 cursor);
extern void *func_0216D6D8(Mmdl *mmdl, int size);
extern int func_0219C814(Mmdl *mmdl, u16 *outBlactId);
extern void func_0219C8D4(Mmdl *mmdl, u32 blactId);
extern void func_02197CCC(Mmdl *mmdl, VecFx32 *out);
extern struct BbBoard *func_02050080(struct BbActSys *sys);
extern void func_0204F638(struct BbBoard *board, int elem, VecFx32 *pos);
extern u16 func_0216D678(Mmdl *mmdl);
extern u16 func_0216D598(Mmdl *mmdl);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B0C(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *out);
extern void func_0207BCA0(VecFx32 *camPos, VecFx32 *camUp, VecFx32 *camTarget, s32 *outMtx43);
extern void func_02082B60(s32 *mtx43, s32 *outMtx33);
extern void func_0207B0A4(s32 *mtx33, s32 *outMtx33);
extern void func_0207B51C(VecFx32 *vec, s32 *mtx33, VecFx32 *out);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern struct FieldMap *func_0216D534(MmdlSys *sys);
extern struct FieldCamera *func_02188C58(struct FieldMap *fieldMap);
extern struct G3dCamera *func_0218EC2C(struct FieldCamera *camera);
extern void func_0207C9D0(VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern void func_0216D8B0(Mmdl *mmdl, VecFx32 *out);
extern s32 func_02197C9C(Mmdl *mmdl);
extern int func_0216D83C(Mmdl *mmdl);
extern u16 func_0216D590(Mmdl *mmdl);
extern u16 func_0216D588(Mmdl *mmdl);
extern int func_02188CBC(struct FieldMap *fieldMap);
extern void *func_02188CB4(struct FieldMap *fieldMap);
extern u32 func_021A3080(void *obj);
extern void func_0216D8C0(Mmdl *mmdl, VecFx32 *offset);
extern u32 func_02013D9C(u32 zoneId);
extern int func_0216D7A8(Mmdl *mmdl, unsigned int kind);
extern u32 func_020508EC(struct BbActSys *sys, int entryIndex, u16 *outLastCommand);
extern u32 func_02082BCC(void *p, u32 value, u32 size);
extern int func_02189A78(struct FieldMap *fieldMap);
extern u32 func_0216D538(MmdlSys *sys);
extern int func_0216D55C(Mmdl *mmdl, int bits);
extern u32 func_0219D738(Mmdl *mmdl, int angle);
extern u8 func_021642D4(int tableIndex, int offset);
extern int func_0219C648(Mmdl *mmdl);
extern int func_0216DAB4(Mmdl *mmdl);
extern void func_020507F0(struct BbActSys *sys, int entryIndex, u32 enabled);
extern int func_020507A0(struct BbActSys *sys, int entryIndex, u32 flags);
extern u32 func_0219D634(Mmdl *mmdl);
extern struct FieldG3dObjCtrl *func_0219D49C(Mmdl *mmdl);
extern void func_021C6664(struct FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos);
extern void func_021C6678(struct FieldG3dObjCtrl *ctrl, int objIdx, int hidden);
extern int func_021C66EC(struct FieldG3dObjCtrl *ctrl, int objIdx, int speed);
extern void func_0219D680(Mmdl *mmdl, u32 objIdx);

void func_0219F5D4(struct G3dCamera *camera, VecFx32 *vec, VecFx32 *out);
int func_0219F628(Mmdl *mmdl, u32 listIndex, u32 cursor, VecFx32 *out);
void func_0219F990(Mmdl *mmdl, MmdlDrawWork *work, u8 dir);
void func_0219FAB4(Mmdl *mmdl, u32 dir, MmdlObjCodeParam *param, VecFx32 *offset);
int func_0219FADC(MmdlDrawWork *work, int dir, MmdlObjCodeParam *param);
int func_0219FE9C(MmdlDirAnimeState *state);
void func_0219FEB0(MmdlDirAnimeState *state, Mmdl *mmdl, struct BbActSys *bbActSys, u16 blactId);
void func_0219FFBC(Mmdl *mmdl, VecFx32 *pos);
u32 func_0219FFD4(Mmdl *mmdl);
void func_021A000C(Mmdl *mmdl, struct BbActSys *bbActSys, u32 blactId, u32 isUpdated, u32 checkMode);
void func_021A006C(Mmdl *mmdl);
void func_021A00E0(Mmdl *mmdl);
extern const VecFx32 d_021D854C;
extern const MmdlRestFrames data_021D8548;

/* Reads the animation list index and cursor of the billboard actor of a model
 * (0 and 0 when the model is not a billboard or has no actor). */
void func_0219F058(Mmdl *mmdl, u16 *outAnime, u16 *outFrame)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    if (func_0216E3C4(mmdl)->drawType == 1) {
        work = func_0216D6F0(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = func_0219C9DC(func_0216D910(mmdl));
            *outAnime = func_02050848(bbActSys, work->blactId);
            *outFrame = func_02050880(bbActSys, work->blactId);
        } else {
            *outAnime = 0;
            *outFrame = 0;
        }
    } else {
        *outAnime = 0;
        *outFrame = 0;
    }
}

void func_0219F0B0(Mmdl *mmdl, u32 listIndex, u32 cursor)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    if (func_0216E3C4(mmdl)->drawType == 1) {
        work = func_0216D6F0(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = func_0219C9DC(func_0216D910(mmdl));
            func_0205082C(bbActSys, work->blactId, listIndex);
            func_0205085C(bbActSys, work->blactId, cursor);
        }
    }
}

/* Draw procedure init: reserves the work and registers the billboard actor. */
void func_0219F0F8(Mmdl *mmdl)
{
    MmdlDrawWork *work = func_0216D6D8(mmdl, 8);
    func_0219FE9C(&work->dirAnime);
    func_0219C814(mmdl, &work->blactId);
}

/* Draw procedure remove: releases the billboard actor. */
void func_0219F114(Mmdl *mmdl, u32 kind)
{
    func_0219C8D4(mmdl, func_0216D6F0(mmdl)->blactId);
}

/* Draw procedure draw: direction and animation state, then the position. */
void func_0219F128(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        func_0219FEB0(&work->dirAnime, mmdl, bbActSys, work->blactId);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Draw procedure getParam: the billboard actor id. */
int func_0219F17C(Mmdl *mmdl, u32 kind)
{
    return func_0216D6F0(mmdl)->blactId;
}

void func_0219F188(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 isUpdated;
    struct BbActSys *bbActSys;
    u32 dirIndex;
    u32 anime;
    isUpdated = 0;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        dirIndex = func_0219FFD4(mmdl);
        anime = func_0216D678(mmdl);
        if (work->dirAnime.dir != dirIndex) {
            work->dirAnime.dir = dirIndex;
            work->dirAnime.anime = anime;
            func_0205082C(bbActSys, work->blactId, dirIndex);
            isUpdated = 1;
        } else if (work->dirAnime.anime != anime) {
            func_0205082C(bbActSys, work->blactId, dirIndex);
            func_0205085C(bbActSys, work->blactId, isUpdated);
            work->dirAnime.anime = anime;
        }
        func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

void func_0219F22C(Mmdl *mmdl)
{
    MmdlDrawWork *work = func_0216D6D8(mmdl, 8);
    func_0219FE9C(&work->dirAnime);
    func_0219C814(mmdl, &work->blactId);
}

void func_0219F248(Mmdl *mmdl, u32 kind)
{
    func_0219C8D4(mmdl, func_0216D6F0(mmdl)->blactId);
}

void func_0219F25C(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        func_0219FEB0(&work->dirAnime, mmdl, bbActSys, work->blactId);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Direction frames at an offset that depends on the draw procedure number. */
void func_0219F2B0(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 isUpdated;
    struct BbActSys *bbActSys;
    u32 isSpecialCode;
    u32 dirIndex;
    u32 frameBase;
    u32 frame;
    isUpdated = 0;
    isSpecialCode = 0;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        dirIndex = func_0219FFD4(mmdl);
        if (func_0216D598(mmdl) == 0xCC) {
            isSpecialCode = 1;
        }
        frameBase = func_0216E3C4(mmdl)->drawProcNo;
        if (frameBase == 0xF) {
            frameBase = 4;
        } else if (frameBase == 5) {
            frameBase = 8;
        } else {
            frameBase = 0x10;
        }
        frame = (u16)(frameBase + dirIndex);
        if (work->dirAnime.dir != dirIndex) {
            work->dirAnime.dir = dirIndex;
            func_0205082C(bbActSys, work->blactId, frame);
            isUpdated = 1;
        }
        func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, isSpecialCode);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Walk animations (anime 10 and up) use list index anime + 30; lower ones use the direction state machine. */
void func_0219F354(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 anime;
    u32 dirIndex;
    u8 isUpdated;
    VecFx32 drawPos;

    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        anime = func_0216D678(mmdl);
        if (anime >= 10) {
            isUpdated = 0;
            dirIndex = func_0219FFD4(mmdl);
            if (anime != work->dirAnime.anime) {
                isUpdated = 1;
                work->dirAnime.dir = dirIndex;
                work->dirAnime.anime = anime;
                work->dirAnime.frame = 0;
                func_0205082C(bbActSys, work->blactId, (u16)(anime + 30));
            }
            func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, 0);
        } else {
            func_0219FEB0(&work->dirAnime, mmdl, bbActSys, work->blactId);
        }
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Like func_0219F354, but the update flag is always set. */
void func_0219F3F0(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 anime;
    u32 dirIndex;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        anime = func_0216D678(mmdl);
        if (anime >= 10) {
            dirIndex = func_0219FFD4(mmdl);
            if (anime != work->dirAnime.anime) {
                work->dirAnime.dir = dirIndex;
                work->dirAnime.anime = anime;
                work->dirAnime.frame = 0;
                func_0205082C(bbActSys, work->blactId, (u16)(anime + 0x1e));
            }
            func_021A000C(mmdl, bbActSys, work->blactId, 1, 0);
        } else {
            func_0219FEB0(&work->dirAnime, mmdl, bbActSys, work->blactId);
        }
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

int func_0219F484(Mmdl *mmdl, u32 kind)
{
    return func_0216D6F0(mmdl)->blactId;
}

/* Two-frame model: anime 0 or 1 selects the list index; larger values fall back to 0. */
void func_0219F490(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 anime;
    struct BbActSys *bbActSys;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        anime = func_0216D678(mmdl);
        if (work->dirAnime.anime >= 2) {
            work->dirAnime.anime = 0;
            func_0205082C(bbActSys, work->blactId, work->dirAnime.anime);
            func_0205085C(bbActSys, work->blactId, 0);
        }
        if (anime < 2 && work->dirAnime.anime != anime) {
            work->dirAnime.anime = anime;
            func_0205082C(bbActSys, work->blactId, work->dirAnime.anime);
            func_0205085C(bbActSys, work->blactId, 0);
        }
        func_021A000C(mmdl, bbActSys, work->blactId, 0, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Three-frame model: same as func_0219F490 with anime 0 to 2. */
void func_0219F52C(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 anime;
    struct BbActSys *bbActSys;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        anime = func_0216D678(mmdl);
        if (work->dirAnime.anime >= 3) {
            work->dirAnime.anime = 0;
            func_0205082C(bbActSys, work->blactId, work->dirAnime.anime);
            func_0205085C(bbActSys, work->blactId, 0);
        }
        if (anime < 3 && work->dirAnime.anime != anime) {
            work->dirAnime.anime = anime;
            func_0205082C(bbActSys, work->blactId, work->dirAnime.anime);
            func_0205085C(bbActSys, work->blactId, 0);
        }
        func_021A000C(mmdl, bbActSys, work->blactId, 0, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

void func_0219F5C8(Mmdl *mmdl, int state)
{
    func_0216D6F0(mmdl)->state = state;
}

/* Rotates vec by the inverse of the view rotation of the camera, into out. */
void func_0219F5D4(struct G3dCamera *camera, VecFx32 *vec, VecFx32 *out)
{
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 camTarget;
    s32 viewMtx43[12];
    s32 viewMtx33[9];
    func_02048AE8(camera, &camPos);
    func_02048B0C(camera, &camUp);
    func_02048B30(camera, &camTarget);
    func_0207BCA0(&camPos, &camUp, &camTarget, viewMtx43);
    func_02082B60(viewMtx43, viewMtx33);
    func_0207B0A4(viewMtx33, viewMtx33);
    func_0207B51C(vec, viewMtx33, out);
}

/* Draw procedure frame offset: none. */
int func_0219F628(Mmdl *mmdl, u32 listIndex, u32 cursor, VecFx32 *out)
{
    out->x = 0;
    out->y = 0;
    out->z = 0;
    return 0;
}

/* Billboard with an offset per frame: rotated by the camera (state 0) or fixed. */
void func_0219F634(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 dirIndex;
    u32 anime;
    u16 listIndex;
    VecFx32 pos;
    VecFx32 frameOffset;
    VecFx32 rotated;
    u32 isUpdated;
    u32 curListIndex;

    isUpdated = 0;
    work = func_0216D6F0(mmdl);
    if (work->blactId == 0xFFFF) {
        return;
    }
    bbActSys = func_0219C9DC(func_0216D910(mmdl));
    dirIndex = func_0219FFD4(mmdl);
    anime = func_0216D678(mmdl);
    listIndex = dirIndex + anime * 4;
    if (dirIndex != work->dirAnime.dir || work->dirAnime.anime != anime) {
        work->dirAnime.dir = dirIndex;
        isUpdated = 1;
        work->dirAnime.anime = anime;
        func_0205082C(bbActSys, work->blactId, listIndex);
        func_0205085C(bbActSys, work->blactId, 0);
    }
    func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, 1);
    func_02197CCC(mmdl, &pos);
    func_0219FFBC(mmdl, &pos);
    curListIndex = func_02050848(bbActSys, work->blactId);
    func_0219F628(mmdl, curListIndex, func_02050880(bbActSys, work->blactId), &frameOffset);
    pos.x += frameOffset.x;
    pos.y += frameOffset.y;
    pos.z += frameOffset.z;
    if (work->state == 0) {
        rotated = d_021D854C;
        func_0219F5D4(func_0218EC2C(func_02188C58(func_0216D534(func_0216D67C(mmdl)))), &rotated, &rotated);
        func_0207C9D0(&pos, &rotated, &pos);
    } else {
        pos.y -= 0xC000;
        pos.z += 0x8000;
    }
    func_0204F638(func_02050080(bbActSys), work->blactId, &pos);
}

/* Static model: direction frame only. */
void func_0219F750(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;
    u32 dirIndex;

    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        dirIndex = func_0219FFD4(mmdl);
        if (work->dirAnime.dir != dirIndex) {
            func_0205082C(bbActSys, work->blactId, dirIndex);
            func_0205085C(bbActSys, work->blactId, 0);
            work->dirAnime.dir = dirIndex;
        }
        func_021A000C(mmdl, bbActSys, work->blactId, 0, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Maps an animation command index to one of 13 groups; rewinds the cursor when the actor is in another group. */
int func_0219F7CC(Mmdl *mmdl, u32 command)
{
    u32 group;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 curGroup;

    work = func_0216D6F0(mmdl);
    if (work->blactId == 0xFFFF) {
        return 0;
    }
    if (command < 0x18) {
        if (command < 6) group = 0;
        else if (command < 0xC) group = 1;
        else if (command < 0x12) group = 2;
        else group = 3;
    } else if (command < 0x28) {
        if (command < 0x1C) group = 4;
        else if (command < 0x20) group = 5;
        else if (command < 0x24) group = 6;
        else group = 7;
    } else if (command < 0x30) {
        if (command < 0x2A) group = 8;
        else if (command < 0x2C) group = 9;
        else if (command < 0x2E) group = 10;
        else group = 11;
    } else {
        group = 12;
    }
    bbActSys = func_0219C9DC(func_0216D910(mmdl));
    curGroup = func_02050880(bbActSys, work->blactId);
    if (curGroup != group) {
        func_0205085C(bbActSys, work->blactId, 0);
    }
    return 1;
}

/* Position update only, no animation change. */
void func_0219F870(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;

    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        func_021A000C(mmdl, bbActSys, work->blactId, 0, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

void func_0219F8C8(Mmdl *mmdl)
{
    MmdlDrawWork *work = func_0216D6D8(mmdl, 8);
    work->state = 9;
    func_0219C814(mmdl, &work->blactId);
}

void func_0219F8E0(Mmdl *mmdl, u32 kind)
{
    func_0219C8D4(mmdl, func_0216D6F0(mmdl)->blactId);
}

/* Walking model: the state follows the direction; func_0219F990 moves the draw offset. */
void func_0219F8F4(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    u8 isUpdated;
    struct BbActSys *bbActSys;
    u32 dir;
    VecFx32 drawPos;
    s32 offsetBuf[3]; /* read through a VecFx32 pointer: the bytes need the address in a register */

    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        isUpdated = 0;
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        dir = func_0216D5F8(mmdl);
        if (dir != work->state) {
            isUpdated = 1;
            work->state = dir;
            work->counter = 0;
            work->extra = 0;
            func_0205082C(bbActSys, work->blactId, work->state);
            {
                VecFx32 *clear = (VecFx32 *)offsetBuf;
                clear->x = 0;
                clear->y = 0;
                clear->z = 0;
                func_0216D8B0(mmdl, clear);
            }
        }
        func_0219F990(mmdl, work, dir);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
        func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, 0);
    }
}

/* Bobbing and sideways offset of a walking model, written to the draw offset of the model. */
void func_0219F990(Mmdl *mmdl, MmdlDrawWork *work, u8 dir)
{
    VecFx32 offset;
    VecFx32 curOffset;
    struct FieldMap *fieldMap;
    s32 isAnimePaused;
    u32 zoneId;
    s32 gridX;
    MmdlObjCodeParam *param;
    int isHidden;
    int canBob;
    int isPlayer;
    u32 objId;
    u8 gridMod;
    void *mapObj;

    canBob = 1;
    param = func_0216E3C4(mmdl);
    isPlayer = 0;
    offset.x = 0;
    offset.y = 0;
    offset.z = 0;
    isAnimePaused = func_02197C9C(mmdl);
    func_0216D8B0(mmdl, &curOffset);
    gridX = func_0216D83C(mmdl);
    zoneId = func_0216D590(mmdl);
    objId = func_0216D588(mmdl);
    if (objId == 0xff)
        isPlayer = canBob;
    isHidden = (objId == 0xfc) ? 1 : 0;
    if (isPlayer != 0) {
        fieldMap = func_0216D534(func_0216D67C(mmdl));
        if (func_02188CBC(fieldMap) != 0 && (mapObj = func_02188CB4(fieldMap)) != 0) {
            canBob = func_021A3080(mapObj) != 0;
        }
    }
    if (isAnimePaused != 0 || (curOffset.y > 0x1800 && param->drawProcNo != 11)) {
        offset.y = curOffset.y;
    } else if (func_0219FADC(work, dir, param) == 0 && canBob != 0) {
        offset.y = offset.y + 0x1800;
    }
    if (func_02013D9C(zoneId) != 0 && isPlayer == 0) {
        gridMod = gridX % 3;
        if (gridMod == 0)
            offset.z = offset.z - 0x219a;
        else if (gridMod == 2)
            offset.z = offset.z + 0x219a;
        offset.z = offset.z - 0x2000;
    }
    func_0219FAB4(mmdl, dir, param, &offset);
    if (isHidden) {
        offset.x = 0;
        offset.y = 0;
        offset.z = 0;
    }
    func_0216D8C0(mmdl, &offset);
    work->counter++;
}

/* Shifts the x offset by 0x2000 for directions 2 and 3 of a model with size class 0. */
void func_0219FAB4(Mmdl *mmdl, u32 dir, MmdlObjCodeParam *param, VecFx32 *offset)
{
    if (param->mdlSize == 0) {
        switch (dir) {
        case 2:
            offset->x -= 0x2000;
            break;
        case 3:
            offset->x += 0x2000;
            break;
        }
    }
}

/* Advances the 20-frame step counter; true while the model is in a lifted step phase. */
int func_0219FADC(MmdlDrawWork *work, int dir, MmdlObjCodeParam *param)
{
    int phase = work->counter % 20;
    u8 drawProcNo = param->drawProcNo;
    work->counter = phase;
    if (drawProcNo == 11) {
        if (dir == 1) {
            if (phase < 5 || phase >= 15)
                return 1;
        } else {
            if (phase < 10)
                return 1;
        }
    } else {
        if ((phase >= 5 && phase < 10) || phase >= 15)
            return 1;
    }
    return 0;
}

int func_0219FB20(Mmdl *mmdl, u32 kind)
{
    return func_0216D6F0(mmdl)->blactId;
}

void func_0219FB2C(Mmdl *mmdl)
{
    MmdlDrawWork *work = func_0216D6D8(mmdl, 8);
    func_0219FE9C(&work->dirAnime);
    func_0219C814(mmdl, &work->blactId);
}

void func_0219FB48(Mmdl *mmdl, u32 kind)
{
    func_0219C8D4(mmdl, func_0216D6F0(mmdl)->blactId);
}

/* Models with several animation patterns, chosen by object code (0xD3 to 0xD6, 0x79). */
void func_0219FB5C(Mmdl *mmdl)
{
    VecFx32 drawPos;
    u32 isUpdated;
    struct BbActSys *bbActSys;
    u32 anime;
    MmdlDrawWork *work;
    u32 objCode;
    u32 dirIndex;
    u32 frame;

    isUpdated = 0;
    work = func_0216D6F0(mmdl);
    if (work->blactId == 0xFFFF)
        return;
    bbActSys = func_0219C9DC(func_0216D910(mmdl));
    objCode = func_0216D598(mmdl);
    anime = func_0216D678(mmdl);
    if (objCode == 0xd3 || objCode == 0xd5 || objCode == 0x79) {
        frame = 0;
        if (anime == work->dirAnime.anime)
            goto draw;
        switch (anime) {
        case 10:
            frame = 1;
            break;
        case 11:
            frame = 2;
            break;
        case 12:
            frame = 3;
            break;
        }
        work->dirAnime.anime = anime;
        func_0205082C(bbActSys, work->blactId, frame);
        isUpdated = 1;
    } else if (objCode == 0xd4 || objCode == 0xd6) {
        dirIndex = func_0219FFD4(mmdl);
        frame = 0;
        if (anime < 10) {
            if (dirIndex == work->dirAnime.dir && anime == work->dirAnime.anime)
                goto draw;
            if (dirIndex == 0)
                frame = 0;
            else if (dirIndex == 1)
                frame = 1;
            work->dirAnime.dir = dirIndex;
        } else {
            if (anime == work->dirAnime.anime)
                goto draw;
            switch (anime) {
            case 10:
                frame = 2;
                break;
            case 11:
                frame = 3;
                break;
            }
        }
        work->dirAnime.anime = anime;
        func_0205082C(bbActSys, work->blactId, frame);
        isUpdated = 1;
    } else {
        if (anime == work->dirAnime.anime)
            goto draw;
        work->dirAnime.anime = anime;
        func_0205082C(bbActSys, work->blactId, isUpdated);
        isUpdated = 1;
    }
draw:
    func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, 1);
    func_02197CCC(mmdl, &drawPos);
    func_0219FFBC(mmdl, &drawPos);
    func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
}

int func_0219FC5C(Mmdl *mmdl, u32 kind)
{
    return func_0216D6F0(mmdl)->blactId;
}

/* Reads list index and cursor for object codes 0xD3 and 0xD5; other codes report 0 and 0. Returns 0 without an actor. */
int func_0219FC68(Mmdl *mmdl, u16 *outAnime, u16 *outFrame)
{
    u32 objCode;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;

    objCode = func_0216D598(mmdl);
    if (objCode == 0xD3 || objCode == 0xD5) {
        work = func_0216D6F0(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = func_0219C9DC(func_0216D910(mmdl));
            *outAnime = func_02050848(bbActSys, work->blactId);
            *outFrame = func_02050880(bbActSys, work->blactId);
            return 1;
        }
        return 0;
    }
    *outAnime = 0;
    *outFrame = 0;
    return 1;
}

/* Same as func_0219FC68 for object codes 0xDD and 0xDE. */
int func_0219FCC0(Mmdl *mmdl, u16 *outAnime, u16 *outFrame)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;

    if ((u16)(func_0216D598(mmdl) + 0xFF23) <= 1) {
        work = func_0216D6F0(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = func_0219C9DC(func_0216D910(mmdl));
            *outAnime = func_02050848(bbActSys, work->blactId);
            *outFrame = func_02050880(bbActSys, work->blactId);
            return 1;
        }
        return 0;
    }
    *outAnime = 0;
    *outFrame = 0;
    return 1;
}

/* Two-pattern model: list index follows anime 0 or 1. */
void func_0219FD1C(Mmdl *mmdl)
{
    u32 isUpdated;
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;
    u32 anime;

    isUpdated = 0;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        anime = func_0216D678(mmdl);
        if (anime != work->dirAnime.anime && anime < 2) {
            work->dirAnime.anime = anime;
            func_0205082C(bbActSys, work->blactId, anime);
            isUpdated = 1;
        }
        func_021A000C(mmdl, bbActSys, work->blactId, isUpdated, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Three-pattern model: anime 10 to 12 select list index 1 to 3. */
void func_0219FD94(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;
    u32 anime;
    u32 frameOrUpdated; /* list index while switching, then the update flag */

    frameOrUpdated = 0;
    work = func_0216D6F0(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = func_0219C9DC(func_0216D910(mmdl));
        anime = func_0216D678(mmdl);
        if (anime != work->dirAnime.anime) {
            switch (anime) {
            case 10: frameOrUpdated = 1; break;
            case 11: frameOrUpdated = 2; break;
            case 12: frameOrUpdated = 3; break;
            }
            work->dirAnime.anime = anime;
            func_0205082C(bbActSys, work->blactId, frameOrUpdated);
            frameOrUpdated = 1;
        }
        func_021A000C(mmdl, bbActSys, work->blactId, frameOrUpdated, 0);
        func_02197CCC(mmdl, &drawPos);
        func_0219FFBC(mmdl, &drawPos);
        func_0204F638(func_02050080(bbActSys), work->blactId, &drawPos);
    }
}

/* Object code 0x7B: true when the model has no actor entry or the last command of the entry is in range. */
u32 func_0219FE20(Mmdl *mmdl, u32 kind)
{
    u32 blactId;
    u16 lastCommand;

    if (func_0216D598(mmdl) != 0x7B) {
        return 1;
    }
    blactId = (u16)func_0216D7A8(mmdl, 0);
    if (blactId != 0xFFFF) {
        if (func_020508EC(func_0219C9DC(func_0216D910(mmdl)), blactId, &lastCommand) == 1) {
            return 1;
        }
    }
    return 0;
}

/* Object code 0x7B: rewinds the animation cursor of the actor. */
void func_0219FE64(Mmdl *mmdl)
{
    u16 blactId;
    u16 zero;
    if (func_0216D598(mmdl) == 0x7B) {
        zero = 0;
        blactId = func_0216D7A8(mmdl, 0);
        if (blactId != 0xFFFF) {
            func_0205085C(func_0219C9DC(func_0216D910(mmdl)), blactId, zero);
        }
    }
}

/* Clears the direction state and sets the direction to 8 (none). */
int func_0219FE9C(MmdlDirAnimeState *state)
{
    func_02082BCC(state, 0, 4);
    state->dir = 8;
    return 8;
}

/* Direction and animation state machine of billboard models: picks the list index (dir + anime * 4)
 * and blends turns through a rest frame group. */
void func_0219FEB0(MmdlDirAnimeState *state, Mmdl *mmdl, struct BbActSys *bbActSys, u16 blactId)
{
    MmdlRestFrames restFrames;
    u32 isUpdated;
    u16 listIndex;
    u32 dirIndex;
    u32 anime;

    isUpdated = 0;
    dirIndex = func_0219FFD4(mmdl);
    anime = func_0216D678(mmdl);
    listIndex = dirIndex + anime * 4;
    if (state->wait != 0 && anime == state->anime)
        state->wait = isUpdated;
    if (dirIndex != state->dir) {
        isUpdated = 1;
        state->anime = anime;
        state->dir = dirIndex;
        state->frame = 0;
        func_0205082C(bbActSys, blactId, listIndex);
    } else if (anime != state->anime) {
        isUpdated = 1;
        if (anime == 0) {
            if (state->anime == 0) {
                func_0205082C(bbActSys, blactId, listIndex);
                state->anime = anime;
                state->wait = 0;
            } else {
                if (state->wait == 0) {
                    state->wait++;
                    isUpdated = 0;
                    goto update;
                }
                restFrames = data_021D8548;
                state->frame = func_02050880(bbActSys, blactId);
                if (state->frame >= 4)
                    state->frame = 0;
                state->frame = restFrames.frames[state->frame];
                func_0205082C(bbActSys, blactId, listIndex);
                state->anime = anime;
                state->wait = 0;
            }
        } else {
            if (state->anime != 0) {
                state->frame = func_02050880(bbActSys, blactId);
                state->frame = (state->frame >= 2) ? 0 : 2;
            }
            func_0205082C(bbActSys, blactId, listIndex);
            func_0205085C(bbActSys, blactId, state->frame);
            state->anime = anime;
            state->wait = 0;
        }
    }
update:
    func_021A000C(mmdl, bbActSys, blactId, isUpdated, 0);
}

/* Adds the height offset of the field map to the draw position. */
void func_0219FFBC(Mmdl *mmdl, VecFx32 *pos)
{
    pos->y += func_02189A78(func_0216D534(func_0216D67C(mmdl)));
}

/* Display direction as a table index. The matched bytes leave the result of the
 * called function in r0 and have no return statement. */
u32 func_0219FFD4(Mmdl *mmdl){
    u32 viewAngle = func_0216D538(func_0216D67C(mmdl));
    u32 dirDisp = func_0216D5F8(mmdl);
    if (func_0216D55C(mmdl, 0x2000))
        func_0219D738(mmdl, viewAngle);
    else
        func_021642D4(dirDisp, viewAngle);
}

/* Sets animation enable and visibility of the actor from the state of the model. */
void func_021A000C(Mmdl *mmdl, struct BbActSys *bbActSys, u32 blactId, u32 isUpdated, u32 checkMode)
{
    u32 enable;
    u32 entryHookFlag;

    enable = 1;
    entryHookFlag = func_0219C648(mmdl);
    if (isUpdated == 0) {
        if (checkMode == 1) {
            if (entryHookFlag == 1 && func_0216D55C(mmdl, 0x10) != 0) enable = 0;
        } else {
            if (entryHookFlag == 1 && func_02197C9C(mmdl) == 1) enable = 0;
        }
    }
    func_020507F0(bbActSys, blactId, enable);
    enable = 1;
    if (func_0216DAB4(mmdl) == 1) enable = 0;
    func_020507A0(bbActSys, blactId, enable);
}

/* G3D object draw procedure init. */
void func_021A006C(Mmdl *mmdl)
{
    MmdlDrawWork *work = func_0216D6D8(mmdl, 2);
    work->blactId = func_0219D634(mmdl);
}

/* G3D object draw procedure draw: position, visibility and animation step. */
void func_021A0084(Mmdl *mmdl)
{
    u32 hidden;
    struct FieldG3dObjCtrl *g3dObjCtrl;
    VecFx32 drawPos;
    MmdlDrawWork *work;

    work = func_0216D6F0(mmdl);
    g3dObjCtrl = func_0219D49C(mmdl);
    func_02197CCC(mmdl, &drawPos);
    func_021C6664(g3dObjCtrl, work->blactId, &drawPos);
    hidden = 0;
    if (func_0216DAB4(mmdl) == 1) hidden = 1;
    func_021C6678(g3dObjCtrl, work->blactId, hidden);
    if (func_02197C9C(mmdl) == 0) {
        func_021C66EC(g3dObjCtrl, work->blactId, 0x1000);
    }
}

/* G3D object draw procedure remove. */
void func_021A00E0(Mmdl *mmdl)
{
    func_0219D680(mmdl, func_0216D6F0(mmdl)->blactId);
}

void func_021A00F4(Mmdl *mmdl) { func_021A00E0(mmdl); }

void func_021A00FC(Mmdl *mmdl) { func_021A006C(mmdl); }
