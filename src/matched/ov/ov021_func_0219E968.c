/*
 * function: FLDMMDL_RAIL_InitMoveWork
 * address:  0x0219E968
 * packet:   pkt_ov021_0219E968
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_GetRailMoveRequest  0x02164380  thumb  ov010
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_RAIL_InitRailWork  0x0219EA5C  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int FLDMMDL_MOVE_GetRailMoveRequest(void *a, u16 *b);
extern void *FLDMMDL_InitMoveProcWork(u32, u32);
extern int FLDMMDL_RAIL_InitRailWork(void *a, u32 b);
extern void MI_CpuFill8(void *, int, int);
extern void FLDMMDL_RAIL_SetLocation(void *a, void *r);

void *FLDMMDL_RAIL_InitMoveWork(u32 a, u32 size)
{
    u8 buf[8];
    int ok = FLDMMDL_MOVE_GetRailMoveRequest((void *)a, (u16 *)buf);
    void *q = FLDMMDL_InitMoveProcWork(a, size);
    FLDMMDL_RAIL_InitRailWork(q, a);
    if (ok) {
        FLDMMDL_RAIL_SetLocation((void *)a, buf);
    } else {
        MI_CpuFill8(buf, 0, 8);
        FLDMMDL_RAIL_SetLocation((void *)a, buf);
    }
    return q;
}
