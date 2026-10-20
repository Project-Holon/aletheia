/*
 * file:     dendou_savedata.c
 * unit:     yes
 * function: DENDOU_SAVEDATA_GetSize, DENDOU_SAVEDATA_GetRecordSize, DENDOU_SAVEDATA_Clear, DENDOU_SAVEDATA_InitRecord, DENDOU_SAVEDATA_SetRecord, DENDOU_SAVEDATA_AppendRecord, DENDOU_SAVEDATA_GetMemberCount, DENDOU_SAVEDATA_ExportMember, DENDOU_SAVEDATA_GetRecordDate, DENDOU_SAVEDATA_GetRecordCount, DENDOU_SAVEDATA_GetHallNumber, DENDOU_SAVEDATA_GetRingMemberCount, DENDOU_SAVEDATA_ExportRingMember, DENDOU_SAVEDATA_GetRingRecordDate
 * address:  0x0200EA0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata_2.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   DENDOU_SAVEDATA_GetMemberCount   0x0200EC14  thumb
 */
#include "../types.h"

struct PartyRingSave;

struct DendouRec;

struct Sav;

struct U16Vec;

struct DendouRec;

struct Date;

struct Strbuf;

struct DendouEntry;

struct RecordTarget;

struct RecordDate;

/* One 0x3c-byte party member snapshot of struct DendouRec. */
struct DendouEntry {
    u16 species;
    u8  level;
    u8  form : 6;
    u8  gender : 2;
    u32 pid;
    u32 experience;
    u16 name[11];
    u16 ot[8];
    u16 traits[4];
};

struct DendouRec {
    struct DendouEntry e[6];
    u16 year;
    u8  month;
    u8  day;
};

struct Date {
    u32 year;
    u32 month;
    u32 day;
};

/* Save block with a ring of 15 dated party snapshots (0x155C bytes). */
struct PartyRingSave {
    struct DendouRec entries[15];   /* +0x000 */
    u32 writeIndex;           /* +0x1554 slot the next snapshot goes to */
    u32 recordCount;          /* +0x1558 saturating total, stops at 9999 */
};

/* An exported party record: two string buffers and the copied fields. */
struct RecordTarget {
    void *nicknameStr;  /* +0x00 */
    void *otNameStr;    /* +0x04 */
    u32   pid;          /* +0x08 */
    u32   experience;   /* +0x0c */
    u16   species;      /* +0x10 */
    u8    level;        /* +0x12 */
    u8    form : 6;     /* +0x13 */
    u8    gender : 2;
    u16   traits[4];    /* +0x14 */
};

/* The date unpacked from a struct DendouRec at +0x168. */
struct RecordDate {
    u32 year;
    u32 month;
    u32 day;
    u32 reserved;
};

#include "mi_memory.h"
struct PokemonParam;

#include "poke_tool.h"
struct Party;

#include "pokeparty.h"

#include "strbuf.h"








u32 DENDOU_SAVEDATA_GetSize(void);

u32 DENDOU_SAVEDATA_GetRecordSize(void);

void DENDOU_SAVEDATA_Clear(void *p);

void DENDOU_SAVEDATA_InitRecord(void *block);

void DENDOU_SAVEDATA_SetRecord(struct DendouRec *rec, void *party, struct Date *date, u32 heap);

void DENDOU_SAVEDATA_AppendRecord(struct PartyRingSave *obj, void *party, void *date, u32 heap);

int DENDOU_SAVEDATA_GetMemberCount(char *p);

void DENDOU_SAVEDATA_ExportMember(const struct DendouEntry *base, int idx, struct RecordTarget *dst);

void DENDOU_SAVEDATA_GetRecordDate(const u8 *o, struct RecordDate *out);

u32 DENDOU_SAVEDATA_GetRecordCount(char *o);

u32 DENDOU_SAVEDATA_GetHallNumber(char *o, u32 n);

int DENDOU_SAVEDATA_GetRingMemberCount(char *o, int idx);

