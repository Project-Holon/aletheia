/*
 * function: SCRIPT_WORK_Delete
 * address:  0x02158F18
 * packet:   pkt_02158F18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   SCRCMD_WORK_DeleteCommon  0x0215A554  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00105.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int WORDSET_DeleteStrbufED04();
extern int STRBUF_Delete();
extern int SCRCMD_WORK_DeleteCommon();
extern int func_020307B0();

int SCRIPT_WORK_Delete(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = 0;
*(int *)((char *)t4) = a0;
a0 = ((struct Obj00105 *)t4)->f2C;
    if (a0 == 0) goto loc_02158F2A;
loc_02158F26:
    a0 = WORDSET_DeleteStrbufED04(a0);
loc_02158F2A:
a0 = ((struct Obj00105 *)t4)->f30;
    if (a0 == 0) goto loc_02158F34;
loc_02158F30:
    a0 = STRBUF_Delete(a0);
loc_02158F34:
a0 = ((struct Obj00105 *)t4)->f34;
    if (a0 == 0) goto loc_02158F3E;
loc_02158F3A:
    a0 = STRBUF_Delete(a0);
loc_02158F3E:
a0 = 0x52;
a0 = a0 << 2;
a0 = *(int *)((char *)t4 + a0);
    a0 = SCRCMD_WORK_DeleteCommon(a0);
loc_02158F48:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02158F4E:
    return a0;}
