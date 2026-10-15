/*
 * function: WORLDTRADE_SEARCH_DrawHistoryHeader
 * address:  0x021FF474
 * packet:   pkt_021FF474
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped  0x021F91DC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 layer);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int WORLDTRADE_INPUT_PrintStringAlignedWrapped(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *g)
{
    void *str;
    u16 color;
    u8 pal;

    color = 0x3C40;
    if (flag != 0) {
        color = 0x440;
        pal = 0;
    } else {
        pal = 2;
    }
    BG_SYS_FillTileMap(1, 0x11, 2, 0xF, 4, pal);
    func_020409B4(1);
    str = func_02045EC0(bank, 0x4B);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win, (u32)str, 0, 0, 0, color, (u32)g);
    STRBUF_Delete(str);
}
