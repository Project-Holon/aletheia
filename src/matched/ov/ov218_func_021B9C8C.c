/*
 * function: UN_SELECT_UpdateFrameList
 * address:  0x021B9C8C
 * packet:   pkt_ov218_021B9C8C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UN_SELECT_SetActorVisible 0x021BA4FC thumb ov218
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   UN_SELECT_GetMsgData 0x021B9C80 thumb ov218
 *   UN_SELECT_DrawFrameListRow 0x021B9AE4 thumb ov218
 *   UN_SELECT_ContainsItem 0x021BA75C thumb ov218
 *   UN_SELECT_SetActorPos 0x021BA6E8 thumb ov218
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void UN_SELECT_SetActorVisible(char *ctx);
extern u32 FRAME_LIST_GetItemValue(char *p, int index);
extern unsigned FRAME_LIST_GetPrinter(char *p);
extern void *UN_SELECT_GetMsgData(u8 *p);
extern void UN_SELECT_DrawFrameListRow(u8 *p, u32 a, u32 b, void *c, u32 d);
extern int UN_SELECT_ContainsItem(char *p, int v);
extern void UN_SELECT_SetActorPos(u32 p, int sel, u32 y);
void UN_SELECT_UpdateFrameList(u8 *p, u32 a, u32 b, u8 *c, u32 d)
{
    u32 t;
    UN_SELECT_SetActorVisible((char *)p);
    FRAME_LIST_GetItemValue((char *)(*(u8 **)(p + 0x2C)), a);
    t = FRAME_LIST_GetPrinter((char *)(*(u8 **)(p + 0x2C)));
    UN_SELECT_DrawFrameListRow(*(u8 **)(p + 0x28), b, t, UN_SELECT_GetMsgData(*(u8 **)(p + 0x28)), a);
    if (UN_SELECT_ContainsItem((char *)p, a)) {
        UN_SELECT_SetActorPos((u32)p, d, (u32)(c + 0x14));
    }
}
