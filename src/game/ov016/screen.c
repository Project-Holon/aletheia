/*
 * file:     screen.c
 * unit:     yes
 * function: DWCi_SCREENlInit, DWCi_SCREENlEnd, DWCi_SCREENlRenew, DWCi_SCREENlCopy, taskLoad, DWCi_SCREENlCopyPalette, taskCopyPltt, DWCi_SCREENlSetPalette, taskSetPltt
 * address:  0x021CE668
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
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gScreenWork  0x021DE630  data
 *   DWCi_TSKlDeleteEx  0x021D7744  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 */
typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;

/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;

#include "heap.h"
#include "../sdk_ioreg.h"
#include "task.h"
#include "../arm9/mi_memory.h"
struct TCB;
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
void DWCi_SCREENlInit(void *scr);
void DWCi_SCREENlEnd(void);
void DWCi_SCREENlRenew(void);
void DWCi_SCREENlCopy(void *src, int pos, int w, int h);
void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
void DWCi_SCREENlSetPalette(void *v);
extern ScreenBss gScreenWork;


/*
 * sdk:      DWCi_SCREENlInit (libdwcutil.TWL.HYB.a(screen.o))
 */

static void taskLoad(void);
static void taskCopyPltt(void *task);
static void taskSetPltt(void *task);
void DWCi_SCREENlInit(void *scr)
{
	gScreenWork.scr = (MemScr *)DWCi_HEAPlAllocEx(0x608, 4);
	MIi_CpuCopyFast(scr, gScreenWork.scr->buf, 0x600);
	gScreenWork.scr->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskLoad, 0, 0x78);
}


/*
 * sdk:      DWCi_SCREENlEnd (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SCREENlEnd.c \n *       --func DWCi_SCREENlEnd --addr 0x021CE6C4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void DWCi_SCREENlEnd(void)
{
    DWCi_TSKlDeleteEx(1, gScreenWork.scr->task);
    DWCi_HEAPlFree_((void **)0x021DE630);
}


void DWCi_SCREENlRenew(void)
{
    gScreenWork.scr->dirty = 1;
}


/*
 * sdk:      DWCi_SCREENlCopy (libdwcutil.TWL.HYB.a(screen.o))
 */
void DWCi_SCREENlCopy(void *src, int pos, int w, int h)
{
	unsigned short *sr;
	unsigned short *dst;
	int i;

	sr = (unsigned short *)src;
	dst = (unsigned short *)gScreenWork.scr->buf + pos;
	for (i = 0; i < h; i++) {
		MIi_CpuCopy16(sr, dst, w * 2);
		sr += 32;
		dst += 32;
	}
}


static void taskLoad(void)
{
    if (!gScreenWork.scr->dirty)
        return;
    DC_FlushRange(gScreenWork.scr->buf, 0x600);
    GX_LoadBG2Scr(gScreenWork.scr->buf, 0, 0x600);
    gScreenWork.scr->dirty = 0;
}


/*
 * sdk:      DWCi_SCREENlCopyPalette (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SCREENlCopyPalette.c \n *       --func DWCi_SCREENlCopyPalette --addr 0x021CE7B0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor)
{
    gScreenWork.src = (unsigned char *)src + sColor * 32;
    gScreenWork.dst = (unsigned char *)HW_BG_PLTT + dColor * 32;
    DWCi_TSKlForm(1, (void (*)(void *, void *))taskCopyPltt, 0, 0x78);
}


/*
 * sdk:      taskCopyPltt (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/taskCopyPltt.c \n *       --func taskCopyPltt --addr 0x021CE7EC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void taskCopyPltt(void *task)
{
    MIi_CpuCopy16(gScreenWork.src, gScreenWork.dst, 0x20);
    DWCi_TSKlDelete(1, task);
}


/*
 * Record v and hand the companion entry point to the timer helper.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SCREENlSetPalette.c \
 *       --func DWCi_SCREENlSetPalette --addr 0x021CE818 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SCREENlSetPalette(void *v)
{
    gScreenWork.src = v;
    DWCi_TSKlForm(1, (void (*)(void *, void *))taskSetPltt, 0, 0x78);
}


/*
 * sdk:      taskSetPltt (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/taskSetPltt.c \n *       --func taskSetPltt --addr 0x021CE844 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void taskSetPltt(void *task)
{
    MIi_CpuCopy16(gScreenWork.src, (void *)HW_BG_PLTT, 0x200);
    DWCi_TSKlDelete(1, task);
}
