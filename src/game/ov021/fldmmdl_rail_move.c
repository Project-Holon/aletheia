/*
 * file:     fldmmdl_rail_move.c
 * unit:     yes
 * function: func_0219D6B8, func_0219D6CC, func_0219D724, func_0219D738, func_0219D780, func_0219D7AC, func_0219D7D0, func_0219D7F0, func_0219D824, func_0219D85C, func_0219D8DC, func_0219D930, func_0219D990, func_0219D9D8, func_0219DA20, func_0219DA80, func_0219DAA4, func_0219DAD0, func_0219DB04, func_0219DB0C, func_0219DB44, func_0219DB48, func_0219DB5C, func_0219DBC8, func_0219DC08, func_0219DC18, func_0219DC28, func_0219DC34, func_0219DC58, func_0219DC64, func_0219DC70, func_0219DC7C, func_0219DC88, func_0219DCC4, func_0219DD18, func_0219DD24, func_0219DD34, func_0219DD44, func_0219DD54, func_0219DD64, func_0219DD74, func_0219DD84, func_0219DD94, func_0219DDA4, func_0219DDB4, func_0219DDC4, func_0219DDD4, func_0219DDE4, func_0219DDF4, func_0219DE04, func_0219DE14, func_0219DE24, func_0219DE34, func_0219DE44, func_0219DE54, func_0219DE64, func_0219DE98, func_0219DECC, func_0219DEDC, func_0219DEEC, func_0219DEFC, func_0219DF0C, func_0219DF1C, func_0219DF2C, func_0219DF3C, func_0219DF4C, func_0219DF5C, func_0219DF6C, func_0219DF7C, func_0219DF8C, func_0219DF9C, func_0219DFAC, func_0219DFBC, func_0219DFCC, func_0219DFDC, func_0219DFEC, func_0219DFFC, func_0219E00C, func_0219E084, func_0219E0A8, func_0219E1B0, func_0219E1D0, func_0219E1F4, func_0219E218, func_0219E238, func_0219E258, func_0219E27C, func_0219E29C
 * address:  0x0219D6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_g3dobj.c at 0x0219D6B8 (no anchor; the field model rail move and rail anime command code, with its own const tables at 0x021D80E4..0x021D841B).
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216D7E0  0x0216D7E0  thumb  ov010
 *   func_0216D7D8  0x0216D7D8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AC760  0x021AC760  thumb  ov021
 *   func_021BBDD4  0x021BBDD4  thumb  ov021
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb  ov021
 *   func_021AC578  0x021AC578  thumb  ov021
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   d_021DDD94     0x021DDD94  data
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E334  0x0219E334  thumb  ov021
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E354  0x0219E354  thumb  ov021
 *   func_0219E370  0x0219E370  thumb  ov021
 *   func_0219E6C8  0x0219E6C8  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

/* A field model (opaque here; fldmmdl.c owns the layout). */
typedef struct Mmdl Mmdl;

/* The start of the object code parameter of a field model. */
typedef struct {
    u16 code;
    u8 drawType;
    u8 drawProcNo;
    u8 shadowSize;
    u8 footMarkType;   /* 2: cycle foot marks */
    u8 reflectType;    /* 0: no reflection */
} MmdlObjCodeParam;

/* A rail location (8 bytes; fldmmdl_rail.c fills it). */
typedef struct {
    u32 word[2];
} RailLocation;

/* Anime command work of the stay walk commands (walk in place). */
typedef struct {
    u16 drawStatus;
    s16 frameCount;
} RailAcmdStayWalkWork;

/* Anime command work of the rail jump commands (0x10). */
typedef struct {
    s32 speed;        /* rail move speed added to moveAcc each frame */
    s32 moveAcc;      /* 0x10000 = one grid moved */
    u16 heightStep;   /* added to heightPos each frame */
    u16 heightPos;    /* 0x100 per height table entry */
    s8 dir;
    s8 frameCount;
    s8 drawStatus;
    s8 heightTable;   /* index into _JumpHeightTables */
} RailAcmdJumpWork;

