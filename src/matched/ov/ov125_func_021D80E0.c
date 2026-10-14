/*
 * unit: yes
 * function: GDS_SOCKET_Send, GDS_SOCKET_ReceiveThread
 * address: 0x021D80E0
 * packet: pkt_ov125_021D80E0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F590 0x0215F590 arm ov009
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   GDS_SOCKET_Sleep 0x021D8438 arm ov125
 *   func_0215F4DC 0x0215F4DC arm ov009
 */

#include "../include/G_Clear.h"

typedef unsigned int u32;
typedef unsigned long long u64;
extern struct Clear gGdsSocket;
extern u64 OS_GetTick(void);
extern int func_0215F590(int, void *, int, int);
extern void GDS_SOCKET_Lock(void);
extern void GDS_SOCKET_Unlock(void);
extern void GDS_SOCKET_Sleep(int);
extern int func_0215F4DC(int, void *, int, int);
int GDS_SOCKET_Send(void)
{
    int start, count = 0, length, result;
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        length = ((u32 *)&gGdsSocket)[0x254/4] - count;
        if (length > (int)((u32 *)&gGdsSocket)[0x254/4]) length = ((u32 *)&gGdsSocket)[0x254/4];
        result = func_0215F590(((u32 *)&gGdsSocket)[0x26c/4], (char *)((u32 *)&gGdsSocket)[0x258/4] + count, length, 0);
        if (result != -6) {
            if (result < 0) {
                ((u32 *)&gGdsSocket)[0x250/4] = 11;
                return 0;
            }
            count += result;
            if (count == ((u32 *)&gGdsSocket)[0x254/4]) break;
        }
        if (((u32 *)&gGdsSocket)[0x248/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)&gGdsSocket)[0x248/4]) {
            ((u32 *)&gGdsSocket)[0x250/4] = 11;
            return 0;
        }
        GDS_SOCKET_Lock();
        if (((u32 *)&gGdsSocket)[0x268/4] == 1) {
            ((u32 *)&gGdsSocket)[0x250/4] = 13;
            GDS_SOCKET_Unlock();
            return 0;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
    return 1;
}
void GDS_SOCKET_ReceiveThread(void *a0)
{
    int count;
    for (;;) {
        count = ((u32 *)&gGdsSocket)[0x410/4];
        GDS_SOCKET_Lock();
        if (!((u32 *)&gGdsSocket)[0x414/4]) {
            ((u32 *)&gGdsSocket)[0x40c/4] = func_0215F4DC(((u32 *)&gGdsSocket)[0x26c/4], (char *)((u32 *)&gGdsSocket)[0x260/4] + count, ((u32 *)&gGdsSocket)[0x25c/4] - count, 0);
            ((u32 *)&gGdsSocket)[0x414/4] = 1;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
}
