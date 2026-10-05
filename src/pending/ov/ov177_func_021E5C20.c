/*
 * function: func_021E5C20
 * address: 0x021E5C20
 * packet: pkt_ov177_021E5C20
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 allocator/clear/ARM9 and own 6718 full body/forwarders re-derived; its tenth HeapArg input reads low16 but this caller forwards fullword so extern stays u32; 2 matched 5D68/6118/7520 constructors reread; 3 enum a1, const a2 and late typed Info view each unchanged14; 4 typed-view, enum and homing idioms read; 5 fresh unfiltered idiom list and ov176/177 constructors reread, stack object shape already matches; prior permuter300 baseline288/14 agreed and unchanged, not repeated.
 * Residual: final retry exhausted; DIFF 288/288 B, 14 prologue scheduling bytes differ.
 * Four iteration runs: enum a1, allocation inline, late typed Info; all unchanged.
 * Check3 const a2 unchanged. Manual scheduling cap used (allocation/Info variants).
 * No further sweep: final retry and three-nonshrinking iteration stop.
 * note 2026-10-05 (wave P8 W5): DIFF 288/288 B, 14 B: the original loads the stack argument heap (ldr r7,[sp,#0x5c]) right after the first home store (str r1,[sp,#0x18]); ours loads it after str r2,[sp,#0x1c]. Only the prologue order differs. Tried, all unchanged at 14 B: no heapId local, heapId declared late or assigned first, plain 0x229 literal instead of the enum, size/site as two locals, k=0x229 local with raw w[k+7] byte stores, u32 owner, const on heap/owner/table/a5, declaration order reversed, each of opt_lifetimes/common_subs/dead_assignments/scheduling/peephole off (unchanged; opt_propagation off breaks the function, 262 B). u16 heap changes entry to add r0,sp,#0x48; ldrh (264 B), so the original word load is a u32 parameter. Siblings 5D68/6118/7520 use u16 heap and store it to w+0x23c, so they are not twins for this prologue.
 * symbols:
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   func_021E6718 0x021E6718 thumb ov177
 *   func_021E72FC 0x021E72FC thumb ov177
 *   func_0204B404 0x0204B404 arm
 *   func_021E7464 0x021E7464 thumb ov177
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y; } Point;
typedef struct {
    u32 f0; u16 h4, pad6; u32 f8; void *fC; u16 h10, h12;
} Info;
typedef struct {
    char pad0[0x188];
    void *f188;
    char pad18c[0x230 - 0x18c];
    u8 c230, c231, c232, c233;
    u32 f234;
    char pad238[0x244 - 0x238];
} Work;
typedef enum { ALLOC_SITE = 0x229 } AllocSize;
extern const char d_021E8DBC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, int, u32);
extern void func_0207D63C(void *, int, int, int, int);
extern u32 func_021E7CF0(void *, u16, u16);
extern void func_021E6718(Work *, u32, const Info *, void *, int, void *, void *, void *, int, u32);
extern void func_021E72FC(u8 *, u32, u32, u32);
extern void func_0204B404(void *, const Point *, u16);
extern void func_021E7464(char *, char *, u32, void *, u32);
extern void func_020413B0(u32, u8, u8, u8, u8, u8);
extern void func_020409B4(u32);
Work *func_021E5C20(const Info *info, u32 a1, void *a2, int owner,
                    void *table, int a5, void *a6, void *a7, void *a8, u32 heap)
{
    u32 heapId = heap;
    Work *w;
    u32 kind;
    u32 size;
    int alt;
    Point pos;
    size = ALLOC_SITE;
    size += 0x1b;
    w = func_02030734(heapId, size, 0, d_021E8DBC, ALLOC_SITE);
    func_02082BCC(w, 0, size);
    w->c230 = 5;
    w->c231 = 15;
    w->c232 = 3;
    w->c233 = 7;
    w->f234 = 1;
    alt = 1;
    func_0207D63C((void *)0x04001050, 4, 8, 15, 3);
    kind = func_021E7CF0(info->fC, info->h10, info->h12);
    if (kind != 5) alt = 0;
    func_021E6718(w, a1, info, a2, a5, a6, a7, a8, alt, heapId);
    func_021E72FC((u8 *)w, info->f8, owner, heapId);
    pos.x = 0x120;
    pos.y = 0x44;
    func_0204B404(w->f188, &pos, 1);
    func_021E7464((char *)w, (char *)info, owner, table, heapId);
    func_020413B0(6, 0, 0, 0x20, 6, 1);
    func_020413B0(6, 0, 6, 0x20, 18, kind + 3);
    func_020409B4(6);
    func_0207D63C((void *)0x04001050, 4, 8, 15, 3);
    return w;
}
