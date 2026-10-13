/*
 * function: SCRCMD_MMDL_ICA_CreateProc
 * address:  0x021D182C
 * packet:   pkt_ov021_021D182C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The spilled second parameter is a u16 (FLDMMDL_SysSearchObjId compares its id
 * against FLDMMDL_GetObjId's u16): as u32/int its reload from [sp] is hoisted
 * above the struct copy's last store. FIELD_SUBPROC_GetWork takes the result of
 * FIELD_SUBPROC_Start (the bl has no argument setup of its own).
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   FIELD_SUBPROC_GetWork  0x021BBA6C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   d_021DD5F0     0x021DD5F0  data    ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09751.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct V3 { u32 a, b, c; };

extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern int *FIELD_SUBPROC_Start(int a, int *d, const int *c);
extern u32 FIELD_SUBPROC_GetWork(const void *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern int d_021DD5F0[];

u8 *SCRCMD_MMDL_ICA_CreateProc(u32 a, u16 b, struct V3 *c, u16 d)
{
    void *t = FIELDMAP_GetMmdlSys((void *)a);
    u32 h = FIELDMAP_GetMapFunc((u8 *)a);
    int *w = FIELD_SUBPROC_Start(-1, (int *)h, d_021DD5F0);
    u8 *p = (u8 *)FIELD_SUBPROC_GetWork(w);

    *(int * *)&((struct Obj09751 *)p)->f188 = w;
    ((struct Obj09751 *)p)->f19C = d;
    *(struct V3 *)(p + 0x18C) = *c;
    ((struct Obj09751 *)p)->f0 = (u32)FLDMMDL_SysSearchObjId(t, b);
    return p;
}
