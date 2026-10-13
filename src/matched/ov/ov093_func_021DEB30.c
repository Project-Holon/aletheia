/*
 * function: HAND_ITEM_FocusBand_UseItem
 * address: 0x021DEB30
 * packet: pkt_ov093_021DEB30
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: remaining two bytes are zero alignment padding.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   HAND_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern void HAND_ITEM_PushUseItem(void *,void *,int);
void HAND_ITEM_FocusBand_UseItem(int a,int b,int c,int *p) { if(c==BTL_EVENT_GetVar(2)) { if(*p) { HAND_ITEM_PushUseItem((void *)a,(void *)b,c); *p=0; } } }
