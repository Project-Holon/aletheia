/*
 * file:     gds_profile.c
 * unit:     yes
 * function: GDS_PROFILE_Create, GDS_PROFILE_Delete, GDS_PROFILE_Init, GDS_PROFILE_CreateNameStr, func_0200D6EC, func_0200D6FC, func_0200D70C, func_0200D72C, func_0200D74C, func_0200D760, func_0200D774, func_0200D82C, func_0200D85C, func_0200D868, func_0200D884, func_0200D914, func_0200DA14, func_0200DA28, func_0200DA54, func_0200DA64, func_0200DA6C, func_0200DA80, func_0200DA98, func_0200DD10, func_0200DD18, func_0200DD28, func_0200DD8C, func_0200DDA8, func_0200DDD0
 * address:  0x0200D59C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020307B0       0x020307B0  arm
 *   func_0200D59C_File  0x020A71E8  data
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   STRBUF_GetEosChar    0x02045A98  arm
 *   func_0203F1FC    0x0203F1FC  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   PMSI_PARAM_InitSentence  0x020242A4  thumb
 *   PMS_WORD_MakeWordId  0x02024888  thumb
 *   PMS_WORD_SplitWordId  0x020248D8  thumb
 */
#include "../../matched/include/Obj03045.h"

struct GameSys;
struct ProgressBlock;
struct TrainerRec;
struct SaveDataObj;
struct RecordData;
struct Strbuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct PlayFlags {
    u8 gameCleared : 1;
    u8 playMinutes : 6;
    u8 hasNationalDex : 1;
};

struct GdsProfile_0200D59C {
    u16 name[8];
    u32 trainerId;
    u8  gender;
    u8  birthMonth;
    u8  trainerSprite;
    u8  country;
    u8  region;
    u8  gameVersion;
    u8  language;
    struct PlayFlags play;
    u16 playHours;
    u8  recordIsRaw;
    u8  pad1F;
    u16 record[0x28];
    u8  pad70[0x0C];
    u16 checksum;
    u16 pad7E;
};

typedef signed int     s32;

struct OwnerInfo {
    u8 favoriteColor;
    u8 pad01;
    u8 birthMonth;
    u8 rest[0x51];
};

struct RecGet {
    u8  unk00[0x14];
    u8  unk14;
    u8  unk15[6];
    u8  b0 : 1;
    u8  b1 : 6;
    u8  b7 : 1;
    u16 unk1C;
};

struct GdsRecord {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u8  unk08[0x20];
};

struct GdsProfile_0200D6EC {
    u8  unk00[0x15];
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B[3];
    u8  unk1E;
    u8  unk1F;
    struct GdsRecord unk20;
};

struct Blk3C {
    u16 f0  : 1;
    u16 f1  : 1;
    u16 f2  : 4;
    u16 f6  : 3;
    u16 f9  : 1;
    u16 f10 : 1;
    u16 f11 : 5;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
    u8  unk08[4];
    u8  unk0C[0x1C];
    u8  unk28[0x14];
};

typedef signed short   s16;

struct Blk1AC {
    u16 unk00;
    u8  unk02;
    u8  unk03;
    u32 unk04;
    u16 unk08[9];
    u16 unk1A[9];
    u16 unk2C[9];
    u16 unk3E;
    u32 unk40;
    u8  unk44[0xB4];
    u8  unkF8[0xB4];
};

struct Src {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
};

struct BlkB90 {
    u32 unk00;
    u8  unk04[250];
    u8  unkFE[0xA92];
};

