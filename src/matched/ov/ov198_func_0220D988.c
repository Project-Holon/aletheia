/*
 * unit: no
 * function: B_PLIST_DRAW_PrintValueIfUnset
 * address: 0x0220D988
 * packet: pkt_ov198_0220D988
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PrintSlotValue 0x0220C0D0 thumb ov198
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u8 lo:7,hi:1;} Bits;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);extern void B_PLIST_DRAW_PrintSlotValue(u8 *,int,int,u16,u8);
void B_PLIST_DRAW_PrintValueIfUnset(u8 *p,int a){if(((Bits *)(p+(u32)B_PLIST_MAIN_GetOrderIndex(p,a)*76+0x1b))->hi==0)B_PLIST_DRAW_PrintSlotValue(p,a,a,8,32);}
