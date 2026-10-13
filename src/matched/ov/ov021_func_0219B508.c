/*
 * function: FLDMMDL_MOVE_InitWalkRepeat
 * address:  0x0219B508
 * packet:   pkt_ov021_0219B508
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
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_InitMoveSubProcWork(int a0, int a1);
extern int FLDMMDL_GetParam(char *a0, int a1);

void FLDMMDL_MOVE_InitWalkRepeat(u32 a)
{
    u8 *p = FLDMMDL_InitMoveSubProcWork(a, 9);
    p[3] = FLDMMDL_GetParam((char *)a, 1);
}