/* Field model move bits (the status word fldmmdl.c sets and tests). */
#define _MOVEBIT_MOVE_START     0x20
#define _MOVEBIT_MOVE_END       0x40
#define _MOVEBIT_JUMP_START     0x80
#define _MOVEBIT_JUMP_END       0x100
#define _MOVEBIT_ACMD           0x200
#define _MOVEBIT_ACMD_END       0x400
#define _MOVEBIT_ATTR_GET_ERROR 0x800
#define _MOVEBIT_SHADOW_SET     0x4000

/* Map attribute flags (func_021AB0F8). */
#define _ATTRFLAG_FOOTMARK 0x08
#define _ATTRFLAG_GRASS    0x20
#define _ATTRFLAG_REFLECT  0x40

#define _ATTR_NONE 0xFFFFFFFF

#define _DIR_UP    0
#define _DIR_DOWN  1
#define _DIR_LEFT  2
#define _DIR_RIGHT 3

#define _DRAW_STA_STOP     0
#define _DRAW_STA_WALK_32F 1
#define _DRAW_STA_WALK_16F 2
#define _DRAW_STA_WALK_8F  3
#define _DRAW_STA_WALK_4F  4
#define _DRAW_STA_WALK_2F  5
#define _DRAW_STA_DASH_4F  10

#define _SE_RAIL_JUMP 0x55E
#define _SE_RAIL_LAND 0x67B

extern void *func_0216D67C(Mmdl *mmdl);
extern MmdlObjCodeParam *func_0216E3C4(Mmdl *mmdl);
extern u32 *func_0216D548(Mmdl *mmdl, u32 bit);
extern void func_0216D6F4(Mmdl *mmdl);
extern int func_0216DA20(Mmdl *mmdl, unsigned int bit);
extern u32 func_0216D57C(Mmdl *mmdl, u32 bit);
extern void func_02197EB4(Mmdl *mmdl);
extern int func_0216DB10(Mmdl *mmdl);
extern void func_0216D708(Mmdl *mmdl);
extern void *func_0216D530(void *mmdlSys);
extern u32 func_021BB3C4(void *railMapper, RailLocation *location);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern void func_0207CDB8(s16 *src, s16 *dst);
extern int func_0207CFB8(int y, int x);
extern int func_0216DA5C(Mmdl *mmdl);
extern u16 func_0216D5A0(Mmdl *mmdl);
extern void func_0216DA70(Mmdl *mmdl);
extern char *func_0216D570(Mmdl *mmdl, u32 bit);
extern int func_0216DCB4(Mmdl *mmdl);
extern void func_0216D7E0(Mmdl *mmdl, u32 attr);
extern void func_0216D7D8(Mmdl *mmdl, u32 attr);
extern void *func_0216D568(Mmdl *mmdl, u32 bit);
extern int func_0216DB24(Mmdl *mmdl);
extern u32 func_0216D7DC(Mmdl *mmdl);
extern u32 func_0216D7E4(Mmdl *mmdl);
extern u16 func_021AB0F8(u32 attr);
extern void func_021AC760(u32 fldEffCtrl, Mmdl *mmdl, u32 animate, int arg);
extern void func_021BBDD4(Mmdl *mmdl, u32 fldEffCtrl, int cycle);
extern int func_0216D98C(void *mmdlSys);
extern void func_021AC2C0(Mmdl *mmdl, u32 fldEffCtrl);
extern u32 func_021AC578(Mmdl *mmdl, u32 fldEffCtrl);
extern int func_0216DC34(Mmdl *mmdl);
extern int func_02163F40(Mmdl *mmdl, int dir);
extern int func_0216DC18(Mmdl *mmdl, int on);
extern void func_021BBFB8(void *mmdlSys, Mmdl *mmdl, u32 fldEffCtrl, u32 arg);
extern void *func_0216D534(void *mmdlSys);
extern u32 func_02188CD0(void *fieldmap);
extern void func_0216D7CC(Mmdl *mmdl);
extern int func_02163F10(Mmdl *mmdl);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D674(Mmdl *mmdl, u16 drawStatus);
extern void func_0216D60C(Mmdl *mmdl, u16 dir);
extern void func_021B8028();
extern u8 func_021B8040(void *railWork);
extern void func_0216D89C();
extern void *func_0216D6BC(Mmdl *mmdl, int size, int arg);
extern void *func_0216D6D4(Mmdl *mmdl);
extern void func_020061E4(u32 seNo);
extern void func_0216D8C0(Mmdl *mmdl, VecFx32 *offset);

