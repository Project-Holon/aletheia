/*
 * file:     fldmmdl_rail.c
 * unit:     yes
 * function: func_0219E2C0, func_0219E2F4, func_0219E334, func_0219E348, func_0219E354, func_0219E370, func_0219E398, func_0219E418, func_0219E424, func_0219E498, func_0219E570, func_0219E634, func_0219E664, func_0219E6C8, func_0219E764, func_0219E784, func_0219E828, func_0219E834, func_0219E844, func_0219E854, func_0219E938, func_0219E940, func_0219E968, func_0219E9A8, func_0219E9F8, func_0219EA10, func_0219EA24, func_0219EA40, func_0219EA5C, func_0219EA78, func_0219EA94, func_0219EAB8, func_0219EAD8, func_0219EAEC, func_0219EB18, func_0219EB4C, func_0219EB90, func_0219EBA0, func_0219EBF4, func_0219ED7C, func_0219ED8C, func_0219EDC4, func_0219EF04
 * address:  0x0219E2C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_g3dobj.c at 0x0219E2C0 (no anchor; the field model rail location API and rail move types; it never calls fldmmdl_rail_move.c, which calls it).
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb
 *   func_021B7E60  0x021B7E60  thumb
 *   func_021B8038  0x021B8038  thumb
 *   func_021BB480  0x021BB480  thumb
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021B7ED4  0x021B7ED4  thumb  ov021
 *   func_021B83B0  0x021B83B0  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7C90  0x021B7C90  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_021B80D8  0x021B80D8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_0207B51C  0x0207B51C  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_021D84D4     0x021D84D4  data  ov021  a1
 *   d_021D841C     0x021D841C  data  ov021  a2
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02164380  0x02164380  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   d_021D84E8  0x021D84E8  data
 *   func_021BB394  0x021BB394  thumb  ov021
 *   func_021BB3A0  0x021BB3A0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 */
#include "fldmmdl_rail_types.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;
typedef signed long long s64;

typedef struct { s32 x, y, z; } VecFx32;

/* Opaque types owned by other files. */
typedef struct Mmdl Mmdl;             /* a field model (fldmmdl.c) */
typedef struct MmdlSys MmdlSys;       /* the field model system */
typedef struct FieldSys FieldSys;
typedef struct RailManager RailManager;
typedef struct RailWork RailWork;     /* the rail walker of one field model */

/* Move work of every rail move type: the rail walker and the last location
 * read from it. Each move type appends its own fields at 0xC. */
typedef struct {
    RailWork *railWork;
    RailLocation location;
} RailMoveWork;

/* Look around move types (turn at random, never walk). */
typedef struct {
    RailMoveWork base;
    s16 waitCount;     /* frames until the next turn */
    u16 kind;          /* index into d_021D84E8 */
} RailLookAroundWork;

/* Wander move types (walk at random around the home location). */
typedef struct {
    RailMoveWork base;
    u8 state : 4;
    u8 kind : 4;       /* index into d_021D84E8 */
    s8 waitCount;
    s8 homeWidth;
    u8 homeLine;
} RailWanderWork;

/* Shuttle move type (walk forward, turn around when blocked, come back). */
typedef struct {
    RailMoveWork base;
    u8 state;
    u8 returning;
    s8 homeWidth;
    u8 homeLine;
} RailShuttleWork;

typedef struct {
    int kind;
    u32 *dirList;      /* mmdl directions, ended by _DIR_LIST_END */
} DirListEntry;

/* Mmdl status bits (func_0216D55C tests, func_0216D550 sets). */
#define _STATUSBIT_NO_HIT    0x80
#define _STATUSBIT_NO_RAIL   0x2000    /* the rail walker is released */

#define _DIR_LIST_END   9
#define _KIND_COUNT     11
#define _LOCATION_NOT_SET 2    /* RailLocation.type of a work not set yet */

/* Anime command kinds for func_02197E7C (direction, kind). */
#define _ACMD_KIND_STOP      0x00
#define _ACMD_KIND_WALK      0x0C
#define _ACMD_KIND_STAY_WALK 0x20

#define _WANDER_START      0    /* stop and play the idle animation */
#define _WANDER_IDLE_ANIM  1    /* wait for the idle animation to end */
#define _WANDER_WAIT       2    /* count the wait frames down */
#define _WANDER_PICK_STEP  3    /* pick a direction and start the step */
#define _WANDER_STEP_ANIM  4    /* wait for the step animation to end */

#define _SHUTTLE_START     0
#define _SHUTTLE_CHECK     1
#define _SHUTTLE_STEP_ANIM 2

