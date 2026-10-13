/*
 * function: FLDMMDL_SysSetDrawInit
 * address: 0x0216D95C
 * packet: pkt_ov010_0216D95C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_SysSetStatusBit 0x0216D4DC thumb ov010
 *   FLDMMDL_SysClearStatusBit 0x0216D4E4 thumb ov010
 */

extern int FLDMMDL_SysSetStatusBit(int a0, int a1, int a2);
typedef unsigned int   u32;
extern u32 *FLDMMDL_SysClearStatusBit(u32 *p, u32 v);
void FLDMMDL_SysSetDrawInit(unsigned int *p, unsigned int v, int a2)
{
    if (v == 1) FLDMMDL_SysSetStatusBit((int)p, 1, a2);
    else FLDMMDL_SysClearStatusBit(p, 1);
}
