/*
 * function: ITEMMENU_GetCursorIndex
 * address: 0x021B61B8
 * packet: pkt_ov070_021B61B8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj00002.h"
typedef unsigned char u8;
int ITEMMENU_GetCursorIndex(u8 *p)
{
    return (int)(*(unsigned int *)&((struct Obj00002 *)p)->f810 + *(unsigned int *)&((struct Obj00002 *)p)->f814 + 1U);
}
