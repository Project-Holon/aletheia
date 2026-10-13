/*
 * function: IRCBATTLEMENU_SeqSaveQuestion
 * address:  0x02197700
 * packet:   pkt_ov021_02197700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_SetSubPaletteActive  0x02196228  thumb  ov021
 *   func_02041570  0x02041570  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   IRCBATTLEMENU_PrintMessage  0x02197644  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqSaveQuestionWait  0x021978AC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void IRCBATTLEMENU_SetSubPaletteActive(u8 *p, int flag);
extern void func_02041570(int channel, u16 val);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void IRCBATTLEMENU_PrintMessage(u8 *, u32);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqSaveQuestionWait(u8 *a);

void IRCBATTLEMENU_SeqSaveQuestion(u8 *a)
{
    IRCBATTLEMENU_SetSubPaletteActive(a, 1);
    func_02041570(5, 0);
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00094 *)a)->f28), 25, (void *)(((struct Obj00094 *)a)->f38));
    IRCBATTLEMENU_PrintMessage(a, 0);
    IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqSaveQuestionWait, 0x761);
}
