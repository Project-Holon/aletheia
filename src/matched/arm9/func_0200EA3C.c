/*
 * function: func_0200EA3C
 * address:  0x0200EA3C
 * packet:   pkt_0200EA3C
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020457B0  0x020457B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045A38  0x02045A38  arm
 *   func_02045A98  0x02045A98  arm
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   func_02045808  0x02045808  arm
 *
 * Snapshot of a party into a 0x16c-byte ring record (func_0200EBD0's slot):
 * zero the six 0x3c-byte entries, then for every non-egg member (field 0x4c
 * of func_02017E1C is 0) store species (5), level (0x9e), the 6/2-bit pair
 * 0x6f/0x6e, fields 0 and 7, fields 0x36..0x39, and the nickname (0x73, 11
 * u16) and OT name (0x8d, 8 u16) through an 11-char string buffer, or the
 * terminator from func_02045A98 in both name slots when the buffer could not
 * be allocated.  The date record (first three words) goes to +0x168.
 * The layout of struct Entry is the one func_0200EC2C (EXACT*) reads back.
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
extern u32 func_0201AA18(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void  MI_CpuFill8(void *dst, u8 v, u32 size);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32   func_02017E1C(void *mon, u32 id, u32 buf);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern u16   func_02045A98(void);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void func_02045808(struct U16Vec *vec);

void func_0200EA3C(struct Rec *rec, void *party, struct Date *date, u32 heap)
{
    int count = func_0201AA18(party);
    void *buf = func_020457B0(11, heap);
    int i;
    int n;

    MI_CpuFill8(rec, 0, 0x168);
    i = 0;
    n = 0;
    for (; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 saved = POKE_TOOL_DecodePartyParam(mon);
        if (func_02017E1C(mon, 0x4c, 0) == 0) {
            struct Entry *e = &rec->e[n];
            rec->e[n].species = func_02017E1C(mon, 5, 0);
            e->level = func_02017E1C(mon, 0x9e, 0);
            e->f03a = func_02017E1C(mon, 0x6f, 0);
            e->f03b = func_02017E1C(mon, 0x6e, 0);
            e->f04 = func_02017E1C(mon, 0, 0);
            e->f08 = func_02017E1C(mon, 7, 0);
            e->f32[0] = func_02017E1C(mon, 0x36, 0);
            e->f32[1] = func_02017E1C(mon, 0x37, 0);
            e->f32[2] = func_02017E1C(mon, 0x38, 0);
            e->f32[3] = func_02017E1C(mon, 0x39, 0);
            if (buf != 0) {
                func_02017E1C(mon, 0x73, (u32)buf);
                func_02045A38(buf, e->name, 11);
                func_02017E1C(mon, 0x8d, (u32)buf);
                func_02045A38(buf, e->ot, 8);
            } else {
                e->name[0] = func_02045A98();
                e->ot[0] = func_02045A98();
            }
            n++;
        }
        POKE_TOOL_EncodePartyParam(mon, saved);
    }
    rec->year = date->year;
    rec->month = date->month;
    rec->day = date->day;
    if (buf != 0) {
        func_02045808(buf);
    }
}