extern void *func_0216D67C(Mmdl *mmdl);
extern void func_02082BCC(void *dst, u32 value, u32 size);
extern FieldSys *func_0216D530(MmdlSys *mmdlSys);
extern u32 func_021BB3C4(FieldSys *fieldSys, RailLocation *loc);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern int func_0216DCB4(Mmdl *mmdl);
extern u16 func_021AB0F8(u32 attr);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D674(Mmdl *mmdl, u16 value);
extern void func_0216D60C(Mmdl *mmdl, u16 dir);
extern void func_021B8028(RailWork *railWork, VecFx32 *outPos);
extern u8 func_021B8040(RailWork *railWork);
extern void func_0216D89C(Mmdl *mmdl, VecFx32 *pos);
extern void *func_0216D69C(Mmdl *mmdl);
extern void func_021B7EE4(RailWork *railWork, RailLocation *loc);
extern RailManager *func_021BB480(FieldSys *fieldSys);
extern u8 func_021B8038(RailWork *railWork);
extern int func_021B7E60(RailWork *railWork, u32 key, RailLocation *outLoc, VecFx32 *outPos);
extern u32 func_021B7DC0(RailWork *railWork, RailLocation *outLoc);
extern void func_021B810C(RailWork *railWork);
extern void func_021B80E0(RailWork *railWork, u32 dir, u32 key);
extern int func_021B7DE0(RailWork *railWork, RailLocation *loc);
extern int func_021B7CD8(RailManager *mgr, RailLocation *loc, u32 key, RailLocation *outLoc);
extern void func_021B7D38(RailManager *mgr, RailLocation *loc, VecFx32 *outPos);
extern int func_021B7C38(RailManager *mgr);
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0216DD1C(MmdlSys *mmdlSys, Mmdl **outMmdl, u32 *iter);
extern int func_0216D55C(Mmdl *mmdl, int bits);
extern void func_021B7ED4(RailWork *railWork, VecFx32 *outPos);
extern int func_021B83B0(const VecFx32 *a, const VecFx32 *b, s32 radius);
extern u8 func_0201441C(int dir);
extern int func_021B7C90(RailManager *mgr, RailLocation *loc, u32 key, VecFx32 *outPos);
extern int func_0216D83C(Mmdl *mmdl);
extern void func_0216D80C(Mmdl *mmdl, int gridX);
extern int func_0216D854(Mmdl *mmdl);
extern void func_0216D818(Mmdl *mmdl, int gridY);
extern int func_0216D86C(Mmdl *mmdl);
extern void func_0216D824(Mmdl *mmdl, int gridZ);
extern void func_0216D844(Mmdl *mmdl, short gridX);
extern void func_0216D85C(Mmdl *mmdl, int gridY);
extern void func_0216D874(Mmdl *mmdl, int gridZ);
extern void func_021B8050(RailWork *railWork, s16 *outOffset);
extern u32 func_021B80D8(RailWork *railWork);
extern void func_0207AF1C(s32 *outMtx, s32 sin, s32 cos);
extern void func_0207B51C(VecFx32 *vec, s32 *mtx, VecFx32 *outVec);
extern void func_0207CCA4(VecFx32 *vec, VecFx32 *outVec);
extern int func_02164380(Mmdl *mmdl, RailLocation *outLoc);
extern void *func_0216D684(Mmdl *mmdl, u32 size);
extern int func_0216D660(Mmdl *mmdl);
extern int func_0216D66C(Mmdl *mmdl);
extern u32 func_020056EC(u32 range);
extern RailWork *func_021BB394(FieldSys *fieldSys);
extern Mmdl *func_0216D550(Mmdl *mmdl, u32 bits);
extern void func_021BB3A0(FieldSys *fieldSys, RailWork *railWork);
extern void func_0216DA50(Mmdl *mmdl);
extern void func_0216DA7C(Mmdl *mmdl);
extern int func_02197E7C(int dir, int kind);
extern void func_0216D438(Mmdl *mmdl, int acmdCode);
extern u32 func_02197EDC(Mmdl *mmdl);
extern void func_0216DA44(Mmdl *mmdl);
extern int func_0216D5D4(Mmdl *mmdl);
extern u16 func_021642A4(int dir);
extern u16 func_0216D608(Mmdl *mmdl);

