/*
 * function: FLDMMDL_MOVE_InitWalkRepeatSpin
 * address:  0x0219B6B0
 * packet:   pkt_ov021_0219B6B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveSubProcWork  0x0216D6A0  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_InitMoveSubProcWork(int a0, int a1);
extern int FLDMMDL_GetParam(char *a0, int a1);
extern u16 FLDMMDL_GetEventType(u8 *p);

void FLDMMDL_MOVE_InitWalkRepeatSpin(u32 a)
{
    u8 *p = FLDMMDL_InitMoveSubProcWork(a, 9);
    u32 s;
    u8 v = 1;
    p[3] = FLDMMDL_GetParam((char *)a, 1);
    s = FLDMMDL_GetEventType((u8 *)a);
    if (s == 5 || s == 20 || s == 15) {
        v = 0;
    }
    p[5] = v;
}
