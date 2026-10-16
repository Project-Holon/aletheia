/*
 * function: BEACON_DETAIL_DrawCurrentInfo
 * address: 0x0218544C
 * packet: pkt_ov219_0218544C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC at +0036 lacks a code-start witness; integrator-owned unit_02045C44.c omits MSGDATA_ReadString from function:. Required singleton TU finds no viable cut. No overlay leaves filed while ARM9 blocked.
 * lever: distinct outer buffer and block-scoped first/second buffers settle the eight-byte r4/r6 swap.
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }

 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BEACON_DETAIL_DrawTextRecord 0x02184D30 thumb ov219
 *   STRBUF_Delete 0x02045808 arm
 *   BEACON_DETAIL_FindNearestRecord 0x0218532C thumb ov219
 *   BEACON_DETAIL_GetEntryText 0x02185C84 thumb ov219
 *   BMP_WIN_TransferChars 0x02045334 arm
 * prototype: caller narrows allocation heap to u16 immediately before each call.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct U16Vec;struct Descriptor;struct CharBuf;struct MsgBank;struct Record;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void BEACON_DETAIL_DrawTextRecord(char *,struct Record *,struct Descriptor *,void *,u8,u8);
extern void STRBUF_Delete(struct U16Vec *);
extern int BEACON_DETAIL_FindNearestRecord(char *,u32 *);
extern int BEACON_DETAIL_GetEntryText(u32,u32,void *,void *,u32);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void BEACON_DETAIL_DrawCurrentInfo(char *p)
{
    struct U16Vec *buffer;
    u32 selected;
    if(*(u32 *)(p+0xC350)==0) {
        buffer=STRBUF_Create(1024,(u16)(*(u32 *)p));
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+0xC01C)),15);
        MSGDATA_ReadString(*(struct MsgBank **)(p+0xC070),15,buffer);
        BEACON_DETAIL_DrawTextRecord(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),buffer,0,0);
        STRBUF_Delete(buffer);
    } else {
        struct U16Vec *first,*second;
        if(BEACON_DETAIL_FindNearestRecord(p,&selected)) {
            first=STRBUF_Create(64,(u16)(*(u32 *)p));
            second=STRBUF_Create(64,(u16)(*(u32 *)p));
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+0xC01C)),15);
            BEACON_DETAIL_GetEntryText(*(u16 *)(p+selected*48+66),*(u16 *)(p+selected*48+68),first,second,*(u32 *)p);
            if(*(u16 *)(p+selected*48+68)!=0)
                BEACON_DETAIL_DrawTextRecord(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),second,0,16);
            BEACON_DETAIL_DrawTextRecord(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),first,0,0);
            STRBUF_Delete(second);
            STRBUF_Delete(first);
            *(int *)(p+0xC2F4)=*(s16 *)(p+selected*48+24);
            *(int *)(p+0xC2F8)=*(s16 *)(p+selected*48+26);
        } else *(u32 *)(p+0xC350)=0;
    }
    BMP_WIN_TransferChars(*(struct Descriptor **)(p+0xC01C));
}
