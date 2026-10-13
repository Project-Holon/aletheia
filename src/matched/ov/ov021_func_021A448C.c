/*
 * function: FIELD_PLAYER_GRID_GetDirChangeKind
 * address:  0x021A448C
 * packet:   pkt_ov021_021A448C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 */

typedef unsigned int u32;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
typedef unsigned short u16;
u16 FLDMMDL_GetDirDisp(void *p);

int FIELD_PLAYER_GRID_GetDirChangeKind(u32 *p, int a)
{
    int r = FLDMMDL_GetDirDisp(FIELD_PLAYER_CORE_GetMmdl((unsigned char *)p[3]));

    if (a == 9)
        return 0;
    if (a != r && p[0] != 1 && p[0] != 3)
        return 2;
    return 1;
}
