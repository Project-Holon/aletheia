/*
 * function: disp
 * address:  0x021BE844
 * packet:   pkt_ov016_021BD8D8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   C_KEY                            0x021DA0F8  data
 *   DWCi_CELLlSetEffect              0x021D4FF4  arm
 *   DWCi_CELLlSetPosition            0x021D5118  arm
 *   DWCi_FNTlDisp                    0x021D5F28  arm
 *   FX_ModS32                        0x0207C994  arm
 *   MemKb                            0x021DE55C  data
 *   keyboard_rodata                  0x021DA098  data
 *   keyboard_str_20914               0x021DA0E8  data
 *   keyboard_str_20916               0x021DA0F0  data
 *   keyboard_str_20918               0x021DA0E0  data
 *
 * Blocker: DIFF, 4 bytes short.  The prologue's frame is 0x20 here against the
 * image's 0x18 because the front end spills TWO extra frame words (sp+8, sp+0xc,
 * each staging a single initialiser byte) on top of the two the image also has
 * (sp+0 prio, sp+4 ix).  With the arrays pushed down to 0x10 the three 5-byte
 * buffers land at 0x10/0x15/0x1a instead of 0x8/0xd/0x12.  Measured: all 36
 * declaration-order x assignment-order permutations of the three
 * `*(KB_N5 *)X = keyboard_str_NNNNN` copies; declaration order is inert, assignment
 * order is not, and the best (N_BTN,N_SKEY,N_KEY) gives 644 bytes / frame 0x1c /
 * 382 differing bytes.  A rolled `for (k=0;k<5;k++) N_X[k]=p[k];` gives the image's
 * 0x18 frame but rolls the copies (600 bytes).  Byte-wise spellings via a
 * `const unsigned char *p` and via `keyboard_str_NNNNN.v[i]` compile to the same
 * 652/0x20.  The frame can only reach 0x18 by removing a spill, which this
 * front end will not do for the unrolled three-copy sequence.
 * Notes in docs/notes/pkt_ov016_021BD8D8.c.txt (permuter seed 9803 flat).
 * Wave8: moving `ix = line * 12;` between the N_KEY and N_SKEY copies is inert
 * (652 B / frame 0x20, 465 concrete). Declaring the three locals as initialised
 * `KB_N5 N_KEY = keyboard_str_20914;` is rejected by dsi/1.1p1 (CCERR, abort).
 * No source lever found that removes the early N_SKEY byte spill.
 *
 * Wave8b re-sweep, all measured at dsi/1.1p1 -O4,p c99/arm: 36 declaration x
 * assignment permutations, byte-element copies (`N_X[k]=s.v[k]`, all six wrap
 * orders incl. 4-first), copies through a `const unsigned char *p`, a comma
 * declaration, a single 15-byte buffer, a `static inline` copy5 helper over
 * `u8*` and over `KB_N5*`, and `KB_N5` struct locals all give 652 B / frame
 * 0x20. The two sp+8/sp+0xc word spills stage exactly str2[4] and str3[0],
 * i.e. a register-allocation shortfall in the batch of fifteen byte loads; the
 * image interleaves the fifteen loads/stores so no byte ever needs a slot.
 * `unsigned char N_X[5] = {0};` for all three is the only spelling that reaches
 * frame 0x18, but it keeps fifteen extra `strb r6` zero stores (704 B), which
 * the original does not have. No source-only lever removes the spills.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(keyboard.o), symbol disp (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov016_func_021BE844.c \
 *       --func disp --addr 0x021BE844 --region ov016 --cc 1.1p1 --arm
 */
typedef _Bool bool;

/* keyboard.o was built with plain char unsigned: every DWARF `char` below is
   written `unsigned char` (ldrb loads of KEY_OUT/SKEY_OUT/BTN_OUT, 0x80 stored
   into input with mov, not mvn). */

typedef struct tagCOORD { unsigned short x, y; } COORD;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;
typedef struct tagAREA { unsigned short l, t, w, h; } AREA;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagMEMKB {
    void          *canv[3][4];        /* 0x000 */
    GXOamAttr     *key[47];           /* 0x030 */
    GXOamAttr     *skey[4];           /* 0x0EC */
    void          *button[2];         /* 0x0FC */
    void          *cellCanv[4];       /* 0x104 */
    void          *cellFocus;         /* 0x114 */
    void          *task;              /* 0x118 */
    unsigned char  input;             /* 0x11C */
    unsigned char  page;              /* 0x11D */
    signed char    push;              /* 0x11E */
    signed char    touchLast;         /* 0x11F */
    signed char    focusLast;         /* 0x120 */
    signed char    focus;             /* 0x121 */
    unsigned char  repeat;            /* 0x122 */
    bool           eraseFlag;         /* 0x123 */
    bool           inputFlag;         /* 0x124 */
    bool           sound;             /* 0x125 */
} MEMKB;

/* keyboard.o .bss at 0x021DE55C */
extern MEMKB *MemKb;

