/*
 * function: func_021664CC
 * address:  0x021664CC
 * packet:   pkt_ov010_021664CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Builds the 0x54-byte record sent over the link: locally from the
 * selected list page plus three packed status fields (with the page
 * start written to *start), or as a copy of the partner's record when
 * the exchange is not in state 4 (*start = 530).
 *
 * DIFF, size-exact, 10 bytes out (2026-09-28 tree_ov010_4): the bitfield
 * word at +0x50 is settled by the pool masks (6/4/4/4/6 bits, the 4-bit
 * kind set to 4). Left: in the partner path the image stores the line
 * 0x1DC to the stack argument right after forming it; 1.1p1 stores it
 * last. Permuter seed 9602 (anneal, 400) found nothing below 10. Notes:
 * docs/notes/pkt_ov010_021664CC.c.txt. The bl to ov011 0x02176880 has no
 * label.
 *
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
extern int func_021767A0(void *field, void *p);
extern u32 func_02012FB0(void *p);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
extern u8 func_021673C4(void *st);
extern u8 func_021673A8(void *st);
extern void *func_02158344(void *field);
extern void *func_02176880(void *link);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern const char d_021729EC[];

LinkRecord *func_021664CC(u32 heap, void *sys, u32 *start)
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