void DENDOU_SAVEDATA_ExportRingMember(void *ring, u32 index, void *recordIndex, void *target);

void DENDOU_SAVEDATA_GetRingRecordDate(u8 *o, int idx, void *out);

u32 DENDOU_SAVEDATA_GetSize(void)
{
    return 0x155C;
}

/*
 * Save-table size callback: returns 0x16C, the size of the block that
 * DENDOU_SAVEDATA_InitRecord clears.  Pointer word 0x0200EA15 at 0x0209DD44.
 */
u32 DENDOU_SAVEDATA_GetRecordSize(void)
{
    return 0x16C;
}

void DENDOU_SAVEDATA_Clear(void *block)
{
    MI_CpuFill8(block, 0, 0x155C);
}

/*
 * Save-table init callback: clears the 0x16C-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200EA38).  Pointer word
 * 0x0200EA2D at 0x0209DD48.
 */
void DENDOU_SAVEDATA_InitRecord(void *block)
{
    MI_CpuFill8(block, 0, 0x16C);
}

/*
 * Snapshot of a party into a 0x16c-byte ring record (DENDOU_SAVEDATA_AppendRecord's slot):
 * zero the six 0x3c-byte entries, then for every non-egg member (field 0x4c
 * of POKE_TOOL_GetPartyValue is 0) store species (5), level (0x9e), the 6/2-bit pair
 * 0x6f/0x6e, fields 0 and 7, fields 0x36..0x39, and the nickname (0x73, 11
 * u16) and OT name (0x8d, 8 u16) through an 11-char string buffer, or the
 * terminator from STRBUF_GetEosChar in both name slots when the buffer could not
 * be allocated.  The date record (first three words) goes to +0x168.
 * The layout of struct DendouEntry is the one DENDOU_SAVEDATA_ExportMember (EXACT*) reads back.
 *
 * Levers: the loop counter i is initialised AFTER the memset and before
 * n (both zeroes are then scheduled across the call with i first, which is
 * what puts i at sp+0x14 and n at sp+0x10); the species store goes through
 * rec->e[n] and every later field through the named entry pointer.
 *
 * EXACT* only because the 402 compiled bytes stop two short of the listing
 * extent at a "movs r0, r0" alignment filler; no byte differs.
 */
void DENDOU_SAVEDATA_SetRecord(struct DendouRec *rec, void *party, struct Date *date, u32 heap)
{
    int count = POKEPARTY_GetCount(party);
    void *buf = STRBUF_Create(11, heap);
    int i;
    int n;

    MI_CpuFill8(rec, 0, 0x168);
    i = 0;
    n = 0;
    for (; i < count; i++) {
        void *mon = POKEPARTY_GetMember(party, i);
        u32 saved = POKE_TOOL_DecodePartyParam(mon);
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0) {
            struct DendouEntry *e = &rec->e[n];
            rec->e[n].species = POKE_TOOL_GetPartyValue(mon, 5, 0);
            e->level = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
            e->form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
            e->gender = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
            e->pid = POKE_TOOL_GetPartyValue(mon, 0, 0);
            e->experience = POKE_TOOL_GetPartyValue(mon, 7, 0);
            e->traits[0] = POKE_TOOL_GetPartyValue(mon, 0x36, 0);
            e->traits[1] = POKE_TOOL_GetPartyValue(mon, 0x37, 0);
            e->traits[2] = POKE_TOOL_GetPartyValue(mon, 0x38, 0);
            e->traits[3] = POKE_TOOL_GetPartyValue(mon, 0x39, 0);
            if (buf != 0) {
                POKE_TOOL_GetPartyValue(mon, 0x73, (u32)buf);
                STRBUF_ToChars(buf, e->name, 11);
                POKE_TOOL_GetPartyValue(mon, 0x8d, (u32)buf);
                STRBUF_ToChars(buf, e->ot, 8);
            } else {
                e->name[0] = STRBUF_GetEosChar();
                e->ot[0] = STRBUF_GetEosChar();
            }
            n++;
        }
        POKE_TOOL_EncodePartyParam(mon, saved);
    }
    rec->year = date->year;
    rec->month = date->month;
    rec->day = date->day;
    if (buf != 0) {
        STRBUF_Delete(buf);
    }
}

