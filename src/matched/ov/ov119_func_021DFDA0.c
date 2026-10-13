/*
 * function: func_021DFDA0
 * address:  0x021DFDA0
 * packet:   pkt_ov119_021DFDA0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E60  0x021E3E60  thumb  ov119
 *   func_0204B100  0x0204B100  arm
 *   func_021DFD3C  0x021DFD3C  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D9434  0x021D9434  thumb  ov119
 *   func_021E10D8  0x021E10D8  thumb  ov119
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   func_021DFE48  0x021DFE48  thumb  ov119
 *
 * Slot-state teardown/rebuild, dispatched on *(p+0x118c): 5 and 6 run the
 * shared +8 slot teardown and hand func_021D8E84 either func_021D9434 or
 * NULL; the default path increments the +0x11f8 byte and hands
 * func_021DFE48. Target of func_021D6C78's ABS32 callback argument (ov119).
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00906.h"
#include "../include/Obj22751.h"
#include "../include/Obj22752.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bank;
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_021E3E60(void *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021DFD3C(void *);
extern void func_021D8E84(void *, int);
extern void func_021D9434(void *p);
extern void func_021E10D8(char *p);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_021DFE48(char *p);

void func_021DFDA0(void *p)
{
    u8 *b = p;
    int st;

    func_0204B1CC(((struct Obj00906 *)b)->f9C4);
    func_0204A5AC();
    func_021E3E60(p);
    ((struct Obj00906 *)b)->f9C4 = func_0204B100(0x154, 0, ((struct Obj00906 *)b)->f5F4);
    st = ((struct Obj00906 *)b)->f118C;
    if (st == 5) {
        func_021DFD3C(p);
        ((struct Obj22751 *)(*(int * *)&((struct Obj00906 *)b)->f8))->f8 = 3;
        func_021D8E84(p, (int)func_021D9434);
    } else if (st == 6) {
        func_021DFD3C(p);
        ((struct Obj22752 *)(*(int * *)&((struct Obj00906 *)b)->f8))->f8 = 3;
        func_021D8E84(p, 0);
    } else {
        func_021E10D8(p);
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        (((struct Obj00906 *)b)->f11F8)++;
        GFL_USE_FadeOutBgm(6);
        ((struct Obj00906 *)b)->fF2C = 0;
        func_021D8E84(p, (int)func_021DFE48);
    }
}
