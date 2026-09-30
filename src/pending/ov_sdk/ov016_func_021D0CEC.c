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
 *           pointer local bound to `MemUsb` or to `&MemUsb->task`.  `const`
 *           on the read-only extern (`M * const g`) is not a fix here: it
 *           rewrites the whole function.  Nothing in the shape of the source
 *           decides it, so the residue is the allocator tie between the
 *           `tagMEMUSB *` base vreg and the loaded value; see
 *           docs/idioms/a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md.
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
