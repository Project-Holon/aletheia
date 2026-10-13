/*
 * file:     keyboard10.c
 * unit:     yes
 * function: func_021BF390, func_021BF6B0, func_021BF6E0, func_021BF6F4, func_021BF708, func_021BF71C, func_021BF730, func_021BF74C, func_021BF7B8, func_021BF824, func_021BF890, func_021BF8FC, func_021BF970, func_021BF988, func_021BFB38, func_021BFCF8, func_021BFED0, func_021BFF14, disp, changeColor, func_021C03F0, func_021C0480, func_021C0528, func_021C0588, func_021C05E0, func_021C0638, func_021C0690, func_021C06E8
 * address:  0x021BF390
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call func_021BF988, func_021BFB38, func_021BFCF8, func_021BFF14.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BF970.c \
 *       --func func_021BF970 --addr 0x021BF970 --region ov016 --cc dsi/1.1p1 --arm
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
 *   CN_BTN                           0x021DA360  data
 *   CN_SKEY                          0x021DA35E  data
 *   KEY_CHR                          0x021DA396  data
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   MemKb10                          0x021DE560  data
 *   dispFocus                        0x021C03F0  arm
 *   exchangeBack                     0x021BFED0  arm
 *   keyboard10_rodata                0x021DA35C  data
 *   keyboard10_str_20601             0x021DA460  data
 *   keyboard10_str_20862             0x021DA450  data
 *   keyboard10_str_20864             0x021DA458  data
 *   keyboard10_str_20866             0x021DA448  data
 *   taskMain                         0x021BF970  arm
 *   DWCi_TSKlSetParam  0x021D771C  arm
 *   func_021C0328   0x021C0328  arm
 *   C_KEY  0x021DA3B0  data
 *   C_SKEY  0x021DA37A  data
 *   C_BTN  0x021DA382  data
 *   func_021D4FE0  0x021D4FE0  arm
 *   func_021D52D4  0x021D52D4  arm
 *   func_021D51F0  0x021D51F0  arm
 *   func_021D5118  0x021D5118  arm
 *   g_021DE560     0x021DE560  data
 *   d_021DA3D8     0x021DA3D8  data
 *   d_021DA3DA     0x021DA3DA  data
 *   keyboard10_bss                   0x021DE560  data
 *   @20862                           0x021DA450  data
 *   @20864                           0x021DA458  data
 *   @20866                           0x021DA448  data
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

/* the local initialisers, the compiler's @NNNNN objects, copied by struct assignment */
typedef struct { unsigned char v[5]; } KB10_N5;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed char s8;

struct G {
    u8  pad00[0x58];
    int f58;
    u8  pad5c[7];
    s8  f63;
};

/* the object reads the file static through its .bss section symbol and takes &MemKb10 through the
   variable's own symbol, so the free gets a second pool word (see
   docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md) */
typedef struct { MEMKB10 *MemKb10; } KEYBOARD10_BSS;

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
extern void func_021D4F60(u8 *p);
extern void DWCi_TSKlSetParam(char *p, unsigned int v);
extern void func_021BF988(void);
extern void func_021BFB38(void);
extern void func_021BFCF8(void);
extern void func_021BFF14(void);
extern void func_021C0328(int, int);
extern char *func_021D4FE0(char *p, unsigned int i);
extern void  func_021D52D4(int a, int b, int c);
extern void func_021D51F0(void *cell, int idx, int priority);
extern void func_021D5118(void *cell, int idx, int x, int y);
void DWCi_KB10lInit(void);
void func_021BF6B0(void);
unsigned char func_021BF6E0(void);
void func_021BF6F4(unsigned char v);
void func_021BF708(unsigned char v);
void func_021BF71C(unsigned char v);
int func_021BF730(void);
void func_021BF970(void);
void func_021BFED0(int a);
void func_021C03F0(void);
/* keyboard10.o .bss at 0x021DE560 */
extern MEMKB10 *MemKb10;
extern const KEYBOARD10_RODATA keyboard10_rodata;
extern const KB10_N5 keyboard10_str_20862;
extern const KB10_N5 keyboard10_str_20864;
extern const KB10_N5 keyboard10_str_20866;
extern const AREA keyboard10_str_20601;
extern RECT DWCi_R_SCR;
extern const unsigned char CN_SKEY[2];
extern const unsigned char CN_BTN[2];
extern const unsigned short KEY_CHR[13];
extern const COORD C_KEY[10];
extern const COORD C_SKEY[2];
extern const COORD C_BTN[2];
extern struct G *g_021DE560;
extern u16   d_021DA3D8[][2];
extern u16   d_021DA3DA[][2];
extern KEYBOARD10_BSS keyboard10_bss;



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



