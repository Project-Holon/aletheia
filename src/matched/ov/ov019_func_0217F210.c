/*
 * function: UNION_MSG_SetupPrintTalkMsg
 * address: 0x0217F210
 * packet: pkt_ov019_0217F210
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_MSG_SetupTalkWindow 0x0217F098 thumb ov019
 *   UNION_MSG_RegisterPartnerWords 0x0217EE90 thumb ov019
 *   UNION_MSG_PrintTalkMsg 0x0217F188 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void UNION_MSG_SetupTalkWindow(unsigned char *base, u8 *x);
struct Self;
extern void UNION_MSG_RegisterPartnerWords(struct Self *self);
extern void UNION_MSG_PrintTalkMsg(char *p, u32 a);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b)
{
    UNION_MSG_SetupTalkWindow(p, a);
    UNION_MSG_RegisterPartnerWords((struct Self *)p);
    UNION_MSG_PrintTalkMsg((char *)p, b);
}
