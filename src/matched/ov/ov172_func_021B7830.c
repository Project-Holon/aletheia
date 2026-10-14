/*
 * function: CTVT_CAMVIEW_GetSlotBuffer
 * address:  0x021B7830
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scaled offset: CTVT_CAMVIEW_GetSlotBufferStep's value times a2 when the state probe passes and a2 is non-zero.
 *
 * symbols:
 *   CTVT_CAMVIEW_GetSlotBufferStep  0x021B785C  thumb  ov172
 *   COMM_TVT_SYS_GetLayoutMode  0x021BE05C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06553.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 CTVT_CAMVIEW_GetSlotBufferStep(void *p);
extern int COMM_TVT_SYS_GetLayoutMode(void *p);

int CTVT_CAMVIEW_GetSlotBuffer(void *a0, char *a1, int a2)
{
    int n = (int)CTVT_CAMVIEW_GetSlotBufferStep(a0);

    if (COMM_TVT_SYS_GetLayoutMode(a0) == 1 && a2 != 0)
        return ((struct Obj06553 *)a1)->f4 + n;
    return ((struct Obj06553 *)a1)->f4 + n * a2;
}
