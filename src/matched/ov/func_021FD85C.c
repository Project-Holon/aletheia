/*
 * function: WORLDTRADE_LIST_PrintNames
 * address:  0x021FD85C
 * packet:   pkt_021FD85C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

void WORLDTRADE_LIST_PrintNames(Pane2 *pane, void *s1, void *s2, void *g)
{
    BMP_Clear(BMP_WIN_GetBmp(pane->win0), 0);
    BMP_Clear(BMP_WIN_GetBmp(pane->win1), 0);
    if (s1 != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win0, (u32)s1, 0, 0, 0, 0x440, (u32)g);
    }
    if (s2 != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win1, (u32)s2, 0, 0, 0, 0x440, (u32)g);
    }
}
