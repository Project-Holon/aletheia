/*
 * function: UNION_EFF_CreateIconObj
 * address:  0x0217FC64
 * packet:   pkt_ov019_0217FC64
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The reload of out[1] before the last call is spelled with a volatile read.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04188.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);

void UNION_EFF_CreateIconObj(char *self, u32 *out, u32 a2, u16 a3, int flag)
{
    u32 *q;

    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj04188 *)out)->f10 = a3;
    if (flag == 0) {
        q = (u32 *)(self + 0xc8);
    } else {
        q = (u32 *)(self + 0xcc);
    }
    out[1] = (u32)G3D_SYSTEM_CreateRender((void *)(*q), 0, (void *)(*q));
    out[3] = (u32)G3D_SYSTEM_CreateObject(*(volatile u32 *)&out[1], 0, 0);
}
