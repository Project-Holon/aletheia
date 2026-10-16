/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02009210
 * packet:   pkt_02009210
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BLOCK20_SAVEDATA_GetBlock, BLOCK20_SAVEDATA_GetBlockFromSys, BLOCK20_SAVEDATA_GetBlockSize, BLOCK20_SAVEDATA_InitBlock,
 *           BLOCK20_SAVEDATA_GetPokemon, BLOCK20_SAVEDATA_SetPokemon, BLOCK20_SAVEDATA_TestBit, BLOCK20_SAVEDATA_SetMode,
 *           BLOCK20_SAVEDATA_GetMode, BLOCK20_SAVEDATA_SetPending, BLOCK20_SAVEDATA_GetPending, BLOCK20_SAVEDATA_SetActive,
 *           BLOCK20_SAVEDATA_GetActive, BLOCK20_SAVEDATA_GetEntryId, BLOCK20_SAVEDATA_GetEntryValue, BLOCK20_SAVEDATA_SetEntry,
 *           BLOCK20_SAVEDATA_ClearEntry, BLOCK20_SAVEDATA_CountEntries, BLOCK20_SAVEDATA_GetRecord, BLOCK20_SAVEDATA_SetRecord,
 *           BLOCK20_SAVEDATA_GetDateStamp, BLOCK20_SAVEDATA_SetDateStamp, BLOCK20_SAVEDATA_GetSavedValue, BLOCK20_SAVEDATA_SetSavedValue,
 *           BLOCK20_SAVEDATA_GetProgress, BLOCK20_SAVEDATA_SetProgress, BLOCK20_SAVEDATA_GetFlag, BLOCK20_SAVEDATA_SetFlag
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock   0x020071CC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *
 * alias: the head of the save block with id 0x20, 0x1AC bytes.  The file opens
 * the way every block file in this region does: a twelve byte thunk that is
 * `SAVE_CONTROL_GetBlock(sys, 0x20)`, a four byte function returning the block size, and
 * a constructor that clears exactly that size.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md; only eight of
 * these twenty-eight functions carry a label.
 *
 * The block is
 *
 *   +0x000  u32         a stamp, 0xDA010100, written through BLOCK20_SAVEDATA_SetDateStamp
 *   +0x004  s32         initialised to -1
 *   +0x008  u8[0xDC]    a blob copied in and out whole
 *   +0x0E4  u16[20]     paired with
 *   +0x10C  u8 [20]     ... one entry each
 *   +0x120  Entry[5]    0x1A bytes each, first halfword seeded to 0x7E
 *   +0x1A2  u8[8]       flags, two of them bitfields
 *
 * The bound on the two parallel arrays is off by one in the original and it is
 * off by one in both directions: the guard is `i > 20` on twenty entry arrays,
 * so index 20 writes the first byte of the array after it, while the counter
 * in BLOCK20_SAVEDATA_CountEntries stops at 19.  Writing the guard as `i >= 20` costs nothing
 * in the C and changes the compare, so the off-by-one is part of the match.
 *
 * BLOCK20_SAVEDATA_TestBit is the signed-index bit test: `n >> 3` is a plain `lsrs` and
 * `n % 8` is the four instruction `lsrs #31` / `lsls #29` / `subs` / `rors #29`
 * sequence, which is the same split docs/MATCHING.md records for
 * sub_0200A6BC.  `& 7` would be two instructions and `/ 8` would add a rounding
 * correction, so the source really does spell the two halves differently.
 * The byte index is the one place a cast is needed: `n >> 3` on the signed
 * parameter is an `asrs`, and only `(u32)n >> 3` gives the original's `lsrs`.
 *
 * The byte at +0x1A6 is two bitfields, `u8 : 7` and `u8 : 1`, and the four
 * accessors on it say so: the getters end in `lsls #0x19` / `lsrs #0x19` and
 * `lsls #0x18` / `lsrs #0x1F`, widths that are not any integer type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.  Both setters
 * take `int`, not `u8`: the `cmp #5` in BLOCK20_SAVEDATA_SetProgress is `blt` rather than
 * `blo`, and both carry a `lsls #0x18` / `lsrs #0x18` truncation to u8 in
 * front of the field mask that an already-u8 parameter does not produce.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009210.c \
 *       --addr 0x02009210 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Big;
struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);

#define BLOCK_ID 0x20

struct Sub02009210Ent {
    u16 unk00;
    u8  unk02[0x18];
};

struct Sub02009210Obj {
    u32 unk000;
    s32 unk004;
    u8  unk008[0xDC];
    u16 unk0E4[20];
    u8  unk10C[20];
    struct Sub02009210Ent unk120[5];
    u8  unk1A2;
    u8  unk1A3;
    u8  unk1A4;
    u8  unk1A5;
    u8  unk1A6_0 : 7;
    u8  unk1A6_7 : 1;
    u8  unk1A7;
    u8  unk1A8;
    u8  unk1A9;
};

struct Sub02009210Obj *BLOCK20_SAVEDATA_GetBlock(void *sys);
u32  BLOCK20_SAVEDATA_GetBlockSize(void);
void BLOCK20_SAVEDATA_SetEntry(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
u8   BLOCK20_SAVEDATA_GetEntryValue(const struct Sub02009210Obj *obj, int i);
void BLOCK20_SAVEDATA_SetDateStamp(struct Sub02009210Obj *obj, u32 value);

struct Sub02009210Obj *BLOCK20_SAVEDATA_GetBlock(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
}

struct Sub02009210Obj *BLOCK20_SAVEDATA_GetBlockFromSys(void *p)
{
    return BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(p));
}

