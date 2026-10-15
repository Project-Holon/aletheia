/*
 * function: LOCAL_TVT_CHARA_DrawLabel
 * address: 0x021B71B8
 * packet: pkt_ov174_021B71B8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B7380 0x021B7380 data ov174 a1
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u8 x,y; } Pair;
extern const Pair d_021B7380[];
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 *GAME_DATA_GetMyStatus(void *);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
void LOCAL_TVT_CHARA_DrawLabel(u8 *p,u8 *q)
{
    void *s;
    void *dst;
    void *ws;
    u8 *save;
    *(u32 *)(q+0x18)=BMP_WIN_Create(0,(u8)(d_021B7380[q[0]].x+2),(u8)(d_021B7380[q[0]].y+1),12,2,12,1);
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(q+0x18)),0);
    BMP_WIN_TransferChars(*(void **)(q+0x18));
    BMP_WIN_MakeScreen(*(void **)(q+0x18));
    BG_SYS_PushTile(0);
    s=func_02045EC0(*(void **)(p+0x68),q[2]);
    if(q[2]==0 || q[2]==5){
        dst=STRBUF_Create(128,*(u16 *)p);
        save=GAME_DATA_GetMyStatus(*(void **)(*(u8 **)(p+0x30)+4));
        ws=WORDSET_CreateDefault(*(u16 *)p);
        WORDSET_SetSlotMyStatus(ws,0,save);
        WORDSET_CopyTaggedText(ws,dst,s);
        STRBUF_Delete(s);
        WORDSET_DeleteStrbufED04(ws);
        s=dst;
    }
    q[7]=func_0201D304(s,*(u32 *)(p+0x60),0);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16)((96-q[7])/2+1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16)((96-q[7])/2-1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16)((96-q[7])/2),2,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16)((96-q[7])/2),0,(u32)s,*(u32 *)(p+0x60),0x3c00);
    PRINTSYS_PrintQueColor(*(void **)(p+0x78),(u32)BMP_WIN_GetBmp(*(void **)(q+0x18)),(s16)((96-q[7])/2),1,(u32)s,*(u32 *)(p+0x60),0x400);
    STRBUF_Delete(s);
    *(u32 *)(q+0x14)=1;
}
