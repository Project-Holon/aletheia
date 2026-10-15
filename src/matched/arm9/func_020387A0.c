/*
 * function: GFL_NET_SYSTEM_RecvChildData
 * address:  0x020387A0
 * packet:   pkt_020387A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The indexed twin of src/matched/GFL_NET_SYSTEM_RecvParentData.c (the own-slot variant):
 * same receive/validate/copy shape, but every global offset is scaled by
 * the slot index -- the 0x1B4 credit counter by i*4, the 0x54 accepted
 * flag and the 0x4C payload by i*16, the 0x1D7 sequence byte by i.  The
 * extra middle block this one has and 0x02038924 does not is the sequence
 * check at 0x1D7+i with its own 0x3F3 error line.
 *
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_RING_BUFF_Write  0x02036428  arm
 */
#include "../include/Obj03449.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *lbl_021469D0;
extern u32 GFL_NET_GetChildSendSize(void);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern void GFL_NET_SYSTEM_SetError(void);
extern u32 GFL_NET_STATE_GetError(void);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern void GFL_NET_RING_BUFF_Write(u8 *dst, u8 *src, s32 len);

int GFL_NET_SYSTEM_RecvChildData(u32 i, u8 *p, s32 n)
{
    u8 *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    GFL_NET_GetChildSendSize();
    if (p == 0)
        return 0;
    g = lbl_021469D0;
    *(u32 *)(g + 0x1b4 + i * 4) = *(u32 *)(g + 0x1b4 + i * 4) - 1;
    if (i == 0)
        *(u16 *)(lbl_021469D0 + 0x100 + 0xe4) = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (*(u32 *)(lbl_021469D0 + i * 16 + 0x54) == 0) {
        if (v & 2)
            return 0;
    }
    r = GF_STANDARD_SetupCalc(p + 2, n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        GFL_NET_SYSTEM_SetError();
        q = (u8 *)GFL_NET_STATE_GetError();
        if (((struct Obj03449 *)q)->fC == 0)
            GFL_NET_STATE_SetError(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f2);
        return 0;
    }
    {
        u8 *s = lbl_021469D0 + 0xd7 + 0x100;
        if (s[i] != 0 && (u8)(p[5] - 1) != s[i]) {
            GFL_NET_SYSTEM_SetError();
            q = (u8 *)GFL_NET_STATE_GetError();
            if (((struct Obj03449 *)q)->fC == 0)
                GFL_NET_STATE_SetError(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f3);
            return 0;
        }
        s[i] = p[5];
    }
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    GFL_NET_RING_BUFF_Write(lbl_021469D0 + 0x4c + i * 16, p + 7, len);
    *(u32 *)(lbl_021469D0 + i * 16 + 0x54) = 1;
    return 1;
}
