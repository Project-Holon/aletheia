/*
 * file:     keyboard.c
 * unit:     yes
 * function: DWCi_KBlInit, func_021BDC24, func_021BDC54, func_021BDC68, func_021BDC7C, func_021BDC90, func_021BDCAC, func_021BDD24, func_021BDD9C, func_021BDE14, func_021BDE8C, func_021BDF08, func_021BDF20, touchRelease, pushCaps, pushShift, touch, exchangeBack, key, disp, func_021BEAD4, func_021BEB58, func_021BEC20, func_021BECFC, func_021BF0D8, func_021BF140, func_021BF19C, func_021BF1F8, func_021BF254, func_021BF2B0
 * address:  0x021BD8D8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   keyboard_data                    0x021DAE68  data
 *   KEY_CHR                          0x021DAE74  data
 *   DWCi_CELLlDelete                 0x021D4F60  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *   DWCi_CELLlGetPosition            0x021D5250  arm
 *   taskMain                         0x021BDF08  arm
 *   C_KEY                            0x021DA0F8  data
 *   DWCi_Coord2Rect                  0x021D600C  arm
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   keyboard_rodata                  0x021DA098  data
 *   DWCi_TPlCheckRelease             0x021D6A7C  arm
 *   DWCi_TPlCheck                    0x021D68E4  arm
 *   DWCi_IPTlCheckRelease            0x021D68A4  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_CELLlSetPosition            0x021D5118  arm
 *   DWCi_FNTlDisp                    0x021D5F28  arm
 *   FX_ModS32                        0x0207C994  arm
 *   C_SKEY                           0x021DA0C0  data
 *   C_BTN                            0x021DA0B8  data
 *   keyboard_str_20914               0x021DA0E8  data
 *   keyboard_str_20916               0x021DA0F0  data
 *   keyboard_str_20918               0x021DA0E0  data
 *   DWCi_CELLlSetPalette             0x021D5098  arm
 *   C_FOCUS                          0x021DA1B4  data
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CELLlGetObj                 0x021D4FE0  arm
 *   MOVE_TBL                         0x021DA288  data
 *   DWCi_FNTlDelete                  0x021D5A2C  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   keyboard_bss                     0x021DE55C  data
 */
#include "../../matched/include/G_KEYBOARD_DATA.h"

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

/* keyboard.o .data at 0x021DAE68, members at their vendor offsets */
typedef struct {
    unsigned char  *KEY_OUT[3];      /* 0x00 */
    unsigned short *KEY_CHR[3];       /* 0x0C */
    int             SKEY_TOUCH_SND[4];/* 0x18 */
} KEYBOARD_DATA;

/* the 5-byte local initialisers of disp, copied by struct assignment */
typedef struct { unsigned char v[5]; } KB_N5;

/* the object reads the file static through its .bss section symbol and takes &MemKb through the
   variable's own symbol, so the free gets a second pool word (see
   docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md) */
typedef struct { MEMKB *MemKb; } KEYBOARD_BSS;

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
extern void func_021BDF20(void);
extern void func_021BE0D8(void);
extern void func_021BE3E4(void);
extern void func_021BE618(void);
void DWCi_KBlInit(void);
void DWCi_KBlEnd(void);
unsigned char func_021BDC54(void);
void func_021BDC68(unsigned char v);
void func_021BDC7C(unsigned char v);
int func_021BDC90(void);
void func_021BDF08(void);
/* keyboard.o .bss at 0x021DE55C */
extern MEMKB *MemKb;
extern const KEYBOARD_RODATA keyboard_rodata;
extern struct KEYBOARD_DATA keyboard_data;
extern unsigned short *KEY_CHR[3];
extern RECT DWCi_R_SCR;
/* keyboard.o single-symbol .rodata sections */
extern const COORD C_KEY[47];
extern const COORD C_FOCUS[53];
extern const signed char MOVE_TBL[53][4];
extern const KB_N5 keyboard_str_20914;
extern const KB_N5 keyboard_str_20916;
extern const KB_N5 keyboard_str_20918;
extern const unsigned char CN_SKEY[4];
extern const unsigned char CN_BTN[2];
extern const COORD C_SKEY[4];
extern const COORD C_BTN[2];
extern KEYBOARD_BSS keyboard_bss;









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









static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}









