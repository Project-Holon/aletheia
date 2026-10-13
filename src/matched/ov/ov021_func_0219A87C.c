/*
 * function: FLDMMDL_MOVECODE_InitBackForth
 * address:  0x0219A87C
 * packet:   pkt_ov021_0219A87C
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
extern u8 *FLDMMDL_InitMoveProcWork(u32, u32);
extern int FLDMMDL_MOVECODE_IsMirrorEventType(u32);
extern void FLDMMDL_MOVECODE_InitMirrorSide(u32 a, u8 *s);

void FLDMMDL_MOVECODE_InitBackForth(u32 a)
{
    u8 *p = FLDMMDL_InitMoveProcWork(a, 8);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(a) == 1) {
        FLDMMDL_MOVECODE_InitMirrorSide(a, p + 4);
    }
}
