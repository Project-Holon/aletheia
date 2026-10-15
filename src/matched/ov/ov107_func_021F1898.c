/*
 * function: MB_UTIL_MSG_ClearWindow
 * address:  0x021F1898
 * packet:   pkt_ov107_021F1898
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   TALKMSGWIN_ClearWindowFrame  0x02194A34  thumb
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
    unsigned char pad14[0x40];
    void *f54;
    unsigned char pad58[4];
    void *f5C;
} Ov107Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
void *BMP_WIN_GetBmp(struct Descriptor *p);
void BMP_Clear(struct CharBuf *buf, u8 value);
int TALKMSGWIN_ClearWindowFrame(void *, void *);
void BG_SYS_PushTile(u32 index);
void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
void TIME_ICON_Delete(u8 *p);

void MB_UTIL_MSG_ClearWindow(Ov107Ctx *p)
{
    BMP_Clear(BMP_WIN_GetBmp(p->f10), 0);
    if (p->f04 == 8) {
        TALKMSGWIN_ClearWindowFrame(p->f54, p->f10);
        BG_SYS_PushTile(p->f02);
    } else {
        BMP_MENUWORK_DrawWindowBorder(p->f10, 1);
    }
    if (p->f5C != 0) {
        TIME_ICON_Delete(p->f5C);
        p->f5C = 0;
    }
}
