/*
 * function: EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange
 * address:  0x02162370
 * packet:   pkt_02162370
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Predicate: is the argument >= 7.
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
int EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(int a)
{
return a >= 7;
}