void func_0219E2C0(Mmdl *mmdl, RailLocation *loc);
void func_0219E2F4(Mmdl *mmdl, RailLocation *outLoc);
int func_0219E334(Mmdl *mmdl, RailLocation *outLoc);
RailWork *func_0219E348(Mmdl *mmdl);
void func_0219E354(Mmdl *mmdl);
void func_0219E370(Mmdl *mmdl, u32 dir, u32 key);
u32 func_0219E398(Mmdl *mmdl, RailLocation *nowLoc, RailLocation *nextLoc, u32 *outAttr);
int func_0219E418(Mmdl *mmdl, u16 dir);
int func_0219E424(Mmdl *mmdl, u32 dir, u32 *outAttr);
int func_0219E498(Mmdl *mmdl, RailLocation *loc);
Mmdl *func_0219E570(MmdlSys *mmdlSys, RailLocation *loc, u32 includeNow);
int func_0219E634(Mmdl *mmdl, RailLocation *outLoc);
int func_0219E664(Mmdl *mmdl, u32 dir, RailLocation *outLoc);
void func_0219E6C8(Mmdl *mmdl, u16 dir);
void func_0219E764(Mmdl *mmdl, s16 *outOffset);
void func_0219E784(Mmdl *mmdl, u32 dir, s16 *outOffset);
RailMoveWork *func_0219E828(Mmdl *mmdl);
void func_0219E834(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3);
int func_0219E844(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3);
void func_0219E854(Mmdl *mmdl);
void func_0219E864(Mmdl *mmdl);
void func_0219E870(Mmdl *mmdl);
void func_0219E87C(Mmdl *mmdl);
void func_0219E888(Mmdl *mmdl);
void func_0219E894(Mmdl *mmdl);
void func_0219E8A0(Mmdl *mmdl);
void func_0219E8AC(Mmdl *mmdl);
void func_0219E8B8(Mmdl *mmdl);
void func_0219E8C4(Mmdl *mmdl);
void func_0219E8D0(Mmdl *mmdl);
void func_0219E8DC(Mmdl *mmdl);
int func_0219E8E8(Mmdl *mmdl);
int func_0219E8F0(Mmdl *mmdl);
void func_0219E8F8(Mmdl *mmdl);
void func_0219E904(Mmdl *mmdl);
int func_0219E910(Mmdl *mmdl);
int func_0219E918(Mmdl *mmdl);
void func_0219E920(Mmdl *mmdl);
int func_0219E928(Mmdl *mmdl);
int func_0219E930(Mmdl *mmdl);
u32 func_0219E938(int dir);
u32 func_0219E940(int key);
RailMoveWork *func_0219E968(Mmdl *mmdl, u32 size);
int func_0219E9A8(Mmdl *mmdl, int homeLine, int homeWidth, RailLocation *loc);
int func_0219E9F8(u32 *table, u32 terminator);
int func_0219EA10(u32 *table, int terminator);
u32 func_0219EA24(u32 kind, u32 terminator);
u32 *func_0219EA40(int kind);
int func_0219EA5C(RailMoveWork *work, Mmdl *mmdl);
void func_0219EA78(RailMoveWork *work, Mmdl *mmdl);
u32 func_0219EA94(RailMoveWork *work, Mmdl *mmdl);
void func_0219EAB8(RailMoveWork *work, Mmdl *mmdl);
void func_0219EAD8(RailMoveWork *work, const RailLocation *loc);
void func_0219EAEC(RailMoveWork *work, Mmdl *mmdl);
void func_0219EB18(Mmdl *mmdl, u16 kind);
int func_0219EB4C(Mmdl *mmdl);
int func_0219EB90(Mmdl *mmdl);
void func_0219EBA0(Mmdl *mmdl, u32 kind);
int func_0219EBF4(Mmdl *mmdl);
int func_0219ED7C(Mmdl *mmdl);
void func_0219ED8C(Mmdl *mmdl);
int func_0219EDC4(Mmdl *mmdl);
int func_0219EF04(Mmdl *mmdl);

extern u8 d_021D84D4[][4];       /* [slope kind][direction] -> angle index */
extern u16 d_021D841C[];         /* angles: 0, 180, 90, 270 degrees */
extern s16 d_020A1B38[];         /* sin/cos table, pairs, 4096 = 1.0 */
extern DirListEntry d_021D84E8[];
extern u32 d_021D84AC[];         /* wait frames, ended by -1 */

/* Set the location of a model and place it there. */
void func_0219E2C0(Mmdl *mmdl, RailLocation *loc)
{
    RailMoveWork *work = func_0216D69C(mmdl);
    VecFx32 pos;
    func_021B7EE4(work->railWork, loc);
    func_0219EAD8(work, loc);
    func_021B8028(work->railWork, &pos);
    func_0216D89C(mmdl, &pos);
}

/* Read where the model goes: the target while it moves, else the place it is. */
void func_0219E2F4(Mmdl *mmdl, RailLocation *outLoc)
{
    RailMoveWork *work;

    func_021BB480(func_0216D530(func_0216D67C(mmdl)));
    work = func_0216D69C(mmdl);
    if (func_021B8040(work->railWork))
        func_021B7E60(work->railWork, func_021B8038(work->railWork), outLoc, 0);
    else
        func_021B7DC0(work->railWork, outLoc);
}

/* Read the place the model is at now. */
int func_0219E334(Mmdl *mmdl, RailLocation *outLoc)
{
    return func_021B7DC0(((RailMoveWork *)func_0216D69C(mmdl))->railWork, outLoc);
}

