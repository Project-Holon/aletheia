/*
 * file:     gf_overlay_p01.c
 * unit:     yes
 * function: func_020348A4, func_02034900, func_02034978, func_0203499C, func_02034A3C, func_02034A5C, func_02034AC4, func_02034BB0, sub_02034CBC, sub_02034D08, func_02034D60, func_02034DC4
 * address:  0x020348A4
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
 *   g_021469AC    0x021469AC  data
 *   str_020A796C  0x020A796C  data
 *   func_0204E328 0x0204E328  arm
 *   G2_GetBG0ScrPtr   0x0207DF60  arm
 *   func_020437D4     0x020437D4  arm
 *   DC_FlushRange     0x020862F0  arm
 *   GXS_LoadBG0Char   0x0207EE68  arm
 *   OS_Terminate      0x02088234  arm
 *   unk_021469AC      0x021469AC  data
 *   func_02034768  0x02034768  arm
 *   func_02034900  0x02034900  arm
 *   func_02030734   0x02030734  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   unk_021469B8    0x021469B8  data
 *   s_FileName      0x020A7970  data
 *   func_020792B8  0x020792B8  arm
 *   func_02034D60  0x02034D60  arm
 *   func_02034CBC  0x02034CBC  arm
 *   func_02034D08  0x02034D08  arm
 *   sub_02034A3C   0x02034A3C  arm
 *   sub_02034714         0x02034714  arm
 *   FS_SetDefaultDMA     0x0207AC64  arm
 *   FS_LoadOverlay       0x02079264  arm
 *   s_Expr0              0x020A7980  data
 *   func_02034DC4  0x02034DC4  arm
 *   FS_LoadOverlayInfo           0x02078D34  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 */
struct Bmp;
struct Obj02034A3C;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int    s32;

struct Registration {
    s32 handle;
    s32 state;
};

struct AreaMan {
    u8 n0;
    u8 n1;
    u8 n2;
    u8 pad03;
    struct Registration *t0;
    struct Registration *t1;
    struct Registration *t2;
};

struct Obj02034A3C {
    u32 unk00;
    u32 unk04;
};

struct AreaTables {
    u32   unk0;
    void *t0;
    void *t1;
    void *t2;
};

struct AreaCounts {
    u8 n0;
    u8 n1;
    u8 n2;
};

