/*
 * function: DWCi_KBlInit
 * address:  0x021BD8D8
 * packet:   pkt_ov016_021BD8D8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   CN_BTN                           0x021DA09C  data
 *   CN_SKEY                          0x021DA0A1  data
 *   DWCi_CEINlSetExCell              0x021D5394  arm
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   DWCi_CELLlForm                   0x021D4E1C  arm
 *   DWCi_CELLlSetEffect              0x021D4FF4  arm
 *   DWCi_CELLlSetPriority            0x021D51F0  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlFormEx                  0x021D5950  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   MemKb                            0x021DE55C  data
 *   disp                             0x021BE844  arm
 *   keyboard_data                    0x021DAE68  data
 *   taskStart0                       0x021BDCAC  arm
 *
 * Blocker: DIFF. Prologue now matches with the local order buf,a,num,k,j,i,ix
 * (a at sp+0x18). Residue is from the button loop on: the original keeps the
 * lcd zero in a callee-saved reg (sl) and rematerialises 0x480 per FNTlDrawRect
 * call, hoisting only the shared 2; 1.1p1 hoists 0x480 into fp and spills the
 * zero to sp+0x10, costing frame 0x24 vs 0x20. CN_BTN 0x021DA09C also has no
 * witness outside the range. Notes in docs/notes/pkt_ov016_021BD8D8.c.txt
 * (permuter seed 9804 flat).
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(keyboard.o), symbol DWCi_KBlInit (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov016_func_021BD8D8.c \
 *       --func DWCi_KBlInit --addr 0x021BD8D8 --region ov016 --cc 1.1p1 --arm
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

extern const unsigned char CN_SKEY[4];
extern const unsigned char CN_BTN[2];

void DWCi_KBlInit(void)
{
    unsigned short buf[2];
    AREA a = { 0 };
    int num;
    int k;
    int j;
    int i;
    int ix;

    a.w = 17;
    a.h = 18;
    MemKb = DWCi_HEAPlAllocEx(sizeof(MEMKB), 4);
    MemKb->input = 0xff;
    MemKb->focus = 0;
    MemKb->eraseFlag = 1;
    MemKb->inputFlag = 1;
    for (i = 0; i < 47; i++) {
        MemKb->key[i] = DWCi_CEINlSetExObj(0, 0x34);
        G2_SetOBJEffect(MemKb->key[i], 0x200, 0);
        G2_SetOBJPriority(MemKb->key[i], 3);
    }
    for (i = 0; i < 4; i++) {
        MemKb->skey[i] = DWCi_CEINlSetExObj(0, CN_SKEY[i]);
        G2_SetOBJEffect(MemKb->skey[i], 0x200, 0);
        G2_SetOBJPriority(MemKb->skey[i], 3);
    }
    for (i = 0; i < 2; i++) {
        MemKb->button[i] = DWCi_CEINlSetExCell(0, CN_BTN[i], 1);
        DWCi_CELLlSetEffect(MemKb->button[i], -1, 0x200, 0);
        DWCi_CELLlSetPriority(MemKb->button[i], -1, 3);
    }
    buf[1] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            MemKb->canv[i][j] = DWCi_FNTlFormEx(0, 28, 2, 0, &num, 0);
            a.l = 0;
            ix = j * 12;
            for (k = 0; k < 12; k++, ix++) {
                buf[0] = keyboard_data.KEY_CHR[i][ix];
                DWCi_FNTlDrawRect(MemKb->canv[i][j], a.l, a.t, a.w, a.h, 2, 0x480, buf);
                a.l += 18;
            }
            if (i == 0)
                MemKb->cellCanv[j] = DWCi_CELLlForm(0, num, 1);
        }
    }
    MemKb->cellFocus = DWCi_CEINlSetExCell(0, 0x40, 1);
    DWCi_CELLlSetEffect(MemKb->cellFocus, -1, 0x200, 0);
    DWCi_CELLlSetPriority(MemKb->cellFocus, -1, 2);
    MemKb->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskStart0, 0, 0x78);
    disp(MemKb->page, 0, 192);
}