/*
 * Ring-buffer record dispatcher: while the saturating counter at +0x1558 is
 * below 9999, hand the 0x16c-byte record at slot +0x1554 to DENDOU_SAVEDATA_SetRecord,
 * then advance the slot (wrapping at 15) and the counter.
 *
 * The residue that stood for four passes (r6 vs r1, push one register
 * narrower) was the parameter list: DENDOU_SAVEDATA_SetRecord takes FOUR arguments
 * (its prologue homes r0..r3), and this function forwards its own r1..r3 to
 * it untouched.  With a1..a3 live in r1..r3 across the prologue the index
 * temporary cannot take r1 and lands in r6.  The only caller
 * (ov205 0x021B9B62) passes (obj, GAME_DATA_GetMyParty result, &stack date record
 * from RTC_GetDate, 4).  The slot index is read inline in the call's
 * argument, not through a named local.
 *
 * Current listing extent is 68 bytes; compiled bytes match exactly.
 */
void DENDOU_SAVEDATA_AppendRecord(struct PartyRingSave *obj, void *party, void *date, u32 heap)
{
    if (obj->recordCount < 9999) {
        u32 slot;
        DENDOU_SAVEDATA_SetRecord((struct DendouRec *)((u8 *)obj + obj->writeIndex * 0x16c), party, date, heap);
        slot = obj->writeIndex + 1;
        obj->writeIndex = slot;
        if (slot >= 15) {
            obj->writeIndex = 0;
        }
        obj->recordCount += 1;
    }
}

/*
 * An unlabelled leaf: it saves nothing, so disasm.py's lr-saving prologue
 * sweep never fired and the bytes print as a run of `.word` in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing in
 * the image branches to it either, so no `function_starts.txt` seed exists.
 * First zero halfword of six 0x3c-byte records.
 *
 * It is not an anonymous hole, though: DENDOU_SAVEDATA_GetRingMemberCount (src/matched/
 * unit_0200EC98.c) tail-calls it through a pool word, which is why that file
 * could not resolve its one relocation until this entry existed -- the
 * `matched` class is the only witness 0x0200EC14 can ever have, since no
 * branch anywhere in the image names it and its address appears in exactly
 * one pool.
 */
int DENDOU_SAVEDATA_GetMemberCount(char *records)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(u16 *)(records + i * 0x3c) == 0)
            break;
    }
    return i;
}

/*
 * One record of a 0x3c-byte table copied into a destination object.
 *
 * This closes the 76-byte residue that docs/notes/pkt_0200EA3C.c.txt
 * section 2 recorded.  Three spellings had to hold at once:
 *
 *  1. the byte at source +3 is a `u8 :6 / u8 :2` bitfield PAIR, not a plain
 *     u8.  The source side is what produces the `lsls #26 / lsrs #26` pair
 *     the note could not reach; reading it as a plain u8 and shifting gives
 *     `ands` instead and compiles 104 bytes.
 *  2. the destination byte at +0x13 is the same bitfield pair.  That is what
 *     turns the insert into `movs r1, #0x3f; ands r1, r3` rather than a
 *     single immediate mask.  Both sides are needed: either one alone is
 *     still wrong.
 *  3. the source pointer must be `const`.  Without it, the store to
 *     dst->f13a may alias s->f03a, so mwcc reloads `ldrb [r4, #3]` a second
 *     time for the `:2` field, two bytes over at 110.  The original loads it
 *     once into r2 and keeps it live across the first insert.  See
 *     docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *
 * EXACT* : the inferred extent ran to 0x0200ECF0 because the accessor at
 * 0x0200EC98 saves no lr and so carries no label.  0x0200EC98 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DENDOU_SAVEDATA_ExportMember.c \
 *       --func DENDOU_SAVEDATA_ExportMember --addr 0x0200EC2C --cc 1.1p1 --thumb
 */