void DWCi_KB10lInit(void)
{
    AREA a = keyboard10_str_20601;
    int num;
    int ix;
    int i;
    int j;
    unsigned short buf[2];

    a.w = 28;
    a.h = 20;
    MemKb10 = DWCi_HEAPlAllocEx(sizeof(MEMKB10), 4);
    MemKb10->input = 0x1f;
    MemKb10->focus = 0;
    MemKb10->eraseFlag = 1;
    MemKb10->inputFlag = 1;
    MemKb10->shiftFlag = 1;
    for (i = 0; i < 10; i++) {
        MemKb10->key[i] = DWCi_CEINlSetExObj(0, 0x36);
        G2_SetOBJEffect(MemKb10->key[i], 0x200, 0);
        G2_SetOBJPriority(MemKb10->key[i], 3);
    }
    for (i = 0; i < 2; i++) {
        MemKb10->skey[i] = DWCi_CEINlSetExObj(0, CN_SKEY[i]);
        G2_SetOBJEffect(MemKb10->skey[i], 0x200, 0);
        G2_SetOBJPriority(MemKb10->skey[i], 3);
    }
    for (i = 0; i < 2; i++) {
        MemKb10->button[i] = DWCi_CEINlSetExCell(0, CN_BTN[i], 1);
        DWCi_CELLlSetEffect(MemKb10->button[i], -1, 0x200, 0);
        DWCi_CELLlSetPriority(MemKb10->button[i], -1, 3);
    }
    buf[1] = 0;
    for (i = 0; i < 4; i++) {
        MemKb10->canv[i] = DWCi_FNTlFormEx(0, 12, 4, 0, &num, 0);
        a.l = 0;
        ix = i * 3;
        for (j = 0; j < 3; j++, ix++) {
            buf[0] = KEY_CHR[ix];
            DWCi_FNTlDrawRect(MemKb10->canv[i], a.l, a.t, a.w, a.h, 2, 0x480, buf);
            a.l += 32;
        }
        MemKb10->cellCanv[i] = DWCi_CELLlForm(0, num, 0);
    }
    MemKb10->cellFocus = DWCi_CEINlSetExCell(0, 0x44, 1);
    DWCi_CELLlSetEffect(MemKb10->cellFocus, -1, 0x200, 0);
    DWCi_CELLlSetPriority(MemKb10->cellFocus, -1, 2);
    MemKb10->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskStart0, 0, 0x78);
    disp(0, 0xc0);
}



/*
 * Feed the two words at +0x58 and +0x5c of the object behind 0x021DE560 to the library.
 * Addresses are Black-image addresses.
 */
void func_021BF6B0(void)
{
    func_021D4F60((u8 *)(*(int *)(*(char **)0x021DE560 + 0x58)));
    DWCi_TSKlSetParam((char *)(*(int *)(*(char **)0x021DE560 + 0x5c)), (unsigned int)((void *)0x021C0528));
}


unsigned char func_021BF6E0(void)
{
    return *(unsigned char *)(*(char **)0x021DE560 + 0x60);
}


