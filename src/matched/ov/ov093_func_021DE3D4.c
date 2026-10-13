/*
 * function: BTL_HANDLER_ITEM_MachoBraceHalveSpeed, BTL_HANDLER_ITEM_GetQuickClawHandlers
 * address: 0x021DE3D4
 * packet: pkt_ov093_021DE3D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gQuickClawHandlerTable 0x021F163C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
void BTL_HANDLER_ITEM_MachoBraceHalveSpeed(int a, int b, int c) { int k=2; if(c == BTL_EVENT_GetVar(k)) BTL_EVENT_MultiplyVar(0x35,k<<10); }
extern u8 gQuickClawHandlerTable[];
void *BTL_HANDLER_ITEM_GetQuickClawHandlers(int *p) { *p=2; return gQuickClawHandlerTable; }
