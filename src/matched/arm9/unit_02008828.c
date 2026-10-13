/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008828
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PLAYER_LOCATION_GetSize, PLAYER_LOCATION_Init, PLAYER_LOCATION_Nop, PLAYER_LOCATION_GetLocationA,
 *           PLAYER_LOCATION_GetLocationB, PLAYER_LOCATION_GetShortData, PLAYER_LOCATION_GetData, PLAYER_LOCATION_SetRecordFromBuffer,
 *           PLAYER_LOCATION_CopyRecordToBuffer, PLAYER_LOCATION_CopyRecord, PLAYER_LOCATION_ReadStyleFrom, PLAYER_LOCATION_WriteStyleTo,
 *           PLAYER_LOCATION_SetFlagA, PLAYER_LOCATION_GetFlagA, PLAYER_LOCATION_SetFlagB, PLAYER_LOCATION_GetFlagB,
 *           PLAYER_LOCATION_SetCounter, PLAYER_LOCATION_GetCounter, PLAYER_LOCATION_GetValueA, PLAYER_LOCATION_SetValueA,
 *           PLAYER_LOCATION_SetValueB, PLAYER_LOCATION_GetValueB, PLAYER_LOCATION_GetZoneId, PLAYER_LOCATION_SetZoneId
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   FIELD_STATUS_IsFlashActive  0x02014468  thumb
 *
 * alias: the save block with id 0x1C, 0x9C bytes, and its accessors.  The
 * range is closed the same way unit_02008700.c is: it opens with the four
 * bytes that return the block size (0x9C, which is what PLAYER_LOCATION_Init clears)
 * and ends where the next such function returns 0x658, at 0x020089A8.  That is
 * the whole 384-byte, twenty-four function file.
 *
 * It was committed as two files for a while, because the pair at 0x0200892C
 * and 0x0200893C reach 0x02014468 and 0x02014464 and nothing else in
 * arm9_main does, so neither address had a witness outside the bytes under
 * test.  Both do have one: ov010 and ov020 branch to them, 0x02014464 is
 * seeded into layout/function_starts.txt from those branches so disasm.py
 * labels it, and cross-region branches now count as `label` evidence.  The
 * file is one unit again and src/matched/unit_0200894C.c is gone.
 *
 * Layout, from the accessors:
 *
 *   +0x00  0x38     untouched here
 *   +0x38  0x1C     handed out by PLAYER_LOCATION_GetLocationA
 *   +0x54  0x1C     handed out by PLAYER_LOCATION_GetLocationB
 *   +0x70  2        handed out by PLAYER_LOCATION_GetShortData
 *   +0x72  u8       written and read by the two unverifiable functions
 *   +0x73  u8
 *   +0x74  u8
 *   +0x76  u16      the only field PLAYER_LOCATION_Init seeds, with 0x1AB
 *   +0x78  u32
 *   +0x7C  u16
 *   +0x7E  u16
 *   +0x80  0x1C     a record, copied in and out field by field by
 *                   PLAYER_LOCATION_SetRecordFromBuffer and PLAYER_LOCATION_CopyRecordToBuffer and copied whole by
 *                   PLAYER_LOCATION_CopyRecord
 *
 * Four of the ten carry no label in the generated listing: they are
 * two-instruction accessors with no register-saving prologue, so disasm.py's
 * sweep never fires on them and the listing emits them as data words.  They
 * were read out of the bytes.
 *
 * Three details pinned this one:
 *
 *  - the record at +0x80 and the buffer PLAYER_LOCATION_SetRecordFromBuffer fills it from are not the
 *    same type, even though their first 0x1C bytes line up.  Two fields cross
 *    over: the record's +0x1A comes from the buffer's +0x1B, and the record's
 *    +0x1B comes from the buffer's +0x40, a word truncated to a byte.  Writing
 *    it as one struct assignment collapses the whole function to an ldm/stm
 *    run and is 80 bytes short.
 *  - the twelve bytes at +0x04 of the record are a nested struct, for the same
 *    reason as in unit_02008700.c: they move as one ldm/stm pair plus a
 *    trailing word while the halfwords around them move one at a time.
 *  - the record's +0x18 is signed and the buffer's is not.  PLAYER_LOCATION_CopyRecordToBuffer reads
 *    it with `movs r0, #0x98; ldrsh r0, [r2, r0]` where every other read in the
 *    function is an immediate-offset ldrh; ldrsh has no immediate form, so the
 *    signedness of one field is what costs that instruction its extra
 *    register.  PLAYER_LOCATION_SetRecordFromBuffer, going the other way, uses a plain ldrh.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008828.c \
 *       --addr 0x02008828 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
struct Sub020071CCCtrl;
struct Sub02014444Obj;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

#define BLOCK_ID 0x1C