/*
 * Store a byte at +0x66 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BF6F4.c \
 *       --func func_021BF6F4 --addr 0x021BF6F4 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021BF6F4(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE560 + 0x66) = v;
}


void func_021BF708(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE560 + 0x67) = v;
}


void func_021BF71C(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE560 + 0x68) = v;
}


/*
 * True when the global pointer at 0x021DE560 is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BF730.c \
 *       --func func_021BF730 --addr 0x021BF730 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021BF730(void)
{
    return *(void **)0x021DE560 != 0;
}



static void taskStart0(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb10->key[0], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 76) {
        disp(0, y);
    } else {
        disp(0, 76);
        disp(1, 192);
        DWCi_TSKlChangeFunc(task, taskStart1);
    }
}



static void taskStart1(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb10->key[3], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 99) {
        disp(1, y);
    } else {
        disp(1, 99);
        disp(2, 192);
        DWCi_TSKlChangeFunc(task, taskStart2);
    }
}



static void taskStart2(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb10->key[6], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 122) {
        disp(2, y);
    } else {
        disp(2, 122);
        disp(3, 192);
        DWCi_TSKlChangeFunc(task, taskStart3);
    }
}



static void taskStart3(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb10->key[9], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 145) {
        disp(3, y);
    } else {
        disp(3, 145);
        disp(4, 192);
        DWCi_TSKlChangeFunc(task, taskStart4);
    }
}



static void taskStart4(void *task)
{
    int x, y;

    DWCi_CELLlGetPosition(MemKb10->button[0], 0, &x, &y);
    y -= 12;
    if (y > 170) {
        disp(4, y);
    } else {
        disp(4, 170);
        dispFocus();
        DWCi_TSKlChangeFunc(task, taskMain);
    }
}


void func_021BF970(void)
{
    func_021BF988();
    func_021BFB38();
    func_021BFCF8();
    func_021BFF14();
}






static void touchTriger(void)
{
    int i;
    RECT r;

    if (!DWCi_TPlCheckTrigger(&DWCi_R_SCR))
        return;
    MemKb10->push = -1;
    for (i = 0; i < 10; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_KEY[i], (COORD *)&keyboard10_rodata.S_KEY, &r);
        if (DWCi_TPlCheckTrigger(&r)) {
            if (!MemKb10->inputFlag) {
                DWCi_SNDlPlay(9);
                return;
            }
            DWCi_SNDlPlay(0);
            MemKb10->push = i;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_SKEY[i], (COORD *)&keyboard10_rodata.S_SKEY, &r);
        if (DWCi_TPlCheckTrigger(&r)) {
            if ((i == 0 && !MemKb10->eraseFlag) || (i == 1 && !MemKb10->shiftFlag)) {
                DWCi_SNDlPlay(9);
                return;
            }
            DWCi_SNDlPlay(0);
            MemKb10->push = i + 10;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_BTN[i], (COORD *)&keyboard10_rodata.S_BTN, &r);
        if (DWCi_TPlCheckTrigger(&r)) {
            DWCi_SNDlPlay(0);
            MemKb10->push = i + 12;
            return;
        }
    }
}






static void touchRelease(void)
{
    int i;
    RECT r;

    MemKb10->input = 0;
    if (!DWCi_TPlCheckRelease(&DWCi_R_SCR))
        return;
    for (i = 0; i < 10; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_KEY[i], (COORD *)&keyboard10_rodata.S_KEY, &r);
        if (DWCi_TPlCheckRelease(&r)) {
            if (MemKb10->push != i)
                return;
            MemKb10->input = keyboard10_rodata.KEY_OUT[i];
            MemKb10->focus = i;
            dispFocus();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_SKEY[i], (COORD *)&keyboard10_rodata.S_SKEY, &r);
        if (DWCi_TPlCheckRelease(&r)) {
            if (MemKb10->push != i + 10)
                return;
            MemKb10->input = keyboard10_rodata.SKEY_OUT[i];
            MemKb10->focus = i + 10;
            dispFocus();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_BTN[i], (COORD *)&keyboard10_rodata.S_BTN, &r);
        if (DWCi_TPlCheckRelease(&r)) {
            if (MemKb10->push != i + 12)
                return;
            MemKb10->input = keyboard10_rodata.BTN_OUT[i];
            MemKb10->focus = i + 12;
            dispFocus();
            return;
        }
    }
}






static void touch(void)
{
    int i;
    RECT r;

    if (DWCi_TPlCheck(&DWCi_R_SCR)) {
        for (i = 0; i < 10; i++) {
            DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_KEY[i], (COORD *)&keyboard10_rodata.S_KEY, &r);
            if (DWCi_TPlCheck(&r)) {
                if (MemKb10->push != i)
                    goto out;
                exchangeBack(i);
                goto end;
            }
        }
        for (i = 0; i < 2; i++) {
            DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_SKEY[i], (COORD *)&keyboard10_rodata.S_SKEY, &r);
            if (DWCi_TPlCheck(&r)) {
                if (MemKb10->push != i + 10)
                    goto out;
                exchangeBack(i + 10);
                if (i == 0) {
                    MemKb10->repeat++;
                    if (MemKb10->repeat >= 40) {
                        if (!MemKb10->eraseFlag) {
                            DWCi_SNDlPlay(9);
                            MemKb10->push = -1;
                        } else {
                            MemKb10->input = 0x10;
                            MemKb10->repeat -= 7;
                        }
                    }
                    return;
                }
                goto end;
            }
        }
        for (i = 0; i < 2; i++) {
            DWCi_Coord2Rect((COORD *)&keyboard10_rodata.C_BTN[i], (COORD *)&keyboard10_rodata.S_BTN, &r);
            if (DWCi_TPlCheck(&r)) {
                if (MemKb10->push != i + 12)
                    goto out;
                exchangeBack(i + 12);
                goto end;
            }
        }
    }
out:
    exchangeBack(-1);
end:
    MemKb10->repeat = 0;
}






void func_021BFED0(int a)
{
    unsigned char **g = (unsigned char **)0x021DE560;
    unsigned char *p = *g;

    if (a == *(signed char *)(p + 0x62))
        return;
    func_021C0328(a, 1);
    func_021C0328(*(signed char *)(*g + 0x62), 0);
    *(char *)(*g + 0x62) = a;
}






static void key(void)
{
    int ix;

    if (DWCi_IPTlCheckRepeat(0x20))
        moveFocus(0);
    if (DWCi_IPTlCheckRepeat(0x40))
        moveFocus(1);
    if (DWCi_IPTlCheckRepeat(0x10))
        moveFocus(2);
    if (DWCi_IPTlCheckRepeat(0x80))
        moveFocus(3);
    if (DWCi_IPTlCheckTrigger(0x01)) {
        ix = MemKb10->focus;
        if (ix < 10) {
            if (!MemKb10->inputFlag) {
                DWCi_SNDlPlay(9);
                return;
            }
            MemKb10->input = keyboard10_rodata.KEY_OUT[ix];
            return;
        } else if (ix - 10 < 2) {
            if ((ix - 10 == 0 && !MemKb10->eraseFlag) || (ix - 10 == 1 && !MemKb10->shiftFlag)) {
                DWCi_SNDlPlay(9);
                return;
            }
            MemKb10->input = keyboard10_rodata.SKEY_OUT[ix - 10];
            return;
        } else {
            MemKb10->input = keyboard10_rodata.BTN_OUT[ix - 12];
        }
    }
    if (DWCi_IPTlCheckRepeat(0x02)) {
        if (!MemKb10->eraseFlag) {
            if (!MemKb10->sound) {
                DWCi_SNDlPlay(9);
                MemKb10->sound = 1;
            }
            return;
        }
        MemKb10->input = 0x10;
    } else if (DWCi_IPTlCheckRelease(0x02)) {
        MemKb10->sound = 0;
    }
}




static void disp(int line, int y)
{
    const KB10_N5 N_KEY = keyboard10_str_20862;
    const KB10_N5 N_SKEY = keyboard10_str_20864;
    const KB10_N5 N_BTN = keyboard10_str_20866;
    int ix;
    int i;

    ix = line * 3;
    for (i = 0; i < N_KEY.v[line]; i++, ix++) {
        G2_SetOBJEffect(MemKb10->key[ix], 0, 0);
        G2_SetOBJPosition(MemKb10->key[ix], C_KEY[ix].x, y);
    }
    if (line < 4)
        DWCi_FNTlDisp(MemKb10->canv[line], C_KEY[line * 3].x, y, MemKb10->cellCanv[line], 2);
    for (i = 0; i < N_SKEY.v[line]; i++) {
        G2_SetOBJEffect(MemKb10->skey[i], 0, 0);
        G2_SetOBJPosition(MemKb10->skey[i], C_SKEY[i].x, y);
    }
    for (i = 0; i < N_BTN.v[line]; i++) {
        DWCi_CELLlSetEffect(MemKb10->button[i], -1, 0, 0);
        DWCi_CELLlSetPosition(MemKb10->button[i], -1, C_BTN[i].x, y);
    }
}




static void changeColor(int idx, bool push)
{
    if (idx < 0)
        return;
    if (idx < 10) {
        G2_SetOBJMode(MemKb10->key[idx], 0, keyboard10_rodata.CL_KEY[push]);
    } else if (idx - 10 < 2) {
        G2_SetOBJMode(MemKb10->skey[idx - 10], 0, keyboard10_rodata.CL_KEY[push]);
    } else {
        DWCi_CELLlSetPalette(MemKb10->button[idx - 12], -1, 0, keyboard10_rodata.CL_BTN[push]);
    }
}





void func_021C03F0(void)
{
    struct G *g;
    int sel = 0x44;
    int v;

    g = g_021DE560;
    if (g->f63 > 0xb)
        sel = 0x45;
    v = (int)func_021D4FE0((char *)g->f58, 0);
    func_021D52D4(0, sel, v);
    g = g_021DE560;
    func_021D51F0((void *)g->f58, -1, 2);
    g = g_021DE560;
    func_021D5118((void *)g->f58, -1, d_021DA3D8[g->f63][0], d_021DA3DA[g->f63][0]);
}





static void moveFocus(int dir)
{
    signed char focus;

    focus = MemKb10->focus;
    MemKb10->focus = keyboard10_rodata.MOVE_TBL[focus][dir];
    if (MemKb10->focus == 13 && (dir == 1 || dir == 3)) {
        MemKb10->focusLast = focus;
    } else if (MemKb10->focus == -1) {
        if (MemKb10->focusLast == 1 || MemKb10->focusLast == 10)
            MemKb10->focus = 10;
        else
            MemKb10->focus = 11;
    } else if (MemKb10->focus == -2) {
        if (MemKb10->focusLast == 1 || MemKb10->focusLast == 10)
            MemKb10->focus = 1;
        else
            MemKb10->focus = 2;
    }
    dispFocus();
    DWCi_SNDlPlay(8);
}





static void taskEnd0(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = DWCi_CELLlGetObj(MemKb10->button[0], 0);
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(4, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd1);
}





static void taskEnd1(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb10->key[9];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(3, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd2);
}





static void taskEnd2(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb10->key[6];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(2, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd3);
}





static void taskEnd3(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb10->key[3];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(1, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd4);
}





static void taskEnd4(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb10->key[0];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(0, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd5);
}





static void taskEnd5(void *task)
{
    int i;

    DWCi_TSKlDelete(0, task);
    for (i = 0; i < 4; i++) {
        DWCi_CELLlDelete(keyboard10_bss.MemKb10->cellCanv[i]);
        DWCi_FNTlDelete(keyboard10_bss.MemKb10->canv[i]);
    }
    for (i = 0; i < 2; i++)
        DWCi_CELLlDelete(keyboard10_bss.MemKb10->button[i]);
    for (i = 0; i < 2; i++)
        DWCi_OBJlDelete(keyboard10_bss.MemKb10->skey[i]);
    for (i = 0; i < 10; i++)
        DWCi_OBJlDelete(keyboard10_bss.MemKb10->key[i]);
    DWCi_HEAPlFree_((void **)&MemKb10);
}
