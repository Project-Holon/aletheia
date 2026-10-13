/*
 * function: IRC_RHYTHM_PrintCenteredMessage
 * address: 0x021B7F80
 * packet: pkt_ov104_021B7F80
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RHYTHM_PrintCenteredMessageColor 0x021B7F90 thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_RHYTHM_PrintCenteredMessageColor(u8 *,void *,int,u16);
void IRC_RHYTHM_PrintCenteredMessage(u8 *p,void *a,int b) { IRC_RHYTHM_PrintCenteredMessageColor(p,a,b,0x3dc4); }
