/*
 * file:     unit_0206E954.c
 * unit:     yes
 * function: func_0206E954, func_0206E964, func_0206E9A4
 * address:  0x0206E954
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj16615.h"
#include "../../matched/include/Obj04802.h"
#include "../../matched/include/Obj11639.h"
#include "../../matched/include/Obj11640.h"
#include "../../matched/include/Obj16616.h"
#include "../../matched/include/Obj16617.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

int func_0206E954(int p0);
unsigned char *func_0206E964(unsigned char *p);
u8 *func_0206E9A4(u8 *p, u32 idx);


int func_0206E954(int p0){ return (p0 + *(int *)((p0 + (((struct Obj16615 *)p0)->fC << 0)))); }


/*
 * BTX0 header walk: the halfword at +12 is the offset of the info block and
 * the halfword at +14 selects the entry form (1 = the 'BTX0' magic form).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E964.c \
 *       --func func_0206E964 --addr 0x0206E964 --cc 1.1p1 --arm
 */
unsigned char *func_0206E964(unsigned char *p)
{
    unsigned char *q = p + ((struct Obj04802 *)p)->fC;

    if (((struct Obj04802 *)p)->fE == 1) {
        if (((struct Obj04802 *)p)->f0 == 0x30585442u)
            return p + ((struct Obj11639 *)q)->f0;
        return 0;
    }
    return p + ((struct Obj11639 *)q)->f4;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E9A4.c \
 *       --func func_0206E9A4 --addr 0x0206E9A4 --cc 1.1p1 --arm
 */
u8 *func_0206E9A4(u8 *p, u32 idx)
{
    u8 *q;
    u8 *h;
    u32 off;

    if (p == 0)
        goto ret0;
    q = p + *(u32 *)(p + ((struct Obj16616 *)p)->fC);
    h = q + 8;
    if (h == 0)
        goto fail;
    if (idx >= ((struct Obj11640 *)q)->f9)
        goto fail;
    off = ((struct Obj11640 *)q)->fE;
    idx = *(u16 *)(h + off) * idx + ((u32)h + off + 4);
    goto end;
fail:
    idx = 0;
end:
    if (idx != 0)
        return q + ((struct Obj16617 *)idx)->f0;
ret0:
    return 0;
}
