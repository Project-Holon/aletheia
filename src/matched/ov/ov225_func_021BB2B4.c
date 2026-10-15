/*
 * function: MANUAL_COMMON_CreateDialog
 * address: 0x021BB2B4
 * packet: pkt_ov225_021BB2B4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BB4F8 retains original visible r0 context although its fixed tail ignores it.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   gManualCommonDialogAllocFile 0x021BC038 data a1
 *   MANUAL_COMMON_LoadDialogAssets 0x021BB400 thumb ov225
 *   MANUAL_COMMON_SetDialogBgMode 0x021BB4F8 thumb ov225
 *   MANUAL_COMMON_DialogTaskNoop 0x021BB3FC thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   MANUAL_COMMON_SetTouchbarState 0x021BA068 thumb ov225
 */
#include "../include/Obj05574.h"
#include "../include/Obj26227.h"
#include "../include/Obj26228.h"
#include "../include/Obj26229.h"
typedef unsigned short u16;
extern const char gManualCommonDialogAllocFile[];
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void MANUAL_COMMON_LoadDialogAssets(char *);
extern void MANUAL_COMMON_SetDialogBgMode(char *);
extern void MANUAL_COMMON_DialogTaskNoop(void *);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void MANUAL_COMMON_SetTouchbarState(char *, unsigned);
char *MANUAL_COMMON_CreateDialog(char *p, char *data)
{
    char *q;
    q = func_02030734(((struct Obj26227 *)data)->f4, 32, 1, gManualCommonDialogAllocFile, 157);
    *(char * *)&((struct Obj05574 *)q)->f0 = p;
    ((struct Obj26228 *)p)->f4 = 1;
    *(char * *)&((struct Obj05574 *)q)->f4 = data;
    MANUAL_COMMON_LoadDialogAssets(q);
    MANUAL_COMMON_SetDialogBgMode(q);
    ((struct Obj05574 *)q)->f14 = func_020056A0((unsigned)MANUAL_COMMON_DialogTaskNoop, (unsigned)q, 1);
    ((struct Obj05574 *)q)->f18 = 0;
    q[0x1c] = -1;
    MANUAL_COMMON_SetTouchbarState(*(char * *)&((struct Obj26229 *)(*(char * *)&((struct Obj05574 *)q)->f4))->f34, 0);
    return q;
}
