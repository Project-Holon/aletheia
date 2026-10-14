/*
 * function: IRCNET_Update
 * address:  0x02179D80
 * packet:   pkt_ov015_02179D80
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame driver of the game's infrared link over libirc: counts frames
 * in gIrcNetWork+0xC0 against the limit at +0xBC, polls IRC_IsConnect, on
 * frame 5 re-initialises libirc (IRC_Init(3)) and installs IRCNET_OnRecv as
 * the receive callback, and on timeout clears the active flag (+0xDD) and
 * raises the done flag (+0xE5).
 *
 * symbols:
 *   d_0217AB80           0x0217AB80  data   ov015
 *   gIrcNetWork           0x0217AAC0  data   ov015
 *   IRCNET_OnRecv        0x02179B38  thumb  ov015
 *   IRC_Move        0x0217A334  arm    ov015
 *   IRC_IsConnect        0x0217A024  arm    ov015
 *   IRC_IsSender         0x0217A014  arm    ov015
 *   IRC_Init             0x02179F74  arm    ov015
 *   IRC_SetRecvCallback  0x0217A584  arm    ov015
 *   IRC_Connect        0x02179FC4  arm    ov015
 *   IRC_Shutdown        0x0217A134  arm    ov015
 *   IRCNET_IsReceiver        0x02179B24  thumb  ov015
 *   GFL_NET_HANDLE_RemoveHandle        0x0203A338  arm
 *   _u32_div_f           0x0209C2B0  arm
 */

#include "../include/G_State.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern struct State d_0217AB80;
extern u8 gIrcNetWork[];

extern void IRCNET_OnRecv(u8 *pkt, u32 len, u32 type);
extern int IRC_Move(void);
extern int IRC_IsConnect(void);
extern int IRC_IsSender(void);
extern void IRC_Init(u8 unit);
extern void IRC_SetRecvCallback(void (*cb)(u8 *, u32, u32));
extern void IRC_Connect(void);
extern void IRC_Shutdown(void);
extern int IRCNET_IsReceiver(void);
extern void GFL_NET_HANDLE_RemoveHandle(u32 a0);

#define W(off) (*(u32 *)(w + (off)))
#define B(off) (w[(off)])

void IRCNET_Update(void)
{
    u8 *w = gIrcNetWork;

    if (((u8 *)&d_0217AB80)[0x1D] != 0 || W(0xC0) < W(0xBC) || W(0xC0) == 0) {

        if (W(0xC0) == 0)
            IRC_Move();

        if (B(0xDD) != 1)
            return;

        if (W(0xC0) != 0) {
            if (IRC_IsConnect() == 1) {
                W(0xC0) = 0;
                if (IRC_IsSender() == 1)
                    B(0xCE) = 0;
                else
                    B(0xCE) = 1;
                if (B(0xE1) == 1)
                    B(0xE4) = 1;
                return;
            }
            if (W(0xC0) < 5) {
                W(0xC0)++;
                return;
            }
            if (W(0xC0) == 5) {
                IRC_Init(3);
                IRC_SetRecvCallback(IRCNET_OnRecv);
                W(0xC0)++;
                return;
            }
            IRC_Move();
            if (W(0xC0) < W(0xBC)) {
                if (B(0xDC) == 1 && W(0xC0) % 5 == 0)
                    IRC_Connect();
                W(0xC0)++;
                return;
            }
            B(0xDD) = 0;
            B(0xE5) = 1;
            GFL_NET_HANDLE_RemoveHandle(1 - IRCNET_IsReceiver());
            IRC_Shutdown();
        } else {
            if (IRC_IsConnect() != 0)
                return;
            if (W(0xBC) != 0) {
                IRC_Shutdown();
                W(0xC0) = 1;
                return;
            }
            B(0xDD) = 0;
            B(0xE5) = 1;
            W(0xC0) = 0xFFFF;
            GFL_NET_HANDLE_RemoveHandle(1 - IRCNET_IsReceiver());
            IRC_Shutdown();
        }
    }
}