struct Stamp {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void OS_GetOwnerInfo(void *info);
extern u16   STRBUF_GetEosChar(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *GAME_DATA_GetSaveControl(struct GameSys *p);
extern u8 *func_02012944(void *p);
extern void *GAME_DATA_GetMiscSave(int *p);
extern struct SaveDataObj *func_02009470(void *sys);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct RecordData *src, int idx, struct RecordData *dst);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern u32 func_02008530(const struct TrainerRec *obj);
extern u8 func_02008550(const struct TrainerRec *obj);
extern u8 func_02008554(const struct TrainerRec *obj);
extern u8 func_0200856C(const struct TrainerRec *obj);
extern u8 func_02008570(const struct TrainerRec *obj);
extern void func_0200C164(const struct ProgressBlock *p, u32 *a, u32 *b, u32 *c, u32 *d);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(struct Strbuf *strbuf, const u16 *src, u32 length);
extern int func_02019D58(u16 a, int b);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern int PMS_WORD_SplitWordId(u32 v, u32 *a1, u32 *a2);
extern void  PMSI_PARAM_InitSentence(void *rec, u32 n);
extern u16 PMS_WORD_MakeWordId(u32 idx, u16 add);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
struct GdsProfile_0200D59C *GDS_PROFILE_Create(u32 heap);
void GDS_PROFILE_Delete(struct GdsProfile_0200D59C *profile);
void GDS_PROFILE_Init(struct GdsProfile_0200D59C *profile, void *sys);
void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag);
u32 func_0200D6EC(struct RecGet *p);
u32 func_0200D6FC(struct RecGet *p);
u32 func_0200D70C(struct RecGet *p);
u32 func_0200D72C(struct RecGet *p);
u32 func_0200D73C(struct RecGet *p);
u32 func_0200D74C(struct GdsProfile_0200D6EC *p);
u32 func_0200D760(struct GdsProfile_0200D6EC *p);
void *func_0200D774(struct GdsProfile_0200D6EC *p, struct GdsRecord *out, u32 tag);
u32 func_0200D810(struct GdsProfile_0200D6EC *p);
u32 func_0200D820(struct GdsProfile_0200D6EC *p);
u32 func_0200D82C(struct GdsProfile_0200D6EC *p);
u32 func_0200D858(void);
void func_0200D85C(struct Blk3C *p);
void func_0200D868(struct Blk3C *p, u32 v);
u32 func_0200D87C(struct Blk3C *p);
u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
void func_0200D914(struct Blk3C *p, u32 id, const void *src);
void func_0200D9E8(struct Blk3C *p, s32 a, s32 b, s32 c);
void func_0200DA14(struct Blk3C *p);
void func_0200DA28(struct Blk3C *p);
u16 func_0200DA54(struct Blk3C *p);
u32 func_0200DA64(void);
void func_0200DA6C(struct Blk1AC *p);
void func_0200DA80(struct Blk1AC *p, s32 v);
void func_0200DA98(struct Blk1AC *p, u16 v);
u16 func_0200DABC(struct Blk1AC *p);
u32 func_0200DAC0(u32 i);
u16 func_0200DAC4(struct Blk1AC *p, u32 i);
u16 func_0200DAD8(struct Blk1AC *p, u32 i);
void func_0200DAEC(struct Blk1AC *p, u32 i, u16 v);
void func_0200DB08(struct Blk1AC *p, u32 i, u16 v);
void func_0200DB1C(struct Blk1AC *p, u32 i);
void func_0200DB30(struct Blk1AC *p, u32 i);
u32 func_0200DB44(struct Blk1AC *p, u32 i);
void func_0200DB60(struct Blk1AC *p, u32 i);
u16 func_0200DB80(struct Blk1AC *p, u32 i);
u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
void func_0200DBF0(struct Blk1AC *p);
void func_0200DBFC(struct Blk1AC *p);
u8 func_0200DC08(struct Blk1AC *p);
u8 func_0200DC0C(struct Blk1AC *p, u32 kind);
void func_0200DC50(struct Blk1AC *p, u32 which, const void *src);
void func_0200DC74(struct Blk1AC *p, u32 which, void *dest);
void func_0200DC94(struct Blk1AC *p, const struct Src *q);
u16 func_0200DCF8(struct Blk1AC *p);
u8 func_0200DCFC(struct Blk1AC *p);
u32 func_0200DD10(void);
void func_0200DD18(struct BlkB90 *p);
void func_0200DD28(u8 *p, u8 a, u8 b, u32 *q);
void func_0200DD8C(struct BlkB90 *p);
u32 func_0200DDA8(const struct Stamp *a, const struct Stamp *b);
int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q);
extern const char func_0200D59C_File[];



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 52 bytes, 0x0200D59C..0x0200D5D0, 2 functions, one of which carries no
 * label in the generated listing.
 *
 * alias: 0x020A71E8 spells "gds_profile.c", the sixth original source file
 * name this project has recovered, attested by the `string` class off the
 * terminator of "musical_dist_save.c" at 0x020A71E6.  The constructor at
 * 0x0200D59C passes it to the debug allocator at 0x02030734 with line 0x50,
 * and the rest of the file is src/matched/unit_0200D6D0.c,
 * src/matched/unit_0200D6EC.c and src/matched/unit_0200D74C.c, with
 * GDS_PROFILE_Init the one function of it left out; see below.
 *
 * The record is 0x80 bytes, which is what the constructor allocates and
 * clears, and which src/matched/unit_0200D5D0.c fills field by field.
 *
 * The heap id is a full word cast to `u16` at the call, not a `u16`
 * parameter: this front end assumes an incoming `u16` parameter is already
 * zero extended and emits nothing, so the `lsls #0x10` / `lsrs #0x10` pair at
 * 0x0200D5A2 is a narrowing the source wrote.  The same reading applies to
 * the tag parameters of GDS_PROFILE_CreateNameStr and func_0200D774.
 *
 * GDS_PROFILE_Delete is the destructor and is eight bytes: a pool word and a `bx`,
 * with no argument set-up at all; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Left out of this range: GDS_PROFILE_Init, 256 bytes, which builds the whole
 * record.  Every concrete byte of it reproduces and it is capped at MATCH,
 * because 0x0200C164 is the target of exactly one branch in the image, its
 * own call at 0x0200D610, so the `label` class has no witness outside the
 * compared range and no cut helps.  The source is parked in
 * src/matched/unit_0200D5D0.c.
 */
