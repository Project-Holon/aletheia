/*
 * function: func_0202E7E0
 * address:  0x0202E7E0
 * packet:   pkt_0202E7E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witness leaf for ov093 func_021C4744 (tiny unlabelled arm9 leaf).
 */

typedef unsigned int u32;
typedef struct { u32 a[8]; } Block;
typedef struct { u32 mode, old, other; Block current, previous; } State;

u32 func_0202E7E0(State *p) { return p->mode; }
