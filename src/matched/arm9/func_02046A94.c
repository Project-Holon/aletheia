/*
 * function: G3D_SYSTEM_SetLight
 * address:  0x02046A94
 * packet:   pkt_02046858
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem   0x02146A5C  data
 *   NNS_G3dGlbLightVector 0x0206AA3C  arm
 *   NNS_G3dGlbLightColor 0x0206AA78  arm
 *
 * A four-halfword record written into an eight-byte slot of the global
 * context at index `idx` (the slot base is ctx + idx*8 and the record starts
 * at +0x3c of it), then the same fields read back signed for the first
 * notification call and unsigned for the second.  The context pointer is
 * re-read from its slot once per statement group because each call may
 * replace it, which is why the field accesses are not CSE'd into one load.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_SetLight.c \
 *       --func G3D_SYSTEM_SetLight --addr 0x02046A94 --cc 1.1p1 --arm
 */
#include "../include/Obj06969.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

extern u8 *_G3dSystem;

extern void NNS_G3dGlbLightVector(int idx, int a, int b, int c);
extern void NNS_G3dGlbLightColor(int idx, u32 v);

void G3D_SYSTEM_SetLight(u32 idx, const u16 *src)
{
    u8 *p = _G3dSystem + idx * 8;

    ((struct Obj06969 *)p)->f3C = src[0];
    ((struct Obj06969 *)p)->f3E = src[1];
    ((struct Obj06969 *)p)->f40 = src[2];
    ((struct Obj06969 *)p)->f42 = src[3];

    NNS_G3dGlbLightVector(idx, *(s16 *)(_G3dSystem + idx * 8 + 0x3c),
                  *(s16 *)(_G3dSystem + idx * 8 + 0x3e),
                  *(s16 *)(_G3dSystem + idx * 8 + 0x40));
    NNS_G3dGlbLightColor(idx, *(u16 *)(_G3dSystem + idx * 8 + 0x42));
}
