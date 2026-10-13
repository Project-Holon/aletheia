/*
 * function: COLOSSEUM_RecvTrainerCard
 * address:  0x02174BEC
 * packet:   pkt_ov012_02174BEC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   func_02082D44  0x02082D44  arm
 */
#include "../include/Obj19278.h"
#include "../include/Obj19279.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_02082D44(void *src, void *dst, u32 n);

void COLOSSEUM_RecvTrainerCard(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19278 *)d)->f355C;

    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()))) {
        return;
    }
    if (w == 0 || ((struct Obj19279 *)w)->f0 == 0) {
        return;
    }
    if (*(void **)(w + a * 4 + 0x134) == 0) {
        return;
    }
    func_02082D44(c, *(void **)(w + a * 4 + 0x134), b);
    (w + a)[0x144] = 1;
}
