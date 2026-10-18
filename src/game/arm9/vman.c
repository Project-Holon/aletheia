/*
 * file:     vman.c
 * unit:     yes
 * function: VMAN_GetBankSetSize, VMAN_Create, VMAN_Delete, VMAN_GetUnitSize, VMAN_InvalidateHandle, VMAN_IsHandleInvalid, VMAN_Alloc, VMAN_Free, VMAN_GetOffset, SAVEDATA_SetPanicHandlers, SAVEDATA_SetFailHook, SAVEDATA_PanicFail, SAVEDATA_PanicFailPrintf, GF_OVERLAY_PanicInit, GF_OVERLAY_PanicPrint, GF_OVERLAY_PanicDie, GF_OVERLAY_RegisterPanicHandlers
 * address:  0x02034520
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from savedata.c and gf_overlay.c by lane A4 (tools/splitfile.py). This is
 * the original vman.c: the VRAM bank manager (VMAN_*) plus the panic screen it
 * registers (SAVEDATA_SetPanic*, GF_OVERLAY_Panic*). The anchored part is
 * VMAN_Create at 0x02034558 ("vman.c" __FILE__ string 0x020A7964, pool site
 * 0x020345D8); the run itself starts one function earlier at 0x02034520
 * (VMAN_GetBankSetSize, module prefix only, unanchored). The panic block
 * 0x020346EC..0x0203499C belongs here by module/callee family (it is the screen
 * VMAN_* and the assert path share); gf_overlay.c's own anchor resumes exactly
 * at 0x0203499C.
 *
 * symbols:
 *   GFL_HEAP_Alloc              0x02030734  arm
 *   GFL_HEAP_Free              0x020307B0  arm
 *   MIi_CpuClear32             0x02082A7C  arm
 *   AREAMAN_Create             0x02033C00  arm
 *   AREAMAN_Delete             0x02033C9C  arm
 *   AREAMAN_Alloc              0x02033CA8  arm
 *   AREAMAN_Free               0x0203422C  arm
 *   GX_ResetBankForBG          0x020808F4  arm
 *   GX_SetBankForBG              0x0207FDCC  arm
 *   GX_SetGraphicsMode         0x0207D4B0  arm
 *   GXx_SetMasterBrightness_   0x0207D534  arm
 *   TEXTPRINT_Init             0x0204E130  arm
 *   BMP_Create                 0x02043678  arm
 *   BMP_Clear                  0x02043B5C  arm
 *   TEXTPRINT_PrintText        0x0204E328  arm
 *   G2_GetBG0ScrPtr            0x0207DF60  arm
 *   BMP_GetPixels              0x020437D4  arm
 *   DC_FlushRange              0x020862F0  arm
 *   GX_LoadBG0Char            0x0207EE68  arm
 *   OS_Terminate               0x02088234  arm
 *   _u32_div_f                 0x0209C2B0  arm
 *   vman_File                  0x020A7964  data
 *   _VramBankSizes             0x020A07C8  data
 *   _UnitSizes                 0x020A07A0  data
 *   _PanicHandlers             0x0214699C  data
 *   _DebugConsole              0x021469AC  data
 *   _NewlineStr                0x020A796C  data
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef volatile u16       vu16;
typedef volatile u32       vu32;
typedef signed int         s32;
typedef void (*PanicHookFunc)(void);

struct Bmp;
struct CharBuf;

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

/* ---- vman.c: VRAM bank manager on top of AreaMan ---- */

struct VmanBank {
    struct AreaMan *areaman;    /* +0x00 */
    u16 unit_size;              /* +0x04, bytes per area */
    u16 base;                   /* +0x06, bytes reserved at the start */
};

/* An allocated run: first area and number of areas; all ones when unused. */
struct VmanHandle {
    u32 pos;
    u32 units;
};

struct VramBankSize {
    u32 bank_flag;
    u32 size_kb;
};

struct UnitSizeEntry {
    u32 key;
    u32 unit_size;
};

/* ---- panic handler table, set up by the boot code ---- */

struct PanicHandlers {
    u32 die_func;
    u32 print_func;
    u32 init_func;
    PanicHookFunc fail_hook;
};

#define REG_DISPCNT  (*(vu32 *)0x04000000)
#define REG_BG0CNT   (*(vu16 *)0x04000008)
#define REG_BG0OFS   (*(vu32 *)0x04000010)
#define REG_BLDCNT   (*(vu16 *)0x04000050)
#define REG_IME      (*(vu16 *)0x04000208)
#define REG_POWCNT   (*(vu16 *)0x04000304)
#define BG_PLTT_1    (*(vu16 *)0x05000002)
#define BG_PLTT_2    (*(vu16 *)0x05000004)

extern void *GFL_HEAP_Alloc(u32 heap_id, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern void MIi_CpuClear32(u32 v, void *dst, u32 n);

struct AreaMan;
struct AreaMan *AREAMAN_Create(u32 area_count, u16 heap_id);
u32 AREAMAN_Delete(void *areaman);
s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len);
void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len);

