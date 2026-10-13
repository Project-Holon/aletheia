/*
 * unit:     yes
 * function: BTL_HANDLER_ITEM_LaxIncenseLowerAccuracy, BTL_HANDLER_ITEM_GetMuscleBandHandlers
 * address:  0x021DE668
 * packet:   pkt_ov093_021DE668
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   gMuscleBandHandlerTable     0x021F13E4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int gMuscleBandHandlerTable;

void BTL_HANDLER_ITEM_LaxIncenseLowerAccuracy(int a, int b, int c)
{
    u16 v;
    float x;

    if (c == BTL_EVENT_GetVar(4)) {
        v = 100 - BTL_HANDLER_ITEM_GetParam(a, 2);
        if (v != 0)
            x = 0.5f + (float)(v << 12);
        else
            x = (float)(v << 12) - 0.5f;
        BTL_EVENT_MultiplyVar(0x35, (int)x / 100);
    }
}

int *BTL_HANDLER_ITEM_GetMuscleBandHandlers(int *p)
{
    *p = 1;
    return &gMuscleBandHandlerTable;
}
