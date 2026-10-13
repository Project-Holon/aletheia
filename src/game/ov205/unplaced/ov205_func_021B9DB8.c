/*
 * function: func_021B9DB8
 * address: 0x021B9DB8
 * packet: pkt_ov205_021B9DB8
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC is inside integrator-owned src/matched/arm9/unit_02045C44.c, whose function: lists only MSGDATA_CreateFromMemory; the missing MSGDATA_ReadString entry leaves the call at +0x42 unwitnessed. TU suggest-split found no viable piece.
 * extent: intended function ends at 021B9E50 (152 bytes); the rest of the handed 392-byte extent is rodata, not follower code.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,u8);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void STRBUF_Delete(struct U16Vec *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021B9DB8(char *p,u32 index,s16 x,s16 y)
{
    struct U16Vec *a,*b;
    a=STRBUF_Create(0x400,*(u16 *)p);
    b=STRBUF_Create(0x400,*(u16 *)p);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+20)),0);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+20)),15);
    MSGDATA_ReadString(*(struct MsgBank **)(p+12),index,a);
    func_0201F02C(*(struct WordSet **)(p+16),1,*(void **)(p+8));
    func_0201F250(*(struct WordSet **)(p+16),b,a);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(*(struct Descriptor **)(p+20)),x,y,b,*(void **)(p+24));
    STRBUF_Delete(a);
    STRBUF_Delete(b);
    BMP_WIN_TransferChars(*(struct Descriptor **)(p+20));
    func_02041B6C(BMP_WIN_GetBgLayer(*(struct Descriptor **)(p+20)));
}