extern int GX_ResetBankForBG(void);
extern void GX_SetBankForBG(u32 enable);
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void TEXTPRINT_Init(u32 fontId);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heapId);
extern void BMP_Clear(struct CharBuf *buf, u8 fillValue);
extern void TEXTPRINT_PrintText(const char *text, struct DebugConsole *console);
extern u16 *G2_GetBG0ScrPtr(void);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void DC_FlushRange(void *addr, u32 size);
extern void GX_LoadBG0Char(const void *src, u32 offset, u32 size);
extern void OS_Terminate(void);

u32 VMAN_GetBankSetSize(u32 bank_flags);
struct VmanBank *VMAN_Create(u16 heap_id, u32 mode, u32 bank_flags, u32 base, u32 mode_arg);
void VMAN_Delete(struct VmanBank *bank);
u32 VMAN_GetUnitSize(u32 key);
void VMAN_InvalidateHandle(struct VmanHandle *handle);
int VMAN_IsHandleInvalid(struct VmanHandle *handle);
int VMAN_Alloc(struct VmanBank *bank, u32 size, struct VmanHandle *out);
void VMAN_Free(struct VmanBank *bank, struct VmanHandle *handle);
u32 VMAN_GetOffset(struct VmanBank *bank, u32 *units_ptr);
void SAVEDATA_SetPanicHandlers(u32 initFunc, u32 printFunc, u32 dieFunc);
void SAVEDATA_SetFailHook(u32 failHook);
void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr);
void SAVEDATA_PanicFailPrintf(const char *file, u32 line, const char *fmt, ...);
void GF_OVERLAY_PanicInit(void);
void GF_OVERLAY_PanicPrint(char *text);
void GF_OVERLAY_PanicDie(void);
void GF_OVERLAY_RegisterPanicHandlers(void);

extern const struct VramBankSize _VramBankSizes[9];
extern char vman_File[];
extern const struct UnitSizeEntry _UnitSizes[5];
extern struct PanicHandlers _PanicHandlers;
extern struct DebugConsole _DebugConsole;
extern const char _NewlineStr[];

/*
 * VMAN_GetBankSetSize: sum the sizes of the nine VRAM banks whose flag bit is
 * set in `bank_flags`, scaled from kilobytes to bytes (`<< 0xa`).
 */
u32 VMAN_GetBankSetSize(u32 bank_flags)
{
    u32 i;
    u32 sum = 0;

    for (i = 0; i < 9; i++) {
        if (bank_flags & _VramBankSizes[i].bank_flag) {
            sum += _VramBankSizes[i].size_kb;
        }
    }
    return sum << 0xa;
}


/*
 * VMAN_Create: allocate a VRAM bank record and carve its area map: the bank
 * set's size less the base, divided by the unit size (0x20, or the size from
 * VMAN_GetUnitSize(mode_arg) when mode is 1).  The image stores the unit size
 * into the record in each arm and the divide re-reads the field (`strh` then
 * `ldrh r1, [r5, #4]`), so there is no unit-size local.
 */
struct VmanBank *VMAN_Create(u16 heap_id, u32 mode, u32 bank_flags, u32 base, u32 mode_arg)
{
    struct VmanBank *bank;
    u32 size;

    bank = GFL_HEAP_Alloc(heap_id, 8, 0, vman_File, 0x7a);
    size = VMAN_GetBankSetSize(bank_flags) - base;
    if (mode == 1)
        bank->unit_size = VMAN_GetUnitSize(mode_arg);
    else
        bank->unit_size = 0x20;
    bank->areaman = AREAMAN_Create(size / bank->unit_size, heap_id);
    bank->base = base;
    return bank;
}


/*
 * VMAN_Delete: delete the bank's area manager, then the bank record.
 */
void VMAN_Delete(struct VmanBank *bank)
{
    AREAMAN_Delete(bank->areaman);
    GFL_HEAP_Free(bank);
}


/*
 * VMAN_GetUnitSize: five-entry linear search over _UnitSizes for `key`,
 * returning the unit size of the matching entry or a default of 0x20.
 */
u32 VMAN_GetUnitSize(u32 key)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        if (_UnitSizes[i].key == key) {
            return _UnitSizes[i].unit_size;
        }
    }
    return 0x20;
}


/*
 * VMAN_InvalidateHandle and VMAN_IsHandleInvalid: a handle is invalid when
 * both of its words are 0xFFFFFFFF.
 */
void VMAN_InvalidateHandle(struct VmanHandle *handle)
{
    handle->pos = 0xFFFFFFFFu;
    handle->units = 0xFFFFFFFFu;
}


int VMAN_IsHandleInvalid(struct VmanHandle *handle)
{
    return handle->pos == 0xFFFFFFFFu && handle->units == 0xFFFFFFFFu;
}


/*
 * VMAN_Alloc: round `size` bytes up to whole units, take that many areas
 * from the bank's area manager and, on success, return the first area and
 * the area count in `out`.  Returns 1 on success, 0 when no run was free.
 */
