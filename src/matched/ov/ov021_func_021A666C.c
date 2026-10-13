/*
 * function: FIELD_PLAYER_NOGRID_CheckRailFromBlocked
 * address:  0x021A666C
 * packet:   pkt_ov021_021A666C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_NOGRID_CheckRailFromStand  0x021A652C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailStep  0x021A658C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FLDMMDL_GetDirDisp(void *o);
extern void *FLDMMDL_FreeAcmd(char *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u32 FIELD_PLAYER_NOGRID_CheckRailFromStand(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
extern u32 FIELD_PLAYER_NOGRID_CheckRailStep(void *a, void *b, u32 c, u32 d, u32 e, u32 f);

u32 FIELD_PLAYER_NOGRID_CheckRailFromBlocked(void *a, void *b, u32 c, u32 d, u32 e, u32 f)
{
    u32 r0 = FLDMMDL_GetDirDisp(b);

    if (e != 9 && e != r0) {
        FLDMMDL_FreeAcmd(b);
        return FIELD_PLAYER_NOGRID_CheckRailStep(a, b, c, d, e, f);
    }
    if (!FLDMMDL_CheckPossibleAcmd((int)b))
        return 0;
    if (e == 9)
        return FIELD_PLAYER_NOGRID_CheckRailFromStand(a, b, c, d, e, f);
    return FIELD_PLAYER_NOGRID_CheckRailStep(a, b, c, d, e, f);
}