RailWork *func_0219E348(Mmdl *mmdl)
{
    return ((RailMoveWork *)func_0216D69C(mmdl))->railWork;
}

/* Run the rail walker and store the place it reaches. */
void func_0219E354(Mmdl *mmdl)
{
    RailMoveWork *work = func_0216D69C(mmdl);
    func_021B810C(work->railWork);
    func_0219EA78(work, mmdl);
}

/* Ask the rail walker for a step. */
void func_0219E370(Mmdl *mmdl, u32 dir, u32 key)
{
    RailMoveWork *work = func_0216D69C(mmdl);
    u32 railKey = func_0219E938(dir);
    func_021B80E0(work->railWork, func_0219E940(key), railKey);
}

/* Test a step from nowLoc to nextLoc. Bit 0: no rail there. Bit 1: the map
 * attribute blocks it. Bit 2: another model stands there. */
u32 func_0219E398(Mmdl *mmdl, RailLocation *nowLoc, RailLocation *nextLoc, u32 *outAttr)
{
    u32 hitBits;
    RailMoveWork *work;
    FieldSys *fieldSys;
    u32 attr;

    hitBits = 0;
    work = func_0216D69C(mmdl);
    fieldSys = func_0216D530(func_0216D67C(mmdl));
    if (!func_021B7DE0(work->railWork, nowLoc)) {
        hitBits |= 1;
    }
    if (!func_021B7DE0(work->railWork, nextLoc)) {
        hitBits |= 1;
    }
    if (!func_0216DCB4(mmdl)) {
        attr = func_021BB3C4(fieldSys, nextLoc);
        if (func_021AB0F8(attr) & 1) {
            hitBits |= 2;
        }
        if (outAttr) {
            *outAttr = attr;
        }
    }
    if (func_0219E498(mmdl, nextLoc)) {
        hitBits |= 4;
    }
    return hitBits;
}

/* Test a step in dir, ignoring the map attribute. */
int func_0219E418(Mmdl *mmdl, u16 dir)
{
    return func_0219E424(mmdl, dir, 0);
}

/* Test a step in dir. Returns 1 when the rails have no place there. */
int func_0219E424(Mmdl *mmdl, u32 dir, u32 *outAttr)
{
    RailManager *railMgr;
    RailMoveWork *work;
    RailLocation nowLoc;
    RailLocation nextLoc;
    int found;
    u32 curDir;

    railMgr = func_021BB480(func_0216D530(func_0216D67C(mmdl)));
    work = func_0216D69C(mmdl);
    func_021B7DC0(work->railWork, &nowLoc);
    curDir = func_0216D5F8(mmdl);
    if (curDir == dir) {
        found = func_021B7E60(work->railWork, func_0219E938(dir), &nextLoc, 0);
    } else {
        found = func_021B7CD8(railMgr, &nowLoc, func_0219E938(dir), &nextLoc);
    }
    if (found) {
        return func_0219E398(mmdl, &nowLoc, &nextLoc, outAttr);
    }
    return 1;
}

/* Does another model stand within reach of loc? */
int func_0219E498(Mmdl *mmdl, RailLocation *loc)
{
    Mmdl *other;
    RailWork *otherWork;
    VecFx32 targetPos;
    VecFx32 otherPos;
    u32 iter;
    MmdlSys *mmdlSys;
    u32 mask;
    RailManager *railMgr;
    u32 reach;
    int notCounted;

    mmdlSys = func_0216D67C(mmdl);
    railMgr = func_021BB480(func_0216D530(mmdlSys));
    iter = 0;
    func_021B7D38(railMgr, loc, &targetPos);
    reach = func_0207C768(func_021B7C38(railMgr), 0x4000);
    while (func_0216DD1C(mmdlSys, &other, &iter) == 1) {
        mask = _STATUSBIT_NO_RAIL;
        if (other == mmdl) {
            continue;
        }
        if (func_0216D55C(other, _STATUSBIT_NO_HIT) != 0) {
            continue;
        }
        notCounted = (func_0216D55C(other, mask) == 0);
        if (!notCounted) {
            otherWork = func_0219E348(other);
            if (func_021B8040(otherWork)) {
                func_021B7E60(otherWork, func_021B8038(otherWork), 0, &otherPos);
                if (func_021B83B0(&targetPos, &otherPos, reach)) {
                    return 1;
                }
            }
            func_021B7ED4(otherWork, &otherPos);
            if (func_021B83B0(&targetPos, &otherPos, reach)) {
                return 1;
            }
        }
    }
    return 0;
}

