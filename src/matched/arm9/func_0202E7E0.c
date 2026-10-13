/*
 * function: COMM_PLAYER_SUPPORT_GetMode
 * address:  0x0202E7E0
 * packet:   pkt_0202E7E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witness leaf for ov093 BTL_SERVER_FLOW_ProcPlayerSupportHeal (tiny unlabelled arm9 leaf).
 */

typedef unsigned int u32;
typedef struct { u32 a[8]; } Block;
typedef struct { u32 mode, old, other; Block current, previous; } State;

u32 COMM_PLAYER_SUPPORT_GetMode(State *p) { return p->mode; }
