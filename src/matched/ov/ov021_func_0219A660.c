/*
 * function: FLDMMDL_MOVECODE_SpinStepWaitInterval
 * address:  0x0219A660
 * packet:   pkt_ov021_0219A660
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_MOVE_IsNearPlayer  0x02164168  thumb  ov010
 *   FLDMMDL_MOVECODE_IsBButtonPressed  0x0219B0C4  thumb  ov021
 *   FLDMMDL_MOVECODE_GetDirTowardPlayerInSet  0x0219B200  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x; u8 b; u8 pad; int n; } St;
extern u16 FLDMMDL_GetEventType(u8 *p);
extern int FLDMMDL_MOVE_IsNearPlayer(int a);
extern int FLDMMDL_MOVECODE_IsBButtonPressed(void);
extern int FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(int a, int id, int end);

int FLDMMDL_MOVECODE_SpinStepWaitInterval(u32 a, St *p)
{
    if (FLDMMDL_GetEventType((u8 *)a) == 11) {
        if (p->n != 0) {
            p->n = 0;
            return 0;
        }
        if (FLDMMDL_MOVE_IsNearPlayer(a) == 0)
            return 0;
        if (FLDMMDL_MOVECODE_IsBButtonPressed() == 0)
            return 0;
        p->n = p->n + 1;
    } else {
        if (p->n != 0) {
            if (FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(a, 0x26, 9) != 9) {
                p->b = 0;
                return 1;
            }
        }
        p->n = p->n + 1;
        if (p->n < 0x18)
            return 0;
    }
    p->b = 3;
    return 1;
}
