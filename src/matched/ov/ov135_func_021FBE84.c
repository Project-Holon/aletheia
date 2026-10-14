/*
 * function: WORLDTRADE_INPUT_PrintFrameString
 * address:  0x021FBE84
 * packet:   pkt_021FBE84
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   WORLDTRADE_INPUT_PutBmpWinString  0x021FAC50  thumb
 *   STRBUF_Delete  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORLDTRADE_INPUT_PutBmpWinString(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void STRBUF_Delete(struct U16Vec *vec);

void WORLDTRADE_INPUT_PrintFrameString(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g)
{
    void *str = func_02045EC0(bank, index);

    WORLDTRADE_INPUT_PutBmpWinString(mgr, win, str, x, color, g);
    STRBUF_Delete(str);
}
