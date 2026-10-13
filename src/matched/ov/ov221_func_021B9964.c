/*
 * function: func_021B9964
 * address: 0x021B9964
 * packet: pkt_ov221_021B9964
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * note: 2026-10-05 (wP6 U2): twin of ov222 021B9964 without window table, string widths and 437DC calls.
 *
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200873C 0x0200873C thumb
 *   CONFIG_GetAppliedFlag 0x020083E4 thumb
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   func_02045B38 0x02045B38 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B9B18 0x021B9B18 thumb ov221
 *   d_021BA174 0x021BA174 data a1
 * */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj {
    u16 heap; u16 pad2; void **info; u32 pad8;
    void *str; void *bmp; u8 pad14[4];
    void *bank; void *ptr[5]; u32 done[5];
};
extern const u8 d_021BA174[];
extern char *GAME_DATA_GetMyStatus(void *);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_021B9B18(unsigned char *p);
void func_021B9964(struct Obj *p)
{
    u8 i;
    char *msg;
    u32 ws, x, t;
    msg = GAME_DATA_GetMyStatus(*p->info);
    p->bank = 0;
    for (i = 0; i < 5; i++) {
        p->ptr[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->done[1] = 1;
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0x1e0, 0x20, p->heap);
    p->bank = func_02045B38(0, 3, 1, p->heap);
    for (i = 0; i < 5; i++) {
        p->ptr[i] = (void *)BMP_WIN_Create(d_021BA174[i*9], d_021BA174[i*9+1], d_021BA174[i*9+2], d_021BA174[i*9+3], d_021BA174[i*9+4], d_021BA174[i*9+5], d_021BA174[i*9+6]);
        BMP_Clear(BMP_WIN_GetBmp(p->ptr[i]), 0);
        BMP_WIN_TransferChars(p->ptr[i]);
    }
    ws = (u32)func_0201EC64(p->heap);
    t = (u32)func_02045EC0(p->bank, 0);
    x = (u32)STRBUF_Create(0x20, p->heap);
    func_0201F02C((struct WordSet *)ws, 0, msg);
    func_0201F250((struct WordSet *)ws, (void *)x, (void *)t);
    PRINTSYS_PrintQueColor(p->bmp, (u32)BMP_WIN_GetBmp(p->ptr[2]), 0, 0, x, (u32)p->str, 0x440);
    STRBUF_Delete((struct U16Vec *)x);
    STRBUF_Delete((struct U16Vec *)t);
    func_0201ED04((struct WordSet *)ws);
    t = (u32)func_02045EC0(p->bank, 1);
    PRINTSYS_PrintQueColor(p->bmp, (u32)BMP_WIN_GetBmp(p->ptr[3]), 0, 0, t, (u32)p->str, 0x440);
    STRBUF_Delete((struct U16Vec *)t);
    t = (u32)func_02045EC0(p->bank, 3);
    PRINTSYS_PrintQueColor(p->bmp, (u32)BMP_WIN_GetBmp(p->ptr[4]), 0, 0, t, (u32)p->str, 0x440);
    STRBUF_Delete((struct U16Vec *)t);
    for (i = 1; i < 5; i++) {
        void *d = p->ptr[i];
        BMP_WIN_TransferChars(d);
        BMP_WIN_MakeScreen(d);
        func_02041B6C(BMP_WIN_GetBgLayer(d));
    }
    func_021B9B18((unsigned char *)p);
}
