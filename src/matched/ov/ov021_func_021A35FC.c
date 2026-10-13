/*
 * function: FIELD_PLAYER_GetNowGridPos
 * address:  0x021A35FC
 * packet:   pkt_ov021_021A35FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
int FLDMMDL_GetGridNowX(void *p);
int FLDMMDL_GetGridNowY(void *p);
int FLDMMDL_GetGridNowZ(void *p);

void FIELD_PLAYER_GetNowGridPos(unsigned char **p, u16 *a, u16 *b, u16 *c)
{
    void *h = FIELD_PLAYER_CORE_GetMmdl(p[1]);

    *a = FLDMMDL_GetGridNowX(h);
    *b = FLDMMDL_GetGridNowY(h);
    *c = FLDMMDL_GetGridNowZ(h);
}
