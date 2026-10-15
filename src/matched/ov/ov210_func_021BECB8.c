/*
 * function: ZKNSEARCH_MAIN_PrintMessageText
 * address: 0x021BECB8
 * packet: pkt_ov210_021BECB8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   ZKNSEARCH_MAIN_PrintWindowText 0x021BE44C thumb ov210
 *   ZKNSEARCH_MAIN_MakeWindowScreen 0x021BE49C thumb ov210
 */
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void ZKNSEARCH_MAIN_PrintWindowText(u8 *, int, unsigned, int, int, unsigned short, unsigned);
extern void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *);
typedef enum { off_ECB8 = 0x1c4 } Offset;
void ZKNSEARCH_MAIN_PrintMessageText(u8 *p, unsigned message)
{
    Offset offset = off_ECB8;
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + offset)), 6);
    ZKNSEARCH_MAIN_PrintWindowText(p, 15, message, 120, 0, 0x446, 2);
    ZKNSEARCH_MAIN_MakeWindowScreen(p + offset);
}
