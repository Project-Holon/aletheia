/*
 * file:     step.c
 * unit:     yes
 * function: DWCi_STEPlBegin, taskBegin0, taskBegin1, taskBegin2, taskBegin3, taskBegin4, taskBegin5, DWCi_STEPlEnd, DWCi_STEPlChange, DWCi_STEPlGet, taskEnd0, taskEnd1, taskEnd2, taskEnd3, taskEnd4, DWCi_STEPlIsEnd, DWCi_STEPlChangeScr, taskChange
 * address:  0x021D0040
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
 *   DWCi_STEPlChangeScr              0x021D0AB0  arm
 *   DWCi_STEPlIsEnd                  0x021D0A84  arm
 *   DWCi_TSKlChangeFunc              0x021D771C  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   .bss                             0x021DE64C  data
 *   File                             0x021DE64C  data
 *   FILE_NAME                        0x021DB950  data
 *   GXS_LoadBG1Scr                   0x0207EABC  arm
 *   MemStep                          0x021DE650  data
 *   PL_CELL                          0x021DA923  data
 *   taskChange                       0x021D0AFC  arm
 *   taskEnd0                         0x021D06A4  arm
 *   taskEnd1                         0x021D0734  arm
 *   taskEnd2                         0x021D0808  arm
 *   taskEnd3                         0x021D08DC  arm
 *   taskEnd4                         0x021D09B0  arm
 */
typedef _Bool bool;

#include "dwcutil_types.h"

#include "gx_oam_types.h"

/* step.o's work area; no DWARF type reaches it, the layout is from the accesses:
   0x1C bytes allocated, five cells, the running task, the ending flag. */
typedef struct tagMEMSTEP {
    void *cell[5];                    /* 0x00 */
    void *task;                       /* 0x14 */
    bool  end;                        /* 0x18 */
} MEMSTEP;

#include "heap.h"
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
#include "cellinfo.h"
struct CellInfo;
union GXOamAttr;
#include "cell.h"
struct CellInfo;
struct TCB;
#include "task.h"
#include "sound.h"
#include "common.h"
#include "archive.h"
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
void DWCi_STEPlChangeScr(int step);
void DWCi_STEPlBegin(int step);
void DWCi_STEPlEnd(void);
void DWCi_STEPlChange(int step);
/* step.o .bss at 0x021DE64C: File first, then MemStep (the initializers register them in this order) */
static void *File = 0;
static MEMSTEP *MemStep = 0;
/* step.o .rodata (the dump prints DWARF dimensions reversed: rows are five bytes) */
extern const unsigned char CELL_IDX[3][5];
extern const unsigned char PL_CELL[3][5];
extern const COORD C_POS[5];
/* step.o .data */
extern char *FILE_NAME[5];

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


void DWCi_STEPlBegin(int step)
{
    int i;

    MemStep = DWCi_HEAPlAllocEx(sizeof(MEMSTEP), 4);
    for (i = 0; i < 5; i++) {
        MemStep->cell[i] = DWCi_CEINlSetExCell(1, CELL_IDX[step][i], 1);
        DWCi_CELLlSetPriority(MemStep->cell[i], -1, 0);
        DWCi_CELLlSetPosition(MemStep->cell[i], -1, -42, C_POS[i].y);
        DWCi_CELLlSetPalette(MemStep->cell[i], -1, 0, PL_CELL[step][i]);
    }
    MemStep->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskBegin0, 0, 0x78);
    DWCi_STEPlChangeScr(step);
    DWCi_SNDlPlay(13);
}


static void taskBegin0(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[0], 0, &x, &y);
    x += 8;
    if (x < 32 || x > 256) {
        for (i = 0; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 32;
        for (i = 0; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskBegin1);
    }
}


static void taskBegin1(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[1], 0, &x, &y);
    x += 8;
    if (x < 80 || x > 256) {
        for (i = 1; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 80;
        for (i = 1; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskBegin2);
    }
}


static void taskBegin2(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[2], 0, &x, &y);
    x += 8;
    if (x < 104 || x > 256) {
        for (i = 2; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 104;
        for (i = 2; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskBegin3);
    }
}


static void taskBegin3(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[3], 0, &x, &y);
    x += 8;
    if (x < 152 || x > 256) {
        for (i = 3; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 152;
        for (i = 3; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskBegin4);
    }
}


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
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskBegin5);
    }
}


static void taskBegin5(void *task)
{
    DWCi_TSKlDelete(0, task);
    MemStep->task = 0;
}


void DWCi_STEPlEnd(void)
{
    MemStep->end = 1;
    MemStep->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskEnd0, 0, 0x78);
}


void DWCi_STEPlChange(int step)
{
    int i;

    for (i = 0; i < 5; i += 2) {
        DWCi_CEINlSet(1, CELL_IDX[step][i], DWCi_CELLlGetObj(MemStep->cell[i], 0));
        DWCi_CELLlSetPriority(MemStep->cell[i], -1, 0);
        DWCi_CELLlSetPosition(MemStep->cell[i], -1, C_POS[i].x, C_POS[i].y);
        DWCi_CELLlSetPalette(MemStep->cell[i], -1, 0, PL_CELL[step][i]);
    }
    DWCi_STEPlChangeScr(step);
}

/*
 * True when field +0x14 of the object behind the pointer is non-zero.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_STEPlGet.c \
 *       --func DWCi_STEPlGet --addr 0x021D0684 --region ov016 --cc dsi/1.1p1 --arm
 */
int DWCi_STEPlGet(void)
{
    char **p = (char **)0x021DE64C;
    unsigned int *q = (unsigned int *)(p[1] + 0x14);
    return *q != 0;
}


static void taskEnd0(void *task)
{
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[4], 0, &x, &y);
    x -= 8;
    if (x > 152) {
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
    } else {
        x = 152;
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd1);
    }
}


static void taskEnd1(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[3], 0, &x, &y);
    x -= 8;
    if (x > 104) {
        for (i = 3; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 104;
        for (i = 3; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd2);
    }
}


static void taskEnd2(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[2], 0, &x, &y);
    x -= 8;
    if (x > 80) {
        for (i = 2; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 80;
        for (i = 2; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd3);
    }
}


static void taskEnd3(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[1], 0, &x, &y);
    x -= 8;
    if (x > 32) {
        for (i = 1; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 32;
        for (i = 1; i < 5; i++)
            DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, (void (*)(void *, void *))taskEnd4);
    }
}


static void taskEnd4(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[0], 0, &x, &y);
    x -= 8;
    for (i = 0; i < 5; i++)
        DWCi_CELLlSetPosition(MemStep->cell[i], -1, x, C_POS[i].y);
    if (x <= 470 && x >= 256) {
        DWCi_TSKlDelete(0, task);
        for (i = 0; i < 5; i++)
            DWCi_CELLlDelete(MemStep->cell[i]);
        DWCi_HEAPlFree_((void **)&MemStep);
    }
}


bool DWCi_STEPlIsEnd(void)
{
    if (MemStep == 0)
        return 1;
    return MemStep->end == 0;
}


void DWCi_STEPlChangeScr(int step)
{
    char *n = (char *)DWCi_Char((unsigned char *)FILE_NAME[step]);

    File = DWCi_ARClReadEx(n, 0, 4);
    DWCi_TSKlForm(1, (void (*)(void *, void *))taskChange, 0, 0x78);
}


static void taskChange(void *task)
{
    DC_FlushRange(File, 0x600);
    GXS_LoadBG1Scr(File, 0, 0x600);
    DWCi_ARClRelease(File);
    DWCi_TSKlDelete(1, task);
}
