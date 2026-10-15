/*
 * function: BOX2_SEQ_ClearMessageWindow
 * address:  0x021EBA30
 * packet:   pkt_ov170_021EBA30
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *
 * Clears a message window to colour 15 and draws its frame.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_ClearMessageWindow(unsigned char *p, void *win)
{
    BMP_Clear(BMP_WIN_GetBmp(win), 0xF);
    BMP_MENUWORK_DrawWindow(win, 2, (unsigned short)*(int *)(WORK(p) + 0x178), 10);
}
