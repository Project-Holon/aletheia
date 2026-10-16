/*
 * function: ZUKAN_INFO_DrawMessage
 * address: 0x021BAA08
 * packet: pkt_ov206_021BAA08
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   ZUKAN_INFO_DrawText 0x021BA960 thumb ov206
 *   STRBUF_Delete 0x02045808 arm
 */
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void ZUKAN_INFO_DrawText(int heap, int window, void *printer, int font, int input, unsigned short right, unsigned short y, unsigned short color, int alignment, int expansion);
extern void STRBUF_Delete(struct U16Vec *vec);
void ZUKAN_INFO_DrawMessage(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int text=(int)func_02045EC0(bank,message);
    ZUKAN_INFO_DrawText(heap,window,printer,font,text,x,y,color,alignment,expansion);
    STRBUF_Delete((struct U16Vec *)text);
}
