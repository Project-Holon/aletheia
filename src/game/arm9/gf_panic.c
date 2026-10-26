/*
 * file:     gf_panic.c
 * unit:     yes
 * function: GF_PANIC_SetHandlers, GF_PANIC_SetFailHook, GF_PANIC_Fail, GF_PANIC_FailPrintf, GF_PANIC_Init, GF_PANIC_Print, GF_PANIC_Die, GF_PANIC_RegisterDefaultHandlers
 * address:  0x020346EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vman.c by tools/splitfile.py.
 *
 * symbols:
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
 *   _PanicHandlers             0x0214699C  data
 *   _DebugConsole              0x021469AC  data
 *   _NewlineStr                0x020A796C  data
 */

#include "../types.h"
#include "../sdk_ioreg_reg.h"

typedef void (*PanicHookFunc)(void);

#include "bmp_shared_types.h"

struct CharBuf;

/* ---- panic handler table, set up by the boot code ---- */
struct PanicHandlers {
    u32 die_func;
    u32 print_func;
    u32 init_func;
    PanicHookFunc fail_hook;
};


#define REG_BG0CNT   (*(vu16 *)REG_BG0CNT_ADDR)

#define REG_BG0OFS   (*(vu32 *)REG_BG0OFS_ADDR)


#define REG_IME      (*(vu16 *)REG_IME_ADDR)

#define REG_POWCNT   (*(vu16 *)REG_POWCNT1_ADDR)

#define BG_PLTT_1    (*(vu16 *)0x05000002)

#define BG_PLTT_2    (*(vu16 *)0x05000004)

#include "gx_vramcnt.h"


#include "gx.h"


#include "textprint.h"

typedef short s16_p07;
#include "bmp.h"


#include "textprint.h"

#include "gx_bgcnt.h"


#include "os_cache.h"

#include "gx_load2d.h"

#include "os_terminate_processor.h"

void GF_PANIC_SetHandlers(u32 initFunc, u32 printFunc, u32 dieFunc);

void GF_PANIC_SetFailHook(PanicHookFunc failHook);

void GF_PANIC_Fail(const char *file, u32 line, const char *expr);

void GF_PANIC_FailPrintf(const char *file, u32 line, const char *fmt, ...);

void GF_PANIC_Init(void);

void GF_PANIC_Print(char *text);

void GF_PANIC_Die(void);

void GF_PANIC_RegisterDefaultHandlers(void);

extern struct PanicHandlers _PanicHandlers;

extern TextParam _DebugConsole;

extern const char _NewlineStr[];

/*
 * Registers the three panic handlers in _PanicHandlers.  Only offsets 0, 4
 * and 8 are written; the fail hook at +0xc is set by the next function.
 */
void GF_PANIC_SetHandlers(u32 initFunc, u32 printFunc, u32 dieFunc)
{
    _PanicHandlers.init_func = initFunc;
    _PanicHandlers.print_func = printFunc;
    _PanicHandlers.die_func = dieFunc;
}

/*
 * Sets the fail hook that the assert functions below call.
 */
void GF_PANIC_SetFailHook(PanicHookFunc failHook)
{
    _PanicHandlers.fail_hook = failHook;
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
void GF_PANIC_Fail(const char *file, u32 line, const char *expr)
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
void GF_PANIC_FailPrintf(const char *file, u32 line, const char *fmt, ...)
{
    PanicHookFunc failHook = _PanicHandlers.fail_hook;

    if (failHook) {
        failHook();
    }
}

/*
 * Bring up the panic screen.  The assert path (GF_PANIC_FailPrintf forwards here)
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
 *   python tools/match.py one --src src/matched/GF_PANIC_Init.c \
 *       --func GF_PANIC_Init --addr 0x02034768 --cc 1.1p1 --arm
 */
void GF_PANIC_Init(void)
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
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_ADDR, 0);

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
void GF_PANIC_Print(char *text)
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
 * The third of the three default assert handlers GF_PANIC_RegisterDefaultHandlers registers:
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
 *   python tools/match.py one --src src/matched/GF_PANIC_Die.c \
 *       --func GF_PANIC_Die --addr 0x02034900 --cc 1.1p1 --arm
 */
void GF_PANIC_Die(void)
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
 * The default-handler registration trampoline: tail-calls GF_PANIC_SetHandlers
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
 *   python tools/match.py one --src src/pending/GF_PANIC_RegisterDefaultHandlers.c \
 *       --func GF_PANIC_RegisterDefaultHandlers --addr 0x02034978 --cc 1.1p1 --arm
 */
void GF_PANIC_RegisterDefaultHandlers(void)
{
    GF_PANIC_SetHandlers((uptr)GF_PANIC_Init, (uptr)GF_PANIC_Print, (uptr)GF_PANIC_Die);
}
