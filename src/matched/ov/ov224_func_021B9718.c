/*
 * function: SUBWAY_MAP_GRAPHIC_Exit
 * address: 0x021B9718
 * packet: pkt_ov224_021B9718
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum do-loop with unsigned bound retains one table iteration; unsigned for-loop folds it, enum for-loop adds an entry guard.
 * volatile: sub-display blend/control reads and writes 021B973C-021B9746.
 * symbols:
 *   gSubwayMapGraphicSubBgLayerTable 0x021B9C04 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets 0x021B9898 thumb ov224
 *   SUBWAY_MAP_GRAPHIC_DeleteScreen 0x021B99E8 thumb ov224
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj06730.h"
typedef enum { ZERO=0, ONE=1 } Index;
typedef struct { unsigned id; char fields[32]; unsigned a,b; } Entry;
extern const Entry gSubwayMapGraphicSubBgLayerTable[];
typedef unsigned int   u32;
struct Node;
struct PrintSys;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets(char *),SUBWAY_MAP_GRAPHIC_DeleteScreen(char *);
struct Proc;
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int SUBWAY_MAP_GRAPHIC_Exit(void *a,int b,int c,char *p)
{
    Index i=ZERO;
    do { BG_SYS_FreeLayerBuf((unsigned char)gSubwayMapGraphicSubBgLayerTable[i].id); i++; } while(i<1U);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=~0xe000;
    SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets(p);
    func_02030EAC(((struct Obj06730 *)p)->f14); PRINTSYS_QUE_Clear(((struct Obj06730 *)p)->f10); PRINTSYS_QUE_Delete(((struct Obj06730 *)p)->f10);
    GF_FONT_Delete(((struct Obj06730 *)p)->fC); SUBWAY_MAP_GRAPHIC_DeleteScreen(*(char * *)&((struct Obj06730 *)p)->f8);
    func_020315D4(a); GFL_HEAP_DeleteChecked(136);
    return 1;
}
