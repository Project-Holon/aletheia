/*
 * function: FLDMMDL_MOVE_LookPlayerTurn
 * address:  0x0219B924
 * packet:   pkt_ov021_0219B924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 *   FLDMMDL_MOVE_HasPlayerMoved  0x0219B9D8  thumb  ov021
 *   FLDMMDL_MOVE_SavePlayerGridPos  0x0219BA0C  thumb  ov021
 *   FLDMMDL_MOVE_TurnToPlayer  0x0219BA6C  thumb  ov021
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 */

typedef unsigned char u8;

extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern void FLDMMDL_OffMoveBitMoveEnd(u8 *p);
typedef unsigned int   u32;
extern int FLDMMDL_MOVE_HasPlayerMoved(u32 a, u8 *s);
extern void FLDMMDL_MOVE_SavePlayerGridPos(u32 a, u8 *s);
extern int FLDMMDL_MOVE_TurnToPlayer(char *a);
extern void FLDMMDL_OnMoveBitMove(u32 a);

int FLDMMDL_MOVE_LookPlayerTurn(char *a, u8 *b)
{
    FLDMMDL_OffMoveBitMove((u8 *)a);
    FLDMMDL_OffMoveBitMoveEnd((u8 *)a);
    if (FLDMMDL_MOVE_HasPlayerMoved((u32)a, b) == 1) {
        FLDMMDL_MOVE_SavePlayerGridPos((u32)a, b);
        if (FLDMMDL_MOVE_TurnToPlayer(a) == 1) {
            FLDMMDL_OnMoveBitMove((u32)a);
            b[0]++;
            return 1;
        }
    }
    return 0;
}
