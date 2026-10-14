/*
 * function: WORLDTRADE_DEPOSIT_PrintModeLabel
 * address:  0x021F8104
 * packet:   pkt_021F8104
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
 *   WORLDTRADE_DEPOSIT_GetModeFontColor  0x021F8078  thumb
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   tbl_02202EB0   0x02202EB0  data
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const u32 tbl_02202EB0[];

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color);
extern u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, x, y, 0, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), g);
        STRBUF_Delete(str);
    }
}