struct GdsProfile_0200D59C *GDS_PROFILE_Create(u32 heap)
{
    struct GdsProfile_0200D59C *profile = func_02030734((u16)heap, sizeof(struct GdsProfile_0200D59C),
                                         0, func_0200D59C_File, 0x50);

    MI_CpuFill8(profile, 0, sizeof(struct GdsProfile_0200D59C));
    return profile;
}



void GDS_PROFILE_Delete(struct GdsProfile_0200D59C *profile)
{
    func_020307B0(profile);
}



/*
 * 0x0200D5D0..0x0200D6D0, 256 bytes, one function.
 *
 * The record builder of "gds_profile.c"; see src/matched/unit_0200D59C.c for
 * the file name and the record.
 *
 * What held it open, and what closed it: 0x0200C164 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200D610 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule, and `tu --suggest-split` could only answer by leaving this function
 * out.  0x0200C164 is part of src/matched/unit_0200C0E8.c, and that entry is
 * now evidence rather than a bare lookup: the `matched` class reads it as our
 * own byte-verified proof of what lives at that address, proved over a range
 * this file does not touch.  This header used to say a matched address is a
 * lookup and not evidence; the distinction it was missing is that an EXACT
 * entry is a comparison against the original bytes, not a name in a table.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200D5D0.c \
 *       --addr 0x0200D5D0 --thumb
 *
 * Three details are worth having.
 *
 *  - the three bitfield writes at +0x1B each cast the source value to `u8`
 *    before the assignment, which is the `lsls #0x18` / `lsrs #0x18` pair in
 *    front of each mask; without the cast the pair is gone.  The widths come
 *    off the second pair: `lsls #0x1A` / `lsrs #0x19` is bits 1..6, `ands #1`
 *    is bit 0 and `lsls #0x1F` / `lsrs #0x18` is bit 7.
 *  - the four out-parameters of func_0200C164 are declared in the order the
 *    call passes them, so the first lands at sp+0x14 and the last at sp+8;
 *    declared the other way round every offset is mirrored and nothing else
 *    moves.  See docs/idioms/local-declaration-order-is-stack-order.md.
 *  - the byte of owner information is read as `add r0, sp, #8` /
 *    `ldrb r0, [r0, #0x12]` rather than off the OSOwnerInfo frame slot,
 *    because `sp + 8` is already a common subexpression: it is the fifth
 *    argument func_0200C164 took a few instructions earlier.
 */
void GDS_PROFILE_Init(struct GdsProfile_0200D59C *profile, void *sys)
{
    struct OwnerInfo info;
    u32 playHours;
    u32 playMinutes;
    u32 cleared;
    u32 nationalDex;
    void *progress;
    void *saveData = GAME_DATA_GetSaveControl(sys);
    void *trainerRec = func_02012944(sys);
    void *recordEnv;
    s32 i;

    func_02009470(saveData);
    progress = GAME_DATA_GetMiscSave(sys);
    recordEnv = func_0200E6E8((u32)saveData);
    OS_GetOwnerInfo(&info);
    func_0200C164(progress, &playHours, &playMinutes, &cleared, &nationalDex);

    MI_CpuFill8(profile, 0, sizeof(struct GdsProfile_0200D59C));
    func_0201F41C(func_020084F4(trainerRec), (u16 *)profile, 8);
    profile->trainerId = func_02008530(trainerRec);
    profile->gender = func_02008550(trainerRec);
    profile->playHours = playHours;
    profile->play.playMinutes = (u8)playMinutes;
    profile->play.gameCleared = (u8)cleared;
    profile->play.hasNationalDex = (u8)nationalDex;
    profile->country = func_0200856C(trainerRec);
    profile->region = func_02008570(trainerRec);
    for (i = 0; i < 0x28; i++) {
        profile->record[i] = STRBUF_GetEosChar();
    }
    func_0200E6FC(recordEnv, 0, (struct RecordData *)profile->record);
    profile->birthMonth = info.birthMonth;
    profile->trainerSprite = func_02008554(trainerRec);
    profile->gameVersion = 0x15;
    profile->language = 2;
    profile->checksum = func_0203F1FC((const u8 *)profile, 0x7C);
}



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 28 bytes, 0x0200D6D0..0x0200D6EC, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "gds_profile.c"; see src/matched/unit_0200D59C.c for how the
 * name is attested and why the range in front of this one is cut here.
 *
 * A fifteen-byte copy into a freshly allocated block: the same
 * STRBUF_Create / STRBUF_SetStringN pair func_0200D774 uses for the 0x28-byte
 * record.  The size is materialised twice, once as the allocation size and
 * once as the copy length, because both are caller-saved argument registers.
 */
