/*
 * function: BUTTON_MAN_Delete
 * address:  0x02051C6C
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_Delete.c \
 *       --func BUTTON_MAN_Delete --addr 0x02051C6C --cc 1.1p1 --arm
 */
#include "../include/Obj16196.h"

typedef unsigned int u32;

extern u32 func_020307B0(void *p);

void BUTTON_MAN_Delete(void *p)
{
    func_020307B0((void *)((struct Obj16196 *)p)->f10);
    func_020307B0(p);
}