void DENDOU_SAVEDATA_ExportMember(const struct DendouEntry *records, int index, struct RecordTarget *dst)
{
    const struct DendouEntry *s = records + index;
    int i;

    dst->species = s->species;
    dst->level = s->level;
    dst->pid = s->pid;
    dst->experience = s->experience;
    dst->form = s->form;
    dst->gender = s->gender;

    STRBUF_SetStringN(dst->nicknameStr, (const u16 *)s->name, 0xb);
    STRBUF_SetStringN(dst->otNameStr, (const u16 *)s->ot, 8);

    for (i = 0; i < 4; i++)
        dst->traits[i] = s->traits[i];
}

/*
 * An unlabelled leaf accessor (it saves no lr, so disasm.py gives it no
 * label, see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It unpacks the three fields at +0x168..+0x16b of the object into a
 * four-word output record and zeroes the fourth word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DENDOU_SAVEDATA_GetRecordDate.c \
 *       --func DENDOU_SAVEDATA_GetRecordDate --addr 0x0200EC98 --cc 1.1p1 --thumb
 */
void DENDOU_SAVEDATA_GetRecordDate(const u8 *record, struct RecordDate *out)
{
    out->year = ((const struct DendouRec *)record)->year;
    out->month = ((const struct DendouRec *)record)->month;
    out->day = ((const struct DendouRec *)record)->day;
    out->reserved = 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The tail of this packet: three unlabelled accessors of the object
 * DENDOU_SAVEDATA_AppendRecord and DENDOU_SAVEDATA_ExportMember work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * DENDOU_SAVEDATA_GetRecordDate (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * DENDOU_SAVEDATA_GetRingMemberCount is a tail call through a pool word to
 * src/matched/DENDOU_SAVEDATA_GetMemberCount.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */
u32 DENDOU_SAVEDATA_GetRecordCount(char *ring)
{
    u32 count = ((struct PartyRingSave *)ring)->recordCount;

    if (count >= 0xf)
        count = 0xf;
    return count;
}

u32 DENDOU_SAVEDATA_GetHallNumber(char *ring, u32 count)
{
    return ((struct PartyRingSave *)ring)->recordCount - count;
}

int DENDOU_SAVEDATA_GetRingMemberCount(char *o, int idx)
{
    int n = ((struct PartyRingSave *)o)->writeIndex - 1 - idx;

    if (n < 0)
        n += 0xf;
    return DENDOU_SAVEDATA_GetMemberCount(o + n * 0x16c);
}

void DENDOU_SAVEDATA_ExportRingMember(void *ring, u32 index, void *recordIndex, void *target)
{
    int slot = ((struct PartyRingSave *)ring)->writeIndex - 1 - (int)index;

    if (slot < 0)
        slot += 0xf;
    DENDOU_SAVEDATA_ExportMember((const struct DendouEntry *)((u8 *)ring + slot * 0x16c), (int)recordIndex, target);
}

/*
 * An unlabelled accessor (its bytes print as a `.word` run after the pool
 * of DENDOU_SAVEDATA_ExportRingMember): the header of ring entry `count - 1 - idx`, a tail call
 * to DENDOU_SAVEDATA_GetRecordDate through a pool word. Same shape as DENDOU_SAVEDATA_GetRingMemberCount in
 * unit_0200ECB4.c. Its only caller is ov171 DENDOU_VIEW_LoadHallOfFame.
 */
void DENDOU_SAVEDATA_GetRingRecordDate(u8 *ring, int index, void *out)
{
    int slot = *(int *)(ring + 0x1554) - 1 - index;

    if (slot < 0)
        slot += 0xf;
    DENDOU_SAVEDATA_GetRecordDate(ring + slot * 0x16c, out);
}
