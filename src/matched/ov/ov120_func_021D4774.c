/*
 * function: GTSNEGO_DISP_StartSync
 * address: 0x021D4774
 * packet: pkt_ov120_021D4774
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_PrepareTrade 0x021D46A4 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void); extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_PrepareTrade(int);
void GTSNEGO_DISP_StartSync(int p) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),3,34); GTSNEGO_DISP_SetStateCallback(p,GTSNEGO_DISP_PrepareTrade,0x2ac); }
