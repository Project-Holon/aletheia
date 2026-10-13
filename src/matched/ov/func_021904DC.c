/*
 * function: FIELD_MSGBG_SetAutoMode
 * address:  0x021904DC
 * packet:   pkt_02193208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the object displaced by 0x160 bytes, forwarding the value.
 * The second parameter is what puts the offset temp in r2 instead of r1.
 *
 * symbols:
 *   FIELD_MSGBG_KeyWaitSetAuto  0x02193208  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_MSGBG_KeyWaitSetAuto(u8 *p, u8 v);

void FIELD_MSGBG_SetAutoMode(u8 *p, u8 v)
{
    FIELD_MSGBG_KeyWaitSetAuto(p + 0x160, v);
}
