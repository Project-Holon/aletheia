/*
 * file:     gf_overlay.c
 * unit:     yes
 * function: GF_OVERLAY_Init, GF_OVERLAY_ReleaseSlot, GF_OVERLAY_Unload, GF_OVERLAY_Load, GF_OVERLAY_CheckRangeFree, GF_OVERLAY_GetSlots, GF_OVERLAY_GetSlotCount, GF_OVERLAY_GetArea, GF_OVERLAY_GetRamRange
 * address:  0x0203499C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * The panic-screen functions (GF_PANIC_Init/PanicPrint/PanicDie and
 * GF_PANIC_RegisterDefaultHandlers) were cut to vman.c at 0x02034768 by lane A4;
 * this file's own anchor resumes exactly at 0x0203499C (pool site 0x02034A34).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MIi_CpuClear32   0x02082A7C  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   FS_UnloadOverlay  0x020792B8  arm
 *   FS_SetDefaultDMA     0x0207AC64  arm
 *   FS_LoadOverlay       0x02079264  arm
 *   FS_LoadOverlayInfo           0x02078D34  arm
 *   _pOverlayTables    0x021469B8  data
 *   _FileName      0x020A7970  data
 *   _AssertExprZero              0x020A7980  data
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 */

typedef unsigned char      u8;

typedef unsigned short     u16;

typedef unsigned int       u32;
typedef signed int    s32;

/* One loaded-overlay record: the overlay id it holds and whether it is live. */
struct OverlaySlot {
    s32 handle;
    s32 state;
};

/*
 * The singleton behind the three overlay tables.  Table 0 serves overlays
 * placed in main RAM, table 1 those placed in the ITCM window
 * (0x01000000..0x02000000), table 2 those in the TWL autoload window.
 */
struct OverlayTables {
    u8 mainCount;
    u8 itcmCount;
    u8 twlCount;
    u8 pad03;
    struct OverlaySlot *mainSlots;
    struct OverlaySlot *itcmSlots;
    struct OverlaySlot *twlSlots;
};

struct OverlayInfo {
    u32 id;
    u32 ramAddress;
    u32 ramSize;
    u32 bssSize;
    u32 sinitInit;
    u32 sinitInitEnd;
    u32 fileId;
    u32 compressed;
    u32 fileArchive;
    u32 fileIndex;
    u32 procTarget;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void  MIi_CpuClear32(u32 data, void *dest, u32 size);
extern int FS_UnloadOverlay(u32 target, u32 id);
extern void GF_PANIC_Fail(const char *file, u32 line, const char *expr);
extern int FS_SetDefaultDMA(int dma);
extern int FS_LoadOverlay(int target, s32 handle);
extern int FS_LoadOverlayInfo(struct OverlayInfo *info, u32 target, u32 id);

void GF_OVERLAY_Init(u32 heapId, int mainCount, int itcmCount, int twlCount);
void GF_OVERLAY_ReleaseSlot(struct OverlaySlot *slot);
void GF_OVERLAY_Unload(s32 handle);
int GF_OVERLAY_Load(s32 handle);
int GF_OVERLAY_CheckRangeFree(s32 handle);
void *GF_OVERLAY_GetSlots(int area);
u8 GF_OVERLAY_GetSlotCount(int area);
int GF_OVERLAY_GetArea(u32 id);
int GF_OVERLAY_GetRamRange(u32 id, u32 *start, u32 *end);

extern struct OverlayTables *_pOverlayTables;
extern const char _FileName[];
extern const char _AssertExprZero[];
extern const unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];








