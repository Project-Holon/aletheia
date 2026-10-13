/*
 * function: FIELD_PLAYER_GRID_ResetHold
 * address:  0x021A5738
 * packet:   pkt_ov021_021A5738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GRID_IsHoldFlagSet  0x021A5390  thumb  ov021
 *   FIELD_PLAYER_GRID_EndHold  0x021A5708  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x14];
    u16 saved;
    u8 flag;
} Obj021A5738;

typedef unsigned int   u32;
int FIELD_PLAYER_GRID_IsHoldFlagSet(u32 a);
int FIELD_PLAYER_GRID_EndHold(u32 a);

void FIELD_PLAYER_GRID_ResetHold(Obj021A5738 *p, int a)
{
    u16 s;

    if (FIELD_PLAYER_GRID_IsHoldFlagSet((u32)p) == 1) {
        s = p->saved;
        FIELD_PLAYER_GRID_EndHold((u32)p);
        if (a == 1) {
            p->saved = s;
            p->flag = 1;
        }
    }
}