int VMAN_Alloc(struct VmanBank *bank, u32 size, struct VmanHandle *out)
{
    u16 unit_size = bank->unit_size;
    u32 units = size / unit_size;
    u32 pos;

    if (size % unit_size != 0) {
        units++;
    }
    pos = AREAMAN_Alloc(bank->areaman, units);
    if (pos != (u32)-1) {
        out->pos = pos;
        out->units = units;
        return 1;
    }
    return 0;
}


/*
 * VMAN_Free: hand a handle's run back to the bank's area manager and then
 * invalidate the handle in place.  The handle's two words are the argument
 * pair, which is the `ldm r4, {r1, r2}`: one aggregate read of the handle.
 * The handle is copied into a callee-saved register because it is needed
 * again afterwards for VMAN_InvalidateHandle; the bank load is consumed by
 * the first call.
 */
void VMAN_Free(struct VmanBank *bank, struct VmanHandle *handle)
{
    AREAMAN_Free(bank->areaman, handle->pos, handle->units);
    VMAN_InvalidateHandle(handle);
}


/*
 * VMAN_GetOffset: byte offset of the area numbered *units_ptr:
 * *units_ptr * unit_size + base.
 */
u32 VMAN_GetOffset(struct VmanBank *bank, u32 *units_ptr)
{
    return *units_ptr * bank->unit_size + bank->base;
}

/*
 * Registers the three panic handlers in _PanicHandlers.  Only offsets 0, 4
 * and 8 are written; the fail hook at +0xc is set by the next function.
 */
void SAVEDATA_SetPanicHandlers(u32 initFunc, u32 printFunc, u32 dieFunc)
{
    _PanicHandlers.init_func = initFunc;
    _PanicHandlers.print_func = printFunc;
    _PanicHandlers.die_func = dieFunc;
}


/*
 * Sets the fail hook that the assert functions below call.
 */
void SAVEDATA_SetFailHook(u32 failHook)
{
    _PanicHandlers.fail_hook = (PanicHookFunc)failHook;
}


/*
 * The assert failure trampoline all `bl 0x2034714` sites reach: the callers
 * pass file name, line and expression string, in that order.  If a fail hook
 * is registered, call it.  This is the forwarding-call idiom read in
 * reverse (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md):
 * the call is `hook()`, zero C-visible arguments, and r1/r2 survive into the
 * hook only because nothing here touches them.  Writing the call as
 * `hook(line, expr)` forces two `mov`s that are not in the original.  The
 * parameters are declared to keep the prototype honest for callers and are
 * otherwise dead in the body.
 */
void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr)
{
    PanicHookFunc failHook = _PanicHandlers.fail_hook;

    if (failHook) {
        failHook();
    }
}


/*
 * The printf-shaped sibling of the assert trampoline: byte for byte the same
 * body, dispatching the hook through `blx` so a Thumb handler works, wrapped
 * in a variadic frame.  The whole difference is the trailing `...`: a
 * variadic function homes all four argument registers (leading
 * `push {r0, r1, r2, r3}`, see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) and
 * its epilogue becomes `pop {r3, lr}` / `add sp, sp, #0x10` / `bx lr`.  No
 * `va_start` appears because this function never reads the variadic tail;
 * the registered hook does.  As above, calling the hook with arguments would
 * add `mov`s the original does not have.
 */
void SAVEDATA_PanicFailPrintf(const char *file, u32 line, const char *fmt, ...)
{
    PanicHookFunc failHook = _PanicHandlers.fail_hook;

    if (failHook) {
        failHook();
    }
}

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
 *   python tools/match.py one --src src/matched/GF_OVERLAY_PanicInit.c \
 *       --func GF_OVERLAY_PanicInit --addr 0x02034768 --cc 1.1p1 --arm
 */
void GF_OVERLAY_PanicInit(void)
{
    u16 savedIme;
    void *charBuf;

    savedIme = REG_IME;
    REG_IME = 0;

    REG_DISPCNT = REG_DISPCNT & ~0x1f00;
    GX_ResetBankForBG();
    GX_SetBankForBG(1);

    REG_POWCNT = REG_POWCNT & ~0x8000;
    GX_SetGraphicsMode(1, 0, 0);

    REG_BLDCNT = 0;
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006c, 0);

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
void GF_OVERLAY_PanicPrint(char *text)
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
 * The third of the three default assert handlers GF_OVERLAY_RegisterPanicHandlers registers:
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
 *   python tools/match.py one --src src/matched/GF_OVERLAY_PanicDie.c \
 *       --func GF_OVERLAY_PanicDie --addr 0x02034900 --cc 1.1p1 --arm
 */
void GF_OVERLAY_PanicDie(void)
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
    GX_LoadBG0Char(charData, 0, 0x2000);
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
 *   python tools/match.py one --src src/pending/GF_OVERLAY_RegisterPanicHandlers.c \
 *       --func GF_OVERLAY_RegisterPanicHandlers --addr 0x02034978 --cc 1.1p1 --arm
 */
void GF_OVERLAY_RegisterPanicHandlers(void)
{
    SAVEDATA_SetPanicHandlers((u32)GF_OVERLAY_PanicInit, (u32)GF_OVERLAY_PanicPrint, (u32)GF_OVERLAY_PanicDie);
}
