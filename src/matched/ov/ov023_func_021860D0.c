/*
 * function: func_021860D0
 * address:  0x021860D0
 * packet:   pkt_ov023_021860D0
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   GFL_NET_ResetSendQueue  0x0203D56C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02186A04  0x02186A04  thumb  ov023
 *   func_021869C0  0x021869C0  thumb  ov023
 *   func_02186958  0x02186958  thumb  ov023
 */
#include "../include/Obj01221.h"

typedef unsigned short u16;

struct Entry;
extern u16 func_02039338(void);
extern struct Entry *func_020399A8(void);
extern int  GFL_NET_ResetSendQueue(void *h);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02186A04(char *a, char *b);
extern void func_021869C0(char *a, char *b);
extern void func_02186958(char *a);

void func_021860D0(char *p)
{
    void *h;

    if (func_02039338() == 0) {
        h = func_020399A8();
        if (GFL_NET_ResetSendQueue(h) == 0)
            return;
        func_02186A04(p + 0x9e4c, p + 0x928c);
        ((struct Obj01221 *)p)->f9E51 = ((struct Obj01221 *)p)->f9E6C;
        if (func_0203D3A8(h, 0x2902, 0x1e, (u32)(p + 0x9e4c)) == 1)
            func_02186958(p + 0x928c);
    } else {
        h = func_020399A8();
        func_021869C0(p + 0x420c, p + 0x928c);
        if (GFL_NET_ResetSendQueue(h) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 0x2901, 6, (u32)(p + 0x420c)) == 1)
            func_02186958(p + 0x928c);
    }
}