/* Find the model that stands at loc (also at its target when includeNow). */
Mmdl *func_0219E570(MmdlSys *mmdlSys, RailLocation *loc, u32 includeNow)
{
    RailManager *railMgr;
    u32 reach;
    VecFx32 targetPos;
    VecFx32 otherPos;
    u32 iter;
    Mmdl *other;
    RailLocation otherLoc;
    RailLocation otherNextLoc;
    u32 mask;
    int notCounted;

    iter = 0;
    railMgr = func_021BB480(func_0216D530(mmdlSys));
    func_021B7D38(railMgr, loc, &targetPos);
    reach = func_0207C768(func_021B7C38(railMgr), 0x4000);
    while (func_0216DD1C(mmdlSys, &other, &iter) == 1) {
        mask = _STATUSBIT_NO_RAIL;
        notCounted = (func_0216D55C(other, mask) == 0);
        if (!notCounted) {
            if (includeNow) {
                func_0219E334(other, &otherLoc);
                func_021B7D38(railMgr, &otherLoc, &otherPos);
                if (func_021B83B0(&targetPos, &otherPos, reach)) {
                    return other;
                }
            }
            func_0219E2F4(other, &otherNextLoc);
            func_021B7D38(railMgr, &otherNextLoc, &otherPos);
            if (func_021B83B0(&targetPos, &otherPos, reach)) {
                return other;
            }
        }
    }
    return 0;
}

/* Read the place in front of the model. */
int func_0219E634(Mmdl *mmdl, RailLocation *outLoc)
{
    RailMoveWork *work;

    func_0216D530(func_0216D67C(mmdl));
    work = func_0216D69C(mmdl);
    return func_021B7E60(work->railWork, func_0201441C(func_0216D5F8(mmdl)), outLoc, 0);
}

/* Read the place one step away in dir. */
int func_0219E664(Mmdl *mmdl, u32 dir, RailLocation *outLoc)
{
    RailManager *railMgr;
    u32 curDir;
    RailMoveWork *work;

    railMgr = func_021BB480(func_0216D530(func_0216D67C(mmdl)));
    curDir = func_0216D5F8(mmdl);
    work = func_0216D69C(mmdl);
    if (curDir != dir) {
        func_0219E2F4(mmdl, outLoc);
        return func_021B7CD8(railMgr, outLoc, func_0201441C(dir), outLoc);
    }
    return func_021B7E60(work->railWork, func_0201441C(dir), outLoc, 0);
}

/* Put the model on the grid cell one step away in dir. */
void func_0219E6C8(Mmdl *mmdl, u16 dir)
{
    RailManager *railMgr;
    VecFx32 pos;
    RailLocation nowLoc;

    railMgr = func_021BB480(func_0216D530(func_0216D67C(mmdl)));
    func_0219E2F4(mmdl, &nowLoc);
    func_021B7C90(railMgr, &nowLoc, func_0201441C(dir), &pos);
    func_0216D80C(mmdl, func_0216D83C(mmdl));
    func_0216D818(mmdl, func_0216D854(mmdl));
    func_0216D824(mmdl, func_0216D86C(mmdl));
    func_0216D844(mmdl, (pos.x >> 4) / 4096);
    func_0216D85C(mmdl, (s16)((pos.y >> 4) / 4096));
    func_0216D874(mmdl, (s16)((pos.z >> 4) / 4096));
}

/* Read the draw offset of the model for the direction it faces. */
void func_0219E764(Mmdl *mmdl, s16 *outOffset)
{
    func_0219E348(mmdl);
    func_0219E784(mmdl, (((u32)func_0216D5F8(mmdl) << 16) >> 16), outOffset);
}

