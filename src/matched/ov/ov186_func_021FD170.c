/*
 * function: BR_UTIL_SetWindowText
 * address: 0x021FD170
 * packet: pkt_ov186_021FD170
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,u16);
void BR_UTIL_SetWindowText(char *p,char *q,void *text)
{
    u32 font;
    font=BR_RES_GetFont(q);
    BR_UTIL_SetTextFromMessage(p,(void *)BR_RES_GetMsgData(q),text,(void *)font,0x3dac);
}
