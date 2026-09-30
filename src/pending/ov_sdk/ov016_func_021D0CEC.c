/*
 * function: func_021D0CEC
 * address:  0x021D0CEC
 * packet:   pkt_ov016_021D0CEC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  +0094 and +0098, 2 concrete bytes, both the register nibble of
 *           the `MemUsb->task` load and of the compare that tests it.  The
 *           image has `ldr r1, [r0, #0xb90]` / `cmp r1, #0`; every source
 *           shape tried here compiles that same load into the dying base
 *           register, `ldr r0, [r0, #0xb90]` / `cmp r0, #0`.  The other 218
 *           bytes and all 9 relocations reproduce exactly.  28 spellings
 *           measured, none moves it: condition form (bare `if`, `!= 0`,
 *           `== 0` with an empty else, `0 != x`, `!=(void *)0`, ternary in
 *           the condition, ternary as the statement, `&& 1`, `x ? 1 : 0`,
 *           braced and unbraced); member type (`int`, `unsigned int`,
 *           `unsigned long`, `void *`, non-volatile and volatile, reached
 *           through a `volatile M *`); access form (`g->task`,
 *           `*(unsigned long *)&g->task`, `*(void **)&g->task`,
 *           `((volatile unsigned long *)&g->task)[0]`, `(char *)g + 0x1B90`);
 *           local-variable shapes (a second local at function scope, the
 *           block-scope local, and reusing `rs` for the task value); and a
*           pointer local bound to `MemUsb` or to `&MemUsb->task`).
 *
 * The residue is not a source-shape question at all.  In this repo the
 * matched EXACT sources that do emit `ldr r1, [r0, #imm]` / `cmp r1, #0`
 * are the ones whose source reads the base again after the guard, which
 * keeps the base live at the load.  Here the intervening `func_021D7744(0)`
 * call forces the reload of `g_021DE654` at +00A8, so the base has exactly
 * one use and is dead at +0094, and 1.1p1 coalesces it into the load
 * destination.  The lane is closed as unreachable from C at this base
 * lifetime; see
 * docs/idioms/a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md.
 *
 * Later batches, all still 220 bytes / 2 diffs / 9 relocs at +0094,+0098:
 * return type `unsigned char` and `bool`; brace/`else`/`do while (0)`
 * rewrites; base captured in a local and reloaded; 16 member types
 * (`unsigned char *`, `unsigned int`, `int`, `void *`, `void **`, `u8 *`,
 * and the plain and `const` spellings of the load target); casts to
 * `unsigned int`; `!!` and `!=`/`==` negations; and member qualifiers
 * `void * const`, `volatile void * const`, `volatile void * volatile`.
 * `M * const`, `volatile M * const` and nested-struct spellings do not
 * compile under -lang c99 here.  `end` must stay volatile: a non-volatile
 * `end` hoists its load and adds diffs at +00B4,+00B8,+00BC, and a single
 * `const M *` for both reads lets the call CSE the second read (212 bytes,
 * 45 diffs).  Declaring the full DWARF struct (start, stack, wait) does not
 * move the pair either; `volatile` vs plain `task`/`end` in that struct only
 * reproduces the same +0094,+0098 or +0094,+0098,+00B4,+00B8,+00BC pair.
 *
 * The lever is confirmed to exist in this corpus but not reachable here: a
 * scan of the whole `asm` tree for `ldr rN,[rM,#imm]` followed by
 * `cmp rN,#0` with
 * N != M found 13,207 hits outside arm9/main.s, 1,504 with base r0 and
 * destination r1, and every EXACT match among those (func_0203D610,
 * func_020414EC, unit_0201BD28, unit_0201BEB8, func_020221B8,
 * func_02029374, func_0202B2A4, sub_02030FB4, ...) is a case where the
 * source reads the base again after the guard, so the base is live at the
 * load and the value must take a fresh register.  Here the base has exactly
 * one use: the intervening `func_021D7744(0)` call forces the compiler to
 * reload `g_021DE654` at +00A8, so the base is dead at +0094 and 1.1p1
 * coalesces it.  Compiler sweep over every build in the repo (1.1, 1.1p1,
 * 1.2, 1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1, 1.6sp2) reports the same
 * 2-byte residue, so the version is not the discriminator either.
 *
 * lane05 (2026-09-30): the sweep above could not have used the true front end,
 *   because the defining object usbap.o carries stamp
 *   `Metrowerks C/C++ for ARM 4.0.0.1025` (tools/sdkobj.py), which no tree under
 *   tools/mwccarm writes. Re-measured 220/220 with the same +0094/+0098 pair
 *   (`ldr r1,[r0,#0xb90]; cmp r1,#0` vs `ldr r0,[r0,#0xb90]; cmp r0,#0`), all 9
 *   relocations resolved. This is a toolchain wall, not a source-shape one.
 *
 * sdk:      DWCi_USBAPlEnd (libdwcutil.TWL.HYB.a usbap.o)
 *
 * vendor DWARF of usbap.o (Metrowerks 4.0.0.1025):
 *   bool DWCi_USBAPlEnd(void);
 *   variable enum WMErrCode rs            r0      - the only local
 *   declarations enum WMErrCode WM_ReadStatus(struct WMStatus *);
 *                enum WMErrCode WM_Reset(void (*)(void *));
 *                enum WMErrCode WM_End(void (*)(void *));
 *                void DWCi_HEAPlFree_(void **);
 *                extern struct tagMEMUSB *MemUsb;
 *                static void cbWm(void *);
 *   DWCi_HEAPlFree_ is declared `void **` in the DWARF, but the call site
 *   passes `&MemUsb`, i.e. an `M **`, which a `void **` parameter rejects;
 *   the extern here is therefore left unprototyped.  Codegen is unaffected.
 *   struct tagMEMUSB (7072 bytes): +0x0 wmBuf[3840], +0xf00 scanBuf[1024],
 *     +0x1300 ap[16], +0x1370 callback, +0x1374 param, +0x13b8 status
 *     (struct WMStatus), +0x1b88 start, +0x1b90 task (void *), +0x1b94 end,
 *     +0x1b95 stack, +0x1b96 wait.  struct WMStatus's first member is `state`,
 *     read here as a plain halfword (`ldrh`, no mask), so it is declared u16.
 *   enum WMErrCode (values read out of the object's DWARF): SUCCESS 0,
 *     FAILED 1, OPERATING 2, ILLEGAL_STATE 3, WM_DISABLE 4, NO_KEYSET 5,
 *     NO_DATASET 5, INVALID_PARAM 6, NO_CHILD 7, FIFO_ERROR 8, TIMEOUT 9,
 *     SEND_QUEUE_FULL 10, NO_ENTRY 11, OVER_MAX_ENTRY 12,
 *     INVALID_POLLBITMAP 13, NO_DATA 14, SEND_FAILED 15, DCF_TEST 16,
 *     WL_INVALID_PARAM 17, WL_LENGTH_ERR 18, FLASH_ERROR 19, MAX 20.
 *     Every `cmp #2` in the image is therefore WM_ERRCODE_OPERATING.
 *
 * 0x021D0DE0, reached by the two ABS32 sites that pass a callback to WM_Reset
 * and WM_End, is not a data struct: it is `cbWm` itself, the file-static
 * `static void cbWm(void *arg)` (148 bytes, the callback for
 * struct WMStartScanExCallback) that also lives in usbap.o.  It is `func
 * local` in the object's symbol table and [open-sdk] only because no C for it
 * has been matched yet; the site resolves on the `sdk` class from
 * layout/symbols_sdk.json, so it never gated this function.
 *
 * symbols:
 *   func_0208EBE4  0x0208EBE4  arm
 *   func_0208F400  0x0208F400  arm
 *   func_0208F43C  0x0208F43C  arm
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE654     0x021DE654  data
 *   g_021DE654_b   0x021DE654  data
 *   func_021D0DE0  0x021D0DE0  arm  ov016
 */

enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2
};

typedef struct {
    unsigned char pad0[0x13B8];
    unsigned short state;
    unsigned char pad1[0x1B90 - 0x13BA];
    volatile void *task;
    volatile unsigned char end;
} M;

extern enum WMErrCode func_0208EBE4(unsigned short *);
extern enum WMErrCode func_0208F400(void (*)(void *));
extern enum WMErrCode func_0208F43C(void (*)(void *));
extern void func_021D7744();
extern void func_021D6438();
extern M *g_021DE654;
extern M *g_021DE654_b;
extern void func_021D0DE0(void *);

int func_021D0CEC(void)
{
    enum WMErrCode rs;
    g_021DE654->end = 1;
    func_0208EBE4(&g_021DE654->state);
    if (g_021DE654->state != WM_ERRCODE_OPERATING) {
        rs = func_0208F400(func_021D0DE0);
        if (rs != WM_ERRCODE_OPERATING)
            return 0;
        do {
            func_0208EBE4(&g_021DE654->state);
        } while (g_021DE654->state != WM_ERRCODE_OPERATING);
    }
    rs = func_0208F43C(func_021D0DE0);
    if (rs != WM_ERRCODE_OPERATING)
        return 0;
    if (g_021DE654->task != 0)
        func_021D7744(0);
    while (g_021DE654->end != 2)
        ;
    func_021D6438(&g_021DE654_b);
    return 1;
}
