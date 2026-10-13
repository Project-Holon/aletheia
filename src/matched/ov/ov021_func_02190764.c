/*
 * function: FIELD_MSGBG_MsgWinPrintStrColorFont
 * address:  0x02190764
 * packet:   pkt_ov021_02190764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_MsgPrintPrintStrColorFont  0x021905C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

extern void FIELD_MSGBG_MsgPrintPrintStrColorFont(Slot *s, int x, int y, u32 z, u16 w, u32 v);

void FIELD_MSGBG_MsgWinPrintStrColorFont(Slot **p, int x, int y, u32 z, u16 w, u32 v)
{
    FIELD_MSGBG_MsgPrintPrintStrColorFont(p[1], x, y, z, w, v);
}
