/*
 * function: POKE_SUMMARY_MAIN_DeleteMsgWindow
 * address:  0x021B6794
 * packet:   pkt_021B6794
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj24150.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *p)
{
    return func_020307B0((void *)(((struct Obj24150 *)p)->f1C0));
}
