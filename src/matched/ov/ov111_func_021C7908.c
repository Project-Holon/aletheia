/*
 * function: VIEWER_ACTOR_FlushBgWindow
 * address:  0x021C7908
 * packet:   pkt_ov111_021C7908
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work;

extern void BMP_MENUWORK_DrawWindow(void *p, int a, int b, int c);
struct Cfg;
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(unsigned int index);

void VIEWER_ACTOR_FlushBgWindow(Work *p)
{
    void *v;

    BMP_MENUWORK_DrawWindow(p->f8, 0, 1, 0xE);
    v = p->f8;
    BMP_WIN_TransferChars(v);
    BMP_WIN_MakeScreen(v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(v));
}
