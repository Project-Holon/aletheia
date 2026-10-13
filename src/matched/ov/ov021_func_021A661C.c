/*
 * function: FIELD_PLAYER_NOGRID_CheckRailFromTurn
 * address:  0x021A661C
 * packet:   pkt_ov021_021A661C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_NOGRID_CheckRailFromStand  0x021A652C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailStep  0x021A658C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_NOGRID_CheckRailFromStand(void *a, void *b, int c, int d, u16 e, int f);
extern int FIELD_PLAYER_NOGRID_CheckRailStep(void *a, void *b, int c, int d, u16 e, int f);

int FIELD_PLAYER_NOGRID_CheckRailFromTurn(void *a, void *b, int c, int d, u16 e, int f)
{
    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return FIELD_PLAYER_NOGRID_CheckRailFromStand(a, b, c, d, e, f);
    }
    return FIELD_PLAYER_NOGRID_CheckRailStep(a, b, c, d, e, f);
}
