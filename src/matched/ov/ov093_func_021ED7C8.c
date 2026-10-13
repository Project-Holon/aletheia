/*
 * function: BTLV_SCU_StartMsgWinFadeIn
 * address:  0x021ED7C8
 * packet:   pkt_ov093_021ED7C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { int h; int x; int y; int dx; int dy; u8 state; u8 cnt; };

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void BTLV_SCU_StartMsgWinFadeIn(struct S *s, int keep)
{
    if ((u8)(s->state + 0xff) <= 1) {
        if (keep == 0) {
            BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)s->h)), 0xc);
            BMP_WIN_TransferChars((struct Descriptor *)s->h);
        }
        s->x = 0;
        s->y = 0x10000;
        s->dx = 0x52aa;
        s->dy = -0x1800;
        s->cnt = 6;
        s->state = 4;
    }
}
