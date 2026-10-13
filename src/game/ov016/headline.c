/*
 * file:     headline.c
 * unit:     yes
 * function: DWCi_HLlInit, DWCi_HLlEnd, DWCi_HLlLoad, DWCi_HLlLoadSet, DWCi_HLlLoadList, taskLoad
 * address:  0x021BD5E8
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
 *   DWCi_HEAPlFree_                0x021D6438  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm  ov016
 *   DWCi_Entry  0x021C0ED8  arm  ov016
 *   GX_LoadBG1Char 0x0207EF90  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   gHeadlineWork     0x021DE554  data
 *   sHeadlinePathJbBgHlChar     0x021DAE54  data
 *   sHeadlineTable     0x021DAE04  data
 *   DWCi_Char        0x021BD170  arm
 *   DWCi_ARClReadEx  0x021D4B68  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   DWCi_ARClRelease 0x021D4C68  arm
 *   DWCi_TSKlForm    0x021D7680  arm
 *   FILE_NAME        0x021DAE04  data  a4
 *   Buffer           0x021DE554  data  a4
 *   taskLoad         0x021BD704  arm
 *   DWCi_SETTIGNlGet             0x021CF404  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 */
extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned int DWCi_Entry(void);
extern void GX_LoadBG1Char(void *, unsigned long, unsigned long);
extern void GX_LoadBG1Scr(void *, unsigned long, unsigned long);
extern void DWCi_HEAPlFree_(void **mem);
char *DWCi_Char(char *name);
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
void MIi_CpuCopyFast(void *srcp, void *destp, unsigned long size);
void DWCi_ARClRelease(void *file);
void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
typedef struct {
    unsigned char pad[0xF4];
    unsigned char idx;
} SETTINGINFO;
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_ScreenDC_FlushRange(void *addr, unsigned long n);
extern void DWCi_TSKlDelete(int kind, void *task);
void DWCi_HLlInit(void);
void DWCi_HLlEnd(void);
void DWCi_HLlLoad(int idx);
void DWCi_HLlLoadSet(void);
void DWCi_HLlLoadList(void);
extern unsigned short *gHeadlineWork;
extern char sHeadlinePathJbBgHlChar[];
extern char *sHeadlineTable[];
extern char *FILE_NAME[20];
extern unsigned short *Buffer;


/*
 * sdk:      DWCi_HLlInit (libdwcutil.TWL.HYB.a headline.o)
 */

static void taskLoad(void *task);
void DWCi_HLlInit(void)
{
    gHeadlineWork = DWCi_HEAPlAllocEx(0xC0, 4);
    DWCi_CMNlLoadResource(sHeadlinePathJbBgHlChar, GX_LoadBG1Char);
    switch (DWCi_Entry()) {
    case 0:
        DWCi_CMNlLoadResource(sHeadlineTable[0], GX_LoadBG1Scr);
        break;
    case 1:
        DWCi_CMNlLoadResource(sHeadlineTable[1], GX_LoadBG1Scr);
        break;
    }
}


/*
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE554.
 * Addresses are Black-image addresses.
 */
void DWCi_HLlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE554);
}


void DWCi_HLlLoad(int idx)
{
    char *n = DWCi_Char(FILE_NAME[idx]);
    void *file = DWCi_ARClReadEx(n, 0, 4);
    MIi_CpuCopyFast(file, Buffer, 0xc0);
    DWCi_ARClRelease(file);
    DWCi_TSKlForm(1, (void (*)(void *, void *))taskLoad, 0, 0x78);
}


void DWCi_HLlLoadSet(void)
{
    DWCi_HLlLoad(DWCi_SETTIGNlGet()->idx + 5);
}


void DWCi_HLlLoadList(void)
{
    DWCi_HLlLoad(DWCi_SETTIGNlGet()->idx + 2);
}


static void taskLoad(void *task)
{
    DWCi_ScreenDC_FlushRange(gHeadlineWork, 0xC0);
    GX_LoadBG1Scr(gHeadlineWork, 0, 0xC0);
    DWCi_TSKlDelete(1, task);
}
