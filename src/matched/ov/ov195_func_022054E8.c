/*
 * function: SHINKA_DEMO_SetupMessageBox
 * address:  0x022054E8
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: either build the +0x6c render
 * node from the +0x74 id (and flush the +0x104/+0x108 stage), or arm the
 * +0x88 transition word with 2.
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);

void SHINKA_DEMO_SetupMessageBox(int a, int *p, int flag)
{
    if (flag != 0) {
        int *q;

        BMP_MENUWORK_DrawWindow((void *)p[0x1b], 0, (unsigned short)p[0x1d], 2);
        BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)p[0x1b])), 0xf);
        q = (int *)p[0x1b];
        BMP_WIN_TransferChars((struct Descriptor *)q);
        BMP_WIN_MakeScreen((struct Cfg *)((int)q));
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)((int)q)));
    } else {
        p[0x22] = 2;
    }
}