static inline void setVec(VecFx32 *vec, s32 x, s32 y, s32 z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

static inline void setVec16(s16 *vec, s32 x, s32 y, s32 z)
{
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

/* Read the draw offset of the rail walker, tilted by the slope under it. */
void func_0219E784(Mmdl *mmdl, u32 dir, s16 *outOffset)
{
    RailWork *railWork;
    u32 slopeKind;
    s32 sinIndex;
    s32 cos;
    s32 rotMtx[9];
    VecFx32 offsetVec;

    railWork = func_0219E348(mmdl);
    func_021B8050(railWork, outOffset);
    slopeKind = func_021B80D8(railWork);
    sinIndex = (d_021D841C[d_021D84D4[slopeKind][dir]] >> 4) * 2;
    cos = d_020A1B38[sinIndex + 1];
    outOffset[1] = (s16)(((s64)cos * outOffset[1] + 0x800) >> 12);
    setVec(&offsetVec, outOffset[0], outOffset[1], outOffset[2]);
    func_0207AF1C(rotMtx, d_020A1B38[sinIndex], cos);
    func_0207B51C(&offsetVec, rotMtx, &offsetVec);
    func_0207CCA4(&offsetVec, &offsetVec);
    setVec16(outOffset, offsetVec.x, offsetVec.y, offsetVec.z);
}

/* Stay move type: init, move, delete, return. */
RailMoveWork *func_0219E828(Mmdl *mmdl)
{
    return func_0219E968(mmdl, 0xc);
}

void func_0219E834(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3)
{
    func_0219EA78(func_0216D69C(mmdl), mmdl);
}

int func_0219E844(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3)
{
    return func_0219EA94(func_0216D69C(mmdl), mmdl);
}

/*
 * The stay return proc is followed by twenty unlabelled tail-call thunks
 * (pool word plus `bx r3`): eleven look around inits for the kinds 0..10, then
 * the move and delete procs of the look around, the two wander inits, the
 * move and delete procs of the wander, and the shuttle init, move, delete.
 */
void func_0219E854(Mmdl *mmdl)
{
    func_0219EAB8(func_0216D69C(mmdl), mmdl);
}

void func_0219E864(Mmdl *mmdl) { func_0219EB18(mmdl, 0); }
void func_0219E870(Mmdl *mmdl) { func_0219EB18(mmdl, 1); }
void func_0219E87C(Mmdl *mmdl) { func_0219EB18(mmdl, 2); }
void func_0219E888(Mmdl *mmdl) { func_0219EB18(mmdl, 3); }
void func_0219E894(Mmdl *mmdl) { func_0219EB18(mmdl, 4); }
void func_0219E8A0(Mmdl *mmdl) { func_0219EB18(mmdl, 5); }
void func_0219E8AC(Mmdl *mmdl) { func_0219EB18(mmdl, 6); }
void func_0219E8B8(Mmdl *mmdl) { func_0219EB18(mmdl, 7); }
void func_0219E8C4(Mmdl *mmdl) { func_0219EB18(mmdl, 8); }
void func_0219E8D0(Mmdl *mmdl) { func_0219EB18(mmdl, 9); }
void func_0219E8DC(Mmdl *mmdl) { func_0219EB18(mmdl, 10); }

int func_0219E8E8(Mmdl *mmdl) { return func_0219EB4C(mmdl); }
int func_0219E8F0(Mmdl *mmdl) { return func_0219EB90(mmdl); }

void func_0219E8F8(Mmdl *mmdl) { func_0219EBA0(mmdl, 0); }
void func_0219E904(Mmdl *mmdl) { func_0219EBA0(mmdl, 9); }

int func_0219E910(Mmdl *mmdl) { return func_0219EBF4(mmdl); }
int func_0219E918(Mmdl *mmdl) { return func_0219ED7C(mmdl); }

void func_0219E920(Mmdl *mmdl) { func_0219ED8C(mmdl); }
int func_0219E928(Mmdl *mmdl) { return func_0219EDC4(mmdl); }
int func_0219E930(Mmdl *mmdl) { return func_0219EF04(mmdl); }

/* Model direction to rail key. */
u32 func_0219E938(int dir)
{
    return func_0201441C(dir);
}

/* Rail key (2, 4, 8, 16) to model direction (0 up, 1 down, 2 left, 3 right). */
u32 func_0219E940(int key)
{
    u32 dir = 1;
    switch (key) {
    case 16: dir = 0; break;
    case 4: dir = 2; break;
    case 2: dir = 3; break;
    case 8: break;
    }
    return dir;
}

/* Allocate the move work of a model and bind it to a rail walker. */
RailMoveWork *func_0219E968(Mmdl *mmdl, u32 size)
{
    RailLocation startLoc;
    int hasStartLoc = func_02164380(mmdl, &startLoc);
    RailMoveWork *work = func_0216D684(mmdl, size);
    func_0219EA5C(work, mmdl);
    if (hasStartLoc) {
        func_0219E2C0(mmdl, &startLoc);
    } else {
        func_02082BCC(&startLoc, 0, 8);
        func_0219E2C0(mmdl, &startLoc);
    }
    return work;
}

/* Is loc outside the area around the home cell the model may walk in? */
int func_0219E9A8(Mmdl *mmdl, int homeLine, int homeWidth, RailLocation *loc)
{
    int limitWidth;
    int limitLine;
    int low;
    int high;

    limitWidth = func_0216D660(mmdl);
    limitLine = func_0216D66C(mmdl);
    if (limitWidth != -1) {
        low = homeWidth - limitWidth;
        high = homeWidth + limitWidth;
        if (low > loc->widthGrid || high < loc->widthGrid) {
            return 1;
        }
    }
    if (limitLine != -1) {
        high = homeLine + limitLine;
        low = homeLine - limitLine;
        if (low > loc->lineGrid || high < loc->lineGrid) {
            return 1;
        }
    }
    return 0;
}

/* Index of the first entry equal to terminator. */
int func_0219E9F8(u32 *table, u32 terminator)
{
    int count;
    for (count = 0; table[count] != terminator; count++) {
    }
    return count;
}

/* Pick a random entry of a table ended by terminator. */
int func_0219EA10(u32 *table, int terminator)
{
    return *(u32 *)((u8 *)(table) + ((func_020056EC(func_0219E9F8((u32 *)table, terminator)) << 2)));
}

/* Pick a random direction out of the direction list of a kind. */
u32 func_0219EA24(u32 kind, u32 terminator)
{
    u32 *dirList = func_0219EA40(kind);
    return dirList[func_020056EC(func_0219E9F8(dirList, terminator))];
}

/* The direction list of a look around or wander kind. */
u32 *func_0219EA40(int kind)
{
    DirListEntry *entry = d_021D84E8;
    int key = 0;
    do {
        if (key == kind) {
            return entry->dirList;
        }
        entry++;
        key = entry->kind;
    } while (key != _KIND_COUNT);
    return 0;
}

/* Get a rail walker for the model and mark the location as not set. */
int func_0219EA5C(RailMoveWork *work, Mmdl *mmdl)
{
    work->railWork = func_021BB394(func_0216D530(func_0216D67C(mmdl)));
    work->location.type = _LOCATION_NOT_SET;
    return _LOCATION_NOT_SET;
}

/* Store the place the rail walker is at now. */
void func_0219EA78(RailMoveWork *work, Mmdl *mmdl)
{
    RailLocation nowLoc;
    func_021B7DC0(work->railWork, &nowLoc);
    func_0219EAD8(work, &nowLoc);
}

/* Release the rail walker. */
u32 func_0219EA94(RailMoveWork *work, Mmdl *mmdl)
{
    func_021BB3A0(func_0216D530(func_0216D67C(mmdl)), work->railWork);
    return (u32)func_0216D550(mmdl, _STATUSBIT_NO_RAIL);
}

/* Get a rail walker again and put it on the stored location. */
void func_0219EAB8(RailMoveWork *work, Mmdl *mmdl)
{
    work->railWork = func_021BB394(func_0216D530(func_0216D67C(mmdl)));
    func_0219EAEC(work, mmdl);
}

/*
 * The source pointer is const: that lets mwcc load loc->lineGrid above the
 * store of loc->widthGrid.
 */
void func_0219EAD8(RailMoveWork *work, const RailLocation *loc)
{
    work->location = *loc;
}

/* Put the rail walker and the model on the stored location. */
void func_0219EAEC(RailMoveWork *work, Mmdl *mmdl)
{
    VecFx32 pos;
    if (work->location.type != _LOCATION_NOT_SET) {
        func_021B7EE4(work->railWork, &work->location);
        func_021B8028(work->railWork, &pos);
        func_0216D89C(mmdl, &pos);
    }
}

/* Look around init: kind selects the directions to turn to. */
void func_0219EB18(Mmdl *mmdl, u16 kind)
{
    RailLookAroundWork *work = (RailLookAroundWork *)func_0219E968(mmdl, 16);
    work->waitCount = func_0219EA10(d_021D84AC, -1);
    work->kind = kind;
    func_0216D674(mmdl, 0);
    func_0216DA50(mmdl);
}

/* Look around move: turn to a random direction of the kind after each wait. */
int func_0219EB4C(Mmdl *mmdl)
{
    RailLookAroundWork *work;

    work = func_0216D69C(mmdl);
    work->waitCount = work->waitCount - 1;
    if (work->waitCount <= 0) {
        work->waitCount = func_0219EA10((u32 *)d_021D84AC, -1);
        func_0216D5E0(mmdl, (u16)func_0219EA24(work->kind, _DIR_LIST_END));
    }
    func_0219EA78(&work->base, mmdl);
}

/* Look around delete. */
int func_0219EB90(Mmdl *mmdl)
{
    return func_0219EA94(func_0216D69C(mmdl), mmdl);
}

/* Wander init: kind selects the directions to walk to. */
void func_0219EBA0(Mmdl *mmdl, u32 kind)
{
    RailWanderWork *work;
    RailLocation homeLoc;

    work = (RailWanderWork *)func_0219E968(mmdl, 0x10);
    func_0219E2F4(mmdl, &homeLoc);
    work->state = 0;
    work->waitCount = 0;
    work->kind = kind;
    work->homeLine = homeLoc.lineGrid;
    work->homeWidth = homeLoc.widthGrid;
    func_0216D674(mmdl, 0);
    func_0216DA50(mmdl);
}

/* Wander move: idle, wait, then step to a random direction of the kind unless
 * the step is blocked, leaves the rail or leaves the home area. */
int func_0219EBF4(Mmdl *mmdl)
{
    RailWanderWork *work;
    u32 dir;
    RailLocation nowLoc;
    RailLocation nextLoc;

    work = func_0216D69C(mmdl);
    switch (work->state) {
    case _WANDER_START:
        func_0216DA50(mmdl);
        func_0216DA7C(mmdl);
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8(mmdl)), (u32)_ACMD_KIND_STOP)));
        work->state++;
        break;
    case _WANDER_IDLE_ANIM:
        if (!func_02197EDC(mmdl)) {
            break;
        }
        work->waitCount = func_0219EA10((u32 *)d_021D84AC, -1);
        work->state++;
    case _WANDER_WAIT:
        work->waitCount--;
        if (work->waitCount != 0) {
            break;
        }
        work->state++;
    case _WANDER_PICK_STEP:
        dir = func_0219EA24(work->kind, _DIR_LIST_END);
        func_0216D60C(mmdl, dir);
        if (func_0219E418(mmdl, dir)) {
            work->state = _WANDER_START;
            break;
        }
        func_0219E2F4(mmdl, &nowLoc);
        func_0219E664(mmdl, (u16)dir, &nextLoc);
        if (nowLoc.railIndex != nextLoc.railIndex) {
            work->state = _WANDER_START;
            break;
        }
        if (func_0219E9A8(mmdl, work->homeLine, work->homeWidth, &nextLoc)) {
            work->state = _WANDER_START;
            break;
        }
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dir, (u32)_ACMD_KIND_WALK)));
        func_0216DA44(mmdl);
        work->state++;
    case _WANDER_STEP_ANIM:
        if (func_02197EDC(mmdl)) {
            func_0216DA50(mmdl);
            work->state = _WANDER_START;
        }
        break;
    }
    func_0219EA78(&work->base, mmdl);
}

