/*
 * function: WORLDTRADE_LIST_PrintLabel
 * address:  0x021FD760
 * packet:   pkt_021FD760
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
} Pane;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

void WORLDTRADE_LIST_PrintLabel(void *bank, Pane *pane, u32 index, void *g, u16 color)
{
    void *str = func_02045EC0(bank, index);

    WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win, (u32)str, 0, 2, 0, color, (u32)g);
    STRBUF_Delete(str);
}
