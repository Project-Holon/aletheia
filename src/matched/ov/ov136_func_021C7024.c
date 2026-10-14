/*
 * unit: yes
 * function: MB_SEQ_ShowMessage2, MB_SEQ_OpenConfirmMenuKind1
 * address: 0x021C7024
 * packet: pkt_ov136_021C7024
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_SEQ_PrintMenuMessage 0x021C630C thumb ov136
 *   MB_SEQ_SetMessageWait 0x021C71A8 thumb ov136
 *   MB_SEQ_OpenMenuKind 0x021C71BC thumb ov136
 * extent: stops before separately filed leaf MB_SEQ_FinishPartyListChoice.
 */
extern void MB_SEQ_PrintMenuMessage(unsigned char *p, unsigned int i);
extern int MB_SEQ_SetMessageWait(char *, int, int);
typedef unsigned char  u8;
extern int MB_SEQ_OpenMenuKind(u8 *p, int v);
void MB_SEQ_ShowMessage2(char *p)
{
    MB_SEQ_PrintMenuMessage((unsigned char *)p, 2);
    MB_SEQ_SetMessageWait(p, 0, 0x13);
}
int MB_SEQ_OpenConfirmMenuKind1(char *p)
{
    return MB_SEQ_OpenMenuKind((u8 *)p, 1);
}