u32 BLOCK20_SAVEDATA_GetBlockSize(void)
{
    return sizeof(struct Sub02009210Obj);
}

void BLOCK20_SAVEDATA_InitBlock(struct Sub02009210Obj *obj)
{
    u8 i;

    MI_CpuFill8(obj, 0, BLOCK20_SAVEDATA_GetBlockSize());
    BLOCK20_SAVEDATA_SetDateStamp(obj, 0xDA010100);
    obj->unk004 = -1;
    obj->unk1A7 = 0;
    obj->unk1A8 = 0;
    obj->unk1A9 = 0;
    obj->unk1A6_0 = 0x7F;
    for (i = 0; i < 5; i++) {
        obj->unk120[i].unk00 = 0x7E;
    }
}

u8 *BLOCK20_SAVEDATA_GetPokemon(struct Sub02009210Obj *obj)
{
    return obj->unk008;
}

void BLOCK20_SAVEDATA_SetPokemon(struct Sub02009210Obj *obj, const void *src)
{
    MI_CpuCopy8(src, obj->unk008, POKE_TOOL_GetPartyParamSize());
}

u32 BLOCK20_SAVEDATA_TestBit(const u8 *bits, int n)
{
    u32 ret = 1;

    if (!(bits[(u32)n >> 3] & (1 << (n % 8)))) {
        ret = 0;
    }
    return ret;
}

void BLOCK20_SAVEDATA_SetMode(struct Sub02009210Obj *obj, u8 value)
{
    obj->unk1A4 = value;
}

u8 BLOCK20_SAVEDATA_GetMode(const struct Sub02009210Obj *obj)
{
    return obj->unk1A4;
}

void BLOCK20_SAVEDATA_SetPending(struct Sub02009210Obj *obj, u8 value)
{
    obj->unk1A5 = value;
}

u8 BLOCK20_SAVEDATA_GetPending(const struct Sub02009210Obj *obj)
{
    return obj->unk1A5;
}

void BLOCK20_SAVEDATA_SetActive(struct Sub02009210Obj *obj, u8 value)
{
    obj->unk1A3 = value;
}

u8 BLOCK20_SAVEDATA_GetActive(const struct Sub02009210Obj *obj)
{
    return obj->unk1A3;
}

u16 BLOCK20_SAVEDATA_GetEntryId(const struct Sub02009210Obj *obj, int i)
{
    u16 value;

    if (i > 20) {
        return 0;
    }
    value = obj->unk0E4[i];
    if (value > 0x272) {
        value = 0;
    }
    return value;
}

u8 BLOCK20_SAVEDATA_GetEntryValue(const struct Sub02009210Obj *obj, int i)
{
    u8 value;

    if (i > 20) {
        return 0;
    }
    value = obj->unk10C[i];
    if (value > 20) {
        value = 0;
    }
    return value;
}

void BLOCK20_SAVEDATA_SetEntry(struct Sub02009210Obj *obj, int i, u16 a, u8 b)
{
    if (i > 20) {
        return;
    }
    obj->unk0E4[i] = a;
    obj->unk10C[i] = b;
}

void BLOCK20_SAVEDATA_ClearEntry(struct Sub02009210Obj *obj, int i)
{
    BLOCK20_SAVEDATA_SetEntry(obj, i, 0, 0);
}

u32 BLOCK20_SAVEDATA_CountEntries(const struct Sub02009210Obj *obj)
{
    u32 count = 0;
    int i;

    for (i = 0; i < 20; i++) {
        if (BLOCK20_SAVEDATA_GetEntryValue(obj, i) != 0) {
            count++;
        }
    }
    return count;
}

struct Sub02009210Ent *BLOCK20_SAVEDATA_GetRecord(struct Sub02009210Obj *obj, int i)
{
    if (i < 5) {
        return &obj->unk120[i];
    }
    return 0;
}

void BLOCK20_SAVEDATA_SetRecord(struct Sub02009210Obj *obj, int i, const void *src)
{
    if (i < 5) {
        MI_CpuCopy8(src, &obj->unk120[i], sizeof(obj->unk120[0]));
    }
}

u32 BLOCK20_SAVEDATA_GetDateStamp(const struct Sub02009210Obj *obj)
{
    return obj->unk000;
}

void BLOCK20_SAVEDATA_SetDateStamp(struct Sub02009210Obj *obj, u32 value)
{
    obj->unk000 = value;
}

s32 BLOCK20_SAVEDATA_GetSavedValue(const struct Sub02009210Obj *obj)
{
    return obj->unk004;
}

void BLOCK20_SAVEDATA_SetSavedValue(struct Sub02009210Obj *obj, s32 value)
{
    obj->unk004 = value;
}

u32 BLOCK20_SAVEDATA_GetProgress(const struct Sub02009210Obj *obj)
{
    u32 value = obj->unk1A6_0;

    if (value >= 5 && value != 0x7F) {
        value = 0x7F;
    }
    return value;
}

void BLOCK20_SAVEDATA_SetProgress(struct Sub02009210Obj *obj, int value)
{
    if (value < 5 || value == 0x7F) {
        obj->unk1A6_0 = value;
    }
}

u32 BLOCK20_SAVEDATA_GetFlag(const struct Sub02009210Obj *obj)
{
    return obj->unk1A6_7;
}

void BLOCK20_SAVEDATA_SetFlag(struct Sub02009210Obj *obj, int value)
{
    obj->unk1A6_7 = value;
}
