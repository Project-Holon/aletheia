/*
 * function: WORLDTRADE_DEPOSIT_PrintBankString
 * address:  0x021F7FD4
 * packet:   pkt_021F7FD4
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
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, 0, y, 0, color, g);
        STRBUF_Delete(str);
    }
}
