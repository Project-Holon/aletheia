/*
 * function: taskLoad
 * address:  0x021D5BC0
 * packet:   pkt_ov016_021D5BC0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskLoad (font.o)
 *
 * Closed (w5_nm): written from the DWARF (bool *renew, MemFont->bg[n] and the
 * renew[0] address test) instead of raw offsets; that gives the object's r5/r6
 * roles.  The object reads `work` from r1: the DWARF lists only `work`, so the
 * task callback's first argument is unnamed in the vendor source and is spelled
 * `task` here.
 *
 * symbols:
 *   DC_FlushRange                  0x020862F0  arm
 *   GX_LoadBG0Char                  0x0207EE68  arm
 *   func_0207EEFC                  0x0207EEFC  arm
 *   gFontWork                     0x021DE680  data
 */

typedef unsigned char bool;

typedef struct tagCANVAS {
    char pad0[0x28];
    void *buffer;
    char pad1[4];
} CANVAS;

typedef struct tagMEMFONT {
    char font[0x10];
    CANVAS canvas[32];
    CANVAS bg[2];
    void *unused;
    void *file[2];
    bool renew[2];
} MEMFONT;

extern void DC_FlushRange(void *startAddr, unsigned long nBytes);
extern void GX_LoadBG0Char(void *pSrc, unsigned long offset, unsigned long szByte);
extern void func_0207EEFC(void *pSrc, unsigned long offset, unsigned long szByte);

extern MEMFONT *gFontWork;

void taskLoad(void *task, void *work)
{
    bool *renew = (bool *)work;

    if (!*renew)
        return;
    if (renew == &gFontWork->renew[0]) {
        DC_FlushRange(gFontWork->bg[0].buffer, 0x6000);
        GX_LoadBG0Char(gFontWork->bg[0].buffer, 0, 0x6000);
    } else {
        DC_FlushRange(gFontWork->bg[1].buffer, 0x3000);
        func_0207EEFC(gFontWork->bg[1].buffer, 0x3000, 0x3000);
    }
    *renew = 0;
}
