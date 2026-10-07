/*
 * file:     net_whpipe_p03.c
 * unit:     yes
 * function: func_02177310, func_0217731C
 * address:  0x02177310
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4  0x021797A4  data  a4
 *   func_0203D798  0x0203D798  arm
 *   func_0203F1FC  0x0203F1FC  arm
 */
#include "../../matched/include/Obj03087.h"
#include "../../matched/include/Obj05922.h"
#include "../../matched/include/Obj19327.h"
#include "../../matched/include/G_W.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef int (*CheckFn)(u8 a, u8 b, u32 c);

typedef void (*NotifyFn)(u32 a, u8 *obj, u32 b, u32 c);

void *func_0203D798(void);
u16 func_0203F1FC(const u8 *src, u32 len);
void func_02177310(u32 v);
int func_0217731C(u8 *obj);
extern struct W *g_021797A4;


void func_02177310(u32 v)
{
    *(u32 *)(*(u32 *)0x021797A4 + 4) = v;
}


int func_0217731C(u8 *obj)
{
    u8 *base = ((u8 *)g_021797A4);
    u8 *st = func_0203D798();
    u8 *p;
    int v67;
    u16 v50;
    CheckFn fn;
    NotifyFn nf;

    v67 = st[0x67];
    v50 = ((struct Obj05922 *)st)->f50;
    p = obj + 0x50;
    if (p[7] != 0)
        return 0;
    if (p[5] != 0)
        return 0;
    if (((struct Obj03087 *)p)->f0 != func_0203F1FC(p + 2, 0x6e))
        return 0;
    if (((struct Obj03087 *)p)->f2 != v50)
        return 0;
    nf = *(NotifyFn *)(((u8 *)g_021797A4) + 0xC38);
    if (nf != 0)
        nf(*(u32 *)(((u8 *)g_021797A4) + 0xC3C), obj, p[4], p[6]);
    fn = *(CheckFn *)&((struct Obj05922 *)st)->f20;
    if (fn != 0) {
        if (fn(v67, p[4], ((struct Obj19327 *)base)->fC64) == 0)
            return 0;
    } else if (v67 != p[4]) {
        return 0;
    }
    if (v67 != 0x14 && p[6] >= st[0x60] && st[0x60] > 1)
        return 0;
    return 1;
}
