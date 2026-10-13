/*
 * function: PLIST_COMM_StartSync
 * address: 0x021B61E8
 * packet: pkt_ov090_021B61E8
 * region: ov090
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
void PLIST_COMM_StartSync(void *a, int b) { func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), b, 45); }
