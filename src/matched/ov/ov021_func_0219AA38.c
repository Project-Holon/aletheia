/*
 * function: FLDMMDL_MOVECODE_InitRoutePatrol
 * address:  0x0219AA38
 * packet:   pkt_ov021_0219AA38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_MOVECODE_IsMirrorEventType  0x0219B358  thumb  ov021
 *   FLDMMDL_MOVECODE_InitMirrorSide  0x0219B374  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3);
extern int FLDMMDL_MOVECODE_IsMirrorEventType(u32);
extern void FLDMMDL_MOVECODE_InitMirrorSide(u32 a, u8 *s);

void FLDMMDL_MOVECODE_InitRoutePatrol(u32 a, u32 b, u32 c, u32 d)
{
    u8 *p = FLDMMDL_InitMoveProcWork(a, 12, c, d);
    p[2] = b;
    p[3] = c;
    p[4] = d;
    if (FLDMMDL_MOVECODE_IsMirrorEventType(a) == 1) {
        FLDMMDL_MOVECODE_InitMirrorSide(a, p + 8);
    }
}
