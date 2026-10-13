/*
 * function: FIELD_PLAYER_GRID_CanStartMove
 * address:  0x021A4254
 * packet:   pkt_ov021_021A4254
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 */

typedef unsigned int u32;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
int FLDMMDL_CheckPossibleAcmd(int a0);
typedef unsigned short u16;
u16 FLDMMDL_GetDirDisp(void *p);

int FIELD_PLAYER_GRID_CanStartMove(u32 *p, u32 a)
{
    void *h = FIELD_PLAYER_CORE_GetMmdl((unsigned char *)p[3]);

    if (FLDMMDL_CheckPossibleAcmd((int)h) == 1)
        return 1;
    if (a != 9 && p[0] == 3 && a != FLDMMDL_GetDirDisp(h))
        return 1;
    return 0;
}
