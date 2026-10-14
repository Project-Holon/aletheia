/*
 * function: GDS_SOCKET_RunConnection
 * address: 0x021D7874
 * packet: pkt_ov125_021D7874
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: case 6 uses an explicit nested if for the error-13 split; the ternary spelling compiled four bytes short.
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   GDS_SOCKET_WaitToken 0x021D8444 arm ov125
 *   GDS_SOCKET_OpenAndResolve 0x021D7E80 arm ov125
 *   GDS_SOCKET_Connect 0x021D7FA0 arm ov125
 *   GDS_SOCKET_Send 0x021D80E0 arm ov125
 *   GDS_SOCKET_Receive 0x021D824C arm ov125
 *   GDS_SOCKET_Free 0x021D7C90 arm ov125
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   GDS_SOCKET_Sleep 0x021D8438 arm ov125
 */

#include "../include/G_Clear.h"

extern struct Clear gGdsSocket;
extern int GDS_SOCKET_WaitToken(void);
extern int GDS_SOCKET_OpenAndResolve(void);
extern int GDS_SOCKET_Connect(void);
extern int GDS_SOCKET_Send(void);
extern int GDS_SOCKET_Receive(void);
extern void GDS_SOCKET_Free(int);
extern void GDS_SOCKET_Lock(void);
extern void GDS_SOCKET_Unlock(void);
extern void GDS_SOCKET_Sleep(int);
void GDS_SOCKET_RunConnection(void)
{
    int finish, next;
    for (;;) {
        finish = 0;
        switch (((int *)&gGdsSocket)[0x13c/4]) {
        case 0: case 1: case 7: case 8: case 9:
            finish = 1;
            break;
        case 2:
            if (!GDS_SOCKET_WaitToken()) {
                next = ((int *)&gGdsSocket)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 3;
            GDS_SOCKET_Lock();
            ((int *)&gGdsSocket)[0x13c/4] = next;
            break;
        case 3:
            if (!GDS_SOCKET_OpenAndResolve()) {
                next = ((int *)&gGdsSocket)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 4;
            GDS_SOCKET_Lock();
            ((int *)&gGdsSocket)[0x13c/4] = next;
            break;
        case 4:
            if (!GDS_SOCKET_Connect()) {
                next = ((int *)&gGdsSocket)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 5;
            GDS_SOCKET_Lock();
            ((int *)&gGdsSocket)[0x13c/4] = next;
            break;
        case 5:
            if (!GDS_SOCKET_Send()) {
                next = ((int *)&gGdsSocket)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 6;
            if (((int *)&gGdsSocket)[0x258/4]) {
                GDS_SOCKET_Free(((int *)&gGdsSocket)[0x258/4]);
                ((int *)&gGdsSocket)[0x258/4] = 0;
            }
            GDS_SOCKET_Lock();
            ((int *)&gGdsSocket)[0x13c/4] = next;
            break;
        case 6:
            if (!GDS_SOCKET_Receive()) {
                if (((int *)&gGdsSocket)[0x250/4] == 13) next = 7;
                else next = 9;
            } else {
                next = 8;
            }
            finish = 1;
            GDS_SOCKET_Lock();
            ((int *)&gGdsSocket)[0x13c/4] = next;
            break;
        }
        if (finish != 0) break;
        if (((int *)&gGdsSocket)[0x268/4] == 1) {
            ((int *)&gGdsSocket)[0x13c/4] = 7;
            ((int *)&gGdsSocket)[0x250/4] = 13;
            break;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
    GDS_SOCKET_Unlock();
}
