/*
 * function: NNS_G3dGetAnmByIdx
 * address:  0x0206E9A4
 * packet:   pkt_0206E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGetAnmByIdx.c \
 *       --func NNS_G3dGetAnmByIdx --addr 0x0206E9A4 --cc 1.1p1 --arm
 */
#include "../include/Obj11640.h"
#include "../include/Obj16616.h"
#include "../include/Obj16617.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *NNS_G3dGetAnmByIdx(u8 *p, u32 idx)
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
