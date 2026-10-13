/*
 * function: FIELD_MSGBG_IsMsgPrintTransDone
 * address:  0x0219061C
 * packet:   pkt_0219061C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter, callee of the thunk at 0x0219077C.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_MSGBG_IsMsgPrintTransDone(u32 *p)
{
    return p[1];
}
