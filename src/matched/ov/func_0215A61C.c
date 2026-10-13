/*
 * function: SCRCMD_WORK_GetMsgWindow
 * address:  0x0215A61C
 * packet:   pkt_0215A61C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int SCRCMD_WORK_GetMsgWindow(int a0)
{

a0 = *(int *)&((struct Obj00005 *)a0)->f20;
a0 = a0 + 0xfc;
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}