int func_0219D6B8(Mmdl *mmdl);
void func_0219D6CC(Mmdl *mmdl);
int func_0219D724(Mmdl *mmdl, RailLocation *location);
u32 func_0219D738(Mmdl *mmdl, int angle);
int func_0219D780(Mmdl *mmdl);
void func_0219D7AC(Mmdl *mmdl);
void func_0219D7D0(Mmdl *mmdl);
void func_0219D7F0(Mmdl *mmdl);
void func_0219D824(Mmdl *mmdl);
u32 func_0219D85C(Mmdl *mmdl);
void func_0219D8DC(Mmdl *mmdl);
void func_0219D930(Mmdl *mmdl);
void func_0219D990(Mmdl *mmdl);
void func_0219D9D8(Mmdl *mmdl);
void func_0219DA20(Mmdl *mmdl);
void func_0219DA80(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DAA4(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DAD0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DB04(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DB0C(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DB44(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
int func_0219DB48(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DB5C(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void func_0219DBC8(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
u32 func_0219DC08(Mmdl *mmdl);
int func_0219DC18(Mmdl *mmdl);
int func_0219DC28(Mmdl *mmdl);
void func_0219DC34(Mmdl *mmdl, u32 dir);
int func_0219DC58(Mmdl *mmdl);
int func_0219DC64(Mmdl *mmdl);
int func_0219DC70(Mmdl *mmdl);
int func_0219DC7C(Mmdl *mmdl);
void func_0219DC88(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus);
int func_0219DCC4(Mmdl *mmdl);
int func_0219DD18(Mmdl *mmdl);
int func_0219DD24(Mmdl *mmdl);
int func_0219DD34(Mmdl *mmdl);
int func_0219DD44(Mmdl *mmdl);
int func_0219DD54(Mmdl *mmdl);
int func_0219DD64(Mmdl *mmdl);
int func_0219DD74(Mmdl *mmdl);
int func_0219DD84(Mmdl *mmdl);
int func_0219DD94(Mmdl *mmdl);
int func_0219DDA4(Mmdl *mmdl);
int func_0219DDB4(Mmdl *mmdl);
int func_0219DDC4(Mmdl *mmdl);
int func_0219DDD4(Mmdl *mmdl);
int func_0219DDE4(Mmdl *mmdl);
int func_0219DDF4(Mmdl *mmdl);
int func_0219DE04(Mmdl *mmdl);
int func_0219DE14(Mmdl *mmdl);
int func_0219DE24(Mmdl *mmdl);
int func_0219DE34(Mmdl *mmdl);
int func_0219DE44(Mmdl *mmdl);
int func_0219DE54(Mmdl *mmdl);
void func_0219DE64(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus);
int func_0219DE98(Mmdl *mmdl);
int func_0219DECC(Mmdl *mmdl);
int func_0219DEDC(Mmdl *mmdl);
int func_0219DEEC(Mmdl *mmdl);
int func_0219DEFC(Mmdl *mmdl);
int func_0219DF0C(Mmdl *mmdl);
int func_0219DF1C(Mmdl *mmdl);
int func_0219DF2C(Mmdl *mmdl);
int func_0219DF3C(Mmdl *mmdl);
int func_0219DF4C(Mmdl *mmdl);
int func_0219DF5C(Mmdl *mmdl);
int func_0219DF6C(Mmdl *mmdl);
int func_0219DF7C(Mmdl *mmdl);
int func_0219DF8C(Mmdl *mmdl);
int func_0219DF9C(Mmdl *mmdl);
int func_0219DFAC(Mmdl *mmdl);
int func_0219DFBC(Mmdl *mmdl);
int func_0219DFCC(Mmdl *mmdl);
int func_0219DFDC(Mmdl *mmdl);
int func_0219DFEC(Mmdl *mmdl);
int func_0219DFFC(Mmdl *mmdl);
void func_0219E00C(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 seNo);
void func_0219E084(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep);
int func_0219E0A8(Mmdl *mmdl);
int func_0219E1B0(Mmdl *mmdl);
int func_0219E1D0(Mmdl *mmdl);
int func_0219E1F4(Mmdl *mmdl);
int func_0219E218(Mmdl *mmdl);
int func_0219E238(Mmdl *mmdl);
int func_0219E258(Mmdl *mmdl);
int func_0219E27C(Mmdl *mmdl);
int func_0219E29C(Mmdl *mmdl);

/* fldmmdl_rail.c */
void func_0219E2F4(Mmdl *mmdl, RailLocation *location);
int func_0219E334(Mmdl *mmdl, RailLocation *location);
void *func_0219E348(Mmdl *mmdl);
void func_0219E354(Mmdl *mmdl);
void func_0219E370(Mmdl *mmdl, u32 dir, u32 frames);
void func_0219E6C8(Mmdl *mmdl, u16 dir);
void func_0219E784(Mmdl *mmdl, u32 dir, s16 *vec);

/* Display direction for each 1/16 turn of the camera relative angle. */
extern u8 d_021D80E4[];
/* Jump height tables (16 entries each), indexed by RailAcmdJumpWork.heightTable. */
extern s32 *d_021DDD94[];

/* Move proc init of the rail move. */
int func_0219D6B8(Mmdl *mmdl)
{
    func_0216D6F4(mmdl);
    return (int)func_0216D548(mmdl, 2);
}

/* Per-frame update of a field model on a rail: anime command or move proc,
 * with the map attribute procs before and after. */
void func_0219D6CC(Mmdl *mmdl)
{
    if (func_0216DA20(mmdl, 2) == 0) {
        func_0219D7AC(mmdl);
        func_0219D7D0(mmdl);
        if (func_0216D57C(mmdl, _MOVEBIT_ACMD) != 0) {
            func_02197EB4(mmdl);
        } else if (func_0216DB10(mmdl) == 0 && func_0219D780(mmdl) == 1) {
            func_0216D708(mmdl);
        }
        func_0219D7F0(mmdl);
        func_0219D824(mmdl);
    }
}

/* Map attribute at a rail location of the field model's rail mapper. */
int func_0219D724(Mmdl *mmdl, RailLocation *location)
{
    return func_021BB3C4(func_0216D530(func_0216D67C(mmdl)), location);
}

/* Display direction of the field model's rail direction seen at `angle`. */
u32 func_0219D738(Mmdl *mmdl, int angle)
{
    s16 vec[4];
    int relAngle;
    func_0219E784(mmdl, func_0216D5F8(mmdl), vec);
    vec[1] = 0;
    func_0207CDB8(vec, vec);
    relAngle = func_0207CFB8(vec[0], vec[2]) - angle;
    if (relAngle < 0) {
        relAngle += 0x10000;
    }
    return d_021D80E4[relAngle >> 12];
}

int func_0219D780(Mmdl *mmdl)
{
    if (func_0216DA5C(mmdl) == 1) {
        return 1;
    }
    if (func_0216D57C(mmdl, _MOVEBIT_ATTR_GET_ERROR) == 0) {
        return 1;
    }
    func_0216D5A0(mmdl);
    return 1;
}

void func_0219D7AC(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, _MOVEBIT_ATTR_GET_ERROR) != 0 && func_0219D85C(mmdl) == 1) {
        func_0216DA70(mmdl);
    }
}

void func_0219D7D0(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, _MOVEBIT_MOVE_START) != 0) {
        func_0219D8DC(mmdl);
    }
    func_0216D570(mmdl, _MOVEBIT_MOVE_START | _MOVEBIT_JUMP_START);
}

void func_0219D7F0(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, _MOVEBIT_JUMP_START) != 0) {
        func_0219D990(mmdl);
    } else if (func_0216D57C(mmdl, _MOVEBIT_MOVE_START) != 0) {
        func_0219D930(mmdl);
    }
    func_0216D570(mmdl, _MOVEBIT_MOVE_START | _MOVEBIT_JUMP_START);
}

void func_0219D824(Mmdl *mmdl)
{
    if (func_0216D57C(mmdl, _MOVEBIT_JUMP_END) != 0) {
        func_0219DA20(mmdl);
    } else if (func_0216D57C(mmdl, _MOVEBIT_MOVE_END) != 0) {
        func_0219D9D8(mmdl);
    }
    func_0216D570(mmdl, _MOVEBIT_MOVE_END | _MOVEBIT_JUMP_END);
}

/* Reads the map attributes at the current and the previous rail location;
 * returns 0 (and sets _MOVEBIT_ATTR_GET_ERROR) when there is none. */
u32 func_0219D85C(Mmdl *mmdl)
{
    RailLocation prevLocation;
    RailLocation nowLocation;
    u32 attrOld = _ATTR_NONE;
    u32 attrNow = _ATTR_NONE;
    void *railMapper;
    if (func_0216DCB4(mmdl) == 0) {
        railMapper = func_0216D530(func_0216D67C(mmdl));
        func_0219E2F4(mmdl, &nowLocation);
        func_0219E334(mmdl, &prevLocation);
        attrOld = func_021BB3C4(railMapper, &prevLocation);
        attrNow = func_021BB3C4(railMapper, &nowLocation);
    }
    func_0216D7E0(mmdl, attrOld);
    func_0216D7D8(mmdl, attrNow);
    if (attrNow == _ATTR_NONE) {
        func_0216D568(mmdl, _MOVEBIT_ATTR_GET_ERROR);
        return 0;
    }
    func_0216D570(mmdl, _MOVEBIT_ATTR_GET_ERROR);
    return 1;
}

void func_0219D8DC(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (func_0219D85C(mmdl) != 0 && func_0216DB24(mmdl) == 1) {
        attrNow = func_0216D7DC(mmdl);
        attrOld = func_0216D7E4(mmdl);
        param = func_0216E3C4(mmdl);
        func_0219DA80(mmdl, attrNow, attrOld, param);
        func_0219DB04(mmdl, attrNow, attrOld, param);
        func_0219DB5C(mmdl, attrNow, attrOld, param);
    }
}

void func_0219D930(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (func_0219D85C(mmdl) != 0 && func_0216DB24(mmdl) == 1) {
        attrNow = func_0216D7DC(mmdl);
        attrOld = func_0216D7E4(mmdl);
        param = func_0216E3C4(mmdl);
        func_0219DAA4(mmdl, attrNow, attrOld, param);
        func_0219DAD0(mmdl, attrNow, attrOld, param);
        func_0219DB0C(mmdl, attrNow, attrOld, param);
        func_0219DB5C(mmdl, attrNow, attrOld, param);
    }
}

void func_0219D990(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (func_0219D85C(mmdl) != 0 && func_0216DB24(mmdl) == 1) {
        attrNow = func_0216D7DC(mmdl);
        attrOld = func_0216D7E4(mmdl);
        param = func_0216E3C4(mmdl);
        func_0219DB0C(mmdl, attrNow, attrOld, param);
        func_0219DB5C(mmdl, attrNow, attrOld, param);
    }
}

void func_0219D9D8(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (func_0219D85C(mmdl) != 0 && func_0216DB24(mmdl) == 1) {
        attrNow = func_0216D7DC(mmdl);
        attrOld = func_0216D7E4(mmdl);
        param = func_0216E3C4(mmdl);
        func_0219DBC8(mmdl, attrNow, attrOld, param);
        func_0219DB44(mmdl, attrNow, attrOld, param);
    }
}

void func_0219DA20(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (func_0219D85C(mmdl) != 0 && func_0216DB24(mmdl) == 1) {
        attrNow = func_0216D7DC(mmdl);
        attrOld = func_0216D7E4(mmdl);
        param = func_0216E3C4(mmdl);
        func_0219DBC8(mmdl, attrNow, attrOld, param);
        func_0219DB44(mmdl, attrNow, attrOld, param);
        func_0219DAA4(mmdl, attrNow, attrOld, param);
        func_0219DB48(mmdl, attrNow, attrOld, param);
    }
}

void func_0219DA80(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    if (func_021AB0F8(attrNow) & _ATTRFLAG_GRASS)
        func_021AC760(func_0219DC08(mmdl), mmdl, 0, 0);
}

void func_0219DAA4(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    if (attrNow != _ATTR_NONE && (func_021AB0F8(attrNow) & _ATTRFLAG_GRASS))
        func_021AC760(func_0219DC08(mmdl), mmdl, 1, 0);
}

void func_0219DAD0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    u32 fldEffCtrl;
    int cycle;
    if (attrOld != _ATTR_NONE && (func_021AB0F8(attrOld) & _ATTRFLAG_FOOTMARK)) {
        fldEffCtrl = func_0219DC08(mmdl);
        cycle = 0;
        if (param->footMarkType == 2)
            cycle = 1;
        func_021BBDD4(mmdl, fldEffCtrl, cycle);
    }
}

void func_0219DB04(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    func_0219DB0C(mmdl, attrNow, attrOld, param);
}

void func_0219DB0C(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    if (func_0216D98C(func_0216D67C(mmdl)) != 0) {
        if (func_0216D57C(mmdl, _MOVEBIT_SHADOW_SET) == 0) {
            func_021AC2C0(mmdl, func_0219DC08(mmdl));
            func_0216D568(mmdl, _MOVEBIT_SHADOW_SET);
        }
    }
}

void func_0219DB44(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
}

int func_0219DB48(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    return func_021AC578(mmdl, func_0219DC08(mmdl));
}

void func_0219DB5C(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    u32 reflectAttr;
    u32 fldEffCtrl;
    void *mmdlSys;
    if (param->reflectType != 0 && func_0216DC34(mmdl) == 0) {
        reflectAttr = _ATTR_NONE;
        if (attrNow != _ATTR_NONE) {
            if (func_021AB0F8(attrNow) & _ATTRFLAG_REFLECT) {
                reflectAttr = attrNow;
            } else {
                attrNow = func_02163F40(mmdl, _DIR_DOWN);
                if (func_021AB0F8(attrNow) & _ATTRFLAG_REFLECT) {
                    reflectAttr = attrNow;
                }
            }
            if (reflectAttr != _ATTR_NONE) {
                fldEffCtrl = func_0219DC08(mmdl);
                mmdlSys = func_0216D67C(mmdl);
                func_0216DC18(mmdl, 1);
                func_021BBFB8(mmdlSys, mmdl, fldEffCtrl, 1);
            }
        }
    }
}

void func_0219DBC8(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    int attrBelow;
    if (param->reflectType != 0 && func_0216DC34(mmdl) != 0) {
        attrBelow = func_02163F40(mmdl, _DIR_DOWN);
        if (attrBelow == -1) {
            func_0216DC18(mmdl, 0);
            return;
        }
        if ((func_021AB0F8(attrBelow) & _ATTRFLAG_REFLECT) == 0) {
            func_0216DC18(mmdl, 0);
        }
    }
}

/* Field effect control of the field map that owns the field model. */
u32 func_0219DC08(Mmdl *mmdl)
{
    return func_02188CD0(func_0216D534(func_0216D67C(mmdl)));
}

/* Anime command step: end of the command. */
int func_0219DC18(Mmdl *mmdl)
{
    func_0216D568(mmdl, _MOVEBIT_ACMD_END);
    return 0;
}

/* Anime command step: nothing, go to the next step. */
int func_0219DC28(Mmdl *mmdl)
{
    func_0216D7CC(mmdl);
    return 1;
}

void func_0219DC34(Mmdl *mmdl, u32 dir)
{
    func_0216D5E0(mmdl, (u16)dir);
    func_0216D674(mmdl, _DRAW_STA_STOP);
    func_02163F10(mmdl);
    func_0216D7CC(mmdl);
}

int func_0219DC58(Mmdl *mmdl)
{
    func_0219DC34(mmdl, _DIR_UP);
    return 1;
}

int func_0219DC64(Mmdl *mmdl)
{
    func_0219DC34(mmdl, _DIR_DOWN);
    return 1;
}

int func_0219DC70(Mmdl *mmdl)
{
    func_0219DC34(mmdl, _DIR_LEFT);
    return 1;
}

int func_0219DC7C(Mmdl *mmdl)
{
    func_0219DC34(mmdl, _DIR_RIGHT);
    return 1;
}

void func_0219DC88(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus)
{
    func_0219E370(mmdl, (u16)dir, frames);
    func_0219E6C8(mmdl, dir);
    func_0216D60C(mmdl, (u16)dir);
    func_0216D674(mmdl, drawStatus);
    func_0216D568(mmdl, _MOVEBIT_MOVE_START);
    func_0216D7CC(mmdl);
}

int func_0219DCC4(Mmdl *mmdl)
{
    void *railWork;
    VecFx32 pos;
    railWork = func_0219E348(mmdl);
    func_0219E354(mmdl);
    func_021B8028(railWork, &pos);
    func_0216D89C(mmdl, &pos);
    if (func_021B8040(railWork)) {
        return 0;
    }
    func_0216D568(mmdl, _MOVEBIT_MOVE_END | _MOVEBIT_ACMD_END);
    func_0216D674(mmdl, _DRAW_STA_STOP);
    func_0216D7CC(mmdl);
    return 0;
}

/* Anime command step: end of a walk command (stop animation). */
int func_0219DD18(Mmdl *mmdl)
{
    func_0216D674(mmdl, _DRAW_STA_STOP);
    return 0;
}

int func_0219DD24(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_UP, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DD34(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_DOWN, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DD44(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_LEFT, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DD54(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_RIGHT, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DD64(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_UP, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DD74(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_DOWN, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DD84(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_LEFT, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DD94(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_RIGHT, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DDA4(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_UP, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DDB4(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_DOWN, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DDC4(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_LEFT, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DDD4(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_RIGHT, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DDE4(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_UP, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DDF4(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_DOWN, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DE04(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_LEFT, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DE14(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_RIGHT, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DE24(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_UP, 4, _DRAW_STA_DASH_4F); return 1; }
int func_0219DE34(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_DOWN, 4, _DRAW_STA_DASH_4F); return 1; }
int func_0219DE44(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_LEFT, 4, _DRAW_STA_DASH_4F); return 1; }
int func_0219DE54(Mmdl *mmdl) { func_0219DC88(mmdl, _DIR_RIGHT, 4, _DRAW_STA_DASH_4F); return 1; }

void func_0219DE64(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus)
{
    RailAcmdStayWalkWork *work = func_0216D6BC(mmdl, sizeof(RailAcmdStayWalkWork), frames);
    work->drawStatus = drawStatus;
    work->frameCount = frames;
    func_0216D5E0(mmdl, (u16)dir);
    func_0216D674(mmdl, drawStatus);
    func_02163F10(mmdl);
    func_0216D7CC(mmdl);
}

int func_0219DE98(Mmdl *mmdl)
{
    RailAcmdStayWalkWork *work = func_0216D6D4(mmdl);
    work->frameCount--;
    if (work->frameCount > 0)
        return 0;
    func_0216D568(mmdl, _MOVEBIT_ACMD_END);
    func_0216D674(mmdl, _DRAW_STA_STOP);
    func_0216D7CC(mmdl);
    return 1;
}

int func_0219DECC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_UP, 32, _DRAW_STA_WALK_32F); return 1; }
int func_0219DEDC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_DOWN, 32, _DRAW_STA_WALK_32F); return 1; }
int func_0219DEEC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_LEFT, 32, _DRAW_STA_WALK_32F); return 1; }
int func_0219DEFC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_RIGHT, 32, _DRAW_STA_WALK_32F); return 1; }
int func_0219DF0C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_UP, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DF1C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_DOWN, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DF2C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_LEFT, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DF3C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_RIGHT, 16, _DRAW_STA_WALK_16F); return 1; }
int func_0219DF4C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_UP, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DF5C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_DOWN, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DF6C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_LEFT, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DF7C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_RIGHT, 8, _DRAW_STA_WALK_8F); return 1; }
int func_0219DF8C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_UP, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DF9C(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_DOWN, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DFAC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_LEFT, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DFBC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_RIGHT, 2, _DRAW_STA_WALK_2F); return 1; }
int func_0219DFCC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_UP, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DFDC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_DOWN, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DFEC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_LEFT, 4, _DRAW_STA_WALK_4F); return 1; }
int func_0219DFFC(Mmdl *mmdl) { func_0219DE64(mmdl, _DIR_RIGHT, 4, _DRAW_STA_WALK_4F); return 1; }

