/*
 * function: FIELD_MSGBG_TalkWinPrintStr
 * address:  0x02191348
 * packet:   pkt_ov021_02191348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TALKMSGWIN_GetBmpWin  0x02194990  thumb  ov021
 *   TALKMSGWIN_Reprint  0x0219499C  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetCharWait  0x02193210  thumb  ov021
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 TALKMSGWIN_GetBmpWin(u32, u32);
struct CharBuf;
struct Descriptor;
extern void TALKMSGWIN_Reprint(u8 *p, int i, u32 b, u32 c);
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 func_020409B4(u32);

u32 FIELD_MSGBG_TalkWinPrintStr(u32 *a, u32 b)
{
    u32 x = TALKMSGWIN_GetBmpWin(a[2], *((u8 *)a + 1));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)x)), 255);
    TALKMSGWIN_Reprint((u8 *)a[2], *((u8 *)a + 1), b, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)(a[5] + 0x160)));
    return func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)x));
}
