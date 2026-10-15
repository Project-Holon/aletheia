/*
 * file:     gf_overlay.c
 * unit:     yes
 * function: sub_02034768, func_020348A4, sub_02034900, func_02034978, func_0203499C, func_02034A3C, func_02034A5C, func_02034AC4, func_02034BB0, GF_OVERLAY_GetSlots, GF_OVERLAY_GetSlotCount, GF_OVERLAY_GetArea, GF_OVERLAY_GetRamRange
 * address:  0x02034768
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020808F4  0x020808F4  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207D534  0x0207D534  arm
 *   TEXTPRINT_Init  0x0204E130  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_Clear   0x02043B5C  arm
 *   _DebugConsole   0x021469AC  data
 *   _NewlineStr  0x020A796C  data
 *   TEXTPRINT_PrintText 0x0204E328  arm
 *   G2_GetBG0ScrPtr   0x0207DF60  arm
 *   BMP_GetPixels     0x020437D4  arm
 *   DC_FlushRange     0x020862F0  arm
 *   GXS_LoadBG0Char   0x0207EE68  arm
 *   OS_Terminate      0x02088234  arm
 *   sub_02034768  0x02034768  arm
 *   sub_02034900  0x02034900  arm
 *   func_02030734   0x02030734  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   _pOverlayTables    0x021469B8  data
 *   _FileName      0x020A7970  data
 *   func_020792B8  0x020792B8  arm
 *   GF_OVERLAY_GetArea  0x02034D60  arm
 *   GF_OVERLAY_GetSlots  0x02034CBC  arm
 *   GF_OVERLAY_GetSlotCount  0x02034D08  arm
 *   SAVEDATA_PanicFail         0x02034714  arm
 *   FS_SetDefaultDMA     0x0207AC64  arm
 *   FS_LoadOverlay       0x02079264  arm
 *   _AssertExprZero              0x020A7980  data
 *   GF_OVERLAY_GetRamRange  0x02034DC4  arm
 *   FS_LoadOverlayInfo           0x02078D34  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   SAVEDATA_SetPanicHandlers  0x020346EC  arm
 */
#define REG_DISPCNT  (*(vu32 *)0x04000000)
#define REG_BG0CNT   (*(vu16 *)0x04000008)
#define REG_BG0OFS   (*(vu32 *)0x04000010)
#define REG_BLDCNT   (*(vu16 *)0x04000050)
#define REG_IME      (*(vu16 *)0x04000208)
#define REG_POWCNT   (*(vu16 *)0x04000304)
#define BG_PLTT_1    (*(vu16 *)0x05000002)
#define BG_PLTT_2    (*(vu16 *)0x05000004)
struct Bmp;
struct CharBuf;
typedef unsigned char      u8;

typedef unsigned short     u16;

typedef unsigned int       u32;

typedef volatile u16       vu16;

typedef volatile u32       vu32;

struct DebugConsole {
    struct Bmp *charBitmap; /* 0x0 */
    u16   cursorX;      /* 0x4 */
    u16   cursorY;      /* 0x6 */
    u8    advanceX;     /* 0x8 */
    u8    advanceY;     /* 0x9 */
    u8    fgColor : 4;  /* 0xA */
    u8    bgColor : 4;
    u8    flags;        /* 0xB */
};

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

extern int func_020808F4(void);
extern void  func_0207FDCC(u32 enable);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void  TEXTPRINT_Init(u32 fontId);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heapId);
extern void BMP_Clear(struct CharBuf *buf, u8 fillValue);
extern void TEXTPRINT_PrintText(const char *text, struct DebugConsole *console);
extern u16 *G2_GetBG0ScrPtr(void);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void DC_FlushRange(void *addr, u32 size);
extern void GXS_LoadBG0Char(const void *src, u32 offset, u32 size);
extern void OS_Terminate(void);
extern void SAVEDATA_SetPanicHandlers(u32 initFn, u32 printFn, u32 dieFn);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void  MIi_CpuClear32(u32 data, void *dest, u32 size);
extern int func_020792B8(u32 target, u32 id);
extern void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr);
extern int FS_SetDefaultDMA(int dma);
extern int FS_LoadOverlay(int target, s32 handle);
extern int FS_LoadOverlayInfo(struct OverlayInfo *info, u32 target, u32 id);
void sub_02034768(void);
void func_020348A4(char *text);
void sub_02034900(void);
void sub_02034978(void);
void GF_OVERLAY_Init(u32 heapId, int mainCount, int itcmCount, int twlCount);
void GF_OVERLAY_ReleaseSlot(struct OverlaySlot *slot);
void GF_OVERLAY_Unload(s32 handle);
int GF_OVERLAY_Load(s32 handle);
int GF_OVERLAY_CheckRangeFree(s32 handle);
void *GF_OVERLAY_GetSlots(int area);
u8 GF_OVERLAY_GetSlotCount(int area);
int GF_OVERLAY_GetArea(u32 id);
int GF_OVERLAY_GetRamRange(u32 id, u32 *start, u32 *end);
extern struct DebugConsole _DebugConsole;
extern const char _NewlineStr[];
extern struct OverlayTables *_pOverlayTables;
extern const char _FileName[];
extern const char _AssertExprZero[];
extern const unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];


