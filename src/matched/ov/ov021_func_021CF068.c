/*
 * function: func_021CF068
 * address:  0x021CF068
 * packet:   pkt_ov021_021CF068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"
#include "../include/Obj04295.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020362DC(void);
struct Handle;
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern void func_021CE9E4(u8 *p, u32 m);
extern int func_02190C78(struct Handle *h);
extern int func_0219049C(u8 *p);
extern int func_021909BC(u32 a);

int func_021CF068(u8 *p)
{
    u8 *q = p + 0x130;
    u32 r;

    switch (q[8]) {
    case 0:
        if (func_020362DC() & 2) {
            ((struct Obj04295 *)q)->f0 = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0)), 0);
            func_021CE9E4(p, 0x23);
            q[8] = 1;
        }
        break;
    case 1:
        r = func_02190C78((struct Handle *)(((struct Obj04295 *)q)->f0));
        if (func_0219049C((u8 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0))) == 1 && p[0x576] == 1)
            r = 1;
        if (r != 2) {
            func_021909BC(((struct Obj04295 *)q)->f0);
            ((struct Obj04295 *)q)->f0 = 0;
            if (r == 1) {
                q[8] = 0;
                func_021CE9E4(p, 0x22);
            } else {
                return 2;
            }
        }
        return 1;
    }
    return 0;
}
