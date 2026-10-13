/*
 * function: FLDMMDL_MOVECODE_IsPlayerWalking
 * address:  0x0219B074
 * packet:   pkt_ov021_0219B074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

int FLDMMDL_MOVECODE_IsPlayerWalking(int a)
{
    int t;

    t = (int)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    if (t != 0) {
        switch (FLDMMDL_GetAcmdCode((u8 *)t)) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0xa3:
        case 0xa4:
        case 0xa5:
        case 0xa6:
            return 1;
        }
    }
    return 0;
}
