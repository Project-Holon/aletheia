/*
 * function: B_PLIST_MAIN_GetSlotState
 * address: 0x02210B00
 * packet: pkt_ov198_02210B00
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_IsSlotSelectable 0x02210F4C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int),B_PLIST_MAIN_IsSlotSelectable(u8 *,int);
int B_PLIST_MAIN_GetSlotState(u8 *p,int i) { if(!*(u16 *)(p+B_PLIST_MAIN_GetOrderIndex(p,i)*76+8))return 0;if(B_PLIST_MAIN_IsSlotSelectable(p,i)==1)return 1;return 2; }
