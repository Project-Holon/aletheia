/*
 * function: FLDMMDL_MOVE_WalkRepeatSpin
 * address:  0x0219B6E0
 * packet:   pkt_ov021_0219B6E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveSubProcWork  0x0216D6B8  thumb  ov010
 *   FLDMMDL_MOVECODE_HasLeftOldGrid  0x0219B494  thumb  ov021
 *   FLDMMDL_MOVECODE_IsAtOldGrid  0x0219B4C8  thumb  ov021
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 */

typedef unsigned char u8;
typedef signed char   s8;

typedef struct St {
    u8 state;
    s8 f1;
    s8 cur;
    s8 max;
} St;

extern void *FLDMMDL_GetMoveSubProcWork(void *p);
extern int FLDMMDL_MOVECODE_HasLeftOldGrid(int a);
extern int FLDMMDL_MOVECODE_IsAtOldGrid(int a);
extern int FLDMMDL_CheckMoveBitMove(void *a0);

int FLDMMDL_MOVE_WalkRepeatSpin(int a)
{
    St *p;

    p = FLDMMDL_GetMoveSubProcWork((void *)a);
    switch (p->state) {
    case 0:
        if (FLDMMDL_MOVECODE_HasLeftOldGrid(a) == 1) {
            p->state++;
        }
        break;
    case 1:
        if (FLDMMDL_MOVECODE_IsAtOldGrid(a) == 0) {
            break;
        }
        p->cur++;
        if (p->cur < p->max) {
            p->state = 0;
            break;
        }
        p->state++;
    case 2:
        if (FLDMMDL_CheckMoveBitMove((void *)a) == 1) {
            break;
        }
        p->state++;
        p->cur = 0;
        p->f1 = 0;
    case 3:
        return 1;
    }
    return 0;
}
