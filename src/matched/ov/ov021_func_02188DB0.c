/*
 * function: FIELDMAP_ResetBgAffineShowMsg
 * address:  0x02188DB0
 * packet:   pkt_ov021_02188DB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_RotScaleMtx22  0x02051E74  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_0204044C  0x0204044C  arm
 *   FIELD_MSGBG_SetupBg  0x02190270  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19493.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Mtx22;
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(u32 a, void *buf, u32 b, u32 c, u32 d, u32 e);
extern void func_0204044C(u32 a);
extern void FIELD_MSGBG_SetupBg(u32 a);

void FIELDMAP_ResetBgAffineShowMsg(u8 *a)
{
    u32 buf[4];

    BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)buf, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, buf, 0, 0, 0, 0);
    func_0204044C(3);
    FIELD_MSGBG_SetupBg(((struct Obj19493 *)a)->f28);
}
