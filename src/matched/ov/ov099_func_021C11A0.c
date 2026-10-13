/*
 * function: func_021C11A0
 * address: 0x021C11A0
 * packet: pkt_ov099_021C11A0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021C1286..021C1288 is two zero alignment bytes.
 * blocker: 0x0203C5EC ARM verified EXACT 20 bytes in blocker-c5ec-one.log.
 *   extern char *d_021469DC;
 *   int GFL_NET_STATE_IsWifiDisconnectFinal(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   symbols: d_021469DC 0x021469DC data a4.
 * prototype: 399A8 leaves a live pointer consumed by 399B8, 39C68 and 3D1A4.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   GFL_NET_STATE_IsWifiDisconnectFinal 0x0203C5EC arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C1154 0x021C1154 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021BC090 0x021BC090 thumb ov099
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 */
typedef unsigned short u16;
extern int func_021BA928(void *);
extern int GFL_NET_STATE_GetWifiState(void);
extern int GFL_NET_STATE_IsWifiDisconnectFinal(void);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
extern int func_021C1154(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern void MI_CpuFill8(void *, int, int);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern void func_021BC090(void *);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
int func_021C11A0(char *p, int ret)
{
    func_021BA928(p);
    if (GFL_NET_STATE_GetWifiState() >= 4 || GFL_NET_STATE_IsWifiDisconnectFinal() != 0) {
        if (*(u16 *)(p + 0x244) != 0) {
            func_021BAAB8(p, 0x44, 0);
        } else {
            func_021BA874(p, *(int *)(p + 0x1f0));
            func_021BAAB8(p, 15, 0);
        }
        *(u16 *)(p + 0x244) = 0;
        *(int *)(p + 0x1cc) = 19;
    } else if (func_021C1154(p) == 0) {
        if (*(int *)(p + 0x1e0) > 1) --*(int *)(p + 0x1e0);
        if (*(int *)(p + 0x1e0) == 0) {
            if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetCurrentHandle()) != 0) {
                MI_CpuFill8(p + 0x1f4, 0, 0x40);
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 14, 10);
                *(u16 *)(p + 0x244) = 0;
                func_021BAAB8(p, 0x45, 0);
                func_021BC090(p);
                *(int *)(p + 0x1cc) = 0x2a;
            }
        } else if (*(int *)(p + 0x1e0) == 1) {
            if (GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()) != 0) {
                if (GFL_NET_HANDLE_CheckNegotiation() == 1) *(int *)(p + 0x1e0) = 0;
            } else if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && GFL_NET_HANDLE_CheckNegotiation() == 1) {
                *(int *)(p + 0x1e0) = 0;
            }
        }
    }
    return ret;
}