/*
 * gf_overlay.c's constructor: allocate the singleton GF_OVERLAY_GetSlots and
 * GF_OVERLAY_GetSlotCount read, one 0x10-byte header followed by the three
 * overlay slot tables laid end to end, zero it, then record the three table
 * lengths at +0/+1/+2 and the three table bases at +4/+8/+0xc.
 *
 * Every store to the singleton is preceded by a fresh `ldr r0, [r7]` because
 * the object being written is reached through the global pointer itself: the
 * compiler cannot prove `tables->mainSlots = ...` does not land on `_pOverlayTables`, so it
 * reloads the pointer before each store.  The allocation size is spelled out
 * twice rather than kept in a local, which is why only the `<< 3` is common
 * subexpression eliminated and the `+ 0x10` is recomputed for the clear.
 *
 * The file string is "gf_overlay.c" and the debug line is 108.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_Init.c \
 *       --func GF_OVERLAY_Init --addr 0x0203499C --cc 1.1p1 --arm
 */
void GF_OVERLAY_Init(u32 heapId, int mainCount, int itcmCount, int twlCount)
{
    struct OverlayTables *tables;
    int totalSlots;

    totalSlots = mainCount + itcmCount + twlCount;

    tables = GFL_HEAP_Alloc(heapId, totalSlots * sizeof(struct OverlaySlot) + sizeof(struct OverlayTables), 0,
                      _FileName, 108);
    _pOverlayTables = tables;
    MIi_CpuClear32(0, tables, totalSlots * sizeof(struct OverlaySlot) + sizeof(struct OverlayTables));

    _pOverlayTables->mainCount = mainCount;
    _pOverlayTables->itcmCount = itcmCount;
    _pOverlayTables->twlCount = twlCount;
    _pOverlayTables->mainSlots = (struct OverlaySlot *)(_pOverlayTables + 1);
    _pOverlayTables->itcmSlots = _pOverlayTables->mainSlots + mainCount;
    _pOverlayTables->twlSlots = _pOverlayTables->itcmSlots + itcmCount;
}








/*
 * Forwards `p`'s first field to an extern with a constant 0, then clears
 * `p`'s second field regardless of what the call returns.
 *
 * FS_UnloadOverlay is called from exactly this one site in the whole ROM, so
 * the relocation has no `label` witness; it resolves on class `matched`
 * against src/matched/FS_UnloadOverlay.c, which is EXACT since
 * src/matched/unit_02079164.c attested its own callee.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_ReleaseSlot.c \
 *       --func GF_OVERLAY_ReleaseSlot --addr 0x02034A3C --cc 1.1p1 --arm
 */
void GF_OVERLAY_ReleaseSlot(struct OverlaySlot *slot)
{
    FS_UnloadOverlay(0, slot->handle);
    slot->state = 0;
}




/*
 * Release the slot an overlay handle owns.  -1 is the "no handle" value and
 * returns at once; otherwise the handle is resolved to its area index
 * (GF_OVERLAY_GetArea), which selects the eight-byte slot table
 * (GF_OVERLAY_GetSlots) and its live length (GF_OVERLAY_GetSlotCount), and the first
 * entry whose state word at +4 is 1 and whose handle at +0 is the one asked
 * for is handed to GF_OVERLAY_ReleaseSlot.  At most one entry matches, so the scan
 * returns rather than breaking.
 *
 * The second field load is spelled off the table base with the scaled index
 * (`ldreq r1, [r5, r3, lsl #3]`) rather than off the entry pointer already
 * in r2: writing both halves of the condition against the same `&table[i]`
 * local costs a `ldr r1, [r2]` instead and is a byte difference.
 *
 * The PC24 at +0x50 (GF_OVERLAY_ReleaseSlot) has no `label` witness: the `bl` at
 * 0x02034AAC inside this function is 0x02034A3C's only reference anywhere
 * in the image.  It resolves on class `matched` now that
 * src/matched/GF_OVERLAY_ReleaseSlot.c is EXACT, which in turn waited on
 * src/matched/FS_UnloadOverlay.c and src/matched/unit_02079164.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_Unload.c \
 *       --func GF_OVERLAY_Unload --addr 0x02034A5C --cc 1.1p1 --arm
 */
