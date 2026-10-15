/*
 * function: MONOLITH_TOOL_STATS_CreateWindows
 * address:  0x021B8B08
 * packet:   pkt_ov071_021B8B08
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Six-window twin of MONOLITH_TOOL_SUMMARY_CreateWindows.
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 */

typedef struct {
    int h[6];
    struct {
        int h;
        unsigned char on;
    } e[6];
} P;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Cfg;
void MONOLITH_TOOL_STATS_CreateWindows(int unused, P *p)
{
    extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern void BMP_WIN_TransferChars(struct Descriptor *);
    extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
    extern void BG_SYS_PushTile(u32 index);
    int i;

    p->h[0] = BMP_WIN_Create(4, 2, 0, 0x1e, 3, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[0]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[0]);
    p->h[1] = BMP_WIN_Create(4, 2, 5, 0x1e, 2, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[1]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[1]);
    p->h[2] = BMP_WIN_Create(4, 2, 8, 0x1e, 2, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[2]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[2]);
    p->h[3] = BMP_WIN_Create(4, 2, 0xe, 0x1e, 4, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[3]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[3]);
    p->h[4] = BMP_WIN_Create(4, 2, 0x10, 0x1e, 2, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[4]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[4]);
    p->h[5] = BMP_WIN_Create(4, 2, 0x12, 0x1e, 2, 0xd, 1);
    BMP_WIN_TransferChars((struct Descriptor *)p->h[5]);
    BMP_WIN_MakeScreen((struct Cfg *)p->h[5]);
    for (i = 0; i < 6; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    BG_SYS_PushTile(4);
}
