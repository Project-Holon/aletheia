/*
 * function: FLDMMDL_UpdateMove
 * address:  0x0216D28C
 * packet:   pkt_0216D28C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The mask test picks between the overlay's own handler and the arm9
 * field setter.
 *
 * symbols:
 *   FLDMMDL_CheckStatusBit   0x0216D55C  thumb  ov010
 *   FLDMMDL_MOVE_UpdateMove   0x02163028  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_UpdateMove   0x0219D6CC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern void FLDMMDL_MOVE_UpdateMove(void *a);
extern void FLDMMDL_RAIL_MOVE_UpdateMove(void *);

void FLDMMDL_UpdateMove(void *a0)
{
    if (FLDMMDL_CheckStatusBit((int)a0, 0x2000) == 0) {
        FLDMMDL_MOVE_UpdateMove((void *)a0);
    } else {
        FLDMMDL_RAIL_MOVE_UpdateMove(a0);
    }
}
