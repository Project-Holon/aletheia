/*
 * function: BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats
 * address: 0x021DE228
 * packet: pkt_ov093_021DE228
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasLoweredStatStage 0x021D5D68 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char    s8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasLoweredStatStage(s8 *p);
extern void BTL_HANDLER_ITEM_PushUseItem(void *, void *, int);
void BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats(int a, void *b, int c, int a3) { if (BTL_POKEPARAM_HasLoweredStatStage(func_021C7CF4(b,c))) BTL_HANDLER_ITEM_PushUseItem((void *)a,b,c); }
