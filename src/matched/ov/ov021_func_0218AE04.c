/*
 * function: func_0218AE04
 * address:  0x0218AE04
 * packet:   pkt_ov021_0218AE04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the current entry id from func_02162564 when it is usable
 * (func_0218AEAC or func_0218AECC accepts it), else 0xFFFF.
 *
 * symbols:
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_0218AEAC  0x0218AEAC  thumb
 *   func_0218AECC  0x0218AECC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00705.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_02162564(void *p);
extern void *func_021625CC(void *p, u16 id);
extern int func_0218AEAC(u8 *p);
extern int func_0218AECC(char *a0, int a1);

u32 func_0218AE04(u8 *p, void *arg)
{
    u32 id = func_02162564(((struct Obj00705 *)p)->fC);
    void *obj;

    if (id == 0xFFFF)
        return 0xFFFF;
    obj = func_021625CC(((struct Obj00705 *)p)->fC, id);
    if (!func_0218AEAC(obj) && !func_0218AECC(obj, ((struct Obj00705 *)p)->f24))
        return 0xFFFF;
    return id;
}
