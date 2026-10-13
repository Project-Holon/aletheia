/*
 * function: FLDMMDL_DeleteSys
 * address:  0x0216CCB0
 * packet:   pkt_0216CCB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CloseObjCodeArc  0x0216E290  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj12056.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CloseObjCodeArc();
extern int func_020307B0();

int FLDMMDL_DeleteSys(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = FLDMMDL_CloseObjCodeArc(a0);
loc_0216CCB8:
a0 = ((struct Obj12056 *)t4)->f44;
    a0 = func_020307B0(a0);
loc_0216CCBE:
a0 = ((struct Obj12056 *)t4)->f18;
    a0 = func_020307B0(a0);
loc_0216CCC4:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0216CCCA:
    return a0;}