void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag)
{
    void *h = STRBUF_Create(0xF, (u16)tag);

    STRBUF_SetStringN(h, src, 0xF);
    return h;
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D73C
 *
 * 96 bytes, 0x0200D6EC..0x0200D74C, 5 functions, none of which carries a
 * label in the generated listing.
 *
 * Five validating getters on one record: a byte at +0x14, three bitfields
 * packed into the byte at +0x1B and a halfword at +0x1C.  Each one reads the
 * field and substitutes a safe value when it is out of range, and the shape
 * of the guard is what says how the source was written.
 *
 * func_0200D6EC and func_0200D72C both test the value against 0 and then
 * against 1 with two `beq` to the same address, which is one `if` with `&&`
 * and not two statements; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 * That the test survives at all in func_0200D72C is the interesting part: the
 * field there is one bit wide, so `v != 0 && v != 1` is provably false and
 * the compiler still emits both compares, which is the same reading as
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md.
 *
 * func_0200D73C clamps rather than zeroes, and the branch is `bls` over a
 * `movs r0, #1`, so its guard is `if (v > 1) v = 1;` and the fall-through arm
 * is the assignment.
 *
 * The bitfield widths are read off the shift pairs: `lsls #0x1F` / `lsrs
 * #0x1F` is bit 0, `lsls #0x18` / `lsrs #0x1F` is bit 7, and `lsls #0x19` /
 * `lsrs #0x1A` is the six bits between them, which is what func_0200D70C
 * passes as the second argument of func_02019D58.
 */
u32 func_0200D6EC(struct RecGet *p)
{
    u32 v = p->unk14;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}




u32 func_0200D6FC(struct RecGet *p)
{
    u32 v = p->unk1C;

    if (v >= 0x28B) {
        v = 0;
    }
    return v;
}




u32 func_0200D70C(struct RecGet *p)
{
    if (p->unk1C >= 0x28B) {
        return 0;
    }
    return func_02019D58(p->unk1C, p->b1);
}




u32 func_0200D72C(struct RecGet *p)
{
    u32 v = p->b7;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}




u32 func_0200D73C(struct RecGet *p)
{
    u32 v = p->b0;

    if (v > 1) {
        v = 1;
    }
    return v;
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D820, func_0200D82C
 *
 * 268 bytes, 0x0200D74C..0x0200D858, 6 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: the tail of "gds_profile.c"; the constructor at 0x0200D59C names
 * 0x020A71E8, see src/matched/unit_0200D59C.c.
 */
u32 func_0200D74C(struct GdsProfile_0200D6EC *p)
{
    return func_02025C1C(p->unk17, p->unk18, func_0200D82C(p));
}




u32 func_0200D760(struct GdsProfile_0200D6EC *p)
{
    return func_02025C30(p->unk17, p->unk18, func_0200D82C(p));
}




void *func_0200D774(struct GdsProfile_0200D6EC *p, struct GdsRecord *out, u32 tag)
{
    u32 a;
    u32 b;
    s32 n = 0;

    if (p->unk1E == 0) {
        out->unk00 = p->unk20.unk00;
        out->unk02 = p->unk20.unk02;
        out->unk04 = p->unk20.unk04;
        out->unk06 = p->unk20.unk06;
        if (out->unk00 >= 5) {
            n++;
            goto chk;
        }
        if (out->unk02 > 0x13) {
            n++;
            goto chk;
        }
        if ((out->unk04 != 0xFFFF && PMS_WORD_SplitWordId(out->unk04, &a, &b) == 0)
            || (out->unk06 != 0xFFFF
                && PMS_WORD_SplitWordId(out->unk06, &a, &b) == 0)) {
            n++;
        }
    chk:
        if (n > 0) {
            PMSI_PARAM_InitSentence(out, 4);
            out->unk02 = 0;
            out->unk04 = PMS_WORD_MakeWordId(0x95, 0x1D);
            out->unk06 = 0xFFFF;
        }
        return 0;
    } else {
        void *h = STRBUF_Create(0x28, (u16)tag);

        STRBUF_SetStringN(h, (const u16 *)&p->unk20, sizeof(p->unk20));
        return h;
    }
}




u32 func_0200D810(struct GdsProfile_0200D6EC *p)
{
    u32 v = p->unk15;

    if (v < 1 || v > 0xC) {
        v = 1;
    }
    return v;
}




u32 func_0200D820(struct GdsProfile_0200D6EC *p)
{
    u32 v = p->unk16;

    if (v > 0xF) {
        v = 0;
    }
    return v;
}




u32 func_0200D82C(struct GdsProfile_0200D6EC *p)
{
    u32 v = p->unk1A;

    switch (v) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
        return v;
    }
    return 2;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D884, func_0200D914, func_0200D9E8, func_0200DA14,
 *           func_0200DA28, func_0200DA54
 *
 * 524 bytes, 0x0200D858..0x0200DA64, 10 functions, eight of which carry no
 * label in the generated listing.
 *
 * A 0x3C-byte record reached almost entirely through one pair of dispatchers.
 * func_0200D858 returns 0x3C and func_0200D85C clears exactly that many bytes
 * as a bare tail call, which is the block-file opening this region keeps
 * producing.
 *
 * The first halfword is seven bitfields and the widths come off the shift
 * pairs rather than a guess: `lsls #0x1A` / `lsrs #0x1C` is bits 2..5,
 * `lsls #0x17` / `lsrs #0x1D` is bits 6..8, and the three single-bit fields
 * at 0, 9 and 10 are `lsls #k` / `lsrs #0x1F`.  The setter arm for each is the
 * mirror image, and the three masks that need a literal pool word
 * (0xFFFFFE3F, 0xFFFFFDFF, 0xFFFFFBFF) are exactly the complements of those
 * fields, which is the independent check.
 *
 * Both dispatchers carry twelve dense case labels from zero and both tables
 * are complete, so no arm is a gap; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The three
 * arms that move a block of bytes return 0 like the default does, and the
 * default is reached by the `bhi` in the preamble, so there is one `return 0`
 * after the switch and not a `default:` label.
 *
 * func_0200D868 truncates its value to `u16` before extracting the bit, which
 * a `u16` parameter does not produce: the parameter is wider and the source
 * casts at the use, the same shape as func_0200BBC8 in
 * src/matched/unit_0200BBC8.c.
 *
 * func_0200D9E8 adds three deltas into three counters, each guarded against
 * its own type's maximum, and each sum is computed once and reused by both
 * the compare and the store; the two halfword guards share one literal pool
 * word holding 0xFFFF.
 *
 * func_0200DA28 reads the counter at id 1 through the getter, increments it
 * in a stack byte and writes it back through the setter, reloading the byte
 * after storing it because its address escapes into the setter call.
 */
u32 func_0200D858(void)
{
    return sizeof(struct Blk3C);
}





void func_0200D85C(struct Blk3C *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk3C));
}