void GF_OVERLAY_Unload(s32 handle)
{
    s32 area;
    struct OverlaySlot *slots;
    s32 slotCount;
    s32 index;

    if (handle == -1) {
        return;
    }

    area = GF_OVERLAY_GetArea(handle);
    slots = GF_OVERLAY_GetSlots(area);
    slotCount = GF_OVERLAY_GetSlotCount(area);

    for (index = 0; index < slotCount; index++) {
        if (slots[index].state == 1 && handle == slots[index].handle) {
            GF_OVERLAY_ReleaseSlot(&slots[index]);
            return;
        }
    }
}




int GF_OVERLAY_Load(s32 handle)
{
    int area;
    int oldDma = -1;
    struct OverlaySlot *slots;
    int slotCount;
    int index;
    int loaded;
    int result;

    if (handle == oldDma) {
        return 1;
    }

    if (GF_OVERLAY_CheckRangeFree(handle) == 0) {
        return 0;
    }

    area = GF_OVERLAY_GetArea(handle);
    slots = GF_OVERLAY_GetSlots(area);
    slotCount = GF_OVERLAY_GetSlotCount(area);

    for (index = 0; index < slotCount; index++) {
        struct OverlaySlot *slot = &slots[index];
        if (slot->state == 0) {
            slot->state = 1;
            slot->handle = handle;
            break;
        }
    }

    if (index >= slotCount) {
        GF_PANIC_Fail(_FileName, 267, _AssertExprZero);
        return 0;
    }

    area--;
    if ((u32)area <= 1) {
        oldDma = FS_SetDefaultDMA(-1);
    }

    loaded = FS_LoadOverlay(0, handle);

    if ((u32)area <= 1) {
        FS_SetDefaultDMA(oldDma);
    }

    result = 0;
    if (loaded != 0) {
        result = 1;
    }
    return result;
}




/*
 * The admission test GF_OVERLAY_Load runs before it claims a slot: an overlay
 * may only be loaded if its RAM footprint is disjoint from every overlay
 * already live in the same table.  An overlay whose header cannot be read
 * is refused outright; an overlap is the GF_ASSERT(0) at gf_overlay.c:330
 * and a 0 return.
 *
 * The three ways two ranges can overlap are one `||` expression, not three
 * `if`s: all three arms branch to the same assert block, which is only
 * reachable as a shared exit if the disjunction is written as a single
 * expression (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * The four out-parameters sit at sp+0xc, sp+8, sp+4 and sp+0 in declaration
 * order, the later declaration taking the lower address.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_CheckRangeFree.c \
 *       --func GF_OVERLAY_CheckRangeFree --addr 0x02034BB0 --cc 1.1p1 --arm
 */
int GF_OVERLAY_CheckRangeFree(s32 handle)
{
    u32 start;
    u32 end;
    u32 otherStart;
    u32 otherEnd;
    int area;
    struct OverlaySlot *slots;
    int slotCount;
    int index;

    if (GF_OVERLAY_GetRamRange(handle, &start, &end) == 0) {
        return 0;
    }

    area = GF_OVERLAY_GetArea(handle);
    slots = GF_OVERLAY_GetSlots(area);
    slotCount = GF_OVERLAY_GetSlotCount(area);

    for (index = 0; index < slotCount; index++) {
        if (slots[index].state == 1) {
            if (GF_OVERLAY_GetRamRange(slots[index].handle, &otherStart, &otherEnd) == 1) {
                if ((start >= otherStart && start < otherEnd) ||
                    (end > otherStart && end <= otherEnd) ||
                    (start <= otherStart && end >= otherEnd)) {
                    GF_PANIC_Fail(_FileName, 330, _AssertExprZero);
                    return 0;
                }
            }
        }
    }
    return 1;
}



/*
 * Selects one of three overlay slot tables out of the overlay-tables singleton by
 * a small index.  The singleton holds the three table pointers at +4, +8
 * and +0xc; an out-of-range index yields the same table as index 0, which
 * is why the compiler cross-jumps the default return onto case 0's block
 * and the `cmp r0, #0` at the top branches to the tail rather than to a
 * block of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetSlots.c \
 *       --func GF_OVERLAY_GetSlots --addr 0x02034CBC --cc 1.1p1 --arm
 */
