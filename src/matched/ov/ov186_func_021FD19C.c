/*
 * function: BR_UTIL_SetWindowTextBuf
 * address: 0x021FD19C
 * packet: pkt_ov186_021FD19C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned BR_RES_GetFont(char *p);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
void BR_UTIL_SetWindowTextBuf(char *p,void *q,void *text)
{
    BR_UTIL_SetTextFromBuffer(p,text,(void *)BR_RES_GetFont(q),0x3dac);
}
