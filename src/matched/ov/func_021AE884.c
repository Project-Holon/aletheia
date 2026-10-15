/*
 * function: EVENT_TRAINER_EYE_GetTrainerId
 * address:  0x021AE884
 * packet:   pkt_021AE884
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * EVENT_POKE_STATUS_NormalizeTicks (0x0215A460) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 *   EVENT_POKE_STATUS_NormalizeTicks  0x0215A460  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 EVENT_POKE_STATUS_NormalizeTicks(u32);
extern u32 FLDMMDL_GetEventId(void *p);

int EVENT_TRAINER_EYE_GetTrainerId(u32 a)
{
return EVENT_POKE_STATUS_NormalizeTicks(FLDMMDL_GetEventId((void *)a));
}

