/*
 * function: GTSNEGO_DISP_SendRecord
 * address: 0x021D47D4
 * packet: pkt_ov120_021D47D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_SendStatus 0x021D4798 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void); extern int GFL_NET_SendToHandle(void *,u16,u16,u32); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_SendStatus(int);
void GTSNEGO_DISP_SendRecord(u8 *p) { if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0x2202,12,(u32)(p+360))) GTSNEGO_DISP_SetStateCallback((int)p,GTSNEGO_DISP_SendStatus,0x2cf); }
