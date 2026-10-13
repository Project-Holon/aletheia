/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008700
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: SYSTEM_DATA_GetSize, SYSTEM_DATA_Init, SYSTEM_DATA_GetMyStatus, SYSTEM_DATA_GetConfig,
 *           SYSTEM_DATA_GetPlayTime, SYSTEM_DATA_IsActive, SYSTEM_DATA_SetActive, SYSTEM_DATA_ClearActive,
 *           SYSTEM_DATA_IsMarked, SYSTEM_DATA_SetMark, SYSTEM_DATA_ClearMark, SYSTEM_DATA_GetWordSlot,
 *           SYSTEM_DATA_SetMyStatus, SYSTEM_DATA_CopyMyStatus
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   sub_02008320    0x02008320  thumb
 *   sub_020084A0    0x020084A0  thumb
 *   PLAYTIME_Init    0x020085A0  thumb
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *
 * alias: a save block and its accessors.  The unit is bounded on both sides by
 * the "how big is my block" function each of these files opens with:
 * SYSTEM_DATA_GetSize returns 0x68, which is exactly what SYSTEM_DATA_Init clears, and
 * the four bytes at 0x02008828 are the same two instructions returning 0x9C,
 * which is what the function after them clears.  So the range is
 * 0x02008700..0x02008828, 296 bytes and fourteen functions, closed at both
 * ends by that shape.
 *
 * Every accessor here reaches its object the same way: SAVE_CONTROL_GetBlock(sys, 0x1B).
 * 0x1B is this block's id, and the call is the only thing the fourteen
 * functions have in common, which is what says they are one file.  The three
 * sub-objects SYSTEM_DATA_Init initialises identify the layout:
 *
 *   +0x00  4 bytes   initialised by sub_02008320
 *   +0x04  0x20      the accessor object of unit_0200852C.c, initialised by
 *                    sub_020084A0, which is the function immediately before
 *                    unit_020084BC.c and calls MYSTATUS_SetAvatarId out of it
 *   +0x24  8 bytes   the playtime object of unit_020085A0.c
 *   +0x2C  u8        a flag, set by SYSTEM_DATA_SetActive and cleared by SYSTEM_DATA_ClearActive
 *   +0x30  u16[10]   a table of marks, each either 0 or 0xC21E
 *   +0x44  u32[9]    a table SYSTEM_DATA_GetWordSlot hands out addresses into
 *                    (0x44 + 9 * 4 = 0x68, which closes the object)
 *
 * Two shapes in here are worth naming:
 *
 *  - SYSTEM_DATA_SetMyStatus and SYSTEM_DATA_CopyMyStatus copy the 0x20-byte sub-object in and out
 *    with four ldm/stm pairs and no call.  That is a plain struct assignment:
 *    mwccarm inlines an aggregate copy of this size rather than calling a
 *    memcpy, and it uses the padded sizeof (0x20) rather than the 0x1E bytes
 *    of declared members.
 *  - SYSTEM_DATA_GetConfig is a tail call through a pool word with the second argument
 *    set up first (`ldr r3, =SAVE_CONTROL_GetBlock+1; movs r1, #0x1B; bx r3`), which is
 *    what `return SAVE_CONTROL_GetBlock(sys, 0x1B);` compiles to when nothing follows
 *    the call.  Its neighbours all do something to the result and therefore
 *    keep a real frame.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008700.c \
 *       --addr 0x02008700 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

/* The three sub-object constructors, each in a file of its own. */
struct Flags02008320;
extern void sub_02008320(struct Flags02008320 *p);
struct Sub0200852CObj;
extern void sub_020084A0(struct Sub0200852CObj *obj);
struct PlayTime;
struct Sub020071CCCtrl;
extern void PLAYTIME_Init(struct PlayTime *p);

/* Save-block lookup: returns the block with the given id. */
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

#define BLOCK_ID 0x1B

struct Sub0200852CObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B;
    u8  unk1C;
    u8  unk1D;
};

struct PlayTime {
    u16 hours;
    u8  minutes;
    u8  seconds;
    u32 stamp;
};

struct Sub02008700Obj {
    u32 unk00;
    struct Sub0200852CObj unk04;
    struct PlayTime unk24;
    u8  unk2C;
    u8  unk2D[3];
    u16 unk30[10];
    u32 unk44[9];
};

/* The carrier the 0x20-byte sub-object is copied to and from. */
struct Sub020087E8Arg {
    u8 unk00[0x20];
    struct Sub0200852CObj unk20;
};

u32 SYSTEM_DATA_GetSize(void)
{
    return sizeof(struct Sub02008700Obj);
}

void SYSTEM_DATA_Init(struct Sub02008700Obj *obj)
{
    MIi_CpuClear32(0, obj, sizeof(struct Sub02008700Obj));
    sub_02008320((struct Flags02008320 *)(&obj->unk00));
    sub_020084A0(&obj->unk04);
    PLAYTIME_Init(&obj->unk24);
    obj->unk2C = 0;
}

struct Sub0200852CObj *SYSTEM_DATA_GetMyStatus(void *sys)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    return &obj->unk04;
}

struct Sub02008700Obj *SYSTEM_DATA_GetConfig(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
}

struct PlayTime *SYSTEM_DATA_GetPlayTime(void *sys)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    return &obj->unk24;
}

u8 SYSTEM_DATA_IsActive(void *sys)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    return obj->unk2C;
}

void SYSTEM_DATA_SetActive(void *sys)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    obj->unk2C = 1;
}

void SYSTEM_DATA_ClearActive(void *sys)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    obj->unk2C = 0;
}

int SYSTEM_DATA_IsMarked(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    if (obj->unk30[index] == 0xC21E) {
        return 1;
    }
    return 0;
}

void SYSTEM_DATA_SetMark(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    obj->unk30[index] = 0xC21E;
}

void SYSTEM_DATA_ClearMark(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    obj->unk30[index] = 0;
}

u32 *SYSTEM_DATA_GetWordSlot(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    return &obj->unk44[index];
}

void SYSTEM_DATA_SetMyStatus(void *sys, const struct Sub020087E8Arg *src)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    obj->unk04 = src->unk20;
}

void SYSTEM_DATA_CopyMyStatus(void *sys, struct Sub020087E8Arg *dest)
{
    struct Sub02008700Obj *obj = SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
    dest->unk20 = obj->unk04;
}
