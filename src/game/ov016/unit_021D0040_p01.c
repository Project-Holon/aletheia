/*
 * file:     unit_021D0040_p01.c
 * unit:     yes
 * function: DWCi_STEPlBegin, taskBegin0, taskBegin1, taskBegin2, taskBegin3, taskBegin4, taskBegin5, DWCi_STEPlEnd, DWCi_STEPlChange
 * address:  0x021D0040
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
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
 *   FILE_NAME                        0x021DB950  data
 *   GXS_LoadBG1Scr                   0x0207EABC  arm
 *   PL_CELL                          0x021DA923  data
 *   step_bss                         0x021DE64C  data
 *   taskChange                       0x021D0AFC  arm
 *   taskEnd0                         0x021D06A4  arm
 *   taskEnd1                         0x021D0734  arm
 *   taskEnd2                         0x021D0808  arm
 *   taskEnd3                         0x021D08DC  arm
 *   taskEnd4                         0x021D09B0  arm
 *   _ZZ10taskBegin4PvE4File          0x021DE64C  data
 *   _ZZ10taskBegin4PvE7MemStep_0     0x021DE650  data
 */
typedef _Bool bool;

typedef struct tagCOORD { unsigned short x, y; } COORD;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

/* step.o's work area; no DWARF type reaches it, the layout is from the accesses:
   0x1C bytes allocated, five cells, the running task, the ending flag. */
typedef struct tagMEMSTEP {
    void *cell[5];                    /* 0x00 */
    void *task;                       /* 0x14 */
    bool  end;                        /* 0x18 */
} MEMSTEP;

/* step.o .bss at 0x021DE64C: the two file statics File and MemStep */
typedef struct {
    void    *file;                    /* 0x00 */
    MEMSTEP *memStep;                 /* 0x04 */
} STEP_BSS;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CELLlDelete(void *cell);
extern void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPalette(void *cell, int idx, int mode, int plt);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_TSKlChangeFunc(void *task, void (*func)(void *));
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_SNDlPlay(int no);
extern char *DWCi_Char(char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void DWCi_ARClRelease(void *file);
extern void DC_FlushRange(void *startAddr, unsigned long nBytes);
extern void GXS_LoadBG1Scr(const void *src, unsigned long offset, unsigned long size);
void DWCi_STEPlChangeScr(int step);
void DWCi_STEPlBegin(int step);
void DWCi_STEPlEnd(void);
void DWCi_STEPlChange(int step);
extern STEP_BSS step_bss;
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

    step_bss.memStep = DWCi_HEAPlAllocEx(sizeof(MEMSTEP), 4);
    for (i = 0; i < 5; i++) {
        step_bss.memStep->cell[i] = DWCi_CEINlSetExCell(1, CELL_IDX[step][i], 1);
        DWCi_CELLlSetPriority(step_bss.memStep->cell[i], -1, 0);
        DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, -42, C_POS[i].y);
        DWCi_CELLlSetPalette(step_bss.memStep->cell[i], -1, 0, PL_CELL[step][i]);
    }
    step_bss.memStep->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskBegin0, 0, 0x78);
    DWCi_STEPlChangeScr(step);
    DWCi_SNDlPlay(13);
}










static void taskBegin0(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(step_bss.memStep->cell[0], 0, &x, &y);
    x += 8;
    if (x < 32 || x > 256) {
        for (i = 0; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 32;
        for (i = 0; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, taskBegin1);
    }
}









static void taskBegin1(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(step_bss.memStep->cell[1], 0, &x, &y);
    x += 8;
    if (x < 80 || x > 256) {
        for (i = 1; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 80;
        for (i = 1; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, taskBegin2);
    }
}








static void taskBegin2(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(step_bss.memStep->cell[2], 0, &x, &y);
    x += 8;
    if (x < 104 || x > 256) {
        for (i = 2; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 104;
        for (i = 2; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, taskBegin3);
    }
}







static void taskBegin3(void *task)
{
    int i;
    int x;
    int y;

    DWCi_CELLlGetPosition(step_bss.memStep->cell[3], 0, &x, &y);
    x += 8;
    if (x < 152 || x > 256) {
        for (i = 3; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
    } else {
        x = 152;
        for (i = 3; i < 5; i++)
            DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, x, C_POS[i].y);
        DWCi_TSKlChangeFunc(task, taskBegin4);
    }
}







static void taskBegin4(void *task)
{
    static void *File;
    static MEMSTEP *MemStep;
    int x;
    int y;

    DWCi_CELLlGetPosition(MemStep->cell[4], 0, &x, &y);
    x += 8;
    if (x < 176 || x > 256) {
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
    } else {
        x = 176;
        DWCi_CELLlSetPosition(MemStep->cell[4], -1, x, 33);
        DWCi_TSKlChangeFunc(task, taskBegin5);
    }
}





static void taskBegin5(void *task)
{
    DWCi_TSKlDelete(0, task);
    step_bss.memStep->task = 0;
}




void DWCi_STEPlEnd(void)
{
    step_bss.memStep->end = 1;
    step_bss.memStep->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskEnd0, 0, 0x78);
}



void DWCi_STEPlChange(int step)
{
    int i;

    for (i = 0; i < 5; i += 2) {
        DWCi_CEINlSet(1, CELL_IDX[step][i], DWCi_CELLlGetObj(step_bss.memStep->cell[i], 0));
        DWCi_CELLlSetPriority(step_bss.memStep->cell[i], -1, 0);
        DWCi_CELLlSetPosition(step_bss.memStep->cell[i], -1, C_POS[i].x, C_POS[i].y);
        DWCi_CELLlSetPalette(step_bss.memStep->cell[i], -1, 0, PL_CELL[step][i]);
    }
    DWCi_STEPlChangeScr(step);
}
