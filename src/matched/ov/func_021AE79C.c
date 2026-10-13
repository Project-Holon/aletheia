/*
 * function: EVENT_TRAINER_EYE_GetSightType
 * address:  0x021AE79C
 * packet:   pkt_021AE79C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_GetEventType (0x0216D5A8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb
 *   FLDMMDL_NormalizeEventType  0x0216E434  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_GetEventType(u32);
extern u32 FLDMMDL_NormalizeEventType(u32);

int EVENT_TRAINER_EYE_GetSightType(u32 a)
{
return FLDMMDL_NormalizeEventType(FLDMMDL_GetEventType(a));
}

