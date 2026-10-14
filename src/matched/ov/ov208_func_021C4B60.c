/*
 * function: ZUKAN_DETAIL_FORM_FlushPrintWindow
 * address:  0x021C4B60
 * packet:   pkt_ov208_021C4B60
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ov208Menu {
    u8  pad0[0x554];
    u32 win[5];
    u32 active[5];
    u32 print[5];
};

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct Cfg;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *win);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 layer);

void ZUKAN_DETAIL_FORM_FlushPrintWindow(void *a0, struct Ov208Menu *p, int a2, int i)
{
    u32 w;

    if (p->active[i] != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)p->print[i], (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i]))) == 0) {
        w = p->win[i];
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        p->active[i] = 0;
    }
}
