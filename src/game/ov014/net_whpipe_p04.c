/*
 * file:     net_whpipe_p04.c
 * unit:     yes
 * function: func_02177494, func_02177560
 * address:  0x02177494
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
 *   g_021797A4     0x021797A4  data  a4
 *   func_0203D798  0x0203D798  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj04174.h"
#include "../../matched/include/Obj07353.h"
#include "../../matched/include/Obj19328.h"
#include "../../matched/include/G_W.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef int (*CheckFn)(u8 a, u8 b, u32 c);

void *func_0203D798(void);
u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02082BCC(void *, u32, u32);
int func_02177494(u8 *obj, u32 flags);
void func_02177560(void);
extern struct W *g_021797A4;


int func_02177494(u8 *obj, u32 flags)
{
    u8 *base = ((u8 *)g_021797A4);
    u8 *st = func_0203D798();
    int v67 = st[0x67];
    u16 v50 = ((struct Obj07353 *)st)->f50;
    u8 *p = obj + 0x50;
    CheckFn fn;

    if ((flags & 1) && p[7] != 0)
        return 0;
    if ((flags & 2) && p[5] != 0)
        return 0;
    if ((flags & 4) && ((struct Obj04174 *)p)->f0 != func_0203F1FC(p + 2, 0x6e))
        return 0;
    if ((flags & 8) && ((struct Obj04174 *)p)->f2 != v50)
        return 0;
    if (flags & 0x10) {
        fn = *(CheckFn *)&((struct Obj07353 *)st)->f20;
        if (fn != 0) {
            if (fn(v67, p[4], ((struct Obj19328 *)base)->fC64) == 0)
                return 0;
        } else if (v67 != p[4]) {
            return 0;
        }
    }
    if ((flags & 0x20) && p[6] >= st[0x60])
        return 0;
    return 1;
}

void func_02177560(void)
{
    u8 *p = ((u8 *)g_021797A4);
    int i;
    for (i = 0; i < 16; i++) *(u16 *)(p + i*2 + 0xC40) = 0;
    func_02082BCC(p + 8, 0, 0xC00);
}
