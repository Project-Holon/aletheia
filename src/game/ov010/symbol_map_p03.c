/*
 * file:     symbol_map_p03.c
 * unit:     yes
 * function: func_021663F4, func_02166434, func_0216649C, func_021664CC
 * address:  0x021663F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216630C  0x0216630C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_021673C4  0x021673C4  thumb  ov010
 *   func_021673A8  0x021673A8  thumb  ov010
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02176880  0x02176880  thumb  ov011
 *   d_02171EF4 0x02171EF4 data a4
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02030734  0x02030734  arm
 *   func_0216749C  0x0216749C  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021729EC     0x021729EC  data  a1
 */
struct Big;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Rec {
    u8 pad[0x50];
    u32 : 6;
    u32 a : 4;
    u32 b : 4;
};

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

typedef struct LinkRecord {
    Entry32 list[20];   /* 0x00 */
    u32 count : 6;      /* 0x50 */
    u32 st849 : 4;
    u32 st848 : 4;
    u32 kind : 4;
    u32 page : 6;
    u32 rest : 8;
} LinkRecord;

extern int func_0216630C(int a0, int a1, int a2, int a3);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern u32 func_02012138(const struct Ctx *p);
extern u8 func_021767A0(void *a, void *b);
extern u8 func_021673C4(u8 *p);
extern u8 func_021673A8(u8 *p);
extern int func_02158344(int a0);
extern u8 *func_02176880(u8 *p);
extern int func_02012FB0(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
int func_021663F4(u8 *list, int def, unsigned dir, int a3);
/* * Reads two 4-bit values (bitfields at bits 6..9 and 10..13 of the word at +0x50 of * the record behind func_02176880) into the out parameters, or takes them * from the two ov010 accessors when func_021767A0 answers 4. */ int func_02166434(void *a, u32 *out0, u32 *out1);
/* * A zero case with a default continuation keeps the failure exit first. * Returns the full-word pointer payload from the selected table slot. */ u32 func_0216649C(void *p);
/* * Builds the 0x54-byte record sent over the link: locally from the * selected list page plus three packed status fields (with the page * start written to *start), or as a copy of the partner's record when * the exchange is not in state 4 (*start = 530). * * recoup 2026-10-05 (lane Y5): EXACT in c99 and c. The older draft was DIFF10/260: the * fifth argument store of the second allocation sat after the argument copies. Fix: the * heap id is u16 in this function and in the allocator prototype (both sides, as in the * ov010 and SDK callers that declare u16 heap). Plain literals 0x1DC and 530 already * derive 530 from the held 0x1DC; a constant local did not change the schedule. * Twin search: grep -rl -E "func_0216749C|func_021673C4|func_021673A8" src/matched src/pending * (hits ov010 02166434, 021673C4, 021673A8, 0216749C, ov011 02174D5C); ov010 02166434 has * the same front half and was the shape source. Callees return real types: func_021767A0 u8, * func_02012FB0 int, func_0216749C u16, func_021673C4/A8 u8, func_02030734 void *. */ LinkRecord *func_021664CC(u16 heap, void *sys, u32 *start);
extern u8 *d_02171EF4[];
extern const char d_021729EC[];


/*
 * Finds the position of a value in a byte list (func_0216630C) and returns
 * the entry a step away from it: 0 = three back, 1 = three on, 2 = one
 * back, 3 = one on; any other direction returns the default.
 */
int func_021663F4(u8 *list, int def, unsigned dir, int a3)
{
    int i = func_0216630C((int)list, def, dir, a3);

    switch (dir) {
    case 0:
        return list[i - 3];
    case 1:
        return list[i + 3];
    case 2:
        return list[i - 1];
    case 3:
        return list[i + 1];
    }
    return def;
}



/*
 * Reads two 4-bit values (bitfields at bits 6..9 and 10..13 of the word at +0x50 of
 * the record behind func_02176880) into the out parameters, or takes them
 * from the two ov010 accessors when func_021767A0 answers 4.
 */
int func_02166434(void *a, u32 *out0, u32 *out1)
{
    void *t;
    u8 *sav;
    void *r;
    struct Rec *rec;

    t = func_020120F4(a);
    sav = func_0200E0B0(func_02012EBC(t));
    r = (void *)func_02012138(a);
    if (func_021767A0(r, t) == 4) {
        *out0 = func_021673C4(sav);
        *out1 = func_021673A8(sav);
        return 1;
    }
    r = (void *)func_02158344((int)r);
    if (r == 0) {
        *out0 = 0;
        *out1 = 0;
        return 0;
    }
    rec = (struct Rec *)func_02176880(r);
    *out0 = rec->a;
    *out1 = rec->b;
    return 1;
}


/*
 * A zero case with a default continuation keeps the failure exit first.
 * Returns the full-word pointer payload from the selected table slot.
 */
u32 func_0216649C(void *p) {
    u32 a;
    u32 b;
    switch (func_02166434(p, &a, &b)) {
    case 0: return 0;
    default: break;
    }
    return *(u32 *)((u32)d_02171EF4 + (a + b * 7u) * 4u);
}



/*
 * Builds the 0x54-byte record sent over the link: locally from the
 * selected list page plus three packed status fields (with the page
 * start written to *start), or as a copy of the partner's record when
 * the exchange is not in state 4 (*start = 530).
 *
 * recoup 2026-10-05 (lane Y5): EXACT in c99 and c. The older draft was DIFF10/260: the
 * fifth argument store of the second allocation sat after the argument copies. Fix: the
 * heap id is u16 in this function and in the allocator prototype (both sides, as in the
 * ov010 and SDK callers that declare u16 heap). Plain literals 0x1DC and 530 already
 * derive 530 from the held 0x1DC; a constant local did not change the schedule.
 * Twin search: grep -rl -E "func_0216749C|func_021673C4|func_021673A8" src/matched src/pending
 * (hits ov010 02166434, 021673C4, 021673A8, 0216749C, ov011 02174D5C); ov010 02166434 has
 * the same front half and was the shape source. Callees return real types: func_021767A0 u8,
 * func_02012FB0 int, func_0216749C u16, func_021673C4/A8 u8, func_02030734 void *.
 */
LinkRecord *func_021664CC(u16 heap, void *sys, u32 *start)
{
    void *p;
    void *st;
    void *field;
    void *link;
    LinkRecord *rec;
    u32 page;
    u8 n;

    p = func_020120F4(sys);
    st = func_0200E0B0(func_02012EBC(p));
    field = (void *)func_02012138(sys);
    if (func_021767A0(field, p) == 4) {
        page = func_02012FB0(p);
        rec = func_02030734(heap, sizeof(LinkRecord), 1, d_021729EC, 0x1C9);
        *start = func_0216749C(st, rec->list, 20, page, &n);
        rec->count = n;
        rec->st849 = func_021673C4(st);
        rec->st848 = func_021673A8(st);
        rec->kind = 4;
        rec->page = page;
        return rec;
    }
    link = (void *)func_02158344((int)field);
    if (link == 0)
        return 0;
    rec = func_02030734(heap, sizeof(LinkRecord), 1, d_021729EC, 0x1DC);
    MI_CpuCopy8(func_02176880(link), rec, sizeof(LinkRecord));
    *start = 530;
    return rec;
}
