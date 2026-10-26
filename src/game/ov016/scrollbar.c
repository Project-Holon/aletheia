/*
 * file:     scrollbar.c
 * unit:     yes
 * function: DWCi_SBlInit, DWCi_SBlEnd, DWCi_SBlGet, DWCi_SBlGetState, DWCi_SBlDisp, DWCi_SBlEnable, DWCi_SBlDisable, taskMain, moveBar, playSound, stepBar, setBar, isTrigger, isTouch, calcRect, disp
 * address:  0x021CE874
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * ARM tail-call thunk into disp.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlDisp.c \
 *       --func DWCi_SBlDisp --addr 0x021CE9AC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_InputCoord  0x021D5FE8  arm  ov016
 *   DWCi_CEINlSetExCell  0x021D5394  arm  ov016
 *   DWCi_CELLlSetPosition  0x021D5118  arm  ov016
 *   DWCi_CELLlSetPriority  0x021D51F0  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gScrollBar  0x021DE63C  data
 *   sScrollBarCellIds  0x021DA8B8  data
 *   DWCi_TSKlDeleteEx  0x021D7744  arm  ov016
 *   DWCi_CELLlDelete  0x021D4F60  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_SNDlSetVolume  0x021CFFD0  arm  ov016
 *   DWCi_TPlGet  0x021D6B64  arm  ov016
 *   DWCi_TPlCheck  0x021D68E4  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   sScrollbarTable  0x021DAA7C  data
 *   sScrollBarStep  0x021DA8BB  data
 *   FX_DivS32  0x0207C958  arm
 *   DWCi_SNDlSetPitch  0x021CFFF0  arm  ov016
 *   DWCi_TPlCheckRepeat  0x021D69F4  arm  ov016
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 */
struct tagCOORD;
typedef struct {
    void *cell;                       /* 0x00 */
    void *obj[2];                     /* 0x04 */
    void *task;                       /* 0x0C */
    unsigned short x;                 /* 0x10 */
    unsigned short y;                 /* 0x12 */
    unsigned short w;                 /* 0x14 */
    unsigned short off;               /* 0x16 */
    unsigned char base;               /* 0x18 */
    unsigned char len;                /* 0x19 */
    unsigned char pos;                /* 0x1A */
    unsigned char bar;                /* 0x1B */
    unsigned char a;                  /* 0x1C */
    unsigned char b;                  /* 0x1D */
    unsigned char disable;            /* 0x1E */
    unsigned char pad;                /* 0x1F */
} ScrollBar;

#include "../types.h"
#include "task.h"
typedef _Bool bool;

#include "dwcutil_types.h"

#include "heap.h"
#include "foundation.h"
extern void *DWCi_CEINlSetExCell(s32 lcd, s32 idx, bool head);
#include "cell.h"
struct TCB;
struct CellInfo;
#include "sound.h"
#include "input.h"
#include "../arm9/fx_cp.h"
void DWCi_SBlInit(int kind, int max, int x, int y, int pos);
void DWCi_SBlEnd(void);
u8 DWCi_SBlGet(void);
unsigned char DWCi_SBlGetState(void);
void DWCi_SBlDisp(int scrollPos);
void DWCi_SBlEnable(void);
void DWCi_SBlDisable(void);
extern ScrollBar *gScrollBar;
extern unsigned char sScrollBarCellIds[];
extern struct tagRECT sScrollbarTable;
extern unsigned char sScrollBarStep[];

/*
 * sdk:      DWCi_SBlInit (libdwcutil.TWL.HYB.a(scrollbar.o))
 */

static void taskMain(void *task, void *work);
static void moveBar(void);
static void playSound(int pos);
static void stepBar(int idx);
static void setBar(void);
static int isTrigger(void);
static int isTouch(int a);
static void calcRect(int idx, RECT *r);
static void disp(int pos);
void DWCi_SBlInit(int kind, int max, int x, int y, int pos)
{
	gScrollBar = (ScrollBar *)DWCi_HEAPlAllocEx(sizeof(*gScrollBar), 4);
	gScrollBar->bar = kind;
	gScrollBar->len = max;
	gScrollBar->pos = pos;
	DWCi_InputCoord(x, y, &gScrollBar->x);
	gScrollBar->cell = DWCi_CEINlSetExCell(0, sScrollBarCellIds[kind], 1);
	DWCi_CELLlSetPosition(gScrollBar->cell, -1, x, y + pos);
	DWCi_CELLlSetPriority(gScrollBar->cell, -1, 1);
	gScrollBar->task = DWCi_TSKlForm(0, taskMain, 0, 0x80);
}

/*
 * sdk:      DWCi_SBlEnd (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void DWCi_SBlEnd(void)
{
	DWCi_TSKlDeleteEx(0, gScrollBar->task);
	DWCi_CELLlDelete(gScrollBar->cell);
	DWCi_HEAPlFree_((void **)0x021DE63C);
}

u8 DWCi_SBlGet(void)
{
    return gScrollBar->pos;
}

/*
 * Read the byte at +0x1d of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlGetState.c \
 *       --func DWCi_SBlGetState --addr 0x021CE998 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char DWCi_SBlGetState(void)
{
    return gScrollBar->b;
}

void DWCi_SBlDisp(int scrollPos)
{
    disp(scrollPos);
}

/*
 * Clear the byte at +0x1e of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlEnable.c \
 *       --func DWCi_SBlEnable --addr 0x021CE9B8 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SBlEnable(void)
{
    gScrollBar->disable = 0;
}

/*
 * Set the byte at +0x1e of the object behind the global pointer to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SBlDisable.c \
 *       --func DWCi_SBlDisable --addr 0x021CE9D0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SBlDisable(void)
{
    gScrollBar->disable = 1;
}

/*
 * sdk:      taskMain (libdwcutil.TWL.HYB.a scrollbar.o)
 */
