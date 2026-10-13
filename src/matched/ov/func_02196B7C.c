/*
 * function: IRCBATTLEMENU_HookKindBackPressed
 * address:  0x02196B7C
 * packet:   pkt_02196B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced thunk: registers the record at 0x021966F0.
 *
 * symbols:
 *   IRCBATTLEMENU_SeqSetupTopMenu  0x021966F0  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
extern void IRCBATTLEMENU_SeqSetupTopMenu(u8 *p);

void IRCBATTLEMENU_HookKindBackPressed(u8 *p)
{
    IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqSetupTopMenu, 0x47A);
}
