/*
 * function: func_0218AD80
 * address:  0x0218AD80
 * packet:   pkt_ov021_0218AD80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up entry id through func_021625CC, optionally resolves its argument,
 * then dispatches to ov020 func_02185410 for kind 6 or func_02185360
 * otherwise.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626A8  0x021626A8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02185410  0x02185410  thumb  ov020
 *   func_02185360  0x02185360  thumb  ov020
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00705.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_021625CC(char *p, unsigned i);
extern u16 func_021626A8(void *b, void *pos);
extern u8 func_021626E8(u8 *p);
extern void *func_02185410(void *p, int u, int a, int b);
extern void *func_02185360(void *p, int u, int a, int b);

void func_0218AD80(u8 *p, void *a, int id, void *arg)
{
    void *obj = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
    void *d;

    if (arg != 0)
        d = (void *)func_021626A8(obj, arg);
    else
        d = 0;
    if (func_021626E8(obj) == 6)
        func_02185410(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
    else
        func_02185360(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
}
