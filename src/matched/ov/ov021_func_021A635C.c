/*
 * function: FIELD_PLAYER_NOGRID_StartActionRail
 * address:  0x021A635C
 * packet:   pkt_ov021_021A635C
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
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartRailNone  0x021A63EC  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartRailStand  0x021A63F0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartRailStep  0x021A6428  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartRailTurn  0x021A6454  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartRailBlocked  0x021A6478  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void FIELD_PLAYER_NOGRID_StartRailNone(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartRailStand(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartRailStep(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartRailTurn(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartRailBlocked(void *a, void *b, int c, int d, int e, int f);

void FIELD_PLAYER_NOGRID_StartActionRail(S *a, int sel, int c, int d, int e, int f)
{
    void *x = FIELD_PLAYER_CORE_GetMmdl(a->f14);
    switch (sel) {
    case 0: FIELD_PLAYER_NOGRID_StartRailNone(a, x, c, d, e, f); break;
    case 1: FIELD_PLAYER_NOGRID_StartRailStand(a, x, c, d, e, f); break;
    case 2: FIELD_PLAYER_NOGRID_StartRailStep(a, x, c, d, e, f); break;
    case 3: FIELD_PLAYER_NOGRID_StartRailTurn(a, x, c, d, e, f); break;
    case 4: FIELD_PLAYER_NOGRID_StartRailBlocked(a, x, c, d, e, f); break;
    }
}
