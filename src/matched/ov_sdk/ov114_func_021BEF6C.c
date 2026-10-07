/*
 * function: func_021BEF6C
 * address:  0x021BEF6C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021CF984  0x021CF984  data
 *   g_021CF98C  0x021CF98C  data
 *   g_021CF9C0  0x021CF9C0  data
 *   g_021CF964  0x021CF964  data
 *   func_021BEC48  0x021BEC48  arm  ov114
 *
 *
 * Drains the module list, then empties the module head pointer.
 */

#include "../include/G_Conn.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern struct Conn *g_021CF984;
extern u32 func_021BEC48(void);

void func_021BEF6C(void)
{
    if ((*(u32 *)&g_021CF984) != 0)
        func_021BEC48();
    (*(u32 *)&g_021CF984) = 0;
}