void func_0200D868(struct Blk3C *p, u32 v)
{
    p->f1 = (u16)v;
}




u32 func_0200D87C(struct Blk3C *p)
{
    return p->f1;
}




u32 func_0200D884(struct Blk3C *p, u32 id, void *out)
{
    switch (id) {
    case 0:
        return p->f2;
    case 1:
        return p->unk02;
    case 2:
        return p->unk03;
    case 3:
        return p->unk04;
    case 4:
        return p->unk06;
    case 5:
        MI_CpuCopy8(p->unk08, out, sizeof(p->unk08));
        return 0;
    case 6:
        MI_CpuCopy8(p->unk28, out, sizeof(p->unk28));
        return 0;
    case 7:
        return p->f0;
    case 8:
        MI_CpuCopy8(p->unk0C, out, sizeof(p->unk0C));
        return 0;
    case 9:
        return p->f6;
    case 10:
        return p->f9;
    case 11:
        return p->f10;
    }
    return 0;
}




void func_0200D914(struct Blk3C *p, u32 id, const void *src)
{
    switch (id) {
    case 0:
        p->f2 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 1:
        p->unk02 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 2:
        p->unk03 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 3:
        p->unk04 = *(const u16 *)src;
        break;
    case 4:
        p->unk06 = *(const u16 *)src;
        break;
    case 5:
        MI_CpuCopy8(src, p->unk08, sizeof(p->unk08));
        break;
    case 6:
        MI_CpuCopy8(src, p->unk28, sizeof(p->unk28));
        break;
    case 7:
        p->f0 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 8:
        MI_CpuCopy8(src, p->unk0C, sizeof(p->unk0C));
        break;
    case 9:
        p->f6 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 10:
        p->f9 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 11:
        p->f10 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    }
}




void func_0200D9E8(struct Blk3C *p, s32 a, s32 b, s32 c)
{
    if (p->unk03 + a < 255) {
        p->unk03 = p->unk03 + a;
    }
    if (p->unk04 + b < 0xFFFF) {
        p->unk04 = p->unk04 + b;
    }
    if (p->unk06 + c < 0xFFFF) {
        p->unk06 = p->unk06 + c;
    }
}




void func_0200DA14(struct Blk3C *p)
{
    u8 v = 0;

    func_0200D914(p, 1, &v);
}




