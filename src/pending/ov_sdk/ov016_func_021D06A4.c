/*
 * function: taskEnd0
 * address:  0x021D06A4
 * packet:   pkt_ov016_021D0040
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  12 bytes in the else arm's four-instruction scheduler window at +0060.
 *           Original: ldr MemStep / str x / ldr cell / sub idx. 1.1p1: str x /
 *           ldr MemStep / sub idx / ldr cell. The taken arm and every other
 *           instruction match. taskBegin4 (0x021D04BC) carries the identical
 *           window. Notes: docs/notes/pkt_ov016_021D0040.c.txt
 *
 * w5_nm: also tried `x = 152` inside the call argument, the `<= 152` arm
 *           first, an early return from the `> 152` arm, the literal 152 in the
 *           call with the store after it, a clamp then conditional change, and a
 *           block local for the cell (12 to 103 bytes; none better than 12).
 *
 * w6_nm tried: the store as a call argument (assignment and comma), the
 * literal in the call, a threaded end flag, a clamp then recheck: 12 B remain.
 *
 * w9_nm: 12 B: const-qualified MemStep (in the macro cast, the struct member, or cell[]) and a MEMSTEP *const local do not move the cell load above the x = 152 store; block cell local, cell hoisted to the top, early-return arm order: 53 to 90 B.
 *
 * T6: 12 B, first at +0060. Object `ldr r0,[r4,#4] / str r2,[sp,#4] /
 * ldr r0,[r0,#0x10] / sub r1,r2,#0x99`; this build `str r2,[sp,#4] /
 * ldr r0,[r4,#4] / sub r1,r2,#0x99 / ldr r0,[r0,#0x10]`. Only the else arm's
 * four-instruction window schedules differently - the taken arm and every
 * other instruction match. Sweep: 12 concrete diffs at -O4,p/-O4,s/-O4/-O3/
 * -O2 for all nine pins.
 * w8_nm: applied docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md
 *        (const on step_bss, const STEP_BSS, MEMSTEP *const, const MEMSTEP *), plus a
 *        `void *cell`/`MEMSTEP *m` named local, the index as an enum/`0-1`/`~0` local,
 *        a `const int` end value, volatile x, and both `(cell)[4]`/`*(cell+4)` spellings:
 *        every one is 12 concrete bytes (const on step_bss overshoots to 67). No
 *        source shape moves the four-instruction window; scheduler tie.
 * W8: re-ran the loop forms from the hint (`for (i=4;i<5;i++)` in the else arm,
 *     `x = 152` inside the loop, loop over both arms, C_POS[i].y bound) - all
 *     unroll to the same straight-line 12-byte window. `MEMSTEP *const m` /
 *     `MEMSTEP * const MemStep` member / `const MEMSTEP *` / `void *const c`
 *     all stay 12 B; `const` on the struct overshoots. The two-token rewrite
 *     did not move `ldr MemStep` above `str x`.
 *
 * w8x: `MEMSTEP *m`/decl-block `MEMSTEP *m = MemStep;` before/after the store, `volatile MEMSTEP *m`
 *      with a comma-forced load, the literal 152 in the call (store kept), the assignment as the 3rd
 *      argument, a `void *c` cell local, `volatile` on the step_bss MemStep member, and moving
 *      `x = 152;` after the call: every shape is 12 B or
 *      worse (c-local and store-after change the taken arm, 38-53 B). The original's else arm is the
 *      only site in the packet that wants the MemStep load (A) above the `str x` (C); taskEnd1..3 and
 *      taskBegin3's loop arms all want C above A and match. Scheduler tie, not a source lever.
 *
 * U26: the matched siblings in this packet keep the same `x = N;` before the call and match
 * (taskEnd1..3 are loop forms); the single-cell else arm stays on the 12-byte window under a
 * `MEMSTEP *m`/`void *cell` local bound before the store, the assignment as the 3rd argument and
 * a comma statement.  Scheduler tie on the four-instruction window.
 *
 * symbols:
 *   CELL_IDX                         0x021DA914  data
 *   C_POS                            0x021DA932  data
 *   DC_FlushRange                    0x020862F0  arm
 *   DWCi_ARClReadEx                  0x021D4B68  arm
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CEINlSetExCell              0x021D5394  arm
 *   DWCi_CELLlDelete                 0x021D4F60  arm
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm
 *   DWCi_CELLlGetPosition            0x021D5250  arm
 *   DWCi_CELLlSetPalette             0x021D5098  arm
 *   DWCi_CELLlSetPosition            0x021D5118  arm
 *   DWCi_CELLlSetPriority            0x021D51F0  arm
 *   DWCi_Char                        0x021BD170  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_STEPlBegin                  0x021D0040  arm
 *   DWCi_STEPlChange                 0x021D05BC  arm
 *   DWCi_STEPlChangeScr              0x021D0AB0  arm
 *   DWCi_STEPlEnd                    0x021D0580  arm
 *   DWCi_STEPlIsEnd                  0x021D0A84  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   FILE_NAME                        0x021DB950  data
 *   GXS_LoadBG1Scr                   0x0207EABC  arm
 *   PL_CELL                          0x021DA923  data
 *   step_bss                         0x021DE64C  data
 *   taskBegin0                       0x021D013C  arm
 *   taskBegin1                       0x021D021C  arm
 *   taskBegin2                       0x021D02FC  arm
 *   taskBegin3                       0x021D03DC  arm
 *   taskBegin4                       0x021D04BC  arm
 *   taskBegin5                       0x021D0558  arm
 *   taskChange                       0x021D0AFC  arm
 *   taskEnd0                         0x021D06A4  arm
 *   taskEnd1                         0x021D0734  arm
 *   taskEnd2                         0x021D0808  arm
 *   taskEnd3                         0x021D08DC  arm
 *   taskEnd4                         0x021D09B0  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(step.o), symbol taskEnd0 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021D06A4.c \
 *       --func taskEnd0 --addr 0x021D06A4 --region ov016 --cc 1.1p1 --arm --lang c99
 */
