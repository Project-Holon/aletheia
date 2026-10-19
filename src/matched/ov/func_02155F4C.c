/*
 * function: MUSICAL_EVENT_Free
 * address:  0x02155F4C
 * packet:   pkt_02155F4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_DRESSUP_SYS_Delete  0x02156CD8  thumb  ov010
 *   MUSICAL_STAGE_SYS_Delete  0x02156F98  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   MUSICAL_MCSS_FreeDistSave  0x021F6888  thumb
 *   MUSICAL_PROGRAM_Delete  0x0215716C  thumb  ov010
 */
#include "../include/Obj02657.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MUSICAL_DRESSUP_SYS_Delete();
extern int MUSICAL_STAGE_SYS_Delete();
extern int func_020307B0();
extern int MUSICAL_MCSS_FreeDistSave();
extern int MUSICAL_PROGRAM_Delete();

int MUSICAL_EVENT_Free(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj02657 *)t4)->f2C;
    if (a0 == 0) goto loc_02155F5A;
loc_02155F56:
    a0 = MUSICAL_DRESSUP_SYS_Delete(a0);
loc_02155F5A:
a0 = ((struct Obj02657 *)t4)->f30;
    if (a0 == 0) goto loc_02155F64;
loc_02155F60:
    a0 = MUSICAL_STAGE_SYS_Delete(a0);
loc_02155F64:
a0 = ((struct Obj02657 *)t4)->f34;
    if (a0 == 0) goto loc_02155F76;
loc_02155F6A:
a0 = ((struct Obj02657 *)a0)->f8;
    a0 = func_020307B0(a0);
loc_02155F70:
a0 = ((struct Obj02657 *)t4)->f34;
    a0 = func_020307B0(a0);
loc_02155F76:
a0 = ((struct Obj02657 *)t4)->f24;
    if (a0 == 0) goto loc_02155F80;
loc_02155F7C:
    a0 = MUSICAL_MCSS_FreeDistSave(a0);
loc_02155F80:
a0 = ((struct Obj02657 *)t4)->f3C;
    if (a0 == 0) goto loc_02155F8A;
loc_02155F86:
    a0 = func_020307B0(a0);
loc_02155F8A:
a0 = ((struct Obj02657 *)t4)->f38;
    if (a0 == 0) goto loc_02155F94;
loc_02155F90:
    a0 = MUSICAL_PROGRAM_Delete(a0);
loc_02155F94:
a0 = ((struct Obj02657 *)t4)->f8;
a1 = 0;
((struct Obj02657 *)((char *)a0))->f0 = a1;
    return a0;}
