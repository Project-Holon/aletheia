/*
 * function: func_021D8F3C
 * address:  0x021D8F3C
 * packet:   pkt_021D8F3C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NHTTP_RAP_DeleteConnection  0x021B9774  thumb  ov114
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08115.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void NHTTP_RAP_Destroy(u8 *p);

void func_021D8F3C(char *p)
{
    if (*(u32 *)&((struct Obj08115 *)p)->f10 != 0) {
        NHTTP_RAP_DeleteConnection(((struct Obj08115 *)p)->f10);
        NHTTP_RAP_Destroy(((struct Obj08115 *)p)->f10);
        *(u32 *)&((struct Obj08115 *)p)->f10 = 0;
    }
}
