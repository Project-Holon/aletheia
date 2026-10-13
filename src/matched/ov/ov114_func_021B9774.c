/*
 * function: NHTTP_RAP_DeleteConnection
 * address:  0x021B9774
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NHTTP_Cleanup  0x021BE698  arm  ov114
 *   NHTTP_DeleteConnection  0x021BF184  arm  ov114
 *
 *
 * Releases the record's +0x0c handle and re-arms the module.
 */
#include "../include/Obj03763.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTP_DeleteConnection(int a);
extern void NHTTP_Cleanup(void);

void NHTTP_RAP_DeleteConnection(u8 *p)
{
    if (p == 0)
        return;
    if (((struct Obj03763 *)p)->fC == 0)
        return;
    NHTTP_DeleteConnection(((struct Obj03763 *)p)->fC);
    ((struct Obj03763 *)p)->fC = 0;
    NHTTP_Cleanup();
}