/* The twelve bytes that move as one unit. */
struct Sub02008860Inner {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

/* The 0x1C-byte record the block keeps at +0x80. */
struct Sub02008828Rec {
    u16 unk00;
    struct Sub02008860Inner unk04;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    s16 unk18;
    u8  unk1A;
    u8  unk1B;
};

/* The buffer the record is exchanged with.  Its first 0x1C bytes line up with
 * the record but the last two fields do not; see the header. */
struct Sub02008860Buf {
    u16 unk00;
    struct Sub02008860Inner unk04;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u8  unk1C[0x24];
    u32 unk40;
};

struct Sub02008828Obj {
    u8  unk00[0x38];
    u8  unk38[0x1C];
    u8  unk54[0x1C];
    u8  unk70[2];
    u8  unk72;
    u8  unk73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u32 unk78;
    u16 unk7C;
    u16 unk7E;
    struct Sub02008828Rec unk80;
};

u32 PLAYER_LOCATION_GetSize(void)
{
    return sizeof(struct Sub02008828Obj);
}

void PLAYER_LOCATION_Init(struct Sub02008828Obj *obj)
{
    MI_CpuFill8(obj, 0, sizeof(struct Sub02008828Obj));
    obj->unk76 = 0x1AB;
}

void PLAYER_LOCATION_Nop(void)
{
}

void *PLAYER_LOCATION_GetLocationA(struct Sub02008828Obj *obj)
{
    return obj->unk38;
}

void *PLAYER_LOCATION_GetLocationB(struct Sub02008828Obj *obj)
{
    return obj->unk54;
}

void *PLAYER_LOCATION_GetShortData(struct Sub02008828Obj *obj)
{
    return obj->unk70;
}

struct Sub02008828Obj *PLAYER_LOCATION_GetData(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
}

void PLAYER_LOCATION_SetRecordFromBuffer(void *sys, const struct Sub02008860Buf *src)
{
    struct Sub02008828Obj *obj = PLAYER_LOCATION_GetData(sys);

    obj->unk80.unk00 = src->unk00;
    obj->unk80.unk04 = src->unk04;
    obj->unk80.unk10 = src->unk10;
    obj->unk80.unk12 = src->unk12;
    obj->unk80.unk14 = src->unk14;
    obj->unk80.unk16 = src->unk16;
    obj->unk80.unk18 = src->unk18;
    obj->unk80.unk1A = src->unk1B;
    obj->unk80.unk1B = src->unk40;
}

void PLAYER_LOCATION_CopyRecordToBuffer(void *sys, struct Sub02008860Buf *dest)
{
    struct Sub02008828Obj *obj = PLAYER_LOCATION_GetData(sys);

    dest->unk00 = obj->unk80.unk00;
    dest->unk04 = obj->unk80.unk04;
    dest->unk10 = obj->unk80.unk10;
    dest->unk12 = obj->unk80.unk12;
    dest->unk14 = obj->unk80.unk14;
    dest->unk16 = obj->unk80.unk16;
    dest->unk18 = obj->unk80.unk18;
    dest->unk1B = obj->unk80.unk1A;
    dest->unk40 = obj->unk80.unk1B;
}

void PLAYER_LOCATION_CopyRecord(void *sys, struct Sub02008828Rec *dest)
{
    struct Sub02008828Obj *obj = PLAYER_LOCATION_GetData(sys);

    *dest = obj->unk80;
}

/* The getter/setter pair on some other object's byte at +6, through which the
 * +0x72 field of this block is exchanged.  Both are four-byte leaves in the
 * middle of a literal-pool run at 0x02014464 and 0x02014468, and neither is
 * reachable from anything else in arm9_main, which is why these two functions
 * were the last unverifiable ones in this file.  See "The two near misses in
 * this run" in docs/MATCHING.md. */
extern u8 FIELD_STATUS_IsFlashActive(struct Sub02014444Obj *o);
extern void FIELD_STATUS_SetFlashActive(struct Sub02014444Obj *o, u8 v);

void PLAYER_LOCATION_ReadStyleFrom(struct Sub02008828Obj *obj, const void *src)
{
    obj->unk72 = FIELD_STATUS_IsFlashActive((struct Sub02014444Obj *)src);
}

void PLAYER_LOCATION_WriteStyleTo(const struct Sub02008828Obj *obj, void *dest)
{
    FIELD_STATUS_SetFlashActive(dest, obj->unk72);
}

void PLAYER_LOCATION_SetFlagA(struct Sub02008828Obj *obj, u8 value)
{
    obj->unk73 = value;
}

void PLAYER_LOCATION_GetFlagA(const struct Sub02008828Obj *obj, u8 *out)
{
    *out = obj->unk73;
}

void PLAYER_LOCATION_SetFlagB(struct Sub02008828Obj *obj, u8 value)
{
    obj->unk74 = value;
}

void PLAYER_LOCATION_GetFlagB(const struct Sub02008828Obj *obj, u8 *out)
{
    *out = obj->unk74;
}

void PLAYER_LOCATION_SetCounter(struct Sub02008828Obj *obj, u32 value)
{
    obj->unk78 = value;
}

void PLAYER_LOCATION_GetCounter(const struct Sub02008828Obj *obj, u32 *out)
{
    *out = obj->unk78;
}

u16 PLAYER_LOCATION_GetValueA(const struct Sub02008828Obj *obj)
{
    return obj->unk7C;
}

void PLAYER_LOCATION_SetValueA(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk7C = value;
}

void PLAYER_LOCATION_SetValueB(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk7E = value;
}

u16 PLAYER_LOCATION_GetValueB(const struct Sub02008828Obj *obj)
{
    return obj->unk7E;
}

u16 PLAYER_LOCATION_GetZoneId(const struct Sub02008828Obj *obj)
{
    return obj->unk76;
}

void PLAYER_LOCATION_SetZoneId(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk76 = value;
}
