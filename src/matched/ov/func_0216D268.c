/*
 * function: FLDMMDL_InitMove
 * address:  0x0216D268
 * packet:   pkt_0216D268
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_MOVE_SetupMove  0x02163010  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_InitMove  0x0219D6B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_MOVE_SetupMove();
extern int FLDMMDL_RAIL_MOVE_InitMove();

int FLDMMDL_InitMove(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
a1 = 2;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = FLDMMDL_CheckStatusBit(a0, a1);
loc_0216D276:
    if (a0 != 0) goto loc_0216D282;
loc_0216D27A:
a0 = t4 + 0;
    a0 = FLDMMDL_MOVE_SetupMove(a0);
loc_0216D280:
    return a0;
loc_0216D282:
a0 = t4 + 0;
    a0 = FLDMMDL_RAIL_MOVE_InitMove(a0);
loc_0216D288:
    return a0;}
