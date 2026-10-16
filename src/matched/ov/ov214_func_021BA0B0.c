/*
 * function: BTL_REC_SEL_ClearWindowWhite
 * address: 0x021BA0B0
 * packet: pkt_ov214_021BA0B0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021BA0DA.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct BtlRecSel {
    unsigned char pad_0[0x6C];
    void * win1;              /* 0x6C */
};
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor; struct Cfg; struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
void BTL_REC_SEL_ClearWindowWhite(int unused, char *p)
{
    struct Descriptor *d;
    BMP_Clear(BMP_WIN_GetBmp(((struct BtlRecSel *)p)->win1), 15);
    d = ((struct BtlRecSel *)p)->win1;
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen((struct Cfg *)d);
    func_02041B6C(BMP_WIN_GetBgLayer(d));
}
