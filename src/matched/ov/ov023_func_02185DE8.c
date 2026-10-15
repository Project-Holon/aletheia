/*
 * function: OEKAKI_DrawStrokes
 * address:  0x02185DE8
 * packet:   pkt_ov023_02185DE8
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gOekakiBrushPixels     0x02186C34  data  ov023  a4
 *   OEKAKI_DrawLine  0x02185C38  thumb  ov023
 *   OEKAKI_StoreLastPoints  0x02185DA8  thumb  ov023
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 */

struct e6 {
    unsigned char b[4];
    unsigned char c : 3;
    unsigned char n : 3;
    unsigned char d : 2;
    unsigned char pad;
};

struct o4 {
    unsigned char x;
    unsigned char y;
    unsigned short n;
};

extern char gOekakiBrushPixels[];
extern void OEKAKI_DrawLine(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d);
extern void OEKAKI_StoreLastPoints(struct e6 *e, struct o4 *o);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(unsigned int index);

void OEKAKI_DrawStrokes(char *p, struct e6 *e, struct o4 *o, int flag)
{
    int hit;
    int i;
    int x;
    int y;

    hit = 0;
    for (i = 0; i < 5; i++) {
        if (e[i].n == 2) {
            x = e[i].b[0] - 9;
            y = e[i].b[2] - 0x11;
            OEKAKI_DrawLine((int)p, (int)(gOekakiBrushPixels + e[i].d * 0xc0 + e[i].c * 0x18),
                          e[i].b[1] - 9, e[i].b[3] - 0x11, &x, &y, 1, o[i].n);
            hit = 1;
        }
    }
    if (hit && flag) {
        BMP_WIN_TransferChars((struct Descriptor *)p);
        BMP_WIN_MakeScreen((struct Cfg *)p);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    }
    OEKAKI_StoreLastPoints(e, o);
    for (i = 0; i < 5; i++)
        e[i].n = 0;
}
