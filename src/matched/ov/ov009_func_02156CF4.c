/*
 * unit:     yes
 * function: DWC_RAP_FlushDeletedFriends, DWC_RAP_GetResult, DWC_RAP_StoreAllowConnect
 * address:  0x02156CF4
 * packet:   pkt_ov009_02156CF4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0203D798  0x0203D798  arm
 *   func_0203D650  0x0203D650  arm
 */
#include "../include/Obj18656.h"
#include "../include/Obj18657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void *func_0203D798(void);
extern u32 func_0203D650(void);

void DWC_RAP_FlushDeletedFriends(void)
{
    volatile int off2 = 0x17c;
    int i;
    i = 0;
    off2 = 0x1fc;
    for (; i < 32; i++) {
        if (*(int *)(g_021A8264 + i * 4 + 0x17c) != -1) {
            u8 *p = func_0203D798();
            if (((struct Obj18656 *)p)->f3C != 0) {
                u8 *q = g_021A8264 + i * 4;
                u32 r = func_0203D650();
                ((void (*)(u32, u32, u32))*(u32 *)(p + 0x3c))(((struct Obj18657 *)q)->f17C, *(u32 *)(q + off2), r);
            }
            *(int *)(g_021A8264 + i * 4 + 0x17c) = -1;
        }
    }
}

u32 DWC_RAP_GetResult(void)
{
    return *(u32 *)(g_021A8264 + 0x758);
}

void DWC_RAP_StoreAllowConnect(u32 v)
{
    g_021A8264[0x7a5] = v;
}
