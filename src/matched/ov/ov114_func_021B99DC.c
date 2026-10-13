/*
 * function: NHTTP_RAP_GetResultCode
 * address:  0x021B99DC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NHTTP_GetResultCode  0x021BE880  arm  ov114
 *
 *
 * Forwards the record's +0x0c key to the module query.
 */
#include "../include/Obj22572.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTP_GetResultCode(int);

int NHTTP_RAP_GetResultCode(u8 *p)
{
    if (p != 0)
        return NHTTP_GetResultCode(((struct Obj22572 *)p)->fC);
    return 0;
}
