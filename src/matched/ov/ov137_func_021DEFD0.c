/*
 * function: func_021DEFD0
 * address: 0x021DEFD0
 * packet: pkt_ov137_021DEFD0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
int func_021DEFD0(int *p) { func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),203,40); *p=23; return 0; }
