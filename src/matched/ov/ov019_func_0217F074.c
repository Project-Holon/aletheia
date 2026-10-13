/*
 * function: UNION_MSG_CloseAllWindows
 * address: 0x0217F074
 * packet: pkt_ov019_0217F074
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_MSG_DeleteRegulationWindow 0x0217F7B8 thumb ov019
 *   UNION_MSG_DeleteTitleWindow 0x0217F624 thumb ov019
 *   UNION_MSG_DeleteYesNo 0x0217F24C thumb ov019
 *   UNION_MSG_DeleteMenu 0x0217F2F4 thumb ov019
 *   UNION_MSG_DeleteTalkWindow 0x0217F128 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void UNION_MSG_DeleteRegulationWindow(char *p);
extern void UNION_MSG_DeleteTitleWindow(char *p);
extern void UNION_MSG_DeleteYesNo(u8 *p);
extern void UNION_MSG_DeleteMenu(u8 *p);
extern void UNION_MSG_DeleteTalkWindow(unsigned char *base);
void UNION_MSG_CloseAllWindows(void *p)
{
    UNION_MSG_DeleteRegulationWindow(p);
    UNION_MSG_DeleteTitleWindow(p);
    UNION_MSG_DeleteYesNo(p);
    UNION_MSG_DeleteMenu(p);
    UNION_MSG_DeleteTalkWindow(p);
}
