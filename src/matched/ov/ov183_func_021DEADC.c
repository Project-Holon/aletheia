/*
 * function: BR_CODEIN_StatMain
 * address: 0x021DEADC
 * packet: pkt_ov183_021DEADC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 */
#include "../include/Obj02521.h"
#include "../include/Obj24585.h"
#include "../include/Obj24586.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern int BR_NET_HandleNetError(char *p);
extern void BR_PROC_SYS_FlushWindows(void *);
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *p);
extern void BR_UTIL_RunHandles(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int BR_UTIL_FlushText(u8 *p);
extern void BR_UTIL_FlushWindow(void *);
int BR_CODEIN_StatMain(int a, int b, int c, char *p)
{
    int i;
    if (BR_NET_HandleNetError(((struct Obj24585 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f18) == 2) {
        BR_PROC_SYS_FlushWindows(((struct Obj24586 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f14);
        return 1;
    }
    BR_UTIL_RunTask(((struct Obj02521 *)p)->f10);
    if (BR_UTIL_IsTaskIdle(((struct Obj02521 *)p)->f10) != 0) return 1;
    for (i = 0; i < 2; i++) BR_UTIL_RunHandles(*(void **)(p + 0x1C + i * 4));
    PRINTSYS_QUE_Main(((struct Obj02521 *)p)->f14);
    if (((struct Obj02521 *)p)->f8 != 0) BR_UTIL_FlushText(((struct Obj02521 *)p)->f8);
    if (((struct Obj02521 *)p)->fC != 0) BR_UTIL_FlushText(((struct Obj02521 *)p)->fC);
    if (((struct Obj02521 *)p)->f24 != 0) BR_UTIL_FlushWindow(((struct Obj02521 *)p)->f24);
    return 0;
}
