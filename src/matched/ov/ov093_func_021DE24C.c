/*
 * function: BTL_HANDLER_ITEM_WhiteHerbCheckAfterAction
 * address: 0x021DE24C
 * packet: pkt_ov093_021DE24C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats 0x021DE228 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats(int, void *, int, int);
void BTL_HANDLER_ITEM_WhiteHerbCheckAfterAction(int a, void *b, int c, int d) { if (BTL_EVENT_GetVar(12) != 6) BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats(a,b,c,d); }
