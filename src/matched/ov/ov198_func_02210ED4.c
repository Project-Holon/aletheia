/*
 * function: B_PLIST_MAIN_IsRowFlagged
 * address: 0x02210ED4
 * packet: pkt_ov198_02210ED4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u8 low:7,high:1;} Bits;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
u8 B_PLIST_MAIN_IsRowFlagged(u8 *p) { if(((Bits *)(p+B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32])*76+27))->high) return 1; return 0; }
