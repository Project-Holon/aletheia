/*
 * file:     fieldmap_ctrl_hybrid.c
 * unit:     yes
 * function: func_021A6DC0, func_021A6DC4, func_021A6E30, func_021A6F18, func_021A6F24, func_021A6F4C, func_021A6F5C, func_021A7010, func_021A70D0, func_021A712C, func_021A7198, func_021A71E4, func_021A7258
 * address:  0x021A6DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A6F14 (d_021DDF64 "fieldmap_ctrl_hybrid.c"); 021A6DC0..021A6DC4 read the same holder (mode f0, core at +4) that 021A6F24 uses.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C5C  0x02188C5C  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   func_02012AC0  0x02012AC0  thumb
 *   func_0219F058  0x0219F058  thumb  ov021
 *   d_021DDF64     0x021DDF64  data  a1
 *   d_021DDF38  0x021DDF38  data  a4
 *   func_021BB1A0  0x021BB1A0  thumb  ov021
 *   func_021B7A84  0x021B7A84  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_021BB3B8  0x021BB3B8  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218E160  0x0218E160  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0219F0B0  0x0219F0B0  thumb  ov021
 *   func_021A2FA4  0x021A2FA4  thumb  ov021
 *   func_021A2FB0  0x021A2FB0  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021A35BC  0x021A35BC  thumb  ov021
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_021A35F0  0x021A35F0  thumb  ov021
 *   func_021A3664  0x021A3664  thumb  ov021
 *   func_021A3674  0x021A3674  thumb  ov021
 *   func_021A3680  0x021A3680  thumb  ov021
 *   func_021A368C  0x021A368C  thumb  ov021
 *   func_021A3698  0x021A3698  thumb  ov021
 *   func_021A36A4  0x021A36A4  thumb  ov021
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;

struct FieldPlayer;
struct FieldNogridMapper;
struct FieldG3dMapper;
struct FieldCamera;
struct RailManager;
struct Mmdl;

/* Which movement system the player uses right now. */
enum {
    FIELDMAP_CTRL_HYBRID_MODE_GRID,     /* walks on the tile grid */
    FIELDMAP_CTRL_HYBRID_MODE_NOGRID,   /* moves along the rails */
    FIELDMAP_CTRL_HYBRID_MODE_NONE      /* not placed yet (right after the allocation) */
};

/* The hybrid map control work (12 bytes), kept in FieldMap.ctrlWork. */
typedef struct FieldMapCtrlHybridWork {
    int mode;                       /* 0x00 FIELDMAP_CTRL_HYBRID_MODE_* */
    struct FieldPlayer *player;     /* 0x04 */
    u32 stepActive;                 /* 0x08: result of the last nogrid step start, 0 after a mode switch */
} FieldMapCtrlHybridWork;

/* Parameter block that func_0216E0AC applies to a field model. */
typedef struct FieldMapCtrlHybridModelParam {
    u8 kind;            /* 0x00 */
    u8 flags;           /* 0x01 */
    u16 objCode;        /* 0x02: refreshed from the model on every switch to grid mode */
} FieldMapCtrlHybridModelParam;

/*
 * One static record: the per-mode update functions (indexed by the work's
 * mode), then the model parameter block.
 */
typedef struct FieldMapCtrlHybridModeTable {
    void (*update[2])(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);    /* 0x00 */
    FieldMapCtrlHybridModelParam modelParam;                                /* 0x08 */
} FieldMapCtrlHybridModeTable;

