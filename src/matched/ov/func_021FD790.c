/*
 * function: func_021FD790
 * address:  0x021FD790
 * packet:   pkt_021FD790
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_021F91DC  0x021F91DC  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
} Pane;

struct Cfg;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);

void func_021FD790(void *bank, Pane *pane, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);
    void *win;

    func_021F91DC(pane->win, (u32)str, 0, 0, 1, 0x3C40, (u32)g);
    win = pane->win;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_020409B4(BMP_WIN_GetBgLayer(win));
    STRBUF_Delete(str);
}
