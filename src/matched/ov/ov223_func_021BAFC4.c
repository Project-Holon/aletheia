/*
 * function: func_021BAFC4
 * address: 0x021BAFC4
 * packet: pkt_ov223_021BAFC4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct MsgBank;
struct StrObj;
struct Descriptor;
struct U16Vec;
struct CharBuf;
struct Cfg;
struct Rec3;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
struct Bmp;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
struct Bmp;
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021BAFC4(char *p, int idx)
{
    struct Descriptor *desc = *(struct Descriptor **)(p + 0x23C);
    s16 x = 0;
    s16 y = 0;
    unsigned w, h;
    unsigned W, H;
    BMP_Clear((struct CharBuf *)func_02045770(desc), 0);
    if (*(u32 *)(p + 0x250) != 0)
        func_0201CE48(*(struct Rec3 **)(p + 0x250));
    if (*(u32 *)(p + 0x258) != 0)
        STRBUF_Delete(*(struct U16Vec **)(p + 0x258));
    *(void **)(p + 0x258) = func_02045EC0(*(struct MsgBank **)(p + 0x234), idx);
    w = (u16)func_0201D304(*(struct StrObj **)(p + 0x258), *(unsigned *)(p + 0x18), 0);
    h = (u16)func_0201D42C(*(struct StrObj **)(p + 0x258), *(void **)(p + 0x18));
    W = BMP_GetWidth(func_02045770(desc));
    H = BMP_GetHeight(func_02045770(desc));
    if (W > w)
        x = ((int)(W - w)) / 2;
    if (H > h)
        y = ((int)(H - h)) / 2;
    *(u32 *)(p + 0x250) = PRINTSYS_PrintStream((u32)desc, x, y, *(u32 *)(p + 0x258), *(u32 *)(p + 0x18), func_02012FFC(),
                                         *(u32 *)(p + 0x254), 2, *(u16 *)p, 0);
    BMP_WIN_TransferChars(desc);
    BMP_WIN_MakeScreen((struct Cfg *)desc);
    func_02041B6C(func_02045730(desc));
}
