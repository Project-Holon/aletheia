/*
 * function: FIELD_PLAYER_NOGRID_CheckWalkFromBlocked
 * address:  0x021A5E28
 * packet:   pkt_ov021_021A5E28
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
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FIELD_PLAYER_NOGRID_CheckWalkFromStand  0x021A5CA4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckWalkStep  0x021A5D04  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_FreeAcmd(char *p);
extern int FIELD_PLAYER_NOGRID_CheckWalkFromStand(void *a, void *b, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckWalkStep(void *a, void *b, int c, int d, int e, int f);

int FIELD_PLAYER_NOGRID_CheckWalkFromBlocked(void *a, void *b, int c, int d, int e, int f)
{
    int t = FLDMMDL_GetDirDisp(b);
    if (e != 9 && e != t) {
        FLDMMDL_FreeAcmd(b);
        return FIELD_PLAYER_NOGRID_CheckWalkStep(a, b, c, d, e, f);
    }
    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return FIELD_PLAYER_NOGRID_CheckWalkFromStand(a, b, c, d, e, f);
    }
    return FIELD_PLAYER_NOGRID_CheckWalkStep(a, b, c, d, e, f);
}
