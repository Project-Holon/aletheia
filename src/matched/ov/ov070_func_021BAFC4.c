/*
 * function: ITEMMENU_PrintMoney
 * address: 0x021BAFC4
 * packet: pkt_ov070_021BAFC4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: 0x02045CAC arm9, two call sites have no outside witness.
 * Existing unit src/matched/arm9/unit_02045C44.c contains its body but
 * lists only MSGDATA_CreateFromMemory in function:, omitting MSGDATA_ReadString.
 * Lever: unsigned long win and distinct pointer/u32/unsigned-long address
 * expressions reproduce recomputation and colours; enum win leaves 10B.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_GetPoints 0x0200C274 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   ITEMMENU_PrintToWindow 0x021BB6E0 thumb ov070
 *   ITEMMENU_FlushWindowAt 0x021BB724 thumb ov070
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;struct CharBuf;struct MsgBank;struct Blk34;struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void *GAME_DATA_GetMiscSave(int *);
extern u32 BEACON_GetPoints(struct Blk34 *);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern void ITEMMENU_PrintToWindow(int,u32 *,u32,u16,s16,u16);
extern void ITEMMENU_FlushWindowAt(void **);
#define P(k) (*(void **)((u32)p+(k)))
#define W(k) (*(u32 *)((u32)p+(k)))
void ITEMMENU_PrintMoney(u8 *p)
{
 unsigned long win = 0x764;
 BMP_Clear(BMP_WIN_GetBmp(P(win)),0);
 BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+(win-8))),0);
 MSGDATA_ReadString(P(0x51C),0x51,P(0x524));
 ITEMMENU_PrintToWindow((int)p,(u32 *)((u32)p+(win-8)),W(0x524),0,4,0x3C40);
 ITEMMENU_FlushWindowAt((void **)((unsigned long)p+(win-8)));
 MSGDATA_ReadString(P(0x51C),0x52,P(0x524));
 WORDSET_SetSlotNumber(P(0x520),0,BEACON_GetPoints(GAME_DATA_GetMiscSave(P(0))),7,1,1);
 WORDSET_CopyTaggedText(P(0x520),P(0x528),P(0x524));
 ITEMMENU_PrintToWindow((int)p,(u32 *)((u32)p+win),W(0x528),0,4,0x3C40);
 ITEMMENU_FlushWindowAt((void **)((u32)p+win));
}
