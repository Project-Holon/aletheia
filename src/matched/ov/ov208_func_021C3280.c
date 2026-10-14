/*
 * function: ZUKAN_DETAIL_VOICE_DrawSpeciesName
 * address: 0x021C3280
 * packet: pkt_ov208_021C3280
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry 0x021BC3C0 thumb ov208
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_GetWidth 0x020437DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   ZUKAN_DETAIL_VOICE_FlushTimerWindow 0x021C3318 thumb ov208
 *   data_020A7370 0x020A7370 data a4
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct MsgBank; struct StrObj; struct Descriptor; struct Bmp; struct U16Vec; struct Key;
extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(struct Key *key);
extern void *func_02045EC0(struct MsgBank *bank,u32 index);
extern u32 func_0201D304(struct StrObj *s,u32 a,u32 b);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u16 BMP_GetWidth(const struct Bmp *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *s);
extern void ZUKAN_DETAIL_VOICE_FlushTimerWindow(u16 *heap, u8 *p, int key);
extern struct MsgBank *data_020A7370;
void ZUKAN_DETAIL_VOICE_DrawSpeciesName(u16 *heap,u8 *p,struct Key *key)
{
    struct StrObj *text;
    u16 width;
    u16 available;
    text=func_02045EC0(data_020A7370,ZUKAN_DETAIL_COMMON_GetCurrentEntry(key));
    width=func_0201D304(text,((struct Obj00146 *)p)->f4,0);
    available=BMP_GetWidth(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC));
    PRINTSYS_PrintQueColor(((struct Obj00146 *)p)->f8,(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC),(s16)((u16)((available-width)/2)),(s16)1,(u32)text,((struct Obj00146 *)p)->f4,0x3c40);
    STRBUF_Delete((struct U16Vec *)text);
    ((struct Obj00146 *)p)->f10=1;
    ZUKAN_DETAIL_VOICE_FlushTimerWindow(heap,p,(int)key);
}
