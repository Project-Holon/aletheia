/*
 * function: FLDMMDL_GetBlActCont
 * address:  0x0216D910
 * packet:   pkt_0216D910
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);

int FLDMMDL_GetBlActCont(int a0)
{

    a0 = (int)FLDMMDL_GetMmdlSys((void *)a0);
loc_0216D916:
    a0 = FLDMMDL_SysGetBlActCont((void *)a0);
loc_0216D91A:
    return a0;}
