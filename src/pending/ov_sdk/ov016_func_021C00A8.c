/*
 * function: disp
 * address:  0x021C00A8
 * packet:   pkt_ov016_021BF74C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  148 lines: prologue copy scheduling of the three 5-byte initialisers (the keyboard.o disp residue), and @20862/@20864/@20866 have no witness outside this function. Notes: docs/notes/pkt_ov016_021BF74C.c.txt
 *
 * symbols:
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CEINlSetExCell              0x021D5394  arm
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   DWCi_CELLlDelete                 0x021D4F60  arm
 *   DWCi_CELLlForm                   0x021D4E1C  arm
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm
 *   DWCi_CELLlGetPosition            0x021D5250  arm
 *   DWCi_CELLlSetEffect              0x021D4FF4  arm
 *   DWCi_CELLlSetPalette             0x021D5098  arm
 *   DWCi_CELLlSetPosition            0x021D5118  arm
 *   DWCi_CELLlSetPriority            0x021D51F0  arm
 *   DWCi_Coord2Rect                  0x021D600C  arm
 *   DWCi_FNTlDelete                  0x021D5A2C  arm
 *   DWCi_FNTlDisp                    0x021D5F28  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlFormEx                  0x021D5950  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_IPTlCheckRelease            0x021D68A4  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TPlCheck                    0x021D68E4  arm
 *   DWCi_TPlCheckRelease             0x021D6A7C  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   MemKb10                          0x021DE560  data
 *   changeColor                      0x021C0328  arm
 *   disp                             0x021C00A8  arm
 *   dispFocus                        0x021C03F0  arm
 *   exchangeBack                     0x021BFED0  arm
 *   key                              0x021BFF14  arm
 *   keyboard10_rodata                0x021DA35C  data
 *   keyboard10_str_20601             0x021DA460  data
 *   keyboard10_str_20862             0x021DA450  data
 *   keyboard10_str_20864             0x021DA458  data
 *   keyboard10_str_20866             0x021DA448  data
 *   moveFocus                        0x021C0480  arm
 *   taskEnd0                         0x021C0528  arm
 *   taskEnd1                         0x021C0588  arm
 *   taskEnd2                         0x021C05E0  arm
 *   taskEnd3                         0x021C0638  arm
 *   taskEnd4                         0x021C0690  arm
 *   taskEnd5                         0x021C06E8  arm
 *   taskMain                         0x021BF970  arm
 *   taskStart0                       0x021BF74C  arm
 *   taskStart1                       0x021BF7B8  arm
 *   taskStart2                       0x021BF824  arm
 *   taskStart3                       0x021BF890  arm
 *   taskStart4                       0x021BF8FC  arm
 *   touch                            0x021BFCF8  arm
 *   touchRelease                     0x021BFB38  arm
 *   touchTriger                      0x021BF988  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(keyboard10.o), symbol disp (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021C00A8.c \
 *       --func disp --addr 0x021C00A8 --region ov016 --cc 1.1p1 --arm --lang c99
 */
typedef _Bool bool;

/* keyboard10.o was built with plain char unsigned, like keyboard.o: every DWARF
   `char` below is written `unsigned char`. */

typedef struct tagCOORD { unsigned short x, y; } COORD;
typedef struct tagRECT { unsigned short l, t, r, b; } RECT;
typedef struct tagAREA { unsigned short l, t, w, h; } AREA;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagMEMKB10 {
    void          *canv[4];           /* 0x00 */
    GXOamAttr     *key[10];           /* 0x10 */
    GXOamAttr     *skey[2];           /* 0x38 */
    void          *button[2];         /* 0x40 */
    void          *cellCanv[4];       /* 0x48 */
    void          *cellFocus;         /* 0x58 */
    void          *task;              /* 0x5C */
    unsigned char  input;             /* 0x60 */
    signed char    push;              /* 0x61 */
    signed char    touchLast;         /* 0x62 */
    signed char    focus;             /* 0x63 */
    signed char    focusLast;         /* 0x64 */
    unsigned char  repeat;            /* 0x65 */
    bool           eraseFlag;         /* 0x66 */
    bool           inputFlag;         /* 0x67 */
    bool           shiftFlag;         /* 0x68 */
    bool           sound;             /* 0x69 */
} MEMKB10;

/* keyboard10.o .bss at 0x021DE560 */
extern MEMKB10 *MemKb10;

/* keyboard10.o .rodata at 0x021DA35C, members at their vendor offsets */
typedef struct {
    unsigned char  CL_BTN[2];         /* 0x00 */
    unsigned char  CN_SKEY[2];        /* 0x02 */
    unsigned char  CN_BTN[2];         /* 0x04 */
    unsigned char  CL_KEY[2];         /* 0x06 */
    unsigned char  BTN_OUT[3];        /* 0x08 */
    unsigned char  SKEY_OUT[3];       /* 0x0B */
    COORD          S_KEY;             /* 0x0E */
    COORD          S_CANV;            /* 0x12 */
    COORD          S_SKEY;            /* 0x16 */
    COORD          S_BTN;             /* 0x1A */
    COORD          C_SKEY[2];         /* 0x1E */
    COORD          C_BTN[2];          /* 0x26 */
    unsigned char  KEY_OUT[11];       /* 0x2E */
    unsigned short KEY_CHR[13];       /* 0x3A */
    COORD          C_KEY[10];         /* 0x54 */
    COORD          C_FOCUS[14];       /* 0x7C */
    signed char    MOVE_TBL[14][4];   /* 0xB4 */
} KEYBOARD10_RODATA;
extern const KEYBOARD10_RODATA keyboard10_rodata;

/* the local initialisers, the compiler's @NNNNN objects, copied by struct assignment */
typedef struct { unsigned char v[5]; } KB10_N5;
extern const KB10_N5 keyboard10_str_20862;
extern const KB10_N5 keyboard10_str_20864;
extern const KB10_N5 keyboard10_str_20866;
extern const AREA keyboard10_str_20601;

extern RECT DWCi_R_SCR;

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

static void changeColor(int idx, bool push);
static void disp(int line, int y);
static void dispFocus(void);
static void exchangeBack(int idx);
static void key(void);
static void moveFocus(int dir);
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

static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}

static void disp(int line, int y)
{
    unsigned char N_KEY[5];
    unsigned char N_SKEY[5];
    unsigned char N_BTN[5];
    int ix;
    int i;

    *(KB10_N5 *)N_KEY = keyboard10_str_20862;
    *(KB10_N5 *)N_SKEY = keyboard10_str_20864;
    *(KB10_N5 *)N_BTN = keyboard10_str_20866;

    ix = line * 3;
    for (i = 0; i < N_KEY[line]; i++, ix++) {
        G2_SetOBJEffect(MemKb10->key[ix], 0, 0);
        G2_SetOBJPosition(MemKb10->key[ix], keyboard10_rodata.C_KEY[ix].x, y);
    }
    if (line < 4)
        DWCi_FNTlDisp(MemKb10->canv[line], keyboard10_rodata.C_KEY[line * 3].x, y, MemKb10->cellCanv[line], 2);
    for (i = 0; i < N_SKEY[line]; i++) {
        G2_SetOBJEffect(MemKb10->skey[i], 0, 0);
        G2_SetOBJPosition(MemKb10->skey[i], keyboard10_rodata.C_SKEY[i].x, y);
    }
    for (i = 0; i < N_BTN[line]; i++) {
        DWCi_CELLlSetEffect(MemKb10->button[i], -1, 0, 0);
        DWCi_CELLlSetPosition(MemKb10->button[i], -1, keyboard10_rodata.C_BTN[i].x, y);
    }
}