/* Wander delete. */
int func_0219ED7C(Mmdl *mmdl)
{
    return func_0219EA94(func_0216D69C(mmdl), mmdl);
}

/* Shuttle init: the home cell is where the model starts. */
void func_0219ED8C(Mmdl *mmdl)
{
    RailShuttleWork *work = (RailShuttleWork *)func_0219E968(mmdl, 16);
    RailLocation homeLoc;
    func_0219E2F4(mmdl, &homeLoc);
    work->state = 0;
    work->returning = 0;
    work->homeLine = homeLoc.lineGrid;
    work->homeWidth = homeLoc.widthGrid;
    func_0216D674(mmdl, 0);
    func_0216DA50(mmdl);
}

/* Shuttle move: walk in the move direction; when blocked, leaves the rail or
 * leaves the area, turn around and walk back to the home cell, then turn
 * around again. */
int func_0219EDC4(Mmdl *mmdl)
{
    RailShuttleWork *work;
    u32 hitBits;
    u32 dir;
    u32 typeChanged;
    int outOfArea;
    RailLocation nowLoc;
    RailLocation nextLoc;

    work = func_0216D69C(mmdl);
    switch (work->state) {
    case _SHUTTLE_START:
        dir = func_0216D5D4(mmdl);
        if (work->returning == 1) {
            dir = (u32)func_021642A4((u16)dir);
        }
        func_0216D60C(mmdl, (u16)dir);
        work->state = _SHUTTLE_CHECK;
    case _SHUTTLE_CHECK:
        func_0219E2F4(mmdl, &nowLoc);
        if (work->returning != 0 && work->homeLine == nowLoc.lineGrid && work->homeWidth == nowLoc.widthGrid) {
            func_0216D60C(mmdl, (u16)((u32)func_021642A4((u16)func_0216D608(mmdl))));
            work->returning = 0;
        }
        typeChanged = 0;
        dir = func_0216D608(mmdl);
        hitBits = (u32)func_0219E418(mmdl, (u16)dir);
        func_0219E664(mmdl, (u16)dir, &nextLoc);
        outOfArea = func_0219E9A8(mmdl, work->homeLine, work->homeWidth, &nextLoc);
        if (nowLoc.railIndex != nextLoc.railIndex) {
            typeChanged = 1;
        }
        if ((hitBits & 1) || outOfArea || typeChanged) {
            work->returning = 1;
            dir = (u32)func_021642A4((u16)dir);
            hitBits = (u32)func_0219E418(mmdl, (u16)dir);
            func_0219E664(mmdl, (u16)dir, &nextLoc);
        }
        func_0216D438(mmdl, (u16)((u32)func_02197E7C((u16)dir, (u16)(hitBits == 0 ? _ACMD_KIND_WALK : _ACMD_KIND_STAY_WALK))));
        func_0216DA44(mmdl);
        work->state = _SHUTTLE_STEP_ANIM;
        break;
    case _SHUTTLE_STEP_ANIM:
        if (func_02197EDC(mmdl) == 1) {
            func_0216DA50(mmdl);
            work->state = _SHUTTLE_START;
        }
        break;
    }
    func_0219EA78(&work->base, mmdl);
}

/* Shuttle delete. */
int func_0219EF04(Mmdl *mmdl)
{
    return func_0219EA94(func_0216D69C(mmdl), mmdl);
}
