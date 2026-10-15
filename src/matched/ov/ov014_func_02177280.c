/*
 * function: NET_WHPIPE_Create
 * address:  0x02177280
 * packet:   pkt_ov014_02177280
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   sFileNetWhPipe     0x02179780  data   a1
 *   func_02030734  0x02030734  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   WM_GetNextTgid  0x0208F1B4  arm
 *   WIH_Initialize  0x021790E4  thumb  ov014
 *   WIH_SetGgid  0x02178E1C  thumb  ov014
 */
#include "../include/Obj05921.h"
#include "../include/Obj19326.h"
#include "../include/G_W.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern struct W *g_pWhPipeWork;
extern char sFileNetWhPipe[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GFL_NET_GetInitParam(void);
extern u16 WM_GetNextTgid(void);
extern int WIH_Initialize(u32 heap, int a, int b);
extern void WIH_SetGgid(u32 v);

int NET_WHPIPE_Create(int a, int b, u32 c, int d)
{
    u8 *st;
    u8 *w;

    GFL_NET_GetInitParam();
    st = GFL_NET_GetInitParam();
    if (((u8 *)g_pWhPipeWork) != 0)
        return 0;
    w = func_02030734(a, 0xCF8, 1, sFileNetWhPipe, 0xed);
    g_pWhPipeWork = (struct W *)(w);
    w[0xCE6] = 0xff;
    if (WIH_Initialize(a, b, d) == 0)
        return 0;
    WIH_SetGgid(((struct Obj19326 *)st)->f50);
    ((struct Obj05921 *)w)->fC64 = c;
    w[0xCE7] = 0;
    w[0xCE4] = 0;
    ((struct Obj05921 *)w)->fC68 = WM_GetNextTgid();
    return 1;
}
