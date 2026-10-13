/*
 * function: FIELD_PLAYER_NOGRID_CheckWalkFromTurn
 * address:  0x021A5DD8
 * packet:   pkt_ov021_021A5DD8
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
 *   FIELD_PLAYER_NOGRID_CheckWalkFromStand  0x021A5CA4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckWalkStep  0x021A5D04  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_NOGRID_CheckWalkFromStand(u8 *p, void *b, u32 c, u32 d, u16 e, u32 f);
extern int FIELD_PLAYER_NOGRID_CheckWalkStep(void *a, void *b, int c, int d, int e, int f);

int FIELD_PLAYER_NOGRID_CheckWalkFromTurn(void *a, void *b, int c, int d, u16 e, int f)
{
    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return FIELD_PLAYER_NOGRID_CheckWalkFromStand(a, b, c, d, e, f);
    }
    return FIELD_PLAYER_NOGRID_CheckWalkStep(a, b, c, d, e, f);
}
