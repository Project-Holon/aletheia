/*
 * unit:     yes
 * function: BTL_HANDLER_ITEM_StickRaiseCriticalRankFarfetchd, BTL_HANDLER_ITEM_GetZoomLensHandlers
 * address:  0x021DE5DC
 * packet:   pkt_ov093_021DE5DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gZoomLensHandlerTable     0x021F13D4  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int k);
extern void *func_021C7CF4(int *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int gZoomLensHandlerTable;

void BTL_HANDLER_ITEM_StickRaiseCriticalRankFarfetchd(int u, int a, int b)
{
    u8 v;
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4((int *)a, b)) == 0x53) {
            v = BTL_EVENT_GetVar(0x2c);
            BTL_EVENT_OverwriteVar(0x2c, (u8)(v + 2));
        }
    }
}

int *BTL_HANDLER_ITEM_GetZoomLensHandlers(int *p)
{
    *p = 1;
    return &gZoomLensHandlerTable;
}