typedef _Bool bool;

typedef struct tagCOORD { unsigned short x, y; } COORD;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

/* step.o's work area; no DWARF type reaches it, the layout is from the accesses:
   0x1C bytes allocated, five cells, the running task, the ending flag. */
typedef struct tagMEMSTEP {
    void *cell[5];                    /* 0x00 */
    void *task;                       /* 0x14 */
    bool  end;                        /* 0x18 */
} MEMSTEP;

/* step.o .bss at 0x021DE64C: the two file statics File and MemStep */
typedef struct {
    void    *File;                    /* 0x00 */
    MEMSTEP *MemStep;                 /* 0x04 */
} STEP_BSS;
extern STEP_BSS step_bss;

/* step.o .rodata (the dump prints DWARF dimensions reversed: rows are five bytes) */
extern const unsigned char CELL_IDX[3][5];
extern const unsigned char PL_CELL[3][5];
extern const COORD C_POS[5];
/* step.o .data */
extern char *FILE_NAME[5];

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlDelete(void *cell);
extern void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_TSKlChangeFunc(void *task, void (*func)(void *));
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_SNDlPlay(int no);
extern char *DWCi_Char(char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void DWCi_ARClRelease(void *file);
extern void DC_FlushRange(void *startAddr, unsigned long nBytes);
extern void GXS_LoadBG1Scr(const void *src, unsigned long offset, unsigned long size);

void DWCi_STEPlChangeScr(int step);
static void taskBegin0(void *task);
static void taskBegin1(void *task);
static void taskBegin2(void *task);
static void taskBegin3(void *task);
static void taskBegin4(void *task);
static void taskBegin5(void *task);
static void taskEnd0(void *task);
static void taskEnd1(void *task);
static void taskEnd2(void *task);
static void taskEnd3(void *task);
static void taskEnd4(void *task);
static void taskChange(void *task);

#define File    (step_bss.File)
#define MemStep (step_bss.MemStep)

static void taskEnd0(void *task)
{
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[4], 0, &x, &y);
    x -= 8;
    if (x > 152) {
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
    } else {
        x = 152;
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
        DWCi_TSKlChangeFunc(task, taskEnd1);
    }
}

