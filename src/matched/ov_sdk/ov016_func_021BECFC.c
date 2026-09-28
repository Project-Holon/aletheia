/*
 * function: moveFocus
 * address:  0x021BECFC
 * packet:   pkt_ov016_021BD8D8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   MOVE_TBL                         0x021DA288  data
 *   MemKb                            0x021DE55C  data
 *   dispFocus                        0x021BEC20  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(keyboard.o), symbol moveFocus (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BECFC.c \
 *       --func moveFocus --addr 0x021BECFC --region ov016 --cc 1.1p1 --arm
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

static void moveFocus(int dir)
{
    signed char focus;

    focus = MemKb->focus;
    MemKb->focus = MOVE_TBL[focus][dir];
    if (MemKb->focus == 46 && dir == 3) {
        MemKb->focusLast = focus;
    } else if (MemKb->focus == 51 && (dir == 1 || dir == 3)) {
        MemKb->focusLast = focus;
    } else if (MemKb->focus == 52 && (dir == 1 || dir == 3)) {
        if (focus != 46)
            MemKb->focusLast = focus;
    } else if (MemKb->focus == -1) {
        if (MemKb->focusLast == 35 || MemKb->focusLast == 50)
            MemKb->focus = 35;
        else
            MemKb->focus = 34;
    } else if (MemKb->focus == -2) {
        switch (MemKb->focusLast) {
        case 0:
        case 49:
            MemKb->focus = 49;
            break;
        case 1:
        case 36:
            MemKb->focus = 36;
            break;
        case 3:
        case 38:
            MemKb->focus = 38;
            break;
        case 4:
        case 39:
            MemKb->focus = 39;
            break;
        case 5:
        case 40:
            MemKb->focus = 40;
            break;
        default:
            MemKb->focus = 37;
            break;
        }
    } else if (MemKb->focus == -3) {
        switch (MemKb->focusLast) {
        case 6:
        case 41:
            MemKb->focus = 41;
            break;
        case 7:
        case 42:
            MemKb->focus = 42;
            break;
        case 9:
        case 44:
            MemKb->focus = 44;
            break;
        case 10:
        case 45:
            MemKb->focus = 45;
            break;
        case 11:
        case 34:
        case 35:
        case 50:
            MemKb->focus = 46;
            break;
        default:
            MemKb->focus = 43;
            break;
        }
    } else if (MemKb->focus == -4) {
        switch (MemKb->focusLast) {
        case 0:
        case 49:
            MemKb->focus = 0;
            break;
        case 1:
        case 36:
            MemKb->focus = 1;
            break;
        case 3:
        case 38:
            MemKb->focus = 3;
            break;
        case 4:
        case 39:
            MemKb->focus = 4;
            break;
        case 5:
        case 40:
            MemKb->focus = 5;
            break;
        default:
            MemKb->focus = 2;
            break;
        }
    } else if (MemKb->focus == -5) {
        switch (MemKb->focusLast) {
        case 6:
        case 41:
            MemKb->focus = 6;
            break;
        case 7:
        case 42:
            MemKb->focus = 7;
            break;
        case 9:
        case 44:
            MemKb->focus = 9;
            break;
        case 10:
        case 45:
            MemKb->focus = 10;
            break;
        case 11:
        case 34:
            MemKb->focus = 11;
            break;
        case 35:
        case 50:
            MemKb->focus = 50;
            break;
        default:
            MemKb->focus = 8;
            break;
        }
    }
    dispFocus();
    DWCi_SNDlPlay(8);
}
