/*
 * function: taskBegin4
 * address:  0x021D04BC
 * packet:   pkt_ov016_021D0040
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * w9_nm2:   still 12 B. Tried: x = 176 as the argument expression, a MEMSTEP *m or void *cell local (loaded before or after the constant), the branch sense reversed, the store after the call; the compiler keeps mov, str x, ldr MemStep, ldr cell where the object has mov, ldr MemStep, str x, ldr cell.
 * blocker:  12 bytes: in the else arm the original loads MemStep->cell[4] before it stores x = 176; 1.1p1 stores x first. The loop forms (taskBegin0..3, taskEnd1..3) match. Notes: docs/notes/pkt_ov016_021D0040.c.txt
 *
 * w9_nm: same 12 B as taskEnd0 (the object loads MemStep->cell[4] before storing x = 176); the taskEnd0 spellings do not change it.
 *
 * T6: as taskEnd0 (same 12 B window). Object `ldr r0,[r4,#4] /
 * str r2,[sp,#4] / ldr r0,[r0,#0x10] / sub r1,r2,#0xb1`; this build
 * `str r2,[sp,#4] / ldr r0,[r4,#4] / sub r1,r2,#0xb1 / ldr r0,[r0,#0x10]`.
 * Sweep: 12 concrete diffs at every -O4/-O3/-O2 cell of all nine pins.
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
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(step.o), symbol taskBegin4 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021D04BC.c \
 *       --func taskBegin4 --addr 0x021D04BC --region ov016 --cc 1.1p1 --arm --lang c99
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

static void taskBegin4(void *task)
{
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[4], 0, &x, &y);
    x += 8;
    if (x < 176 || x > 256) {
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
    } else {
        x = 176;
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
        DWCi_TSKlChangeFunc(task, taskBegin5);
    }
}
