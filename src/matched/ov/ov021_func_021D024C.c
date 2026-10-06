/*
 * function: func_021D024C
 * address:  0x021D024C
 * packet:   pkt_ov021_021D024C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Highlights button sel of four and records it.
 *
 * symbols:
 *   func_021AC1E0  0x021AC1E0  thumb
 *   func_02047804  0x02047804  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06104.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021AC1E0(u32 a);
struct AnmCtl;
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
struct G3dSys;
struct Owner;
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_020477D4(struct Owner *owner, u32 index);

void func_021D024C(void *obj, u32 sel)
{
    int i;
    u8 *q;

    if (obj == 0)
        return;
    q = (u8 *)func_021AC1E0((u32)obj);
    for (i = 0; i < 4; i++) {
        func_02047804((struct AnmCtl *)(((struct Obj06104 *)q)->fC), (u16)i);
        if (i == sel)
            func_020477A4((struct G3dSys *)(((struct Obj06104 *)q)->fC), (u16)i);
        else
            func_020477D4((struct Owner *)(((struct Obj06104 *)q)->fC), (u16)i);
    }
    q[2] = sel;
    q[3] = 0;
}
