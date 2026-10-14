/*
 * function: COMM_TVT_SYS_CreateTimeIcon
 * address:  0x021BE318
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Rebuilds the +0x1dc record from the +0x1d8 source, retiring the old one first.
 *
 * symbols:
 *   COMM_TVT_SYS_DeleteTimeIcon  0x021BE34C  thumb  ov172
 *   TIME_ICON_CreateNode  0x0202EE8C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05448.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern void COMM_TVT_SYS_DeleteTimeIcon(void *p);
typedef unsigned char  u8;
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);

void COMM_TVT_SYS_CreateTimeIcon(char *a0, void *a1)
{
    if (((struct Obj05448 *)a0)->f1DC != 0)
        COMM_TVT_SYS_DeleteTimeIcon(a0);

    ((struct Obj05448 *)a0)->f1DC =
        (u32)TIME_ICON_CreateNode(((struct Obj05448 *)a0)->f1D8, (void *)a1, 0xf, 0x10, ((struct Obj05448 *)a0)->f0);
}
