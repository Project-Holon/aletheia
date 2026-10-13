/*
 * function: FLDMMDL_MOVECODE_InitMirrorSide
 * address:  0x0219B374
 * packet:   pkt_ov021_0219B374
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 FLDMMDL_GetEventType(u8 *p);

void FLDMMDL_MOVECODE_InitMirrorSide(u32 a, u8 *s)
{
    u32 v = FLDMMDL_GetEventType((u8 *)a);
    if (v == 7 || v == 17) {
        s[1] = 0;
    } else {
        s[1] = 1;
    }
}
