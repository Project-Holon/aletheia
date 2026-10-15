/*
 * function: GTSNEGO_MSG_PrintListEntry
 * address: 0x021D8118
 * packet: pkt_ov120_021D8118
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: the allocator's first argument is 6, not the 1 its ov120 twins pass:
 *       021D813A `movs r0, #6` is both the multiplier for n*6+1 and r0 at the
 *       blx. The caller narrows n*6+1 to a byte (021D8140/021D8144), so the
 *       allocator's parameters are the u8 of the ov120_func_021D7F5C twin.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Clear 0x0204581C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
int GTSNEGO_MSG_PrintListEntry(char *p, void *r, int n)
{
    void **t=(void **)(p+0x6c);
    void *q;
    if(!t[n]) t[n]=(void *)BMP_WIN_Create((u8)6,(u8)6,(u8)(n*6+1),(u8)24,4,11,1);
    q=t[n];
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    STRBUF_Clear(*(void **)(p+0x20));
    STRBUF_Clear(*(void **)(p+0x18));
    WORDSET_SetSlotMyStatus(*(void **)(p+0x10),0,r);
    WORDSET_SetSlotNumber(*(void **)(p+0x10),1,func_02008534(r),5,2,1);
    WORDSET_SetSlotFromMsgE7(*(void **)(p+0x10),2,func_0200856C(r));
    MSGDATA_ReadString(*(void **)(p+0xc),28,*(void **)(p+0x20));
    WORDSET_CopyTaggedText(*(void **)(p+0x10),*(void **)(p+0x18),*(void **)(p+0x20));
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,*(void **)(p+0x18),*(void **)(p+0x14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    return 0;
}