extern u32 func_020307B0(void *memory);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u16 func_02188C84(FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern void func_02188CAC(FieldMap *fieldMap, void *ctrlWork);
extern void *func_02188CA4(FieldMap *fieldMap);
extern void func_02188D40(FieldMap *fieldMap, VecFx32 *targetPos);
extern struct FieldCamera *func_02188C58(FieldMap *fieldMap);
extern struct FieldNogridMapper *func_02188C5C(FieldMap *fieldMap);
extern void *func_02188C80(FieldMap *fieldMap);
extern struct FieldG3dMapper *func_02188C98(FieldMap *fieldMap);
extern void *func_020120F4(void *gameSystem);
extern void *func_020127A4(void *gameData);
extern void *func_02012AB8(void *saveRecord);
extern u8 func_02012AC0(void *saveRecord);
extern u8 func_0201441C(int dir);
extern void func_02164208(int dir, VecFx32 *vec, int amount);
extern VecFx32 *func_0216D888(struct Mmdl *mmdl);
extern void func_0216D88C(struct Mmdl *mmdl, VecFx32 *outPos);
extern int func_0216D3CC(struct Mmdl *mmdl);
extern void *func_0216D4B4(struct Mmdl *mmdl);
extern u16 func_0216D598(struct Mmdl *mmdl);
extern u16 func_0216D5F8(struct Mmdl *mmdl);
extern void func_0216D5E0(struct Mmdl *mmdl, int dir);
extern int func_0216D600(struct Mmdl *mmdl, u16 dir);
extern u16 func_0216D608(struct Mmdl *mmdl);
extern int func_0216DC4C(struct Mmdl *mmdl);
extern void func_0216E084(struct Mmdl *mmdl, unsigned int gridX, unsigned int gridY, unsigned int gridZ, u16 dir);
extern void func_0216E0AC(struct Mmdl *mmdl, FieldMapCtrlHybridModelParam *param);
extern void func_0218E13C(struct FieldCamera *camera, u32 mode);
extern int func_0218EC60(struct FieldCamera *camera);
extern int func_0218E160(struct FieldCamera *camera);
extern void func_0218F05C(struct FieldCamera *camera);
extern void func_0219F058(struct Mmdl *mmdl, u16 *outAnime, u16 *outFrame);
extern void func_0219F0B0(struct Mmdl *mmdl, u32 anime, u32 frame);
extern int func_021AB0D4(struct FieldG3dMapper *mapper, VecFx32 *pos);
extern int func_021AB11C(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern int func_021B7A84(struct RailManager *manager, VecFx32 *startPos, VecFx32 *endPos, RailLocation *outLocation, VecFx32 *outPos);
extern int func_021B7CD8(struct RailManager *manager, RailLocation *location, u8 key, RailLocation *outLocation);
extern int func_021BB1A0(int attr);
extern void func_021BB3AC(struct FieldNogridMapper *mapper, u32 railWork);
extern void func_021BB3B8(struct FieldNogridMapper *mapper);
extern struct RailManager *func_021BB480(struct FieldNogridMapper *mapper);
extern u16 func_021A2FA4(struct FieldPlayer *player, u32 keyCont);
extern u32 func_021A2FB0(struct FieldPlayer *player);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *outPos);
extern void func_021A3044(struct FieldPlayer *player, VecFx32 *pos);
extern void func_021A305C(struct FieldPlayer *player, u32 dir);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern u32 func_021A30C8(struct FieldPlayer *player);
extern u32 func_021A3128(struct FieldPlayer *player, u32 dir);
extern int func_021A35BC(struct FieldPlayer *player);
extern void func_021A35E0(struct FieldPlayer *player, u32 heapId);
extern void func_021A35F0(struct FieldPlayer *player, u32 keyTrg, u32 keyCont, u32 flags);
extern void func_021A3664(struct FieldPlayer *player, u32 heapId);
extern void func_021A3674(struct FieldPlayer *player, u32 keyTrg, u32 keyCont);
extern void func_021A3680(struct FieldPlayer *player, const void *place);
extern void func_021A368C(struct FieldPlayer *player);
extern u32 func_021A3698(struct FieldPlayer *player);
extern u32 func_021A36A4(struct FieldPlayer *player);
extern char d_021DDF64;
extern FieldMapCtrlHybridModeTable d_021DDF38;

u32 func_021A6DC0(FieldMapCtrlHybridWork *work);
void func_021A6DC4(FieldMapCtrlHybridWork *work, FieldMap *fieldMap);
void func_021A6E30(FieldMap *fieldMap, VecFx32 *pos, u16 dir);
void func_021A6F18(FieldMap *fieldMap);
void func_021A6F24(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *func_021A6F4C(FieldMap *fieldMap);
void func_021A6F5C(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);
void func_021A7010(FieldMap *fieldMap, FieldMapCtrlHybridWork *work);
void func_021A70D0(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, RailLocation *railLocation, u32 keyTrg, u32 keyCont);
void func_021A712C(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, VecFx32 *gridPos, u32 keyTrg, u32 keyCont);
int func_021A7198(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, VecFx32 *outPos, u32 dir);
int func_021A71E4(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, RailLocation *outLocation, u32 dir);
void func_021A7258(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, int mode, const void *place, u16 dir, u16 blactAnime, u16 blactFrame);

/* Current movement system of the work. */
u32 func_021A6DC0(FieldMapCtrlHybridWork *work)
{
    return work->mode;
}

/*
 * Re-places the player in the movement system it stands in, from the
 * model's current direction (mode 0: grid to rail, else rail to grid).
 */
void func_021A6DC4(FieldMapCtrlHybridWork *work, FieldMap *fieldMap)
{
    VecFx32 gridPos;
    RailLocation railLocation;
    u16 dir = func_0216D5F8(func_021A3074(work->player));

    if (work->mode == 0) {
        if (func_021A71E4(fieldMap, work, &railLocation, dir) != 0) {
            func_021A70D0(fieldMap, work, dir, 0, &railLocation, 0, 0);
        }
    } else {
        if (func_021A7198(fieldMap, work, &gridPos, dir) != 0) {
            func_021A712C(fieldMap, work, dir, 0, &gridPos, 0, 0);
        }
    }
    work->stepActive = 0;
}

/*
 * Create slot: allocates the 12-byte work, creates the player in the
 * movement system the save data records (0: grid, else rail) and places it
 * through func_021A7258 (grid: at pos, rail: at the saved rail location).
 */
void func_021A6E30(FieldMap *fieldMap, VecFx32 *pos, u16 dir)
{
    void *saveRecord;
    u16 heapId;
    FieldMapCtrlHybridWork *work;
    int mode;
    struct Mmdl *mmdl;
    void *savedLocation;
    u16 blactAnime[2];

    saveRecord = func_020127A4(func_020120F4(func_02188C80(fieldMap)));
    heapId = func_02188C84(fieldMap);
    work = func_02030734(heapId, sizeof(FieldMapCtrlHybridWork), 1, &d_021DDF64, 0xbd);
    func_02188CAC(fieldMap, work);
    work->player = func_02188CB4(fieldMap);
    mode = func_02012AC0(saveRecord);
    work->mode = FIELDMAP_CTRL_HYBRID_MODE_NONE;
    mmdl = func_021A3074(work->player);
    func_0219F058(mmdl, &blactAnime[0], &blactAnime[1]);
    if (mode == 0) {
        func_021A35E0(work->player, heapId);
        func_021A3664(work->player, heapId);
        func_021A305C(work->player, dir);
        func_021A7258(fieldMap, work, mode, pos, dir, blactAnime[0], blactAnime[1]);
    } else {
        savedLocation = func_02012AB8(saveRecord);
        func_021A3664(work->player, heapId);
        func_021A35E0(work->player, heapId);
        func_021A305C(work->player, dir);
        func_021A7258(fieldMap, work, mode, savedLocation, dir, blactAnime[0], blactAnime[1]);
    }
    func_02188D40(fieldMap, func_0216D888(mmdl));
    func_021A3038(work->player, pos);
}

/* Destroy slot: frees the work. */
void func_021A6F18(FieldMap *fieldMap)
{
    func_020307B0(func_02188CA4(fieldMap));
}

/* Main slot: runs the update of the current mode, then reads back the player position. */
void func_021A6F24(FieldMap *fieldMap, VecFx32 *pos)
{
    FieldMapCtrlHybridWork *work = func_02188CA4(fieldMap);

    d_021DDF38.update[work->mode](fieldMap, work);
    func_021A3038(work->player, pos);
}

/* Position of the player's model, the point the camera follows. */
VecFx32 *func_021A6F4C(FieldMap *fieldMap)
{
    return func_0216D888(func_021A3074(func_02188CB4(fieldMap)));
}

/*
 * Update in grid mode: when the player stands on a rail entry tile and the
 * tile ahead allows it, switches to the rails, else walks with the keys.
 */
void func_021A6F5C(FieldMap *fieldMap, FieldMapCtrlHybridWork *work)
{
    RailLocation railLocation;
    u32 aheadAttr;
    u32 standAttr;
    struct Mmdl *mmdl;
    u32 keyTrg;
    u32 keyCont;
    u32 flags;
    u16 dir;

    keyTrg = func_020362DC();
    keyCont = func_0203630C();
    flags = 0;
    mmdl = func_021A3074(work->player);
    dir = func_021A2FA4(work->player, keyCont);
    if (func_0216D3CC(mmdl) == 1 || func_021A2FB0(work->player) == 1) {
        if (dir != 9) {
            standAttr = func_021A30C8(work->player);
            aheadAttr = func_021A3128(work->player, dir);
            if (func_021BB1A0(func_021AB0F0(standAttr)) != 0) {
                if (func_021AB11C(aheadAttr) != 0) {
                    if (func_021A71E4(fieldMap, work, &railLocation, dir) != 0) {
                        func_021A70D0(fieldMap, work, dir, 1, &railLocation, keyTrg, keyCont);
                        return;
                    }
                }
            }
        }
    }
    if (func_021A35BC(work->player) == 1)
        flags |= 1;
    func_021A35F0(work->player, keyTrg, keyCont, flags);
}

/*
 * Update in nogrid mode: when the player is on a rail tile and the tile
 * ahead allows it, switches back to the grid, else moves along the rails.
 */
void func_021A7010(FieldMap *fieldMap, FieldMapCtrlHybridWork *work)
{
    VecFx32 gridPos;
    u32 aheadAttr;
    u32 standAttr;
    u32 keyTrg;
    struct Mmdl *mmdl;
    u32 keyCont;
    u32 useDir;
    u16 dir;

    keyTrg = func_020362DC();
    keyCont = func_0203630C();
    mmdl = func_021A3074(work->player);
    if (work->stepActive == 0) {
        dir = func_021A2FA4(work->player, keyCont);
        useDir = 1;
    } else {
        dir = func_0216D608(mmdl);
        useDir = 0;
    }
    if (func_0216D3CC(mmdl) == 1 || func_021A2FB0(work->player) == 1) {
        if (dir != 9) {
            standAttr = func_021A30C8(work->player);
            aheadAttr = func_021A3128(work->player, dir);
            if (func_021BB1A0(func_021AB0F0(standAttr)) != 0) {
                if (func_021AB11C(aheadAttr) != 0) {
                    if (func_021A7198(fieldMap, work, &gridPos, dir) != 0) {
                        func_021A712C(fieldMap, work, dir, useDir, &gridPos, keyTrg, keyCont);
                        work->stepActive = 0;
                        return;
                    }
                }
            }
        }
    }
    work->stepActive = func_021A3698(work->player);
    func_021A3674(work->player, keyTrg, keyCont);
}

/* Switches from grid to rail mode at railLocation, then starts a rail step with the keys. */
void func_021A70D0(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, RailLocation *railLocation, u32 keyTrg, u32 keyCont)
{
    u16 blactAnime[2];
    struct Mmdl *mmdl;

    mmdl = func_021A3074(work->player);
    func_0219F058(mmdl, &blactAnime[0], &blactAnime[1]);
    func_021A35F0(work->player, 0, 0, 0);
    if (useDir == 0)
        dir = func_0216D5F8(mmdl);
    func_021A7258(fieldMap, work, 1, railLocation, dir, blactAnime[0], blactAnime[1]);
    func_021A3674(work->player, keyTrg, keyCont);
}

/* Switches from rail to grid mode at gridPos, then starts a grid step with the keys. */
void func_021A712C(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, u16 dir, u32 useDir, VecFx32 *gridPos, u32 keyTrg, u32 keyCont)
{
    u16 blactAnime[2];
    struct Mmdl *mmdl;
    u32 flags;

    flags = 0;
    mmdl = func_021A3074(work->player);
    func_0219F058(mmdl, &blactAnime[0], &blactAnime[1]);
    func_021A3674(work->player, 0, 0);
    if (useDir == 0)
        dir = func_0216D5F8(mmdl);
    func_021A7258(fieldMap, work, 0, gridPos, dir, blactAnime[0], blactAnime[1]);
    if (func_021A35BC(work->player) == 1)
        flags |= 1;
    func_021A35F0(work->player, keyTrg, keyCont, flags);
}

/*
 * Finds the grid position the player would step to one tile ahead in dir
 * and returns 1 when the map attribute there allows it.
 */
int func_021A7198(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, VecFx32 *outPos, u32 dir)
{
    struct FieldG3dMapper *g3dMapper;
    VecFx32 aheadPos;

    g3dMapper = func_02188C98(fieldMap);
    func_021A3038(work->player, outPos);
    aheadPos = *outPos;
    func_02164208(dir, &aheadPos, 0x10000);
    if (func_021AB11C(func_021AB0D4(g3dMapper, &aheadPos)) == 0)
        return 1;
    return 0;
}

/*
 * Looks for the rail line under the player (a vertical segment around its
 * position) and returns its location in outLocation. The function has no
 * return statement: the callers test the r0 that func_021B7A84 or
 * func_021B7CD8 left behind.
 */
int func_021A71E4(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, RailLocation *outLocation, u32 dir)
{
    VecFx32 hitPos;
    VecFx32 segBottom;
    VecFx32 segTop;
    u16 locations[8];   /* [0..3]: stepped location (unused), [4..7]: hit location */
    struct RailManager *railManager;
    u16 *outWords = (u16 *)outLocation;

    railManager = func_021BB480(func_02188C5C(fieldMap));
    func_021A3038(work->player, &segBottom);
    segTop.x = segBottom.x;
    segTop.y = segBottom.y + 0x4000;
    segTop.z = segBottom.z;
    segBottom.y = segBottom.y - 0x4000;
    if (func_021B7A84(railManager, &segBottom, &segTop, (RailLocation *)&locations[4], &hitPos) != 0)
        func_021B7CD8(railManager, (RailLocation *)&locations[4], func_0201441C(dir), (RailLocation *)locations);
    outWords[0] = locations[4];
    outWords[1] = locations[5];
    outWords[2] = locations[6];
    outWords[3] = locations[7];
}

/*
 * Moves the player model between the two movement systems. mode 0: grid
 * (place points at a VecFx32, copied in; the model gets a tile position and
 * the camera follows again); else rail (place points at a RailLocation).
 * Does nothing when the work is already in that mode. d_021DDF38 is one
 * static record: the per-mode updates, then the parameter block that
 * func_0216E0AC takes, whose objCode is refreshed here (docs/idioms/
 * pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 */
void func_021A7258(FieldMap *fieldMap, FieldMapCtrlHybridWork *work, int mode, const void *place, u16 dir, u16 blactAnime, u16 blactFrame)
{
    struct FieldNogridMapper *nogridMapper;
    struct FieldCamera *camera;
    struct Mmdl *mmdl;
    VecFx32 pos;

    nogridMapper = func_02188C5C(fieldMap);
    camera = func_02188C58(fieldMap);
    if (work->mode == mode) {
        return;
    }
    mmdl = func_021A3074(work->player);
    if (func_0216DC4C(mmdl) != 0) {
        func_0216D4B4(mmdl);
    }
    if (mode == 0) {
        pos = *(const VecFx32 *)place;
        d_021DDF38.modelParam.objCode = func_0216D598(mmdl);
        func_021A368C(work->player);
        func_0216E0AC(mmdl, &d_021DDF38.modelParam);
        func_0216E084(mmdl, (s16)((pos.x >> 12) / 16), (s16)((pos.y >> 12) / 16), (s16)((pos.z >> 12) / 16), dir);
        func_0216D88C(mmdl, &pos);
        func_021A3044(work->player, &pos);
        func_021BB3B8(nogridMapper);
        func_0218E13C(camera, 0);
        func_0218EC60(camera);
        func_0218E160(camera);
    } else {
        func_021A3680(work->player, place);
        func_021BB3AC(nogridMapper, func_021A36A4(work->player));
        func_0218F05C(camera);
    }
    func_0216D5E0(mmdl, dir);
    func_0216D600(mmdl, dir);
    func_0219F0B0(mmdl, blactAnime, blactFrame);
    work->mode = mode;
}
