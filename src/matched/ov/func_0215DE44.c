/*
 * function: SCRCMD_MUSICAL_CloseCommSession
 * address:  0x0215DE44
 * packet:   pkt_0215DE44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUS_COMM_FUNC_Delete  0x021FC684  thumb
 */
#include "../include/Obj12042.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MUS_COMM_FUNC_Delete(int a0);

void SCRCMD_MUSICAL_CloseCommSession(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12042 *)t4)->f4;
    if (a0 == 0) goto loc_0215DE56;
loc_0215DE4E:
    a0 = MUS_COMM_FUNC_Delete(a0);
loc_0215DE52:
a0 = 0;
((struct Obj12042 *)t4)->f4 = a0;
loc_0215DE56:
    return;}
