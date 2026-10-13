/*
 * function: BTL_HANDLER_ITEM_BrightPowderLowerAccuracy
 * address:  0x021DE374
 * packet:   pkt_ov093_021DE374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
typedef signed int     s32;
extern void BTL_EVENT_MultiplyVar(int key, s32 m);

void BTL_HANDLER_ITEM_BrightPowderLowerAccuracy(int a, int b, int c)
{
    u32 v;

    if (c == BTL_EVENT_GetVar(4)) {
        v = 100 - BTL_HANDLER_ITEM_GetParam(a, 2);
        BTL_EVENT_MultiplyVar(0x35, (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) / 100);
    }
}
