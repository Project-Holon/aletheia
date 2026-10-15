/*
 * function: NAMEIN_GRAPHIC_AppendString
 * address: 0x021F23B8
 * packet: pkt_ov194_021F23B8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 STRBUF_GetEosChar(void);
extern int NAMEIN_GRAPHIC_AppendChar(char *,u16);
void NAMEIN_GRAPHIC_AppendString(char *p,const u16 *q) {while(*q!=STRBUF_GetEosChar()) {if(!NAMEIN_GRAPHIC_AppendChar(p,*q)) break;q++;}}
