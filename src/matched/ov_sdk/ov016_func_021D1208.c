/*
 * function: DWCi_WINlInitEx
 * address:  0x021D1208
 * packet:   pkt_ov016_021D1208
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed (2026-10-01, wave 3 lane08): draft semantics were wrong in the
 *           button loop.  The image's r7 is a hoisted constant 0 copied from
 *           i at entry, so the loop calls are (0, CELL_BUTTON[type][i], 0),
 *           (.., -1, 0x100, 0), (.., -1, 0); and the bound BUTTON_NUM[type]
 *           is read once, so the tables are const (extern const).  With the
 *           real loop pressure, ms and dark spill on their own exactly as
 *           DWARF says ([fb+20], [fb+16]); the volatile `d` stand-in is gone.
 *
 * sdk:      DWCi_WINlInitEx (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_MSGlGetEx                   0x021c1048 arm
 *   DWCi_HEAPlAllocEx                0x021d6414 arm
 *   G2x_SetBlendBrightness_          0x0207d658 arm
 *   DWCi_CEINlSetExCell              0x021d5394 arm
 *   DWCi_CELLlSetPosition            0x021d5118 arm
 *   DWCi_CELLlSetPriority            0x021d51f0 arm
 *   DWCi_FNTlFormEx                  0x021d5950 arm
 *   DWCi_CELLlForm                   0x021d4e1c arm
 *   DWCi_CMNlFontFlag                0x021bd3cc arm
 *   DWCi_FNTlDrawRect                0x021d5e5c arm
 *   DWCi_FNTlDisp                    0x021d5f28 arm
 *   DWCi_GXlSetWndPlane              0x021d61f4 arm
 *   DWCi_GXlSetWndPosition           0x021d60ec arm
 *   disp                             0x021d1868 arm
 *   DWCi_TSKlForm                    0x021d7680 arm
 *   sWindowTable15                       0x021daa58 data
 *   gCommentWork                       0x021de598 data
 *   gWindowWork                       0x021de658 data
 *   sWindowTable1                       0x021da9a0 data
 *   sWindowTable2                       0x021da9a6 data
 *   sWindowTable7                       0x021da9c8 data
 *   sWindowTable9                       0x021da9e6 data
 *   sWindowTable10                       0x021da9e8 data
 *   sWindowTable3                       0x021da9ac data
 *   taskV                            0x021d1598 arm  ov016
 *   taskMove                         0x021d15f0 arm  ov016
 */

#include "../include/G_MemWinT.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned char bool;

typedef struct {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    u16 countWait;
    signed char count;
    signed char input;
    u8 type;
    u8 wait;
    u8 dark;
} MemWinT;

extern u16 *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void *DWCi_FNTlFormEx(int lcd, int width, int height, bool head, int *obj, int font);
extern void *DWCi_CELLlForm(int lcd, int num, bool head);
extern unsigned long DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, u16 *txt);
extern void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio);
extern void DWCi_GXlSetWndPlane(int lcd, int wnd, int plane, bool effect);
extern void DWCi_GXlSetWndPosition(int lcd, int wnd, void *r);
extern void disp(int y);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskV(void *task);
extern void taskMove(void *task);

extern u8 sWindowTable15[6];
extern void *gCommentWork;
extern struct MemWinT *gWindowWork;
extern const u8 sWindowTable1[6];
extern const u8 sWindowTable2[6];
extern const u8 sWindowTable7[][2];
extern u16 sWindowTable9[];
extern u16 sWindowTable10[];
extern u16 sWindowTable3[4];

void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num)
{
    u8 EFF[6];
    int obj;
    int i;
    u16 *ms;

    EFF[0] = sWindowTable15[0];
    EFF[1] = sWindowTable15[1];
    EFF[2] = sWindowTable15[2];
    EFF[3] = sWindowTable15[3];
    EFF[4] = sWindowTable15[4];
    EFF[5] = sWindowTable15[5];

    ms = DWCi_MSGlGetEx(gCommentWork, msg, n, num);
    gWindowWork = (struct MemWinT *)((MemWinT *)DWCi_HEAPlAllocEx(0x20, 4));
    gWindowWork->type = type;
    gWindowWork->input = -2;
    gWindowWork->dark = dark;
    G2x_SetBlendBrightness_(0x04000050, 0x1f, 0);

    gWindowWork->cellWin = DWCi_CEINlSetExCell(0, sWindowTable1[type], 0);
    DWCi_CELLlSetPosition(gWindowWork->cellWin, -1, 0x100, 0);
    DWCi_CELLlSetPriority(gWindowWork->cellWin, -1, 0);

    for (i = 0; i < sWindowTable2[type]; i++) {
        gWindowWork->button[i] = DWCi_CEINlSetExCell(0, sWindowTable7[type][i], 0);
        DWCi_CELLlSetPosition(gWindowWork->button[i], -1, 0x100, 0);
        DWCi_CELLlSetPriority(gWindowWork->button[i], -1, 0);
    }

    gWindowWork->canv = DWCi_FNTlFormEx(0, 0x20, 0xc, 1, &obj, 0);
    gWindowWork->cellChar = DWCi_CELLlForm(0, obj, 0);
    DWCi_FNTlDrawRect(gWindowWork->canv, 0, 0, sWindowTable9[type * 2], sWindowTable10[type * 2], 2, DWCi_CMNlFontFlag(), ms);
    DWCi_FNTlDisp(gWindowWork->canv, 0x100, 0, gWindowWork->cellChar, 0);

    DWCi_GXlSetWndPlane(0, 0, 0x1f, 0);
    DWCi_GXlSetWndPlane(0, 1, 0x1f, EFF[gWindowWork->type]);
    DWCi_GXlSetWndPlane(0, 3, 0x1f, 1);
    DWCi_GXlSetWndPosition(0, 1, sWindowTable3);

    disp(0xc0);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xE000) | 0x6000;

    if (dark)
        gWindowWork->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskV, 0, 0x78);
    else
        gWindowWork->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskMove, 0, 0x78);
}