static void taskMain(void *task, void *work)
{
    gScrollBar->b = 0;
    switch (gScrollBar->a) {
    case 0:
        if (gScrollBar->disable)
            return;
        switch (isTrigger()) {
        case 1:
            if (gScrollBar->bar == 0)
                return;
            DWCi_SNDlPlay(0x16);
            DWCi_SNDlSetVolume(0);
            gScrollBar->b = 1;
            DWCi_TPlGet((struct tagCOORD *)(&gScrollBar->w));
            gScrollBar->base = gScrollBar->pos;
            gScrollBar->a = 1;
            break;
        case 2:
            stepBar(2);
            break;
        case 3:
            stepBar(3);
            break;
        case 4:
            setBar();
            break;
        }
        break;
    case 1:
        moveBar();
        break;
    case 2:
        if (isTouch(2) != 2) {
            gScrollBar->b = 5;
            gScrollBar->a = 0;
        } else if (isTrigger() == 2) {
            stepBar(2);
        }
        break;
    case 3:
        if (isTouch(3) != 3) {
            gScrollBar->b = 7;
            gScrollBar->a = 0;
        } else if (isTrigger() == 3) {
            stepBar(3);
        }
        break;
    }
}

/*
 * sdk:      moveBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static void moveBar(void)
{
	COORD c;
	int pos;
	int s;

	if (DWCi_TPlCheck((u16 *)((char *)&sScrollbarTable))) {
		DWCi_TPlGet((struct tagCOORD *)(&c));
		if (c.x >= gScrollBar->x - 30) {
			pos = gScrollBar->base + (c.y - gScrollBar->off);
			if (pos < 0)
				pos = 0;
			else {
				s = sScrollBarStep[gScrollBar->bar];
				if (pos >= gScrollBar->len - s)
					pos = gScrollBar->len - s;
			}
			playSound(pos);
			disp(pos);
			gScrollBar->b = 2;
			return;
		}
	}
	DWCi_SNDlStop();
	gScrollBar->a = 0;
	gScrollBar->b = 3;
}

/*
 * sdk:      playSound (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static void playSound(int pos)
{
	int d;
	int vol;
	int pit;

	d = gScrollBar->pos - pos;
	if (d < 0)
		d = -d;
	if (d < 2)
		vol = 0;
	else if (d >= 6)
		vol = 0x7f;
	else
		vol = FX_DivS32(0x7f, 6 - d);
	DWCi_SNDlSetVolume(vol);
	if (d < 2)
		pit = -0x100;
	else if (d >= 6)
		pit = 0x100;
	else
		pit = FX_DivS32(0x200, 6 - d) - 0x100;
	DWCi_SNDlSetPitch(0xffff, pit);
}

/*
 * sdk:      stepBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static void stepBar(int idx)
{
	gScrollBar->a = idx;
	gScrollBar->b = (idx == 2) ? 4 : 6;
}

/*
 * sdk:      setBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static void setBar(void)
{
	COORD c;
	int pos;
	int s;

	DWCi_TPlGet((struct tagCOORD *)(&c));
	s = sScrollBarStep[gScrollBar->bar];
	pos = c.y - gScrollBar->y - ((unsigned)s >> 1);
	if (pos < 0)
		pos = 0;
	else if (pos >= gScrollBar->len - s)
		pos = gScrollBar->len - s;
	disp(pos);
	gScrollBar->b = 3;
}

/*
 * sdk:      isTrigger (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static int isTrigger(void)
{
	int idx;
	RECT r;

	idx = 1;
	calcRect(idx, &r);
	if (DWCi_TPlCheckRepeat((u16 *)&r))
		return idx;
	for (idx = 2; idx <= 3; idx++) {
		calcRect(idx, &r);
		if (DWCi_TPlCheckRepeat((u16 *)&r))
			return idx;
	}
	idx = 4;
	calcRect(idx, &r);
	if (!DWCi_TPlCheckTrigger((u16 *)&r))
		idx = 0;
	return idx;
}

/*
 * sdk:      isTouch (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static int isTouch(int a)
{
	int idx;
	RECT r;

	for (idx = 2; idx <= 3; idx++) {
		calcRect(idx, &r);
		if (DWCi_TPlCheck((u16 *)&r))
			return idx;
	}
	return 0;
}

/*
 * sdk:      calcRect (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static void calcRect(int idx, RECT *r)
{
	int x = gScrollBar->x;
	r->l = x;
	r->r = x + 12;
	switch (idx) {
	case 0:
		break;
	case 1:
		r->t = gScrollBar->y + gScrollBar->pos;
		r->b = r->t + sScrollBarStep[gScrollBar->bar];
		break;
	case 2:
		r->t = gScrollBar->y - 13;
		r->b = gScrollBar->y;
		break;
	case 3:
		r->t = gScrollBar->y + gScrollBar->len;
		r->b = r->t + 13;
		break;
	case 4:
		r->t = gScrollBar->y;
		r->b = r->t + gScrollBar->len;
		break;
	}
}

/*
 * sdk:      disp (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
static void disp(int pos)
{
	DWCi_CELLlSetPosition(gScrollBar->cell, -1, gScrollBar->x, pos + gScrollBar->y);
	gScrollBar->pos = pos;
}
