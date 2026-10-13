/*
 * function: FIELD_PLAYER_NOGRID_CheckActionSlow
 * address:  0x021A6014
 * packet:   pkt_ov021_021A6014
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
 *   FIELD_PLAYER_NOGRID_CheckSlowFromStand  0x021A607C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckSlowStep  0x021A60DC  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckSlowFromTurn  0x021A61B0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckSlowFromBlocked  0x021A6200  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_PLAYER_NOGRID_CheckSlowFromStand(void *a, void *b, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckSlowStep(void *a, void *b, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckSlowFromTurn(void *a, void *b, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckSlowFromBlocked(void *a, void *b, int c, int d, int e, int f);

int FIELD_PLAYER_NOGRID_CheckActionSlow(int *a, int b, int c, int d, int e)
{
    int sw = a[0];
    int r = 0;
    void *p = ((void **)a)[7];
    switch (sw) {
    case 0: r = FIELD_PLAYER_NOGRID_CheckSlowFromStand(a, p, b, c, d, e); break;
    case 1: r = FIELD_PLAYER_NOGRID_CheckSlowStep(a, p, b, c, d, e); break;
    case 2: r = FIELD_PLAYER_NOGRID_CheckSlowFromTurn(a, p, b, c, d, e); break;
    case 3: r = FIELD_PLAYER_NOGRID_CheckSlowFromBlocked(a, p, b, c, d, e); break;
    }
    return r;
}
