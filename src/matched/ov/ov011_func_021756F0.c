/*
 * function: INTRUDE_COMM_SetLock
 * address:  0x021756F0
 * packet:   pkt_ov011_021756F0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: sets bit 6 of the byte at +0x93f from the low bit of v.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Flags {
    u8 lo : 6;
    u8 f  : 1;
    u8 hi : 1;
} Flags;

void INTRUDE_COMM_SetLock(u8 *o, u32 v)
{
    ((Flags *)(o + 0x93f))->f = (u8)v;
}
