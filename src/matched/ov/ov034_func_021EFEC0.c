/*
 * function: REPORT_Create
 * address:  0x021EFEC0
 * packet:   pkt_ov034_021EFEC0
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_Create 0x021EFEC0 thumb
 *   func_02030734 0x02030734 arm
 *   sReportAllocSite    0x021F0B20 data ov034 a1
 *   REPORT_InitBgs 0x021F0114 thumb ov034
 *   REPORT_LoadBgGraphics 0x021F0228 thumb ov034
 *   REPORT_InitActors 0x021F0724 thumb ov034
 *   REPORT_InitWindows 0x021F0284 thumb ov034
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   REPORT_UpdateSaveAnim 0x021F09BC thumb ov034
 */
#include "../include/Obj00166.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char sReportAllocSite[];
extern void REPORT_InitBgs(u32 heapId);
extern void REPORT_LoadBgGraphics(int);
typedef unsigned char  u8;
extern void REPORT_InitActors(int *p);
extern void REPORT_InitWindows(u8 *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int func_020056A0(void *, void *, int);
extern void REPORT_UpdateSaveAnim(void *task, char *p);

void *REPORT_Create(int a0, int a1)
{
    char *p = (char *)func_02030734(a1, 0x130, 0, sReportAllocSite, 0x114);
    *(int *)&((struct Obj00166 *)p)->f0 = a0;
    ((struct Obj00166 *)p)->f12C = a1;
    ((struct Obj00166 *)p)->f110 = 0;
    ((struct Obj00166 *)p)->f128 = 0;
    REPORT_InitBgs(((struct Obj00166 *)p)->f12C);
    REPORT_LoadBgGraphics(((struct Obj00166 *)p)->f12C);
    REPORT_InitActors((int *)p);
    REPORT_InitWindows((u8 *)p);
    GFL_NET_RestartWithDefaultTimeout(0, a1);
    ((struct Obj00166 *)p)->f10C = func_020056A0(REPORT_UpdateSaveAnim, p, 0);
    return p;
}
