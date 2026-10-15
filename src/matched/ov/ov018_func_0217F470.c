/*
 * function: EVENT_COMM_COMMON_PrintToWindow
 * address: 0x0217F470
 * packet: pkt_ov018_0217F470
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   FIELD_MSGBG_MsgWinPrintStr 0x02190758 thumb ov021
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern int FIELD_MSGBG_MsgWinPrintStr(u32 a, u32 b, u32 c, u32 d);
void EVENT_COMM_COMMON_PrintToWindow(void **p, void *bank, void *handle, unsigned int index, int a, int b)
{
    MSGDATA_ReadString(bank, index, p[2]);
    WORDSET_CopyTaggedText(p[0], p[1], p[2]);
    FIELD_MSGBG_MsgWinPrintStr((u32)handle, (u16)a, (u16)b, (u32)p[1]);
}
