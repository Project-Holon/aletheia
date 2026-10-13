/*
 * function: FIELD_PLAYER_NOGRID_StartActionSlow
 * address:  0x021A5F98
 * packet:   pkt_ov021_021A5F98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_StartSlowNone  0x021A6278  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartSlowStand  0x021A627C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartSlowStep  0x021A62B4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartSlowTurn  0x021A62D8  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartSlowBlocked  0x021A62FC  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartSlowLedgeJump  0x021A6338  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void FIELD_PLAYER_NOGRID_StartSlowNone(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartSlowStand(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartSlowStep(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartSlowTurn(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartSlowBlocked(void *a, void *b, int c, int d, int e, int f);
extern void FIELD_PLAYER_NOGRID_StartSlowLedgeJump(void *a, void *b, int c, int d, int e, int f);

void FIELD_PLAYER_NOGRID_StartActionSlow(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f)
{
    void *p = ((void **)a)[7];
    switch (sel) {
    case 0: FIELD_PLAYER_NOGRID_StartSlowNone(a, p, c, d, e, f); break;
    case 1: FIELD_PLAYER_NOGRID_StartSlowStand(a, p, c, d, e, f); break;
    case 2: FIELD_PLAYER_NOGRID_StartSlowStep(a, p, c, d, e, f); break;
    case 3: FIELD_PLAYER_NOGRID_StartSlowTurn(a, p, c, d, e, f); break;
    case 4: FIELD_PLAYER_NOGRID_StartSlowBlocked(a, p, c, d, e, f); break;
    case 5: FIELD_PLAYER_NOGRID_StartSlowLedgeJump(a, p, c, d, e, f); break;
    }
}
