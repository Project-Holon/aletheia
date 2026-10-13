/*
 * function: GFL_NET_SYSTEM_RecvParentData
 * address:  0x02038924
 * packet:   pkt_020385C4
 * status:   EXACT
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_RING_BUFF_Write  0x02036428  arm
 */
#include "../include/Obj06939.h"
#include "../include/Obj11355.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *lbl_021469D0;
extern int GFL_NET_GetInitParam(void);
extern void GFL_NET_GetChildSendSize(void);
extern u16 func_0203F1FC(u8 *p, s32 n);
extern void GFL_NET_SYSTEM_SetError(void);
extern u8 *GFL_NET_STATE_GetError(void);
extern void GFL_NET_STATE_SetError(u32 a, u32 b, u32 c, u32 d);
extern void GFL_NET_RING_BUFF_Write(u8 *dst, u8 *src, s32 len);

int GFL_NET_SYSTEM_RecvParentData(u32 a0, u8 *p, s32 n)
{
    u8 *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    GFL_NET_GetInitParam();
    GFL_NET_GetChildSendSize();
    g = lbl_021469D0;
    ((struct Obj11355 *)g)->f1B0 = ((struct Obj11355 *)g)->f1B0 - 1;
    if (p == 0)
        return 0;
    if (a0 == 0)
        *(u16 *)(lbl_021469D0 + 0x100 + 0xe4) = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (*(u32 *)(lbl_021469D0 + 0x34) == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC(p + 2, n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        GFL_NET_SYSTEM_SetError();
        q = GFL_NET_STATE_GetError();
        if (((struct Obj06939 *)q)->fC == 0)
            GFL_NET_STATE_SetError(((struct Obj06939 *)q)->f0, ((struct Obj06939 *)q)->f4, ((struct Obj06939 *)q)->f8, 0x3f2);
        return 0;
    }
    *(u8 *)(lbl_021469D0 + 0x1d6) = p[5];
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    GFL_NET_RING_BUFF_Write(lbl_021469D0 + 0x2c, p + 7, len);
    *(u32 *)(lbl_021469D0 + 0x34) = 1;
    return 1;
}