struct OverlayInfo {
    u32 id;
    u32 ram_address;
    u32 ram_size;
    u32 bss_size;
    u32 sinit_init;
    u32 sinit_init_end;
    u32 file_id;
    u32 compressed;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern void func_0204E328(const char *s, const char *d);
extern u16 *G2_GetBG0ScrPtr(void);
extern void *func_020437D4(const struct Bmp *bmp);
extern void DC_FlushRange(void *addr, u32 size);
extern void GXS_LoadBG0Char(const void *src, u32 offset, u32 size);
extern void OS_Terminate(void);
extern void func_02034768(void);
extern void func_02034900(void);
extern void sub_020346EC(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MIi_CpuClear32(u32 data, void *dest, u32 size);
extern int func_020792B8(u32 a, u32 b);
extern void *func_02034CBC(int i);
extern int func_02034D60(u32 id);
extern u8 func_02034D08(int i);
extern void sub_02034A3C(struct Obj02034A3C *p);
extern void sub_02034714(const char *file, u32 line, const char *expr);
extern int FS_SetDefaultDMA(int dma);
extern int FS_LoadOverlay(int target, s32 handle);
extern int func_02034DC4(u32 id, u32 *start, u32 *end);
void sub_02034A5C(s32 handle);
int sub_02034AC4(s32 handle);
int sub_02034BB0(s32 handle);
void *sub_02034CBC(int i);
u8 sub_02034D08(int i);
extern int FS_LoadOverlayInfo(struct OverlayInfo *info, u32 target, u32 id);
void func_020348A4(char *s);
void sub_02034900(void);
void sub_02034978(void);
void sub_0203499C(u32 heap, int n0, int n1, int n2);
int sub_02034D60(u32 id);
int sub_02034DC4(u32 id, u32 *start, u32 *end);
extern char g_021469AC[];
extern const char str_020A796C[];
extern void *unk_021469AC;
extern struct AreaMan *unk_021469B8;
extern const char s_FileName[];
extern const char s_Expr0[];
extern const unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];







/*
 *           --suggest-split offers nothing (single function, both
 *           unresolved sites' only witnesses are inside this range).
 *           witness outside 020348A4..02034900; both of this site's calls to
 *           func_0204E328 are inside this function. Every concrete byte of the
 *           body reproduces.
 */
void func_020348A4(char *s)
{
    int f;

    func_0204E328(s, g_021469AC);
    f = 0;
    while (*s != 0) {
        if (*s++ == '\n') {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        func_0204E328(str_020A796C, g_021469AC);
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
    u16 *p;
    int j;
    int i;
    int n;
    void *src;

    p = G2_GetBG0ScrPtr();

    n = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 0x20; j++) {
            p[j] = n;
            n++;
        }
        p += 0x20;
    }

    src = func_020437D4(unk_021469AC);
    DC_FlushRange(src, 0x2000);
    GXS_LoadBG0Char(src, 0, 0x2000);
    OS_Terminate();
}







/*
 * The default-handler registration trampoline: tail-calls sub_020346EC
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
    sub_020346EC((u32)func_02034768, (u32)func_020348A4, (u32)func_02034900);
}







/*
 * gf_overlay.c's constructor: allocate the singleton sub_02034CBC and
 * sub_02034D08 read, one 0x10-byte header followed by the three
 * registration tables laid end to end, zero it, then record the three table
 * lengths at +0/+1/+2 and the three table bases at +4/+8/+0xc.
 *
 * Every store to the singleton is preceded by a fresh `ldr r0, [r7]` because
 * the object being written is reached through the global pointer itself: the
 * compiler cannot prove `p->t0 = ...` does not land on `unk_021469B8`, so it
 * reloads the pointer before each store.  The allocation size is spelled out
 * twice rather than kept in a local, which is why only the `<< 3` is common
 * subexpression eliminated and the `+ 0x10` is recomputed for the clear.
 *
 * The file string is "gf_overlay.c" and the debug line is 108.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203499C.c \
 *       --func sub_0203499C --addr 0x0203499C --cc 1.1p1 --arm
 */
void sub_0203499C(u32 heap, int n0, int n1, int n2)
{
    struct AreaMan *p;
    int count;

    count = n0 + n1 + n2;

    p = func_02030734(heap, count * sizeof(struct Registration) + sizeof(struct AreaMan), 0,
                      s_FileName, 108);
    unk_021469B8 = p;
    MIi_CpuClear32(0, p, count * sizeof(struct Registration) + sizeof(struct AreaMan));

    unk_021469B8->n0 = n0;
    unk_021469B8->n1 = n1;
    unk_021469B8->n2 = n2;
    unk_021469B8->t0 = (struct Registration *)(unk_021469B8 + 1);
    unk_021469B8->t1 = unk_021469B8->t0 + n0;
    unk_021469B8->t2 = unk_021469B8->t1 + n1;
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
 *   python tools/match.py one --src src/matched/sub_02034A3C.c \
 *       --func sub_02034A3C --addr 0x02034A3C --cc 1.1p1 --arm
 */
void sub_02034A3C(struct Obj02034A3C *p)
{
    func_020792B8(0, p->unk00);
    p->unk04 = 0;
}



/*
 * Release the registration a handle owns.  -1 is the "no handle" value and
 * returns at once; otherwise the handle is resolved to its area index
 * (func_02034D60), which selects the eight-byte registration table
 * (func_02034CBC) and its live length (func_02034D08), and the first
 * entry whose state word at +4 is 1 and whose handle at +0 is the one asked
 * for is handed to sub_02034A3C.  At most one entry matches, so the scan
 * returns rather than breaking.
 *
 * The second field load is spelled off the table base with the scaled index
 * (`ldreq r1, [r5, r3, lsl #3]`) rather than off the entry pointer already
 * in r2: writing both halves of the condition against the same `&table[i]`
 * local costs a `ldr r1, [r2]` instead and is a byte difference.
 *
 * The PC24 at +0x50 (sub_02034A3C) has no `label` witness: the `bl` at
 * 0x02034AAC inside this function is 0x02034A3C's only reference anywhere
 * in the image.  It resolves on class `matched` now that
 * src/matched/sub_02034A3C.c is EXACT, which in turn waited on
 * src/matched/func_020792B8.c and src/matched/unit_02079164.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034A5C.c \
 *       --func sub_02034A5C --addr 0x02034A5C --cc 1.1p1 --arm
 */
void sub_02034A5C(s32 handle)
{
    s32 area;
    struct Registration *table;
    s32 count;
    s32 i;

    if (handle == -1) {
        return;
    }

    area = func_02034D60(handle);
    table = func_02034CBC(area);
    count = func_02034D08(area);

    for (i = 0; i < count; i++) {
        if (table[i].state == 1 && handle == table[i].handle) {
            sub_02034A3C((struct Obj02034A3C *)(&table[i]));
            return;
        }
    }
}



int sub_02034AC4(s32 handle)
{
    int which;
    int oldDMA = -1;
    struct Registration *table;
    int count;
    int i;
    int success;
    int ret;

    if (handle == oldDMA) {
        return 1;
    }

    if (sub_02034BB0(handle) == 0) {
        return 0;
    }

    which = func_02034D60(handle);
    table = func_02034CBC(which);
    count = func_02034D08(which);

    for (i = 0; i < count; i++) {
        struct Registration *entry = &table[i];
        if (entry->state == 0) {
            entry->state = 1;
            entry->handle = handle;
            break;
        }
    }

    if (i >= count) {
        sub_02034714(s_FileName, 267, s_Expr0);
        return 0;
    }

    which--;
    if ((u32)which <= 1) {
        oldDMA = FS_SetDefaultDMA(-1);
    }

    success = FS_LoadOverlay(0, handle);

    if ((u32)which <= 1) {
        FS_SetDefaultDMA(oldDMA);
    }

    ret = 0;
    if (success != 0) {
        ret = 1;
    }
    return ret;
}



/*
 * The admission test sub_02034AC4 runs before it claims a slot: an overlay
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
 *   python tools/match.py one --src src/matched/sub_02034BB0.c \
 *       --func sub_02034BB0 --addr 0x02034BB0 --cc 1.1p1 --arm
 */
int sub_02034BB0(s32 handle)
{
    u32 start;
    u32 end;
    u32 other_start;
    u32 other_end;
    int which;
    struct Registration *table;
    int count;
    int i;

    if (func_02034DC4(handle, &start, &end) == 0) {
        return 0;
    }

    which = func_02034D60(handle);
    table = func_02034CBC(which);
    count = func_02034D08(which);

    for (i = 0; i < count; i++) {
        if (table[i].state == 1) {
            if (func_02034DC4(table[i].handle, &other_start, &other_end) == 1) {
                if ((start >= other_start && start < other_end) ||
                    (end > other_start && end <= other_end) ||
                    (start <= other_start && end >= other_end)) {
                    sub_02034714(s_FileName, 330, s_Expr0);
                    return 0;
                }
            }
        }
    }
    return 1;
}


/*
 * Selects one of three registration tables out of the areaman singleton by
 * a small index.  The singleton holds the three table pointers at +4, +8
 * and +0xc; an out-of-range index yields the same table as index 0, which
 * is why the compiler cross-jumps the default return onto case 0's block
 * and the `cmp r0, #0` at the top branches to the tail rather than to a
 * block of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034CBC.c \
 *       --func sub_02034CBC --addr 0x02034CBC --cc 1.1p1 --arm
 */
void *sub_02034CBC(int i)
{
    switch (i) {
    default:
    case 0:
        return unk_021469B8->t0;
    case 1:
        return unk_021469B8->t1;
    case 2:
        return unk_021469B8->t2;
    }
}


/*
 * The live-length companion of sub_02034CBC: the same three-way index, but
 * reading the three `u8` counts packed at the head of the areaman singleton
 * rather than the table pointers at +4/+8/+0xc.  Here the default is its own
 * arm returning 0, so the `cmp r0, #0` block is distinct and the dispatch
 * chain ends in an explicit `b` to the zero tail instead of cross-jumping.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034D08.c \
 *       --func sub_02034D08 --addr 0x02034D08 --cc 1.1p1 --arm
 */
u8 sub_02034D08(int i)
{
    switch (i) {
    case 0:
        return unk_021469B8->n0;
    case 1:
        return unk_021469B8->n1;
    case 2:
        return unk_021469B8->n2;
    }
    return 0;
}



/*
 * Maps an overlay id onto the areaman table index that owns it: the
 * overlay header's ram_address (+4) inside 0x01000000..0x02000000 is
 * table 1, inside the arm9_autoload1_main_twl window (its base up to
 * base + 0x4000) is table 2, anything else is 0.  The two range guards
 * are sequential, so each `hs` arm carries its own epilogue.
 *
 * Shape notes:
 *  - `id = info.ram_address;` reuses the parameter; a fresh local puts
 *    the load in r1 and shifts every compare by a register.
 *  - The window base is the linker region symbol cast to an integer.  The
 *    image pools 0x02FE0000 in r1 and derives the bound with
 *    `add r0, r1, #0x4000`.  A literal base (any spelling) colours base
 *    r0 / bound r1 (5 out); the symbol kept as a pointer gives the right
 *    registers but folds base + 0x4000 into a second relocated pool word
 *    (104 bytes).  Only the integer cast keeps both the add and the
 *    colouring (u32 and unsigned long both EXACT).  Same region symbol as
 *    src/matched/func_0200520C.c and src/matched/sub_02030534.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034D60.c \
 *       --func sub_02034D60 --addr 0x02034D60 --cc 1.1p1 --arm
 */
int sub_02034D60(u32 id)
{
    struct OverlayInfo info;
    u32 lo;

    FS_LoadOverlayInfo(&info, 0, id);

    id = info.ram_address;
    if (id <= 0x02000000 && id >= 0x01000000) {
        return 1;
    }
    lo = (u32)SDK_AUTOLOAD_MAIN_TWL_START;
    if (id <= lo + 0x4000 && id >= lo) {
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
 *   python tools/match.py one --src src/matched/sub_02034DC4.c \
 *       --func sub_02034DC4 --addr 0x02034DC4 --cc 1.1p1 --arm
 */
int sub_02034DC4(u32 id, u32 *start, u32 *end)
{
    struct OverlayInfo info;
    u32 addr;

    if (FS_LoadOverlayInfo(&info, 0, id) == 0) {
        return 0;
    }

    addr = info.ram_address;
    *start = addr;
    *end = addr + (info.ram_size + info.bss_size);
    return 1;
}
