/*
 * function: EVENT_TRAINER_GetTrainerIdFromScriptId
 * address:  0x0215A460
 * packet:   pkt_0215A460
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Map a tick count onto a 3000/5000 ms window, truncated to 16 bits.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
u32 EVENT_TRAINER_GetTrainerIdFromScriptId(u32 a)
{
if (a < 5000)
return (u16)(a - 3000);
return (u16)(a - 5000);
}
