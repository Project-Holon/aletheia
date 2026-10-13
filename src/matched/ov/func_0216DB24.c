/*
 * function: FLDMMDL_CheckDrawInitComp
 * address:  0x0216DB24
 * packet:   pkt_0216DB24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysCheckDrawInit  0x0216D948  thumb  ov010
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysCheckDrawInit(int a0);
extern int FLDMMDL_CheckMoveBitDrawInitComp(void *a0);

int FLDMMDL_CheckDrawInitComp(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)FLDMMDL_GetMmdlSys((void *)a0);
loc_0216DB2C:
    a0 = FLDMMDL_SysCheckDrawInit(a0);
loc_0216DB30:
    if (a0 != 0) goto loc_0216DB38;
loc_0216DB34:
a0 = 0;
    return a0;
loc_0216DB38:
a0 = t4 + 0;
    a0 = FLDMMDL_CheckMoveBitDrawInitComp((void *)a0);
loc_0216DB3E:
    if (a0 == 0) goto loc_0216DB46;
loc_0216DB42:
a0 = 1;
    return a0;
loc_0216DB46:
a0 = 0;
    return a0;}
