/*
 * function: FLDMMDL_InitDir
 * address: 0x0216D208
 * packet: pkt_ov010_0216D208
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetDirHeader 0x0216D5D4 thumb ov010
 *   FLDMMDL_SetDirDisp 0x0216D5D8 thumb ov010
 *   FLDMMDL_SetDirMove 0x0216D600 thumb ov010
 */

typedef unsigned short u16;
extern int FLDMMDL_GetDirHeader(void *p);
extern int FLDMMDL_SetDirDisp(int a0, int a1);
extern int FLDMMDL_SetDirMove(int a0, u16 a1);
void FLDMMDL_InitDir(void *p)
{
    FLDMMDL_SetDirDisp((int)p, (u16)FLDMMDL_GetDirHeader(p));
    FLDMMDL_SetDirMove((int)p, (u16)FLDMMDL_GetDirHeader(p));
}
