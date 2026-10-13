/*
 * function: APP_TASKMENU_IsDecide
 * address:  0x02027A20
 * packet:   pkt_02027A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter for the word at offset 0xC of a task menu object; witness for
 * the call at +0x16 of ov119 func_021DA318.
 */
#include "../include/Obj15770.h"

unsigned APP_TASKMENU_IsDecide(char *p)
{
    return ((struct Obj15770 *)p)->fC;
}