void func_0200DA28(struct Blk3C *p)
{
    u8 v = func_0200D884(p, 1, 0);

    if (v < 255) {
        v++;
    }
    func_0200D914(p, 1, &v);
}




u16 func_0200DA54(struct Blk3C *p)
{
    return func_0200D884(p, 1, 0);
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200DABC, func_0200DAC0, func_0200DAC4, func_0200DAD8,
 *           func_0200DAEC, func_0200DB08, func_0200DB1C, func_0200DB30,
 *           func_0200DB44, func_0200DB60, func_0200DB80, func_0200DBA0,
 *           func_0200DBF0, func_0200DBFC, func_0200DC08, func_0200DC0C,
 *           func_0200DC50, func_0200DC74, func_0200DC94, func_0200DCF8,
 *           func_0200DCFC
 *
 * 684 bytes, 0x0200DA64..0x0200DD10, 25 functions, eighteen of which carry no
 * label in the generated listing.
 *
 * A 0x1AC-byte save record of counters: one clamped total at +0x00, a streak
 * byte at +0x02, a level byte at +0x03 that the constructor seeds with 1, a
 * word of eleven flag bits at +0x04, three nine-entry `u16` arrays at +0x08,
 * +0x1A and +0x2C, a derived score at +0x3E, and two 0xB4-byte blobs at +0x44
 * and +0xF8.  The size getter and the constructor's `MI_CpuFill8(p, 0, 0x1AC)`
 * agree with 0xF8 + 0xB4, which is what pins the last field's length.
 *
 * Five things here are worth naming.
 *
 *  - func_0200DAC0 is `bx lr` and nothing else, and it is a function, not
 *    padding: eight of the accessors `bl` it with the index in r0 and use
 *    the result.  It is `u32 f(u32 i) { return i; }`, an id-to-slot mapping
 *    that was never filled in, and the calls to it are what make the three
 *    arrays indexed rather than direct.
 *  - func_0200DBA0 takes a **signed** index, which the `blt` on the range
 *    check says and the `blo` inside the shift loop does not contradict: the
 *    loop counter is unsigned, so the comparison against it is unsigned too.
 *    Its switch bodies are emitted in the order 2, 1, 0, which is the order
 *    the source wrote them in; written 0, 1, 2 the case-2 body stops being
 *    the fall-through and the function grows a branch.
 *  - the mask is cleared with `~(u32)0 ^ mask`, not `~mask`: the original
 *    materialises the all-ones word with `movs r1, #0; mvns r1, r1` and then
 *    `eors`, which is two instructions where `mvns r1, r4` would have been
 *    one.
 *  - func_0200DC0C's two arms both end in a call to func_0200DBA0 followed
 *    by a store to +0x02, and the compiler cross-jumps them into one copy
 *    that each arm sets up its arguments for and branches to.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - in func_0200DC94 the two products are each truncated to `u16` and their
 *    sum is not.  Holding the sum in a `u16` adds a `lsls`/`lsrs` pair the
 *    original does not have, which is the whole of the difference between
 *    that function and EXACT.
 */
u32 func_0200DA64(void)
{
    return sizeof(struct Blk1AC);
}





void func_0200DA6C(struct Blk1AC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk1AC));
    p->unk03 = 1;
}




void func_0200DA80(struct Blk1AC *p, s32 v)
{
    s32 n = p->unk00 + v;

    if (n > 9999) {
        p->unk00 = 9999;
    } else {
        p->unk00 = n;
    }
}




void func_0200DA98(struct Blk1AC *p, u16 v)
{
    s16 n = (s16)p->unk00 - (s16)v;

    if (n >= 0) {
        p->unk00 = p->unk00 - v;
    } else {
        p->unk00 = 0;
    }
}




u16 func_0200DABC(struct Blk1AC *p)
{
    return p->unk00;
}




u32 func_0200DAC0(u32 i)
{
    return i;
}




u16 func_0200DAC4(struct Blk1AC *p, u32 i)
{
    return p->unk08[func_0200DAC0(i)];
}




u16 func_0200DAD8(struct Blk1AC *p, u32 i)
{
    return p->unk1A[func_0200DAC0(i)];
}




void func_0200DAEC(struct Blk1AC *p, u32 i, u16 v)
{
    u32 k = func_0200DAC0(i);

    if (p->unk1A[k] < v) {
        p->unk1A[k] = v;
    }
}




void func_0200DB08(struct Blk1AC *p, u32 i, u16 v)
{
    p->unk08[func_0200DAC0(i)] = v;
}




void func_0200DB1C(struct Blk1AC *p, u32 i)
{
    p->unk2C[func_0200DAC0(i)] = 0;
}




void func_0200DB30(struct Blk1AC *p, u32 i)
{
    p->unk2C[func_0200DAC0(i)] = 1;
}




