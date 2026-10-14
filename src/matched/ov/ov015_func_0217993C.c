/*
 * function: IRCNET_InitWork
 * address:  0x0217993C
 * packet:   pkt_ov015_0217993C
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gIrcNetWork     0x0217AAC0  data   ov015  a4
 *   d_0217AB40     0x0217AB40  data   ov015  a4
 *   d_0217ABA0     0x0217ABA0  data   ov015  a4
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   IRC_Init  0x02179F74  arm    ov015
 *   func_0217A584  0x0217A584  arm    ov015
 *   IRCNET_OnRecv  0x02179B38  thumb  ov015
 *   func_020056EC  0x020056EC  thumb
 */

#include "../include/G_s_ab40.h"
#include "../include/G_s_aba0.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct s_aac0 {
    u8 pad0[8];
    u32 f8;
    u8 pad1[4];
    u8 f10;
};

extern struct s_aac0 gIrcNetWork;
extern struct s_ab40 d_0217AB40;
extern struct s_aba0 d_0217ABA0;

extern void MI_CpuFill8(void *p, int v, u32 n);
typedef unsigned short u16;
extern u16 func_0208F1B4(void);
extern void IRC_Init(u8 unitId);
extern void func_0217A584(void (*cb)(void));
extern void IRCNET_OnRecv(u8 *pkt, u32 len, u32 type);
extern u32 func_020056EC(u32 x);

void IRCNET_InitWork(u32 a, u8 b)
{
    MI_CpuFill8(&gIrcNetWork, 0, 0xE8);
    d_0217AB40.f3c = a;
    d_0217ABA0.b6 = func_0208F1B4();
    IRC_Init(3);
    func_0217A584((void (*)(void))IRCNET_OnRecv);
    gIrcNetWork.f8 = func_020056EC(0);
    if (gIrcNetWork.f8 == 0)
        gIrcNetWork.f8 = 1;
    gIrcNetWork.f10 = b;
}
