/*
 * function: FLDMMDL_CheckSysStatusBit
 * address: 0x0216DA20
 * packet: pkt_ov010_0216DA20
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetMmdlSys 0x0216D67C thumb ov010
 *   FLDMMDL_SysCheckStatusBit 0x0216D4D4 thumb ov010
 */

extern void *FLDMMDL_GetMmdlSys(void *p);
extern int FLDMMDL_SysCheckStatusBit(int a0, int a1);
int FLDMMDL_CheckSysStatusBit(void *p, unsigned int v)
{
    return FLDMMDL_SysCheckStatusBit((int)FLDMMDL_GetMmdlSys(p), v);
}
