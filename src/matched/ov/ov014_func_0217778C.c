/*
 * function: func_0217778C
 * address:  0x0217778C
 * packet:   pkt_ov014_0217778C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_02088234  0x02088234  arm
 *   func_02082D44  0x02082D44  arm
 *   NET_WHPIPE_SetBeaconGameInfo  0x02177D58  thumb  ov014
 */
#include "../include/Obj07354.h"
#include "../include/Obj09380.h"
#include "../include/Obj09381.h"
#include "../include/G_W.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern struct W *g_pWhPipeWork;
extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern void func_02088234(void);
extern void func_02082D44(void *src, void *dst, int n);
extern void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len);

typedef int (*SizeFn)(u32 a);
typedef u32 (*DataFn)(u32 a);

void func_0217778C(void)
{
    u8 *e;
    u8 *st;
    u8 *w;
    SizeFn sfn;
    int n;

    if (GFL_NET_GetRunState() == 0)
        return;
    w = ((u8 *)g_pWhPipeWork);
    st = GFL_NET_GetInitParam();
    sfn = *(SizeFn *)&((struct Obj09380 *)st)->f1C;
    if (sfn == 0)
        return;
    n = sfn(((struct Obj09381 *)w)->fC64);
    if (n >= 0x68) {
        func_02088234();
        return;
    }
    e = w + 0xC6E;
    e[4] = st[0x67];
    ((struct Obj07354 *)e)->f2 = ((struct Obj09380 *)st)->f50;
    e[5] = 0;
    e[7] = w[0xCEA];
    func_02082D44((void *)(*(DataFn *)(st + 0x18))(((struct Obj09381 *)w)->fC64), e + 8, n);
    NET_WHPIPE_SetBeaconGameInfo(w + 0xC6E, 0x70);
}
