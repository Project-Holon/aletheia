/*
 * function: B_PLIST_MAIN_IsSlotSelectable
 * address: 0x02210F4C
 * packet: pkt_ov198_02210F4C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_GetOwnerFlag18 0x02210EFC thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int),B_PLIST_MAIN_GetOwnerFlag18(char **);
int B_PLIST_MAIN_IsSlotSelectable(u8 *p,int i) { u32 v;v=B_PLIST_MAIN_GetOrderIndex(p,i);if(B_PLIST_MAIN_GetOwnerFlag18((char **)p)==1) {if(v==0 || v==3)return 1;return 0;}else {if(v<(*(u8 **)p)[34])return 1;return 0;} }