u32 func_0200DB44(struct Blk1AC *p, u32 i)
{
    if (p->unk2C[func_0200DAC0(i)] != 0) {
        return 1;
    }
    return 0;
}




void func_0200DB60(struct Blk1AC *p, u32 i)
{
    u32 k = func_0200DAC0(i);

    if (p->unk2C[k] < 0xFFFE) {
        p->unk2C[k] = p->unk2C[k] + 1;
    }
}




u16 func_0200DB80(struct Blk1AC *p, u32 i)
{
    u16 n = p->unk2C[func_0200DAC0(i)] - 1;

    if ((s16)n < 0) {
        n = 0;
    }
    return n;
}




u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op)
{
    u32 j;
    u32 mask = 1;

    if (i >= 11) {
        return 0;
    }
    for (j = 0; j < i; j++) {
        mask <<= 1;
    }
    switch (op) {
    case 2:
        p->unk04 &= ~(u32)0 ^ mask;
        break;
    case 1:
        p->unk04 |= mask;
        break;
    case 0:
        return (p->unk04 >> i) & 1;
    }
    return 0;
}




void func_0200DBF0(struct Blk1AC *p)
{
    if (p->unk03 < 10) {
        p->unk03 = p->unk03 + 1;
    }
}




void func_0200DBFC(struct Blk1AC *p)
{
    if (p->unk03 > 1) {
        p->unk03 = p->unk03 - 1;
    }
}




u8 func_0200DC08(struct Blk1AC *p)
{
    return p->unk03;
}




u8 func_0200DC0C(struct Blk1AC *p, u32 kind)
{
    switch (kind) {
    case 2:
        func_0200DBA0(p, 0, 2);
        p->unk02 = 0;
        break;
    case 3:
        if (func_0200DBA0(p, 0, 0)) {
            if (p->unk02 < 0xFF) {
                p->unk02 = p->unk02 + 1;
            }
        } else {
            func_0200DBA0(p, 0, 1);
            p->unk02 = 1;
        }
        break;
    }
    return p->unk02;
}




void func_0200DC50(struct Blk1AC *p, u32 which, const void *src)
{
    if (which == 0) {
        MI_CpuCopy8(src, p->unkF8, sizeof(p->unkF8));
    } else {
        MI_CpuCopy8(src, p->unk44, sizeof(p->unk44));
    }
}




void func_0200DC74(struct Blk1AC *p, u32 which, void *dest)
{
    if (which == 0) {
        MI_CpuCopy8(p->unkF8, dest, sizeof(p->unkF8));
    } else {
        MI_CpuCopy8(p->unk44, dest, sizeof(p->unk44));
    }
}




void func_0200DC94(struct Blk1AC *p, const struct Src *q)
{
    u16 a;
    u16 c;
    u16 d;
    s32 t;

    a = (q->unk02 - 1) * 1000;
    t = (u16)(q->unk04 * 10) + (u16)(q->unk03 * 20);
    if (t > 950) {
        c = 0;
    } else {
        c = 950 - t;
    }
    if (q->unk06 > 970) {
        d = 0;
    } else {
        d = (1000 - q->unk06) / 30;
    }
    p->unk3E = a + c + d;
}




u16 func_0200DCF8(struct Blk1AC *p)
{
    return p->unk3E;
}




u8 func_0200DCFC(struct Blk1AC *p)
{
    return p->unk3E / 1000;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 24 bytes, 0x0200DD10..0x0200DD28, the size getter and the constructor of
 * the save block this file belongs to: 0xB90 bytes, of which the first four
 * are a packed stamp and the next 250 are a bitmap of 2000 bits.  Neither
 * function carries a label in the generated listing.
 *
 * Near miss, and the reason this unit stops at 0x0200DD28: func_0200DD28,
 * 104 bytes, which sets one bit of that bitmap and then packs four bytes
 * into the stamp word.  It is
 *
 *     void func_0200DD28(struct BlkB90 *p, u32 a, u32 b,
 *                        const struct Stamp *q)
 *     {
 *         u16 idx;
 *         u8 sh;
 *
 *         if (b == 0 || b > 200 || a == 0 || a > 10) {
 *             return;
 *         }
 *         idx = (a - 1) * 200 + (b - 1);
 *         sh = idx % 8;
 *         p->unk04[(u8)(idx / 8)] |= (u8)(1 << sh);
 *         p->unk00 = (q->unk00 << 24) | ((q->unk04 << 24) >> 8)
 *                  | ((q->unk08 << 24) >> 16) | q->unk0C;
 *     }
 *
 * and that reproduces the size to the byte and every instruction, in the
 * same order bar one, with a different register assignment throughout.  The
 * original keeps the block pointer in r0 and moves the stamp pointer out of
 * r3 into r4, saving three registers; this source moves both, saves four,
 * and schedules the `lsls #0x15` that forms the byte index twenty-two bytes
 * early, which is the one live value that costs it r7.  Sixteen spellings
 * were tried: the modulo and the division as `%`/`/` and as shifts, the
 * byte index as a `u8` cast, an `& 0xFF` and a named `u8` local, the bit as
 * a named local and at the use, the guard positive and negative, the two
 * statements in both orders, the stamp as a struct pointer and as a `u32 *`,
 * and `const` on either pointer.  Every one of them produces the same 104
 * bytes with the same allocation, so the shift-amount truncation and the
 * cast at the use (docs/idioms, sub_0200A6BC) are already right and what is
 * left is not reachable from the source shape.  Forty bytes differ and every
 * one of them is a register number.
 */
u32 func_0200DD10(void)
{
    return sizeof(struct BlkB90);
}




void func_0200DD18(struct BlkB90 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct BlkB90));
}