/* keyboard.o .rodata at 0x021DA098, members at their vendor offsets */
typedef struct {
    unsigned char  CL_KEY[2];         /* 0x00 */
    unsigned char  CL_BTN[2];         /* 0x02 */
    unsigned char  CN_BTN[2];         /* 0x04 */
    unsigned char  BTN_OUT[3];       /* 0x06 */
    unsigned char  CN_SKEY[4];        /* 0x09 */
    COORD          S_CANV;            /* 0x0E */
    COORD          S_BTN;             /* 0x12 */
    COORD          S_KEY;             /* 0x16 */
    unsigned char  SKEY_OUT[5];       /* 0x1A */
    COORD          C_BTN[2];          /* 0x20 */
    COORD          C_SKEY[4];         /* 0x28 */
    COORD          S_SKEY[4];         /* 0x38 */
} KEYBOARD_RODATA;
extern const KEYBOARD_RODATA keyboard_rodata;

/* keyboard.o .data at 0x021DAE68, members at their vendor offsets */
typedef struct {
    unsigned char  *KEY_OUT[3];      /* 0x00 */
    unsigned short *KEY_CHR[3];       /* 0x0C */
    int             SKEY_TOUCH_SND[4];/* 0x18 */
} KEYBOARD_DATA;
extern KEYBOARD_DATA keyboard_data;

extern RECT DWCi_R_SCR;

/* keyboard.o single-symbol .rodata sections */
extern const COORD C_KEY[47];
extern const COORD C_FOCUS[53];
extern const signed char MOVE_TBL[53][4];

extern void DWCi_TSKlChangeFunc(void *task, void (*func)(void *));
extern void DWCi_TSKlDelete(int kind, void *task);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void *DWCi_CELLlForm(int lcd, int num, bool head);
extern void DWCi_CELLlDelete(void *cell);
extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void DWCi_Coord2Rect(COORD *coord, COORD *size, RECT *rect);
extern void *DWCi_FNTlFormEx(int lcd, int width, int height, bool head, int *obj, int font);
extern void DWCi_FNTlDelete(void *canvas);
extern void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern void DWCi_SNDlPlay(int no);
extern bool DWCi_IPTlCheckRelease(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_TPlCheck(RECT *r);
extern bool DWCi_TPlCheckRelease(RECT *r);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern long FX_ModS32(long a, long b);

static void changeColor(int idx, bool push);
static void changePage(int page);
static void disp(int page, int line, int y);
static void dispFocus(void);
static void exchangeBack(int idx);
static void key(void);
static void moveFocus(int dir);
static void pushCaps(void);
static void pushShift(void);
static void taskEnd0(void *task);
static void taskEnd1(void *task);
static void taskEnd2(void *task);
static void taskEnd3(void *task);
static void taskEnd4(void *task);
static void taskEnd5(void *task);
static void taskMain(void *task);
static void taskStart0(void *task);
static void taskStart1(void *task);
static void taskStart2(void *task);
static void taskStart3(void *task);
static void taskStart4(void *task);
static void touch(void);
static void touchRelease(void);
static void touchTriger(void);

static inline void G2_GetOBJPosition(const GXOamAttr *oam, unsigned long *x, unsigned long *y)
{
    *x = (oam->attr01 & 0x01FF0000) >> 16;
    *y = (oam->attr01 & 0x000000FF) >> 0;
}

static inline void G2_SetOBJMode(GXOamAttr *oam, int mode, int cParam)
{
    oam->attr01 = (oam->attr01 & ~0x0C00) | (mode << 10);
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xF000) | (cParam << 12));
}

static inline void G2_SetOBJEffect(GXOamAttr *oam, int effect, int affine)
{
    oam->attr01 = (oam->attr01 & ~(0x0300 | 0x3E000000)) | effect | (affine << 25);
}

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

/* the 5-byte local initialisers of disp, copied by struct assignment */
typedef struct { unsigned char v[5]; } KB_N5;
extern const KB_N5 keyboard_str_20914;
extern const KB_N5 keyboard_str_20916;
extern const KB_N5 keyboard_str_20918;

static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}

static void disp(int page, int line, int y)
{
    unsigned char N_KEY[5];
    unsigned char N_SKEY[5];
    unsigned char N_BTN[5];
    int ix;
    int i;

    *(KB_N5 *)N_KEY = keyboard_str_20914;
    *(KB_N5 *)N_SKEY = keyboard_str_20916;
    *(KB_N5 *)N_BTN = keyboard_str_20918;

    ix = line * 12;
    for (i = 0; i < N_KEY[line]; i++, ix++) {
        G2_SetOBJEffect(MemKb->key[ix], 0, 0);
        G2_SetOBJPosition(MemKb->key[ix], C_KEY[ix].x, y);
    }
    if (line < 4)
        DWCi_FNTlDisp(MemKb->canv[page][line], C_KEY[line * 12].x, y, MemKb->cellCanv[line], 2);
    ix = FX_ModS32(line + 3, 4);
    for (i = 0; i < N_SKEY[line]; i++) {
        G2_SetOBJEffect(MemKb->skey[ix], 0, 0);
        G2_SetOBJPosition(MemKb->skey[ix], keyboard_rodata.C_SKEY[ix].x, y);
    }
    for (i = 0; i < N_BTN[line]; i++) {
        DWCi_CELLlSetEffect(MemKb->button[i], -1, 0, 0);
        DWCi_CELLlSetPosition(MemKb->button[i], -1, keyboard_rodata.C_BTN[i].x, y);
    }
}
