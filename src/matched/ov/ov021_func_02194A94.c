/*
 * function: TALKMSGWIN_AddBmpWin
 * address:  0x02194A94
 * packet:   pkt_ov021_02194A94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

typedef struct { u8 pad[0x10]; u32 x10; u8 x14; u8 x15; } Obj;

u32 TALKMSGWIN_AddBmpWin(Obj *a, u32 b, u32 c, u32 d, u8 e)
{
    u32 w;

    w = BMP_WIN_Create((u8)a->x10, b, c, d, e, a->x15, 1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w)), 15);
    BMP_WIN_TransferChars((struct Descriptor *)w);
    return w;
}