void DWCi_KBlInit(void)
{
    AREA a = { 0 };
    int num;
    int ix;
    int i;
    int j;
    int k;
    unsigned short buf[2];

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
            for (k = 0; k < 12; k++, ix++, a.l += 18) {
                buf[0] = KEY_CHR[i][ix];
                DWCi_FNTlDrawRect(MemKb->canv[i][j], a.l, a.t, a.w, a.h, 2, 0x480, buf);
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










void DWCi_KBlEnd(void)
{
    DWCi_CELLlDelete(MemKb->cellFocus);
    DWCi_TSKlChangeFunc(MemKb->task, taskEnd0);
}









/*
 * Unsigned byte at +0x11c of a global object pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC54.c \
 *       --func func_021BDC54 --addr 0x021BDC54 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char func_021BDC54(void)
{
    return *(unsigned char *)(*(char **)0x021DE55C + 0x11c);
}









/*
 * Store a byte at +0x123 of a global object pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC68.c \
 *       --func func_021BDC68 --addr 0x021BDC68 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021BDC68(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE55C + 0x123) = v;
}









/*
 * Store a byte at +0x124 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC7C.c \
 *       --func func_021BDC7C --addr 0x021BDC7C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021BDC7C(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE55C + 0x124) = v;
}









/*
 * True when the global pointer at 0x021DE55C is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC90.c \
 *       --func func_021BDC90 --addr 0x021BDC90 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021BDC90(void)
{
    return *(void **)0x021DE55C != 0;
}










static void taskStart0(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb->key[0], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 81) {
        disp(MemKb->page, 0, y);
    } else {
        disp(MemKb->page, 0, 81);
        disp(MemKb->page, 1, 192);
        DWCi_TSKlChangeFunc(task, taskStart1);
    }
}










static void taskStart1(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb->key[12], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 103) {
        disp(MemKb->page, 1, y);
    } else {
        disp(MemKb->page, 1, 103);
        disp(MemKb->page, 2, 192);
        DWCi_TSKlChangeFunc(task, taskStart2);
    }
}










static void taskStart2(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb->key[24], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 125) {
        disp(MemKb->page, 2, y);
    } else {
        disp(MemKb->page, 2, 125);
        disp(MemKb->page, 3, 192);
        DWCi_TSKlChangeFunc(task, taskStart3);
    }
}










static void taskStart3(void *task)
{
    int x, y;

    G2_GetOBJPosition(MemKb->key[36], (unsigned long *)&x, (unsigned long *)&y);
    y -= 12;
    if (y > 147) {
        disp(MemKb->page, 3, y);
    } else {
        disp(MemKb->page, 3, 147);
        disp(MemKb->page, 4, 192);
        DWCi_TSKlChangeFunc(task, taskStart4);
    }
}










static void taskStart4(void *task)
{
    int x, y;

    DWCi_CELLlGetPosition(MemKb->button[0], 0, &x, &y);
    y -= 12;
    if (y > 170) {
        disp(MemKb->page, 4, y);
    } else {
        disp(MemKb->page, 4, 170);
        dispFocus();
        DWCi_TSKlChangeFunc(task, taskMain);
    }
}









/*
 * Call func_021BDF20, func_021BE0D8, func_021BE3E4, func_021BE618.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDF08.c \
 *       --func func_021BDF08 --addr 0x021BDF08 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021BDF08(void)
{
    func_021BDF20();
    func_021BE0D8();
    func_021BE3E4();
    func_021BE618();
}









static void touchTriger(void)
{
    int i;
    RECT r;

    if (!DWCi_TPlCheckTrigger(&DWCi_R_SCR))
        return;
    MemKb->push = -1;
    for (i = 0; i < 47; i++) {
        DWCi_Coord2Rect((COORD *)&C_KEY[i], (COORD *)&keyboard_rodata.S_KEY, &r);
        if (DWCi_TPlCheckTrigger(&r)) {
            if (!MemKb->inputFlag) {
                DWCi_SNDlPlay(9);
                return;
            }
            DWCi_SNDlPlay(0);
            MemKb->push = i;
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_SKEY[i], (COORD *)&keyboard_rodata.S_SKEY[i], &r);
        if (DWCi_TPlCheckTrigger(&r)) {
            if ((i == 3 && !MemKb->eraseFlag) || (i == 2 && !MemKb->inputFlag)) {
                DWCi_SNDlPlay(9);
                return;
            }
            DWCi_SNDlPlay(keyboard_data.SKEY_TOUCH_SND[i]);
            MemKb->push = i + 47;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_BTN[i], (COORD *)&keyboard_rodata.S_BTN, &r);
        if (DWCi_TPlCheckTrigger(&r)) {
            DWCi_SNDlPlay(0);
            MemKb->push = i + 51;
            return;
        }
    }
}








static void touchRelease(void)
{
    int i;
    RECT r;

    MemKb->input = 0;
    if (!DWCi_TPlCheckRelease(&DWCi_R_SCR))
        return;
    for (i = 0; i < 47; i++) {
        DWCi_Coord2Rect((COORD *)&C_KEY[i], (COORD *)&keyboard_rodata.S_KEY, &r);
        if (DWCi_TPlCheckRelease(&r)) {
            if (MemKb->push != i)
                return;
            MemKb->input = keyboard_data.KEY_OUT[MemKb->page][i];
            if (MemKb->page == 1)
                changePage(0);
            MemKb->focus = i;
            dispFocus();
            return;
        }
    }
    for (i = 2; i < 4; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_SKEY[i], (COORD *)&keyboard_rodata.S_SKEY[i], &r);
        if (DWCi_TPlCheckRelease(&r)) {
            if (MemKb->push != i + 47)
                return;
            MemKb->input = keyboard_rodata.SKEY_OUT[i];
            if (MemKb->page == 1)
                changePage(0);
            MemKb->focus = i + 47;
            dispFocus();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_BTN[i], (COORD *)&keyboard_rodata.S_BTN, &r);
        if (DWCi_TPlCheckRelease(&r)) {
            if (MemKb->push != i + 51)
                return;
            MemKb->input = keyboard_rodata.BTN_OUT[i];
            MemKb->focus = i + 51;
            dispFocus();
            return;
        }
    }
    DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_SKEY[0], (COORD *)&keyboard_rodata.S_SKEY[0], &r);
    if (DWCi_TPlCheckRelease(&r)) {
        if (MemKb->push != 47)
            return;
        pushCaps();
        MemKb->focus = 47;
        dispFocus();
        return;
    }
    DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_SKEY[1], (COORD *)&keyboard_rodata.S_SKEY[1], &r);
    if (DWCi_TPlCheckRelease(&r)) {
        if (MemKb->push != 48)
            return;
        pushShift();
        MemKb->focus = 48;
        dispFocus();
    }
}







static void pushCaps(void)
{
    changePage(MemKb->page == 2 ? 0 : 2);
    DWCi_SNDlPlay(1);
}







static void pushShift(void)
{
    changePage(MemKb->page == 1 ? 0 : 1);
    DWCi_SNDlPlay(1);
}





static void touch(void)
{
    int i;
    RECT r;

    if (DWCi_TPlCheck(&DWCi_R_SCR)) {
        for (i = 0; i < 47; i++) {
            DWCi_Coord2Rect((COORD *)&C_KEY[i], (COORD *)&keyboard_rodata.S_KEY, &r);
            if (DWCi_TPlCheck(&r)) {
                if (MemKb->push != i)
                    goto out;
                exchangeBack(i);
                goto end;
            }
        }
        for (i = 2; i < 4; i++) {
            DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_SKEY[i], (COORD *)&keyboard_rodata.S_SKEY[i], &r);
            if (DWCi_TPlCheck(&r)) {
                if (MemKb->push != i + 47)
                    goto out;
                exchangeBack(i + 47);
                if (i == 3) {
                    MemKb->repeat++;
                    if (MemKb->repeat >= 40) {
                        if (!MemKb->eraseFlag) {
                            DWCi_SNDlPlay(9);
                            MemKb->push = -1;
                        } else {
                            MemKb->input = 0x80;
                            MemKb->repeat -= 7;
                        }
                    }
                }
                return;
            }
        }
        for (i = 0; i < 2; i++) {
            DWCi_Coord2Rect((COORD *)&keyboard_rodata.C_BTN[i], (COORD *)&keyboard_rodata.S_BTN, &r);
            if (DWCi_TPlCheck(&r)) {
                if (MemKb->push != i + 51)
                    goto out;
                exchangeBack(i + 51);
                goto end;
            }
        }
    }
out:
    exchangeBack(-1);
end:
    MemKb->repeat = 0;
}





static void exchangeBack(int idx)
{
    if (idx == MemKb->touchLast)
        return;
    changeColor(idx, 1);
    changeColor(MemKb->touchLast, 0);
    MemKb->touchLast = idx;
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
        ix = MemKb->focus;
        if (ix < 47) {
            if (!MemKb->inputFlag) {
                DWCi_SNDlPlay(9);
                return;
            }
            MemKb->input = keyboard_data.KEY_OUT[MemKb->page][ix];
            if (MemKb->page == 1)
                changePage(0);
            return;
        } else if (ix - 47 < 4) {
            switch (ix - 47) {
            case 0:
                pushCaps();
                return;
            case 1:
                pushShift();
                return;
            case 2:
                if (!MemKb->inputFlag) {
                    DWCi_SNDlPlay(9);
                    return;
                }
                break;
            case 3:
                if (!MemKb->eraseFlag) {
                    DWCi_SNDlPlay(9);
                    return;
                }
                break;
            }
            if (MemKb->page == 1)
                changePage(0);
            MemKb->input = keyboard_rodata.SKEY_OUT[ix - 47];
            return;
        } else {
            MemKb->input = keyboard_rodata.BTN_OUT[ix - 51];
        }
    }
    if (DWCi_IPTlCheckRepeat(0x02)) {
        if (!MemKb->eraseFlag) {
            if (!MemKb->sound) {
                DWCi_SNDlPlay(9);
                MemKb->sound = 1;
            }
            return;
        }
        MemKb->input = 0x80;
    } else if (DWCi_IPTlCheckRelease(0x02)) {
        MemKb->sound = 0;
    }
    if (DWCi_IPTlCheckTrigger(0x400))
        pushCaps();
    if (DWCi_IPTlCheckTrigger(0x800))
        pushShift();
}



static void disp(int page, int line, int y)
{
    const KB_N5 N_KEY = keyboard_str_20914;
    const KB_N5 N_SKEY = keyboard_str_20916;
    const KB_N5 N_BTN = keyboard_str_20918;
    int ix;
    int i;

    ix = line * 12;
    for (i = 0; i < N_KEY.v[line]; i++, ix++) {
        G2_SetOBJEffect(MemKb->key[ix], 0, 0);
        G2_SetOBJPosition(MemKb->key[ix], C_KEY[ix].x, y);
    }
    if (line < 4)
        DWCi_FNTlDisp(MemKb->canv[page][line], C_KEY[line * 12].x, y, MemKb->cellCanv[line], 2);
    ix = FX_ModS32(line + 3, 4);
    for (i = 0; i < N_SKEY.v[line]; i++) {
        G2_SetOBJEffect(MemKb->skey[ix], 0, 0);
        G2_SetOBJPosition(MemKb->skey[ix], C_SKEY[ix].x, y);
    }
    for (i = 0; i < N_BTN.v[line]; i++) {
        DWCi_CELLlSetEffect(MemKb->button[i], -1, 0, 0);
        DWCi_CELLlSetPosition(MemKb->button[i], -1, C_BTN[i].x, y);
    }
}




static void changePage(int page)
{
    int i;
    bool c = 0;
    bool s = 0;

    MemKb->page = page;
    for (i = 0; i < 4; i++)
        disp(page, i, C_KEY[i * 12].y);
    if (page == 2)
        c = 1;
    else if (page == 1)
        s = 1;
    changeColor(47, c);
    changeColor(48, s);
}




static void changeColor(int idx, bool push)
{
    if (idx < 0)
        return;
    if (idx < 47) {
        G2_SetOBJMode(MemKb->key[idx], 0, keyboard_rodata.CL_KEY[push]);
    } else if (idx - 47 < 4) {
        G2_SetOBJMode(MemKb->skey[idx - 47], 0, keyboard_rodata.CL_KEY[push]);
    } else {
        DWCi_CELLlSetPalette(MemKb->button[idx - 51], -1, 0, keyboard_rodata.CL_BTN[push]);
    }
}




static void dispFocus(void)
{
    int type;

    switch (MemKb->focus) {
    case 47:
        type = 0x42;
        break;
    case 48:
        type = 0x41;
        break;
    case 49:
        type = 0x43;
        break;
    case 50:
        type = 0x41;
        break;
    case 51:
    case 52:
        type = 0x45;
        break;
    default:
        type = 0x40;
        break;
    }
    DWCi_CEINlSet(0, type, DWCi_CELLlGetObj(MemKb->cellFocus, 0));
    DWCi_CELLlSetPriority(MemKb->cellFocus, -1, 2);
    DWCi_CELLlSetPosition(MemKb->cellFocus, -1, C_FOCUS[MemKb->focus].x, C_FOCUS[MemKb->focus].y);
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




static void taskEnd0(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = DWCi_CELLlGetObj(MemKb->button[0], 0);
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(MemKb->page, 4, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd1);
}




static void taskEnd1(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb->key[36];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(MemKb->page, 3, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd2);
}




static void taskEnd2(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb->key[24];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(MemKb->page, 2, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd3);
}




static void taskEnd3(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb->key[12];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(MemKb->page, 1, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd4);
}




static void taskEnd4(void *task)
{
    GXOamAttr *obj;
    int x, y;

    obj = MemKb->key[0];
    G2_GetOBJPosition(obj, (unsigned long *)&x, (unsigned long *)&y);
    y += 12;
    disp(MemKb->page, 0, y);
    if (y >= 192)
        DWCi_TSKlChangeFunc(task, taskEnd5);
}




static void taskEnd5(void *task)
{
    int i, j;

    DWCi_TSKlDelete(0, task);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            DWCi_FNTlDelete(keyboard_bss.MemKb->canv[i][j]);
            if (i == 0)
                DWCi_CELLlDelete(keyboard_bss.MemKb->cellCanv[j]);
        }
    }
    for (i = 0; i < 2; i++)
        DWCi_CELLlDelete(keyboard_bss.MemKb->button[i]);
    for (i = 0; i < 4; i++)
        DWCi_OBJlDelete(keyboard_bss.MemKb->skey[i]);
    for (i = 0; i < 47; i++)
        DWCi_OBJlDelete(keyboard_bss.MemKb->key[i]);
    DWCi_HEAPlFree_((void **)&MemKb);
}