void func_0219E00C(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 seNo)
{
    RailAcmdJumpWork *work;
    work = func_0216D6BC(mmdl, sizeof(RailAcmdJumpWork), speed);
    work->dir = dir;
    work->speed = speed;
    work->frameCount = frames;
    work->drawStatus = drawStatus;
    work->heightTable = heightTable;
    work->heightStep = heightStep;
    if (speed == 0) {
        func_02163F10(mmdl);
    } else {
        func_0219E370(mmdl, (u16)dir, 8);
        func_0219E6C8(mmdl, dir);
    }
    func_0216D568(mmdl, _MOVEBIT_MOVE_START | _MOVEBIT_JUMP_START);
    func_0216D60C(mmdl, (u16)dir);
    func_0216D674(mmdl, drawStatus);
    func_0216D7CC(mmdl);
    if (seNo) {
        func_020061E4(seNo);
    }
}

void func_0219E084(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep)
{
    func_0219E00C(mmdl, dir, speed, frames, drawStatus, heightTable, heightStep, _SE_RAIL_JUMP);
}

int func_0219E0A8(Mmdl *mmdl)
{
    RailAcmdJumpWork *work;
    void *railWork;
    s32 absSpeed;
    s32 heightIndex;
    s32 table;
    VecFx32 pos;
    VecFx32 offset;
    s32 zeroOffset[3]; /* stand-in: a VecFx32 here moves it on the stack; the s32[3] seen through a VecFx32 pointer keeps the layout */
    work = func_0216D6D4(mmdl);
    work->frameCount--;
    if (work->speed != 0) {
        railWork = func_0219E348(mmdl);
        func_0219E354(mmdl);
        func_021B8028(railWork, &pos);
        func_0216D89C(mmdl, &pos);
        if (work->moveAcc >= 0x10000 && work->frameCount > 0) {
            work->moveAcc = 0;
            func_0219E370(mmdl, work->dir, 8);
            func_0219E6C8(mmdl, work->dir);
            func_0216D568(mmdl, _MOVEBIT_MOVE_START);
        }
        absSpeed = work->speed;
        if (absSpeed < 0) {
            absSpeed = -absSpeed;
        }
        work->moveAcc += absSpeed;
    }
    work->heightPos += work->heightStep;
    if (work->heightPos > 0xF00) {
        work->heightPos = 0xF00;
    }
    heightIndex = (u16)(work->heightPos / 256);
    table = work->heightTable;
    offset.x = 0;
    offset.y = d_021DDD94[table][heightIndex];
    offset.z = 0;
    func_0216D8C0(mmdl, &offset);
    if (work->frameCount > 0 || func_021B8040(railWork)) {
        return 0;
    }
    {
        VecFx32 *zero = (VecFx32 *)zeroOffset;
        zero->x = 0;
        zero->y = 0;
        zero->z = 0;
        func_0216D8C0(mmdl, zero);
    }
    func_0216D568(mmdl, _MOVEBIT_MOVE_END | _MOVEBIT_JUMP_END | _MOVEBIT_ACMD_END);
    func_02163F10(mmdl);
    func_0216D674(mmdl, _DRAW_STA_STOP);
    func_0216D7CC(mmdl);
    func_020061E4(_SE_RAIL_LAND);
    return 1;
}

int func_0219E1B0(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_UP, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int func_0219E1D0(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_DOWN, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int func_0219E1F4(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_LEFT, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int func_0219E218(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_RIGHT, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int func_0219E238(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_UP, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
int func_0219E258(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_DOWN, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
int func_0219E27C(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_LEFT, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
int func_0219E29C(Mmdl *mmdl) { func_0219E084(mmdl, _DIR_RIGHT, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
