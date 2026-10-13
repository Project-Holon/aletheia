/*
 * function: FLDMMDL_MOVE_GetTurnAcmdBase
 * address:  0x0219BA2C
 * packet:   pkt_ov021_0219BA2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 */

typedef unsigned short u16;

typedef unsigned char  u8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern u16 FLDMMDL_GetAcmdCode(u8 *p);

int FLDMMDL_MOVE_GetTurnAcmdBase(int a)
{
    int v;

    FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    v = FLDMMDL_GetAcmdCode((u8 *)a);
    switch (v) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    }
    return v;
}
