/*
 * function: NET_WHPIPE_RefreshBeacon
 * address:  0x021777FC
 * packet:   pkt_ov014_021777FC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   sEmptyString     0x02179790  data   a4
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   NET_WHPIPE_GetConnectedNum  0x02177A74  thumb  ov014
 *   NET_WHPIPE_SetBeaconGameInfo  0x02177D58  thumb  ov014
 */
#include "../include/Obj04955.h"
#include "../include/Obj19331.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
extern u8 sEmptyString[];
extern void *GFL_NET_GetInitParam(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082D44(void *src, void *dst, int n);
extern int NET_WHPIPE_GetConnectedNum(void);
extern void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len);

typedef int (*SizeFn)(u32 a);
typedef u32 (*DataFn)(u32 a);

void NET_WHPIPE_RefreshBeacon(void)
{
    u8 *w = g_pWhPipeWork;
    u8 *e = w + 0xC6E;
    u8 *st = GFL_NET_GetInitParam();
    SizeFn sfn = *(SizeFn *)&((struct Obj19331 *)st)->f1C;
    int n;

    if (sfn != 0) {
        n = sfn(((struct Obj04955 *)w)->fC64);
        if (n > 0x68)
            func_02034714((const char *)sEmptyString, 0, (const char *)sEmptyString);
        func_02082D44((void *)(*(DataFn *)(st + 0x18))(((struct Obj04955 *)w)->fC64), e + 8, n);
    }
    if (e[6] != NET_WHPIPE_GetConnectedNum()) {
        w[0xCF0] = 0;
        e[6] = NET_WHPIPE_GetConnectedNum();
    }
    if (w[0xCF0] == 0) {
        NET_WHPIPE_SetBeaconGameInfo(w + 0xC6E, 0x70);
        w[0xCF0] = 2;
    }
    w[0xCF0]--;
}
