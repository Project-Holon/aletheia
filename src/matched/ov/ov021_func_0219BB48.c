/*
 * function: FLDMMDL_MOVE_LookFellowTurn
 * address:  0x0219BB48
 * packet:   pkt_ov021_0219BB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 *   FLDMMDL_MOVE_CanTurnToFellow  0x0219BCE4  thumb  ov021
 *   FLDMMDL_MOVE_TurnToFellow  0x0219BD30  thumb  ov021
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern void FLDMMDL_OffMoveBitMoveEnd(u8 *p);
extern int FLDMMDL_MOVE_CanTurnToFellow(u32 a, u32 b);
struct Obj05999;
extern int FLDMMDL_MOVE_TurnToFellow(char *a, struct Obj05999 *b);
extern void FLDMMDL_OnMoveBitMove(u32);

int FLDMMDL_MOVE_LookFellowTurn(char *a, u8 *s)
{
    FLDMMDL_OffMoveBitMove((u8 *)a);
    FLDMMDL_OffMoveBitMoveEnd((u8 *)a);
    if (FLDMMDL_MOVE_CanTurnToFellow((u32)a, (u32)s) == 1 && FLDMMDL_MOVE_TurnToFellow(a, (struct Obj05999 *)s) == 1) {
        FLDMMDL_OnMoveBitMove((u32)a);
        s[0]++;
        return 1;
    }
    return 0;
}
