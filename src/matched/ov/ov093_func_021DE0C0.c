/*
 * function: BTL_HANDLER_ITEM_MicleBerryUseWhenForced, BTL_HANDLER_ITEM_GetJabocaBerryHandlers
 * address: 0x021DE0C0
 * packet: pkt_ov093_021DE0C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 * unit: yes
 * symbols:
 *   BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy 0x021DE058 thumb ov093
 *   gJabocaBerryHandlerTable 0x021F160C data a4
 */
#include "../include/Obj21380.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy(void *, void *, int, u8 *);
void BTL_HANDLER_ITEM_MicleBerryUseWhenForced(void *a, void *b, int c, u8 *d) { if (((struct Obj21380 *)d)->f18) BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy(a,b,c,d); }
extern u8 gJabocaBerryHandlerTable[];
void *BTL_HANDLER_ITEM_GetJabocaBerryHandlers(int *p) { *p=2; return gJabocaBerryHandlerTable; }
