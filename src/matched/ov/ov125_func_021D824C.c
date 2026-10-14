/*
 * function: GDS_SOCKET_Receive
 * address: 0x021D824C
 * packet: pkt_ov125_021D824C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   d_021D9E40b 0x021D9E40 data a4
 *   gGdsReceiveThread 0x021DA18C data a4 ov125
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   OS_CreateThread 0x020853C0 arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   OS_DestroyThread 0x020855BC arm
 *   GDS_SOCKET_ReceiveThread 0x021D81EC arm ov125
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   GDS_SOCKET_Sleep 0x021D8438 arm ov125
 */

#include "../include/G_Clear.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
extern struct Clear gGdsSocket;
extern struct Clear d_021D9E40b;
extern char gGdsReceiveThread[];
extern u64 OS_GetTick(void);
extern void OS_CreateThread(void *, void (*)(void *), int, void *, int, unsigned);
extern void OS_WakeupThreadDirect(void *);
extern void OS_DestroyThread(void *);
extern void GDS_SOCKET_ReceiveThread(void *);
extern void GDS_SOCKET_Lock(void);
extern void GDS_SOCKET_Unlock(void);
extern void GDS_SOCKET_Sleep(int);
int GDS_SOCKET_Receive(void)
{
    u32 count = 0;
    int zero = 0;
    u32 word = -1;
    int start;
    int r;
    u64 t0;
    int ret = 0;

    t0 = OS_GetTick();
    OS_CreateThread(gGdsReceiveThread, GDS_SOCKET_ReceiveThread, 0, ((u8 *)&d_021D9E40b), 0x800, ((u32 *)&gGdsSocket)[0x270 / 4]);
    ((u32 *)&gGdsSocket)[0x40C / 4] = -6;
    ((u32 *)&gGdsSocket)[0x410 / 4] = 0;
    ((u32 *)&gGdsSocket)[0x414 / 4] = 0;
    OS_WakeupThreadDirect(gGdsReceiveThread);
    start = t0 / 0x7fd88;
    for (;;) {
        if (((u32 *)&gGdsSocket)[0x24C / 4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)&gGdsSocket)[0x24C / 4]) {
            ((u32 *)&gGdsSocket)[0x250 / 4] = 12;
            OS_DestroyThread(gGdsReceiveThread);
            return ret;
        }
        if (((u32 *)&gGdsSocket)[0x414 / 4] == 0) {
            continue;
        }
        r = ((u32 *)&gGdsSocket)[0x40C / 4];
        if (r != -6) {
            if (r <= 0) {
                ((u32 *)&gGdsSocket)[0x250 / 4] = 9;
                OS_DestroyThread(gGdsReceiveThread);
                return 0;
            }
            count += r;
            if (count >= 4 && word == -1) {
                u8 *h = (u8 *)&word;
                u8 *q = (u8 *)((u32 *)&gGdsSocket)[0x260 / 4];
                h[0] = q[0]; h[1] = q[1]; h[2] = q[2]; h[3] = q[3];
            }
            if (count == word) {
                if (word != -1) {
                    ((u32 *)&gGdsSocket)[0x25C / 4] = word - 4;
                    break;
                }
            }
            ((u32 *)&gGdsSocket)[0x410 / 4] = count;
        }
        GDS_SOCKET_Lock();
        if (((u32 *)&gGdsSocket)[0x268 / 4] == 1) {
            ((u32 *)&gGdsSocket)[0x250 / 4] = 13;
            GDS_SOCKET_Unlock();
            OS_DestroyThread(gGdsReceiveThread);
            return 0;
        }
        GDS_SOCKET_Unlock();
        ((u32 *)&gGdsSocket)[0x414 / 4] = zero;
        GDS_SOCKET_Sleep(1);
    }
    OS_DestroyThread(gGdsReceiveThread);
    return 1;
}
