/*
 * function: func_021664CC
 * address:  0x021664CC
 * packet:   pkt_ov010_021664CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
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
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02030734  0x02030734  arm
 *   func_0216749C  0x0216749C  thumb  ov010
 *   func_021673C4  0x021673C4  thumb  ov010
 *   func_021673A8  0x021673A8  thumb  ov010
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02176880  0x02176880  thumb  ov011
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021729EC     0x021729EC  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern void *func_020120F4(void *sys);
extern void *func_02012EBC(void *p);
extern void *func_0200E0B0(void *p);
extern void *func_02012138(void *sys);
extern u8 func_021767A0(void *field, void *p);
extern int func_02012FB0(u8 *p);
extern void *func_02030734(u16 heap, u32 size, int flags, const char *file, u16 line);
extern u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
extern u8 func_021673C4(u8 *st);
extern u8 func_021673A8(u8 *st);
extern void *func_02158344(void *field);
extern u8 *func_02176880(u8 *link);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern const char d_021729EC[];

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
    field = func_02012138(sys);
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
    link = func_02158344(field);
    if (link == 0)
        return 0;
    rec = func_02030734(heap, sizeof(LinkRecord), 1, d_021729EC, 0x1DC);
    MI_CpuCopy8(func_02176880(link), rec, sizeof(LinkRecord));
    *start = 530;
    return rec;
}
