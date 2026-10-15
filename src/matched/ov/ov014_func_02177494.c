/*
 * function: NET_WHPIPE_CheckBeaconFlags
 * address:  0x02177494
 * packet:   pkt_ov014_02177494
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  a4
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 */
#include "../include/Obj04174.h"
#include "../include/Obj07353.h"
#include "../include/Obj19328.h"
#include "../include/G_W.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
void *GFL_NET_GetInitParam(void);
u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

typedef int (*CheckFn)(u8 a, u8 b, u32 c);

int NET_WHPIPE_CheckBeaconFlags(u8 *obj, u32 flags)
{
    u8 *base = ((u8 *)g_pWhPipeWork);
    u8 *st = GFL_NET_GetInitParam();
    int v67 = st[0x67];
    u16 v50 = ((struct Obj07353 *)st)->f50;
    u8 *p = obj + 0x50;
    CheckFn fn;

    if ((flags & 1) && p[7] != 0)
        return 0;
    if ((flags & 2) && p[5] != 0)
        return 0;
    if ((flags & 4) && ((struct Obj04174 *)p)->f0 != GF_STANDARD_SetupCalc(p + 2, 0x6e))
        return 0;
    if ((flags & 8) && ((struct Obj04174 *)p)->f2 != v50)
        return 0;
    if (flags & 0x10) {
        fn = *(CheckFn *)&((struct Obj07353 *)st)->f20;
        if (fn != 0) {
            if (fn(v67, p[4], ((struct Obj19328 *)base)->fC64) == 0)
                return 0;
        } else if (v67 != p[4]) {
            return 0;
        }
    }
    if ((flags & 0x20) && p[6] >= st[0x60])
        return 0;
    return 1;
}