/*
 * 100 bytes (0x0200DD28..0x0200DD8C). Sets one bit of the 2000-bit bitmap of
 * the 0xB90 save block (unit_0200DD10.c) and packs four bytes into its stamp.
 * The u8 mask initialised to 1 at the top gives the early `movs r3,#1`.
 */
void func_0200DD28(u8 *p, u8 a, u8 b, u32 *q) {
    u8 mask = 1;
    u16 idx;
    if (b == 0 || b > 200 || a == 0 || a > 10) {
        return;
    }
    idx = (b - 1) + (a - 1) * 200;
    mask <<= (u8)(idx % 8);
    (p + 4)[(u8)(idx / 8)] |= mask;
    *(u32 *)p = (q[0] << 24) | ((q[1] << 24) >> 8) | ((q[2] << 24) >> 16) | q[3];
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 208 bytes, 0x0200DD8C..0x0200DE5C.  This file is the merge the wave 4A
 * report asked for: func_0200DD8C and func_0200DDA8 are each called from
 * exactly one instruction in the image, both inside func_0200DDD0, so as
 * separate files the caller could never attest them.  In one unit both
 * call sites are local and the whole range is EXACT.  See the header of
 * src/matched/unit_0200DD10.c for why the range starts at 0x0200DD8C.
 *
 * func_0200DD8C clears the 250-byte bitmap and then the four-byte stamp, in
 * that order and as two separate calls: the second one's size is four, not
 * the 254 a single call would have used, so the two fields are cleared
 * independently even though they are adjacent.
 *
 * func_0200DDA8 compares the first three words of two stamps and answers
 * whether the first is greater, with an early return per word rather than a
 * combined expression.  The fourth word is not compared, which is what makes
 * the stamp's last field a tag rather than part of the ordering.
 *
 * func_0200DDD0 is the query half of the 0xB90-byte block: it answers
 * whether the (a, b) pair has already been recorded and whether the stamp it
 * is asked about is newer than the stored one.  Four things pin the source:
 *  - the result local is initialised to 1 before the guard, and the bit
 *    mask is built off the register holding that 1 (see
 *    docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 *  - the guard is one ||, not two statements (see
 *    docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md);
 *  - the stamp is unpacked into a local struct Stamp a byte at a time, big
 *    endian, stores in source order;
 *  - idx % 8 is the signed-modulo shift sequence with the shift amount
 *    truncated to u8 before the shift and the mask cast to u8 at the use
 *    (the sub_0200A6BC shape), and the byte index is (u8)(idx / 8).
 */
void func_0200DD8C(struct BlkB90 *p)
{
    MI_CpuFill8(p->unk04, 0, sizeof(p->unk04));
    MI_CpuFill8(p, 0, sizeof(p->unk00));
}



u32 func_0200DDA8(const struct Stamp *a, const struct Stamp *b)
{
    if (a->unk00 > b->unk00) {
        return 1;
    }
    if (a->unk04 > b->unk04) {
        return 1;
    }
    if (a->unk08 > b->unk08) {
        return 1;
    }
    return 0;
}



int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q)
{
    struct Stamp s;
    u16 idx;
    u8  sh;
    u32 r = 1;

    if (b > 200 || a > 10) {
        return 0;
    }
    s.unk00 = (u8)(p->unk00 >> 24);
    s.unk04 = (u8)(p->unk00 >> 16);
    s.unk08 = (u8)(p->unk00 >> 8);
    s.unk0C = (u8)p->unk00;
    if (func_0200DDA8(q, &s) != 0) {
        func_0200DD8C(p);
        return 0;
    }
    idx = (a - 1) * 200 + (b - 1);
    sh = idx % 8;
    if (!(p->unk04[(u8)(idx / 8)] & (u8)(1 << sh))) {
        r = 0;
    }
    return r;
}
