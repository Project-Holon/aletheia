/*
 * function: func_021DEFE8
 * address: 0x021DEFE8
 * packet: pkt_ov137_021DEFE8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 func_02039CB4(struct Link *,u32,u32);
int func_021DEFE8(int *p) { if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),203,40)) *p=24; return 0; }
