/*
 * function: FIELD_PLAYER_NOGRID_CheckWalkFromStand
 * address:  0x021A5CA4
 * packet:   pkt_ov021_021A5CA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_NOGRID_CheckWalkStep  0x021A5D04  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FIELD_PLAYER_NOGRID_CheckWalkStep(void *a, void *b, int c, int d, int e, int f);

int FIELD_PLAYER_NOGRID_CheckWalkFromStand(u8 *p, void *b, u32 c, u32 d, u16 e, u32 f)
{
    if (FLDMMDL_CheckPossibleAcmd((int)b) == 1) {
        if (e != 9) {
            if (e != FLDMMDL_GetDirDisp(b) && f == 0) {
                return 3;
            }
            return FIELD_PLAYER_NOGRID_CheckWalkStep(p, b, c, d, e, f);
        }
        return 1;
    }
    return 0;
}
