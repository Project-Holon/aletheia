/*
 * function: MISC_SAVEDATA_SnapshotParty
 * address:  0x0200EA3C
 * packet:   pkt_0200EA3C
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   STRBUF_Delete  0x02045808  arm
 *
 * Snapshot of a party into a 0x16c-byte ring record (MISC_SAVEDATA_AppendPartyRecord's slot):
 * zero the six 0x3c-byte entries, then for every non-egg member (field 0x4c
 * of POKE_TOOL_GetPartyValue is 0) store species (5), level (0x9e), the 6/2-bit pair
 * 0x6f/0x6e, fields 0 and 7, fields 0x36..0x39, and the nickname (0x73, 11
 * u16) and OT name (0x8d, 8 u16) through an 11-char string buffer, or the
 * terminator from STRBUF_GetEosChar in both name slots when the buffer could not
 * be allocated.  The date record (first three words) goes to +0x168.
 * The layout of struct Entry is the one MISC_SAVEDATA_ExportRecord (EXACT*) reads back.
 *
 * Levers: the loop counter i is initialised AFTER the memset and before
 * n (both zeroes are then scheduled across the call with i first, which is
 * what puts i at sp+0x14 and n at sp+0x10); the species store goes through
 * rec->e[n] and every later field through the named entry pointer.
 *
 * EXACT* only because the 402 compiled bytes stop two short of the listing
 * extent at a "movs r0, r0" alignment filler; no byte differs.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Entry {
    u16 species;
    u8  level;
    u8  f03a : 6;
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u16 name[11];
    u16 ot[8];
    u16 f32[4];
};

struct Rec {
    struct Entry e[6];
    u16 year;
    u8  month;
    u8  day;
};

struct Date {
    u32 year;
    u32 month;
    u32 day;
};

struct Sav;
struct U16Vec;
extern u32 POKEPARTY_GetCount(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void  MI_CpuFill8(void *dst, u8 v, u32 size);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32   POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 buf);
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
extern u16   STRBUF_GetEosChar(void);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void STRBUF_Delete(struct U16Vec *vec);

void MISC_SAVEDATA_SnapshotParty(struct Rec *rec, void *party, struct Date *date, u32 heap)
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
            struct Entry *e = &rec->e[n];
            rec->e[n].species = POKE_TOOL_GetPartyValue(mon, 5, 0);
            e->level = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
            e->f03a = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
            e->f03b = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
            e->f04 = POKE_TOOL_GetPartyValue(mon, 0, 0);
            e->f08 = POKE_TOOL_GetPartyValue(mon, 7, 0);
            e->f32[0] = POKE_TOOL_GetPartyValue(mon, 0x36, 0);
            e->f32[1] = POKE_TOOL_GetPartyValue(mon, 0x37, 0);
            e->f32[2] = POKE_TOOL_GetPartyValue(mon, 0x38, 0);
            e->f32[3] = POKE_TOOL_GetPartyValue(mon, 0x39, 0);
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
