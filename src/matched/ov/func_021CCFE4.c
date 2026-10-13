/*
 * function: PARTY_SELECT_LIST_PrintText
 * address:  0x021CCFE4
 * packet:   pkt_021CCFE4
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
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_MSGBG_SysWinPrintMsg(u32, u32, u32, u32);

int PARTY_SELECT_LIST_PrintText(u32 a, u32 b)
{
return FIELD_MSGBG_SysWinPrintMsg(*(u32 *)((u8 *)((a + 176))), 0, 0, b);
}

