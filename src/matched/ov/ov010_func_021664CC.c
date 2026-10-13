/*
 * function: SYMBOL_MAP_CreateLinkRecord
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
 * the same front half and was the shape source. Callees return real types: INTRUDE_COMM_GetPartnerSlot u8,
 * GAME_DATA_GetSymbolMapFlag int, func_0216749C u16, func_021673C4/A8 u8, func_02030734 void *.
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   func_02030734  0x02030734  arm
 *   func_0216749C  0x0216749C  thumb  ov010
 *   func_021673C4  0x021673C4  thumb  ov010
 *   func_021673A8  0x021673A8  thumb  ov010
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetPartnerRecord  0x02176880  thumb  ov011
 *   MI_CpuCopy8    0x02082D44  arm
 *   g_SymbolMapFileName     0x021729EC  data  a1
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

struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E0B0(void *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *field, void *p);
extern int GAME_DATA_GetSymbolMapFlag(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
extern u8 func_021673C4(u8 *st);
extern u8 func_021673A8(u8 *st);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern u8 *INTRUDE_COMM_GetPartnerRecord(u8 *link);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern const char g_SymbolMapFileName[];

LinkRecord *SYMBOL_MAP_CreateLinkRecord(u16 heap, void *sys, u32 *start)
{
    void *p;
    void *st;
    void *field;
    void *link;
    LinkRecord *rec;
    u32 page;
    u8 n;

    p = GAMESYSTEM_GetGameData(sys);
    st = func_0200E0B0(GAME_DATA_GetSaveControl(p));
    field = (void *)GAMESYSTEM_GetGameComm(sys);
    if (INTRUDE_COMM_GetPartnerSlot(field, p) == 4) {
        page = GAME_DATA_GetSymbolMapFlag(p);
        rec = func_02030734(heap, sizeof(LinkRecord), 1, g_SymbolMapFileName, 0x1C9);
        *start = func_0216749C(st, rec->list, 20, page, &n);
        rec->count = n;
        rec->st849 = func_021673C4(st);
        rec->st848 = func_021673A8(st);
        rec->kind = 4;
        rec->page = page;
        return rec;
    }
    link = (void *)INTRUDE_COMM_GetWorkIfRunning((int)field);
    if (link == 0)
        return 0;
    rec = func_02030734(heap, sizeof(LinkRecord), 1, g_SymbolMapFileName, 0x1DC);
    MI_CpuCopy8(INTRUDE_COMM_GetPartnerRecord(link), rec, sizeof(LinkRecord));
    *start = 530;
    return rec;
}
