/*
 * function: COMM_ENTRY_MENU_CheckDisconnects
 * address:  0x021CE24C
 * packet:   pkt_ov021_021CE24C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   COMM_ENTRY_MENU_ClearMember  0x021CE3D8  thumb  ov021
 *   COMM_ENTRY_MENU_ClearPendingBits  0x021CEA84  thumb  ov021
 *   COMM_ENTRY_MENU_QueueSend  0x021CEAB0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02098.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 GFL_NET_IsConnectMember(u32 index);
extern void COMM_ENTRY_MENU_ClearMember(u8 *p, u8 i);
extern void COMM_ENTRY_MENU_ClearPendingBits(u8 *p, int n);
extern void COMM_ENTRY_MENU_QueueSend(u8 *p);

void COMM_ENTRY_MENU_CheckDisconnects(u8 *p)
{
    u8 i;
    int off;

    for (i = 0; i < 4; i++) {
        off = i * 0x2c;
        if (p[0x70 + off] && !GFL_NET_IsConnectMember(i)) {
            void (*cb)(u32, u8 *, u8 *) = *(void (**)(u32, u8 *, u8 *))(p + 0x490);

            if (cb) {
                cb(((struct Obj02098 *)p)->f488, p + 0x50 + off, p + 0x73 + off);
            }
            COMM_ENTRY_MENU_ClearMember(p, i);
            COMM_ENTRY_MENU_ClearPendingBits(p, i);
            COMM_ENTRY_MENU_QueueSend(p);
        }
    }
}