/*
 * Bring up the panic screen.  The assert path (SAVEDATA_PanicFailPrintf forwards here)
 * has to draw text after the game has already lost whatever video state it
 * was running, so this tears the display down to a known configuration and
 * rebuilds exactly one text layer on it:
 *
 *   - interrupts are masked (REG_IME latched and cleared), every layer is
 *     switched off in DISPCNT, and the VRAM/engine teardown helpers run;
 *   - POWCNT's LCD-swap bit is cleared so the screen this draws on is the
 *     one the user is looking at;
 *   - blend (0x04000050) and master brightness (0x0400006C) are neutralised;
 *   - DISPCNT is reduced to graphics mode 0 with BG0 alone enabled
 *     (~0xE000, then (x & ~0x1F00) | 0x100, then ~0x38000000 and
 *     ~0x07000000 for the VRAM-block and OBJ-mapping fields);
 *   - BG0CNT keeps only priority and mosaic and takes character base 4
 *     ((x & 0x43) | 0x10), then drops its priority to 0 (x & ~3), and BG0's
 *     scroll pair at 0x04000010 is zeroed as one 32-bit write;
 *   - the first two BG palette entries become white (0x7FFF) and the panic
 *     text colour (0x60E1);
 *   - a 0x20x8 4bpp character buffer is allocated, published at
 *     _DebugConsole.charBitmap, and cleared to pixel value 2.
 *
 * Two shapes here are compiler idiom rather than source:
 *
 *   0x7FFF is not an ARM rotated immediate, so it is rematerialised as
 *   `rsb r3, r4, #0x8000` off the register that already holds 1
 *   (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-\
 *   unless-an-argument-shares-it.md, read with 1 in place of 0).
 *
 *   The palette base pooled at 0x05000002 rather than 0x05000000 is the
 *   pool-base-masked-by-the-load's-reach idiom: the constant materialised
 *   is the address of the *first* access, and the second entry is reached
 *   at +2 from it.
 *
 * The two bitfield stores at +0xA are one register value, not two
 * read-modify-writes: the dead first `strb` is eliminated but the `and
 * r3, r3, #0xff` truncation between the statements survives, which is what
 * says these are two separate 4-bit field assignments and not a single
 * merged `(x & ~0xFF) | 0x21`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034768.c \
 *       --func sub_02034768 --addr 0x02034768 --cc 1.1p1 --arm
 */
void sub_02034768(void)
{
    u16 savedIme;
    void *charBuf;

    savedIme = REG_IME;
    REG_IME = 0;

    REG_DISPCNT = REG_DISPCNT & ~0x1f00;
    func_020808F4();
    func_0207FDCC(1);

    REG_POWCNT = REG_POWCNT & ~0x8000;
    func_0207D4B0(1, 0, 0);

    REG_BLDCNT = 0;
    func_0207D534((volatile u16 *)0x0400006c, 0);

    REG_DISPCNT = REG_DISPCNT & ~0xe000;
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x100;
    REG_DISPCNT = REG_DISPCNT & ~0x38000000;
    REG_DISPCNT = REG_DISPCNT & ~0x07000000;

    REG_BG0CNT = (REG_BG0CNT & 0x43) | 0x10;
    REG_BG0CNT = REG_BG0CNT & ~3;
    REG_BG0OFS = 0;

    BG_PLTT_1 = 0x7fff;
    BG_PLTT_2 = 0x60e1;

    TEXTPRINT_Init(0);

    charBuf = BMP_Create(0x20, 8, 0x20, 0);
    _DebugConsole.charBitmap = charBuf;
    _DebugConsole.cursorX = 0;
    _DebugConsole.cursorY = 0;
    _DebugConsole.advanceX = 1;
    _DebugConsole.advanceY = 1;
    _DebugConsole.fgColor = 1;
    _DebugConsole.bgColor = 2;
    _DebugConsole.flags = 0;

    BMP_Clear(charBuf, 2);
}








