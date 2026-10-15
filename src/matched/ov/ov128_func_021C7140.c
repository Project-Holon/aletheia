/*
 * function: func_021C7140
 * address: 0x021C7140
 * packet: pkt_ov128_021C7140
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C63AC 0x021C63AC thumb ov128
 *   STRBUF_Create 0x020457B0 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   WF2DMAP_TOUCH_TransferScreen 0x021CA4B4 thumb ov128
 *   STRBUF_Delete 0x02045808 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 */
#include "../include/Obj02482.h"
#include "../include/Obj02841.h"
#include "../include/Obj14034.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C63AC(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
struct MsgBank;
struct R;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void WF2DMAP_TOUCH_TransferScreen(char *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *,u32,u32,void **,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
struct P {
    u8 pad00[44];
    void *buf;
    void *text1;
    u16 color1;
    u16 pad36;
    u32 flag1;
    void *text2;
    u16 color2;
    u16 pad42;
    u32 flag2;
    void *menu;
};
void func_021C7140(struct P *p, u8 *a, u8 *ctx, u16 heap)
{
    int i;
    void *buf;
    void *text;
    u32 width;
    func_021C63AC(ctx,(u32 *)((u8 *)p+12),3,4,5,24,20,10,1,0);
    func_021C63AC(ctx,(u32 *)((u8 *)p+28),1,2,19,27,4,10,172,0);
    p->buf=STRBUF_Create(128,heap);
    buf=STRBUF_Create(128,heap);
    text=STRBUF_Create(128,heap);
    WORDSET_SetSlotMyStatus(((struct Obj02482 *)ctx)->f0,0,GAME_DATA_GetMyStatus(((struct Obj14034 *)a)->f4));
    for(i=0;i<3;i++) {
        MSGDATA_ReadString(((struct Obj02482 *)ctx)->f4,i+1,text);
        WORDSET_CopyTaggedText(((struct Obj02482 *)ctx)->f0,buf,text);
        width=func_0201D304((struct StrObj *)((u32)buf),((struct Obj02482 *)ctx)->f17C,0);
        TOUCHBAR_PrintAligned((u8 *)p+12,(void *)(((struct Obj02482 *)ctx)->f34),(192-width)/2,i*40+8,(u32)buf,((struct Obj02482 *)ctx)->f17C,0x440,0);
    }
    WF2DMAP_TOUCH_TransferScreen(((struct Obj02841 *)p)->fC);
    STRBUF_Delete(buf);
    STRBUF_Delete(text);
    ((struct Obj02841 *)p)->f14=ARC_UTIL_LoadPaletteDataFromHandle(((struct Obj02482 *)ctx)->f8,13,0,(void **)((u8 *)p+24),heap);
    p->text1=func_02045EC0(((struct Obj02482 *)ctx)->f4,66);
    p->color1=0x39e3;
    p->flag1=0;
    p->text2=func_02045EC0(((struct Obj02482 *)ctx)->f4,67);
    p->color2=0x39e3;
    p->flag2=0;
    p->menu=APP_TASKMENU_RES_Create(1,14,((struct Obj02482 *)ctx)->f17C,((struct Obj02482 *)ctx)->f34,heap);
}
