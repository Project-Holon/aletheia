/*
 * function: IRCBATTLEMENU_SeqSaveStart
 * address:  0x02197798
 * packet:   pkt_ov021_02197798
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_IsMessageEnd  0x021975D0  thumb  ov021
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqSaveMain  0x02197738  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int IRCBATTLEMENU_IsMessageEnd(u8 *p);
extern int GAME_DATA_SaveStart(int a0);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqSaveMain(u8 *a);

void IRCBATTLEMENU_SeqSaveStart(u8 *a)
{
    if (IRCBATTLEMENU_IsMessageEnd(a) != 0) {
        GAME_DATA_SaveStart(((struct Obj00094 *)a)->f30);
        IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqSaveMain, 0x78E);
    }
}