void *GF_OVERLAY_GetSlots(int area)
{
    switch (area) {
    default:
    case 0:
        return _pOverlayTables->mainSlots;
    case 1:
        return _pOverlayTables->itcmSlots;
    case 2:
        return _pOverlayTables->twlSlots;
    }
}



/*
 * The live-length companion of GF_OVERLAY_GetSlots: the same three-way index, but
 * reading the three `u8` counts packed at the head of the overlay-tables singleton
 * rather than the table pointers at +4/+8/+0xc.  Here the default is its own
 * arm returning 0, so the `cmp r0, #0` block is distinct and the dispatch
 * chain ends in an explicit `b` to the zero tail instead of cross-jumping.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetSlotCount.c \
 *       --func GF_OVERLAY_GetSlotCount --addr 0x02034D08 --cc 1.1p1 --arm
 */
u8 GF_OVERLAY_GetSlotCount(int area)
{
    switch (area) {
    case 0:
        return _pOverlayTables->mainCount;
    case 1:
        return _pOverlayTables->itcmCount;
    case 2:
        return _pOverlayTables->twlCount;
    }
    return 0;
}




/*
 * Maps an overlay id onto the overlay table index that owns it: the
 * overlay header's ramAddress (+4) inside 0x01000000..0x02000000 is
 * table 1, inside the arm9_autoload1_main_twl window (its base up to
 * base + 0x4000) is table 2, anything else is 0.  The two range guards
 * are sequential, so each `hs` arm carries its own epilogue.
 *
 * Shape notes:
 *  - `id = info.ramAddress;` reuses the parameter; a fresh local puts
 *    the load in r1 and shifts every compare by a register.
 *  - The window base is the linker region symbol cast to an integer.  The
 *    image pools 0x02FE0000 in r1 and derives the bound with
 *    `add r0, r1, #0x4000`.  A literal base (any spelling) colours base
 *    r0 / bound r1 (5 out); the symbol kept as a pointer gives the right
 *    registers but folds base + 0x4000 into a second relocated pool word
 *    (104 bytes).  Only the integer cast keeps both the add and the
 *    colouring (u32 and unsigned long both EXACT).  Same region symbol as
 *    src/matched/GFL_USE_VBlankHandler.c and src/matched/GFL_HEAP_InitSystemHeap.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetArea.c \
 *       --func GF_OVERLAY_GetArea --addr 0x02034D60 --cc 1.1p1 --arm
 */
int GF_OVERLAY_GetArea(u32 id)
{
    struct OverlayInfo overlayInfo;
    u32 twlBase;

    FS_LoadOverlayInfo(&overlayInfo, 0, id);

    id = overlayInfo.ramAddress;
    if (id <= 0x02000000 && id >= 0x01000000) {
        return 1;
    }
    twlBase = (u32)SDK_AUTOLOAD_MAIN_TWL_START;
    if (id <= twlBase + 0x4000 && id >= twlBase) {
        return 2;
    }
    return 0;
}




/*
 * Reports the RAM footprint of an overlay: on success the load address goes
 * to the first out-parameter and the one-past-the-end address (load address
 * plus the image and bss sizes) to the second, and the function answers 1.
 * A failed header read answers 0 and touches neither.
 *
 * The literal 0 is kept in a callee-saved register across the call because
 * both the `target` argument and the failure return need it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetRamRange.c \
 *       --func GF_OVERLAY_GetRamRange --addr 0x02034DC4 --cc 1.1p1 --arm
 */
int GF_OVERLAY_GetRamRange(u32 id, u32 *start, u32 *end)
{
    struct OverlayInfo overlayInfo;
    u32 ramStart;

    if (FS_LoadOverlayInfo(&overlayInfo, 0, id) == 0) {
        return 0;
    }

    ramStart = overlayInfo.ramAddress;
    *start = ramStart;
    *end = ramStart + (overlayInfo.ramSize + overlayInfo.bssSize);
    return 1;
}
