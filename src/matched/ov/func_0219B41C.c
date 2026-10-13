/*
 * function: FLDMMDL_MOVECODE_UpdateEventTypeProc
 * address:  0x0219B41C
 * packet:   pkt_0219B41C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_MOVECODE_CheckByEventType  0x0219B45C  thumb  ov021
 *   FLDMMDL_MOVECODE_UpdateByEventType  0x0219B478  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_MOVECODE_CheckByEventType(u32, u32, u32, u32);
extern u32 FLDMMDL_MOVECODE_UpdateByEventType(u32);

int FLDMMDL_MOVECODE_UpdateEventTypeProc(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_MOVECODE_CheckByEventType(a, b, c, d) == 0) {
    return 0;
}
if (FLDMMDL_MOVECODE_UpdateByEventType(a) != 0) {
    return 1;
}
return 0;
}

