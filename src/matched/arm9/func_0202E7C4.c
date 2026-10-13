/*
 * function: COMM_PLAYER_SUPPORT_SetModeAndCurrent
 * address:  0x0202E7C4
 * packet:   pkt_0202E7C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the mode word and copies a 32-byte block into the current slot
 * (same State layout as COMM_PLAYER_SUPPORT_GetMode).  Caller: ov011 0x02174514.
 */

typedef unsigned int u32;
typedef struct { u32 a[8]; } Block;
typedef struct { u32 mode, old, other; Block current, previous; } State;

void COMM_PLAYER_SUPPORT_SetModeAndCurrent(State *p, u32 mode, const Block *src)
{
    p->mode = mode;
    p->current = *src;
}
