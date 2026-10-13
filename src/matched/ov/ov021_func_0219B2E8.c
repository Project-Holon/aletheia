/*
 * function: FLDMMDL_MOVECODE_UpdateTriggerWait
 * address:  0x0219B2E8
 * packet:   pkt_ov021_0219B2E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_MOVE_IsNearPlayer  0x02164168  thumb  ov010
 *   FLDMMDL_MOVECODE_IsBButtonPressed  0x0219B0C4  thumb  ov021
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
typedef unsigned short u16;
extern u16 FLDMMDL_GetEventType(u8 *p);
extern int FLDMMDL_MOVE_IsNearPlayer(int a);
extern int FLDMMDL_MOVECODE_IsBButtonPressed(void);
extern int FLDMMDL_GetParam(char *a0, int a1);

int FLDMMDL_MOVECODE_UpdateTriggerWait(int a, u8 *b)
{
    if (FLDMMDL_GetEventType((u8 *)a) != 12) {
        return 1;
    }
    if (b[0] == 0) {
        if (FLDMMDL_MOVE_IsNearPlayer(a) == 0) {
            return 0;
        }
        if (FLDMMDL_MOVECODE_IsBButtonPressed() == 0) {
            return 0;
        }
        b[0] = FLDMMDL_GetParam((char *)a, 1);
    }
    if (b[0] != 0) {
        b[0]--;
    }
    return 1;
}
