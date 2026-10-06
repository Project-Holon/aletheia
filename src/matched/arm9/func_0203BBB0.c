/*
 * function: func_0203BBB0
 * address:  0x0203BBB0
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Two presets that differ only in the state byte they match and the handler
 * they advertise.  Each test is a conjunction of the state byte and the
 * eight-byte pointer stored beside it, and the first arm also refuses when
 * the vtable's +0x10 hook answers zero.
 *
 * The four code addresses are declared as the functions they are: written as
 * integer literals the front end folds two nearby ones into one pool word plus
 * a `sub`, which is four bytes shorter than the original.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BBB0.c \
 *       --func func_0203BBB0 --addr 0x0203BBB0 --cc 1.1p1 --arm
 */
#include "../include/Obj06945.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_021469DC;

struct Slot;
extern void *func_0203D788(void);
typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_0203B950(u8 *p);
extern void func_0203B90C(void);
extern void func_0203B5D4(struct Slot *p);
extern void func_0203B48C(void);

void func_0203BBB0(u32 a)
{
    u8 *s = func_0203D788();
    u8 *g;

    g = g_021469DC;
    if (g[0x56] == 2 && ((struct Obj06945 *)g)->f8 == (u32)func_0203B950) {
        if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) != 0) {
            func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203B90C, 0, 0x3E0);
        }
    }

    g = g_021469DC;
    if (g[0x56] == 1 && ((struct Obj06945 *)g)->f8 == (u32)func_0203B5D4) {
        func_0203AD80((struct NetState *)g, (void *)func_0203B48C, 0, 0x3E9);
    }
}