/*
 *           --suggest-split offers nothing (single function, both
 *           unresolved sites' only witnesses are inside this range).
 *           witness outside 020348A4..02034900; both of this site's calls to
 *           TEXTPRINT_PrintText are inside this function. Every concrete byte of the
 *           body reproduces.
 */
void func_020348A4(char *text)
{
    int hasNewline;

    TEXTPRINT_PrintText(text, &_DebugConsole);
    hasNewline = 0;
    while (*text != 0) {
        if (*text++ == '\n') {
            hasNewline = 1;
            break;
        }
    }
    if (hasNewline == 0) {
        TEXTPRINT_PrintText(_NewlineStr, &_DebugConsole);
    }
}








/*
 * The third of the three default assert handlers sub_02034978 registers:
 * the die handler.  It fills the main BG0 screen map with the identity
 * mapping (256 tiles laid out 32 per row over 8 rows, the counter running
 * straight through both loops rather than restarting per row), uploads the
 * 0x2000 byte font character data the object at 0x021469AC owns to the sub
 * screen, and stops the machine.
 *
 * The row stride is written as `p += 0x20` on a `u16 *`, which is the
 * `add r0, r0, #0x40` at the bottom of the outer loop; the inner index is a
 * plain subscript, hence `lsl r1, r3, #1` per store rather than a walking
 * pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034900.c \
 *       --func sub_02034900 --addr 0x02034900 --cc 1.1p1 --arm
 */
void sub_02034900(void)
{
    u16 *screenMap;
    int col;
    int row;
    int tile;
    void *charData;

    screenMap = G2_GetBG0ScrPtr();

    tile = 0;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 0x20; col++) {
            screenMap[col] = tile;
            tile++;
        }
        screenMap += 0x20;
    }

    charData = BMP_GetPixels(_DebugConsole.charBitmap);
    DC_FlushRange(charData, 0x2000);
    GXS_LoadBG0Char(charData, 0, 0x2000);
    OS_Terminate();
}








/*
 * The default-handler registration trampoline: tail-calls SAVEDATA_SetPanicHandlers
 * (pkt_020345F8, the "register" half of the assert/panic hook: see
 * src/matched/unit_020346EC.c) with the addresses of this packet's own
 * three biggest functions, none of which is matched yet.
 *
 * Every concrete byte matches; the three ABS32 sites naming those
 * functions have no witness anywhere else in the ARM9 image (each of
 * those addresses is a function that no `bl`/`label` site reaches), so
 * they stay unresolved under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034978.c \
 *       --func sub_02034978 --addr 0x02034978 --cc 1.1p1 --arm
 */
void sub_02034978(void)
{
    SAVEDATA_SetPanicHandlers((u32)sub_02034768, (u32)func_020348A4, (u32)sub_02034900);
}








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

    tables = func_02030734(heapId, totalSlots * sizeof(struct OverlaySlot) + sizeof(struct OverlayTables), 0,
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
 * func_020792B8 is called from exactly this one site in the whole ROM, so
 * the relocation has no `label` witness; it resolves on class `matched`
 * against src/matched/func_020792B8.c, which is EXACT since
 * src/matched/unit_02079164.c attested its own callee.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_ReleaseSlot.c \
 *       --func GF_OVERLAY_ReleaseSlot --addr 0x02034A3C --cc 1.1p1 --arm
 */
void GF_OVERLAY_ReleaseSlot(struct OverlaySlot *slot)
{
    func_020792B8(0, slot->handle);
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
 * src/matched/func_020792B8.c and src/matched/unit_02079164.c.
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
        SAVEDATA_PanicFail(_FileName, 267, _AssertExprZero);
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
                    SAVEDATA_PanicFail(_FileName, 330, _AssertExprZero);
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
